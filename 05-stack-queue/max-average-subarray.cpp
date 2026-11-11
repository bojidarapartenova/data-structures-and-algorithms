#include <queue>

using namespace std;
class Solution
{
public:
    double findMaxAverage(vector<int> &nums, int k)
    {
        queue<int> q;
        int sum = 0;

        for (int i = 0; i < k; i++)
        {
            sum += nums[i];
            q.push(nums[i]);
        }

        int maxSum = sum;
        for (int i = k; i < nums.size(); i++)
        {
            sum -= q.front();
            q.pop();
            q.push(nums[i]);

            sum += nums[i];

            maxSum = max(maxSum, sum);
        }

        return (double)maxSum / k;
    }
};