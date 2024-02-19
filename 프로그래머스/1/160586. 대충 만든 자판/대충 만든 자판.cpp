#include <string>
#include <vector>
#include <algorithm>

using namespace std;

const int MAX_DISTANCE = 100;

vector<int> solution(vector<string> keymap, vector<string> targets) {
    vector<int> answer;
    for (auto& target : targets)
    {
        int totalMinDistance = 0;

        for (auto& character : target)
        {
            int minDistance = MAX_DISTANCE;

            for (auto& key : keymap)
            {
                auto it = find(key.begin(), key.end(), character);

                if (it != key.end())
                {
                    int index = distance(key.begin(), it) + 1;

                    if (index < minDistance) minDistance = index;
                }
            }
            if (minDistance != MAX_DISTANCE)
                totalMinDistance += minDistance;
            else
            {
                totalMinDistance = 0;
                break;
            }
        }
        if (totalMinDistance == 0) totalMinDistance = -1;
        answer.push_back(totalMinDistance);
    }
    return answer;
}