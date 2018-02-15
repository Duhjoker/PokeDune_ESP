#ifndef _Inventory_H_
#define _Inventory_H_

#include "Variables.h"

#define ITEM_Spice          0
#define ITEM_Water          1
#define ITEM_Ring           2
#define ITEM_Crysknife      3
#define ITEM_Thumper        4
#define ITEM_Glowglobe      5
#define ITEM_Stilltent      6
#define ITEM_Abba           7
#define ITEM_Stillsuit      8
#define ITEM_Fremkit        9

#define NoItem              255
#define MaxChests           2

#define MAX_ITEM            10
#define SLOT_AVAILABLE      255
#define NO_SLOT_AVAILABLE   254
#define NUMBER_OF_SLOTS     12

struct Slot {
  int slot_x;
  int slot_y;
  int slot_w;
  int slot_h;
  uint8_t itemId;
  uint8_t quantity;
  uint8_t S;     // number of items in stack
};

Slot slots[NUMBER_OF_SLOTS] = {
  { 180, 16,  81, 16, SLOT_AVAILABLE, 0},
  { 180, 34,  81, 16, SLOT_AVAILABLE, 0},
  { 180, 52,  81, 16, SLOT_AVAILABLE, 0},
  { 180, 70,  81, 16, SLOT_AVAILABLE, 0},
  { 180, 88,  81, 16, SLOT_AVAILABLE, 0},
  { 180, 106, 81, 16, SLOT_AVAILABLE, 0},
  { 180, 124, 81, 16, SLOT_AVAILABLE, 0},
  { 180, 142, 81, 16, SLOT_AVAILABLE, 0},
  { 180, 160, 81, 16, SLOT_AVAILABLE, 0},
  { 180, 178, 81, 16, SLOT_AVAILABLE, 0},
  { 180, 196, 81, 16, SLOT_AVAILABLE, 0},
  { 180, 214, 81, 16, SLOT_AVAILABLE, 0},
};
///////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////
class Chest
  {
  public:
    uint16_t w;
    uint16_t h;
    uint8_t itemId;
    bool isOpen;
  };


  Chest chests[] =
  {
  {16, 16, ITEM_Spice, false },
  {16, 16, ITEM_Spice, false },

  };

///////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////
bool addItemToInventory(uint8_t itemId) {

  bool added = false;

  for (uint8_t i = 0; i <  NUMBER_OF_SLOTS; i++) {

    Slot *slot = &slots[i];

    if ((slot->itemId == itemId) && (slot->quantity < MAX_ITEM)) {  // if inventory id equals item and inventory slot is less than the max item amount
      slot->quantity++;                                            // increment the quantity
      added = true;
      break;
    }

  }

  if (!added) {

    for (uint8_t i = 0; i <  NUMBER_OF_SLOTS; i++) {

      Slot *slot = &slots[i];

      if (slot->itemId == SLOT_AVAILABLE) {
        slot->quantity++;
        slot->itemId = itemId;
        added = true;
        break;
      }

    }

  }

  return added;

}
///////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////
void removeItemFromInventory(uint8_t itemId) {

  for (uint8_t i = 0; i <  NUMBER_OF_SLOTS; i++) {

    Slot *slot = &slots[i];

    if (slot->itemId == itemId) {

      slot->quantity--;

      if (slot->quantity == 0) {
        slot->itemId = SLOT_AVAILABLE;
      }

      break;
    }

  }

}
///////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////
const char * getItemName(uint8_t itemId)
{
  switch (itemId)
  {
    case 0: return "Spice";
    case 1: return "Water";
    case 2: return "Ring";
    case 3: return "Crysknife";
    case 4: return "Thumper";
    case 5: return "Glowglobe";
    case 6: return "Stilltent";
    case 7: return "Abba";
    case 8: return "Stillsuit";
    case 9: return "Fremkit";
    default: return "INVALID ITEM";
  }
}
///////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////
//void printName(Slot slot)
//{
//  printName(slot, 2, WHITE);
//}
///////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////
void printName(Slot slot, int size, int colour)
{
  tft.setCursor(slot.slot_x, slot.slot_y);
  tft.setTextSize(size);
  tft.setTextColor(colour);
  tft.println(getItemName(slot.itemId));
  tft.setCursor(270, slot.slot_y);
  tft.setTextSize(size);
  tft.setTextColor(colour);
  tft.println(slot.quantity);
}
///////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////
void printInventory() {

  for (uint8_t i = 0; i <  NUMBER_OF_SLOTS; i++) {

    Serial.print(" Slot #");
    Serial.print(i);
    Serial.print(": ");

    if (slots[i].itemId == SLOT_AVAILABLE) {
      Serial.println("Slot is empty.");
    }
    else {
      Serial.print("Slot contains ");
      Serial.print(slots[i].quantity);
      Serial.print(" of ");
      printName(slots[i], 2, WHITE);
      Serial.println("");
    }

  }

  Serial.println("");

}
////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////
void printItemlist() {
  Rect rectA {180, 16, 81, 16};
  Rect rectB {180, 34, 81, 16};
  Rect rectC {180, 52, 81, 16};
  Rect rectD {180, 70, 81, 16};
  Rect rectE {180, 106, 81, 16};
  Rect rectF {180, 124, 81, 16};
  Rect rectG {180, 142, 81, 16};
  Rect rectH {180, 160, 81, 16};
  Rect rectI {180, 178, 81, 16};
  Rect rectJ {180, 196, 81, 16};
  Rect rectK {180, 214, 81, 16};
  Rect rectL {cursore.cursorE_x, cursore.cursorE_y, 32, 32,};

  tft.fillRoundRect(140, 0, 160, 240, 4, WHITE);
  tft.fillRoundRect(145, 4, 150, 232, 4, BLUE);
  printInventory();
  //////////////////////////////////////////////////////////////////////////////////////////
  //////////////////////////////////////////////////////////////////////////////////////////
  int y = ss1.analogRead(2);
  int x = ss1.analogRead(3);

  /// if(tft.Bpressed(BTN_UP)){
  if (x > 600 && last_x < 600) {
    tft.writeRectNBPP(cursore.cursorE_x, cursore.cursorE_y, 32, 32, 4, cursor3, palette);
    cursore.cursor_direction = 1;
    cursore.cursorE_y -= 18;
  }
  if (cursore.cursorE_y <= 14) {
    cursore.cursorE_y = 14;
  }

  //////////////////////////////////////////////////////////////////////////////
  ///////////////////////////////Down///////////////////////////////////////////
  //////////////////////////////////////////////////////////////////////////////
  /// if(tft.Bpressed(BTN_DOWN)){
  if (x < 400 && last_x > 400) {
    tft.writeRectNBPP(cursore.cursorE_x, cursore.cursorE_y, 32, 32, 4, cursor3, palette);
    cursore.cursor_direction = 1;
    cursore.cursorE_y += 18;
  }
  if (cursore.cursorE_y >= 214) {
    cursore.cursorE_y = 214;
  }

  last_x = x;
  /////////////////////////////////////////////////////////////////////////////////////////
  /////////////////////////////////////////////////////////////////////////////////////////
  if (cursore.cursor_direction == 1) {
    tft.writeRectNBPP(cursore.cursorE_x, cursore.cursorE_y, 32, 32, 4, cursor3, palette);
  }

  //////////////////////////////////////////////////////////////////////////////////////////
  //////////////////////////////////////////////////////////////////////////////////////////
  if (!digitalRead(IRQ_PIN2)) {
    uint32_t buttons = ss2.digitalReadBulk(button_mask2);
    if (! (buttons & (1 << BUTTON_A))) {
      state = STATE_Menu;
    }
    //////////////////////////////////////////////////////////////////////////////////////////
    //////////////////////////////////////////////////////////////////////////////////////////
          if ((! (buttons & (1 << BUTTON_X)) && tft.collideRectRect( rectA.x, rectA.y, rectA.width, rectA.height, rectL.x, rectL.y, rectL.width, rectL.height)))
    {
      tft.fillScreen(GREEN);
    }
    else if ((! (buttons & (1 << BUTTON_X)) && tft.collideRectRect( rectB.x, rectB.y, rectB.width, rectB.height, rectL.x, rectL.y, rectL.width, rectL.height)))
    {
      tft.fillScreen(PURPLE); 
    }
    else if ((! (buttons & (1 << BUTTON_X))  && tft.collideRectRect( rectC.x, rectC.y, rectC.width, rectC.height, rectL.x, rectL.y, rectL.width, rectL.height)))
    {
      tft.fillScreen(GREEN);
    }
    else if ((! (buttons & (1 << BUTTON_X)) && tft.collideRectRect( rectD.x, rectD.y, rectD.width, rectD.height, rectL.x, rectL.y, rectL.width, rectL.height)))
    {
      tft.fillScreen(RED);
    }
    else if ((! (buttons & (1 << BUTTON_X)) && tft.collideRectRect( rectE.x, rectE.y, rectE.width, rectE.height, rectL.x, rectL.y, rectL.width, rectL.height)))
    {
      tft.fillScreen(YELLOW);
    }
    else if ((! (buttons & (1 << BUTTON_X)) && tft.collideRectRect( rectF.x, rectF.y, rectF.width, rectF.height, rectL.x, rectL.y, rectL.width, rectL.height)))
    {
      tft.fillScreen(WHITE);
    }
    else if ((! (buttons & (1 << BUTTON_X)) && tft.collideRectRect( rectG.x, rectG.y, rectG.width, rectG.height, rectL.x, rectL.y, rectL.width, rectL.height)))
    {
      tft.fillScreen(GREEN);
    }
    else if ((! (buttons & (1 << BUTTON_X)) && tft.collideRectRect( rectH.x, rectH.y, rectH.width, rectH.height, rectL.x, rectL.y, rectL.width, rectL.height)))
    {
      tft.fillScreen(RED);
    }
    else if ((! (buttons & (1 << BUTTON_X)) && tft.collideRectRect( rectI.x, rectI.y, rectI.width, rectI.height, rectL.x, rectL.y, rectL.width, rectL.height)))
    {
      tft.fillScreen(YELLOW);
    }
    else if ((! (buttons & (1 << BUTTON_X)) && tft.collideRectRect( rectJ.x, rectJ.y, rectJ.width, rectJ.height, rectL.x, rectL.y, rectL.width, rectL.height)))
    {
      tft.fillScreen(WHITE);
    }
    else if ((! (buttons & (1 << BUTTON_X)) && tft.collideRectRect( rectK.x, rectK.y, rectK.width, rectK.height, rectL.x, rectL.y, rectL.width, rectL.height)))
    {
      tft.fillScreen(GREEN);
    }
  }
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void ItemlistBat() {
  Rect rectA {180, 16, 81, 16};
  Rect rectB {180, 34, 81, 16};
  Rect rectC {180, 52, 81, 16};
  Rect rectD {180, 70, 81, 16};
  Rect rectE {180, 106, 81, 16};
  Rect rectF {180, 124, 81, 16};
  Rect rectG {180, 142, 81, 16};
  Rect rectH {180, 160, 81, 16};
  Rect rectI {180, 178, 81, 16};
  Rect rectJ {180, 196, 81, 16};
  Rect rectK {180, 214, 81, 16};
  Rect rectL {cursore.cursorE_x, cursore.cursorE_y, 32, 32,};

  tft.fillRoundRect(140, 0, 160, 240, 4, WHITE);
  tft.fillRoundRect(145, 4, 150, 232, 4, BLUE);
  printInventory();
  //////////////////////////////////////////////////////////////////////////////////////////
  //////////////////////////////////////////////////////////////////////////////////////////
  int y = ss1.analogRead(2);
  int x = ss1.analogRead(3);

  /// if(tft.Bpressed(BTN_UP)){
  if (x > 600 && last_x < 600) {
    tft.writeRectNBPP(cursore.cursorE_x, cursore.cursorE_y, 32, 32, 4, cursor3, palette);
    cursore.cursor_direction = 1;
    cursore.cursorE_y -= 18;
  }
  if (cursore.cursorE_y <= 14) {
    cursore.cursorE_y = 14;
  }

  //////////////////////////////////////////////////////////////////////////////
  ///////////////////////////////Down///////////////////////////////////////////
  //////////////////////////////////////////////////////////////////////////////
  /// if(tft.Bpressed(BTN_DOWN)){
  if (x < 400 && last_x > 400) {
    tft.writeRectNBPP(cursore.cursorE_x, cursore.cursorE_y, 32, 32, 4, cursor3, palette);
    cursore.cursor_direction = 1;
    cursore.cursorE_y += 18;
  }
  if (cursore.cursorE_y >= 214) {
    cursore.cursorE_y = 214;
  }

  last_x = x;
  /////////////////////////////////////////////////////////////////////////////////////////
  /////////////////////////////////////////////////////////////////////////////////////////
  if (cursore.cursor_direction == 1) {
    tft.writeRectNBPP(cursore.cursorE_x, cursore.cursorE_y, 32, 32, 4, cursor3, palette);
  }

  //////////////////////////////////////////////////////////////////////////////////////////
  //////////////////////////////////////////////////////////////////////////////////////////
  if (!digitalRead(IRQ_PIN2)) {
    uint32_t buttons = ss2.digitalReadBulk(button_mask2);
    if (! (buttons & (1 << BUTTON_A))) {
      state = STATE_Battle;
    }
    //////////////////////////////////////////////////////////////////////////////////////////
    //////////////////////////////////////////////////////////////////////////////////////////
          if ((! (buttons & (1 << BUTTON_X)) && tft.collideRectRect( rectA.x, rectA.y, rectA.width, rectA.height, rectL.x, rectL.y, rectL.width, rectL.height)))
    {
      tft.fillScreen(GREEN);
    }
    else if ((! (buttons & (1 << BUTTON_X)) && tft.collideRectRect( rectB.x, rectB.y, rectB.width, rectB.height, rectL.x, rectL.y, rectL.width, rectL.height)))
    {
      tft.fillScreen(PURPLE); 
    }
    else if ((! (buttons & (1 << BUTTON_X))  && tft.collideRectRect( rectC.x, rectC.y, rectC.width, rectC.height, rectL.x, rectL.y, rectL.width, rectL.height)))
    {
      tft.fillScreen(GREEN);
    }
    else if ((! (buttons & (1 << BUTTON_X)) && tft.collideRectRect( rectD.x, rectD.y, rectD.width, rectD.height, rectL.x, rectL.y, rectL.width, rectL.height)))
    {
      tft.fillScreen(RED);
    }
    else if ((! (buttons & (1 << BUTTON_X)) && tft.collideRectRect( rectE.x, rectE.y, rectE.width, rectE.height, rectL.x, rectL.y, rectL.width, rectL.height)))
    {
      tft.fillScreen(YELLOW);
    }
    else if ((! (buttons & (1 << BUTTON_X)) && tft.collideRectRect( rectF.x, rectF.y, rectF.width, rectF.height, rectL.x, rectL.y, rectL.width, rectL.height)))
    {
      tft.fillScreen(WHITE);
    }
    else if ((! (buttons & (1 << BUTTON_X)) && tft.collideRectRect( rectG.x, rectG.y, rectG.width, rectG.height, rectL.x, rectL.y, rectL.width, rectL.height)))
    {
      tft.fillScreen(GREEN);
    }
    else if ((! (buttons & (1 << BUTTON_X)) && tft.collideRectRect( rectH.x, rectH.y, rectH.width, rectH.height, rectL.x, rectL.y, rectL.width, rectL.height)))
    {
      tft.fillScreen(RED);
    }
    else if ((! (buttons & (1 << BUTTON_X)) && tft.collideRectRect( rectI.x, rectI.y, rectI.width, rectI.height, rectL.x, rectL.y, rectL.width, rectL.height)))
    {
      tft.fillScreen(YELLOW);
    }
    else if ((! (buttons & (1 << BUTTON_X)) && tft.collideRectRect( rectJ.x, rectJ.y, rectJ.width, rectJ.height, rectL.x, rectL.y, rectL.width, rectL.height)))
    {
      tft.fillScreen(WHITE);
    }
    else if ((! (buttons & (1 << BUTTON_X)) && tft.collideRectRect( rectK.x, rectK.y, rectK.width, rectK.height, rectL.x, rectL.y, rectL.width, rectL.height)))
    {
      tft.fillScreen(GREEN);
    }
  }
}




#endif
