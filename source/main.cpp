/*
Virtual Functions
(c) 2016
Author: David Erbelding
Written under the supervision of David I. Schwartz, Ph.D., and
supported by a professional development seed grant from the B. Thomas
Golisano College of Computing & Information Sciences
(https://www.rit.edu/gccis) at the Rochester Institute of Technology.
This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or (at
your option) any later version.
This program is distributed in the hope that it will be useful, but
WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
General Public License for more details.
You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

// Include iostream for output during the program.
#include <iostream>
using namespace std;

// These classes all inherit from the character class.
#include "../header/fighter.h"
#include "../header/ranger.h"
#include "../header/wizard.h"
#include "../header/necromancer.h"

int main() 
{
    // Create a fighter, ranger, and wizard at level 5
    int level = 5;

    // Print out each character's stats.

    // Virtual functions means that print stats can be defined differently for each
    Fighter fighter = Fighter(level);
    fighter.PrintClass();
    fighter.PrintStats();
    cout << endl;

    // We can't do:
    // Character character = Fighter(level);
    // because Character has no definition for PrintClass
    // Why can't use the Fighter definition?

    // Object slicing
    // Object slicing occurs whenever an object is stored as a parent type.
    // It "slices" out any of the child objects information, and stores it only as the parent type.

    // We can get around this by using pointers instead:
    Character * rangerPointer = new Ranger(level);  // This is where the real benefit of virtual functions shows up.
    rangerPointer->PrintClass();                    // We can create a pointer of type character, and it doesn't matter
    rangerPointer->PrintStats();                    // what type it actually is, it will use the correct definition.
    // delete pointer use.
    delete rangerPointer;
    cout << endl;

    Wizard wizard = Wizard(level);                  // The object also doesn't need to have been allocated with new.
    Character * wizardPointer = &wizard;            // A pointer to the base type is allowed.
    wizardPointer->PrintClass();
    wizardPointer->PrintStats();
    // This pointer doesn't need to be deleted since
    // it points to an object on the stack.
    cout << endl;


    Wizard necromancer = Necromancer(level);        // Because wizard defines PrintClass, this object can be sliced.
    necromancer.PrintClass();                       // Then, when we print call PrintClass, the object is treated as a wizard.
    necromancer.PrintStats();
    cout << endl;

    Wizard * w = new Necromancer(level);            // Of course, if you don't want your object to be sliced
    w->PrintClass();                                // The problem is solved by using a pointer again.
    w->PrintStats();                                // The pointer could also have been of type Character, and it would do the same thing.
    delete w; // cleanup pointer
    cout << endl;


    cin.get();  // wait for user to press enter.
    return 0;   // End Program.
}