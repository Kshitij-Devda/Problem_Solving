class Solution {
public:
    string decodeString(string s) {
         string s1;
         stack<char>st;
         for(auto u:s){
            if(!st.empty()&&u==']'){
                string s2;
                while(st.top()!='['){
                    cout<<st.top();
                    s2+=st.top();
                    st.pop();
                }
                st.pop();
                string s5;
                while(!st.empty()){
                    if(st.top()>='a'&&st.top()<='z'){
                        break;
                    }
                    if(st.top()=='['){
                        break;
                    }
                    s5+=st.top();
                    st.pop();
                }
                reverse(s5.begin(),s5.end());
                int k=stoi(s5);
                reverse(s2.begin(),s2.end());
                string s3=s2;
                string s4;
                for(int j=1;j<=k;j++){
                    s4+=s3;
                }
                for(auto u:s4){
                    st.push(u);
                }
            }
            else{
                st.push(u);
            }
         }
         while(!st.empty()){
             s1+=st.top();
             st.pop();
         }
         reverse(s1.begin(),s1.end());
         return s1;
    }
};