using System;
using System.Collections.Generic;

public class Solution {
    public string[] solution(string[] players, string[] callings) {
        Dictionary<string, int> dic = new Dictionary<string, int>();    
        for (int i = 1; i <= players.Length; i++)
        {
            dic.Add(players[i - 1], i);
        }
        for (int i = 0; i < callings.Length; i++) {
            if (dic.ContainsKey(callings[i]))
            {
                int index = dic[callings[i]];
                string temp = players[index - 1];
                players[index - 1] = players[index - 2];
                players[index - 2] = temp;

                dic[callings[i]]--;
                dic[players[index - 1]]++;
            }
        }
        return players;
    }
}