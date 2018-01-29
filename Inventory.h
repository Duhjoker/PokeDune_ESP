#ifndef _Inventory_H_
#define _Inventory_H_

#define ITEM_Spice          0
#define ITEM_Water          1
#define ITEM_Ring           2
#define ITEM_Crysknife      3
#define ITEM_Thumper        4
#define ITEM_Glowglobe      5
#define ITEM_Stilltent      6
#define ITEM_Abban          7
#define ITEM_Stillsuit      8
#define ITEM_Fremkit        9

#define MAX_ITEM            10
#define SLOT_AVAILABLE      255
#define NO_SLOT_AVAILABLE   254
#define NUMBER_OF_SLOTS     10

struct Slot {
  int slot_x;
  int slot_y;
  int slot_w;
  int slot_h;
  uint8_t itemId;
  uint8_t quantity;
};

Slot slots[NUMBER_OF_SLOTS] = {
  { 200, 48, 81, 16, SLOT_AVAILABLE},
  { 200, 66, 81, 16, SLOT_AVAILABLE},
  { 200, 84, 81, 16, SLOT_AVAILABLE},
  { 200, 102, 81, 16, SLOT_AVAILABLE},
  { 200, 112, 81, 16, SLOT_AVAILABLE},
  { 200, 120, 81, 16, SLOT_AVAILABLE},
  { 200, 138, 81, 16, SLOT_AVAILABLE},
  { 200, 156, 81, 16, SLOT_AVAILABLE},
  { 200, 174, 81, 16, SLOT_AVAILABLE},
  { 200, 192, 81, 16, SLOT_AVAILABLE},
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
  tft.writeRectNBPP(0, 0, 136, 20, 4, menul1, palette);
  tft.writeRectNBPP(0, 20, 136, 40, 4, menul2, palette);
  tft.writeRectNBPP(0, 60, 136, 40, 4, menul3, palette);
  tft.writeRectNBPP(0, 100, 136, 40, 4, menul4, palette);
  tft.writeRectNBPP(0, 140, 136, 40, 4, menul5, palette);
  tft.writeRectNBPP(0, 180, 136, 40, 4, menul6, palette);
  tft.writeRectNBPP(0, 220, 136, 20, 4, menul7, palette);
  tft.writeRectNBPP(136, 0, 184, 26, 4, menur1, palette);
  tft.writeRectNBPP(136, 26, 184, 16, 4, menur2, palette);
  tft.writeRectNBPP(136, 42, 184, 16, 4, menur2, palette);
  tft.writeRectNBPP(136, 58, 184, 16, 4, menur2, palette);
  tft.writeRectNBPP(136, 74, 184, 16, 4, menur2, palette);
  tft.writeRectNBPP(136, 90, 184, 16, 4, menur2, palette);
  tft.writeRectNBPP(136, 106, 184, 16, 4, menur2, palette);
  tft.writeRectNBPP(136, 122, 184, 16, 4, menur2, palette);
  tft.writeRectNBPP(136, 138, 184, 16, 4, menur2, palette);
  tft.writeRectNBPP(136, 154, 184, 16, 4, menur2, palette);
  tft.writeRectNBPP(136, 170, 184, 16, 4, menur2, palette);
  tft.writeRectNBPP(136, 186, 184, 16, 4, menur2, palette);
  tft.writeRectNBPP(136, 202, 184, 16, 4, menur2, palette);
  tft.writeRectNBPP(136, 218, 184, 22, 4, menur3, palette);
  //////////////////////////////////////////////////////////////////////////////////////////
  //////////////////////////////////////////////////////////////////////////////////////////
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
