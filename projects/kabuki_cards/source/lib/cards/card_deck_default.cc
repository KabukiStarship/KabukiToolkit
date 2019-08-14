/** Kabuki Toolkit @version 0.x
@link    https://github.com/kabuki-starship/kabuki-toolkit.git
@file    /projects/kabuki_cards/
@author  Cale McCollough <https://calemccollough.github.io>
@license Copyright (C) 2014-2019 Cale McCollough <http://calemccollough.github.io>;
All right reserved (R). This Source Code Form is subject to the terms of the 
Mozilla Public License, v. 2.0. If a copy of the MPL was not distributed with 
this file, You can obtain one at https://mozilla.org/MPL/2.0/. */

#include "card.h"

namespace kabuki {
namespace cards {

KabukiCard::Card ()
{
    faceValue=0;
    suit=0;
	suitstring="Empty";
}  
   
void KabukiCard::setCard( int_w newSuit,  int_w newFace)
{
    suit=newSuit;
    faceValue=newFace;

    switch (suit)
    {
        case 0:
        suitstring = " ";
        break;
        case 1:
        suitstring = "heart";
        break;
        case 2:
        suitstring = "diamond";
        break;			
        case 3:
        suitstring = "club";			
        break;
        case 4:
        suitstring = "spaid";			
        break;
    }
    suitIcon = new ImageIcon (suitstring.concat(".jpg"));
}
   
void KabukiCard::setCard(Card cardTemp)
{
    suitstring = cardTemp.suitstring();
    faceValue = cardTemp.faceValue();
    suitstring= cardTemp.suitstring();
    suitIcon = new ImageIcon (suitstring.concat(".jpg"));
}
	
string KabukiCard::suitstring()
{
    return suitstring;
}
   
 int_w KabukiCard::faceValue()
{
    return faceValue;
}
   
 int_w KabukiCard::compareTo(Object other)
{
    Card c = (Card)other;
         
    if (this.suitstring() == null)
        return 1;
    if (this.suitstring().equals(c.suitstring()))
    {
        if (this.faceValue < c.faceValue)
        return -1;
        if (this.faceValue > c.faceValue)
        return 1;
    }
    else
    {
        return 1;
    }
    return 0;
}
   
boolean KabukiCard::equals (Card compairCard)
{
    if (compairCard.compareTo(this) == 0)
        return true;
    return false;
}
	
string KabukiCard::tostring()
{ 
    string cardstring;

	if (faceValue == 1)
		cardstring = ("Ace of " + suitstring + ", ");
	else
		if (faceValue == 11)
        cardstring = ("Jack of " + suitstring + ", ");
		else
			if (faceValue == 12)
   			cardstring = ("Queen of " + suitstring + ", ");
			else
				if (faceValue == 13)
					cardstring = ("King of " +suitstring + ", ");
			else
				if (faceValue == 0)
					cardstring = ("Empty" + ", ");
				else
				    cardstring = (faceValue + " of " + suitstring + ", ");
    return cardstring;
}
   
int_w KabukiCard::xPos()
{ return xPos; }
   
void KabukiCard::setX(int_w newX)
{ xPos = newX; }
   
int_w KabukiCard::yPos()
{ return yPos; }
   
void KabukiCard::setY(int_w newY)
{ yPos = newY; }
   
void KabukiCard::draw(Component g, Graphics page)
{  
    xPos = x;
    yPos = y;
      
    if (!suitstring.equals("Empty"))
    {
        page.setColor (Color.white);
        page.fillRoundRect (xPos,yPos, 60, 90, 15, 15);
        page.setColor (Color.black);
        page.drawRoundRect (xPos,yPos, 60, 90, 15, 15);
        if (faceValue==1)
        page.drawstring ("Ace", xPos+28, yPos+50);
        else
        if (faceValue==11)
            page.drawstring ("J", xPos+28, yPos+50);
        else
        {
            if (faceValue==12)
                page.drawstring ("Q", xPos+28, yPos+50);
            else
            {
                if (faceValue==13)
                    page.drawstring ("K", xPos+28, yPos+50);
                else
                {
                    page.drawstring (Integer.tostring(faceValue), xPos+6, yPos+36);
                    page.drawstring (Integer.tostring(faceValue), xPos+41, yPos+60);
                }
                }
        }
        suitIcon.paintIcon (g, page, x+5 , y+5 );
        suitIcon.paintIcon (g, page, x+40, y+5 );
        suitIcon.paintIcon (g, page, x+5 , y+65);
        suitIcon.paintIcon (g, page, x+40, y+65);
    }
}

} //< namespace cards
} //< namespace kabuki
