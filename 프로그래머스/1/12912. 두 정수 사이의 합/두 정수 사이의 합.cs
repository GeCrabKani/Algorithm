public class Solution {
    public long solution(int a, int b) {
        return b > a ? ((long)b * (b + 1) / 2) - ((long)a * (a - 1) / 2) : ((long)a * (a + 1) / 2) - ((long)b * (b - 1) / 2);
    }
}