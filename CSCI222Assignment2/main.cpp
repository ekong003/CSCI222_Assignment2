/* 
 * File:   main.cpp
 * Author: cino
 *
 * Created on January 29, 2014, 7:24 PM
 */
#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>

#include <cppconn/resultset.h>

#include "mydb_class.h"

/*
 * 
 */
int main(int argc, char** argv) {
    
    //free hosting. ..
    mydb_class mydb("sql2.freemysqlhosting.net","sql228692","tX6!fE6!");
    //fetching result from db
    sql::ResultSet *res = mydb.DbFetchArray("SELECT * from package");
    while(res->next()){
        cout<<"Id : "<<res->getString(1);
    }
    //inserting data to db.
    //int val = mydb.DbInsert("INSERT INTO customer(customer_id,customer_name,customer_pwd) values('cino','Cino Jose','123')");
    //cout<<"Id is "<<val;
    //updating record to db
   mydb.DbUpdate("UPDATE customer set customer_name='CINO' WHERE customer_id='cino'");
   cout<<"Sucessfully Updated"<<endl;
   //delete from db
   mydb.DbDelete("delete from customer where customer_id ='cino'");
   cout<<"Deleted Sucessfully"<<endl;
   
}

