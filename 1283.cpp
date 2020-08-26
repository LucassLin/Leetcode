/*
find the smallest divisor such that after division the sum of every number in the array is less than a threshold

easy binary search
*/

int smallestDivisor(vector<int>& nums, int threshold) {
        int l=1, r=1000000;       
        while(l<r){
            int mid = (l+r)/2;
            int sum = 0;
            for(int num : nums) sum += (num+mid-1)/mid;
            if(sum>threshold) l=mid+1;
            else r=mid;
        }
        return l;
    }