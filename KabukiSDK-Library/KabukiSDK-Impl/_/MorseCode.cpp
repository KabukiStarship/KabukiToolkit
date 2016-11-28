/** Kabuki Software Development Kit
    @file    /.../KabukiSDK-Library/KabukiSDK-Impl/_Util/MorseCode.cpp
    @author  Cale McCollough <cale.mccollough@gmail.com>
    @license Copyright (C) 2016 [Cale McCollough](calemccollough.github.io)

                            All right reserved (R).

        Licensed under the Apache License, Version 2.0 (the "License"); you may
        not use this file except in compliance with the License. You may obtain
        a copy of the License at

        http://www.apache.org/licenses/LICENSE-2.0

        Unless required by applicable law or agreed to in writing, software
        distributed under the License is distributed on an "AS IS" BASIS,
        WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
        See the License for the specific language governing permissions and
        limitations under the License.
*/

#include "MorseCode.hpp"

namespace _Util {

const char* Encode (char Code)
{
    static const char* space = " "; //<

    static const char* cypher[] = {
        ".-.-.",        //< ASCII: NUL, Morse Code: End of message.
        0,              //< ASCII: SOH.
        "-.-.-",        //< ASCII: STX, Morse Code: Start copying.
        "-.-..-..",     //< ASCII: ETX, Morse Code: Going off the air ("clear").
        "...-.-",       //< ASCII: EOT, Morse Code: End of transmission.
        "-.--.",        //< ASCII: ENQ, Morse Code: Invite a specific station to transmit.
        "...-.",        //< ASCII: ACK, Morse Code: Understood.
        "...---...",    //< ASCII: BEL, Morse Code: SOS distress signal.
        "........",     //< ASCII: BS,  Morse Code: Prosign error.
        space,          //< ASCII: HT,  Morse Code: non-standard space.
        ".-.-",         //< ASCII: LF,  Morse Code: New Line
        "-...-",        //< ASCII: VT,  Morse Code: New paragraph.
        ".-.-.",        //< ASCII: FF,  Morse Code: New Page
        0,              //< ASCII: CR
        "-..---",       //< ASCII: SO,  Morse Code: Change to Wabun Mores code.
        ".--...",       //< ASCII: SI,  Morse Code: Non-standard return to Western Mores Code
        0,              //< ASCII: DLE
        0,              //< ASCII: DC1
        0,              //< ASCII: DC2
        0,              //< ASCII: DC3
        0,              //< ASCII: DC4
        0,              //< ASCII: NAK
        ".-...",        //< ASCII: SYN, Morse Code: AS, Wait.
        0,              //< ASCII: ETB
        0,              //< ASCII: CAN
        "-...-.-",      //< ASCII: EM,  Morse Code: Break/BRB.
        0,              //< ASCII: SUB
        0,              //< ASCII: ESC
        0,              //< ASCII: FS
        0,              //< ASCII: GS
        0,              //< ASCII: RS
        0,              //< ASCII: US
        space,          //< ASCII: ' '
        ".-..-.",       //< ASCII: '!'
        ".-..-.",       //< ASCII: '\"'
        0,              //< ASCII: '#'
        "..._.-..",     //< ASCII: '$'
        "....._..",     //< ASCII: '%'
        "._...",        //< ASCII: '&'
        ".----.",       //< ASCII: '\''
        "-.--.-",       //< ASCII: '('
        ".-..-.",       //< ASCII: ')', Nonstandard, inverse of '('
        0,              //< ASCII: '*'
        0,              //< ASCII: '+'
        "--..--",       //< ASCII: ','
        "-....-",       //< ASCII: '-'
        ".-.-.-",       //< ASCII: '.'
        "-..-.",        //< ASCII: '/'
        "-----",        //< ASCII: '0'
        ".---",         //< ASCII: '1'
        "..---",        //< ASCII: '2'
        "...--",        //< ASCII: '3'
        "....-",        //< ASCII: '4'
        ".....",        //< ASCII: '5'
        "-...",         //< ASCII: '6'
        "--...",        //< ASCII: '7'
        "---..",        //< ASCII: '8'
        "----.",        //< ASCII: '9'
        "---...",       //< ASCII: ':'
        0,              //< ASCII: ','
        0,              //< ASCII: '<'
        "-...-",        //< ASCII: '='
        0,              //< ASCII: '>'
        "..--..",       //< ASCII: '?'
        ".--.-.",       //< ASCII: '@'
        ".-",           //< ASCII: 'A'
        "-...",         //< ASCII: 'B'
        "-.-.",         //< ASCII: 'C'
        "-..",          //< ASCII: 'D'
        ".",            //< ASCII: 'E'
        "..-.",         //< ASCII: 'F'
        "--.",          //< ASCII: 'G'
        "....",         //< ASCII: 'H'
        "..",           //< ASCII: 'I'
        ".---",         //< ASCII: 'J'
        "-.-",          //< ASCII: 'K'
        ".-..",         //< ASCII: 'L'
        "--",           //< ASCII: 'M'
        "-.",           //< ASCII: 'N'
        "---",          //< ASCII: 'O'
        ".--.",         //< ASCII: 'P'
        "--.-",         //< ASCII: 'Q'
        ".-.",          //< ASCII: 'R'
        "...",          //< ASCII: 'S'
        "-",            //< ASCII: 'T'
        "..-",          //< ASCII: 'U'
        "...-",         //< ASCII: 'V'
        ".--",          //< ASCII: 'W'
        "-..-",         //< ASCII: 'X'
        "-.--",         //< ASCII: 'Y'
        "--.."          //< ASCII: 'Z'
    };

    if (Code < 0) return 0;
    if (Code >= 'a' && Code <= 'z') Code -= 'a' - 'A';   //< Covert from lowercase to upper case if need be.
    if (Code > 'Z')
    {
        switch (Code)
        {
          case -4: return ".-.-";   //< 132
          case -5: return ".--.-";  //< 133
          case -6: return ".--.-";  //< 134
          case -16: return "..-.."; //< 144
          case -37: return "--.--"; //< 165
          case -25: return "---.";  //< 153
          case -26: return "..--";  //< 154
          default:  return 0;
        }
    }
    return cypher[Code];
}

byte MorseCode::getState ()
{
    return 0;
}

const char* MorseCode::getState (byte Value)
{
    return 0;
}

const char* MorseCode::sub (I2P::Terminal& slot, int index, int Enq)
{
    switch (Index)
    {
        case 0: return I2P::NumMembers (0);
    }
    
    return Query ? Enquery ("MorseCode", "_Com"): InvalidIndex ();
}

}   //< namespace _Util
