class Solution {
public:
    int countMonobit(int n) {
        int monobits = 0, num = 1;
        while (num <= n) {
            num = num << 1;
            num = num ^ 1;
            monobits++;
        }
        return monobits+1;
    }
};