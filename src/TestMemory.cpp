/*     This file is part of Test65.

    Test65 is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    Test65 is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with Test65.  If not, see <http://www.gnu.org/licenses/>.
*/

// This file deals with the testing of the intel hex format

#include <iostream>
#include <wx/string.h>
#include "testMemory.h"


using namespace std;


#include "../../lib65/include/memory.h"

bool setBitPattern(byte data)
{
    bool success=true;
    Memory *mem;
    int addr;
    for(addr=0xFFFF;addr>0;addr--)
    {
        mem->write(addr,data);
    }

    for(addr=0;addr<0x10000;addr++)
    {
        byte got=mem->read(addr);
        if(got!=data)
        {
            cout<<"Failed setBitPattern("<<data<<") at "<< addr<< " with "<<(int)got <<endl;
            success=false;
            break;
        }
    }

    if (success)
        cout<<"Passed setBitPattern("<<data<<")"<<endl;
    return success;
}

bool testMemory()
{
    bool rv=setBitPattern(0xA5);

    return rv;
}
