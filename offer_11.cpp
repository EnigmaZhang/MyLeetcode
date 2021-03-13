#include <iostream>
#include <vector>

class Solution
{
public:
    int minArray(std::vector<int> &numbers)
    {
        int start{0}, end{static_cast<int>(numbers.size()) - 1};

        int mid;

        int result;

        if (numbers[start] < numbers[end] || numbers.size() == 1)
        {
            return numbers[0];
        }

        while (true)
        {
            if (end - start == 1)
            {
                result = numbers[end];
                break;
            }

            mid = start + (end - start) / 2;

            if (numbers[start] == numbers[end] && numbers[mid] == numbers[start])
            {
                int tmp{ numbers[start] };
                result = numbers[start];

                for (int i : numbers)
                {
                    if (i < tmp)
                    {
                        result = i;
                    }
                    else
                    {
                        tmp = i;
                    }
                }

                return result;
            }

            if (numbers[mid] >= numbers[start])
            {
                start = mid;
            }
            else if (numbers[mid] <= numbers[end])
            {
                end = mid;
            }
        }

        return result;
    }
};

int main()
{
    Solution solution = Solution();

    std::vector<int> test{ 1, 1, 1 };

    std::cout << solution.minArray(test) << std::endl;

    return 0;
}