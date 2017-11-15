/* Main Entry Point */
#include <iostream>
#include "llvm/IR/Module.h"
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
	drive.SwitchStream(ifs);
	delete ifs;
	return drive.parse();
}
