//===================================================================
/*
   CSCI 222 Assignment 2

   This is a utility tool to display text messages to the console.  
*/
//===================================================================

#ifndef DISPLAYMANAGER_H
#define	DISPLAYMANAGER_H

#include "Staff.h"
#include <map>
#include <string>
#include <vector>


namespace STB
{

// Enumerator for the ANSI text color codes
enum ePixelColor  { BLACK, RED, GREEN, YELLOW, BLUE, MAGENTA, CYAN, WHITE };

// Enumerator for the text styles
enum eTextStyle  { NONE        = 1 << 0, 
                   BOLD        = 1 << 1,
                   UNDERSCORE  = 1 << 2, 
                   BLINK       = 1 << 3, 
                   REVERSE     = 1 << 4,        // Reverses the foreground and background colors
                   CONCEALED   = 1 << 5 }; 

                   

// Menu event handler interface
class IMenuEventHandler
{
public:
    
    // Constructor/destructor
    IMenuEventHandler() {}
    virtual ~IMenuEventHandler() {}
    
    virtual void OnMenuSelect() = 0;
};
                   

//============================
//    Class DisplayManager    
//============================
class DisplayManager
{
public:
    
    // Constructor/Destructor
    DisplayManager();
    ~DisplayManager();
    
    // Add a menu entry
    // <param eStaffMenu>   Different roles will have different menu options. </param>
    // <param strMenuLabel> The menu label.                                   </param>
    // <return>             Menu entry id.                                    </return>
    int  AddMenuEntry( Staff::eRole eStaffRole, std::string strMenuLabel );
    
    // Add a suscriber
    // <param eStaffMenu>         Different roles will have different menu options. </param>
    // <param nMenuID>            Menu entry id.                                    </param>
    // <param IMenuEventHandler*> Menu event handler.                               </param>
    void AddMenuSuscriber( Staff::eRole eStaffRole, int nMenuID, IMenuEventHandler* pHandler );
    
    // Menu selection event broadcast
    // <param eStaffRole>  User of the menu. </param>
    void PromptMenuSelect( Staff::eRole eStaffRole );
        
    // Display menu
    void DisplayMenu( Staff::eRole eStaffRole );
    
    // Output the text msg to the console screen
    // <param eTextColor>       Text Color.                 </param>
    // <param eBackgroundColor> Background Color.           </param>
    // <param nStyle>           Combination of text styles. </param>
    // <param strMsg>           Msg to be printed.          </param>
    static void Print( std::string strMsg );
    static void Print( std::string strMsg, ePixelColor eTextColor );
    static void Print( std::string strMsg, ePixelColor eTextColor, unsigned int nStyle );
    static void Print( std::string strMsg, ePixelColor eTextColor, unsigned int nStyle, ePixelColor eBackgroundColor );
    
    // Set the text color, text style and background color
    // <param eTextColor>       Text Color.                 </param>
    // <param eBackgroundColor> Background Color.           </param>
    // <param nStyle>           Combination of text styles. </param>
    static void Begin( ePixelColor eTextColor );
    static void Begin( ePixelColor eTextColor, unsigned int nStyle );
    static void Begin( ePixelColor eTextColor, unsigned int nStyle, ePixelColor eBackgroundColor );
    static void End();
    
    
    // Display header, which looks like this
    // ==============================================
    //                    [HEADER]
    // ==============================================
    //
    // This method automatically aligns the header to the center.
    // Note: DO NOT USE NEW LINE for the header text.
    // <param strHeader>        Header text.      </param>
    // <param eTextColor>       Text Color.       </param>
    // <param eBackgroundColor> Background Color. </param>
    static void DisplayHeader( std::string strHeader, ePixelColor eTextColor = GREEN, ePixelColor eBackgroundColor = BLUE );
    
    // Display logo
    static void DisplayLogo();
    
    // Display prompt
    // <param strMsg>     Prompt msg to the user. </param>
    // <param eTextColor> Text Color.             </param>
    static void DisplayPrompt( std::string strMsg, ePixelColor eTextColor = BLUE );
    
    // Displays the exit message - "Exiting SmartTravel Holidays Booking Management System"
    static void DisplayExit();
    
    // Clears the screen
    static void ClearScreen();
    
private:
    
    //====================
    //    Utility Tools
    //====================
    static std::string _GetTextStyle( unsigned int nStyle );
    
    //===================
    //    Data Fields
    //===================
    static std::map<ePixelColor, std::string>   m_mapTextColor;
    static std::map<ePixelColor, std::string>   m_mapBackgroundColor;
    static std::map<eTextStyle,  std::string>   m_mapTextStyle;
    
    
    struct MenuComponent
    {
        std::string                      strLabel;     // Menu label
        std::vector<IMenuEventHandler*>  aSuscribers;  // Suscribers
    };
    
    std::map<Staff::eRole, std::vector<MenuComponent> > m_mapMenuData;    
};
    
}  // End of namespace STB

#endif