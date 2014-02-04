//===================================================================
/*
   CSCI 222 Assignment 2

   Implements DisplayManager.h
*/
//===================================================================

#include "DisplayManager.h"
#include "InputManager.h"
#include <iomanip>
#include <iostream>
#include <sstream>
#include <c++/4.6/bits/stl_vector.h>


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

// Constructor
DisplayManager::DisplayManager() {}

// Destructor
DisplayManager::~DisplayManager()
{
    std::map<Staff::eRole, std::vector<MenuComponent> >::iterator iter = m_mapMenuData.begin();
    for( ; iter != m_mapMenuData.end(); ++iter )
    {
        std::vector<MenuComponent>& aMenuComponents = iter->second;
        for( unsigned int i = 0; i < aMenuComponents.size(); ++i )
        {
            std::vector<IMenuEventHandler*>& aMenuHandlers = aMenuComponents[i].aSuscribers;
            for( unsigned int j = 0; j < aMenuHandlers.size(); ++j )
            {
                if( aMenuHandlers[j] )
                    delete aMenuHandlers[j];
            }
        }
        aMenuComponents.clear();
    }
}

int DisplayManager::AddMenuEntry( Staff::eRole eStaffRole, std::string strMenuLabel )
{
    MenuComponent cMenuComponent;
    cMenuComponent.strLabel = strMenuLabel;
    
    m_mapMenuData[eStaffRole].push_back( cMenuComponent );
    return m_mapMenuData[eStaffRole].size();
}

void DisplayManager::AddMenuSuscriber( Staff::eRole eStaffRole, int nMenuID, IMenuEventHandler* pHandler )
{
    int nSize = m_mapMenuData[eStaffRole].size();
    
    // Check if nMenuID is valid
    if( nMenuID >= 1 && nMenuID <= nSize )
        m_mapMenuData[eStaffRole][nMenuID - 1].aSuscribers.push_back( pHandler ); 
}

void DisplayManager::PromptMenuSelect( Staff::eRole eStaffRole )
{
    int nSize = m_mapMenuData[eStaffRole].size();
    
    std::stringstream ss;
    ss << "Select a menu option [" << 1 << "-" << nSize << "]";
    int nMenuID = InputManager::GetIntMinMax( ss.str(), 1, nSize );
    
    DisplayLogo();
    Begin( BLUE, BOLD );
    std::cout << "\n\nYou have selected "; 
    Begin( RED, BOLD, YELLOW );        
    std::cout << m_mapMenuData[eStaffRole][nMenuID - 1].strLabel << "\n\n";
        
    std::vector<IMenuEventHandler*>& aHandlers = m_mapMenuData[eStaffRole][nMenuID - 1].aSuscribers;
    for( unsigned int i = 0; i < aHandlers.size(); ++i )
        aHandlers[i]->OnMenuSelect();
}

// Display menu
void DisplayManager::DisplayMenu( Staff::eRole eStaffRole )
{
    DisplayLogo();
    
    std::vector<MenuComponent>& vMenuList = m_mapMenuData[eStaffRole];    
    Begin( GREEN, BOLD );
    for( unsigned int i = 0; i < vMenuList.size(); ++i )
        std::cout << "(" << i + 1 << ")\t" << vMenuList[i].strLabel << std::endl; 
    End();
}

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
	std::cout << std::setfill( ' ' ) << std::setw( nBUFFER_SIZE + 1 ) << "\n";
    
	// Align the header to the centre
	if( strHeader.length() > nBUFFER_SIZE )
		std::cout << std::setfill( ' ' ) << strHeader;
	else
    {
        int nPos = ( nBUFFER_SIZE + strHeader.length() ) / 2;
        std::cout << std::setfill( ' ' ) << std::setw( nPos ) << strHeader;
        std::cout << std::setfill( ' ' ) << std::setw( nBUFFER_SIZE - nPos ) << "";
    }	
    
    std::cout << "\n" << std::setfill( ' ' ) << std::setw( nBUFFER_SIZE ) << "";
	std::cout << "\n================================================================================\n\n\E[0m";
}

// Display the logo
void DisplayManager::DisplayLogo()
{
    DisplayHeader( "SmartTravel Holidays Booking Management System" );
}

// Display text prompt msg
void DisplayManager::DisplayPrompt( std::string strMsg, ePixelColor eTextColor )
{
    Begin( eTextColor, BOLD );
    std::cout << "\n" << strMsg << ": ";
    Begin( GREEN );
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