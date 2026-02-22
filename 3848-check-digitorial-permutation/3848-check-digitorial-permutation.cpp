class Solution {
public:
    // bool isDigitorialPermutation(int n) {
    //     vector<int>fact(10, 0);
    //     fact[0] = 1;
    //     for(int i=1; i<=9; i++)
    //         fact[i] = fact[i-1] * i;

    //     int temp = n, sum = 0;
    //     while(temp) {
    //         sum += fact[temp % 10];
    //         temp /= 10;
    //     }
    //     string s1 = to_string(sum), s2= to_string(n);
    //     sort(s1.begin(), s1.end());
    //     sort(s2.begin(), s2.end());
    //     return s1 == s2;
    // }
    bool isDigitorialPermutation(int n) {
        int temp = n, maxElement = 0;
        unordered_map<int, int> numbers;
        while (temp > 0) {
            int num = temp % 10;
            numbers[num]+=1;
            temp = temp / 10;
            maxElement = max(maxElement, num);
        }
        
        int prev = 1, curr, sum = 0;
        for (int num = 1; num <= maxElement; num++) {
            curr = prev * num;
            
            if(numbers.find(num)!=numbers.end()){
                sum += curr * numbers[num];
            }
            prev = curr;
        }
        sum+=numbers[0];
        // get freq of sum be reduced from numbers andd if any freq value remain then false else true
        temp = sum;
        while (temp > 0) {
            int num = temp % 10;
            numbers[num]-=1;
            temp = temp / 10;
        }
        for(auto& entry: numbers){
            if(entry.second != 0) return false;
        }
        return true;
    }
};