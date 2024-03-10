#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n, long long left, long long right) {
    vector<int> answer;
    long long row = left / n;
    long long col = left % n;

    for (int i = col + 1; i <= n; i++)
    {
        i > row + 1 ? answer.push_back(i) : answer.push_back(row + 1);

        if (answer.size() == (right - left + 1)) return answer;
    }
    while (true)
    {
        row++;
        for (int i = 1; i <= n; i++)
        {
            i > row + 1 ? answer.push_back(i) : answer.push_back(row + 1);

            if (answer.size() == (right - left + 1)) return answer;
        }
    }
    return answer;
}