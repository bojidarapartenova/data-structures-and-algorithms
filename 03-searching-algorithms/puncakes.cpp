#include <vector>
#include <iostream>

using namespace std;
bool isEnough(vector<int> &cooks, long long time, long long n)
{
    long long sum = 0;
    for (int i = 0; i < cooks.size(); i++)
    {
        sum += time / cooks[i];

        if (sum >= n)
        {
            return true;
        }
    }
    return sum >= n;
}

int main()
{
    long long n, k;
    cin >> n >> k;
    vector<int> cooks;

    for (int i = 0; i < k; i++)
    {
        int time;
        cin >> time;
        cooks.push_back(time);
    }

    int min = cooks[0];
    for (int i = 0; i < cooks.size(); i++)
    {
        if (min > cooks[i])
        {
            min = cooks[i];
        }
    }

    long long left = 0;
    long long right = n * min;

    while (left <= right)
    {
        long long mid = left + (right - left) / 2;
        if (isEnough(cooks, mid, n))
        {
            right = mid - 1;
        }
        else
        {
            left = mid + 1;
        }
    }
    cout << left;
}