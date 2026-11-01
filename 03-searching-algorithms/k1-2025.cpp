#include <iostream>
#include <vector>
#include <algorithm>

bool isPossible(std::vector<int> boxes, int mid, int h)
{
    int hoursLeft = h;
    for (size_t i = 0; i < boxes.size(); i++)
    {
        while (boxes[i] > 0)
        {
            boxes[i] -= mid;
            hoursLeft--;

            if (hoursLeft < 0)
            {
                return false;
            }
        }
    }
    return true;
}

int main()
{
    int n, h;
    std::cin >> n >> h;

    std::vector<int> boxes;
    for (size_t i = 0; i < n; i++)
    {
        int b;
        std::cin >> b;
        boxes.push_back(b);
    }

    std::sort(boxes.begin(), boxes.end());

    int left = 1;
    int right = boxes[boxes.size() - 1];
    while (left <= right)
    {
        int mid = left + (right - left) / 2;

        if (isPossible(boxes, mid, h))
        {
            right = mid - 1;
        }
        else
        {
            left = mid + 1;
        }
    }

    std::cout << left;
}