class Solution {
public:

  int solve(int n,vector<int>&t){
    if(n<0)return 0;

    if(n==0)return 1;

    if(t[n]!=-1) return t[n];

    int onestep=solve(n-1,t);
    int twostep=solve(n-2,t);

    return t[n]=onestep+twostep;

  }
    int climbStairs(int n) {

        vector<int>t(46,-1);

        return solve(n,t);
        
    }
};