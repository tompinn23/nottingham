/* Main Entry Point */
#include <iostream>
#include <algorithm>
#include <fstream>
#include <string>
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
	args::Flag print(argParser,  "print",  "Print llvm ir to output",{'p', "print"});
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
	ifs->open(file.Get(), ifstream::in);
	if(ifs->fail())
	{
		std::cerr << rang::style::bold << rang::fg::red << "error: " << rang::style::reset << "failed to find the source file" << std::endl;
		delete ifs;
		return 1;
	}
	Driver drive;
	drive.SwitchStream(ifs);
	std::cout << rang::style::bold << rang::fg::green << "info: " << rang::style::reset << "parsing " << file.Get() << std::endl;
	int i = drive.parse();
	if(print)
		drive.DumpModule();
	delete ifs;
	return i;
}
