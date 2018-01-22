#ifndef _Battle_H_
#define _Battle_H_

#include "Player.h"
#include "Variables.h"
//#include "Monsters.h"
//int count = 0;
//int16_t x;
//int16_t y;

//int cursor_x = 0;       //cursor position on screen x
//int cursor_y = 136;     //cursor position on screen y

//int battle options[] = {"Attack", "Item", "Weirding", "Flee"};

//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////
/*
 void drawbattle(uint16_t player_x, uint16_t player_y) {

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
 if(count == 0)
{
x = random(10,30); //sets the horizontal axis trigger from ten to thirty steps
y = random(10,30); //sets the vertical axis trigger from ten to thirty steps
count = 1;
}

Rect rectA {x,y,16,16};
Rect rectB {player_x, player_y,16,16};
Rect rectC {x,y,33,7};
Rect rectD {x,y,22,7};
Rect rectE {x,y,47,7};
Rect rectF {x,y,23,7};
Rect rectG {cursor_x,cursor_y,26,26};

if(tft.collideRectRect( rectA.x, rectA.y, rectA.width, rectA.height, rectB.x, rectB.y, rectB.width, rectB.height))
{
//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////
  tft.fillScreen(BLACK);
  tft.fillRect(0, 30, 320, 50, WHITE);  ////// draws a back grounds stripe for the monsters to sit on the length nof the screen
  tft.writeRectNBPP(143, 50, 34, 24, 4, cavespider, palette);
  tft.drawRoundRect(40, 82, 240, 40, 4, WHITE);
  tft.fillRoundRect(41, 83, 237, 37, 4, BLUE);
  tft.setCursor(90,94);
  tft.setTextColor(WHITE); 
  tft.setTextSize(2);
  tft.println("Cave spider");
  tft.drawRoundRect(10,130,118,104,4,WHITE);
  tft.fillRoundRect(11,131,115,101,4,BLUE);
  tft.setCursor(24,136);
  tft.setTextColor(WHITE); 
  tft.setTextSize(2);
  tft.println("Attack");
  tft.setCursor(24,160);
  tft.setTextColor(WHITE); 
  tft.setTextSize(2);
  tft.println("Item");
  tft.setCursor(24,181);
  tft.setTextColor(WHITE); 
  tft.setTextSize(2);
  tft.println("Weirding");
  tft.setCursor(24,211);
  tft.setTextColor(WHITE); 
  tft.setTextSize(2);
  tft.println("Flee");
  tft.writeRectNBPP(0,130,26,26,4,cursordot1,palette);
///////////////////////////////////////////////////////////////////////////////
////////////////////////////Up/////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
 if (ButtonUp.fallingEdge()){
     tft.writeRectNBPP(cursor_x,cursor_y,16,16,4,cursordot1,palette);
     cursor_y -= 26;
     if(checkcolision())
     {
      cursor_y += 26;} 
     }
     if(cursor_y <= 136){
        cursor_y = 136;}
          
//////////////////////////////////////////////////////////////////////////////
///////////////////////////////Down///////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////
 if (ButtonDown.fallingEdge()){
   tft.writeRectNBPP(cursor_x, cursor_y,16,16,4,cursordot1,palette);
   cursor_y += 26;
    if(checkcolision())
    {
    cursor_y -= 26;}
    }
    if(player_y >= 240){
       player_y = 240;}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////
if (player.player_direction == 1){
  tft.writeRectNBPP(cursor_x, cursor_y,26,26,4,cursordot1,palette);
}
       
///////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////

      if ((ButtonA.fallingEdge() && tft.collideRectRect( rectC.x, rectC.y, rectC.width, rectC.height, rectG.x, rectG.y, rectG.width, rectG.height)))
{
 //do some thing 
}
else if ((ButtonA.fallingEdge() && tft.collideRectRect( rectD.x, rectD.y, rectD.width, rectD.height, rectG.x, rectG.y, rectG.width, rectG.height)))
{
 //do some thing 
}
else if ((ButtonA.fallingEdge() && tft.collideRectRect( rectE.x, rectE.y, rectE.width, rectE.height, rectG.x, rectG.y, rectG.width, rectG.height)))
{
 //do some thing 
} 
else if ((ButtonA.fallingEdge() && tft.collideRectRect( rectF.x, rectF.y, rectF.width, rectF.height, rectG.x, rectG.y, rectG.width, rectG.height)))
{
 //do some thing 
}
  
          }
 };*/
#endif
