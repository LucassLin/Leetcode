/*
need to find longest subarray with absolute diff between any elements in this subarray less than a number-limit ->
find longest subarray with min and max diff less than minute ->
keep track of min and max for sliding window ->
1. use two priority queue, max queue for tracking imax, min queue for tracking imin. NlgN
2. use deque to keep track of min and max number, O(N)
*/

int longestSubarray(vector<int>& nums, int limit) {
        deque<int> maxq, minq;
        int i=0, j=0, res=0;
        for(; j<nums.size(); ++j){
            while(!maxq.empty() && nums[j]>maxq.back()) maxq.pop_back();
            while(!minq.empty() && nums[j]<minq.back()) minq.pop_back();
            maxq.push_back(nums[j]);
            minq.push_back(nums[j]);
            while(maxq.front()-minq.front()>limit){
                if(maxq.front() == nums[i]) maxq.pop_front();
                if(minq.front() == nums[i]) minq.pop_front();
                i++;
            }
            res = max(res, j-i+1);
        }
        return res;
    }