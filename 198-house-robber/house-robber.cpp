/*class Solution {
public:
int solve(vector<int>& nums,int i,int n,vector<int>&t){
    if(i>=n)return 0;
    if(t[i]!=-1) return t[i];

    int steal=nums[i]+solve(nums,i+2,n,t);
    int skip=solve(nums,i+1,n,t);

    return t[i]= max(steal,skip);
}
    int rob(vector<int>& nums) {
        vector<int>t(101,-1);
        int n=nums.size();
      return solve(nums,0,n,t);
        
    }
};*/



class Solution {
public:

    int rob(vector<int>& nums) {
        int n=nums.size();

        if(n==0 ) return 0;

        if(n==1) return nums[0];
        
        
        vector<int>t(n+1,0);

      //t[i] mtlb ith house tk kitna money stole kra hai

      t[0]=0;
      t[1]=nums[0];

      for(int i=2;i<=n;i++){
        int steal=nums[i-1]+t[i-2];
        int skip=t[i-1];

        t[i]=max(steal,skip);
      }

      return t[n];



        
    }
};