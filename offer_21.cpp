#include <iostream>
#include <string>
#include <vector>

class Solution {
public:
    std::vector<int> exchange(std::vector<int>& nums)
    {
        if (nums.size() == 0)
        {
            return nums;
        }

        size_t indexBegin{ 0 };
        size_t indexEnd{ nums.size() - 1 };

        while (indexBegin < indexEnd)
        {
            while (indexBegin < indexEnd && nums[indexBegin] % 2 == 1)
            {
                indexBegin++;
            }

            while (indexBegin < indexEnd && nums[indexEnd] % 2 == 0)
            {
                indexEnd--;
            }

            if (indexBegin < indexEnd)
            {
                int tmp{ nums[indexBegin] };
                nums[indexBegin] = nums[indexEnd];
                nums[indexEnd] = tmp;
            }
        }

        return nums;
    }
};

int main()
{
    Solution solution = Solution();


    return 0;
}