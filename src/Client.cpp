//===================================================================
/*
   CSCI 222 Assignment 2

   Implements Client.h
*/
//===================================================================

#include "Client.h"

//mysql result set include
#include <cppconn/resultset.h>

namespace STB
{

//====================
//    Class Client 
//====================
    
// Constructor
Client::Client( int nClientID ) : m_nID( nClientID ) {
    
    //STB::mydb("sql2.freemysqlhosting.net","sql228692","tX6!fE6!");
}

Client::Client( int nClientID, std::string strFirstName, std::string strLastName, std::string strAddress ) :
    m_nID( nClientID ),
    m_strFirstName( strFirstName ),
    m_strLastName( strLastName ),
    m_strAddress( strAddress )
{
}

// Book package
void Client::BookPackage( const Package& cPackage )
{
    // TODO
}
//function to show the available packages in the db.
void Client::ViewPackage(){
    
    
    
    
}

void Client::ViewSubmission(){
    
}

}  // End of namespace STB