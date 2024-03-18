#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    int days = 0;
    int count = 0;

    for (int i = 0; i < progresses.size(); i++) {
        int currentDays = (100 - progresses[i] + speeds[i] - 1) / speeds[i];

        if (days < currentDays) {
            if (count > 0) {
                answer.push_back(count);
            }
            days = currentDays;
            count = 1;
        }
        else {
            count++;
        }
    }

    answer.push_back(count);

    return answer;
}