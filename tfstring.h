#ifndef __TFSTRING_TFSTRING_H
#define __TFSTRING_TFSTRING_H

#include <string>
#include <vector>

namespace tf {

struct string {
    explicit string(std::string const& s) : _s(s) {}

    constexpr bool contains(std::string const& s) const noexcept
    {
        return _s.find(s) != std::string::npos;
    }

    constexpr bool startswith(std::string const& s) const noexcept
    {
        return _s.find(s) == 0;
    }

    constexpr bool endswith(std::string const& s) const noexcept
    {
        return _s.find(s) == _s.size() - s.size();
    }

    std::vector<std::string> split(char c) const noexcept
    {
        auto result = std::vector<std::string>{};
        auto substr = std::string{""};
        for (auto&& _c : _s) {
            if (_c == c) {
                result.emplace_back(substr);
                substr = "";
                continue;
            }
            substr += _c;
        }
        result.emplace_back(substr);
        return result;
    }

private:
    std::string const& _s;
};

}

#endif //__TFSTRING_TFSTRING_H
