#include <string>
#include <vector>
#include <stack>

using namespace std;

bool check(string s)
{
    stack<char> st;

    for (auto c : s) {
        if (c == '(' || c == '[' || c == '{') {
            st.push(c);
        }
        else {
            if (st.empty()) return false;
            if (c == ')' && st.top() != '(') return false;
            if (c == ']' && st.top() != '[') return false;
            if (c == '}' && st.top() != '{') return false;
            st.pop();
        }
    }

    return st.empty();
}

int solution(string s) {
    int answer = 0;
    int size = s.size();
    for (int i = 0; i < size; i++)
    {
        if (check(s)) answer++;
        s = s.substr(1) + s[0];
    }
    return answer;
}