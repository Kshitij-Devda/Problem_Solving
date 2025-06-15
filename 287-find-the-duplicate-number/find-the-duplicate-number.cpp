class Solution {
public:
    int findDuplicate(vector<int>& nums) {

       /* int n=nums.size();
        sort(nums.begin(),nums.end());
       
      
      for(int i=0;i<n;i++){
        
            if(nums[i]==nums[i+1]){
                return nums[i];
               

            }
           
           
            
        }
        return -1;
      }*/


      int ans;
      for(int i=0;i<nums.size();i++){

         int ind=abs (nums[i]);
        //already visted
        if(nums[ind]<0){
            ans=ind;
            break;
        }

        //visit mahi hua toh
         nums[ind]*=-1;
      }
      return ans;
      
        
    }
}
;