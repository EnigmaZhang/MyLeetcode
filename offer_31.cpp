#include <iostream>
#include <stack>
#include <vector>

class Solution 
{
public:
    bool validateStackSequences(std::vector<int>& pushed, std::vector<int>& popped) 
    {
        if (pushed.empty() && popped.empty())
        {
            return true;
        }
        
        if (pushed.empty() || popped.empty())
        {
            return false;
        }

        std::stack<int> s;
        size_t pushIndex{ 0 };
        size_t popIndex{ 0 };

        while (true)
        {
            if (s.empty() || s.top() != popped[popIndex])
            {
                s.push(pushed[pushIndex]);
                pushIndex++;
            }
            else
            {
                s.pop();
                popIndex++;
            }
            if (pushIndex == pushed.size() && popIndex == popped.size())
            {
                return true;
            }
            else if (pushIndex == pushed.size() && popped[popIndex] != s.top())
            {
                return false;
            }
        }
    }
};

int main()
{
    Solution solution = Solution();

    std::vector<int> pushed{ 1,2,3,4,5 };
    std::vector<int> popped{ 4,5,3,2,1 };

    std::cout << solution.validateStackSequences(pushed, popped) << std::endl;

    return 0;
}