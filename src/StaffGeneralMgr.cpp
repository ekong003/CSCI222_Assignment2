//===================================================================
/*
   CSCI 222 Assignment 2

   Implements StaffGeneralMgr.h
*/
//===================================================================

#include "StaffGeneralMgr.h"


namespace STB
{

//=============================
//    Class StaffGeneralMgr    
//=============================

// Constructor
StaffGeneralMgr::StaffGeneralMgr( int nStaffID, std::string strStaffName, std::string strPassword ) :
    Staff( nStaffID, strStaffName, strPassword, Staff::GENERAL_MANAGER )
{
}

// Destructor
StaffGeneralMgr::~StaffGeneralMgr()
{
}

// Add/Edit/Delete staff account
bool StaffGeneralMgr::AddNewStaff( int nStaffID, std::string strStaffName, std::string strPassword, Staff::eRole eStaffRole )
{
    // TODO
}
    
bool StaffGeneralMgr::EditStaffName( int nStaffID, std::string strNewName )
{
    // TODO
}

bool StaffGeneralMgr::EditStaffRole( int nStaffID, Staff::eRole eStaffRole )
{
    // TODO
}
    
bool StaffGeneralMgr::DeleteStaffRole( int nStaffID )
{
    // TODO
}

// Display menu
void StaffGeneralMgr::DisplayMenu() const
{
    // TODO
}

}

