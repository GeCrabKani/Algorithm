public class Solution {
    public bool solution(int x) {
        string s = x.ToString();
        int sum = 0;
        for (int i = 0; i < s.Length; i++)
        {
            sum += s[i] - '0';
        }
        if (x % sum == 0)
            return true;
        else
            return false;
    }
} 