#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

string solution(vector<string> cards1, vector<string> cards2, vector<string> goal) {
    int index1 = 0, index2 = 0;

    for (const string& word : goal) {
        bool found = false;

        if (index1 < cards1.size() && cards1[index1] == word) {
            index1++;
            found = true;
        } else if (index2 < cards2.size() && cards2[index2] == word) {
            index2++;
            found = true;
        }

        if (!found) {
            return "No";
        }
    }

    return "Yes";
}