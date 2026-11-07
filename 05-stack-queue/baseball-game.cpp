#include <string>
#include <stack>

using namespace std;

class Solution
{
public:
    int calPoints(vector<string> &operations)
    {
        stack<int> stack;

        for (int i = 0; i < operations.size(); i++)
        {
            if (operations[i] == "C")
            {
                stack.pop();
            }

            else if (operations[i] == "D")
            {
                int el = stack.top() * 2;
                stack.push(el);
            }

            else if (operations[i] == "+")
            {
                int first = stack.top();
                stack.pop();
                int second = stack.top();
                stack.push(first);
                stack.push(first + second);
            }

            else
            {
                stack.push(stoi(operations[i]));
            }
        }

        int sum = 0;
        while (!stack.empty())
        {
            sum += stack.top();
            stack.pop();
        }

        return sum;
    }
};