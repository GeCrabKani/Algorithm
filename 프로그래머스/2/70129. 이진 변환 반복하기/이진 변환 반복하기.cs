using System;
using System.Collections.Generic;

public class Solution {
    private static string Binary(string n)
    {
        string answer = "";
        int len = n.Length;
        while (len > 0)
        {
            answer = (len % 2).ToString() + answer;
            len /= 2;
        }
        return answer;
    }
    
    public int[] solution(string s) {
        List<int> answer = new List<int>();
        int count = 0, removeZero = 0;
        while (s != "1")
        {
            string st = "";
            foreach (char c in s)
            {
                if (c == '1')
                {
                    st += c;
                }
                else
                {
                    removeZero++;
                }
            }
            s = Binary(st);
            count++;
        }
        answer.Add(count);
        answer.Add(removeZero);
        return answer.ToArray();
    }
}