#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int compare(string s1, string s2) {
    if (s1.size() > s2.size()) 
    {
        if (s1[0] == '-' && s2[0] == '0') {
            return 1;
        }
        else if (s1[0] != '-' && s2[0] == '0') {
            return 0;
        }
        else if (s1[0] == '-' && s2[0] == '-') {
            return 1;
        }
        else if (s1[0] != '-' && s2[0] == '-') {
            return 0;
        }
        else if (s1[0] == '-' && s2[0] != '-') {
            return 1;
        }
        else {
            return 0;
        }
    }
    else if (s1.size() < s2.size()) {
        if(s1[0] == '0' && s2[0] == '-') {
            return 0;
        }
        else if (s1[0] == '0' && s2[0] != '-') {
            return 1;
        }
        else if (s1[0] == '-' && s2[0] == '-') {
            return 0;
        }
        else if (s1[0] != '-' && s2[0] == '-') {
            return 0;
        }
        else if (s1[0] == '-' && s2[0] != '-') {
            return 1;
        }
        else {
            return 1;
        }
    }
	else if(s1[0] == '0' && s2[0] == '-') {
		return 0;
	}
	else if (s1[0] == '0' && s2[0] != '-') {
		return 1;
	}
	else if (s1[0] == '-' && s2[0] == '0') {
		return 1;
	}
	else if (s1[0] != '-' && s2[0] == '0') {
		return 0;
	}
    else if (s1[0] == '-' && s2[0] == '-') {
		return s1 > s2;
	}
	else if (s1[0] != '-' && s2[0] == '-') {
		return 0;
	}
	else if (s1[0] == '-' && s2[0] != '-') {
		return 1;
	}
	else {
		return s1 < s2;
	}
}

string solution(string s) {
    string answer = "";
	vector<string> v;
	string temp = "";
	for (int i = 0; i < s.length(); i++) {
		if (s[i] != ' ') {
			temp += s[i];
		}
		else {
			v.push_back(temp);
			temp = "";
		}
	}
	v.push_back(temp);
	sort(v.begin(), v.end(), compare);
    answer += v[0];
    answer += " ";
    answer += v[v.size() - 1];
    return answer;
}