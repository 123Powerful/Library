#include "Student.h"

Student::Student()
{
}

Student::Student(User user)
{
	SetUserID(user.GetUserID());
	SetUserName(user.GetUserName());
	SetUserPWD(user.GetUserPWD());
	SetUserRole(user.GetUserRole());
}

Student::~Student()
{
}

void Student::ShowMenu()
{
	system("cls");
	cout << "     ============================��ӭʹ��ͼ��ݺ�̨����ϵͳ��===========================" << endl;
	cout << "                                  1.����¼��2��" << endl;
	cout << "                                  2.ͼ���ѯ2��" << endl;
	cout << "                                  3.�û���ѯ2��" << endl;
	cout << "                                  4.���׼�¼��ѯ2��" << endl;
	cout << "                                  1.����¼��2��" << endl;
}
