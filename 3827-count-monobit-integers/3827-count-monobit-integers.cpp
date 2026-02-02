class Solution {
public:
    int countMonobit(int n) {
        if (n <= 1)
            return n + 1;
        int monobits = 0, num = 1;
        while (num <= n) {
            num = num << 1;
            num = num ^ 1;
            monobits++;
        }
        return monobits+1;
    }
};