#include <iostream>
#include <string>

class Solution
{
    bool check(const std::string &s, int i, int j)
    {
        while (i < j)
        {
            if (s[i++] != s[j--])
            {
                return false;
            }
        }
        return true;
    }

public:
    bool validPalindrome(std::string s)
    {
        int i = 0;
        int j = s.size() - 1;

        while (i < j)
        {
            if (s[i] == s[j])
            {
                i++;
                j--;
            }
            else
            {
                return check(s, i + 1, j) || check(s, i, j - 1);
            }
        }
        return true;
    }
};

int main()
{
}