class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int res = 0, maxTime = 0, sum = 0, n = neededTime.size();
        
        for (int i = 0; i < n; ++i) {
            if (i > 0 && colors[i] != colors[i - 1]) {
                res += sum - maxTime;
                sum = maxTime = 0;
            }
            sum += neededTime[i];
            maxTime = max(maxTime, neededTime[i]);
        }
        res += sum - maxTime;
        return res;
    }
};