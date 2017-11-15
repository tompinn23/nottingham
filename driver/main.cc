/* Main Entry Point */
#include <iostream>
#include "llvm/IR/Module.h"
#include <algorithm>
#include <fstream>
#include "driver/driver.h"
using namespace llvm;
using namespace std;


int main(int argc, char** argsv)
{
	ifstream* ifs = new ifstream();
	std::unique_ptr<Ni::Driver> driver(new Ni::Driver());
	ifs->open("test.ni", ifstream::in);
	driver->SwitchStream(ifs);
	delete ifs;
	return driver->parse();
}
