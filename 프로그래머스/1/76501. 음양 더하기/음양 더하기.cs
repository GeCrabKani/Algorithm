using System;
using System.Linq;

public class Solution {
    public int solution(int[] absolutes, bool[] signs) {
        return absolutes.Select((x, i) => signs[i] ? x : -x).Sum();
    }
}