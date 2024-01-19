using System;

public class Solution {
    public long solution(int n, int[] times) {
        Array.Sort(times);
        long left = 1;
        long right = (long)times[times.Length - 1] * n;
        long mid;
        long answer = right;
        while (left <= right)
        {
            mid = (left + right) / 2;
            long people = 0;
            for (int i = 0; i < times.Length; i++)
            {
                people += mid / times[i];
            }
            if (people >= n)
            {
                if (mid < answer)
                {
                    answer = mid;
                }
                right = mid - 1;
            }
            else
            {
                left = mid + 1;
            }
        }
        return answer;
    }
}