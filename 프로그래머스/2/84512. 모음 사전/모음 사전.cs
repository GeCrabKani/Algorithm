using System;

public class Solution {
    public int solution(string word) {
        int answer = 0;
        for (int i = 0; i < word.Length; i++)
        {
            switch (word[i])
            {
                case 'A':
                    {
                        answer++;
                        break;
                    }
                case 'E':
                    {
                        if (i == 0) answer += 782;
                        else if (i == 1) answer += 157;
                        else if (i == 2) answer += 32;
                        else if (i == 3) answer += 7;
                        else answer += 2;
                        break;
                    }
                case 'I':
                    {
                        if (i == 0) answer += 1563;
                        else if (i == 1) answer += 313;
                        else if (i == 2) answer += 63;
                        else if (i == 3) answer += 13;
                        else answer += 3;
                        break;
                    }
                case 'O':
                    {
                        if (i == 0) answer += 2344;
                        else if (i == 1) answer += 469;
                        else if (i == 2) answer += 94;
                        else if (i == 3) answer += 19;
                        else answer += 4;
                        break;
                    }
                case 'U':
                    {
                        if (i == 0) answer += 3125;
                        else if (i == 1) answer += 625;
                        else if (i == 2) answer += 125;
                        else if (i == 3) answer += 25;
                        else answer += 5;
                        break;
                    }
            }
        }
        return answer;
    }
}