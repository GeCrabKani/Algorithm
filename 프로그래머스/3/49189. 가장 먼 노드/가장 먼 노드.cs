using System;
using System.Collections.Generic;
using System.Linq;

public class Solution {
    static List<int>[] edgeList = new List<int>[20001];
    static int[] dist = new int[20001];

    static void bfs(int start)
    {
        Queue<int> q = new Queue<int>();
        q.Enqueue(start);
        dist[start] = 0;
        while (q.Count() > 0)
        {
            int cur = q.Dequeue();
            foreach(int next in edgeList[cur])
            {
                if (dist[next] == -1)
                {
                    dist[next] = dist[cur] + 1;
                    q.Enqueue(next);
                }
            }
        }
    }
    public int solution(int n, int[,] edge) {
        for (int i = 0; i <= 20000; i++)
        {
            edgeList[i] = new List<int>();
        }

        for (int i = 0; i < edge.GetLength(0); i++)
        {
            edgeList[edge[i, 0]].Add(edge[i, 1]);
            edgeList[edge[i, 1]].Add(edge[i, 0]);
        }
        Array.Fill(dist, -1);
        bfs(1);
        Array.Sort(dist);
        int cnt = 0;
        for (int i = 20000; i >= 0; i--)
        {
            if (dist[i] != dist[20000]) break;
            cnt++;
        }
        return cnt;
    }
}