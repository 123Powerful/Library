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
	cout << "==========================��ӭʹ��ͼ��ݺ�̨����ϵͳ��==========================" << endl;
	cout << "                              1.����¼��" << endl;
	cout << "                              2.ͼ���ѯ" << endl;
	cout << "                              3.ͼ���ѯ" << endl;
	cout << "                              4.�鿴�ֿ�" << endl;
	cout << "                              5.���ļ�¼" << endl;
	cout << "                              6.����ͳ��" << endl;
	cout << "                              7.�����û�" << endl;
	cout << "                              8.��ѯ�û�" << endl;
	cout << "                              0.�˳���¼" << endl;
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
	book.SetPub(pub);
	book.SetTotalNum(total);
	book.SetLeftNum(0);
	book.SetInDate(szTime);

	m_dbUtil.OpenDB();
	m_dbUtil.addBook(book);
	return true;
}

//չʾ�����鼮
bool Manager::DisplayBook()
{
	return true;
}