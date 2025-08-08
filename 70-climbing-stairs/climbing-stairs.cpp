class Solution {
public:

  /*int solve(int n,vector<int>&t){
    if(n<0)return 0;

    if(n==0)return 1;

    if(t[n]!=-1) return t[n];

    int onestep=solve(n-1,t);
    int twostep=solve(n-2,t);

    return t[n]=onestep+twostep;

  }*/
    int climbStairs(int n) {

        if(n==1 || n==2) return n;

        vector<int>t(n+1);
        t[0]=0;
        t[1]=1;
        t[2]=2;

        for(int i=3;i<=n;i++){
            t[i]=t[i-1]+t[i-2];
        }

        return t[n];

        
        
    }
};