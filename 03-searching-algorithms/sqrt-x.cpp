class Solution
{
public:
    int mySqrt(int x)
    {
        if (x == 1)
        {
            return 1;
        }

        int left = 0;
        int right = x / 2;
        while (left <= right)
        {
            long long mid = left + (right - left) / 2;
            if (mid * mid == x)
            {
                return mid;
            }
            else if (mid * mid < x)
            {
                left = mid + 1;
            }
            else
            {
                right = mid - 1;
            }
        }
        return right;
    }
};