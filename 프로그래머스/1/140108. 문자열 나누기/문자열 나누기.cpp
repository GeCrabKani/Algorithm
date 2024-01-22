#include <string>
#include <vector>

using namespace std;

int solution(string s) {
    int answer = 0;
    int xCnt = 0, yCnt = 0;
    int sIndex = 0;
    
    for (char c : s) {
        if (c == s[sIndex]) xCnt++;
        else yCnt++;

        if (xCnt == yCnt) {
            sIndex += xCnt + yCnt;
            answer++;
            xCnt = 0;
            yCnt = 0;
        }
    }
    if (xCnt != 0) answer++;
    return answer;
}