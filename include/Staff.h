//===================================================================
/*
   CSCI 222 Assignment 2

   This is the base class for backend users of the Booking Management
   System. It contains basic employee details.
*/
//===================================================================

#ifndef STAFF_H
#define	STAFF_H

#include <string>

namespace STB
{
    
//======================================================
//    Base class for SmartTravel Holidays employees
//======================================================
class Staff
{
public:
    
    // Enumerator for the staff roles
    enum eRole  { GENERAL_MANAGER, HOLIDAY_MANAGER, BOOKING_STAFF };
       
    // Constructor
    // <param nStaffID>     The unique identifier for the staff.     </param>
    // <param strStaffName> Name of staff.                           </param>
    // <param strPassword>  Login password (non-encrypted).          </param>
    // <param eStaffRole>   Defined the access rights to the system. </param>
    explicit Staff( int nStaffID, std::string strStaffName, std::string strPassword, eRole eStaffRole );
    
    // Destructor
    virtual ~Staff();
    
    // Checks if the password entered is valid
    bool ValidatePassword( std::string strPassword );
    
    // Mutators
    void EditName    ( std::string strNewName );
    void EditPassword( std::string strNewPassword );
    void EditRole    ( eRole eNewRole );
    
    // Accessors
    int         GetID()   const;
    std::string GetName() const;
    eRole       GetRole() const;
    
    // Display menu options for this particular role
    virtual void DisplayMenu() const = 0;
    
protected:
    
    //=========================
    //    Utility Functions
    //=========================
    
    // Constructor
    // <param strPassword>  User password. </param>
    // <return> The encrypted password.    </return>
    virtual std::string _EncryptPassword( std::string strPassword );
    
    
    //===================
    //    Data Fields
    //===================
    int             m_nStaffID;       // Staff identifier
    std::string     m_strName;        // Staff name
    std::string     m_strPassword;    // Stores the encrypted password
    eRole           m_eRole;    
};



//===================================
//    Inline function definitions
//===================================

inline void Staff::EditName    ( std::string strNewName )      { m_strName = strNewName; }
inline void Staff::EditPassword( std::string strNewPassword )  { m_strPassword = strNewPassword; }
inline void Staff::EditRole    ( eRole eNewRole )              { m_eRole = eNewRole; }

inline int          Staff::GetID() const                 { return m_nStaffID; }
inline std::string  Staff::GetName() const               { return m_strName; }
inline Staff::eRole Staff::GetRole() const               { return m_eRole; }

}  // End of namespace STB

#endif

