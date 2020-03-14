/**
  ******************************************************************************
	WIFI_MNGR
  ******************************************************************************
  */
/* Define to prevent recursive inclusion -------------------------------------*/
#include <string.h>
#include <stdbool.h>
#include "main.h"
#include "wifi_mngr.h"
#include "common/include/nm_common.h"
#include "driver/include/m2m_wifi.h"
#include "socket/include/socket.h"
/* USER CODE BEGIN 0 */
/** Index of scan list to request scan result. */
//static uint8_t scan_request_index = 0;
///** Number of APs found. */
//static uint8_t num_founded_ap = 0;
/* USER CODE END 0 */

// &&&&&&&&&&&&&&&& CB functions &&&&&&&&&&&&&&&&&&
static void wifi_cb(uint8_t u8MsgType, void *pvMsg);
static void socket_cb(SOCKET sock, uint8_t u8Msg, void *pvMsg);


//=========== === socket section === ===========

#define STRING_EOL    "\r\n"
#define STRING_HEADER "-- WINC1500 TCP server example --"STRING_EOL \
	"-- "BOARD_NAME " --"STRING_EOL	\
	"-- Compiled: "__DATE__ " "__TIME__ " --"STRING_EOL

/** Message format definitions. */
typedef struct s_msg_wifi_product {
	uint8_t name[9];
} t_msg_wifi_product;

/** Message format declarations. */
static t_msg_wifi_product msg_wifi_product = {
	.name = MAIN_WIFI_M2M_PRODUCT_NAME,
};

/** Receive buffer definition. */
static uint8_t gau8SocketTestBuffer[MAIN_WIFI_M2M_BUFFER_SIZE];

/** Socket for TCP communication */
static SOCKET tcp_server_socket = -1;
static SOCKET tcp_client_socket = -1;

/** Wi-Fi connection state */
static uint8_t wifi_connected;
struct sockaddr_in addr;
/* functions implementation area */
//=========== ===  end of socket section === ===========
static char TxBuff[12] = "Hola Mundo\r\n";

/* ================
int8_t WifiMngr_Init(void)
================ */
int8_t WifiMngr_Init(void)
{
	tstrWifiInitParam param;
	int8_t ret;

	/* Initialize socket address structure. */
	addr.sin_family = AF_INET;
	addr.sin_port = _htons(MAIN_WIFI_M2M_SERVER_PORT);
	addr.sin_addr.s_addr = 0;



	nm_bsp_init();

	/* Initialize Wi-Fi parameters structure. */
	memset((uint8_t *)&param, 0, sizeof(tstrWifiInitParam));

	/* =================  Initialize Wi-Fi driver with data and status callbacks. ================= */
	//param.pfAppWifiCb = wifi_cb;
	param.pfAppWifiCb = (tpfAppWifiCb)wifi_cb;
	ret = m2m_wifi_init(&param);
	if (M2M_SUCCESS != ret)
	{
		printf("main: m2m_wifi_init call error!(%d)\r\n", ret);
		while (true)
		{
		}
	}

	/* Initialize socket module */
	socketInit();
	registerSocketCallback(socket_cb, NULL);

	return ret;
}

/* ================
 sint8 WifiMngr_ScanReq(tenuM2mScanCh a_e_tenuM2mScanCh)
================ */
sint8 WifiMngr_ScanReq(tenuM2mScanCh a_e_tenuM2mScanCh)
{
	return m2m_wifi_request_scan(a_e_tenuM2mScanCh);
}


/* ================
WifiMngr_Connect(tenuM2mScanCh a_e_tenuM2mScanCh)
================ */
sint8 WifiMngr_Connect(tenuM2mScanCh a_e_tenuM2mScanCh)
{
	/* Connect to router. */
	return m2m_wifi_connect((char *)MAIN_WLAN_SSID, sizeof(MAIN_WLAN_SSID),\
							MAIN_WLAN_AUTH, (char *)MAIN_WLAN_PSK,\
							a_e_tenuM2mScanCh);
}

/* ================
 void	WifiMngr_HandleEvents(void)
================ */
sint8	WifiMngr_HandleEvents(void)
{
//	return m2m_wifi_handle_events(NULL);

	sint8 ret = m2m_wifi_handle_events(NULL);

	if (wifi_connected == M2M_WIFI_CONNECTED) {
		if (tcp_server_socket < 0) {
			/* Open TCP server socket */
			if ((tcp_server_socket = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
				printf("main: failed to create TCP server socket error!\r\n");
				return ret;
			}

			/* Bind service*/
			bind(tcp_server_socket, (struct sockaddr *)&addr, sizeof(struct sockaddr_in));
		}
	}
	return ret;
}

/* ================
static void wifi_cb(uint8_t u8MsgType, void *pvMsg)
================ */
static void wifi_cb(uint8_t u8MsgType, void *pvMsg)
{
	switch (u8MsgType) {
	case M2M_WIFI_RESP_CON_STATE_CHANGED:
	{
		tstrM2mWifiStateChanged *pstrWifiState = (tstrM2mWifiStateChanged *)pvMsg;
		if (pstrWifiState->u8CurrState == M2M_WIFI_CONNECTED) {
			printf("wifi_cb: M2M_WIFI_RESP_CON_STATE_CHANGED: CONNECTED\r\n");
			m2m_wifi_request_dhcp_client();
		} else if (pstrWifiState->u8CurrState == M2M_WIFI_DISCONNECTED) {
			printf("wifi_cb: M2M_WIFI_RESP_CON_STATE_CHANGED: DISCONNECTED\r\n");
			wifi_connected = 0;
			m2m_wifi_connect((char *)MAIN_WLAN_SSID, sizeof(MAIN_WLAN_SSID), MAIN_WLAN_AUTH, (char *)MAIN_WLAN_PSK, M2M_WIFI_CH_ALL);
		}
	}
	break;

	case M2M_WIFI_REQ_DHCP_CONF:
	{
		uint8_t *pu8IPAddress = (uint8_t *)pvMsg;
		wifi_connected = 1;
		printf("wifi_cb: M2M_WIFI_REQ_DHCP_CONF: IP is %u.%u.%u.%u\r\n",
				pu8IPAddress[0], pu8IPAddress[1], pu8IPAddress[2], pu8IPAddress[3]);
	}
	break;

	default:
		break;
	}
}



/* ================
static void socket_cb(SOCKET sock, uint8_t u8Msg, void *pvMsg)
================ */
static void socket_cb(SOCKET sock, uint8_t u8Msg, void *pvMsg)
{
	switch (u8Msg) {
	/* Socket bind */
	case SOCKET_MSG_BIND:
	{
		tstrSocketBindMsg *pstrBind = (tstrSocketBindMsg *)pvMsg;
		if (pstrBind && pstrBind->status == 0) {
			printf("socket_cb: bind success!\r\n");
			listen(tcp_server_socket, 0);
		} else {
			printf("socket_cb: bind error!\r\n");
			close(tcp_server_socket);
			tcp_server_socket = -1;
		}
	}
	break;

	/* Socket listen */
	case SOCKET_MSG_LISTEN:
	{
		tstrSocketListenMsg *pstrListen = (tstrSocketListenMsg *)pvMsg;
		if (pstrListen && pstrListen->status == 0) {
			printf("socket_cb: listen success!\r\n");
			accept(tcp_server_socket, NULL, NULL);
		} else {
			printf("socket_cb: listen error!\r\n");
			close(tcp_server_socket);
			tcp_server_socket = -1;
		}
	}
	break;

	/* Connect accept */
	case SOCKET_MSG_ACCEPT:
	{
		tstrSocketAcceptMsg *pstrAccept = (tstrSocketAcceptMsg *)pvMsg;
		if (pstrAccept) {
			printf("socket_cb: accept success!\r\n");
			accept(tcp_server_socket, NULL, NULL);
			tcp_client_socket = pstrAccept->sock;
			recv(tcp_client_socket, gau8SocketTestBuffer, sizeof(gau8SocketTestBuffer), 0);
		} else {
			printf("socket_cb: accept error!\r\n");
			close(tcp_server_socket);
			tcp_server_socket = -1;
		}
	}
	break;

	/* Message send */
	case SOCKET_MSG_SEND:
	{
		printf("socket_cb: send success!\r\n");
		printf("TCP Server Test Complete!\r\n");
//
//		send(tcp_client_socket, TxBuff, 12, 0);
//		send(tcp_client_socket, TxBuff, 12, 0);
//		send(tcp_client_socket, TxBuff, 12, 0);
		printf("close socket\n");
		close(tcp_client_socket);
		close(tcp_server_socket);
	}
	break;

	/* Message receive */
	case SOCKET_MSG_RECV:
	{
		tstrSocketRecvMsg *pstrRecv = (tstrSocketRecvMsg *)pvMsg;
		if (pstrRecv && pstrRecv->s16BufferSize > 0) {
			printf("socket_cb: recv success!\r\n");
			send(tcp_client_socket, &msg_wifi_product, sizeof(t_msg_wifi_product), 0);
		} else {
			printf("socket_cb: recv error!\r\n");
			close(tcp_server_socket);
			tcp_server_socket = -1;
		}
	}

	break;

	default:
		break;
	}
}




/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
