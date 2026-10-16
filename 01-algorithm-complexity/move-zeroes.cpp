#include <iostream>
#include <vector>

class Solution
{
public:
    void moveZeroes(std::vector<int> &nums)
    {
        int pos = 0;
        for (size_t i = 0; i < nums.size(); i++)
        {
            if (nums[i] != 0)
            {
                std::swap(nums[pos], nums[i]);
                pos++;
            }
        }
    }
};

int main()
{
}