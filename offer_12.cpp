#include <vector>
#include <string>

class Solution
{
public:
    bool exist(std::vector<std::vector<char>> &board, std::string word)
    {
        bool* visited = new bool[board.size() * board[0].size()];
        for (int i{ 0 }; i < board.size() * board[0].size(); i++)
        {
            visited[i] = false;
        }

        int pathLength = 0;

        for (size_t row{ 0 }; row < board.size(); row++)
        {
            for (size_t col { 0 }; col < board[0].size(); col++)
            {
                if (hasPathCore(board, row, col, word, pathLength, visited))
                {
                    return true;
                }
            }
            
        }

        delete[] visited;

        return false;
    }

    bool hasPathCore(const std::vector<std::vector<char>> &board, size_t row, size_t col, std::string word, int& pathLength, bool* visited)
    {
        if (word.length() == pathLength)
        {
            return true;
        }
        bool hasPath = false;

        if (row >= 0 && row < board.size() && col >= 0 && col < board[0].size() && board[row][col] == word[pathLength] && !visited[board[0].size() * row + col])
        {
            pathLength++;
            visited[board[0].size() * row + col] = true;

            hasPath = hasPathCore(board, row - 1, col, word, pathLength, visited)
            || hasPathCore(board, row + 1, col, word, pathLength, visited)
            || hasPathCore(board, row, col + 1, word, pathLength, visited)
            || hasPathCore(board, row, col - 1, word, pathLength, visited);

            if (!hasPath)
            {
                pathLength--;
                visited[board[0].size() * row + col] = false;
            }
        }

        return hasPath;
    }
};