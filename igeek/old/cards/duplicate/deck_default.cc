/** kabuki::cards
    @file       ~/source/kabuki/cards/impl/deck_default.cc
    @author  Cale McCollough <cale.mccollough@gmail.com>
    @license Copyright (C) 2017 Cale McCollough <calemccollough.github.io>;
             All right reserved (R). Licensed under the Apache License, Version 
             2.0 (the "License"); you may not use this file except in 
             compliance with the License. You may obtain a copy of the License 
             [here](http://www.apache.org/licenses/LICENSE-2.0). Unless 
             required by applicable law or agreed to in writing, software
             distributed under the License is distributed on an "AS IS" BASIS,
             WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or 
             implied. See the License for the specific language governing 
             permissions and limitations under the License.
*/

#include "../include/deck_default.h"
#include "../include/card.h"

DojoCard::Card ()
{
    faceValue=0;
    suit=0;
	suitString="Empty";
}  
   
void DojoCard::setCard( int_w newSuit,  int_w newFace)
{
    suit=newSuit;
    faceValue=newFace;

    switch (suit)
    {
        case 0:
        suitString = " ";
        break;
        case 1:
        suitString = "heart";
        break;
        case 2:
        suitString = "diamond";
        break;			
        case 3:
        suitString = "club";			
        break;
        case 4:
        suitString = "spaid";			
        break;
    }
    suitIcon = new ImageIcon (suitString.concat(".jpg"));
}
   
void DojoCard::setCard(Card cardTemp)
{
    suitString = cardTemp.suitString();
    faceValue = cardTemp.faceValue();
    suitString= cardTemp.suitString();
    suitIcon = new ImageIcon (suitString.concat(".jpg"));
}
	
String DojoCard::suitString()
{
    return suitString;
}
   
 int_w DojoCard::faceValue()
{
    return faceValue;
}
   
 int_w DojoCard::compareTo(Object other)
{
    Card c = (Card)other;
         
    if (this.suitString() == null)
        return 1;
    if (this.suitString().equals(c.suitString()))
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
   
boolean DojoCard::equals (Card compairCard)
{
    if (compairCard.compareTo(this) == 0)
        return true;
    return false;
}
	
String DojoCard::toString()
{ 
    String cardString;

	if (faceValue == 1)
		cardString = ("Ace of " + suitString + ", ");
	else
		if (faceValue == 11)
        cardString = ("Jack of " + suitString + ", ");
		else
			if (faceValue == 12)
   			cardString = ("Queen of " + suitString + ", ");
			else
				if (faceValue == 13)
					cardString = ("King of " +suitString + ", ");
			else
				if (faceValue == 0)
					cardString = ("Empty" + ", ");
				else
				    cardString = (faceValue + " of " + suitString + ", ");
    return cardString;
}
   
int_w DojoCard::xPos()
{ return xPos; }
   
void DojoCard::setX(int_w newX)
{ xPos = newX; }
   
int_w DojoCard::yPos()
{ return yPos; }
   
void DojoCard::setY(int_w newY)
{ yPos = newY; }
   
void DojoCard::draw(Component g, Graphics page)
{  
    xPos = x;
    yPos = y;
      
    if (!suitString.equals("Empty"))
    {
        page.setColor (Color.white);
        page.fillRoundRect (xPos,yPos, 60, 90, 15, 15);
        page.setColor (Color.black);
        page.drawRoundRect (xPos,yPos, 60, 90, 15, 15);
        if (faceValue==1)
        page.drawString ("Ace", xPos+28, yPos+50);
        else
        if (faceValue==11)
            page.drawString ("J", xPos+28, yPos+50);
        else
        {
            if (faceValue==12)
                page.drawString ("Q", xPos+28, yPos+50);
            else
            {
                if (faceValue==13)
                    page.drawString ("K", xPos+28, yPos+50);
                else
                {
                    page.drawString (Integer.toString(faceValue), xPos+6, yPos+36);
                    page.drawString (Integer.toString(faceValue), xPos+41, yPos+60);
                }
                }
        }
        suitIcon.paintIcon (g, page, x+5 , y+5 );
        suitIcon.paintIcon (g, page, x+40, y+5 );
        suitIcon.paintIcon (g, page, x+5 , y+65);
        suitIcon.paintIcon (g, page, x+40, y+65);
    }
}