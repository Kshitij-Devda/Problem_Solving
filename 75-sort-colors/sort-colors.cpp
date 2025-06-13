class Solution {
public:


    void sortColors(vector<int>& nums) {
       int zer,one,two;
       zer=0;
       one=0;
       two=0;

       for(int i=0;i<nums.size();i++){
        if(nums[i]==0){
            zer++;
        }
        else if(nums[i]==1){
            one++;
        }
        else{
            two++;
        }
       }
       int i=0;

       while(zer--){
        nums[i]=0;
        i++;
       }
       while(one--){
        nums[i]=1;
        i++;
       }
       while(two--){
        nums[i]=2;
        i++;
       }
 

    }
};