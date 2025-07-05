class Solution {
public:

     void removeocc(string &s, string &part){
           int found=s.find(part);

           if(found != string::npos){
               string l=s.substr(0,found);
               string r=s.substr(found+part.size(),s.size());

               s=l+r;

               removeocc(s,part);

           }
           //base case
           else{
            return;
           }
     }
    string removeOccurrences(string s, string part) {

        removeocc(s,part);
        return s;

       

        
    }
};