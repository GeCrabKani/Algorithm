#include <iostream>

using namespace std;

int solution(int n, int a, int b)
{
    int answer = 1;
    if (a > b)
    {
        int temp = a;
        a = b;
        b = temp;
    }
    while (true)
    {
        if (b - a == 1 && b % 2 == 0)
            return answer;
        else
        {
            a++;
            b++;
            a /= 2;
            b /= 2;
            answer++;
        }
    }
}