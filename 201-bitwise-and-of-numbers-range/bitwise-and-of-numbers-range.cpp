class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        int diff=right-left;
        int ans=0;
        for(int i=0;i<32;i++) {
            int b1=left&1<<i;
            int b2=right&1<<i;
            if(b1>0 && b2>0 && diff<b1) {ans=ans|b1;}
        }
        return ans;   
    }
};