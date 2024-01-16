using System.Linq;
using System;
using System.Collections.Generic;

public class Solution {
    public int[] solution(int[] array, int[,] commands) {
        int[] answer = new int[commands.GetLength(0)];

        for (int i = 0; i < commands.GetLength(0); i++)
        {
           int j = commands[i, 0];
           int k = commands[i, 1];
           int l = commands[i, 2];

           List<int> temp = new List<int>();
           temp = array.Skip(j - 1).Take(k - j + 1).ToList();
           temp.Sort();
           answer[i] = temp[l - 1];
        }
        return answer;
    }
}