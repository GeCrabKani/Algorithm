using System;

public class Solution {
    static int[,] answer;
    static int index = 0;

    static void hanoi(long a, int b, int c)
    {
        if (a != 0)
        {
            hanoi(a - 1, b, 6 - b - c);
            answer[index, 0] = b;
            answer[index++, 1] = c;
            hanoi(a - 1, 6 - b - c, c);
        }
    }
    public int[,] solution(int n) {
        answer = new int[(int)Math.Pow(2, n) - 1, 2];
        hanoi(n, 1, 3);
        return answer;
    }
}