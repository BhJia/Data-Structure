#include <iostream>
#include <unordered_map>
#include <vector>
#include <stack>
using namespace std;
bool isValid(string s);
bool isValid(string s)
{
    int n = s.size();
    if (n % 2 != 0)
        return false;
    unordered_map<char, char> pairs;
    pairs[')'] = '(';
    pairs[']'] = '[';
    pairs['}'] = '{';
    stack<char> st;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == '(' || s[i] == '[' || s[i] == '{')
        {
            st.push(s[i]);
        }
        else
        {
            if (st.empty() || pairs[s[i]] != st.top())
            {
                return false;
            }
            st.pop();
        }
    }
    return st.empty();
}

int main()
{
    string s;
    cin >> s;
    cout << isValid(s) << endl;
    return 0;
}
