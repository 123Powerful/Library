#include "Manager.h"

Manager::Manager()
{
}

Manager::Manager(User user)
{
	SetUserID(user.GetUserID());
	SetUserName(user.GetUserName());
	SetUserPWD(user.GetUserPWD());
	SetUserRole(user.GetUserRole());
}

Manager::~Manager()
{
}


void Manager::ShowMenu()
{
	system("cls");
	cout << "     ============================��ӭʹ��ͼ��ݺ�̨����ϵͳ��===========================" << endl;
	cout << "                                  1.����¼�룺" << endl;
	cout << "                                  2.ͼ���ѯ��" << endl;
	cout << "                                  3.�û���ѯ��" << endl;
	cout << "                                  4.���׼�¼��ѯ��" << endl;
	cout << "                                  1.����¼�룺" << endl;
}