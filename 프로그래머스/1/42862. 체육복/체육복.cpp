#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = n - lost.size();
    for (int i = 0; i < reserve.size(); i++) {
        if (find(lost.begin(), lost.end(), reserve[i]) != lost.end()) {
            lost.erase(find(lost.begin(), lost.end(), reserve[i]));
            reserve.erase(reserve.begin() + i);
            answer++;
            i--;
        }
    }
    sort(lost.begin(), lost.end());
    sort(reserve.begin(), reserve.end());
    for (int i = 0, j = 0; i < reserve.size() && j < lost.size(); i++) {
        if (lost[j] == reserve[i] - 1 || lost[j] == reserve[i] + 1) {
            answer++;
            j++;
        }
        else if (lost[j] < reserve[i] - 1) {
            j++;
            i--;
        }
    }
    return answer;
}