//===================================================================
/*
   CSCI222 Assignment 2

   This is the client interface that invokes that various sub-components.
   
   When the user first runs the application, the system will prompt
   the user for his login id and password.
 
   If the login is valid, the system will then display a text menu
   displaying the various options available to the user, based on his
   role.  For example, onlly the General Manager can create a holiday
   package. 
*/
//===================================================================

#ifndef BOOKING_SYSTEM_MANAGER_H
#define	BOOKING_SYSTEM_MANAGER_H

#include "DisplayManager.h"
#include "InputManager.h"
#include "LoginManager.h"
#include "Staff.h"


namespace STB
{

//==================================
//    Class BookingSystemManager    
//==================================
class BookingSystemManager
{
public:

     // Constructor/destructor
    BookingSystemManager();
    ~BookingSystemManager();
    
    // Runs the program
    void Run();
    
    // Process user login
    // <return> True if login is successful </return>
    bool Login();
    
private: 
    
    class Test : public IMenuEventHandler
    {
        virtual void OnMenuSelect() { std::cout << "\nBOOYA" << std::endl; }
    };
    
    
    //=================
    //   Data fields
    //=================
    LoginManager        m_cLoginMgr;    // Handles the login process
    InputManager        m_cInputMgr;    // Handles user input
    DisplayManager      m_cDisplayMgr;  // Handles the menu display
    
    Staff::eRole        m_eUserRole;    // Is the user the GM, HM or BS?
    bool                m_bQuit;        // If set to true, we terminate the program  
};
    
}  // End of namespace STB

#endif

