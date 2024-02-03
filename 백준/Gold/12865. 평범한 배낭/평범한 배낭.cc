#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int knapSack(int k, vector<int> v1, vector<int> v2, int n)
{
	int i, w;
	vector<vector<int>> K(n + 1, vector<int>(k + 1, 0));

	for (i = 0; i <= n; i++)
	{
		for (w = 0; w <= k; w++)
		{
			if (i == 0 || w == 0)
				K[i][w] = 0;
			else if (v1[i - 1] <= w)
				K[i][w] = max(v2[i - 1] + K[i - 1][w - v1[i - 1]], K[i - 1][w]);
			else
				K[i][w] = K[i - 1][w];
		}
	}
	return K[n][k];
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, k;
	cin >> n >> k;
	vector<int> v1, v2;
	for (int i = 0; i < n; i++) {
		int w, v;
		cin >> w >> v;
		v1.push_back(w);
		v2.push_back(v);
	}
	cout << knapSack(k, v1, v2, v1.size());
	return 0;
}