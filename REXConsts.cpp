//
//  REXConsts.cpp
//  htmltagger
//
//  Created by Arthur E. Vossberg III on 24-05-2014.
//  Copyright (c) 2014 Art Vossberg. All rights reserved.
//

#include "REXConsts.hpp"

/**
 * Empty string for replacements.
 */
const std::string REXConsts::EMPTY_STR = "";

/**
 * Single space string for replacements.
 */
const std::string REXConsts::SPC_STR = " ";

/**
 * The format string that is used to wrapped HTML markup.
 */
const std::string REXConsts::FMT_STR = "$1";

/**
 * The single quote ['] string.
 */
const std::string REXConsts::SQ_STR = "'";


const std::string REXConsts::TRIM_BEG_STR = "(^[[:space:]]{1,})";
const std::regex  REXConsts::TRIM_BEG_REX(TRIM_BEG_STR);

const std::string REXConsts::TRIM_END_STR = "([[:space:]]{1,}$)";
const std::regex  REXConsts::TRIM_END_REX(TRIM_END_STR);

// Attribute values with double quotes
const std::string REXConsts::ATTR_VALS_DQ_STR =
    "(<[a-zA-Z]+[[:digit:]]*([[:space:]]{1,}([[:alnum:]]{1,}|[[:alnum:]]{1,}-[[:alnum:]]{1,})=\"(.*)\")+[[:space:]]*>)";
const std::regex  REXConsts::ATTR_VALS_DQ_REX(ATTR_VALS_DQ_STR);

// Attribute values with single quotes
const std::string REXConsts::ATTR_VALS_SQ_STR =
    "(<[a-zA-Z]+[[:digit:]]*([[:space:]]{1,}([[:alnum:]]{1,}|[[:alnum:]]{1,}-[[:alnum:]]{1,})='(.*)')+[[:space:]]*>)";
const std::regex  REXConsts::ATTR_VALS_SQ_REX(ATTR_VALS_SQ_STR);

// <!DOCTYPE html>
const std::string REXConsts::DOC_TYPE_STR = "(<!DOCTYPE (.*)>)";
const std::regex  REXConsts::DOC_TYPE_REX(DOC_TYPE_STR);

// father&apos;s word D&apos;Avignon
const std::string REXConsts::XML_ENTS_STR = "(&[[:alnum:]]{2,8};)";
const std::regex  REXConsts::XML_ENTS_REX(XML_ENTS_STR);

// EducationWorld&#174;
const std::string REXConsts::HTML_ENTS_STR = "(&#[[:alnum:]]{2,8};)";
const std::regex  REXConsts::HTML_ENTS_REX(HTML_ENTS_STR);

// <!-- xml comments -->
const std::string REXConsts::XML_COMMENTS_STR =
    "(<![-]{2}[[:space:]]+(.*)[[:space:]][-]{2}>)";
const std::regex  REXConsts::XML_COMMENTS_REX(XML_COMMENTS_STR);

// <h1>
const std::string REXConsts::OPEN_TAG_STR = "(<[a-zA-Z]+[[:digit:]]*>)";
const std::regex  REXConsts::OPEN_TAG_REX(OPEN_TAG_STR);

// </h1>
const std::string REXConsts::CLOSE_TAG_STR = "(<[/][a-zA-Z]+[[:digit:]]*>)";
const std::regex  REXConsts::CLOSE_TAG_REX(CLOSE_TAG_STR);

// <br/>
const std::string REXConsts::BR_SIMP_STR = "(<p>|<br/>)";
const std::regex  REXConsts::BR_SIMP_REX(BR_SIMP_STR);

// <br />
const std::string REXConsts::BR_COMP_STR = "(<p>|<br[[:space:]]{1,}[/]>)";
const std::regex  REXConsts::BR_COMP_REX(BR_COMP_STR);

