#ifndef LOG_H
#define LOG_H

#include <log4cxx/logger.h>
#include <log4cxx/basicconfigurator.h>
#include <log4cxx/propertyconfigurator.h>
#include <log4cxx/helpers/exception.h>

extern log4cxx::LoggerPtr gLogger;
const char * log_format(const char *fmt, ...); 

//#define MYLOG_TRACE(logger, fmt, ...) LOG4CXX_TRACE(logger, log_format(fmt, ## __VA_ARGS__))                                                                                                 
//#define MYLOG_DEBUG(logger, fmt, ...) LOG4CXX_DEBUG(logger, log_format(fmt, ## __VA_ARGS__))                                                                                                 
//#define MYLOG_INFO(logger, fmt, ...) LOG4CXX_INFO(logger, log_format(fmt, ## __VA_ARGS__))                                                                                                   
//#define MYLOG_WARN(logger, fmt, ...) LOG4CXX_WARN(logger, log_format(fmt, ## __VA_ARGS__))                                                                                                   
//#define MYLOG_ERROR(logger, fmt, ...) LOG4CXX_ERROR(logger, log_format(fmt, ## __VA_ARGS__))                                                                                                 
//#define MYLOG_FATAL(logger, fmt, ...) LOG4CXX_FATAL(logger, log_format(fmt, ## __VA_ARGS__))


#define MYLOG_TRACE(fmt, ...) LOG4CXX_TRACE(gLogger, log_format(fmt, ## __VA_ARGS__))                                                                                                 
#define MYLOG_DEBUG(fmt, ...) LOG4CXX_DEBUG(gLogger, log_format(fmt, ## __VA_ARGS__))                                                                                                 
#define MYLOG_INFO(fmt, ...) LOG4CXX_INFO(gLogger, log_format(fmt, ## __VA_ARGS__))                                                                                                   
#define MYLOG_WARN(fmt, ...) LOG4CXX_WARN(gLogger, log_format(fmt, ## __VA_ARGS__))                                                                                                   
#define MYLOG_ERROR(fmt, ...) LOG4CXX_ERROR(gLogger, log_format(fmt, ## __VA_ARGS__))                                                                                                 
#define MYLOG_FATAL(fmt, ...) LOG4CXX_FATAL(gLogger, log_format(fmt, ## __VA_ARGS__))

#endif

