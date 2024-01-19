using System;

public class Solution {
    static int ans = 0;
    static int[] arr = new int[12];

    static bool check(int level)
    {
        for (int i = 0; i < level; i++)
        {
            if (arr[i] == arr[level] || Math.Abs(arr[i] - arr[level]) == level - i) return false;
        }
        return true;
    }
    
    static void nqueen(int n, int num)
    {
        if (num == n) ans++;
        else
        {
            for (int i = 0; i < n; i++)
            {
                arr[num] = i;
                if (check(num)) nqueen(n, num + 1);
            }
        }
    }
    
    public int solution(int n) {
        nqueen(n, 0);
        return ans;
    }
}