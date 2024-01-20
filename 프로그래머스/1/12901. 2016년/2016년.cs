public class Solution {
    public string solution(int a, int b) {
        string[] day = { "SUN", "MON", "TUE", "WED", "THU", "FRI", "SAT" };
        string answer = "";
        switch (a)
        {
            case 1:
                {
                    answer = day[(4 + b) % 7];
                    break;
                }
            case 2:
                {
                    answer = day[(35 + b) % 7];
                    break;
                }
            case 3:
                {
                    answer = day[(64 + b) % 7];
                    break;
                }
            case 4:
                {
                    answer = day[(95 + b) % 7];
                    break;
                }
            case 5:
                {
                    answer = day[(125 + b) % 7];
                    break;
                }
            case 6:
                {
                    answer = day[(156 + b) % 7];
                    break;
                }
            case 7:
                {
                    answer = day[(186 + b) % 7];
                    break;
                }
            case 8:
                {
                    answer = day[(217 + b) % 7];
                    break;
                }
            case 9:
                {
                    answer = day[(248 + b) % 7];
                    break;
                }
            case 10:
                {
                    answer = day[(278 + b) % 7];
                    break;
                }
            case 11:
                {
                    answer = day[(309 + b) % 7];
                    break;
                }
            case 12:
                {
                    answer = day[(339 + b) % 7];
                    break;
                }
        }
        return answer;
    }
}