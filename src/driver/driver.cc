/*
 * =====================================================================================
 *
 *       Filename:  driver.cc
 *
 *    Description:  The main 'driving' class. Starts the parser and lexer
 *
 *        Version:  1.0
 *        Created:  13/11/17 21:30:57
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Tom Pinnock (tompinn23), 
 *   Organization:  ni-lang
 *
 * =====================================================================================
 */

#include <stdlib.h>
#include <sstream>


#include "driver/driver.h"
#include "llvm/IR/LLVMContext.h"

using ::llvm::LLVMContext;
using namespace Ni;

static LLVMContext llvmContext;

Driver::Driver() : lexer(*this), visitor(new Module("testing", llvmContext)), parser(lexer, visitor, *this)
{

}

Driver::~Driver()
{
	
}

void Driver::AddToList(ASTNode *ptr)
{
	ast.push_back(ptr);
}

int Driver::parse() {
	return parser.parse();
}

void Driver::SwitchStream(std::istream *is) {
	//TODO: Clear ast when stream switched
	lexer.switch_streams(is);
}


