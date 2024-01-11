using System;
using System.Linq;

public class Solution {
    public int[] solution(int[] arr, int divisor) {
        int[] answer = arr.Where(x => x % divisor == 0).ToArray().OrderBy(x => x).ToArray();
        return answer.Count() > 0 ? answer : new[] {-1};
    }
}