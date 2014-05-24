/*
* $Id: HTMLTagManager.cpp 147 2008-05-16 15:38:19Z avossberg $
*
* built from command line using vs12 console:
* cl /EHsc HTMLTagManager.cpp
*/

#include "HTMLTagManager.hpp"
#include "REXConsts.hpp"

#include <iostream>

#include <vector>

#include <regex>

#include <boost/lexical_cast.hpp>

//#include <boost/algorithm/string.hpp>

const std::string HTMLTagManager::BEG_HTML_IGN_STR =
	boost::lexical_cast<std::string>((char)17);
const std::string HTMLTagManager::END_HTML_IGN_STR =
	boost::lexical_cast<std::string>((char)16);


HTMLTagManager::HTMLTagManager()
{
	// No argument default ctor
}

HTMLTagManager::~HTMLTagManager()
{
}

/*
 * Function Description in interface.
 */
std::string HTMLTagManager::addHtmlMarkup(std::string& buff)
{
	std::string SPC_STR = " ";

	/**
	 * The format string that is used to wrapped HTML markup.
	 */
	std::string fmt_str = 
		SPC_STR + "<" + "$1" + ">" + SPC_STR;
		//SPC_STR + BEG_HTML_IGN_STR + "$1" + END_HTML_IGN_STR + SPC_STR;

	return buff;

} // void HTMLWrapper::addHtmlMarkup(std::string& buff)


/*
 * Function Description in interface.
 */
std::string HTMLTagManager::removeHtmlMarkup(std::string& buff)
{
    // <h1>
	buff = std::regex_replace(buff, REXConsts::OPEN_TAG_REX, REXConsts::EMPTY_STR);
    
    // </h1>
	buff = std::regex_replace(buff, REXConsts::CLOSE_TAG_REX, REXConsts::EMPTY_STR);

    // Attribute values with double quotes
	buff = std::regex_replace(buff, REXConsts::ATTR_VALS_DQ_REX, REXConsts::EMPTY_STR);
    
    // Attribute values with single quotes
	buff = std::regex_replace(buff, REXConsts::ATTR_VALS_SQ_REX, REXConsts::EMPTY_STR);
    
    // <DOCTYPE html>
	buff = std::regex_replace(buff, REXConsts::DOC_TYPE_REX, REXConsts::EMPTY_STR);
    
	// father&apos;s word D&apos;Avignon
	buff = std::regex_replace(buff, REXConsts::XML_ENTS_REX, REXConsts::SQ_STR);
    
	// EducationWorld&#174;
	buff = std::regex_replace(buff, REXConsts::HTML_ENTS_REX, REXConsts::EMPTY_STR);
    
    // <!-- XML comments -->
	buff = std::regex_replace(buff, REXConsts::XML_COMMENTS_REX, REXConsts::EMPTY_STR);
    
	// <br/>
	buff = std::regex_replace(buff, REXConsts::BR_SIMP_REX, REXConsts::EMPTY_STR);
    
	// <br />
	buff = std::regex_replace(buff, REXConsts::BR_COMP_REX, REXConsts::EMPTY_STR);
    
	// Empty space at the beginning of buffer
	buff = std::regex_replace(buff, REXConsts::TRIM_BEG_REX, REXConsts::EMPTY_STR);
    
	// Empty space at the end of buffer
	buff = std::regex_replace(buff, REXConsts::TRIM_END_REX, REXConsts::EMPTY_STR);
    
	return buff;
    
} // void HTMLWrapper::removeHtmlMarkup(std::string& buff)
