//#pragma once

#include <vector>
#include <string>

typedef std::pair<std::string, std::string> myKeyValPair;

class CKeyValue
{
public:
    CKeyValue(void);
    ~CKeyValue(void);

    std::vector<std::string> splitspaces(const std::string& s);

    std::vector<std::string> split(const std::string& s, char separator, bool bSinglePair = false);
    std::vector<std::string> split(const std::vector<std::string>& vecLine, char chSeparator);

    std::vector<myKeyValPair> splitKeyValPair(const std::vector<std::string>& vecLine, char chSeparator);
    bool getKeyVal(const std::vector<myKeyValPair>& vecKeyValPair, const std::string& strKeyName, std::string &strValue);
    std::vector<myKeyValPair>::iterator getKeyVal(const std::vector<myKeyValPair>::iterator& itBegin,
                                                  const std::vector<myKeyValPair>::iterator& itEnd,
                                                  const std::string& strKeyName, std::string &strValue);
    bool isValueExist(std::vector<myKeyValPair>& vecKeyValPair, const std::string& strKeyName, const std::string& strTargetValue);

    std::vector<std::string> splitfile(const std::string& strFileName, char chSeparator);

    std::string splitnext(std::string& s, char chSeparator);

private:
    std::string & ltrim(std::string & str);
    std::string & rtrim(std::string & str);
    std::string & trim(std::string & str);

};
