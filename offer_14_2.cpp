#include <iostream>
#include <math.h>

class Solution 
{
public:
    int cuttingRope(int n)
    {
        if (n < 2)
        {
            return 0;
        }

        if (n == 2)
        {
            return 1;
        }

        if (n == 3)
        {
            return 2;
        }


        int timesOfThree = n / 3;

        if (n - timesOfThree * 3 == 1)
        {
            timesOfThree -= 1;
        }

        int leftTwo{ n - timesOfThree * 3 };

        leftTwo = leftTwo > 0 ? leftTwo : 1;

        return static_cast<int>(my_pow(3, timesOfThree) * leftTwo % 1000000007);
    }

private:
    long long my_pow(int n, int x)
    {
        long long ret_val{ 1 };
        long long long_long_n{ n };

        while (x > 0)
        {
            if (x % 2)
            {
                ret_val = (ret_val * long_long_n) % 1000000007;
            }

            long_long_n = long_long_n * long_long_n % 1000000007;
            x /= 2;
        }

        return ret_val;
    }

};