public class Solution {
    public int[,] solution(int[,] arr1, int[,] arr2) {
            int[,] answer = (int[,])arr1.Clone();
            for (int i = 0; i < arr1.GetLength(0); i++)
                for (int j = 0; j < arr1.GetLength(1); j++)
                    answer[i, j] += arr2[i, j];
            return answer;
    }
}