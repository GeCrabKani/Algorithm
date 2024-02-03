#include <iostream>
#include <sstream>
#include <vector>
using namespace std;

int sum (string str) {
	int sum = 0;
	istringstream ss(str);
    string stringBuffer;
    vector<int> x;
    x.clear();
    while (getline(ss, stringBuffer, '+')){
        x.push_back(stoi(stringBuffer));
    }
    for (int i = 0; i < x.size(); i++) {
    	sum += x[i];
	}
	return sum;
}

int main() {
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int tmp, result = 0;
	string str;
	cin >> str;
    istringstream ss(str);
    string stringBuffer;
    vector<string> x;
    x.clear();
    while (getline(ss, stringBuffer, '-')){
        x.push_back(stringBuffer);
    }
    result = sum(x[0]);
    for (int i = 1; i < x.size(); i++) {
    	result -= sum(x[i]);
	}
	cout << result;
	return 0;
}