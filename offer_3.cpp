class Solution {
public:
    int findRepeatNumber(std::vector<int>& nums)
    {
        for (size_t i{ 0 }; i < nums.size(); i++)
        {
            if (nums[i] == nums[nums[i]] && nums[i] != i)
            {
                return nums[i];
            }
            else
            {
                swap(nums[i], nums[nums[i]]);
            }
        }

        return -1;
    }

private:
    void swap(int& a, int& b)
    {
        int tmp{ a };
        a = b;
        b = tmp;
    }
};