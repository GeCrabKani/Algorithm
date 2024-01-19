using System;
using System.Collections.Generic;
using System.Linq;

public class Solution {
    public int[] solution(int k, int[] score) {
        int[] answer = new int[score.Length];
        List<int> list = new List<int>();

        for (int i = 0; i < score.Length; i++) {
            list.Add(score[i]);

            if (list.Count > k) {
                list.Remove(list.Min());
            }

            list.Sort();
            answer[i] = list[0];
        }

        return answer;
    }
}