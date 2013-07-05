#ifndef SD_CONFIGURATION_SINGLETON_H
#define SD_CONFIGURATION_SINGLETON_H

#include <common/SDConfiguration.h>

/* ʹ������Ϣȫ�ֻ����Ա������ط���Ҫʱ������*/
class SDConfigurationSingleton
{
public:
	~SDConfigurationSingleton(){delete m_config;}

	static SDConfigurationSingleton* get_instance(){return m_instance;}

	void init(SDConfiguration* config);
	const SDConfiguration& get_config() const;

protected:
	SDConfigurationSingleton(){m_config=NULL;}
	SDConfigurationSingleton(const SDConfigurationSingleton&){}
	SDConfigurationSingleton& operator=(const SDConfigurationSingleton&){return *this;}

private:
	static SDConfigurationSingleton* m_instance;

	SDConfiguration* m_config;
};

#endif /* end SD_CONFIGURATION_SINGLETON_H */

