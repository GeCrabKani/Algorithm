using System;

public class Solution {
    public int solution(string s) {
            string answer = s.Replace("zero", "0");
            answer = answer.Replace("one", "1");
            answer = answer.Replace("two", "2");
            answer = answer.Replace("three", "3");
            answer = answer.Replace("four", "4");
            answer = answer.Replace("five", "5");
            answer = answer.Replace("six", "6");
            answer = answer.Replace("seven", "7");
            answer = answer.Replace("eight", "8");
            answer = answer.Replace("nine", "9");

            return int.Parse(answer);
    }
}