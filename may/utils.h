#ifndef UTILS_H
#define UTILS_H

#include <vector>
#include <string>

namespace may {

void splitString(const std::string& src, char delim, std::vector<std::string>& dst);
bool toInt(const std::string& src, int& digit);

}

#endif // UTILS_H
