class Solution {
public:

/*double bruteforce(vector<int>& nums, int & k){
    int i=0,j=k-1;
    int maxsum=INT_MIN;

    while(j<nums.size()){
        int sum=0;
        for(int y=i;y<=j;y++){
            sum=sum+nums[y];
        }
        maxsum=max(sum,maxsum);
        i++;
        j++;
    }

    return maxsum/(double)k;

}*/

double slidingwindow(vector<int>& nums, int &k){
    int i=0,j=k-1;
    int sum=0;

    for(int y=i;y<=j;y++){
        sum+=nums[y];
    }
    int maxsum=sum;
    j++;

    while(j<nums.size()){
        sum=sum-nums[i];
        sum=sum+nums[j];
        i++;
        j++;
        maxsum=max(maxsum,sum);

    }

    return maxsum/double(k);
    
}
double findMaxAverage(vector<int>& nums, int k){
    return slidingwindow(nums,k);
        
    }
};