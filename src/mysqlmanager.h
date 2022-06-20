//mysqlmanager.h
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
    const char*    host;            // 主机名
    const char*    user;            // 用户名
    const char*    password;        // 密码
    const char*    database;        // 数据库名
    unsigned int   port;            // 端口号
    const char*    unix_socket;     // uinx socket
    unsigned long  clientflag;      // 用户状态

    // 初始化用户连接
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
// 连接数据库
    bool Init(ConnectionInfo& info);

    // 关闭数据库连接
    bool FreeConnect();

    //执行sql语句
    bool ExecuteSql(const char* sql);

    // 获得查询结果
    MYSQL_RES* QueryData(const char* sql);

    // 输出查询结果
    std::string PrintQueryRes();

private:
    MYSQL m_mysql;                // mysql操作实体
    MYSQL_RES* m_res;            // 查询结果集
};
#endif