class Solution {
    unordered_set<string> st;
    int dp[10000][30][31];
    bool check(int idx, vector<string>& words, int i, int cnt)
    {
        if(idx==words[i].size())
        {
            if(cnt>1) return true;
            return false;
        }
        if(dp[i][idx][cnt]!=-1) return dp[i][idx][cnt];
        for(int k=idx; k<words[i].size(); k++)
        {
            string t=words[i].substr(idx, k-idx+1);
            if(st.find(t) != st.end() && check(k+1, words, i, cnt+1)) 
            {
                return dp[i][idx][cnt] = 1;
            }
        }
        return dp[i][idx][cnt] = 0;
    }
public:
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) 
    {
        int n=words.size();
        vector<string> ans;
        for(auto &w: words) st.insert(w);
        memset(dp, -1, sizeof(dp));
        for(int i=0; i<n; i++)
        {
            if(check(0, words, i, 0)) ans.push_back(words[i]);
        }  
        return ans;      
    }
};