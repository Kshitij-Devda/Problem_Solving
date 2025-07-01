class Solution {
public:
    string convert(string s, int numrow) {

        if(numrow==1)return s;

        int i=0,row=0;
        bool dir=1;//T->B

        vector<string> zigzag(numrow);

        while(true){

            if(dir){
                while(row<numrow && i<s.size()){
                    zigzag[row++].push_back(s[i++]);

                }
                row=numrow-2;
            }
            else{
                while(row>=0 && i<s.size()){
                    zigzag[row--].push_back(s[i++]);
                }
                row=1;
            }
              if(i>=s.size()){
                break;
              }
            dir=!dir;
        }
            string ans="";
        for(int i=0;i<zigzag.size();i++){

             ans=ans+zigzag[i];
        }

        return ans;
      

    }
};