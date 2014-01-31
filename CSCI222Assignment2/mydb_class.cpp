/* 
 * File:   mydb_class.cpp
 * Author: cino
 * 
 * Created on January 31, 2014, 12:39 PM
 */

#include "mydb_class.h"

mydb_class::mydb_class(string host,string uname,string password) {
   
  try {
      
     driver = get_driver_instance();
     host ="tcp://"+host+":3306";
     cout<<host<<endl;
     conn = driver->connect(host,uname,password);
   }
   catch(sql::SQLException &e ){
        
        cout<<"# Err: SQLException in "<<__FILE__;
        cout<<"("<<__FUNCTION__<<") on line " <<__LINE__<<endl;
        cout<<"# ERR: "<< e.what();
        cout<<" (MYSQL error code :"<<e.getErrorCode();
        cout<<" , SQLState :"<<e.getSQLState()<<" )"<<endl;
         
     }

   }

void mydb_class::DeleteConnection(){
    
        //delete res;
        //delete stmt;
        delete conn;
    
    
}



mydb_class::~mydb_class() {
    
}

