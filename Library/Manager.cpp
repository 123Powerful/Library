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
	cout << "                              3.ɾ��ͼ��" << endl;
	cout << "                              4.ͼ���б�" << endl;
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

	if (!m_dbUtil.isOpen)
	{
		m_dbUtil.OpenDB();
	}
	m_dbUtil.AddBook(book);
	return true;
}

//չʾ�����鼮
bool Manager::DisplayAllBook()
{
	vector<Book> books;
	if (!m_dbUtil.isOpen)
	{
		m_dbUtil.OpenDB();
	}
	
	m_dbUtil.DisplayAllBook(books);
	vector<Book>::iterator vecIter;
	cout << "ID     ����            ����           ������       �������     �ݲ�����   ����" << endl;
	for (vecIter = books.begin(); vecIter != books.end(); vecIter ++)
	{
		//char szRecord[1024] = {0};
		//sprintf(szRecord, "%3d  %7s", vecIter->GetBookID(), vecIter->GetBookName());
		//sprintf(szRecord, "%3d    %7s    %5s    %11s    %11s    %10s    %2d    %2d", vecIter->GetBookID(), vecIter->GetBookName(), vecIter->GetAuthor(), vecIter->GetISBN(), vecIter->GetPub(), vecIter->GetInDate(), vecIter->GetTotalNum(), vecIter->GetLeftNum());
		//cout << szRecord << endl;
		cout << setiosflags(ios::left) << setw(4) << vecIter->GetBookID() << "  " << setw(14) << vecIter->GetBookName() << "  " << setw(10) << vecIter->GetAuthor() << "  " << setw(14) << vecIter->GetPub() << "  " << setw(14) << vecIter->GetInDate() << "  " << setw(8) << vecIter->GetTotalNum() << "  " << setw(3) << vecIter->GetLeftNum() << endl;
	}
	cin.get();
	cin.get();
	return true;
}

bool Manager::QueryBook(string strBookName)
{
	vector<Book> books;
	if (!m_dbUtil.isOpen)
	{
		m_dbUtil.OpenDB();
	}

	m_dbUtil.SelectBookByName(strBookName, books);
	vector<Book>::iterator vecIter;
	cout << "ID     ����            ����           ������       �������     �ݲ�����   ����" << endl;
	for (vecIter = books.begin(); vecIter != books.end(); vecIter++)
	{
		//char szRecord[1024] = {0};
		//sprintf(szRecord, "%3d  %7s", vecIter->GetBookID(), vecIter->GetBookName());
		//sprintf(szRecord, "%3d    %7s    %5s    %11s    %11s    %10s    %2d    %2d", vecIter->GetBookID(), vecIter->GetBookName(), vecIter->GetAuthor(), vecIter->GetISBN(), vecIter->GetPub(), vecIter->GetInDate(), vecIter->GetTotalNum(), vecIter->GetLeftNum());
		//cout << szRecord << endl;
		cout << setiosflags(ios::left) << setw(4) << vecIter->GetBookID() << "  " << setw(14) << vecIter->GetBookName() << "  " << setw(10) << vecIter->GetAuthor() << "  " << setw(14) << vecIter->GetPub() << "  " << setw(14) << vecIter->GetInDate() << "  " << setw(8) << vecIter->GetTotalNum() << "  " << setw(3) << vecIter->GetLeftNum() << endl;
	}
	cin.get();
	cin.get();
	return true;
}