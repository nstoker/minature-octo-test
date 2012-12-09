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
#include <vector>
#include <wx/string.h>
#include "testIntelHex.h"
#include "Memory.h"

using namespace std;

#include "../../lib65/include/readIntelHex.h"
#include "../../lib65/include/memory.h"

bool testIHfoe(wxString fname,address addr,vector<byte> data)
{
    cout<<"\tImporting '"<<fname.mb_str()<<"'. ";
    bool rv=true;
    readIntelHex rh;
    Memory mem; // TODO Check memory location(s) contain the correct data.

    if(rh.openFile(fname,&mem))
    {
        vector<byte>::iterator it=data.begin();
        for(vector<byte>::iterator it=data.begin();it!=data.end();++it)
        {
            if(*it!=mem.read(addr))
           {
               cout.setf(ios::hex,ios::basefield);
               cout.setf(ios::showbase);
               cout<<endl<<"\t\tAt "<< addr<< " expected "<< *it<<" got "<<mem.read(addr);
               rv=false;
           }

           addr++;
        }

    } else {
        cout<< "failed to load into memory.";
        rv=false;
    }
    return rv;
}

bool testIntelHex(void)
{
    readIntelHex rh;

    cout<<"Testing intelHex format file import"<<endl;

    bool rv;
    int myints[]={0x02u,0x33u,0x7Au};
    vector<byte> data(myints,myints+sizeof(myints)/sizeof(byte));

    wxString fName=wxT("/Users/ns/Projects/Sim65/minature-octo-test/data/test.hex");
    rv = testIHfoe(fName, 0x0030, data); //03 0030 00 02337A 1E
    if(rv)
        cout<<" successfully loaded"<<endl;

    return rv;
}
