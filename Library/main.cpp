#include <iostream>
#include "User.h"
#include "FileUtil.h"
#include "Manager.h"
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
	FileUtil file;
	user = file.ReadUser(strUserName, strUserPWD);
	if (user.GetUserID() > 0)
	{
		Manager manager;
		manager.ShowMenu();
	}
	cin.get();
	cin.get();
	return 0;
}