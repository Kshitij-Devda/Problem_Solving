class Solution {
public:

vector<int> findans(vector<int>& arr, int k, int x){
    int l=0;
    int h=arr.size()-1;

    while(h-l>=k){
        if(x-arr[l]>arr[h]-x){
            l++;
        }
        else{
            h--;
        }
    }

    vector<int>ans;
    for(int i=l;i<=h;i++){
        ans.push_back(arr[i]);
    }
    return ans;
}
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {

        return findans(arr,k,x);
    
}
};
