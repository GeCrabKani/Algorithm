public class Solution {
    public string solution(string s) {
        string answer = "";
        for (int i = 0, j = 0; i < s.Length; i++, j++)
        {
            if (s[i] == ' ')
            {
                j = -1;
                answer += " ";
            }
            else if (j % 2 == 1)
            {
                answer += char.ToLower(s[i]);
            }
            else
            {
                answer += char.ToUpper(s[i]);
            }
        }
        return answer;
    }
}