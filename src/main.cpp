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
#include <iostream>
#include "TestMemory.h"
#include "testIntelHex.h"

using namespace std;

int main()
{
    cout << "Console Simulator for the lib65 project" << endl
         << "Licenced under GPL v3, (c) 2012 Neil Stoker"<<endl;

    try
    {
        if (!testMemory())
        {
            cout<<"testMemory failed."<<endl;
            exit(EXIT_FAILURE);
        }



//        if (!testIntelHex())
//        {
//            cout<<"testIntelHex failed."<<endl;
//            exit(EXIT_FAILURE);
//        }
    }
    catch (int e)
    {
        cout<<"Exception "<< e<<" occurred."<<endl;
    }

    cout <<"test65 Exiting."<< endl;
    return 0;
}
