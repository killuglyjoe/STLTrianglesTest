#include "comandlineparser.h"

/**
 * @brief Примитивный парсер аргументов
 * @param argc
 * @param argv
 */
ComandLineParser::ComandLineParser(int &argc, char **argv)
{
    for (int i=1; i < argc; ++i)
        m_argsList.push_back(std::string(argv[i]));
}
/**
 * @brief ComandLineParser::argsList
 * @return
 */
const std::vector<std::string> &ComandLineParser::argsList() const
{
    return m_argsList;
}
/**
 * @brief ComandLineParser::stlFilePath
 * @return
 */
std::string ComandLineParser::stlFilePath() const
{
    std::string path("");
    if(argsList().size())
        path = argsList().at(0);

    return path;
}
/**
 * @brief ComandLineParser::writePath
 * @return
 */
std::string ComandLineParser::writePath() const
{
    std::string path("");
    if(argsList().size() > 1)
        path = argsList().at(1);

    return path;
}
