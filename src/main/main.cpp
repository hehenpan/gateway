


//#include "module_test.h"
#include "mycommon.h"
#include "SDConfigurationSingleton.h"
//#include <log4cxx/configurator.h>
#include "log.h"
using namespace log4cxx;

#include <sys/types.h>
#include <sys/wait.h>
//#include "dispatcher.h"

//#include "unit_test.h"

void init_config(void)
{ 
	std::string config_file;
	config_file ="../conf/loginserver.conf";
	SDConfiguration* config = new SDConfiguration(config_file.c_str());
	if (!config->load()) 
	{
		//LOG4CPLUS_ERROR(logger, "read config_file \"" << m_conf_file << "\" fail: " << strerror(errno));
		printf("failed to load config file path=%s\n", config_file.c_str());
		delete config;
		exit(0);
	}
	SDConfigurationSingleton::get_instance()->init(config);



}

void sign_t(int sign)
{
	printf("error!! in thread %u\n", (unsigned int) pthread_self());
	abort();
}


int main(int argc, char* argv[])
{

	
	//return 0;
	if (argc >= 2)
	{
		char *pparam = argv[1];
		std::string str_param=pparam;
		if (!str_param.compare("daemon"))
		{
			printf("become guard\n");
			printf("become daemon\n");
			daemon(1, 1);
			do 
			{
				pid_t pid;
				pid = fork();
				if (pid == 0)
				{// child process
					break;
				}
				else
				{
					int status=0;
					waitpid(pid, &status, 0);
					sleep(5);
					printf("child process exit, restart child process\n");
				}
			} while (true);
		}
		else
		{
			printf("become app \n");
		}
	}

	
	
	try
	{
		log4cxx::PropertyConfigurator::configure("../conf/log.conf");

	}
	catch(log4cxx::helpers::Exception&)
	{
		printf("failed to config logger\n");
		//cerr << "failed to config logger" << endl;
		return false;
	}

	gLogger = log4cxx::Logger::getRootLogger();

	MYLOG_DEBUG("--- gateway server started ------");

	
	

	EnableCoreFile();

	
	signal(SIGPIPE, SIG_IGN);
	//debug
	signal(SIGSEGV, sign_t);

	signal(SIGIO, SIG_IGN);
	//signal(SIGINT, SIG_IGN);
	signal(SIGALRM, SIG_IGN);

	init_config();

	//unit_test mytest;
	//mytest.general_test();


	//dispatcher service;
	//service.init_dispatcher();

	

	

	while(true)
	{
		sleep(1000000);
	}
	
	return 0;
}
