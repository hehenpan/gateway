#if !defined _CMYSQL_H
#define _CMYSQL_H

#include <stdio.h>
#include <string>
#include <map>
#include <vector>
#include <mysql.h>
#include <sys/types.h>
#include "cexception.h"
#include <stdint.h>

typedef map<string, int> STRING2INT;

class SDDBConnectionPool;
	
class CMysql
{
public:
	CMysql();
	CMysql(const char* szHost, 
		   const char* szUser, 
		   const char* szPass, 
		   const char* szDataBase,
		   unsigned int iPort =0,
		   const char* szSocket = NULL,
		   unsigned long iClientFlag = 0);
	~CMysql();

	int Close();
	int Connect(const char* szHost, 
				const char* szUser, 
				const char* szPass, 
				const char* szDataBase,
				unsigned int iPort =0,
				const char* szSocket = NULL,
				unsigned long iClientFlag = 0);
	int Connect();
	bool IfConnected(const char* szHost);

	int Query(char* szSqlString);
	int Query(string& szSqlString);
	int StoreResult();
	int FreeResult();
	char** FetchRow();
	const char* GetFieldName(int iField);
	char* GetField(unsigned int iField);
	char* GetField(char* szFieldName);
    char* GetFieldBinary(const char* szFieldName, int& iFieldLen);
    char* GetFieldBinary(unsigned int iField, int& iFieldLen);

	unsigned int GetErrorNo(void);
    
	int GetAffectedRows();
	unsigned int GetAffectedCols() {
		return m_iField;
	};
	MYSQL* GetConnectHandle() { return &m_connection; }

	static int EscapeString (string &str);
    static void Escape(string& str_out, char* buf_in, int buf_in_len);

	unsigned int GetLastInsertId();
	unsigned int  m_iRows;
	unsigned int  m_iField;

	void record_query(char* szSqlString);
	
	static std::string get_statistic(int reset);
	
protected:
	char *m_ErrMsg;
	char  m_szHost[65];	    // ���ݿ�������
	char  m_szUser[65];	    // ���ݿ��û���
	char *m_szPass;	    // ���ݿ��û�����
	char  m_szDataBase[65]; // ���ݿ���
	char *m_szSocket;
	unsigned int m_iPort;
	unsigned long m_iClientFlag;
	
	
	MYSQL m_connection;
	MYSQL_RES *m_result;
	MYSQL_ROW m_row;
	STRING2INT m_FieldIndex;
	bool m_bFieldIndexInitialized;
	bool m_bConnected, m_bIfConfig,m_isuse;

	int InitFieldName();

private:
	// ͳ�����ݲ�ѯ(��/д)���� , û�м�������������race condition
	static uint32_t m_query_num;
	static uint32_t m_read_num;
	static uint32_t m_write_num;
	static std::map<std::string,uint32_t> m_db_read;
	static std::map<std::string,uint32_t> m_db_write;
	
	friend class SDDBConnectionPool;
};

#endif //_CMYSQL_H
