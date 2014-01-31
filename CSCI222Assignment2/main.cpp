/* 
 * File:   main.cpp
 * Author: cino
 *
 * Created on January 29, 2014, 7:24 PM
 */
#include <cstdlib>
#include <iostream>



#include <mysql_connection.h>
#include <cppconn/driver.h>
#include <cppconn/exception.h>
#include <cppconn/resultset.h>
#include <cppconn/statement.h>

/*
 * 
 */
int main(int argc, char** argv) {
   
    
 
    //
    try {
        sql::Driver *driver;
        sql::Connection *conn;
        sql::ResultSet *res;
        sql::Statement *stat;

        driver = get_driver_instance();
        conn = driver->connect("tcp://127.0.0.1:3306","root","csci222");
        //cout<<"Connected to the database"<<endl;
        
        delete res;
        delete stmt;
        delete conn;

    }
    catch(sql::SQLException &e ){
        
        cout<<"# Err: SQLException in "<<__FILE__;
        cout<<"("<<__FUNCTION__<<") on line " <<__LINE__<<endl;
        cout<<"# ERR: "<< e.what();
        cout<<" (MYSQL error code :"<<e.getErrorCode();
        cout<<" , SQLState :"<<e.getSQLState()<<" )"<<endl;
         
    }
    
    cout<<endl;
    return EXIT_SUCCESS;
    
}

