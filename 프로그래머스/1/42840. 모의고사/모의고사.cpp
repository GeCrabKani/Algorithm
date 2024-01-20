#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> answers) {
    vector<int> answer;
    int pattern[3][10] = {
        {1, 2, 3, 4, 5},
        {2, 1, 2, 3, 2, 4, 2, 5},
        {3, 3, 1, 1, 2, 2, 4, 4, 5, 5}
    };
    int score[3] = { 0, 0, 0 };

    for (int i = 0; i < answers.size(); i++) {
        if (pattern[0][i % 5] == answers[i]) score[0]++;
        if (pattern[1][i % 8] == answers[i]) score[1]++;
        if (pattern[2][i % 10] == answers[i]) score[2]++;
    }

    int maxScore = *max_element(score, score + 3);
    for (int i = 0; i < 3; i++) {
        if (score[i] == maxScore) {
            answer.push_back(i + 1);
        }
    }

    return answer;
}