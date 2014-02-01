//===================================================================
/*
   CSCI 222 Assignment 2

   Implements Client.h
*/
//===================================================================

#include "Client.h"


namespace STB
{

//====================
//    Class Client 
//====================
    
// Constructor
Client::Client( int nClientID ) : m_nID( nClientID ) {}

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

}  // End of namespace STB