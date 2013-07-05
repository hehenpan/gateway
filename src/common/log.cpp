#include <string.h>                                                                                                                                                                          
#include <stdio.h>                                                                                                                                                                           
#include <stdarg.h>                                                                                                                                                                          
#include <log.h>                                                                                                                                                                  

log4cxx::LoggerPtr gLogger;

const char *log_format(const char *fmt, ...)                                                                                                                                                 
{                                                                                                                                                                                            
  va_list va;                                                                                                                                                                                
  static char formatted[2048];                                                                                                                                                               
  va_start(va, fmt);                                                                                                                                                                         
  vsnprintf(formatted, sizeof(formatted), fmt, va);                                                                                                                                                        
  va_end(va);
  
  return formatted;                                                                                                                                                                          
}

