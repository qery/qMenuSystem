/////////////////////
// qMenuSystem
// version: 1.0
// 22.12.2013
// HEADER
/////////////////////
#include "qMenuDisplay.h"

#ifndef qMenuSystem_h
#define qMenuSystem_h

#define ACTION_NONE    0
#define ACTION_UP      1
#define ACTION_DOWN    2
#define ACTION_SELECT  3
#define ACTION_BACK    4


class qMenuSystem
{
  public:
    qMenuSystem(DigoleSerialDisp disp);
    void InitMenu(const char ** page, int itemCount, int selectedIndex);
    int ProcessMenu(int action);
    void ShowMenu();
    void MessageBox(const char text[]) { qmd.MessageBox(text); };
    
    const char ** CurrentMenu;
  private:
    int _selectedIndex;
    int _itemCount;
    int _firstVisible;
    
    char tempBuffer[32];
    qMenuDisplay qmd;
};

#endif
