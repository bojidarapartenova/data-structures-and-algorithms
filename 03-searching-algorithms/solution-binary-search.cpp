#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

struct Box
{
    int weight;
    int index;
    Box(int weight, int index) : weight(weight), index(index) {}
};

bool operator<(const Box &b1, const Box &b2)
{
    return b1.weight < b2.weight;
}

void handleRequest()
{
    int x;
    cin >> x;
    int n;
    cin >> n;

    vector<Box> boxes;
    for (int i = 0; i < n; i++)
    {
        int w;
        cin >> w;
        boxes.push_back({w, i + 1});
    }

    sort(boxes.begin(), boxes.end());

    int left = 0;
    int right = boxes.size() - 1;
    while (left < right)
    {
        int sum = boxes[left].weight + boxes[right].weight;
        if (sum == x)
        {
            break;
        }
        else if (sum < x)
        {
            left++;
        }
        else
        {
            right--;
        }
    }

    cout << min(boxes[left].index, boxes[right].index) << ' ' << max(boxes[left].index, boxes[right].index) << endl;
}

int main()
{
    int t;
    cin >> t;

    for (int i = 0; i < t; i++)
    {
        handleRequest();
    }
    return 0;
}