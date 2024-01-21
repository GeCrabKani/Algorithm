#include <string>
#include <vector>

using namespace std;

void divisor(vector<int>& v, const int& n)
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = i; j <= n; j += i)
        {
            v[j]++;
        }
    }
}

int solution(int number, int limit, int power) {
    int answer = 0;
    vector<int> v(number + 1, 0);
    divisor(v, number);
    for (auto i : v)
    {
        if (i > limit) answer += power;
        else answer += i;
    }
    return answer;
}