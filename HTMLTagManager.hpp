/*
* $Id: HTMLTagManager.hpp 42 2008-04-23 17:52:28Z avossberg $
*/

/*
* Standard Header Guard
*/
#ifndef HTML_TAG_MANAGER_HPP
#define HTML_TAG_MANAGER_HPP

#include <string>

class HTMLTagManager
{

private:

	const char* charBuffer;

	/**
	* Static const std:string(s)that will hold the 
	* ignore characters to be used around HTML markup.
	*/
	static const std::string BEG_HTML_IGN_STR; // = (char)17; 
	static const std::string END_HTML_IGN_STR; // = (char)16; 


	/**
	* Private data member of type std::string that will
	* hold the input buffer as marked up by the call to
	* the addHtmlMarkup function.
	*/
	std::string htmlMarkupBuffer;

	/**
	* Private data member of type char pointer that will
	* hold the marked up buffer after converting the std::string
	* buffer to a const char*.
	*/
	const char* checkedBuffer;

	/**
	* Private data member of type std::string that will
	* hold the full output buffer.
	*/
	std::string outputBuffer;


public:

	HTMLTagManager();

	~HTMLTagManager();

	/**
	* <p>
	* Private function that uses a series of regular expressions
	* to add HTML markup to the inputBuffer.
	* </p>
	*
	* @param buff - A std::string reference to the inputBuffer.
	*
	* @return void
	*/
	std::string addHtmlMarkup(std::string& buff);

	/**
	* <p>
	* Private function that uses a simple regular expression
	* to remove HTML markup to the modified inputBuffer.
	* </p>
	*
	* @param buff - A std::string reference to the modified inputBuffer.
	*
	* @return void
	*/
	std::string removeHtmlMarkup(std::string& buff);

	void setCharBuffer(const char* buff);

	std::string processCharBuffer(std::string& buff);

	const char* getCharBuffer() const;

}; // class HTMLTagManager


/**
* <p>
* Explicit inline function that sets the charBuffer data member.
* </p>
*
* @param buff - A const char pointer that refers to the char array
* containing the checkedBuffer
*
* @return void
*/
inline void HTMLTagManager::setCharBuffer(const char* buff)
{
	charBuffer = buff;
}

inline const char* HTMLTagManager::getCharBuffer() const
{
	return charBuffer;
}

inline std::string HTMLTagManager::processCharBuffer(std::string& buff)
{
	return removeHtmlMarkup(buff);
}

#endif // HTML_TAG_MANAGER_HPP
