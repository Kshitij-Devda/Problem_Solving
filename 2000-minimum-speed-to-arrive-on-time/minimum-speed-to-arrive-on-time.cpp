class Solution {
public:
    bool getSpeed(vector<int>&dist,double &hour,int speed){
        int n = dist.size();
        double time = 0.0;

        for(int i=0;i<n-1;i++){
            time += ceil((double) dist[i]/(double) speed);
        }

        time += (double)dist[n-1]/(double) speed;
        return time <= hour;
    }
    int minSpeedOnTime(vector<int>& dist, double hour) {
        int low = 1;
        int high = 1e7;
        int ans = -1;

        while(low <= high){
            int mid = low + (high-low)/2;

            if(getSpeed(dist,hour,mid)){
                ans = mid;
                high = mid-1;
            } else{
                low = mid+1;
            }
        }
        return ans;
    }
};