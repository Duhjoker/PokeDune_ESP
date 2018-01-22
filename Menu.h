#ifndef _Menu_H_
#define _Menu_H_

#include "Variables.h"
#include "Player.h"
#include "World.h"


///////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////
struct CursorA
{
  int cursorA_x; 
  int cursorA_y; 
  int cursor_direction;
};

 CursorA cursora = { 17, 31, 1};
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int menu_1 = 1;

struct Item{
 uint8_t x;
 uint8_t y;
 uint8_t ID;
 uint8_t S;
 bool Active;
};

const uint8_t MaxItem = 10;

const uint8_t MaxSlots = 10;

struct Item Enviroment[MaxItem];

struct Item Inventory[MaxSlots];
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
struct Slot {
  int x;
  int y;
  int w;
  int h;
  bool avail;
};
const uint8_t no_of_slots = 10;

const Slot slots[no_of_slots] = { 
  { 16, 48, 81, 16, true},
  { 16, 64, 81, 16, true},
  { 16, 80, 81, 16, true},
  { 16, 96, 81, 16, true},
  { 16, 112, 81, 16, true},
  { 16, 128, 81, 16, true},
  { 16, 144, 81, 16, true},
  { 16, 160, 81, 16, true},
  { 16, 176, 81, 16, true},
  { 16, 192, 81, 16, true},
 // { 16, 208, 81, 16 },

};
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void AddInv(uint8_t Item){
  bool Added = false;                 
  for(uint8_t i=0; i<  MaxSlots; i++){                             // for unsigned 8 equals 0, i is less than the max amount of slots increments i plus 2
    if((Inventory[i].ID == Item)&&(Inventory[i].S < MaxItem)){     // if inventoryis i id equals item and inventory slot is less than the max item amount
          Inventory[i].S++;                                        // increment the slot position 
          Added = true;                // <<< Was AddInv = true;   
          break;                                                   // stop operation
    }
 }

 if (!Added) {                          //<<< Was if (!AddInv) {
   for(uint8_t i=0; i<  MaxSlots; i++){
      if(Inventory[i].ID == 0){
            Inventory[i].S++;
            Inventory[i].ID = Item;
            Added = true;               //<<< Was AddInv = true;
            break;
      }
    }
  }
return;                          //<<< Was return AddInv;
}
///////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////


uint8_t getFirstAvailSlot() {

  for (uint8_t i = 0; i < no_of_slots; i++) {      ///// for unsingned 8 equals 0 i is less than the number of slot
    if (slots[i].avail == true) return i;          ///// use available slot
  }

  return 255; // Or something that signifies no slots available ..

}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void Menu(){
//////////////////////////////////////////////////////////////////////////////
///////////////////////////////Palette////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////
 palette[0] = 0;
       palette[1] = BLACK;
             palette[2] = BLUE;
                   palette[3] = BROWN;
                         palette[4] = DARKGREEN;
                              palette[5] = GREY;
                                    palette[6] = PINK;
                                          palette[7] = RED;
//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////                                                
                                           palette[8] = BEIGE;
                                     palette[9] = GREEN;
                               palette[a]= DARKGREY;
                         palette[b] = LIGHTGREY;
                   palette[c] = YELLOW; 
             palette[d] = PURPLE; 
       palette[e] = WHITE;
 palette[f] = ORANGE;
//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////
Rect rectA {0,0,136,20};
Rect rectB {0,20,136,40};
Rect rectC {0,60,136,40};
Rect rectD {0,100,136,40};
Rect rectE {0,140,136,40};
Rect rectF {0,180,136,40};
Rect rectG {0,220,136,20};
Rect rectH {cursora.cursorA_x,cursora.cursorA_y,16,16};
/////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////
 tft.writeRectNBPP(0,0,136,20,4,menul1,palette);
  tft.writeRectNBPP(0,20,136,40,4,menul2,palette);
   tft.writeRectNBPP(0,60,136,40,4,menul3,palette);
    tft.writeRectNBPP(0,100,136,40,4,menul4,palette);
     tft.writeRectNBPP(0,140,136,40,4,menul5,palette);
      tft.writeRectNBPP(0,180,136,40,4,menul6,palette);
       tft.writeRectNBPP(0,220,136,20,4,menul7,palette);
        tft.writeRectNBPP(136,0,184,26,4,menur1,palette);
         tft.writeRectNBPP(136,26,184,16,4,menur2,palette);
          tft.writeRectNBPP(136,42,184,16,4,menur2,palette);
           tft.writeRectNBPP(136,58,184,16,4,menur2,palette);
          tft.writeRectNBPP(136,74,184,16,4,menur2,palette);
         tft.writeRectNBPP(136,90,184,16,4,menur2,palette);
        tft.writeRectNBPP(136,106,184,16,4,menur2,palette);
       tft.writeRectNBPP(136,122,184,16,4,menur2,palette);
      tft.writeRectNBPP(136,138,184,16,4,menur2,palette);
     tft.writeRectNBPP(136,154,184,16,4,menur2,palette);
    tft.writeRectNBPP(136,170,184,16,4,menur2,palette);
   tft.writeRectNBPP(136,186,184,16,4,menur2,palette);
  tft.writeRectNBPP(136,202,184,16,4,menur2,palette);
 tft.writeRectNBPP(136,218,184,22,4,menur3,palette);
///////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////
  int y = ss1.analogRead(2);
  int x = ss1.analogRead(3);
  
/// if(tft.Bpressed(BTN_UP)){
   if(x > 600 && last_x < 600){
     tft.writeRectNBPP(cursora.cursorA_x,cursora.cursorA_y,16,16,4,cursordot2,palette);
     cursora.cursor_direction = 1;
     cursora.cursorA_y -= 40;
   } 
     if(cursora.cursorA_y <= 30){
        cursora.cursorA_y = 30;}  
              
//////////////////////////////////////////////////////////////////////////////
///////////////////////////////Down///////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////
/// if(tft.Bpressed(BTN_DOWN)){
 if(x < 400 && last_x > 400){
   tft.writeRectNBPP(cursora.cursorA_x, cursora.cursorA_y,16,16,4,cursordot2,palette);
   cursora.cursor_direction = 1;
   cursora.cursorA_y += 40;
 }
    if(cursora.cursorA_y >= 192){
       cursora.cursorA_y = 192;}

         last_x = x;
//////////////////////////////////////////////////////////////////////////////
/////////////////////////////////exit menu////////////////////////////////////
////////////////////////////////////////////////////////////////////////////// 
  if(!digitalRead(IRQ_PIN2)){
    uint32_t buttons = ss2.digitalReadBulk(button_mask2);
if (! (buttons & (1 << BUTTON_A))) { 
  state = STATE_Player;             
    }  
 }      
///////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////
  if (cursora.cursor_direction == 1){
  tft.writeRectNBPP(cursora.cursorA_x, cursora.cursorA_y,16,16,4,cursordot2,palette);
   } 
  }

///////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*
     if((tft.Bpressed(BTN_B) && tft.collideRectRect( rectB.x, rectB.y, rectB.width, rectB.height, rectH.x, rectH.y, rectH.width, rectH.height)))
{
// do some thing 
}
else if((tft.Bpressed(BTN_B) && tft.collideRectRect( rectC.x, rectC.y, rectC.width, rectC.height, rectH.x, rectH.y, rectH.width, rectH.height)))
{
// do some thing 
} 
else if((tft.Bpressed(BTN_B) && tft.collideRectRect( rectD.x, rectD.y, rectD.width, rectD.height, rectH.x, rectH.y, rectH.width, rectH.height)))
{
// do some thing 
}
else if((tft.Bpressed(BTN_B) && tft.collideRectRect( rectE.x, rectE.y, rectE.width, rectE.height, rectH.x, rectH.y, rectH.width, rectH.height)))
{
// do some thing 
}
else if((tft.Bpressed(BTN_B) && tft.collideRectRect( rectF.x, rectF.y, rectF.width, rectF.height, rectH.x, rectH.y, rectH.width, rectH.height)))
{
// do some thing 
   }
   if (player.player_direction == 1){
  tft.writeRectNBPP(cursora.cursorA_x, cursora.cursorA_y,16,16,4,cursordot2,palette);
}
}
*/
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#endif
