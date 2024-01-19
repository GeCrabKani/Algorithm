#include <string>
#include <vector>
#include <map>

using namespace std;

vector<string> solution(vector<string> players, vector<string> callings) {
    vector<string> answer;
    map<string, int> m;
	for (int i = 1; i <= players.size(); i++) {
		m.insert({ players[i - 1], i });
	}
	for (int i = 0; i < callings.size(); i++) {
		string temp = "";
		if (m.find(callings[i]) != m.end()) {
			temp = players[m.find(callings[i])->second - 1];
			players[m.find(callings[i])->second - 1] = players[m.find(callings[i])->second - 2];
			players[m.find(callings[i])->second - 2] = temp;
            
            m[callings[i]]--;
            m[players[m.find(callings[i])->second]]++;
		}
	}
    return players;
}