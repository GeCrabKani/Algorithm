#include <iostream>
#include <queue>
#include <unordered_map>

using namespace std;

int n;
int inDegree[1001];
vector<int> v[1001];

void topologySort()
{
    int result[1001];
    queue<int> q;

    for (int i = 1; i <= n; i++)
    {
        if (inDegree[i] == 0) q.push(i);
    }

    for (int i = 1; i <= n; i++)
    {
        if (q.empty())
        {
            cout << 0;
            return;
        }
        
        int x = q.front();
        q.pop();
        result[i] = x;

        for (int j = 0; j < v[x].size(); j++)
        {
            int y = v[x][j];

            if (--inDegree[y] == 0)
            {
                q.push(y);
            }
        }
    }

    for (int i = 1; i <= n; i++)
    {
        cout << result[i] << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int m;
    cin >> n >> m;

    for (int i = 0; i < m; i++)
    {
        int t, x;
        cin >> t;

        cin >> x;

        for (int j = 0; j < t - 1; j++)
        {
            int y;
            cin >> y;

            v[x].push_back(y);
            inDegree[y]++;

            x = y;
        }
    }

    topologySort();

	return 0;
}