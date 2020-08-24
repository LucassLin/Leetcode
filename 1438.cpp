/*
use deque to keep track of max or min number from range(i, j)
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