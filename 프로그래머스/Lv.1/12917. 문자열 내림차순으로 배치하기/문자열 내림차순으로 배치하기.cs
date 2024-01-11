using System;
using System.Linq;

public class Solution {
    public string solution(string s) {
        char[] chars = s.ToCharArray();
        var sortedChars = chars.OrderByDescending(x => x);
        return string.Concat(sortedChars);
    }
}