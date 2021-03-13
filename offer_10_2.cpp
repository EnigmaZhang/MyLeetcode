#include<iostream>
#include<vector>

class Solution 
{
public:
    int numWays(int n) 
    {
        std::vector<long> fibs;

        int first{ 1 };
        int second{ 1 };

        if (n == 0)
        {
            return 1;
        }
        else if (n == 1)
        {
            return 1;
        }
        else
        {
            for (int i{ 2 }; i <= n; i++)
            {

                long tmp{ first + second };
                first = second;
                second = tmp > 1000000007 ? tmp % 1000000007 : tmp;
            }

            return second;
        }
    }
};

int main()
{
    Solution solution = Solution();
    std::cout << solution.numWays(100) << std::endl;

    return 0;
}