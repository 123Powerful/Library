#include "Manager.h"

Manager::Manager()
{
}


Manager::~Manager()
{
}


void Manager::ShowMenu()
{
	system("cls");
	cout << "============================��ӭʹ��ͼ��ݺ�̨����ϵͳ��============================" << endl;
	cout << "                                  1.����¼�룺" << endl;
	cout << "                                  2.ͼ���ѯ��" << endl;
	cout << "                                  3.�û���ѯ��" << endl;
	cout << "                                  4.���׼�¼��ѯ��" << endl;
	cout << "                                  5.����¼�룺" << endl;
}

bool Manager::AddBook()
{
	int id;
	string bookName;
	string author;
	string isbn;
	string pub;
	int total;
	char szTime[32] = {0};
	struct tm *ptr;
	time_t lt;
	lt = time(NULL);
	m_timeUtil.TimeToString(lt, szTime);

	cout << "��ѡ���������ͼ�鹦�ܣ�����������ͼ����Ϣ" << endl;
	cout << "ͼ������ ���� ISBN ������ �ܲ���" << endl;
	cin >> bookName;
	cin >> author;
	cin >> isbn;
	cin >> pub;
	cin >> total;

	Book book;
	book.SetBookName(bookName);
	book.SetAuthor(author);
	book.SetISBN(isbn);
	book.SetLeftNum(0);
	return true;
}