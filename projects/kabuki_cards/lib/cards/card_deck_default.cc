/* Kabuki Toolkit @version 0.x
@link    https://github.com/kabuki-starship/kabuki-toolkit.git
@file    /projects/kabuki_cards/lib/cards/deck_default.cc
@author  Cale McCollough <<https://calemccollough.github.io>>
@license Copyright (C) 2014-9 Cale McCollough <<calemccollough.github.io>>;
All right reserved (R). This Source Code Form is subject to the terms of the
Mozilla Public License, v. 2.0. If a copy of the MPL was not distributed with
this file, You can obtain one at <https://mozilla.org/MPL/2.0/>. */

#include "card.h"

namespace kabuki_cards {

KabukiCard::Card() {
  face_value = 0;
  suit = 0;
  suit_string = "Empty";
}

void KabukiCard::setCard(int_w newSuit, int_w newFace) {
  suit = newSuit;
  face_value = newFace;

  switch (suit) {
    case 0:
      suit_string = " ";
      break;
    case 1:
      suit_string = "heart";
      break;
    case 2:
      suit_string = "diamond";
      break;
    case 3:
      suit_string = "club";
      break;
    case 4:
      suit_string = "spaid";
      break;
  }
  suitIcon = new ImageIcon(suit_string.concat(".jpg"));
}

void KabukiCard::SetCard(Card cardTemp) {
  suit_string = cardTemp.suit_string();
  face_value = cardTemp.face_value();
  suit_string = cardTemp.suit_string();
  suitIcon = new ImageIcon(suit_string.concat(".jpg"));
}

AString KabukiCard::SuitString() { return suit_string; }

int_w KabukiCard::FaceValue() { return face_value; }

int_w KabukiCard::CompareTo(Object other) {
  Card c = (Card)other;

  if (this.suit_string() == null) return 1;
  if (this.suit_string().equals(c.suit_string())) {
    if (this.face_value < c.face_value) return -1;
    if (this.face_value > c.face_value) return 1;
  } else {
    return 1;
  }
  return 0;
}

boolean KabukiCard::Equals(Card compairCard) {
  if (compairCard.compareTo(this) == 0) return true;
  return false;
}

AString KabukiCard::ToString() {
  AString card_tring;

  if (face_value == 1)
    card_tring = ("Ace of " + suit_string + ", ");
  else if (face_value == 11)
    card_tring = ("Jack of " + suit_string + ", ");
  else if (face_value == 12)
    card_tring = ("Queen of " + suit_string + ", ");
  else if (face_value == 13)
    card_tring = ("King of " + suit_string + ", ");
  else if (face_value == 0)
    card_tring = ("Empty" + ", ");
  else
    card_tring = (face_value + " of " + suit_string + ", ");
  return card_tring;
}

int_w KabukiCard::xPos() { return xPos; }

void KabukiCard::SetX(int_w newX) { xPos = newX; }

int_w KabukiCard::yPos() { return yPos; }

void KabukiCard::setY(int_w newY) { yPos = newY; }

/*
void KabukiCard::draw(Component g, Graphics page) {
  xPos = x;
  yPos = y;

  if (!suit_string.equals("Empty")) {
    page.setColor(Color.white);
    page.fillRoundRect(xPos, yPos, 60, 90, 15, 15);
    page.setColor(Color.black);
    page.drawRoundRect(xPos, yPos, 60, 90, 15, 15);
    if (face_value == 1)
      page.drawString("Ace", xPos + 28, yPos + 50);
    else if (face_value == 11)
      page.drawString("J", xPos + 28, yPos + 50);
    else {
      if (face_value == 12)
        page.drawString("Q", xPos + 28, yPos + 50);
      else {
        if (face_value == 13)
          page.drawString("K", xPos + 28, yPos + 50);
        else {
          page.drawString(Integer.ToString(face_value), xPos + 6, yPos + 36);
          page.drawString(Integer.ToString(face_value), xPos + 41, yPos + 60);
        }
      }
    }
    suitIcon.paintIcon(g, page, x + 5, y + 5);
    suitIcon.paintIcon(g, page, x + 40, y + 5);
    suitIcon.paintIcon(g, page, x + 5, y + 65);
    suitIcon.paintIcon(g, page, x + 40, y + 65);
  }
}*/

}  // namespace kabuki_cards
