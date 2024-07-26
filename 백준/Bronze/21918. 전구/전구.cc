#include <iostream>
#include <vector>
#include <string>
#include <climits>
#include <algorithm>
#include <queue>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m, a, b, c;
    cin >> n >> m;
    vector<int> light;
    light.resize(n);
    
    for (int i = 0; i < n; i++)
    {
        cin >> light[i];
    }

    for (int i = 0; i < m; i++)
    {
        cin >> a >> b >> c;

        switch (a)
        {
        case 1:
            light[b - 1] = c;
            break;
        case 2:
            for (int j = b - 1; j < c; j++)
            {
                light[j] == 0 ? light[j] = 1 : light[j] = 0;
            }
            break;
        case 3:
            for (int j = b - 1; j < c; j++)
            {
                light[j] = 0;
            }
            break;
        case 4:
            for (int j = b - 1; j < c; j++)
            {
                light[j] = 1;
            }
            break;
        }
    }

    for (int i = 0; i < n; i++)
    {
        cout << light[i] << " ";
    }

    return 0;
}
