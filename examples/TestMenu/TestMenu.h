// required for "prog_char" and "PROGMEM"
#include <avr/pgmspace.h>

// texts for menus

prog_char itmBack[] PROGMEM = "< Back";
prog_char itmOn[] PROGMEM = "On";
prog_char itmOff[] PROGMEM = "Off";
prog_char itmEnabled[] PROGMEM = "Enabled";
prog_char itmDisabled[] PROGMEM = "Disabled";

prog_char itmRoot[] PROGMEM = "Root menu";
prog_char itmSubmenu1[] PROGMEM = "Submenu 1";
prog_char itmSubmenu2[] PROGMEM = "Submenu 2";
prog_char itmSubmenu3[] PROGMEM = "Submenu 3";
prog_char itmMessageBox[] PROGMEM = "Message box";
prog_char itmItem1[] PROGMEM = "Item 1";
prog_char itmItem2[] PROGMEM = "Item 2";
prog_char itmItem3[] PROGMEM = "Item 3";
prog_char itmItem4[] PROGMEM = "Item 4";
prog_char itmItem5[] PROGMEM = "Item 5";

////////////////////////////////////////////////////////////////
// menus - first item is menu title and it does not count toward cnt

PROGMEM const char * mnuRoot[] = {
  itmRoot,
  itmSubmenu1,itmSubmenu2,itmSubmenu3,itmMessageBox};
PROGMEM const int cntRoot = 4;

PROGMEM const char * mnuSubmenu1[] = {
  itmSubmenu1,
  itmItem1,itmItem2,itmItem3,itmItem4,itmItem5,itmBack};
PROGMEM const int cntSubmenu1 = 6;

PROGMEM const char * mnuSubmenu2[] = {
  itmSubmenu2,
  itmOn,itmOff,itmBack};
PROGMEM const int cntSubmenu2 = 3;

PROGMEM const char * mnuSubmenu3[] = {
  itmSubmenu3,
  itmEnabled,itmDisabled,itmBack};
PROGMEM const int cntSubmenu3 = 3;




