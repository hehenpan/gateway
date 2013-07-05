#ifndef RVSGEO_H
#define RVSGEO_H

#include <errno.h>
#include <string>
#include <iostream>
#include <fstream>
#include <map>
#include <algorithm>
#include <float.h>
#include <limits.h>
#include <math.h>
#include <pthread.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <sys/types.h>
#include <time.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <stdarg.h>
#include <pthread.h>
#include <list>
#include <vector>

#include "stdlib.h"
#include "string.h"
#include "sys/resource.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
//#include <mysql.h>
#include <signal.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
//#include "tinyxml.h"

// ------------BOOST LIB HEADER-------------------
#include "boost/smart_ptr.hpp"
#include "boost/function.hpp"
#include "boost/bind.hpp"
#include "boost/bimap.hpp"
#include "boost/foreach.hpp"
#include "boost/algorithm/string.hpp"

#include <boost/property_tree/ptree.hpp>  
#include <boost/property_tree/xml_parser.hpp>  

#define STRTOD(PTR, END_PTR) ((PTR == NULL)? DBL_MAX: strtod(PTR, END_PTR))
#define STRTOULL(PTR, END_PTR, BASE) ((PTR == NULL)? ULLONG_MAX: strtoull(PTR, END_PTR, BASE))

#define MAX_BUFF_LENGTH   1024

//
//
//int loadconfig(char *filename);
//
//int initlog4cxx(const char *config);
//
int printstring(std::string &str);
//
int printstring2str(std::string &str_src, std::string &str_dst);
//
void erasestr(std::string &str);
//void maketimeout_minutes(timespec *tsp, int minutes);
//
//void maketimeout_seconds(timespec *tsp, int seconds);


//typedef   unsigned char  BYTE;
typedef   unsigned char  byte;
typedef   unsigned short word;
typedef   unsigned short WORD;
typedef   unsigned int   dword;
typedef   unsigned int   DWORD;



void hton32(uint32_t *a);



#define SCOPED_LOCK_LOCKED   0
#define SCOPED_LOCK_UNLOCKED 1
class scopedlock
{
public:

	scopedlock(pthread_mutex_t *p_mutex)
	{
		m_p_mutex = p_mutex;
		pthread_mutex_lock(m_p_mutex);
		m_lock_tag = SCOPED_LOCK_LOCKED;
	}

	~scopedlock()
	{
		if(m_lock_tag == SCOPED_LOCK_LOCKED)
		{
			pthread_mutex_unlock(m_p_mutex);
		}
	}

	void unlock()
	{
		if(m_lock_tag == SCOPED_LOCK_LOCKED)
		{
			pthread_mutex_unlock(m_p_mutex);
			m_lock_tag = SCOPED_LOCK_UNLOCKED;
		}
	}

private:
	int m_lock_tag;
	pthread_mutex_t *m_p_mutex;
};


int getcurrentimestr(char *ptime, int length);


#define STRTOULL(PTR, END_PTR, BASE) ((PTR == NULL)? ULLONG_MAX: strtoull(PTR, END_PTR, BASE))

#define MACRO_MEM_ZERO(data)  memset(&data, 0, sizeof(data))

class MyMutex
{
public:
	MyMutex(){ pthread_mutex_init(&m_mutex, NULL);}
	~MyMutex(){pthread_mutex_destroy(&m_mutex);}
	pthread_mutex_t *get(void){ return &m_mutex;}
private:
	pthread_mutex_t m_mutex;
};


uint64_t atoi64(const char *pstr);


#define APPEND_STREAM(str, data)   str.append((char *)&data, sizeof(data))


#define  MAX(a,  b)  (  (a)>(b)?(a):(b) )
#define  MIN(a,  b)  (  (a)<(b)?(a):(b) )




#define    ONE_THOUSAND   1000
#define    TM_GMTOFF   28800  //8 hour tick recorded with second unit


void maketimeout_seconds(timespec *tsp, int seconds);



void EnableCoreFile(void);



//#define  MY_LOGERROR(logEvent) LOG4CPLUS_ERROR(logger, logEvent)    
//#define  MY_LOGDEBUG(logEvent) LOG4CPLUS_DEBUG(logger, logEvent)    
//#define  MY_LOGINFO(logEvent)  LOG4CPLUS_INFO(logger, logEvent)    
//#define  MY_LOGWARN(logEvent)  LOG4CPLUS_WARN(logger, logEvent)    


int pre_process_shell_cmd(std::string &str_cmd);

// ���ĩβ�� / ����Ĭ��ȥ��
int process_path_erase(std::string &str_file_path);


enum enum_running_mode
{
	enum_runing_mode_production=0,
	enum_runing_mode_test=1,
};

int set_running_mode(enum_running_mode mode);
enum_running_mode get_running_mode(void);
#define SIMULATION_DELAY  \
	if (get_running_mode() == enum_runing_mode_test) \
{ \
	MY_LOGINFO("SIMULATION_DELAY delay 1s"); \
	sleep(1); \
} \
	else \
{ \
	; \
}



void map2string(std::string &str_rtn, std::map<std::string, std::string> &map_src);
void string2map(std::string &str_src, std::map<std::string, std::string> &map_rtn);
void string2map_urldecode( std::string &str_src, std::map<std::string, std::string> &map_rtn );
std::string get_vaule(std::string key, std::map<std::string, std::string> &map_get);

#endif












