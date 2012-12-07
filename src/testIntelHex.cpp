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
#include "testIntelHex.h"
#include "Memory.h"

#include "../../lib65/include/readIntelHex.h"

bool testIHfoe(wxString fname)
{
    std::cout<<"\tImporting '"<<fname.mb_str()<<"'. ";
    bool rv=false;
    readIntelHex rh;
    Memory *mem;

    if(rh.openFile(fname,mem))
    {
        std::cout<< "loaded ok";
        rv=true;
    } else {
        std::cout<< "FAILED.";
    }

    std::cout<<std::endl;
    return rv;
}

bool testIntelHex(void)
{
    readIntelHex rh;
    Memory *mem;
    std::cout<<"Testing intelHex format file import"<<std::endl;
    bool rv=true;
    rv = rv && testIHfoe(wxT("/Users/ns/Projects/Sim65/minature-octo-test/data/test.hex"));
    rv = rv && testIHfoe(wxT("/Users/ns/Projects/Sim65/minature-octo-test/data/test6502.hex"));
    return true; // Ok, we've failed
}
