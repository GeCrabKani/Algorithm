#include <iostream>
#include <map>

using namespace std;

string getSubstringAfter(const string& str, const string& delimiter) {
    size_t pos = str.find(delimiter);
    if (pos != string::npos) {
        return str.substr(pos + delimiter.length());
    }
    return "";
}

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
        cout << member.first << " " << member.second << endl;
    }

    return 0;
}