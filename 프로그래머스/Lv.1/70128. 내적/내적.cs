using System;
using System.Linq;

public class Solution {
    public int solution(int[] a, int[] b) {
        int answer = a.Zip(b, (x, y) => x * y).Sum();
        return answer;
    }
}