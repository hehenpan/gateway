#pragma once

#include "mycommon.h"

#include "cJSON.h"
class json_wrapper
{
public:
	json_wrapper(void);
	~json_wrapper(void);

	void add_kv(std::string key, std::string value);
	
	int encode_get_json_string(std::string &str_json);

	int parse_json(std::string &str_json);

	std::string get_value_string(std::string key);
private:
	std::map<std::string, std::string> m_map_param;
	bool m_is_encoded;
	std::string m_json_encoded;

	cJSON *m_pjsonobj;
};
