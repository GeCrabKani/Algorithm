#include <string>
#include <vector>

using namespace std;

int solution(int n, int m, vector<int> section) {
    int answer = 0;
    int paint = section[0];
    for (auto i : section)
    {
        if (paint > n) return answer;
        
        if (i >= paint)
        {
            answer++;
            paint = i + m;
        }
    }
    return answer;
}