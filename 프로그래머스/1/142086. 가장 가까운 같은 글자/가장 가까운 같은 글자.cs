using System;
using System.Collections.Generic;

public class Solution {
    public int[] solution(string s) {
        List<int> answer = new List<int>();

        Dictionary<char, int> dic = new Dictionary<char, int>();

        for (int i = 0; i < s.Length; i++)
        {
            if (dic.ContainsKey(s[i]))
            {
                answer.Add(i - dic[s[i]]);
                dic.Remove(s[i]);
            }
            else
            {
                answer.Add(-1);
            }

            dic.Add(s[i], i);
        }

        return answer.ToArray();
    }
}