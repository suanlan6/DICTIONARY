#include "mysqlmanager.h"
#include <iostream>
#include <vector>
#include <string>
#include "word.h"
using namespace std;


// �������ݿ�
bool MySQLManager::Init(ConnectionInfo& info) {
    // ��ʼ��mysql,����mysql�����ݿ�
    mysql_init(&m_mysql);

    // ����ʧ��
    if (!(mysql_real_connect(&m_mysql, info.host, info.user, info.password, info.database, info.port, info.unix_socket, info.clientflag)))
        return false;

    return true;
}

// �ͷ�����
bool MySQLManager::FreeConnect() {
    //�ͷ���Դ
    mysql_free_result(m_res);
    mysql_close(&m_mysql);
    mysql_library_end();//�ر�MySQL��
    return true;
}

// ִ��sql���, �������ӡ�ɾ������������
bool MySQLManager::ExecuteSql(const char * sql) {
    if (mysql_query(&m_mysql, sql)) {
        // �����log������ֱ����ʾ������̨
        cerr << "ִ��sql���ʧ�ܣ�������ϢΪ�� " << mysql_error(&m_mysql) << endl;
        return false;
    }
    else
        cout << "ִ��sql���ɹ���" << endl;

    return true;
}

// ��ѯ����
MYSQL_RES* MySQLManager::QueryData(const char* sql)
{
    if (mysql_query(&m_mysql, sql)) {
        // �����log������ֱ����ʾ������̨
        cerr << "��ѯ���ִ��ʧ�ܣ�������ϢΪ�� " << mysql_error(&m_mysql) << endl;
        return nullptr;
    }

    // �洢��ѯ���
    m_res = mysql_store_result(&m_mysql);

    return m_res;
}

// ���������
string MySQLManager::PrintQueryRes() {
    if (nullptr == m_res || NULL == m_res)
        return "";

    // �ֶ�������
    MYSQL_FIELD* field = nullptr;

    // ��ȡ����
    int columns = mysql_num_fields(m_res);

    MYSQL_ROW row;
    vector<string> res;
    string ans;
    int total = 0;
    while (row = mysql_fetch_row(m_res)) {
        //cout << splitChinese(row[2]);
        //printf("%s", splitChinese(row[2]).c_str());
        ans = splitChinese(row[2]);
        total++;
    }
    return ans;
}