using System;
using System.Linq;

public class Solution {
    public int solution(int n) {
        if (n == 0) return 0;
        int answer = 0;
        string s = "";
        while (n > 3)
        {
            s += (n % 3).ToString();
            n /= 3;
        }
        if (n == 1)
        {
            s += "1";
        }
        else if (n == 2)
        {
            s += "2";
        }
        else
        {
            s += "01";
        }
        var result = s.Reverse();
        s = string.Concat(result);
        for (int i = 0; i < s.Length; i++)
        {
            answer += (s[i] - '0') * (int)Math.Pow(3, i);
        }
        return answer;
    }
}