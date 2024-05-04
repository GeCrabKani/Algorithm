#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> map(51, vector<int>(51, 0));
vector<vector<int>> cloud(51, vector<int>(51, 0));
vector<vector<int>> moveCloud(51, vector<int>(51, 0));
vector<vector<int>> rain(51, vector<int>(51, 0));

int n;

void SetCloud()
{
    cloud[n][1] = 1;
    cloud[n][2] = 1;
    cloud[n - 1][1] = 1;
    cloud[n - 1][2] = 1;
}

void MoveCloud(int d, int s)
{
    switch(d)
    {
    case 1:
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (cloud[i][j] == 1)
                {
                    cloud[i][j] = 0;
                    int jIndex = j - s;
                    while (true)
                    {
                        if (jIndex <= 0)
                        {
                            jIndex += n;
                        }
                        else
                        {
                            break;
                        }
                    }
                    moveCloud[i][jIndex] = 1;
                }
            }
        }
        cloud = moveCloud;
        break;
    case 2:
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (cloud[i][j] == 1)
                {
                    cloud[i][j] = 0;
                    int iIndex = i - s;
                    while (true)
                    {
                        if (iIndex <= 0)
                        {
                            iIndex += n;
                        }
                        else
                        {
                            break;
                        }
                    }
                    int jIndex = j - s;
                    while (true)
                    {
                        if (jIndex <= 0)
                        {
                            jIndex += n;
                        }
                        else
                        {
                            break;
                        }
                    }
                    moveCloud[iIndex][jIndex] = 1;
                }
            }
        }
        cloud = moveCloud;
        break;
    case 3:
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (cloud[i][j] == 1)
                {
                    cloud[i][j] = 0;
                    int iIndex = i - s;
                    while (true)
                    {
                        if (iIndex <= 0)
                        {
                            iIndex += n;
                        }
                        else
                        {
                            break;
                        }
                    }
                    moveCloud[iIndex][j] = 1;
                }
            }
        }
        cloud = moveCloud;
        break;
    case 4:
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (cloud[i][j] == 1)
                {
                    cloud[i][j] = 0;
                    int iIndex = i - s;
                    while (true)
                    {
                        if (iIndex <= 0)
                        {
                            iIndex += n;
                        }
                        else
                        {
                            break;
                        }
                    }
                    int jIndex = j + s;
                    while (true)
                    {
                        if (jIndex > n)
                        {
                            jIndex -= n;
                        }
                        else
                        {
                            break;
                        }
                    }
                    moveCloud[iIndex][jIndex] = 1;
                }
            }
        }
        cloud = moveCloud;
        break;
    case 5:
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (cloud[i][j] == 1)
                {
                    cloud[i][j] = 0;
                    int jIndex = j + s;
                    while (true)
                    {
                        if (jIndex > n)
                        {
                            jIndex -= n;
                        }
                        else
                        {
                            break;
                        }
                    }
                    moveCloud[i][jIndex] = 1;
                }
            }
        }
        cloud = moveCloud;
        break;
    case 6:
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (cloud[i][j] == 1)
                {
                    cloud[i][j] = 0;
                    int iIndex = i + s;
                    while (true)
                    {
                        if (iIndex > n)
                        {
                            iIndex -= n;
                        }
                        else
                        {
                            break;
                        }
                    }
                    int jIndex = j + s;
                    while (true)
                    {
                        if (jIndex > n)
                        {
                            jIndex -= n;
                        }
                        else
                        {
                            break;
                        }
                    }
                    moveCloud[iIndex][jIndex] = 1;
                }
            }
        }
        cloud = moveCloud;
        break;
    case 7:
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (cloud[i][j] == 1)
                {
                    cloud[i][j] = 0;
                    int iIndex = i + s;
                    while (true)
                    {
                        if (iIndex > n)
                        {
                            iIndex -= n;
                        }
                        else
                        {
                            break;
                        }
                    }
                    moveCloud[iIndex][j] = 1;
                }
            }
        }
        cloud = moveCloud;
        break;
    case 8:
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (cloud[i][j] == 1)
                {
                    cloud[i][j] = 0;
                    int iIndex = i + s;
                    while (true)
                    {
                        if (iIndex > n)
                        {
                            iIndex -= n;
                        }
                        else
                        {
                            break;
                        }
                    }
                    int jIndex = j - s;
                    while (true)
                    {
                        if (jIndex <= 0)
                        {
                            jIndex += n;
                        }
                        else
                        {
                            break;
                        }
                    }
                    moveCloud[iIndex][jIndex] = 1;
                }
            }
        }
        cloud = moveCloud;
        break;
    }
}

void Rain()
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (cloud[i][j] == 1)
            {
                map[i][j]++;
                rain[i][j] = 1;
            }
        }
    }
}

void RemoveCloud()
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (cloud[i][j] == 1)
                cloud[i][j] = -1;
        }
    }
}

void WaterCopy()
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (rain[i][j] == 1)
            {
                // 좌상
                if (i != 1 && j != 1)
                {
                    if (map[i - 1][j - 1] > 0)
                    {
                        map[i][j]++;
                    }
                }

                // 우상
                if (i != n && j != 1)
                {
                    if (map[i + 1][j - 1] > 0)
                    {
                        map[i][j]++;
                    }
                }

                // 좌하
                if (i != 1 && j != n)
                {
                    if (map[i - 1][j + 1] > 0)
                    {
                        map[i][j]++;
                    }

                }

                // 우하
                if (i != n && j != n)
                {
                    if (map[i + 1][j + 1] > 0)
                    {
                        map[i][j]++;
                    }
                }
            }
        }
    }
}

void MakeCloud()
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (map[i][j] >= 2 && cloud[i][j] != -1)
            {
                cloud[i][j] = 1;
                map[i][j] -= 2;
            }

            if (cloud[i][j] == -1)
            {
                cloud[i][j] = 0;
            }
        }
    }
}

void CalWater()
{
    int sum = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            sum += map[i][j];
        }
    }
    cout << sum;
}

void ResetMoveCloud()
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            moveCloud[i][j] = 0;
        }
    }
}

void ResetRain()
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            rain[i][j] = 0;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int m, d, s;
    cin >> n >> m;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> map[i][j];
        }
    }

    SetCloud();
    for (int i = 0; i < m; i++)
    {
        cin >> d >> s;
        MoveCloud(d, s);
        Rain();
        RemoveCloud();
        WaterCopy();
        MakeCloud();
        ResetMoveCloud();
        ResetRain();
    }
    CalWater();
}