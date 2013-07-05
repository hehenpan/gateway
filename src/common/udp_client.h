#pragma once

#include "mycommon.h"

#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <sys/poll.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/epoll.h>
#include "SDLogger.h"
#include <sys/types.h>
#include <sys/socket.h>
class udp_client
{
public:
	udp_client(void);
	~udp_client(void);

	int udp_open(std::string str_ip, int port);
	int udp_send(std::string &str_senddata);
	int udp_recv(std::string &str_recvdata);
	int udp_close(void);

private:
	int m_udp_client_fd;
	struct sockaddr_in addr;
	//DECL_LOGGER(logger);
};
