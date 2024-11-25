#include "Utils.h"

namespace Utils {
    std::string Utils::fileToCString(std::string filepath) {
        std::ifstream f(filepath);
        std::string str;
        if (f) {
            std::ostringstream ss;
            ss << f.rdbuf();
            str = ss.str();
        }
        else {
            char buffer[1024];
            strerror_s(buffer, errno);
            std::cerr << buffer << std::endl;
        }
        return str;
    }
}