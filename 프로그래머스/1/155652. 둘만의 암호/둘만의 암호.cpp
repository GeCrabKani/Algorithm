#include <string>
#include <vector>

using namespace std;

string solution(string s, string skip, int index) {
    string answer = "";
    string alphabet = { 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
    for (auto c : skip)
    {
        size_t pos = alphabet.find(c);
        if (pos != string::npos)
        {
            alphabet.erase(pos, 1);
        }
    }

    for (auto c : s)
    {
        size_t pos = alphabet.find(c);

        pos += index;

        pos %= alphabet.size();

        answer += alphabet[pos];
    }

    return answer;
}