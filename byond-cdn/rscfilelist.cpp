/* RSC file lister By MrStonedOne
 * This takes a rsc file in stdin, and prints a dm file in stdout that contains a list referencing every file of that rsc (as a file)
 * 
 * This is mainly so you can directly #include an RSC file, and have byond actually send the resources over that are in it.
 * 
 * How to use:
 * 1) ./rscfilelist < resources.rsc > files.dm
 *
 * Exit codes are either 0 for success, or a number for the if check that failed: See below:
 * 
 * How to compile:
 * Requires visual c++ compiler 2012 or any linux compiler with c++11 support.
 * Windows:
 *	Normal: cl.exe /EHsc /Ox /Qpar rscfilelist.cpp
 *	Debug: cl.exe /EHsc /Zi rscfilelist.cpp
 * Linux:
 *	Normal: g++ -O3 -std=c++11 rscfilelist.cpp -o rscfilelist
 *	Debug: g++ -g -Og -std=c++11 rscfilelist.cpp -o rscfilelist
 * Any Compile errors most likely indicate lack of c++11 support. Google how to upgrade or nag coderbus for help..
 *
 *  Copyright (C) 2017, Kyle Spier-Swenson (MrStonedOne)
 *
 *  This program is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU Affero General Public License as
 *  published by the Free Software Foundation, either version 3 of the
 *  License, or (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU Affero General Public License for more details.
 *
 *  You should have received a copy of the GNU Affero General Public License
 *  along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 *  THE RESULTING OUTPUT IS COVERED UNDER THIS SAME LICENSE AS THE COMBINED WORK OF THE USER AND THE AUTHOR.
 */

// istream::ignore example
#include <iostream>     // std::cin, std::cout
#include <vector>
#include <string>
using namespace std;
#define MAX_FILE_PATH_LENGTH 4096


string sanitize(string str) {
	size_t index = 0;
	while (true) {
		/* Locate the substring to replace. */
		index = str.find("\\", index);
		if (index == std::string::npos) 
			break;

		/* Make the replacement. */
		str.replace(index, 1, "\\\\");

		/* Advance index forward so the next iteration doesn't pick it up as well. */
		index += 2;
	}
	return str;
}
	
int parse() {
	string filepath;
	unsigned int len;
	while(cin) {
		if (cin.fail())
			return 0;
		cin.ignore(18); //ignore bullshit meta data
		if (cin.fail())
			return 0;
		
		cin.read((char*)&len, 4); //get the file size
		if (cin.fail())
			return 3;

		if (cin.fail())
			return 4;
		getline(cin, filepath, '\0');  //get the filename
		filepath = sanitize(filepath);
		if (cin.fail())
			return 5;
		cout << "'" << filepath << "'," << endl;
		if (cin.fail())
			return 6;
		cin.ignore(len);
		if (cin.fail())
			return 7;
	}
	return 0;
}

int main() {
	
	cout << "var/files = list(";
	int rtn =  parse();
	cout << "\"\")";
}

