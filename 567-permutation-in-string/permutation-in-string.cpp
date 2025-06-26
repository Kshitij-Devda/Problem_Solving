class Solution {
    private:
    bool checkequal(int a[26],int b[26]){
        for(int i=0;i<26;i++){
            if(a[i]!=b[i])
            return 0;
        }
        return 1;
    }
public:
    bool checkInclusion(string s1, string s2) {

        int count1[26]={0};
         //s1 ka count array create kr lene ka
        for(int i=0;i<s1.length();i++){
            int index=s1[i]-'a';
            count1[index]++;
        }

        //s2 me s1 ki window banake traverse krenege

        int i=0;
        int count2[26]={0};
        int window=s1.length();

        //first window process krdo
        while((i<s2.length()) && (i<window)){
            int in=s2[i]-'a';

            count2[in]++;
            i++;
        }
        if( checkequal(count1,count2)){
            return 1;
        }

        //aage ki window process karo
        while(i<s2.length()){
            char newch =s2[i];
            int index=newch-'a';
            count2[index]++;

            char old=s2[i-window];
            int in=old-'a';
            count2[in]--;

            i++;



           if( checkequal(count1,count2))
           return 1;


        }
        return 0;




       
    }
};
