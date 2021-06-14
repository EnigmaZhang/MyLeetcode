#include <iostream>
#include <string>
#include <deque>
#include <vector>
#include <set>

class Solution {
public:
    std::vector<std::string> permutation(std::string s)
    {
        std::vector<std::string> v;

        if (s.length() == 0)
        {
            return v;
        }

        permutationCore(s, v, 0);

        std::set<std::string> st{ v.begin(), v.end() };
        v.assign(st.begin(), st.end());

        return v;
    }
private:
    void permutationCore(std::string& s, std::vector<std::string>& v, size_t index)
    {
        if (index == s.length() - 1)
        {
            v.push_back(std::string{ s });
            return;
        }

        permutationCore(s, v, index + 1);
        for (size_t i{ index + 1 }; i < s.length(); i++)
        {
            char tmp{ s[index] };
            s[index] = s[i];
            s[i] = tmp;
            permutationCore(s, v, index + 1);
            tmp = s[index];
            s[index] = s[i];
            s[i] = tmp;
        }
    }
};

int main()
{
    Solution solution = Solution();
    std::vector<std::string> v;

    v = solution.permutation("aab");

    for (std::string s : v)
    {
        std::cout << s << std::endl;
    }

    return 0;
}