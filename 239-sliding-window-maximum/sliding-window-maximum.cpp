class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int>dq;
        vector<int>ans;

        //process first window
        
        for(int i=0;i<k;i++){
            int element=nums[i];

            //jo bhi elemet raahega usko queue me jaayenga hi amd faltu elements ko pop bhi krdo
            
            while(!dq.empty() && nums[dq.back()]<element){
                dq.pop_back();
            }

            dq.push_back(i);

        }

        //ans me and store kr do abh
        int index=dq.front();
        int elem=nums[index];
        ans.push_back(elem);


        //process next windows

        for(int i=k;i<nums.size();i++){
            // removal

            if(!dq.empty() && dq.front()<i-k+1){
                dq.pop_front();
            }

            //addition

            int element= nums[i];
             while(!dq.empty() && nums[dq.back()]<element){
                dq.pop_back();
            }

            dq.push_back(i);

            //ans me store

        int index=dq.front();
        int elem=nums[index];
        ans.push_back(elem);

        
   
        
    }
    return ans;
}
};