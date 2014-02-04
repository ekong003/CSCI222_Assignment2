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

//#include "mydb_class.h"
#include "BookingSystemManager.h"


/*
 * 
 */
int main( int argc, char** argv ) 
{
    STB::BookingSystemManager cBookingSystemMgr;
    cBookingSystemMgr.Run();   
}

