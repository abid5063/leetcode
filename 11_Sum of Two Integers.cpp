class Solution {
public:
    int getSum(int a, int b) {
        while(b!=0){
            int a= a^b;
            b= a&b <<1;
        }
        return a;
        
    }
};