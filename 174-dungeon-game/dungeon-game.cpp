class Solution {
public:
    vector<pair<int,int>>moves = {{0,1},{1,0}};
    vector<vector<unordered_map<int,bool>>>dp;
    bool solve(int i,int j, int current,vector<vector<int>>& dungeon){
        if(current<=0) return false;
        if(i==dungeon.size()-1 && j==dungeon[0].size()-1){
            current+=dungeon[i][j];
            if(current>0) return true;
            return false;
        }
        if(dp[i][j].find(current)!=dp[i][j].end()) return dp[i][j][current];
        bool ans = false;
        for(auto& move:moves){
            int ni = i+move.first;
            int nj = j+move.second;
            if(ni>=0 && ni<dungeon.size() && nj>=0 && nj<dungeon[0].size()){
                ans|=solve(ni,nj,current+dungeon[i][j],dungeon);
                if(ans) break;
            }
        }
        return dp[i][j][current] =  ans;
    }
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int rows = dungeon.size(),cols = dungeon[0].size();
        int left = 1,right = INT_MAX;
        dp.resize(rows,vector<unordered_map<int,bool>>(cols));
        while(left<right){
            int mid = left+(right-left)/2;
            if(solve(0,0,mid,dungeon)) right = mid;
            else left = mid+1;
        }
        return left;
    }
};