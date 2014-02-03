//===================================================================
/*
   Name      : Ong Eng Kiat, Dennis
   Student ID: 4593686

   Implements ConsoleTextInput.h
*/
//===================================================================

#include "Input.h"
#include "DisplayManager.h"
#include <algorithm>
#include <iostream>
#include <limits>
#include <sstream>


namespace STB
{

//==============================
//    Class ConsoleTextInput
//==============================
BaseInput::BaseInput()	{}
BaseInput::~BaseInput() {}



//==============================
//    Class ConsoleTextInput
//==============================
int ConsoleTextInput::GetInt()
{
	int i = 0;
	while( !( std::cin >> i ) ) 
	{    
		std::cin.clear();
		std::cin.ignore( std::numeric_limits<std::streamsize>::max(), '\n' );
        DisplayManager::Print( "\nYou have entered an invalid integer, please try again: ", RED );
	}

	std::cin.clear();
	std::cin.ignore( 256, '\n' );
	return i;
}

int ConsoleTextInput::GetIntMinMax( int nMin, int nMax )
{
	int i = 0;
	while( !( std::cin >> i ) || i < nMin || i > nMax ) 
	{   
		std::cin.clear();
		std::cin.ignore( std::numeric_limits<std::streamsize>::max(), '\n' );
        DisplayManager::Begin( RED );
		std::cout << "\nYou need to key in an integer in the range [" << nMin << "-" << nMax << "], please try again: ";
        DisplayManager::End();
	}

	std::cin.clear();
	std::cin.ignore( 256, '\n' );
	return i;
}

unsigned int ConsoleTextInput::GetUnsignedInt()
{
	unsigned int i = 0;
	while( !( std::cin >> i ) ) 
	{    
		std::cin.clear();
		std::cin.ignore( std::numeric_limits<std::streamsize>::max(), '\n' );
		DisplayManager::Print( "\nYou need to enter a positive integer, please try again: ", RED );
	}

	std::cin.clear();
	std::cin.ignore( 256, '\n' );
	return i;
}

float ConsoleTextInput::GetFloat()
{
	float i = 0;
	while( !( std::cin >> i ) ) 
	{    
		std::cin.clear();
		std::cin.ignore( std::numeric_limits<std::streamsize>::max(), '\n' );
		DisplayManager::Print( "\nYou need to a float: ", RED );
	}

	std::cin.clear();
	std::cin.ignore( 256, '\n' );
	return i;
}

std::string ConsoleTextInput::GetString()
{
	std::string s;
	std::getline( std::cin, s );
	
	std::cin.clear();
	//std::cin.ignore( 256, '\n' );
	return s;
}

bool ConsoleTextInput::GetYesOrNo()
{
    bool bOutput = true;

    while( true )
    {
        std::string s = GetString();

        // Convert string to lower case
        std::transform( s.begin(), s.end(), s.begin(), ::tolower );
        if( s == "y" )
            break;
        else if( s == "n" )
        {
            bOutput = false;
            break;
        }
        else
            DisplayManager::Print( "\nInvalid input, you need to key in either 'Y' or 'No': ", RED );
    }
    return bOutput;
}

}  // End of namespace STB