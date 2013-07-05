#include "udp_client.h"


//IMPL_LOGGER(udp_client, logger);

udp_client::udp_client(void)
{
	m_udp_client_fd = -1;
}

udp_client::~udp_client(void)
{

	if (m_udp_client_fd != -1)
	{
		close(m_udp_client_fd);
	}
}

int udp_client::udp_open( std::string str_ip, int port )
{
	
	memset(&addr, 0, sizeof(addr));
	addr.sin_family = AF_INET;
	addr.sin_addr.s_addr = inet_addr(str_ip.c_str());
	addr.sin_port = htons(port);

	m_udp_client_fd=socket(AF_INET,SOCK_DGRAM,0);
	if (m_udp_client_fd == -1)
	{
		return -1;
	} 

	int result = 0;

	result = connect(m_udp_client_fd,(struct sockaddr *)&addr,sizeof(addr));
	if (result == -1)
	{
		//MY_LOGERROR("open udp socket failed, ip="<<str_ip<<" port="<<port<<" errno="<<errno<<" errstr="<<strerror(errno));
		close(m_udp_client_fd);
		m_udp_client_fd = -1;
		return -1;
	} 

	return 0;

}

int udp_client::udp_send( std::string &str_senddata )
{
	if (m_udp_client_fd == -1)
	{
		return -1;
	}
	int result;
	result = sendto(m_udp_client_fd, str_senddata.c_str(), str_senddata.size(), 0, (sockaddr *)&addr, sizeof(addr));
	if (result == -1)
	{
		//MY_LOGERROR("failed to send data with udp,errno="<<errno<<" errstr="<<strerror(errno));
		return -1;
	}
	return result;

}

int udp_client::udp_recv( std::string &str_recvdata )
{
	if (m_udp_client_fd == -1)
	{
		return -1;
	}
	int result;
	char chardata[1024] ={0};
	socklen_t addrlength = sizeof(addr);

	fd_set fds_read;
	FD_ZERO(&fds_read);
	FD_SET(m_udp_client_fd, &fds_read);
	struct timeval tv;
	tv.tv_sec = 5;
	tv.tv_usec = 0;
	result = select(m_udp_client_fd+1, &fds_read, NULL, NULL, &tv);
	if (result == -1)
	{
		//MY_LOGERROR("udp socket select err happens, errno="<<errno<<" strerr="<<strerror(errno));
		return -1;
	}
	if (result == 0)
	{
		//MY_LOGERROR("udp socket select timeout");
		return -1;
	}
	if (FD_ISSET(m_udp_client_fd, &fds_read))
	{
		result = recvfrom(m_udp_client_fd, chardata, 1024, 0, (sockaddr *)&addr, &addrlength);
	}
	else
	{
		//MY_LOGERROR("udp socket, m_udp_client_fd is NOT ready");
		return -1;
	}

	if (result == -1)
	{
		//MY_LOGERROR("udp recvfrom failed, errno="<<errno<<" strerr="<<strerror(errno));
		return -1;
	}

	str_recvdata.append(chardata, result);
	return result;


	
}

int udp_client::udp_close( void )
{
	if (m_udp_client_fd != -1)
	{
		close(m_udp_client_fd);
		m_udp_client_fd = -1;
	}
}
