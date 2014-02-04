//===================================================================
/*
   CSCI222 Assignment 2

   Utility class to extract input from the user.
*/
//===================================================================

#ifndef INPUT_H
#define INPUT_H

#include <map>
#include <string>


namespace STB
{

//=======================================
//    Console interface 
//=======================================
class InputManager
{
public:
    
    // Get user input
    static int          GetInt( std::string strPrompt );
    static int          GetIntMinMax( std::string strPrompt, int nMin, int nMax );		
    static unsigned     GetUnsignedInt( std::string strPrompt );
    static float        GetFloat( std::string strPrompt );
    static std::string	GetString( std::string strPrompt );
    static bool         GetYesOrNo( std::string strPrompt );    
};

}  // End of namespace STB

#endif