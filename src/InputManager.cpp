//===================================================================
/*
   Name      : Ong Eng Kiat, Dennis
   Student ID: 4593686

   Implements ConsoleTextInput.h
*/
//===================================================================

#include "InputManager.h"
#include "DisplayManager.h"
#include <algorithm>
#include <iostream>
#include <limits>
#include <sstream>


namespace STB
{

//==========================
//    Class InputManager 
//==========================

// Get user input
int InputManager::GetInt( std::string strPrompt )
{
    DisplayManager::DisplayPrompt( strPrompt );
    
    int i = 0;
	while( !( std::cin >> i ) ) 
	{    
		std::cin.clear();
		std::cin.ignore( std::numeric_limits<std::streamsize>::max(), '\n' );
        DisplayManager::DisplayPrompt( "You have entered an invalid integer, please try again", RED );
	}

    DisplayManager::End();
	std::cin.clear();
	std::cin.ignore( 256, '\n' );
	return i;
}

int InputManager::GetIntMinMax( std::string strPrompt, int nMin, int nMax )
{
    DisplayManager::DisplayPrompt( strPrompt );
    
    int i = 0;
	while( !( std::cin >> i ) || i < nMin || i > nMax ) 
	{   
		std::cin.clear();
		std::cin.ignore( std::numeric_limits<std::streamsize>::max(), '\n' );
        DisplayManager::Begin( RED );
		std::cout << "\nYou need to key in an integer in the range [" << nMin << "-" << nMax << "], please try again: ";
        DisplayManager::Begin( GREEN );
	}

    DisplayManager::End();
	std::cin.clear();
	std::cin.ignore( 256, '\n' );
	return i;
}
    
unsigned InputManager::GetUnsignedInt( std::string strPrompt )
{
    DisplayManager::DisplayPrompt( strPrompt );
    
    unsigned int i = 0;
	while( !( std::cin >> i ) ) 
	{    
		std::cin.clear();
		std::cin.ignore( std::numeric_limits<std::streamsize>::max(), '\n' );
        DisplayManager::DisplayPrompt( "You need to enter a positive integer, please try again", RED );
	}

    DisplayManager::End();
	std::cin.clear();
	std::cin.ignore( 256, '\n' );
	return i;
}

float InputManager::GetFloat( std::string strPrompt )
{
    DisplayManager::DisplayPrompt( strPrompt );
    
    float i = 0;
	while( !( std::cin >> i ) ) 
	{    
		std::cin.clear();
		std::cin.ignore( std::numeric_limits<std::streamsize>::max(), '\n' );
		DisplayManager::DisplayPrompt( "You need to a float", RED );
	}

    DisplayManager::End();
	std::cin.clear();
	std::cin.ignore( 256, '\n' );
	return i;
}
    
std::string	InputManager::GetString( std::string strPrompt )
{
    DisplayManager::DisplayPrompt( strPrompt );
    std::string s;
	std::getline( std::cin, s );
	
	std::cin.clear();
	//std::cin.ignore( 256, '\n' );
	return s;
}
    
bool InputManager::GetYesOrNo( std::string strPrompt )
{
    DisplayManager::DisplayPrompt( strPrompt );
    
    bool bOutput = true;
    while( true )
    {
        std::string s;
        std::getline( std::cin, s );	
        std::cin.clear();

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
            DisplayManager::DisplayPrompt( "Invalid input, you need to key in either 'Y' or 'No'", RED );
    }
    
    DisplayManager::End();
    return bOutput;
}

}  // End of namespace STB