/* 
 * File:   main.cpp
 * Author: cino
 *
 * Created on January 29, 2014, 7:24 PM
 */
#include <cstdlib>
#include <iostream>

#include "mydb_class.h"

/*
 * 
 */
int main(int argc, char** argv) {
   
 mydb_class mydb("127.0.0.1","root","csci222");
 mydb.DeleteConnection();
 
    
    
}

