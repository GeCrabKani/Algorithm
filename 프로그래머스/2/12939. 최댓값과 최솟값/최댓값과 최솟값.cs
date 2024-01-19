using System;
using System.Collections.Generic;

public class Solution {
    int compare(string s1, string s2)
    {
        if (s1.StartsWith("-") && !s2.StartsWith("-"))
        {
            return -1;
        }
        else if (!s1.StartsWith("-") && s2.StartsWith("-"))
        {
            return 1;
        }

        return int.Parse(s1).CompareTo(int.Parse(s2));
    }
    public string solution(string s) {
        string answer = "";
        List<string> list = new List<string>();
        string[] words = s.Split(new char[] { ' ' }, StringSplitOptions.RemoveEmptyEntries);
        list.AddRange(words);
        list.Sort(compare);
        answer += list[0];
        answer += " ";
        answer += list[list.Count - 1];
        return answer;
    }
}