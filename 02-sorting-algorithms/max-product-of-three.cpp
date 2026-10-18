#include <iostream>
#include <vector>
#include <algorithm>

class Solution
{
public:
    int maximumProduct(std::vector<int> &nums)
    {
        sort(nums.begin(), nums.end());

        int largestEl = nums[nums.size() - 1];
        int product1 = largestEl * nums[nums.size() - 2] * nums[nums.size() - 3];
        int product2 = largestEl * nums[0] * nums[1];

        if (product1 > product2)
        {
            return product1;
        }
        else
        {
            return product2;
        }
    }
};