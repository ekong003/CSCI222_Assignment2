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

namespace STB{

class mydb_class {
public:
    mydb_class(std::string,std::string,std::string);
    void DeleteConnection();
    sql::ResultSet* DbFetchArray(std::string);
    int DbInsert(std::string);
    bool DbUpdate(std::string);
    bool DbDelete(std::string);
    virtual ~mydb_class();
private:
        
        sql::Driver *driver;
        sql::Connection *conn;
        sql::ResultSet *res;
        sql::Statement *stmt;
        sql::PreparedStatement* pstmt;
    

};

}
#endif	/* MYDB_CLASS_H */

