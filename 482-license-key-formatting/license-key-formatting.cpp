class Solution {
public:
  string licenseKeyFormatting(string s, int k) {
    string answer;

    for( int i = s.size() - 1; i >= 0;){
      for(int j = 0;i >= 0 && j != k; j++, i--)
        if(s[i] == '-') j--;
        else {
          if(s[i] > 96) s[i] -= 32;
          answer.push_back(s[i]);
        }
      while(i >= 0 && s[i] == '-') i--;
      if(i != -1) answer.push_back('-');
    }
    
    reverse(answer.begin(),answer.end());
    return answer;
  }
};