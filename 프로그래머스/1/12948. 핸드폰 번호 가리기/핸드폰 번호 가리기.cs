using System;
using System.Linq;

public class Solution {
    public string solution(string phone_number) {
        char[] chars = phone_number.ToCharArray();
        var masked = chars.Select((x, i) => i < chars.Length - 4 ? '*' : x);
        return string.Concat(masked);
    }
}