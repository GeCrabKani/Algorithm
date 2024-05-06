#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, sum = 0;
vector<vector<int>> map(500, vector<int>(500, 0));

int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, 1, 0, -1 };

void MoveTornado(int direction, int count, int x, int y)
{
    vector<pair<int, int>> offsets;
    vector<float> percentages = { 0.05, 0.1, 0.1, 0.07, 0.07, 0.02, 0.02, 0.01, 0.01 };

    for (int i = 0; i < count; i++)
    {
        if (x == 0 && y == 0)
        {
            return;
        }

        int sand = map[y + dy[direction]][x + dx[direction]];
        int tornadoX = x;
        int tornadoY = y;
        int sandSum = 0;

        switch (direction)
        {
        case 0:
            offsets = { {-3, 0}, {-2, -1}, {-2, 1}, {-1, -1}, {-1, 1}, {-1, -2}, {-1, 2}, {0, -1}, {0, 1} };
            break;
        case 1:
            offsets = { {0, 3}, {-1, 2}, {1, 2}, {-1, 1}, {1, 1}, {-2, 1}, {2, 1}, {-1, 0}, {1, 0} };
            break;
        case 2:
            offsets = { {3, 0}, {2, -1}, {2, 1}, {1, -1}, {1, 1}, {1, -2}, {1, 2}, {0, -1}, {0, 1} };
            break;
        case 3:
            offsets = { {0, -3}, {-1, -2}, {1, -2}, {-1, -1}, {1, -1}, {-2, -1}, {2, -1}, {-1, 0}, {1, 0} };
            break;
        }

        for (int j = 0; j < offsets.size(); j++)
        {
            if (tornadoX + offsets[j].first < 0 || tornadoY + offsets[j].second < 0 || tornadoX + offsets[j].first >= n || tornadoY + offsets[j].second >= n)
            {
                sum += int(sand * percentages[j]);
                continue;
            }
            map[tornadoY + offsets[j].second][tornadoX + offsets[j].first] += int(sand * percentages[j]);
        }

        for (int j = 0; j < percentages.size(); j++)
        {
            sandSum += int(sand * percentages[j]);
        }

        if (tornadoX + dx[direction] * 2 < 0 || tornadoY + dy[direction] * 2 < 0 || tornadoX + dx[direction] * 2 >= n || tornadoY + dy[direction] * 2 >= n)
        {
            sum += sand - sandSum;
        }
        else
        {
            map[tornadoY + dy[direction] * 2][tornadoX + dx[direction] * 2] += sand - sandSum;
        }

        map[tornadoY + dy[direction]][tornadoX + dx[direction]] = 0;

        x += dx[direction];
        y += dy[direction];
    }

    switch (direction)
    {
    case 0:
        return MoveTornado(1, count, x, y);
        break;
    case 1:
        return MoveTornado(2, count + 1, x, y);
        break;
    case 2:
        return MoveTornado(3, count, x, y);
        break;
    case 3:
        return MoveTornado(0, count + 1, x, y);
        break;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> map[i][j];
        }
    }

    MoveTornado(0, 1, n / 2, n / 2);

    cout << sum;
}