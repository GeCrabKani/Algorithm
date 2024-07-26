#include <iostream>
#include <map>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;
    string s;
    map<string, int> m;

    for (int i = 0; i < n; i++)
    {
        cin >> s;

        m[s.substr(s.find(".") + 1)]++;
    }

    for (auto member : m)
    {
        cout << member.first << " " << member.second << "\n";
    }

    return 0;
}