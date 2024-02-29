#include <string>
#include <vector>

using namespace std;


int gcd(int a, int b) {
    if (a % b == 0) {
        return b;
    }
    else {
        return gcd(b, a % b);
    }
}

int solution(vector<int> arr) {
    int answer = 1;
    for (auto target : arr)
    {
        answer = (answer * target) / gcd(answer, target);
    }
    return answer;
}