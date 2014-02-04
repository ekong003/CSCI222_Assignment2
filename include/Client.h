//===================================================================
/*
   CSCI 222 Assignment 2

   Personal details of customers who book for tour packages with Smart
   Travel Holidays.
*/
//===================================================================

#ifndef CLIENT_H
#define	CLIENT_H

#include "Package.h"

#include <string>


namespace STB
{
    
//=====================================
//    Personal details of customer
//=====================================
class Client
{
public:
    
    // Constructor
    // <param nClientID>    The unique identifier for the customer.  </param>
    // <param strFirstName> Customer first name.                     </param>
    // <param strLastName>  Customer last name.                      </param>
    // <param strAddress>   Billing address of customer.             </param>
    Client( int nClientID );
    Client( int nClientID, std::string strFirstName, std::string strLastName, std::string strAddress = "" );
    
    // Booking
    // <param cPackage> Package details. </param>
    void BookPackage( const Package& cPackage );
    
    //View Package
    void ViewPackage();
   
    //View Submissions
    void ViewSubmission();
    
        
    // Mutators
    void EditFirstName( std::string strNewName );
    void EditLastName ( std::string strNewName );
    void EditAddress  ( std::string strNewAddress );
    
    // Accessors
    int         GetID()        const;
    std::string GetFirstName() const;
    std::string GetLastName()  const;
    std::string GetAddress()   const;  
    
private:
    
    //===================
    //    Data Fields
    //===================
    int          m_nID;
    std::string  m_strFirstName;
    std::string  m_strLastName;
    std::string  m_strAddress;
    //database connector object
};



//===================================
//    Inline function definitions
//===================================
inline void Client::EditFirstName( std::string strNewName )         { m_strFirstName = strNewName; }
inline void Client::EditLastName ( std::string strNewName )         { m_strLastName = strNewName; }
inline void Client::EditAddress  ( std::string strNewAddress )      { m_strAddress = strNewAddress; }

inline int          Client::GetID()        const    { return m_nID; }
inline std::string  Client::GetFirstName() const    { return m_strFirstName; }
inline std::string  Client::GetLastName()  const    { return m_strLastName; }
inline std::string  Client::GetAddress()   const    { return m_strAddress; }
    
}  // End of namespace STB

#endif

