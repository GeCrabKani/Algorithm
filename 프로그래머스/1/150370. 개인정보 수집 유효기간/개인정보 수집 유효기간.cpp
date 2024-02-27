#include <string>
#include <vector>
#include <sstream>
#include <unordered_map>

using namespace std;

void parseDate(const string& dateStr, int& year, int& month, int& day) {
    istringstream iss(dateStr);
    string part;
    getline(iss, part, '.'); year = stoi(part);
    getline(iss, part, '.'); month = stoi(part);
    getline(iss, part, '.'); day = stoi(part);
}

void addMonths(int& year, int& month, int& day, int months) {
    month += months;
    year += (month - 1) / 12;
    month = (month - 1) % 12 + 1;
}

vector<int> solution(string today, vector<string> terms, vector<string> privacies) {
    vector<int> answer;
    unordered_map<string, int> termMap;
    int tYear, tMonth, tDay;

    parseDate(today, tYear, tMonth, tDay);

    for (const auto& term : terms) {
        istringstream iss(term);
        string type;
        int month;
        iss >> type >> month;
        termMap[type] = month;
    }

    for (int i = 0; i < privacies.size(); ++i) {
        int pYear, pMonth, pDay;
        string date, type;
        istringstream iss(privacies[i]);
        getline(iss, date, ' ');
        iss >> type;

        parseDate(date, pYear, pMonth, pDay);
        pDay--;
        addMonths(pYear, pMonth, pDay, termMap[type]);

        if (tYear > pYear || (tYear == pYear && tMonth > pMonth) || (tYear == pYear && tMonth == pMonth && tDay > pDay)) {
            answer.push_back(i + 1);
        }
    }

    return answer;
}