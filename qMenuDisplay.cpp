#include "qMenuDisplay.h"

DigoleSerialDisp _disp(8,9,10);

qMenuDisplay::qMenuDisplay()
{
}

qMenuDisplay::qMenuDisplay(DigoleSerialDisp disp)
{
  _disp=disp;
}

void qMenuDisplay::Start()
{
  _disp.clearScreen();
  _disp.setFont(18);
}

void qMenuDisplay::Finish()
{
}

void qMenuDisplay::Title(const char text[])
{
  _disp.setTextPosAbs(64-strlen(text)*9/2,11);
  _disp.print(text);
  _disp.drawHLine(0,14,128);
}

void qMenuDisplay::Item(int index,const char text[])
{
  _disp.setTextPosAbs(5,(index*14)+32);
  _disp.print(text);
}

void qMenuDisplay::Highlight(int index)
{
  _disp.setMode('~');
  _disp.drawBox(4,(index*14)+20,120,13);
}

void qMenuDisplay::MessageBox(const char text[])
{
  int textWidth=strlen(text)*9;
  int x=64-(textWidth/2);
  int y=32;

  _disp.setMode('&');
  _disp.setColor(0);
  _disp.drawBox(x-5,y-12,textWidth+9,21+3);
  _disp.setMode('~');
  _disp.setColor(1);
  _disp.drawFrame(x-3,y-10,textWidth+5,17+3);

  _disp.setTextPosAbs(x,y+5);
  _disp.print(text);
}

