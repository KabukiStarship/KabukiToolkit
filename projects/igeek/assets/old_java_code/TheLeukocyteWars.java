/* The Leukocyte Wars
@file       ~/TheLeukocyteWars.java
@date       June 2, 2014
@author  Cale McCollough <https://calemccollough.github.io>
@license Copyright (C) 2014-2019 Cale McCollough <cale@astartup.net>;
All right reserved (R). This Source Code Form is subject to the terms of the 
Mozilla Public License, v. 2.0. If a copy of the MPL was not distributed with 
this file, You can obtain one at https://mozilla.org/MPL/2.0/. */

package leukocytewars;

import javax.swing.*;

public class TheLeukocyteWars extends JApplet
{
    public TheLeukocyteWars ()
    {
        add (new LeukocyteWar ());
    }
    
    public static void main (String[] args)
    {
        JFrame window = new JFrame ("The Leukocyte Wars");
        window.setDefaultCloseOperation (JFrame.EXIT_ON_CLOSE);
        
        JScrollPane scrollableArea = new JScrollPane (new LeukocyteWar ());
        
        window.setContentPane (scrollableArea);
        
        window.pack ();
        window.setVisible (true);
    }
}
