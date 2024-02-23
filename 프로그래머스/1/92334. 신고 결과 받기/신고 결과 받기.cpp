#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

vector<int> solution(vector<string> id_list, vector<string> report, int k) {
        vector<int> answer(id_list.size(), 0);
    unordered_map<string, int> um;
    unordered_map<string, int> um2;

    sort(report.begin(), report.end());
    auto last = unique(report.begin(), report.end());
    report.erase(last, report.end());

    for (int i = 0; i < id_list.size(); i++)
    {
        um2[id_list[i]] = i;
    }

    for (auto s : report)
    {
        size_t spacePos = s.find(' ');
        string user2 = s.substr(spacePos + 1);

        auto it = um.find(user2);
        if (it != um.end())
        {
            it->second += 1;
        }
        else
        {
            um[user2] = 1;
        }
    }

    for (auto s : report)
    {
        size_t spacePos = s.find(' ');
        string user1 = s.substr(0, spacePos);
        string user2 = s.substr(spacePos + 1);

        if (um[user2] >= k)
        {
            answer[um2[user1]]++;
        }
    }
    return answer;
}