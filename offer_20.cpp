#include <iostream>
#include <string>
#include <cctype>


class Solution {
public:
    bool isNumber(std::string s)
    {
        trim(s);
        size_t ePosition{ std::string::npos };
        for (size_t i{ 0 }; i < s.length(); i++)
        {
            if (s[i] == 'e' || s[i] == 'E')
            {
                ePosition = i;
                break;
            }
        }

        if (ePosition != std::string::npos)
        {
            return (isDecimal(s.substr(0, ePosition)) || isInteger(s.substr(0, ePosition))) && isInteger(s.substr(ePosition + 1));
        }
        else
        {
            return isDecimal(s) || isInteger(s);
        }
    }
private:
    void trim(std::string& s)
    {
        if (!s.empty())
        {
            s.erase(0, s.find_first_not_of(' '));
            s.erase(s.find_last_not_of(' ') + 1);
        }
    }

    bool isDecimal(const std::string& s)
    {
        size_t dotPosition{ s.find_first_of('.') };
        if (dotPosition == std::string::npos)
        {
            return false;
        }

        std::string beforeDot{ s.substr(0, dotPosition) };
        std::string afterDot(s.substr(dotPosition + 1));

        if (beforeDot[0] == '+' || beforeDot[0] == '-')
        {
            beforeDot = beforeDot.substr(1);
        }

        if (beforeDot.empty() && isAllNumbers(afterDot))
        {
            return true;
        }
        if (isAllNumbers(beforeDot) && afterDot.empty())
        {
            return true;
        }
        if (isAllNumbers(beforeDot) && isAllNumbers(afterDot))
        {
            return true;
        }

        return false;
    }

    bool isInteger(const std::string& s)
    {
        if (s.find_first_of('.') != std::string::npos)
        {
            return false;
        }

        if (s[0] == '+' || s[0] == '-')
        {
            return isAllNumbers(s.substr(1));
        }

        return isAllNumbers(s);
    }

    bool isAllNumbers(const std::string& s)
    {
        if (s.length() == 0)
        {
            return false;
        }

        for (char i : s)
        {
            if (!isdigit(i))
            {
                return false;
            }
        }

        return true;
    }
};

int main()
{
    Solution solution = Solution();

    std::string s;

    std::cin >> s;

    std::cout << solution.isNumber(s) << std::endl;

    return 0;
}