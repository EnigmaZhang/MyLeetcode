#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>

class Solution {
public:
    std::vector<int> spiralOrder(std::vector<std::vector<int>>& matrix) 
    {
        if (matrix.size() == 0)
        {
            return std::vector<int>();
        }

        std::vector<int> nums;

        int rowNum{ static_cast<int>(matrix.size()) }, colNum{ static_cast<int>(matrix[0].size()) };
        int startIndex{ 0 };

        while (rowNum > startIndex * 2 && colNum > startIndex * 2)
        {
            circleInMatrix(matrix, nums, startIndex, rowNum, colNum);
            startIndex++;
        }

        return nums;
    }
private:
    void circleInMatrix(std::vector<std::vector<int>>& matrix, std::vector<int>& nums, int startIndex, int rowNum, int colNum)
    {
        for (int i{ startIndex }; i < colNum - startIndex; i++)
        {
            nums.push_back(matrix[startIndex][i]);
        }

        if (rowNum - startIndex * 2 >= 2)
        {
            for (int i{ startIndex + 1 }; i < rowNum - startIndex; i++)
            {
                nums.push_back(matrix[i][colNum - startIndex - 1]);
            }
        }

        if (rowNum - startIndex * 2 >= 2 && colNum -startIndex * 2 >= 2)
        {
            for (int i{ colNum - startIndex - 2 }; i >= startIndex; i--)
            {
                nums.push_back(matrix[rowNum - startIndex - 1][i]);
            }
        }
        if (rowNum - startIndex * 2 >= 3 && colNum - startIndex * 2 >= 2)
        {
            for (int i{ rowNum - startIndex - 2 }; i >= startIndex + 1; i--)
            {
                nums.push_back(matrix[i][startIndex]);
            }
        }
    }
};

int main()
{
    Solution solution = Solution();


    return 0;
}