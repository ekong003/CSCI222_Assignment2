/* 
 * File:   mydb_class.h
 * Author: cino
 *
 * Created on January 31, 2014, 12:39 PM
 */

#ifndef MYDB_CLASS_H
#define	MYDB_CLASS_H

#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>


#include <mysql_connection.h>
#include <cppconn/driver.h>
#include <cppconn/exception.h>
#include <cppconn/resultset.h>
#include <cppconn/statement.h>

using namespace std;

class mydb_class {
public:
    mydb_class(string,string,string);
    void DeleteConnection();
    sql::ResultSet* DbFetchArray(string);
    int DbInsert(string);
    bool DbUpdate(string);
    bool DbDelete(string);
    virtual ~mydb_class();
private:
        
        sql::Driver *driver;
        sql::Connection *conn;
        sql::ResultSet *res;
        sql::Statement *stmt;
        sql::PreparedStatement* pstmt;
    

};

#endif	/* MYDB_CLASS_H */
