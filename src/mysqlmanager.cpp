//mysqlmanager.cpp
#include "mysqlmanager.h"
#include <iostream>
#include <vector>
#include <string>
#include "word.h"
using namespace std;


// 初始化，连接数据库
bool MySQLManager::Init(ConnectionInfo& info) {
    // 初始化数据库
    mysql_init(&m_mysql);

    // 连接数据库
    if (!(mysql_real_connect(&m_mysql, info.host, info.user, info.password, info.database, info.port, info.unix_socket, info.clientflag)))
        return false;

    return true;
}

// 关闭数据库连接
bool MySQLManager::FreeConnect() {
    //释放缓存结果
    mysql_free_result(m_res);
    mysql_close(&m_mysql);
    mysql_library_end();//关闭mysql连接
    return true;
}

//执行sql语句
bool MySQLManager::ExecuteSql(const char * sql) {
    if (mysql_query(&m_mysql, sql)) {
        // 打印错误信息
        cerr << "ִexecute problem " << mysql_error(&m_mysql) << endl;
        return false;
    }
    else
        cout << "ִsql语句执行成功" << endl;
    return true;
}

// sql查询语句执行
MYSQL_RES* MySQLManager::QueryData(const char* sql)
{
    if (mysql_query(&m_mysql, sql)) {
        // 打印错误信息
        cerr << "query problem " << mysql_error(&m_mysql) << endl;
        return nullptr;
    }

    // 生成结果集
    m_res = mysql_store_result(&m_mysql);
    return m_res;
}

// 输出结果集
string MySQLManager::PrintQueryRes() {
    // 查询结果为空，返回空字符串
    if (nullptr == m_res || NULL == m_res)
        return "";

    // 初始化数据库表单
    MYSQL_FIELD* field = nullptr;

    // 获取数据列数
    int columns = mysql_num_fields(m_res);

    MYSQL_ROW row;
    vector<string> res;
    string ans;
    int total = 0;
    
    // 获取每一行的中文结果
    while (row = mysql_fetch_row(m_res)) {
        ans = splitChinese(row[2]);
        total++;
    }
    return ans;
}