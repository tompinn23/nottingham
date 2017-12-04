/* Main Entry Point */
#include <iostream>
#include <algorithm>
#include <fstream>
#include "driver/driver.h"
#include "driver/args.hxx"
#include "driver/rang.hpp"
#include "version.h"
using namespace llvm;
using namespace std;
using namespace Ni;



int main(int argc, char** argv)
{
	args::ArgumentParser argParser("Nilang Compiler");
	args::HelpFlag help(argParser, "help", "Display this help menu", {'h', "help"});
	args::Positional<std::string> file(argParser, "file", "Input File");
	try
	{
		argParser.ParseCLI(argc, argv);
	}
	catch(args::Help)
	{
		std::cout << argParser;
		return 0;
	}
	catch (args::ParseError e)
    {
        std::cerr << e.what() << std::endl;
        std::cerr << argParser;
        return 1;
    }
    catch (args::ValidationError e)
    {
        std::cerr << e.what() << std::endl;
        std::cerr << argParser;
        return 1;
	}
	if(file.Get().empty())
	{
		std::cerr << rang::style::bold << rang::fg::red << "error: " << rang::style::reset << "no input files" << std::endl;
		return 1;
	}
	ifstream* ifs = new ifstream();
	Driver drive;
	ifs->open(file.Get(), ifstream::in);
	if(ifs->fail())
	{
		std::cerr << rang::style::bold << rang::fg::red << "error: " << rang::style::reset << "failed to find the source file" << std::endl;
		delete ifs;
		return 1;
	}
	drive.SwitchStream(ifs);
	int i = drive.parse();
	drive.DumpModule();
	delete ifs;
	return i;
}
