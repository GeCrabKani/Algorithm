using System;
using System.Linq;

public class Solution {
    public int[] solution(int[] arr) {
        if (arr.Length == 1) return new[] { -1 };

        int[] answer = new int[arr.Length - 1];
        int min = arr.Min();
        int answerIndex = 0;
        for (int i = 0; i < arr.Length; i++)
            if (arr[i] != min)
            {
                answer[answerIndex] = arr[i];
                answerIndex++;
            }
                
        return answer;
    }
}