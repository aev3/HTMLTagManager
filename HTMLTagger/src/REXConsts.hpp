/*
 * REXConsts.hpp
 *
 *  Created on: May 26, 2014
 */

#ifndef REXCONSTS_HPP
#define REXCONSTS_HPP

#include <regex>
#include <string>

/**
 * <p>
 * Simple class that holds a collection of static strings and related
 * regular expressions.
 * </p>
 */
class REXConsts
{
public:
    REXConsts();
    /**
     * Empty string for replacements.
     */
    static const std::string EMPTY_STR; // = "";

    /**
     * Single space string for replacements.
     */
    static const std::string SPC_STR; // = " ";

    /**
     * The format string that is used to wrapped HTML markup.
     */
    static const std::string FMT_STR; //= "$1";

    /**
     * The single quote ['] string.
     */
    static const std::string SQ_STR; //= "'";

    /**
     * Regular expression to capture open tags like <code><h1><code>.
     */
    static const std::string OPEN_TAG_STR; // = "(<[a-zA-Z]+[[:digit:]]*>)"
    static const std::regex OPEN_TAG_REX; // (OPEN_TAG_STR);

    /**
     * Regular expression to capture close tags like '</h1>'.
     */
    static const std::string CLOSE_TAG_STR; // = "(<[/][a-zA-Z]+[[:digit:]]*>)"
    static const std::regex CLOSE_TAG_REX; // (CLOSE_TAG_STR);

    // Attribute values with double quotes
    static const std::string ATTR_VALS_DQ_STR;
    // = "(<[a-zA-Z]+[[:digit:]]*([[:space:]]{1,}([[:alnum:]]{1,}|[[:alnum:]]{1,}-[[:alnum:]]{1,})=\"(.*)\")+[[:space:]]*>)";
    static const std::regex ATTR_VALS_DQ_REX; // (ATTR_VALS_DQ_STR);

    // Attribute values with single quotes
    static const std::string ATTR_VALS_SQ_STR;
    // = "(<[a-zA-Z]+[[:digit:]]*([[:space:]]{1,}([[:alnum:]]{1,}|[[:alnum:]]{1,}-[[:alnum:]]{1,})='(.*)')+[[:space:]]*>)"
    static const std::regex ATTR_VALS_SQ_REX; // (ATTR_VALS_SQ_STR);

    // <!DOCTYPE html>
    static const std::string DOC_TYPE_STR; // = "(<!DOCTYPE (.*)>)";
    static const std::regex DOC_TYPE_REX; // (DOC_TYPE_STR);

    // father&apos;s word D&apos;Avignon
    static const std::string XML_ENTS_STR; // = "(&[[:alnum:]]{2,8};)";
    static const std::regex XML_ENTS_REX; // (XML_ENTS_STR);

    // EducationWorld&#174;
    static const std::string HTML_ENTS_STR; // = "(&#[[:alnum:]]{2,8};)";
    static const std::regex HTML_ENTS_REX; // (HTML_ENTS_STR);

    // <!-- xml comments -->
    static const std::string XML_COMMENTS_STR;
    // = "(<![-]{2}[[:space:]]+(.*)[[:space:]][-]{2}>)";
    static const std::regex XML_COMMENTS_REX; // (XML_COMMENTS_STR);

    /**
     * Regular expression to trim spaces at the beginning of a string.
     */
    static const std::string TRIM_BEG_STR; // = "(^[[:space:]]{1,})"
    static const std::regex TRIM_BEG_REX; //(TRIM_END_STR);

    /**
     * Regular expression to trim spaces at the end of a string.
     */
    static const std::string TRIM_END_STR; // = "([[:space:]]{1,}$)"
    static const std::regex TRIM_END_REX; //(TRIM_END_STR);

    // <br/>
    static const std::string BR_SIMP_STR; // = "(<p>|<br/>)");
    static const std::regex BR_SIMP_REX; // (BR_SIMP_STR);

    // <br />
    static const std::string BR_COMP_STR; // = ("(<p>|<br[[:space:]]{1,}[/]>)"));
    static const std::regex BR_COMP_REX; // (BR_COMP_STR);

    virtual
    ~REXConsts();

}; // class REXConsts

#endif /* REXCONSTS_HPP */
