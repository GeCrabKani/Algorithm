#include <string>
#include <vector>
#include <unordered_set>

using namespace std;

int solution(vector<int> elements) {
    unordered_set<int> uniqueSums;
    int n = elements.size();

    for (int i = 0; i < n; ++i) { // 시작 인덱스
        int sum = 0;
        for (int length = 1; length <= n; ++length) { // 부분 배열의 길이
            sum += elements[(i + length - 1) % n];
            uniqueSums.insert(sum);
        }
    }

    return uniqueSums.size();
}
