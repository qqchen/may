#include "utils.h"
#include <sstream>

namespace may {

void splitString(const std::string& src, char delim, std::vector<std::string>& dst)
{
    std::stringstream ss(src);
    std::string item;

    while (std::getline(ss, item, delim))
    {
        dst.push_back(item);
    }
}

bool toInt(const std::string& src, int& digit)
{
    digit = 0;
    std::stringstream ss(src);
    ss >> digit;
    return true;
}

}
