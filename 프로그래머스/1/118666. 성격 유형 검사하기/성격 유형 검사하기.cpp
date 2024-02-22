#include <string>
#include <vector>
#include <map>

using namespace std;

string solution(vector<string> survey, vector<int> choices) {
    string answer = "";
    map<char, int> m;
    for (int i = 0; i < choices.size(); i++)
    {
        switch (choices[i])
        {
            case 1:
                m[survey[i][0]] += 3;
                break;
            case 2:
                m[survey[i][0]] += 2;
                break;
            case 3:
                m[survey[i][0]] += 1;
                break;
            case 4:
                break;
            case 5:
                m[survey[i][1]] += 1;
                break;
            case 6:
                m[survey[i][1]] += 2;
                break;
            case 7:
                m[survey[i][1]] += 3;
                break;
        }
    }

    m['T'] > m['R'] ? answer += 'T' : answer += 'R';
    m['F'] > m['C'] ? answer += 'F' : answer += 'C';
    m['M'] > m['J'] ? answer += 'M' : answer += 'J';
    m['N'] > m['A'] ? answer += 'N' : answer += 'A';
    return answer;
}