class Solution {
public:
bool isvowel(char ch){
  char c=tolower(ch);

  return c=='a'||c=='e'||c=='i'||c=='o'||c=='u';

}
    string reverseVowels(string s) {
        
        int l=0;
        int h=s.size()-1;

        while(l<h){
            if(isvowel(s[l]) && isvowel(s[h])){
                swap(s[l],s[h]);
                l++;
                h--;
            }
            else if(!isvowel(s[l])){
                l++;
            }
            else{
                h--;
            }
        }
        return s;
    }
};