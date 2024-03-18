#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

int solution(vector<vector<string>> clothes) {
    int answer = 1;
    unordered_map<string, int> um;
    
    for (int i = 0; i < clothes.size(); i++)
    {
        um[clothes[i][1]]++;
    }

    for (auto& pair : um) {
        answer *= (pair.second + 1);
    }
    
    answer--;
    
    return answer;
}