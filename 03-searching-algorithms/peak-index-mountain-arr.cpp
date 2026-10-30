#include <vector>

class Solution
{
public:
    int peakIndexInMountainArray(std::vector<int> &arr)
    {
        long long left = 0;
        long long right = arr.size() - 1;

        while (left < right)
        {
            long long mid = left + (right - left) / 2;

            if (arr[mid] > arr[mid + 1])
            {
                right = mid;
            }
            else
            {
                left = mid + 1;
            }
        }
        return left;
    }
};