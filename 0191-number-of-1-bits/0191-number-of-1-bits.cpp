class Solution {
public:
    int hammingWeight(int n) {
        int count = 0;
        while(n>0){
            int remainder = n%2;
            if(remainder)
                count++;
            n/=2;
        }
        return count;
    }
};