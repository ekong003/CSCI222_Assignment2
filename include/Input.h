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

//========================================================
//	  Interface to gather input from the user
//========================================================
class BaseInput
{
public:

    // Constructor/Destructor
    BaseInput();
    virtual ~BaseInput();

    virtual int         GetInt() = 0;
    virtual int         GetIntMinMax( int nMin, int nMax ) = 0;		// Get an integer from a given range, inclusive
    virtual unsigned	GetUnsignedInt() = 0;
    virtual float       GetFloat() = 0;
    virtual std::string GetString() = 0;
    virtual bool        GetYesOrNo() = 0;                           // Y = true, N = false
};



//======================================
//   Gathers text input from console 
//======================================
class ConsoleTextInput : public BaseInput
{
public:

    virtual int         GetInt();
    virtual int         GetIntMinMax( int nMin, int nMax );		
    virtual unsigned	GetUnsignedInt();
    virtual float       GetFloat();
    virtual std::string	GetString();
    virtual bool        GetYesOrNo();
};

}  // End of namespace STB

#endif