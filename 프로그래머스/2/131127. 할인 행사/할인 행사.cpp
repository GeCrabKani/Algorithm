#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

int solution(vector<string> want, vector<int> number, vector<string> discount) {
    int answer = 0;
    
    for (int i = 0; i <= discount.size() - 10; i++)
    {
        bool canDiscount = true;
        unordered_map<string, int> um;

        for (int j = i; j < i + 10; j++)
        {
            um[discount[j]]++;
        }
        
        for (int j = 0; j < want.size(); j++)
        {
            if (um[want[j]] < number[j])
            {
                canDiscount = false;
                break;
            }
        }

        if (canDiscount) answer++;
    }
    return answer;
}