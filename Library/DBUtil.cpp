#include "DBUtil.h"


DBUtil::DBUtil()
{
}


DBUtil::~DBUtil()
{
}

//�����û������������û���Ϣ
User DBUtil::ReadUser(string strUserName, string strUserPWD)
{
	User user;
	::CoInitialize(NULL); // ��ʼ��OLE/COM�⻷�� ��Ϊ����ADO�ӿ���׼��
	_RecordsetPtr m_pRecordset("ADODB.Recordset");
	_ConnectionPtr m_pConnection("ADODB.Connection");
	string sql = "select * from [user]  where name='" + strUserName + "' and password='" + strUserPWD + "'";
	_bstr_t bstrSQL((wchar_t *)(_bstr_t(sql.c_str()))); //��ѯ��� 
	try
	{
		// ����Connection����
		m_pConnection.CreateInstance("ADODB.Connection");
		// ���������ַ�����������BSTR�ͻ���_bstr_t����
		_bstr_t strConnect = "Provider=SQLOLEDB;Server=.\\SQLEXPRESS;Database=library; uid=sa; pwd=root;";
		//�����ݿ�����������ServerΪ����(192.168.1.5,3340)
		//�û�sa������123ֻ������ҵĿ� 
		m_pConnection->Open(strConnect, "", "", adModeUnknown);
		if (m_pConnection == NULL)
			cerr << "Lind data ERROR!\n";
		// ������¼������
		m_pRecordset.CreateInstance(__uuidof(Recordset));
		// ȡ�ñ��еļ�¼
		m_pRecordset->Open(bstrSQL, m_pConnection.GetInterfacePtr(),
			adOpenDynamic, adLockOptimistic, adCmdText);
		int nUserID = 0;
		string strName = "";
		string strPassWord = "";
		int nRole = 0;
		while (!m_pRecordset->EndOfFile)
		{
			nUserID = m_pRecordset->GetCollect("id");//������ֶα�ź��ֶ��������� 
			strName = (const char*)_bstr_t(m_pRecordset->GetCollect("name"));
			strPassWord = (const char*)_bstr_t(m_pRecordset->GetCollect("password"));
			nRole = m_pRecordset->GetCollect("role");
			if (strName == strUserName && strPassWord == strUserPWD)
			{
				user.SetUserID(nUserID);
				user.SetUserName(strUserName);
				user.SetUserPWD(strUserPWD);
				user.SetUserRole(nRole);
				return user;
			}
			m_pRecordset->MoveNext(); ///�Ƶ���һ����¼
		}

		//m_pRecordset->MoveFirst(); //�ƶ�����һ����¼
		//m_pRecordset->AddNew(); ///����¼�¼
		//m_pRecordset->PutCollect("snum", _variant_t(student.snum));
		//m_pRecordset->PutCollect("sname", _variant_t(student.sname));
		//m_pRecordset->PutCollect("sage", _variant_t(student.sage));
		//m_pRecordset->PutCollect("ssex", _variant_t(student.ssex));
		//m_pRecordset->PutCollect("smajor", _variant_t(student.smajor));
		//m_pRecordset->Update();
		//m_pConnection->Execute(query_cmd, NULL, 1); //��Executeִ��sql�����ɾ��
		//m_pRecordset->Close(); // �رռ�¼��
	}
	// ��׽�쳣
	catch (_com_error e)
	{
		// ��ʾ������Ϣ
		cerr<<"\nERROR:"<<(char*)e.Description();//�׳��쳣
	}
	if (m_pConnection->State)
		m_pConnection->Close();
	::CoUninitialize();
	return user;
}
