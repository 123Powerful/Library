#include "DBUtil.h"


DBUtil::DBUtil()
{
	szUsername = "root";
	szPswd = "ROOT";
	szHost = "localhost";
	szDatabase = "library";
	nPort = 3306;
	isOpen = false;
}


DBUtil::~DBUtil()
{
	CloseDB();
}

//�����ݿ�
bool DBUtil::OpenDB()
{
	mysql_init(&myCont);
	if (mysql_real_connect(&myCont, szHost.c_str(), szUsername.c_str(), szPswd.c_str(), szDatabase.c_str(), nPort, NULL, 0))
	{
		isOpen = true;
		return true;
	}
	return false;
}

//�ر����ݿ�
bool DBUtil::CloseDB()
{
	mysql_close(&myCont);//�Ͽ�����
	return true;
}



//�����û������������û���Ϣ
User DBUtil::ReadUser(string strUserName, string strUserPWD)
{
	User user;
	char column[32][32];
	int res;
	string sql;
	if (isOpen)
	{
		mysql_query(&myCont, "SET NAMES GBK"); //���ñ����ʽ,������cmd���޷���ʾ����
		sql += "select * from user where name='" + strUserName + "' and password='" + strUserPWD + "'";
		res = mysql_query(&myCont, sql.c_str());//��ѯ
		if (!res)
		{
			result = mysql_store_result(&myCont);//�����ѯ�������ݵ�result
			if (result)
			{
				int i, j;
				//cout << "number of result: " << (unsigned long)mysql_num_rows(result) << endl;
				for (i = 0; fd = mysql_fetch_field(result); i++)//��ȡ����
				{
					strcpy_s(column[i], fd->name);
				}
				j = mysql_num_fields(result);
				// 				for (i = 0; i < j; i++)
				// 				{
				// 					printf("%s\t", column[i]);
				// 				}
				//				printf("\n");
				// 				while (sql_row = mysql_fetch_row(result))//��ȡ���������
				// 				{
				// 					for (i = 0; i < j; i++)
				// 					{
				// 						printf("%s\n", sql_row[i]);
				// 					}
				// 					printf("\n");
				// 					
				// 				}
				if (j > 0)
				{
					sql_row = mysql_fetch_row(result);
					user.m_nID = atoi(sql_row[0]);
					user.m_strName = sql_row[1];
					user.m_nRole = atoi(sql_row[3]);
				}

				//fd = mysql_fetch_field(result);

			}
		}
		else
		{
			cout << "query sql failed!" << endl;
		}
	}
	else
	{
		cout << "connect failed!" << endl;
	}
	if (result != NULL)
	{
		mysql_free_result(result);//�ͷŽ����Դ
	}
	return user;
}

//����ͼ��
bool DBUtil::AddBook(Book book)
{
	string sql = "";
	int res;
	char szTotal[16];
	char szLeftNum[16];
	sprintf(szTotal, "%d", book.GetTotalNum());
	sprintf(szLeftNum, "%d", book.GetTotalNum());

	if (isOpen)
	{
		//���ʱ��
		mysql_query(&myCont, "SET NAMES GBK"); //���ñ����ʽ,������cmd���޷���ʾ����
		sql += "insert into book values(null,'" + book.GetBookName() + "','" + book.GetAuthor() + "','" + book.GetISBN() + "','" + book.GetPub() + "','" + book.GetInDate() + "', " + szTotal + ", " + szLeftNum + ")";
		mysql_query(&myCont, sql.c_str());
		cout << "����ͼ��ɹ�" << endl;
	}
	else
	{
		cout << "connect failed!" << endl;
	}
	cin.get();
	cin.get();
	return false;

}

//չʾ����ͼ��
bool DBUtil::DisplayAllBook(vector<Book> &books)
{
	char column[32][32];
	int res;
	string sql;
	if (isOpen)
	{
		mysql_query(&myCont, "SET NAMES GBK"); //���ñ����ʽ,������cmd���޷���ʾ����
		sql += "select * from book";
		res = mysql_query(&myCont, sql.c_str());//��ѯ
		if (!res)
		{
			result = mysql_store_result(&myCont);//�����ѯ�������ݵ�result
			if (result)
			{
				int i;
				while (sql_row = mysql_fetch_row(result))//��ȡ���������
				{
					Book book;
					book.SetBookID(atoi(sql_row[0]));
					book.SetBookName(sql_row[1]);
					book.SetAuthor(sql_row[2]);
					book.SetISBN(sql_row[3]);
					book.SetPub(sql_row[4]);
					book.SetInDate(sql_row[5]);
					book.SetTotalNum(atoi(sql_row[6]));
					book.SetLeftNum(atoi(sql_row[7]));
					books.push_back(book);
				}
			}
		}
		else
		{
			cout << "query sql failed!" << endl;
		}
	}
	else
	{
		cout << "connect failed!" << endl;
	}
	if (result != NULL)
	{
		mysql_free_result(result);//�ͷŽ����Դ
	}

	return true;
}


bool DBUtil::SelectBookByName(string strBookName, vector<Book> &books)
{
	char column[32][32];
	int res;
	string sql;
	if (isOpen)
	{
		mysql_query(&myCont, "SET NAMES GBK"); //���ñ����ʽ,������cmd���޷���ʾ����
		sql += "select * from book where bookname like '%" + strBookName + "%'";
		res = mysql_query(&myCont, sql.c_str());//��ѯ
		if (!res)
		{
			result = mysql_store_result(&myCont);//�����ѯ�������ݵ�result
			if (result)
			{
				int i;
				while (sql_row = mysql_fetch_row(result))//��ȡ���������
				{
					Book book;
					book.SetBookID(atoi(sql_row[0]));
					book.SetBookName(sql_row[1]);
					book.SetAuthor(sql_row[2]);
					book.SetISBN(sql_row[3]);
					book.SetPub(sql_row[4]);
					book.SetInDate(sql_row[5]);
					book.SetTotalNum(atoi(sql_row[6]));
					book.SetLeftNum(atoi(sql_row[7]));
					books.push_back(book);
				}
			}
		}
		else
		{
			cout << "query sql failed!" << endl;
		}
	}
	else
	{
		cout << "connect failed!" << endl;
	}
	if (result != NULL)
	{
		mysql_free_result(result);//�ͷŽ����Դ
	}
	return true;
}


bool DBUtil::SelectBookById(int nBookId, Book &book)
{
	char column[32][32];
	int res;
	string sql;
	char szBookId[5] = {0};
	sprintf(szBookId, "%d", nBookId);
	if (isOpen)
	{
		mysql_query(&myCont, "SET NAMES GBK"); //���ñ����ʽ,������cmd���޷���ʾ����
		sql += "select * from book where id=";
		sql += szBookId;
		res = mysql_query(&myCont, sql.c_str());//��ѯ
		if (!res)
		{
			result = mysql_store_result(&myCont);//�����ѯ�������ݵ�result
			if (result)
			{
				int i;
				while (sql_row = mysql_fetch_row(result))//��ȡ���������
				{
					book.SetBookID(atoi(sql_row[0]));
					book.SetBookName(sql_row[1]);
					book.SetAuthor(sql_row[2]);
					book.SetISBN(sql_row[3]);
					book.SetPub(sql_row[4]);
					book.SetInDate(sql_row[5]);
					book.SetTotalNum(atoi(sql_row[6]));
					book.SetLeftNum(atoi(sql_row[7]));
				}
			}
		}
		else
		{
			cout << "query sql failed!" << endl;
		}
	}
	else
	{
		cout << "connect failed!" << endl;
	}
	if (result != NULL)
	{
		mysql_free_result(result);//�ͷŽ����Դ
	}
	return true;
}

bool DeleteBookById(int nBookId);

bool DBUtil::DeleteBookById(int nBookId)
{
	char column[32][32];
	int res;
	string sql;
	char szBookId[5] = {0};
	sprintf(szBookId, "%d", nBookId);
	if (isOpen)
	{
		mysql_query(&myCont, "SET NAMES GBK"); //���ñ����ʽ,������cmd���޷���ʾ����
		sql += "delete from book where id=" ;
		sql += szBookId;
		res = mysql_query(&myCont, sql.c_str());//��ѯ
		if (!res)
		{
			cout << "ɾ���ɹ���" << endl;
		}
		else
		{
			cout << "query sql failed!" << endl;
		}
	}
	else
	{
		cout << "connect failed!" << endl;
	}

	return true;
}