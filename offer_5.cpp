class Solution {
public:
    std::string replaceSpace(std::string s) 
    {
        size_t old_length{ s.length() };
        size_t spaces = std::count(s.begin(), s.end(), ' ');
        size_t new_length = s.length() + spaces * 2;
        s.resize(new_length);

        for (size_t p1{ old_length }, p2{ new_length }, i{ 0 }; i < old_length + 1; i++)
        {
            if (s[p1] != ' ')
            {
                s[p2] = s[p1];
                p2--;
            }
            else
            {
                s.replace(p2 - 2, 3, "%20");
                p2 -= 3;
            }

            p1--;
        }

        return s;
    }
};