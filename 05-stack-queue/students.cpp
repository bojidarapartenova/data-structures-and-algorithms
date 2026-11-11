#include <queue>
#include <stack>

using namespace std;
class Solution
{
public:
    int countStudents(vector<int> &students, vector<int> &sandwiches)
    {
        queue<int> q;
        stack<int> s;

        int count0 = 0;
        int count1 = 0;

        for (int i = 0; i < students.size(); i++)
        {
            if (students[i] == 0)
            {
                count0++;
            }
            else
            {
                count1++;
            }

            q.push(students[i]);
        }

        for (int i = sandwiches.size() - 1; i >= 0; i--)
        {
            s.push(sandwiches[i]);
        }

        while (!q.empty() && !s.empty())
        {
            if (s.top() == 0 && count0 == 0)
            {
                break;
            }

            if (s.top() == 1 && count1 == 0)
            {
                break;
            }

            if (q.front() == s.top())
            {
                if (q.front() == 0)
                {
                    count0--;
                }
                else
                {
                    count1--;
                }

                q.pop();
                s.pop();
            }
            else
            {
                q.push(q.front());
                q.pop();
            }
        }
        return q.size();
    }
};