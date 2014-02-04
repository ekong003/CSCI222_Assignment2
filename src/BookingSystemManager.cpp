//===================================================================
/*
   CSCI222 Assignment 2

   Implements BookingSystemManager.h
 */
//===================================================================

#include "BookingSystemManager.h"
#include "DisplayManager.h"


namespace STB 
{

//==================================
//    Class BookingSystemManager
//==================================

const int nLOGIN_CIPHER_KEY = 16;

// Constructor
BookingSystemManager::BookingSystemManager() :
    m_cLoginMgr( new CaesarCipherAlgo( nLOGIN_CIPHER_KEY ) ),
    m_bQuit( false )
{
}

// Destructor
BookingSystemManager::~BookingSystemManager() {}

// Execute the program
void BookingSystemManager::Run()
{
    int i1 = m_cDisplayMgr.AddMenuEntry( Staff::GENERAL_MANAGER, "Create Package" );
    int i2 = m_cDisplayMgr.AddMenuEntry( Staff::GENERAL_MANAGER, "Edit Package" );
    int i3 = m_cDisplayMgr.AddMenuEntry( Staff::GENERAL_MANAGER, "Delete Package" );
    
    m_cDisplayMgr.AddMenuSuscriber( Staff::GENERAL_MANAGER, i1, new BookingSystemManager::Test() );
    
    m_cDisplayMgr.DisplayMenu( Staff::GENERAL_MANAGER );
    m_cDisplayMgr.PromptMenuSelect( Staff::GENERAL_MANAGER );
    
    // Start the login process
    //if( Login() )
    {   
        // The main loop
        //while( !m_bQuit )
        {
           
        }
    }    
}

// Login process
bool BookingSystemManager::Login()
{   
    // Initialize the user database
    if( !m_cLoginMgr.LoadStaffDatabase() )
        return false;
    
    // Display logo
    DisplayManager::DisplayLogo();  
    
    // Login process
    int nNumTries = 0, nUserID;
    std::string strPassword;
    
    while( nNumTries < 3 )
    {
        nNumTries++;
        nUserID     = m_cInputMgr.GetInt( "User id" );
        strPassword = m_cInputMgr.GetString( "Password" );
        
        // If login is successful, break out of this while loop
        if( m_cLoginMgr.VerifyLogin( nUserID, strPassword ) )
        {
            //TODO
            //m_cUser = m_cLoginMgr.GetUserData( strUserID );
            return true;
        }
        
        // Display unsuccessful login outcome
		DisplayManager::Print( "You have entered an incorrect user id/password.", RED );
    }
        
    // If the user has 3 unsuccessful attempt quit the program
    DisplayManager::DisplayExit();
    return false;
}

}  // End of namespace STB