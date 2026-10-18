#include <iostream>
#include <vector>
#include <algorithm>

class Solution
{
public:
    std::vector<int> intersect(std::vector<int> &nums1, std::vector<int> &nums2)
    {
        std::vector<int> res;
        std::vector<int> count1(10001, 0);
        std::vector<int> count2(1001, 0);

        for (int i = 0; i < nums1.size(); i++)
        {
            count1[nums1[i]]++;
        }
        for (int i = 0; i < nums2.size(); i++)
        {
            count2[nums2[i]]++;
        }

        for (int i = 0; i < count1.size(); i++)
        {
            if (count1[i] > 0 && count2[i] > 0)
            {
                int less = 0;
                if (count1[i] < count2[i])
                {
                    less = count1[i];
                }
                else
                {
                    less = count2[i];
                }
                while (less > 0)
                {
                    res.push_back(i);
                    less--;
                }
            }
        }
        return res;
    }
};