class Solution {
public:
	bool findNumberIn2DArray(std::vector<std::vector<int>>& matrix, int target)
	{
		if (matrix.size() == 0 || matrix[0].size() == 0)
		{
			return false;
		}

		int n{ static_cast<int>(matrix[0].size()) - 1 };
		int m{ 0 };


		int now_num{ matrix[m][n] };

		while (true)
		{
			if (now_num == target)
			{
				return true;
			}
			else if (now_num > target)
			{
				n--;
			}
			else
			{
				m++;
			}

			if (m >= static_cast<int>(matrix.size()) || n < 0)
			{
				break;
			}
			else
			{
				now_num = matrix[m][n];
			}
		}

		return false;
	}
};