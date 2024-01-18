using System;

public class Solution {
    public int solution(int a, int b, int n) {
        int answer = 0;
        while (n >= a)
        {
            answer += n / a * b;
            int temp = n % a;
            n /= a;
            n *= b;
            n += temp;
        }
        return answer;
    }
}