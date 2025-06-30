class Solution {
public:
    int myAtoi(string s) 
    {
        int num=0,i=0;
        int sign=1;
        //leading space hatao
        while(s[i]==' '){
            i++;


        }
        //for sign
        if(i<s.size() && (s[i]=='+'||s[i]=='-')){
            sign=s[i]=='+'?1:-1;
            i++;
        }

        //for number
        while(i<s.size() && isdigit(s[i])){
            int digit=s[i]-'0';

          if(num>INT_MAX/10 || (num==INT_MAX/10 && s[i]>'7')){
            return sign==-1?INT_MIN:INT_MAX;
          }

            num=num*10 + digit;
            i++;
        }
      

          return num*sign;       


        
    }
};