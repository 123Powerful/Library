#include <iostream>
#include "User.h"
#include "FileUtil.h"
#include "Manager.h"
#include "DBUtil.h"
#include "Student.h"
#include "Book.h"
using namespace std;

int main()
{
	string strUserName = "";
	string strUserPWD = "";
	User user;
	cout << "             �������û�����";
	cin >> strUserName;
	cout << endl;
	cout << "             ���������룺";
	cin >> strUserPWD;
	cout << endl;
	DBUtil dbUtil;
	user = dbUtil.ReadUser(strUserName, strUserPWD);
	if (user.GetUserID() == 0)
	{
		Manager manager(user);
		manager.ShowMenu();
		int command = -1;		//ѡ������
		while (1)
		{
			cout << "��ѡ�����";
			cin >> command;
			switch (command)
			{
			case 1:
				Book book;
				cout << "��ѡ���������ͼ�鹦�ܣ�";
				cout << "������ͼ�����ƣ�";
			default:
				break;
			}
		}
	}
	else
	{
		Student student;
		student.ShowMenu();
	}
	cin.get();
	cin.get();
	return 0;
}