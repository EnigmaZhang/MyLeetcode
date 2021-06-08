#include <iostream>
#include <math.h>
#include <string>

class Solution {
public:
    int hammingWeight(uint32_t n) 
    {
        int count{ 0 };
        while (n)
        {
            if (n & 0X80000000)
            {
                count++;
            }
            n <<= 1;
        }

        return count;
    }
};

int main()
{
    Solution solution = Solution();

    std::string s;
    uint32_t n;

    std::cin >> s;

    n = static_cast<uint32_t>(std::stoi(s, 0, 2));

    std::cout << solution.hammingWeight(n) << std::endl;

    return 0;
}