#include <iostream>

class Solution 
{
public:

    int movingCount(int m, int n, int k) 
    {
        reached = new bool[m * n];
        
        for (int i{ 0 }; i < m * n; i++)
        {
            reached[i] = false;
        }

        int ret_val{ movingCountCore(0, 0, k, m, n) };

        delete[] reached;

        return ret_val;
    }

private:
    bool* reached;
    int movingCountCore(int m, int n, int k, int m_max, int n_max)
    {
        if (m < 0 || m >= m_max || n < 0 || n >= n_max)
        {
            return 0;
        }

        if (reached[m * n_max + n])
        {
            return 0;
        }

        if (!allowingIn(m, n, k))
        {
            return 0;
        }

        reached[m * n_max + n] = true;

        int up{ movingCountCore(m - 1, n, k, m_max, n_max) };
        int down{ movingCountCore(m + 1, n, k, m_max, n_max) };
        int left{ movingCountCore(m, n - 1, k, m_max, n_max) };
        int right{ movingCountCore(m, n + 1, k, m_max, n_max) };

        return up + down + left + right + 1;
    }

    bool allowingIn(int m, int n, int k)
    {

        if (bitSum(m) + bitSum(n) > k)
        {
            return false;
        }
        return true;
    }

    int bitSum(int n)
    {
        int ret_val{ 0 };
        while (n)
        {
            ret_val += n % 10;
            n /= 10;
        }

        return ret_val;
    }
};

int main()
{
    Solution solution = Solution();
    int m, n, k;

    std::cin >> m >> n >> k;
    std::cout << solution.movingCount(m, n, k) << std::endl;

    return 0;
}