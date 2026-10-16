#include <iostream>
#include <vector>
#include <unordered_map>

class Solution
{
public:
    std::vector<int> twoSum(std::vector<int> &nums, int target)
    {
        std::unordered_map<int, int> seen;
        for (int i = 0; i < nums.size(); i++)
        {
            int curr = nums[i];
            int x = target - curr;

            if (seen.find(x) != seen.end())
            {
                return {seen[x], i};
            }
            seen[curr] = i;
        }
        return {};
    }
};

int main()
{
}