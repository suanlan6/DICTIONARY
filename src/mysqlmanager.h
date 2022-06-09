#ifndef _MYSQLMANAGER_H
#define _MYSQLMANAGER_H
#include <winsock2.h>
#include <windows.h>
#include <string>
#include "F:\\mysql\\mysql-8.0.28-winx64\\include\\mysql.h"

#pragma comment(lib,"libmysql.lib")

const std::string SQLquerry1 = "select * from dictionary1 where english = '";
//const string SQLquerry2 = "select * from dictionary2 where english = '";
const std::string SQLend = "' limit 1;";

static const char* HOST                = "127.0.0.1";
static const char* USER                = "root";
static const char* PASSWORD            = "hmf666";
static const char* DATABASE            = "test";
static const int   PORT                = 12345;
static const char* UNIX_SOCKET         = nullptr;
static const unsigned long CLIENT_FLAG = 0;
 
struct ConnectionInfo {
    const char*    host;            // ������ַ
    const char*    user;            // �û���
    const char*    password;        // ����
    const char*    database;        // ���ݿ���
    unsigned int   port;            // �˿ں�
    const char*    unix_socket;     // unix���ӱ�ʶ
    unsigned long  clientflag;      // �ͻ������ӱ�־

    // ���캯��������һЩĬ��ֵ
    ConnectionInfo() :
        host(HOST),
        user(USER),
        password(PASSWORD),
        database(DATABASE),
        port(PORT),
        unix_socket(UNIX_SOCKET),
        clientflag(CLIENT_FLAG)
    {
    }
};

class MySQLManager {
public:
// �������ݿ�
    bool Init(ConnectionInfo& info);

    // �ͷ�����
    bool FreeConnect();

    bool ExecuteSql(const char* sql);

    // ��ѯ����
    MYSQL_RES* QueryData(const char* sql);

    // ��ӡ�����
    std::string PrintQueryRes();

private:
    MYSQL m_mysql;                // mysql����
    MYSQL_RES* m_res;            // ��ѯ�����
};
#endif