#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

int solution(vector<int> nums) {
    int isPrime[3000];
    fill_n(isPrime, 3000, 1);
    isPrime[0] = isPrime[1] = 0;

    for (int i = 2; i <= sqrt(3000); i++) {
        if (isPrime[i]) {
            for (int j = i * i; j < 3000; j += i) {
                isPrime[j] = 0;
            }
        }
    }
    int answer = 0;
    for (int i = 0; i < nums.size(); i++) {
        for (int j = i + 1; j < nums.size(); j++) {
            for (int k = j + 1; k < nums.size(); k++) {
                if (isPrime[nums[i] + nums[j] + nums[k]]) {
                    answer++;
                }
            }
        }
    }
    return answer;
}