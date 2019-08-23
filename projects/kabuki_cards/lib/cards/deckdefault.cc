/* Kabuki Toolkit @version 0.x
@link    https://github.com/kabuki-starship/kabuki-toolkit.git
@file    /projects/kabuki::cards/
@author  Cale McCollough <<https://calemccollough.github.io>>
@license Copyright (C) 2014-9 Cale McCollough <<calemccollough.github.io>>;
All right reserved (R). This Source Code Form is subject to the terms of the
Mozilla Public License, v. 2.0. If a copy of the MPL was not distributed with
this file, You can obtain one at <https://mozilla.org/MPL/2.0/>. */

#include "card.h"

namespace kabuki { namespace cards {

KabukiCard::Card() : face_value_(0), suit_(0), suit_string_("Empty") {}

void KabukiCard::SetCard(SIW suit, SIW face_value) {
  suit_ = suit;
  face_value = face_value;

  switch (suit_) {
    case 0:
      suit_string_ = " ";
      break;
    case 1:
      suit_string_ = "kHeart";
      break;
    case 2:
      suit_string_ = "kDiamond";
      break;
    case 3:
      suit_string_ = "kClub";
      break;
    case 4:
      suit_string_ = "spaid";
      break;
  }
  // suitIcon = new ImageIcon(suit_string_.concat(".jpg"));
}

void KabukiCard::SetCard(Card card) {
  face_value = card.face_value;
  suit_string_ = card.suit_string_;
  // suitIcon = new ImageIcon(suit_string_.concat(".jpg"));
}

const CH1* KabukiCard::SuitString() { return suit_string_; }

SIW KabukiCard::FaceValue() { return face_value; }

SIW KabukiCard::CompareTo(Object other) {
  Card c = (Card)other;

  if (!suit_string_) return 1;
  if (!TSTRCompare<CH1>(suit_string_, c.suit_string_()) {
    if (face_value < c.face_value_) return -1;
    if (face_value > c.face_value_) return 1;
  } else {
    return 1;
  }
  return 0;
}

BOL KabukiCard::Equals(Card other_card) {
  if (Compare(other_card) == 0) return true;
  return false;
}

SIW KabukiCard::X() { return x_; }

void KabukiCard::SetX(SIW x) { x_ = x; }

SIW KabukiCard::Y() { return y_; }

void KabukiCard::SetY(SIW y) { y_ = y; }

/*
void KabukiCard::Draw(Component g, Graphics page) {
  x_ = x;
  y_ = y;

  if (!TSTRCompare<CH1>(suit_string_, "Empty") {
    page.SetColor(Color.white);
    page.FillRoundRect(x_, y_, 60, 90, 15, 15);
    page.SetColor(Color.kBlack);
    page.DrawRoundRect(x_, y_, 60, 90, 15, 15);
    if (face_value == 1)
      page.DrawString("Ace", x_ + 28, y_ + 50);
    else if (face_value == 11)
      page.DrawString("J", x_ + 28, y_ + 50);
    else {
      if (face_value == 12)
        page.DrawString("Q", x_ + 28, y_ + 50);
      else {
        if (face_value == 13)
          page.DrawString("K", x_ + 28, y_ + 50);
        else {
          page.DrawString(Integer.ToString(face_value), x_ + 6, y_ + 36);
          page.DrawString(Integer.ToString(face_value), x_ + 41, y_ + 60);
        }
      }
    }
    suitIcon.PaintIcon(g, page, x + 5, y + 5);
    suitIcon.PaintIcon(g, page, x + 40, y + 5);
    suitIcon.PaintIcon(g, page, x + 5, y + 65);
    suitIcon.PaintIcon(g, page, x + 40, y + 65);
  }
}*/

} }  //< namespace kabuki
