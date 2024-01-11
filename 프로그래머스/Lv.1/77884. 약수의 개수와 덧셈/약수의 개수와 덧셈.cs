using System;

public class Solution {
    public int isodd(int n) {
        int count = 2;
        for (int i = 2; i <= n / 2; i++) {
            if (n % i == 0) count++;
        }
        if (n == 1) count--;
        return count % 2;
    }
    
    public int solution(int left, int right) {
        int answer = 0;
        for(int i = left; i <= right; i++) {
            if (isodd(i) == 1) {
                answer -= i;
            } else {
                answer += i;
            }
        }
        return answer;
    }
}