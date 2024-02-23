#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<string> park, vector<string> routes) {
    vector<int> answer;
    int x = 0, y = 0;
    for (int i = 0; i < park.size(); i++)
    {
        for (int j = 0; j < park[i].size(); j++)
        {
            if (park[i][j] == 'S')
            {
                x = j;
                y = i;
                break;
            }
        }
    }

    for (auto route : routes)
    {
        int num = route[2] - '0';
        bool move = true;

        switch (route[0])
        {
        case 'N':
            for (int i = 1; i <= num; i++)
            {
                if (y - i < 0 || park[y - i][x] == 'X') move = false;
            }

            if (move) y -= num;
            break;
        case 'S' :
            for (int i = 1; i <= num; i++)
            {
                if (y + i >= park.size() || park[y + i][x] == 'X') move = false;
            }

            if (move) y += num;
            break;
        case 'W' :
            for (int i = 1; i <= num; i++)
            {
                if (x - i < 0 || park[y][x - i] == 'X') move = false;
            }

            if (move) x -= num;
            break;
        case 'E' :
            for (int i = 1; i <= num; i++)
            {
                if (x + i >= park[0].size() || park[y][x + i] == 'X') move = false;
            }

            if (move) x += num;
            break;
        }
    }
    answer.push_back(y);
    answer.push_back(x);
    return answer;
}