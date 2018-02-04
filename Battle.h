#ifndef _Battle_H_
#define _Battle_H_

#include "Player.h"
#include "Variables.h"
#include "Monsters.h"


struct CursorB
{
  int cursorB_x;
  int cursorB_y;
  int cursorB_direction;
};

CursorB cursorb = { 9, 138, 1};

//////////////////////////////////////////////////////////////////////////

void drawBattle() {
  //////////////////////////////////////////////////////////////////////////////
  ///////////////////////////////Palette////////////////////////////////////////
  //////////////////////////////////////////////////////////////////////////////
  palette[0] = 0;            palette[8] = BEIGE;
  palette[1] = BLACK;        palette[9] = GREEN;
  palette[2] = BLUE;         palette[a] = DARKGREY;
  palette[3] = BROWN;        palette[b] = LIGHTGREY;
  palette[4] = DARKGREEN;    palette[c] = YELLOW;
  palette[5] = GREY;         palette[d] = PURPLE;
  palette[6] = PINK;         palette[e] = WHITE;
  palette[7] = RED;          palette[f] = ORANGE;
  ////////////////////////////////////////////////////////////////////////////////////////////////////////////
  ////////////////////////////////////////////////////////////////////////////////////////////////////////////

  Rect rectC {24, 138, 33, 7};
  Rect rectD {24, 164, 22, 7};
  Rect rectE {24, 190, 47, 7};
  Rect rectF {24, 216, 23, 7};
  Rect rectG {cursorb.cursorB_x, cursorb.cursorB_y, 32, 32};
  ////////////////////////////////////////////////////////////////////////////////////////////////////////////
  ////////////////////////////////////////////////////////////////////////////////////////////////////////////
  tft.fillScreen(BLACK);
  tft.fillRect(0, 30, 320, 50, WHITE);  ////// draws a back grounds stripe for the monsters to sit on the length nof the screen
  tft.writeRectNBPP(143, 50, 34, 24, 4, cavespider, palette);
  tft.drawRoundRect(40, 82, 240, 40, 4, WHITE);
  tft.fillRoundRect(41, 83, 237, 36, 4, BLUE);
  tft.setCursor(90, 94);
  tft.setTextColor(WHITE);
  tft.setTextSize(2);
  tft.println("Cave spider");
  tft.fillRoundRect(10, 130, 119, 106, 4, WHITE);
  tft.fillRoundRect(14, 133, 111, 100, 4, BLUE);
  tft.setCursor(24, 138);
  tft.setTextColor(WHITE);
  tft.setTextSize(2);
  tft.println("Attack");
  tft.setCursor(24, 164);
  tft.setTextColor(WHITE);
  tft.setTextSize(2);
  tft.println("Item");
  tft.setCursor(24, 190);
  tft.setTextColor(WHITE);
  tft.setTextSize(2);
  tft.println("Weirding");
  tft.setCursor(24, 216);
  tft.setTextColor(WHITE);
  tft.setTextSize(2);
  tft.println("Flee");
  ///////////////////////////////////////////////////////////////////////////////
  ///////////////////////////////////////////////////////////////////////////////
  int y1 = ss1.analogRead(2);
  int x1 = ss1.analogRead(3);
  ///////////////////////////////////////////////////////////////////////////////
  ////////////////////////////Up/////////////////////////////////////////////////
  ///////////////////////////////////////////////////////////////////////////////
  if (x1 > 600 && last_x < 600) {
    tft.writeRectNBPP(cursorb.cursorB_x, cursorb.cursorB_y, 32, 32, 4, cursor3, palette);
    cursorb.cursorB_y -= 26;
  }
  if (cursorb.cursorB_y <= 136) {
    cursorb.cursorB_y = 136;
  }

  //////////////////////////////////////////////////////////////////////////////
  ///////////////////////////////Down///////////////////////////////////////////
  //////////////////////////////////////////////////////////////////////////////
  if (x1 < 400 && last_x > 400) {
    tft.writeRectNBPP(cursorb.cursorB_x, cursorb.cursorB_y, 32, 32, 4, cursor3, palette);
    cursorb.cursorB_y += 26;
  }
  if (cursorb.cursorB_y >= 240) {
    cursorb.cursorB_y = 240;
  }

  last_x = x1;
  ///////////////////////////////////////////////////////////////////////////////////////////////////////////////
  ///////////////////////////////////////////////////////////////////////////////////////////////////////////////
  if (cursorb.cursorB_direction == 1) {
    tft.writeRectNBPP(cursorb.cursorB_x, cursorb.cursorB_y, 32, 32, 4, cursor3, palette);
  }
  ///////////////////////////////////////////////////////////////////////////////////////////////////////////////
  ///////////////////////////////////////////////////////////////////////////////////////////////////////////////
  if (!digitalRead(IRQ_PIN2)) {
    uint32_t buttons = ss2.digitalReadBulk(button_mask2);
    ///////////////////////////////////////////////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////////////////////////////////////////////

    if ((! (buttons & (1 << BUTTON_X)) && tft.collideRectRect( rectC.x, rectC.y, rectC.width, rectC.height, rectG.x, rectG.y, rectG.width, rectG.height)))
    {
      tft.fillScreen(GREEN);
    }
    else  if ((! (buttons & (1 << BUTTON_X)) && tft.collideRectRect( rectD.x, rectD.y, rectD.width, rectD.height, rectG.x, rectG.y, rectG.width, rectG.height)))
    {
      state = STATE_Item_list_bat;
    }
    else  if ((! (buttons & (1 << BUTTON_X)) && tft.collideRectRect( rectE.x, rectE.y, rectE.width, rectE.height, rectG.x, rectG.y, rectG.width, rectG.height)))
    {
      tft.fillScreen(PURPLE);
    }
    else  if ((! (buttons & (1 << BUTTON_X)) && tft.collideRectRect( rectF.x, rectF.y, rectF.width, rectF.height, rectG.x, rectG.y, rectG.width, rectG.height)))
    {
      state = STATE_Player;
    }
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////
  }
};
/////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////
void ItemlistBat() {
  tft.fillRoundRect(140, 0, 160, 240, 4, WHITE);
  tft.fillRoundRect(145, 4, 150, 232, 4, BLUE);
  printInventory();
  if (!digitalRead(IRQ_PIN2)) {
    uint32_t buttons = ss2.digitalReadBulk(button_mask2);
    if (! (buttons & (1 << BUTTON_A))) {
      state = STATE_Battle;
    }
  }
}

#endif
