#include <iostream>
#include <limits>

class Solution 
{
public:
    double myPow(double x, int n) 
    {
        if (n == INT_MIN)
        {
            unsigned int exponent = static_cast<unsigned int>(-(INT_MIN + 1));
            return 1.0 / (powWithUnsignedExponent(x, exponent) * x);
        }

        unsigned int exponent = n >= 0 ? static_cast<unsigned int>(n) : static_cast<unsigned int>(-n);

        if (n >= 0)
        {
            return powWithUnsignedExponent(x, exponent);
        }
        else
        {
            return 1.0 / powWithUnsignedExponent(x, exponent);
        }
    }

private:
    double powWithUnsignedExponent(double x, unsigned int n)
    {
        double ret_val{ 1 };
        while (n)
        {
            if (n & 1)
            {
                ret_val *= x;
            }
            
            x = x * x;
            n >>= 1;
        }

        return ret_val;
    }
};

int main()
{
    Solution solution = Solution();
    
    double x;
    int n;

    std::cin >> x >> n;

    std::cout << solution.myPow(x, n) << std::endl;

    return 0;
}