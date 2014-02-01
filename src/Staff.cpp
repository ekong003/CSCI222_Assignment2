//===================================================================
/*
   CSCI 222 Assignment 2

   Implements Staff.h
*/
//===================================================================

#include "Staff.h"


namespace STB
{

//===================
//    Class Staff    
//===================

// Constructor
Staff::Staff( int nStaffID, std::string strStaffName, std::string strPassword, eRole eStaffRole ) :
    m_nStaffID( nStaffID ),
    m_strName( strStaffName ),
    m_eRole( eStaffRole )
{
    m_strPassword = _EncryptPassword( strPassword );
}

// Destructor
Staff::~Staff()
{
}

// Check if the input password is valid
bool Staff::ValidatePassword( std::string strPassword )
{
    return _EncryptPassword( strPassword ) == m_strPassword;
}

// Utility method
std::string Staff::_EncryptPassword( std::string strPassword )
{
    // TODO
    return std::string( "" );
}

}
