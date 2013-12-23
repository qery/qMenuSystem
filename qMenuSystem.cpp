/////////////////////
// qMenuSystem
// version: 1.0
// 22.12.2013
// CLASS
/////////////////////
#include <avr/pgmspace.h>
#include "qMenuSystem.h"
#include "qMenuDisplay.h"

//DigoleSerialDisp disp(255,255,255);
//qMenuDisplay qmd;

qMenuSystem::qMenuSystem(DigoleSerialDisp disp)
{
  qmd=qMenuDisplay(disp);
  _selectedIndex=0;
  _itemCount=0;
  _firstVisible=1;
}

void qMenuSystem::InitMenu(const char ** page, int itemCount, int selectedIndex)
{
  CurrentMenu=page;
  _selectedIndex=selectedIndex;
  _itemCount=itemCount;
//  ProcessMenu(ACTION_NONE);
  ShowMenu();
}

int qMenuSystem::ProcessMenu(int action)
{
  if (action==ACTION_DOWN)
    _selectedIndex++;
  if (action==ACTION_UP)
    _selectedIndex--;
    
  if (_selectedIndex>_itemCount)
    _selectedIndex=1;
  if (_selectedIndex<1)
    _selectedIndex=_itemCount;
  
  if (action==ACTION_SELECT)
    return _selectedIndex;
  
  ShowMenu();
  
  return 0;
}

void qMenuSystem::ShowMenu()
{
  if (_selectedIndex>_firstVisible+2)
    _firstVisible=_selectedIndex-2;
  else if (_selectedIndex<_firstVisible)
    _firstVisible=_selectedIndex;
  
  qmd.Start();
  
  // display title
  strcpy_P(tempBuffer, (char*)pgm_read_word(&(CurrentMenu[0])));
  qmd.Title(tempBuffer);
  
  // display items
  int p = 3;
  if (p > (_itemCount-_firstVisible+1))
    p=_itemCount-_firstVisible+1;
  for (int i=0;i<p;i++)
  {
    strcpy_P(tempBuffer, (char*)pgm_read_word(&(CurrentMenu[i+_firstVisible])));
    qmd.Item(i,tempBuffer);
  }
  
  // display selection
  qmd.Highlight(_selectedIndex-_firstVisible);
  
  qmd.Finish();
}

