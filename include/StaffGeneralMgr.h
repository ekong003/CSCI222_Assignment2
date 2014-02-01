//===================================================================
/*
   CSCI 222 Assignment 2

   The roles of the general manager are:
   (1) Create/Edit/Delete packages;
   (2) Create/Edit/Delete staff account;
   (3) View Statistics
*/
//===================================================================

#ifndef STAFFGENERALMGR_H
#define	STAFFGENERALMGR_H

#include "Staff.h"


namespace STB
{

//=============================
//    Class StaffGeneralMgr
//=============================
class StaffGeneralMgr : public Staff
{
public:
    
    // Constructor
    // <param nStaffID>     The unique identifier for the GM. </param>
    // <param strStaffName> Name of GM.                       </param>
    // <param strPassword>  Login password (non-encrypted).   </param>
    StaffGeneralMgr( int nStaffID, std::string strStaffName, std::string strPassword );
    
    // Destructor
    virtual ~StaffGeneralMgr();
    
    
    // TODO: Bind to the staff and form database
    //void Init( ?? );
    
    
    
    //=======================
    //    Holiday Packages
    //=======================
    // TODO: Create/Edit/Delete Package
    
    
    //===================== 
    //    Staff Account
    //===================== 
    
    // Add new staff into the staff database
    // <param nStaffID>     The unique identifier for the staff.      </param>
    // <param strStaffName> Name of staff.                            </param>
    // <param strPassword>  Login password (non-encrypted).           </param>
    // <param eStaffRole>   Defined the access rights to the system.  </param>
    // <return>             False if there is an existing staff id. 
    //                      Staff details will not be amended.        </return>
    bool AddNewStaff( int nStaffID, std::string strStaffName, std::string strPassword, Staff::eRole eStaffRole );
    
    // Edit staff name into the staff database
    // <param nStaffID>     The unique identifier for the staff. </param>
    // <param strStaffName> New name of staff.                   </param>
    // <return>             False if staff id cannot be found.   </return>
    bool EditStaffName( int nStaffID, std::string strNewName );

    // Edit staff role into the staff database
    // <param nStaffID>   The unique identifier for the staff.     </param>
    // <param eStaffRole> Defined the access rights to the system. </param>
    // <return>           False if staff id cannot be found.       </return>
    bool EditStaffRole( int nStaffID, Staff::eRole eStaffRole );
            
    // Edit staff name into the staff database
    // <param nStaffID> The unique identifier for the staff. </param>
    // <return>         False if staff id cannot be found.   </return>
    bool DeleteStaffRole( int nStaffID );
      
    
    //====================
    //    Statistics
    //====================
    
    void ViewStatsByPackageID  ( int nPackageID   );
    void ViewStatsByPackageType( int nPackageType );
    
    
    // Display menu options for this particular role
    virtual void DisplayMenu() const;
    
protected:
    
    
    
};
    
}  // End of namespace STB

#endif

