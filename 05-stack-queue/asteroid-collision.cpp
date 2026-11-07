#include <string>
#include <stack>

using namespace std;
class Solution
{
public:
    vector<int> asteroidCollision(vector<int> &asteroids)
    {
        stack<int> st;

        for (int a : asteroids)
        {
            bool alive = true;

            while (!st.empty() && st.top() > 0 && a < 0 && alive)
            {
                int top = st.top();

                if (abs(top) < abs(a))
                {
                    st.pop();
                }
                else if (abs(top) == abs(a))
                {
                    st.pop();
                    alive = false;
                }
                else
                {
                    alive = false;
                }
            }

            if (alive)
            {
                st.push(a);
            }
        }

        vector<int> res;
        while (!st.empty())
        {
            res.push_back(st.top());
            st.pop();
        }

        reverse(res.begin(), res.end());
        return res;
    }
};