class Solution {

public:
    int climbStairs(int n) {
        int first = 1, second = 2, third;
        if(n<=2) return n;
        for(int i = 3; i<=n; i++){
            third = first + second;
            first = second;
            second = third;
        } 
        return second;
    }
};