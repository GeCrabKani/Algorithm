using System;
using System.Collections.Generic;
using System.Linq;

public class Solution {
    public int solution(int[] citations) {
        List<int> list = citations.ToList();
        list.Sort();
        int hIndex = 0;
        int size = list.Count;
        for (int i = 0; i < size; i++)
        {
            if (list[i] >= size - i)
            {
                hIndex = size - i;
                break;
            }    
        }
        return hIndex;
    }
}