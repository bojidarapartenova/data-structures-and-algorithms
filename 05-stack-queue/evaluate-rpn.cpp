#include <string>
#include <stack>

using namespace std;
class Solution
{
public:
    int evalRPN(vector<string> &tokens)
    {
        stack<int> s;

        for (int i = 0; i < tokens.size(); i++)
        {
            if (tokens[i] == "+" || tokens[i] == "-" || tokens[i] == "*" || tokens[i] == "/")
            {
                int second = s.top();
                s.pop();
                int first = s.top();
                s.pop();

                if (tokens[i] == "+")
                {
                    s.push(first + second);
                }
                else if (tokens[i] == "-")
                {
                    s.push(first - second);
                }
                else if (tokens[i] == "*")
                {
                    s.push(first * second);
                }
                else if (tokens[i] == "/")
                {
                    s.push(first / second);
                }
            }
            else
            {
                s.push(stoi(tokens[i]));
            }
        }

        return s.top();
    }
};