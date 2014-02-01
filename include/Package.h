//===================================================================
/*
   CSCI 222 Assignment 2

   Data type for the holiday package, contains:
   (1) PackageID  : Each holiday tour has a unique package ID.
   (2) PackageName: E.g "The small adventure".
   (3) PackageType: Enumerator for the package name.
   (4) Description: Short description of the package including
                    details such as destination
   (5) Price      : Cost of package per person      
*/
//===================================================================

#ifndef PACKAGE_H
#define	PACKAGE_H

#include <string>


namespace STB
{
    
struct Package
{
    int             ID;             // Unique id
    std::string     Name;           // Package name
    int             Type;           // Package type
    std::string     Description;
    float           Price;          // Cost per pax
};
    
}  // End of namespace STB

#endif

