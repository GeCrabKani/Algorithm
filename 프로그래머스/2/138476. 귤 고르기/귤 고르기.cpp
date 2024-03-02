#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int k, vector<int> tangerine) {
    int answer = 0;
    vector<int> v(10000001, 0);
    for (int i = 0; i < tangerine.size(); i++)
    {
        v[tangerine[i]]++;
    }
    sort(v.begin(), v.end());
    for (int i = v.size() - 1; i > 0; i--)
    {
        answer++;
        k -= v[i];
        if (k <= 0) return answer;
    }
}