/*
 * $Id: HTMLTagManager.cpp 147 2008-05-16 15:38:19Z avossberg $
 *
 * built from command line using vs12 console:
 * cl /EHsc HTMLTagManager.cpp
 */

#include "HTMLTagManager.hpp"

#include <string>

#include <iostream>

#include <regex>

/**
 * This is a wrapper for calling HTMLTagManager class to
 * parse a string.
 */
#ifdef linux
int main(int argc, char* argv[])
#elif defined __APPLE__
int main(int argc, char* argv[])
#else
int __cdecl main(int argc, char* argv[])
#endif
{
	/*
	 * Initialize HTMLTagManager and set the inputBuffer.
	 */
    HTMLTagManager manager;
    std::string str_buff =
    "<p>The D&apos;Avignon fox <b>jumps</b> over the <i>lazy</i> dog <br/>";
    
    std::string re_buff = manager.removeHtmlMarkup(str_buff);
    std::cout << "RE_BUFF = '" << re_buff << "'" << std::endl;

    return(0);

}

