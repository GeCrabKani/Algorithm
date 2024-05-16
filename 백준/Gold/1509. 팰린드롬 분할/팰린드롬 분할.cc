#include <iostream>
#include <vector>
#include <string>
#include <climits>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string s;
    cin >> s;
    int n = s.length();

    vector<vector<bool>> isPalindrome(n, vector<bool>(n, false));

    for (int i = 0; i < n; ++i) {
        isPalindrome[i][i] = true;
    }

    for (int i = 0; i < n - 1; ++i) {
        if (s[i] == s[i + 1]) {
            isPalindrome[i][i + 1] = true;
        }
    }

    for (int length = 3; length <= n; ++length) {
        for (int i = 0; i <= n - length; ++i) {
            int j = i + length - 1;
            if (s[i] == s[j] && isPalindrome[i + 1][j - 1]) {
                isPalindrome[i][j] = true;
            }
        }
    }

    vector<int> dp(n, INT_MAX);

    for (int j = 0; j < n; ++j) {
        if (isPalindrome[0][j]) {
            dp[j] = 0;
        }
        else {
            for (int i = 1; i <= j; ++i) {
                if (isPalindrome[i][j]) {
                    dp[j] = min(dp[j], dp[i - 1] + 1);
                }
            }
        }
    }

    cout << dp[n - 1] + 1<< endl;

    return 0;
}