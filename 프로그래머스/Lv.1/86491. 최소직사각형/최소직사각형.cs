using System;

public class Solution {
    public int solution(int[,] sizes) {
        int maxWidth = 0;
        int maxHeight = 0;

        for (int i = 0; i < sizes.GetLength(0); i++) {
            int w = Math.Max(sizes[i, 0], sizes[i, 1]);
            int h = Math.Min(sizes[i, 0], sizes[i, 1]);

            maxWidth = Math.Max(maxWidth, w);
            maxHeight = Math.Max(maxHeight, h);
        }

        return maxWidth * maxHeight;
    }
}