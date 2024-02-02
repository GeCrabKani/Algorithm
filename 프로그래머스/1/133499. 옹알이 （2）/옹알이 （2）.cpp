#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<string> babblings) {
    vector<string> validSounds = {"aya", "ye", "woo", "ma"};
    int answer = 0;

    for (string& word : babblings) {
        bool isValid = true;
        string lastSound = "";
        for (size_t i = 0; i < word.length() && isValid;) {
            bool found = false;
            for (const string& sound : validSounds) {
                if (word.substr(i, sound.length()) == sound) {
                    if (sound == lastSound) {
                        isValid = false;
                        break;
                    }
                    lastSound = sound;
                    i += sound.length();
                    found = true;
                    break;
                }
            }
            if (!found) {
                isValid = false;
                break;
            }
        }
        if (isValid) {
            answer++;
        }
    }

    return answer;
}
