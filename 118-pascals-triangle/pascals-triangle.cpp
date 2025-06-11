class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>>ans;
        ans.push_back({1});
        if(numRows==1){
            return ans;
        }
        vector<int>row1={1,1};
        ans.push_back({1,1});
        for(int i=1;i<numRows-1;i++){
            vector<int>row2={1};
            for(int j=0;j<row1.size()-1;j++){
                row2.push_back(row1[j]+row1[j+1]);
            }
            row2.push_back(1);
            ans.push_back(row2);
            row1=row2;
        }
        return ans;
    }
};