using System;
using System.Collections.Generic;

public class Solution {
    public int[] solution(int[] numbers) {
        List<int> ints = new List<int>();
        for (int i = 0; i < numbers.Length - 1; i++)
        {
            for (int j = i + 1; j < numbers.Length; j++)
            {
                if (!ints.Contains(numbers[i] + numbers[j]))
                    ints.Add(numbers[i] + numbers[j]);
            }
        }
        ints.Sort();

        return ints.ToArray();
    }
}