#include <string>
#include <vector>

using namespace std;

string solution(string X, string Y) {
    string answer = "";
    int arrx[10] = { 0 }, arry[10] = { 0 };
    for (auto x : X)
    {
        arrx[x - '0']++;
    }
    for (auto y : Y)
    {
        arry[y - '0']++;
    }
    for (int i = 9; i >= 0; i--)
    {
        int cnt;
        arrx[i] > arry[i] ? cnt = arry[i] : cnt = arrx[i];
        
        if (i == 0 && answer == "" && cnt > 0) return "0";

        for (int j = 0; j < cnt; j++)
        {
            answer += (i + '0');
        }
    }
    if (answer == "") return "-1";
    return answer;
}