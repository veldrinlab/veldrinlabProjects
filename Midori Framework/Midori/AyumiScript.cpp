/**
 * File contains definition of AyumiScript class.
 * @file    AyumiScript.cpp
 * @author  Szymon "Veldrin" Jab³oñski
 * @date    2011-07-10
 */

#include "AyumiScript.hpp"

using namespace std;

/**
 * Class default constructor. Create empty script object with no virtual machine.
 */
AyumiScript::AyumiScript()
{
	
}
	
/**
 * Class constructor with initialize parameters. Create script with global virtual machine.
 * @param	scriptFile is name of script file.
 */
AyumiScript::AyumiScript(const char* scriptFile)
{
	this->scriptFile = scriptFile;
	virtualMachine = VirtualMachine::getInstance()->getGlobalState();
}

/**
 * Class destructor, free allocated memory. Nothing to delete.
 */
AyumiScript::~AyumiScript()
{

}

/**
 * Method is used to execute script file. It calls lua_dofile function with defined virtual machine.
 */
void AyumiScript::executeScript()
{
	if(luaL_dofile(virtualMachine,scriptFile) != 0)
		cout << "Error running script: " << string(scriptFile) << endl;
	else
		cout << "Ran Lua Script: " << string(scriptFile) << endl;
}

/**
 * Accessor to virtual machine private memebr.
 * @return	pointer to script virtual machine.
 */
lua_State* AyumiScript::getVirtualMachine() const
{
	return virtualMachine;
}

/**
 * Setter for private script name member.
 * @param	name is script name.
 */
void AyumiScript::setScriptFile(const char* name)
{
	scriptFile = name;
}

/**
 * Setter for private virtual machine member.
 * @param	machine is pointer to new virtual machine.
*/
void AyumiScript::setVirtualMachine(lua_State* machine)
{
	virtualMachine = machine;
}
