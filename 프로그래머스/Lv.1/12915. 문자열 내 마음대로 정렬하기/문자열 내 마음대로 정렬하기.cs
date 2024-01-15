using System.Linq;
using System;

public class Solution {
    public string[] solution(string[] strings, int n) {
            string[] answer = strings.OrderBy(x => x).ToArray();
            answer = answer.OrderBy(x => x[n]).ToArray();

            return answer;
    }
}