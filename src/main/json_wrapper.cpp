#include "json_wrapper.h"

json_wrapper::json_wrapper(void)
{
	m_is_encoded = false;
	m_pjsonobj = NULL;
}

json_wrapper::~json_wrapper(void)
{
	if (m_pjsonobj != NULL)
	{
		cJSON_Delete(m_pjsonobj);
		m_pjsonobj = NULL;
	}
}

void json_wrapper::add_kv( std::string key, std::string value )
{
	m_map_param.insert(make_pair(key, value));

}

int json_wrapper::encode_get_json_string( std::string &str_json )
{
	if (m_is_encoded == true)
	{
		return -1;
	}
	m_is_encoded= true;

	cJSON *pjsonobj = cJSON_CreateObject();
	if (pjsonobj == NULL)
	{
		return -1;
	}
	std::pair<std::string, std::string> iter;
	BOOST_FOREACH(iter, m_map_param)
	{
		cJSON_AddStringToObject(pjsonobj, iter.first.c_str(), iter.second.c_str());
	}

	char *pdata = cJSON_PrintUnformatted(pjsonobj);
	m_json_encoded = pdata;
	str_json = m_json_encoded;
	free(pdata);
	cJSON_Delete(pjsonobj);


	return 0;

}

int json_wrapper::parse_json( std::string &str_json)
{

	cJSON *pjsonobj = cJSON_Parse(str_json.c_str());
	if (pjsonobj == NULL)
	{
		return -1;
	}
	return 0;



}

std::string json_wrapper::get_value_string( std::string key )
{
	if (m_pjsonobj == NULL)
	{
		return "";
	}
	cJSON *pobj = cJSON_GetObjectItem(m_pjsonobj, key.c_str());
	if (pobj == NULL)
	{
		return "";
	}
	if (pobj->type != cJSON_String)
	{
		return "";
	}
	std::string value;
	value = pobj->valuestring;
	return value;

}