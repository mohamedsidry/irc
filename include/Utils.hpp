#ifndef UTILS_HPP
#define UTILS_HPP

#include <string>


class Utils
{
    private:
        Utils();
        Utils(const Utils&);
        Utils& operator=(const Utils&);
        ~Utils();
    public:
        static bool isAllWhitespace(const std::string& str);
        static bool hasOnly(const std::string& src, const std::string& set);
        static bool startWith(const std::string& str, unsigned char c);
        static bool hasAtLeastOne(const std::string& src, unsigned char c);
        static bool hasWhitespace(const std::string& str);

};

#endif // UTILS_HPP

