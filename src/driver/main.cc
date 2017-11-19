/* Main Entry Point */
#include <iostream>
#include <algorithm>
#include <fstream>
#include "driver/driver.h"
using namespace llvm;
using namespace std;
using namespace Ni;

int main(int argc, char** argsv)
{
	ifstream* ifs = new ifstream();
	Driver drive;
	ifs->open("test.ni", ifstream::in);
	if(ifs->fail())
	{
		std::cerr << "Failed to find the source file" << std::endl;
	}
	drive.SwitchStream(ifs);
	int i = drive.parse();
	drive.DumpModule();
	delete ifs;
	return i;
}
