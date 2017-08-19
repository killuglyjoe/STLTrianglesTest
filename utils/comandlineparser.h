#ifndef COMANDLINEPARSER_H
#define COMANDLINEPARSER_H

#include <string>
#include <vector>

class ComandLineParser
{
public:
    ComandLineParser(int &argc, char **argv);

    std::string stlFilePath() const;
    std::string writePath() const;

protected:
    const std::vector<std::string> &argsList() const;
private:
    std::vector<std::string> m_argsList;

};

#endif // COMANDLINEPARSER_H
