class Solution {
public:

int findans(vector<int>& nums,int &n){
    int an;
    for(int i=0;i<n;i++){
        if(i!=nums[i]){
             an= i;
            break;
        }
    }
    return an;
}

 int missingNumber(vector<int>& nums){
    
        sort(nums.begin(),nums.end());
        int n=nums.size();
       int ans =findans(nums,n);
       return ans;

    }

};