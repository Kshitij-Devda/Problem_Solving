class Solution {
public:
   void maxprofitfinder(vector<int>& prices,int i,int &minprice,int &maxprofit){
         
        //base case
        if(i==prices.size()){
            return;
        }

         //ek case apn solve krte
         if(prices[i]<minprice){
            minprice=prices[i];
         }
         int todayprofit= prices[i]-minprice;

         if(todayprofit>maxprofit){
            maxprofit=todayprofit;
         }

         maxprofitfinder(prices,i+1,minprice,maxprofit);
   }
int maxProfit(vector<int>& prices) {
       int minprice=INT_MAX;
       int maxprofit=0;
       maxprofitfinder(prices,0,minprice,maxprofit);
       return maxprofit;
    }
};