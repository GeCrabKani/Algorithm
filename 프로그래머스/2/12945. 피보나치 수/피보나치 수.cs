public class Solution {
    int[] arr = new int[100001];
    
    void fibo(int n)
    {
        for (int i = 2; i <= n; i++)
        {
            arr[i] = arr[i - 1] % 1234567 + arr[i - 2] % 1234567;
            arr[i] %= 1234567;
        }
    }
    
    public int solution(int n) {
        int answer = 0;
        arr[0] = 0;
        arr[1] = 1;
        fibo(n);
        answer = arr[n];
        return answer;
    }
}