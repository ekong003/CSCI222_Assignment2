//===================================================================
/*
   CSCI222 Assignment 2

   Implements LoginManager.h
 */
//===================================================================

#include "LoginManager.h"
#include "DisplayManager.h"
#include <algorithm>
#include <ctype.h>


namespace STB 
{

//============================
//   Class CaesarCipherAlgo
//============================

const int nCAESAR_CIPHER_CARDINAL = 127;

// Constructor
CaesarCipherAlgo::CaesarCipherAlgo( int nShift ) 
{
    // Ensure that nShift is between 1 to 126, else clamp the value
    m_nShift = ( nShift <= 1 ) ? 1 : ( ( nShift >= 126 ) ? 126 : nShift );
}

// Implementations of virtual functions
std::string CaesarCipherAlgo::Encrypt( std::string strPassword ) const 
{
    std::string strEncryptedPW(strPassword);
    for( unsigned int i = 0; i < strEncryptedPW.length(); ++i )
        strEncryptedPW[i] = (strEncryptedPW[i] + m_nShift) % nCAESAR_CIPHER_CARDINAL;
    return strEncryptedPW;
}

std::string CaesarCipherAlgo::Decrypt( std::string strPassword ) const 
{
    std::string strOriginalPW(strPassword);
    for( unsigned int i = 0; i < strOriginalPW.length(); ++i )
        strOriginalPW[i] = (strOriginalPW[i] + nCAESAR_CIPHER_CARDINAL - m_nShift) % nCAESAR_CIPHER_CARDINAL;
       
    return strOriginalPW;
}



//=========================
//   Class LoginManager
//=========================

// Constructor
LoginManager::LoginManager( const char* pFile, BaseEncryptionAlgo* pEncryptionAlgo ) :
    m_pEncryptionFunc(pEncryptionAlgo) 
{
}

// Destructor
LoginManager::~LoginManager() 
{
    if( m_pEncryptionFunc ) 
    {
        delete m_pEncryptionFunc;
        m_pEncryptionFunc = NULL;
    }
}

// Load file
bool LoginManager::LoadStaffDatabase() 
{
    bool bSuccess = true;
    
    // TODO: CINO HOW DO I INCORPORATE MYSQL?
    
    return bSuccess;
}

// Re-encrypt the existing password based on the new algorithm
void LoginManager::ChangeEncryptionAlgo( BaseEncryptionAlgo* pEncryptionAlgo) 
{
    if( m_pEncryptionFunc ) 
    {
        //TODO
        /*
        // Decrypt the existing passwords
        LoginIter iter = m_mapLogin.begin();
        for( ; iter != m_mapLogin.end(); ++iter )
        {
            std::string strOriginalPW = m_pEncryptionFunc->Decrypt( iter->second.EncryptedPassword );
            iter->second.EncryptedPassword = pEncryptionAlgo->Encrypt( strOriginalPW );
        }
        */
    }

    delete m_pEncryptionFunc;
    m_pEncryptionFunc = pEncryptionAlgo;
    
    //_UpdateLoginDataToFile();
}

bool LoginManager::VerifyLogin( int nStaffID, std::string strPassword )
{
    if( !_IsStaffValid( nStaffID ) )
        return false;
    
    // Return true is password is correct
    return _GetEncryptedPassword( nStaffID ) == _EncryptPassword( strPassword );
}

bool LoginManager::ChangePassword( int nStaffID, std::string strNewPassword )
{   
    // Return false if there is no such user id
    if( !_IsStaffValid( nStaffID ) )
    {
        DisplayManager::Print( "[Error] No record of StaffID in database.", RED );
        return false;
    }
        
    // Check that the password is valid
    if( IsPasswordValid( strNewPassword ) )
    {
        std::string strNewEncryptedPW = _EncryptPassword( strNewPassword );
        
        // TODO: Update password to database
        
        DisplayManager::Print( "[Success] Password changed.", RED );
		return true;
    }
    else
    {
        DisplayManager::Print( "[Error] Password needs to be alpha numeric and have at least 8 chars", RED );
        return false;
    }
}

// Password is valid if it has at least 8 chars and contains both letters and digits
bool LoginManager::IsPasswordValid( std::string strPassword ) 
{
    int nLen = strPassword.length();

    // Check the length of the password
    if( nLen < 8 )
    {
        DisplayManager::Print( "[Error] Password needs to be alpha numeric and have at least 8 chars", RED );
        return false;
    }

    // Check that the password contains both letters and digits
    const char* pPassword = strPassword.c_str();
    bool bHasLetters = false, bHasNumbers = false;

    for( int i = 0; i < nLen; ++i )
    {
        (isdigit(pPassword[i]) ? bHasNumbers : bHasLetters) = true;

        if( bHasLetters && bHasNumbers )
            return true;
    }

    // If we reach here, it means the password has either no digits or no letters
    DisplayManager::Print( "[Error] Password needs to have both digits and numbers", RED );
    return false;
}

// Default password
std::string LoginManager::DefaultPassword()
{ 
    return "123password"; 
}

// Encryts the password
std::string LoginManager::_EncryptPassword( std::string strPassword ) 
{
    return m_pEncryptionFunc->Encrypt( strPassword );
}

bool LoginManager::_IsStaffValid( int nStaffID )
{
    // <Cino - execute your query here>
    // <Function needs to return false if nStafffID cannot be found in the database>
    
    return true;
}

std::string LoginManager::_GetEncryptedPassword( int nStaffID )
{
    // <Cino - execute your query here>
    // <Function needs to return "" if nStafffID cannot be found in the database>
    
    return "";
}

} // End of namespace STB