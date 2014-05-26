/*
 * HTMLTagManagerApp.cpp
 *
 *  Created on: May 26, 2014
 */

#include "HTMLTagManager.hpp"
#include "REXConsts.hpp"

#include <string>
#include <iostream>

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
    const std::string buffer =
      "<p>The D&apos;Avignon fox.</p> <p>It <b>jumps</b> over the <i>lazy</i> dog.<br /></p>";

    std::cout << "BUFFER = '"
            <<  buffer
            << "'"
            << std::endl;

    /*  Initialize HTMLTagManager and call removeHtmlMarkup function */
    HTMLTagManager manager;

    std::cout << "REBUFF = '"
            << manager.removeHtmlMarkup(buffer)
            << "'"
            << std::endl;

    return(0);

}





