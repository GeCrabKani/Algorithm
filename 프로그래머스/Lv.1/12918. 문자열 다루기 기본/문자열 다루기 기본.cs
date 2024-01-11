public class Solution {
    public bool solution(string s) {
        if (s.Length != 4 && s.Length != 6) return false;
        for (int i = 0; i < s.Length; i++)
            if (!char.IsDigit(s[i])) return false;
        return true;
    }
}