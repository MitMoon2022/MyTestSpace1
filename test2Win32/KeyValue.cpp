
#include "KeyValue.h"
#include "stdafx.h"
#include <fstream>
#include <iterator>
#include <locale>
#include <algorithm>
#include <iterator>
#include <iostream>
#include <sstream>

// @Class to decode Key-Value data pattern
// eg.:
// LN1=8K3
// LN2=4f3
//
// PAN=DGEH091251#22:50:17_08.03.17;LS02#11:08:26_09.03.17;PMA05
// PAN=DGEH091252#22:38:35_08.03.17;LS02#13:22:32_09.03.17;PMA05
// PAN=DGEH091307#22:21:06_08.03.17;LS02#12:49:13_09.03.17;PMA05
//
// or
// JH10, Z20080H2013W002, Z20080h2013W002
// JH10-S0, Z20080H2013W002, Z20080h2013W002
//
// or
// GZ10=QCS10U
// GZ10-S0=QCS10U
CKeyValue::CKeyValue(void)
{
    //cout<<"construct\n";
}

CKeyValue::~CKeyValue(void)
{
}

std::string & CKeyValue::ltrim(std::string & str)
{
    auto it2 =  std::find_if(str.begin(), str.end(), [](char ch)
                             {
                                 return !std::isspace(ch, std::locale::classic());
                             });
    str.erase(str.begin(), it2);
    return str;
}

std::string & CKeyValue::rtrim(std::string & str)
{
    auto it1 =  std::find_if(str.rbegin(), str.rend(), [](char ch)
                             {
                                 return !std::isspace(ch, std::locale::classic());
                             });
    str.erase(it1.base(), str.end());
    return str;
}

std::string & CKeyValue::trim(std::string & str)
{
    return ltrim(rtrim(str));
}

// Tokenizer file content into vector of strings token
//
std::vector<std::string> CKeyValue::splitfile(const std::string& strFileName, char chSeparator)
{
    std::vector<std::string> vecLine;

    std::ifstream inFile(strFileName);

    if (inFile) // File open success
    {
        std::string strContents((std::istreambuf_iterator<char>(inFile)),
                                std::istreambuf_iterator<char>());
        //
        vecLine = split(strContents, '\n');
    }

    //
    return vecLine;
}

// Tokenizer string content into vector of strings token
//
std::vector<std::string> CKeyValue::split(const std::vector<std::string>& vecLine, char chSeparator)
{
    std::vector<std::string> vecOut;
    std::vector<std::string> vecToken;

    for (auto it = vecLine.begin();
         it != vecLine.end();
         ++it)
    {
        if (!it->empty()) // process non-empty line
        {
            vecToken = split(*it, chSeparator);
            std::copy(vecToken.begin(), vecToken.end(), std::back_inserter(vecOut));
        }
    }

    return vecOut;
}

// Split vectors of string into Key-Value Pair
//
std::vector<myKeyValPair> CKeyValue::splitKeyValPair(const std::vector<std::string>& vecLine, char chSeparator)
{
    std::vector<myKeyValPair> vecKeyValPair;
    std::vector<std::string>  vecToken;

    for (auto it = vecLine.begin();
         it != vecLine.end();
         ++it)
    {
        if (!it->empty()) // process non-empty line
        {
            vecToken = split(*it, chSeparator, true);
            if (vecToken.size() == 2)  // ignore Non pair token
            {
                vecKeyValPair.push_back(std::make_pair(vecToken[0], vecToken[1]));
            }
        }
    }

    return vecKeyValPair;
}

//
// Get Value from vector of Key-Value Pair given begin and end iterator
//
std::vector<myKeyValPair>::iterator CKeyValue::getKeyVal(const std::vector<myKeyValPair>::iterator& itBegin,
                                                         const std::vector<myKeyValPair>::iterator& itEnd,
                                                         const std::string& strKeyName, std::string &strValue)
{
    for (auto it = itBegin;
         it != itEnd;
         ++it)
    {
        if (it->first == strKeyName)
        {
            strValue = it->second;
            return it;
        }
    }

    return itEnd;
}

// Get Value from vector of Key-Value Pair
//
bool CKeyValue::getKeyVal(const std::vector<myKeyValPair>& vecKeyValPair, const std::string& strKeyName, std::string &strValue)
{
    for (auto it = vecKeyValPair.begin();
         it != vecKeyValPair.end();
         ++it)
    {
        if (it->first == strKeyName)
        {
            strValue = it->second;
            return true;
        }
    }

    return false;
}

// Find a Value from vector of Key-Value Pair even if there is multiple same key
//
bool CKeyValue::isValueExist(std::vector<myKeyValPair>& vecKeyValPair, const std::string& strKeyName, const std::string &strTargetValue)
{
    std::string strValue;
    auto        it = vecKeyValPair.begin();

    while (it != vecKeyValPair.end())
    {
        it = getKeyVal(it, vecKeyValPair.end(), strKeyName, strValue);
        //
        if (strValue.find(strTargetValue) != std::string::npos)
        {
            return true;
        }

        // Continue to iterate until a value is found
        if (it != vecKeyValPair.end())
        {
            it++;
        }
    }

    return false;
}

// Split string into list of token
//
std::vector<std::string> CKeyValue::split(const std::string& s, char chSeparator, bool bSinglePair)
{
    std::vector<std::string> strOut;

    std::string::size_type prev_pos = 0, pos = 0;

    while ((pos = s.find(chSeparator, pos)) != std::string::npos)
    {
        std::string substring(s.substr(prev_pos, pos - prev_pos));

        strOut.push_back(substring);

        prev_pos = ++pos;

        if (bSinglePair)
        {
            // Force to end
            pos = std::string::npos;
            break;
        }
    }

    strOut.push_back(s.substr(prev_pos, pos - prev_pos)); // Last word

    return strOut;

    //std::istringstream f("s");
    //std::string strToken;
    //while (std::getline(f, strToken, chSeparator)) {
    //    strOut.push_back(s);
    //}
}

// Split string separate by spaces (' ', '\t', '\n', '\r') into list of token
//
std::vector<std::string> CKeyValue::splitspaces(const std::string& s)
{
    std::istringstream iss(s);

    std::vector<std::string> vecToken;

    std::copy(std::istream_iterator<std::string>(iss),
              std::istream_iterator<std::string>(),
              back_inserter(vecToken));

    return vecToken;
}

// Split string by single token
// To replace GetNextData()
//
std::string CKeyValue::splitnext(std::string& s, char chSeparator)
{
    std::string strOut;

    std::string::size_type prev_pos = 0, pos = 0;

    if ((pos = s.find(chSeparator, pos)) != std::string::npos)
    {
        strOut = s.substr(prev_pos, pos - prev_pos);
        s.erase(0, ++pos);
    }
    else
    {
        strOut = s;
        // Trim any CR / LF
        rtrim(strOut);
        //
        s.clear();
    }

    return strOut;
}