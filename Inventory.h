#ifndef _Inventory_H_
#define _Inventory_H_

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
#define MaxChests           4

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
};

Slot slots[NUMBER_OF_SLOTS] = {
  { 180, 24,  81, 16, SLOT_AVAILABLE, 0},
  { 180, 42,  81, 16, SLOT_AVAILABLE, 0},
  { 180, 60,  81, 16, SLOT_AVAILABLE, 0},
  { 180, 78,  81, 16, SLOT_AVAILABLE, 0},
  { 180, 96,  81, 16, SLOT_AVAILABLE, 0},
  { 180, 114, 81, 16, SLOT_AVAILABLE, 0},
  { 180, 132, 81, 16, SLOT_AVAILABLE, 0},
  { 180, 150, 81, 16, SLOT_AVAILABLE, 0},
  { 180, 168, 81, 16, SLOT_AVAILABLE, 0},
  { 180, 186, 81, 16, SLOT_AVAILABLE, 0}, 
  { 180, 204, 81, 16, SLOT_AVAILABLE, 0},
  { 180, 222, 81, 16, SLOT_AVAILABLE, 0},
};
///////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////
/*class Chest
{
  public:
    uint16_t x;
    uint16_t y;
    uint8_t itemId;
    bool isOpen;
};

Chest chests[] =
{
  { 304, 464, ITEM_Spice, false }, 
 
};

class Room
{
public:
  Chest chests[MaxChests];
  int chestCount;

  uint8_t getChestCount() { return chestCount;}
    Chest[] getChests() { return chests; }

};

Room rooms[] = 
{
  {1},
  }; */
///////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////
class Chest
{
  public:
    uint8_t itemId;
    bool isOpen;
};

#define NoItem 255

Chest chests[] =
{
  { ITEM_Spice, false }, 
  { ITEM_Spice, false },
 
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
  Rect rectA {0, 0, 136, 20};
  Rect rectB {0, 20, 136, 40};
  Rect rectC {0, 60, 136, 40};
  Rect rectD {0, 0, 136, 20};
  Rect rectE {0, 20, 136, 40};
  Rect rectF {0, 60, 136, 40};
  Rect rectG {0, 0, 136, 20};
  Rect rectH {0, 20, 136, 40};
  Rect rectI {0, 60, 136, 40};
  Rect rectJ {0, 0, 136, 20};
  Rect rectK {0, 20, 136, 40};
  Rect rectL {0, 60, 136, 40};
  Rect rectM {0, 60, 136, 40};
  
  tft.fillRoundRect(140, 0, 160, 240, 4, WHITE);
  tft.fillRoundRect(145, 4, 150, 232, 4, BLUE);
  printInventory();


 
  //////////////////////////////////////////////////////////////////////////////////////////
  //////////////////////////////////////////////////////////////////////////////////////////
  if (!digitalRead(IRQ_PIN2)) {
    uint32_t buttons = ss2.digitalReadBulk(button_mask2);
    if (! (buttons & (1 << BUTTON_A))) {
      state = STATE_Menu;
    }
    //////////////////////////////////////////////////////////////////////////////////////////
    //////////////////////////////////////////////////////////////////////////////////////////
  }
}
#endif
