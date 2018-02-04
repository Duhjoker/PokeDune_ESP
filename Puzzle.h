#ifndef _Puzzle_H_
#define _Puzzle_H_

#include "Variables.h"

///////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////

void detectside() {

  int block_x = 288;
  int block_y = 96;

  if (tft.collideRectRect(block_x, block_y, 16, 16, player.player_x, player.player_y, 16, 16))
  {
    if (tft.collideRectRect(block_x + 1, block_y, 14, 2, player.player_x, player.player_y, 16, 16)) {
      block_y -= 16;
    }

    if (tft.collideRectRect(block_x + 1, block_y + 14, 14, 2, player.player_x, player.player_y, 16, 16)) {
      block_y += 16;
    }

    if (tft.collideRectRect(block_x, block_y + 1, 2, 14, player.player_x, player.player_y, 16, 16)) {
      block_x -= 16;
    }

    if (tft.collideRectRect(block_x + 14, block_y + 1, 2, 14, player.player_x, player.player_y, 16, 16)) {
      block_x += 16;
    }
  }
}

#endif
