#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<string> wallpaper) {
    vector<int> answer;
    int lux = 50, luy = 50, rdx = 0, rdy = 0;
    for (int i = 0; i < wallpaper.size(); i++)
    {
        for (int j = 0; j < wallpaper[i].size(); j++)
        {
            if (wallpaper[i][j] == '#')
            {
                if (lux > j) lux = j;
                if (luy > i) luy = i;
                if (rdx < j + 1) rdx = j + 1;
                if (rdy < i + 1) rdy = i + 1;
            }
        }
    }
    answer.push_back(luy);
    answer.push_back(lux);
    answer.push_back(rdy);
    answer.push_back(rdx);
    return answer;
}