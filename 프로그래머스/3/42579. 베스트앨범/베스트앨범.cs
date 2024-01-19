using System.Linq;
using System;
using System.Collections.Generic;

public class Solution {
    public int[] solution(string[] genres, int[] plays) {
        var answer = new List<int>();
        var music = new Dictionary<string, List<KeyValuePair<int, int>>>();
        var musicSum = new Dictionary<string, int>();

        for (int i = 0; i < genres.Length; i++)
        {
            if (!music.ContainsKey(genres[i]))
            {
                music[genres[i]] = new List<KeyValuePair<int, int>>();
            }
            music[genres[i]].Add(new KeyValuePair<int, int>(plays[i], i));
            if (!musicSum.ContainsKey(genres[i]))
            {
                musicSum[genres[i]] = 0;
            }
            musicSum[genres[i]] += plays[i];
        }

        var musicSumArr = musicSum.ToList();
        musicSumArr.Sort((a, b) => b.Value.CompareTo(a.Value));

        foreach (var m in musicSumArr)
        {
            var genreList = music[m.Key];
            genreList.Sort((a, b) => {
                if (a.Key == b.Key) return a.Value.CompareTo(b.Value);
                else return b.Key.CompareTo(a.Key);
            });

            answer.Add(genreList[0].Value);
            if (genreList.Count > 1)
            {
                answer.Add(genreList[1].Value);
            }
        }
        return answer.ToArray();
    }
}