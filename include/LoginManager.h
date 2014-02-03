//===================================================================
/*
   CSCI222 Assignment 2

   The LoginManager class handles the login logic of the Smart Travel
   Booking system.
*/
//===================================================================

#ifndef LOGIN_MANAGER_H
#define LOGIN_MANAGER_H

#include "Staff.h"
#include <map>
#include <string>


namespace STB
{

// Abstract encryption class
class BaseEncryptionAlgo
{
public:

    // Virtual destructor
    virtual ~BaseEncryptionAlgo()	{};

    // Abstract encryption/decryption, all derived classes must implement this
    virtual std::string Encrypt ( std::string strPassword ) const = 0;
    virtual std::string Decrypt ( std::string strPassword ) const = 0;
};



// Encryption functors
//==========================================================================
//	The Caesar cipher basically shifts an ordered set of lexicons.
//  Here we assume the lexicon is the set of 127 ASCII chars, we we do the 
//  shifting before applying modulo 127
//==========================================================================
class CaesarCipherAlgo : public BaseEncryptionAlgo
{
public:

    // Constructor
    // <param nShift> The amount to be shifted. </param>
    CaesarCipherAlgo( int nShift );

    // Encrypts the password by shifting the input password.
    // <param strPassword> The input password.     </param>
    // <return>            The encrypted password. </return>
    virtual std::string Encrypt ( std::string strPassword ) const;
	
    // Decrypts the password by shifting the encrypted password.
    // <param strPassword> The encrypted password. </param>
    // <return>            The original password.  </return>
    virtual std::string Decrypt ( std::string strPassword ) const;

private:
	
    int m_nShift;		// Amount to shift
};



//========================================================================
//   The LoginManager class handles the login process of the booking system.
//   Specifically, it has the following functionalities:	
//
//   (1) Loads the admin database which contains the userID and the 
//       respective encrypted passwords.
//   (2) Adds new users. 
//   (3) Removes a user from the database.
//   (4) Checks if a login is valid. The user password must be at least 8 chars and 
//       contain both numerals and letters.
//   (5) Changes a user password.
//   
//========================================================================
class LoginManager
{
public:
    
    // There are 2 kinds of users that access the POS system, the administrator
    // and the cashier
    struct LoginData
    {
        std::string Role;    // "admin" or "cashier"
        std::string EncryptedPassword;    
        
        // Constructor
        LoginData() {};
        LoginData( std::string strRole, std::string strPassword ) : Role( strRole ), EncryptedPassword( strPassword ) {}
    };
    
    // Constructor
    // <param pFile> Admin file that contains the userID and encrypted password. </param>
    LoginManager( const char* pFile, BaseEncryptionAlgo* pEncryptionAlgo );

    // Destructor
    ~LoginManager();

    // Loads the admin file.
    // <return> True if the database can be accessed. </return>
    bool LoadStaffDatabase();

    // Decrypts all the existing user password using the old encryption algo and then
    // Encrypts them with the new encryption algo.
    // <param pEncryptionAlgo> New encryption algorithm. </param>
    void ChangeEncryptionAlgo( BaseEncryptionAlgo* pEncryptionAlgo );
    
    // Checks if the login is valid.
    // <param nStaffID>    StaffID.            </param>
    // <param strPassword> The input password. </param>
    // <return>            True if the password is correct. </return>
    bool VerifyLogin( int nStaffID, std::string strPassword );
    
    // Changes the user's password. Note that the password will only change if it is valid.
    // Otherwise, this function will display a warning message.
    // <param nStaffID>       StaffID.          </param>
    // <param strNewPassword> The new password. </param>
    // <return>               False if there is no existing userID or the password is invalid. </return>
    bool ChangePassword( int nStaffID, std::string strNewPassword );

    // A password is valid if it has at least 8 chars and contains both numerals and letters.
    // <param strPassword> The input password.        </param>
    // <return>            True if password is valid. </return>
    bool IsPasswordValid( std::string strPassword );
        
    // Default password
    static std::string DefaultPassword();

private:

    //=======================
    //   Utility Functions
    //=======================	

    std::string _EncryptPassword( std::string strPassword );
    bool        _IsStaffValid( int nStaffID );
    std::string _GetEncryptedPassword( int nStaffID );
    
    //=================
    //   Data fields
    //=================
    BaseEncryptionAlgo*     m_pEncryptionFunc;   // Encryption algorithm
};

}  // End of namespace STB

#endif