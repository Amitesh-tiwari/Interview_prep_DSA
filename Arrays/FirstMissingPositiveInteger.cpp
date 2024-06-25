Given an unsorted integer array nums. 
Return the smallest positive integer that is not 
present in nums.

You must implement an algorithm that runs in 
O(n) time and uses O(1) auxiliary space.

//code
int n = nums.size();
        int i=0;
        while(i<n)
        {
            if(nums[i]<=0)
            {
                i++;
                continue;
            }
            if(nums[i]-1>=n)
            {
                i++;
                continue;
            }
            if(nums[i]-1==i)
            {
                i++;
                continue;
            }
            int t = nums[i];
            int ind = nums[i]-1;
            nums[i] = nums[ind];
            nums[ind] = t;
            if(nums[i]==nums[ind])
                i++;
        }
        for(int i=0;i<n;i++)
        {
            if((nums[i])!=i+1)
                return i+1;
        }
        return n+1;