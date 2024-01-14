public class Solution {
    public string solution(string s, int n) {
        char[] chars = new char[s.Length];
        for (int i = 0; i < s.Length; i++)
        {
            char ch = s[i];

            if (s[i] >= 'A' && s[i] <= 'Z')
            {
                if (s[i] + n > 'Z')
                    chars[i] = (char)(ch + n - 26);
                else
                    chars[i] = (char)(ch + n);
            }
            else if (s[i] >= 'a' && s[i] <= 'z')
            {
                if (s[i] + n > 'z')
                    chars[i] = (char)(ch + n - 26);
                else
                    chars[i] = (char)(ch + n);
            }
            else
            {
                chars[i] = s[i];
            }
        }
        return new string(chars);
    }
}