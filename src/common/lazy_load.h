#pragma once




/*
˵������ģ����Ҫ���ڴ�����Լ������̵Ĺ̻�
�����д����Ķ��Լ��أ����´������̴���copy��paste����������bug
����boost::function���ƣ�ʵ�ֶ��Լ������̴����Ψһ���Լ���ҵ�����ĸ���

�Լ��غ����ķ�����Ҫ���չ涨���践�أ�

��ȡ���ͣ�
-1�� ���ش����ʧ��
0��  ���سɹ�����ȡ���ݸ���Ϊ0
>0:  ���سɹ�����ȡ���ݸ���
д�����ͣ�
-1:  д��ʧ��
0��  д��ɹ�


ע������m_func_dbread����m_func_dbwrite�����Բ�ͬʱ����

*/
#include "mycommon.h"
#include "boost/lambda/lambda.hpp"
#include "boost/bind.hpp"
#include "boost/lambda/bind.hpp"

class lazy_load
{
public:
	lazy_load(void);
	~lazy_load(void);

	// 
	void bind_function(boost::function<int(void)> dbread, boost::function<int(void)> dbwrite,
					   boost::function<int(void)> cacheread, boost::function<int(void)> cachewrite);

	int read(void);
	int write(void);

private:
	boost::function<int(void)> m_func_dbread;
	boost::function<int(void)> m_func_dbwrite;
	boost::function<int(void)> m_func_cacheread;
	boost::function<int(void)> m_func_cachewrite;

};
