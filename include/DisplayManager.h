//===================================================================
/*
   CSCI 222 Assignment 2

   This is a utility tool to display text messages to the console.  
*/
//===================================================================

#ifndef DISPLAYMANAGER_H
#define	DISPLAYMANAGER_H

#include <map>
#include <string>


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



//============================
//    Class DisplayManager    
//============================
class DisplayManager
{
public:
    
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
    // This method automatically aligns the header to the center
    // <param strHeader>        Header text.      </param>
    // <param eTextColor>       Text Color.       </param>
    // <param eBackgroundColor> Background Color. </param>
    static void DisplayHeader( std::string strHeader, ePixelColor eTextColor = GREEN, ePixelColor eBackgroundColor = BLUE );
    
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
    
};
    
}  // End of namespace STB

#endif