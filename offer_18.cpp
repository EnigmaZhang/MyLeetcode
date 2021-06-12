#include <iostream>
#include <vector>
#include <string>
#include <map>


class Solution {
public:
    bool isMatch(std::string s, std::string p) 
    {
        return isMatchCore(s, 0, p, 0);
    }
private:
    bool isMatchCore(const std::string& s, size_t sStartIndex, const std::string& p, size_t pStartIndex)
    {
        while (sStartIndex != s.length() || pStartIndex != p.length())
        {
            // std::cout << sStartIndex << ' ' << pStartIndex << std::endl;
            if (sStartIndex > s.length() || pStartIndex >= p.length())
            {
                return false;
            }

            if (p[pStartIndex + 1] == '*')
            {
                if (s[sStartIndex] != 0 && (s[sStartIndex] == p[pStartIndex] || p[pStartIndex] == '.'))
                {
                    return isMatchCore(s, sStartIndex + 1, p, pStartIndex) || isMatchCore(s, sStartIndex, p, pStartIndex + 2);
                }
                else
                {
                    return isMatchCore(s, sStartIndex, p, pStartIndex + 2);
                }

            }
            
            if (s[sStartIndex] != p[pStartIndex] && p[pStartIndex] != '.')
            {
                return false;
            }

            sStartIndex++;
            pStartIndex++;
        }

        return true;
    }
};

int main()
{
    Solution solution = Solution();

    std::string s, p;

    // std::cin >> s >> p;
    s = "aaa";
    p = "a*a";


    std::cout << solution.isMatch(s, p) << std::endl;

    return 0;
}