#include <iostream>

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

        int* products = new int[n + 1];

        products[0] = 0;
        products[1] = 1;
        products[2] = 2;
        products[3] = 3;

        for (int i = 4; i <= n; i++)
        {
            int max_product{ 0 };
            for (int j = 1; j <= i / 2; j++)
            {
                int product{ products[j] * products[i - j] };
                max_product = max_product > product ? max_product : product;
            }
            products[i] = max_product;
        }

        int ret_val{ products[n] };

        delete[] products;

        return ret_val;
    }

};