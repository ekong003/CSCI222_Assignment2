//===================================================================
/*
   CSCI 222 Assignment 2

   Implements DisplayManager.h
*/
//===================================================================

#include "DisplayManager.h"
#include <iomanip>
#include <iostream>


namespace STB
{

//====================================
//    Static member initialization
//====================================
    
// We first need to templatize the map factory
template<typename TKey, typename TValue>
class StaticMapFactory
{
public:

    // Constructor
    StaticMapFactory( const TKey& tKey, const TValue& tVal )
    {
        m_map[tKey] = tVal;
    }

    // Functor
    StaticMapFactory<TKey, TValue>& operator() ( const TKey& tKey, const TValue& tVal )
    {
        m_map[tKey] = tVal;
        return *this;
    }

    operator std::map<TKey, TValue>()
    {
        return m_map;
    }
    
private:

    std::map<TKey, TValue> m_map;
};

std::map<ePixelColor, std::string> DisplayManager::m_mapTextColor
= StaticMapFactory<ePixelColor, std::string> (BLACK,"30")(RED,"31")(GREEN,"32")(YELLOW,"33")(BLUE,"34")(MAGENTA,"35")(CYAN,"36")(WHITE,"37");

std::map<ePixelColor, std::string> DisplayManager::m_mapBackgroundColor
= StaticMapFactory<ePixelColor, std::string> (BLACK,"40")(RED,"41")(GREEN,"42")(YELLOW,"43")(BLUE,"44")(MAGENTA,"45")(CYAN,"46")(WHITE,"47");
    
std::map<eTextStyle, std::string> DisplayManager::m_mapTextStyle
= StaticMapFactory<eTextStyle, std::string> (NONE,"0;")(BOLD,"1;")(UNDERSCORE,"4;")(BLINK,"5;")(REVERSE,"7;")(CONCEALED,"8;");
    


//=============================
//    Class DisplayManager    
//=============================

// Display text to console
void DisplayManager::Print( std::string strMsg )
{
    std::cout << strMsg;
}

void DisplayManager::Print( std::string strMsg, ePixelColor eTextColor )
{
    Begin( eTextColor );
    std::cout << strMsg;
    End();
}

void DisplayManager::Print( std::string strMsg, ePixelColor eTextColor, unsigned int nStyle )
{
    Begin( eTextColor, nStyle );
    std::cout << strMsg;
    End();
}

void DisplayManager::Print( std::string strMsg, ePixelColor eTextColor, unsigned int nStyle, ePixelColor eBackgroundColor )
{
    Begin( eTextColor, nStyle, eBackgroundColor );
    std::cout << strMsg;
    End();
}

// Set the text color, text style and background color
void DisplayManager::Begin( ePixelColor eTextColor )
{
    std::cout << "\E[0;" << m_mapTextColor[eTextColor] << "m";
}

void DisplayManager::Begin( ePixelColor eTextColor, unsigned int nStyle )
{
    std::cout << "\E[" << _GetTextStyle( nStyle ) << m_mapTextColor[eTextColor] << "m";
}

void DisplayManager::Begin( ePixelColor eTextColor, unsigned int nStyle, ePixelColor eBackgroundColor )
{
    std::cout << "\E[" << _GetTextStyle( nStyle );
    std::cout << m_mapTextColor[eTextColor] << ";";
    std::cout << m_mapBackgroundColor[eBackgroundColor] << "m";
}

void DisplayManager::End()
{
    std::cout << "\n\E[0m";
}

// Display header
void DisplayManager::DisplayHeader( std::string strHeader, ePixelColor eTextColor, ePixelColor eBackgroundColor )
{
    ClearScreen();
    
    const int nBUFFER_SIZE = 80;
    
    std::cout << std::setiosflags( std::ios::right );
	std::cout << "\E[1;" << m_mapTextColor[eTextColor] << ";" << m_mapBackgroundColor[eBackgroundColor] << "m";
    std::cout << "\n================================================================================\n";
	
	// Align the header to the centre
	if( strHeader.length() > nBUFFER_SIZE )
		std::cout << std::setfill( ' ' ) << strHeader;
	else
    {
        int nPos = ( nBUFFER_SIZE - strHeader.length() ) / 2;
        std::cout << std::setfill( ' ' ) << std::setw( strHeader.length() + nPos ) << strHeader;
        std::cout << std::setfill( ' ' ) << std::setw( nPos ) << "";
    }	
    
	std::cout << "\n================================================================================\n\n\E[0m";
}

// Display exit message
void DisplayManager::DisplayExit()
{
    Print( "\n\nExiting SmartTravel Holidays Booking Management System", GREEN, BOLD, BLUE );
}

// Clear the screen
void DisplayManager::ClearScreen()
{
    std::cout << std::string( 100, '\n' );
}

// Utility functions
std::string DisplayManager::_GetTextStyle( unsigned int nStyle )
{
    std::string strOutput( "" );
    std::map<eTextStyle, std::string>::iterator iter = m_mapTextStyle.begin();
    for( iter; iter != m_mapTextStyle.end(); ++iter )
    {
        if( nStyle & iter->first )
            strOutput += iter->second;
    }    
    return strOutput;
}
    
}  // End of namespace STB