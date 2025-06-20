class Solution {
public:
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        //vector to store median        
        vector<double> median;
        //map to delete the elements that are to be removed from sliding window 
        unordered_map<int,int> mp;
        //to store the element in heap in descending order
        priority_queue<int> maxHeap;
        //to store the element in heap in ascending order
        priority_queue<int, vector<int>, greater<int>> minHeap;

        //first insert the element upto the size of window in maxHeap
        for(int i=0;i<k;i++)
        {
            maxHeap.push(nums[i]);
        }

        //Now to balance the size of maxHeap and minHeap, insert half elements in minHeap
        for(int i=0; i<k/2; i++)
        {
            minHeap.push(maxHeap.top());
            maxHeap.pop();
        }

        //for rest of the elements
        for(int i=k; i<nums.size(); i++)
        {

            if(k%2 != 0) //if k is odd
                median.push_back(maxHeap.top()*1.0);
            else  // if k is even
                median.push_back((maxHeap.top()*1.0 + minHeap.top()*1.0)/2);

            //to remove previous element from sliding window and inserting new element and checking the balance of maxHeap and minHeap
            int p = nums[i-k], q = nums[i], balance = 0;

            //if p is present in maxHeap
            if(p <= maxHeap.top())
            {
                balance--;
                if(p == maxHeap.top())
                {
                    maxHeap.pop();
                }
                else
                {
                    mp[p]++;
                }
            }
            else  //if p is present in minHeap
            {
                balance++;
                if(p == minHeap.top())
                {
                    minHeap.pop();
                }
                else
                {
                    mp[p]++;
                }
            }

            //to insert q in maxHeap when q is smaller than top of the maxHeap
            if(!maxHeap.empty() && q<=maxHeap.top())
            {
                maxHeap.push(q);
                balance++;
            }
            else  //if q is greater the top of maxHeap then insert it into minHeap
            {
                minHeap.push(q);
                balance--;
            }
            
            //if balance > 0
            if(balance > 0)
            {
                minHeap.push(maxHeap.top());
                maxHeap.pop();
            }   //if balance < 0
            else if(balance < 0)
            {
                maxHeap.push(minHeap.top());
                minHeap.pop();
            }

            //to delete last element present in heap and for that map is used
            while(!maxHeap.empty() && mp[maxHeap.top()])
            {
                mp[maxHeap.top()]--;
                maxHeap.pop();
            }
            while(!minHeap.empty() && mp[minHeap.top()])
            {
                mp[minHeap.top()]--;
                minHeap.pop();
            }
        }
        if(k%2 != 0)
            median.push_back(maxHeap.top()*1.0);
        else 
            median.push_back((maxHeap.top()*1.0 + minHeap.top()*1.0)/2);
        return median;
    }
};