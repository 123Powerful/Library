#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <winsock.h>
#include <mysql.h> 
#include <iostream>
#include "User.h"
#include "Book.h"
#include "TimeUtil.h"
#pragma once
class DBUtil
{
public:
	DBUtil();
	~DBUtil();
	bool OpenDB();
	bool CloseDB();
	User ReadUser(string strUserName, string strUserPWD);
	bool addBook(Book book);
public:
	string szUsername;			//�û���
	string szPswd;				//����
	string szHost;				//������
	string szDatabase;			//���ݿ���
	int nPort;					//�˿ں�  
	MYSQL myCont;
	MYSQL_RES *result;
	MYSQL_ROW sql_row;
	MYSQL_FIELD *fd;
	bool isOpen;
	TimeUtil timeUtil;
};

