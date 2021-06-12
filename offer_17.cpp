#include <iostream>
#include <vector>
#include <string>

class Solution {
public:
    std::vector<int> printNumbers(int n) 
    {
        std::vector<int> v;
        std::string s{ "1" };

        while (true)
        {
            if (s.length() == n + 1 && s[0] == '1')
            {
                break;
            }
            v.push_back(std::stoi(s));
            s = increaseOne(s);
        }

        return v;
    }
private:
    std::string increaseOne(std::string s)
    {
        int nowBit{ static_cast<int>(s.length()) - 1 };
        int bitAdd{ 1 };
        while (nowBit != -1)
        {
            if (s[nowBit] + bitAdd <= '9')
            {
                s[nowBit]++;
                break;
            }
            else
            {
                s[nowBit] = '0';
                bitAdd = 1;
                nowBit--;
            }
        }

        if (nowBit == -1)
        {
            s = '1' + s;
        }

        return s;
    }
};

int main()
{
    Solution solution = Solution();
    
    int n;
    std::vector<int> v;

    std::cin >> n;

    v = solution.printNumbers(n);

    for (int i : v)
    {
        std::cout << i << " ";
    }

    return 0;
}