class Solution {
public:
    string reorganizeString(string s) {

          int hash[26]={0};

          //sbse pehele count krlo
          for(int i=0;i<s.size();i++){
            int in=s[i]-'a';
            hash[in]++;
          }

          //max_fre_chr nikal le
          int max_freq=INT_MIN;
          char max_freq_char;

          for(int i=0;i<26;i++){
            if(hash[i]>max_freq){
                max_freq=hash[i];
                max_freq_char=i+'a';

            }
          }

          int index=0;
          //pace krna padhega
          while(max_freq>0 && index<s.size()){
            s[index]=max_freq_char;
            max_freq--;
            index+=2;
          }

          while(max_freq!=0){
            return "";
          }

          hash[max_freq_char-'a']=0;

          for(int i=0;i<26;i++){
            while(hash[i]>0){
                if(index>=s.size()){
                    index=1;
                }
                s[index]=i+'a';
                hash[i]--;
                index+=2;
            }
          }

          return s;
        
    }
};