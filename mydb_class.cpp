/* 
 * File:   mydb_class.cpp
 * Author: cino
 * 
 * Created on January 31, 2014, 12:39 PM
 */

#include "mydb_class.h"
#include <string>
#include <vector>
using namespace std;

namespace STB{
    
STB::mydb_class::mydb_class(std::string host,std::string uname,std::string password) {
   
  try {
      
     driver = get_driver_instance();
     host ="tcp://"+host+":3306";
     //cout<<host<<endl;
     conn = driver->connect(host,uname,password);
     conn->setSchema("sql228692");
     stmt = conn->createStatement();
     
   }
   catch(sql::SQLException &e ){
        
        cout<<"# Err: SQLException in "<<__FILE__;
        cout<<"("<<__FUNCTION__<<") on line " <<__LINE__<<endl;
        cout<<"# ERR: "<< e.what();
        cout<<" (MYSQL error code :"<<e.getErrorCode();
        cout<<" , SQLState :"<<e.getSQLState()<<" )"<<endl;
         
     }

   }
//Returns a resultset.
sql::ResultSet* mydb_class::DbFetchArray(string qry){
    return res= stmt->executeQuery(qry);
    
}

int mydb_class::DbInsert(string query){
    int val=0;
    try{
        stmt->execute(query);
        res= stmt->executeQuery("SELECT LAST_INSERT_ID()");
        while(res->next()){
            val = res->getInt(1);
        }
    }catch(sql::SQLException &e){
        cout<<"# Err: SQLException in "<<__FILE__;
        cout<<"("<<__FUNCTION__<<") on line " <<__LINE__<<endl;
        cout<<"# ERR: "<< e.what();
        cout<<" (MYSQL error code :"<<e.getErrorCode();
        cout<<" , SQLState :"<<e.getSQLState()<<" )"<<endl;
    }
    return val;
}

bool mydb_class::DbUpdate(string query){
    bool val=false;
    try{
        val=stmt->execute(query);
        
    }catch(sql::SQLException &e){
        cout<<"# Err: SQLException in "<<__FILE__;
        cout<<"("<<__FUNCTION__<<") on line " <<__LINE__<<endl;
        cout<<"# ERR: "<< e.what();
        cout<<" (MYSQL error code :"<<e.getErrorCode();
        cout<<" , SQLState :"<<e.getSQLState()<<" )"<<endl;
    }
    return val;
    
}
bool mydb_class::DbDelete(string query){
   bool val=false;
    try{
        val=stmt->execute(query);
        
    }catch(sql::SQLException &e){
        cout<<"# Err: SQLException in "<<__FILE__;
        cout<<"("<<__FUNCTION__<<") on line " <<__LINE__<<endl;
        cout<<"# ERR: "<< e.what();
        cout<<" (MYSQL error code :"<<e.getErrorCode();
        cout<<" , SQLState :"<<e.getSQLState()<<" )"<<endl;
    }
    return val; 
}
void mydb_class::DeleteConnection(){
    
        //delete res;
        //delete stmt;
        delete conn;
    
    
}



mydb_class::~mydb_class() {
    
}

}