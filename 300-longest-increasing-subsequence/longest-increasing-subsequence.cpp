class Solution {
public:
int t[2501][2501];
int solve(int ind,int p,vector<int>& nums){
    
     int n=nums.size();
    if(ind>=n) return 0;

    if(p!=-1 && t[ind][p]!=-1) return t[ind][p];

    int take=0;
    int skip=0;

    if((p==-1 )|| (nums[ind]>nums[p])){
        //take
         take=1+solve(ind+1,ind,nums);
    }
    //skip
     skip=solve(ind+1,p,nums);
     if(p!=-1)
    return t[ind][p]=max(take,skip);
     
     else
     return max(take,skip);
    
}
    int lengthOfLIS(vector<int>& nums) {
        memset(t,-1,sizeof(t));
       
        return solve(0,-1,nums);
        
    }
};