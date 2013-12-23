#define _Digole_Serial_SPI_
#include <DigoleSerial.h>
#ifndef qMenuDisplay_h
#define qMenuDisplay_h

class qMenuDisplay
{
  public:
    qMenuDisplay(DigoleSerialDisp disp);
    qMenuDisplay();
    void Start();
    void Finish();
    void Title(const char text[]);
    void Item(int index,const char text[]);
    void Highlight(int index);
    void MessageBox(const char text[]);
  private:
//    char tempBuffer[32];
};




#endif
