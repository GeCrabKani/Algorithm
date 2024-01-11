public class Solution {
    public int[] solution(int n, int m) {
        int[] answer = new int[2];
        int min, max;
        if (n > m)
        {
            min = m;
            max = n;
        }
        else
        {
            min = m;
            max = n;
        }
        for (int i = min; i > 0; i--)
        {
            if (n % i == 0 && m % i == 0)
            {
                answer[0] = i;
                break;
            }
        }
        for (int i = max; ; i += max)
        {
            if (i % n == 0 && i % m == 0)
            {
                answer[1] = i;
                break;
            }
        }
        return answer;
    }
}