class Solution {
public:
    int minOperations(vector<int>& nums) {
        //remove the reduntant elements.
        //consider each element as starting point and check for no of elements lying in range.Then we can get the count of operations needed for this element as starting point by using upper bound.
        sort(nums.begin(),nums.end());
        vector<int>temp;
        for(int i=0;i<nums.size();i++)
        {
            if(i==0){temp.push_back(nums[0]);continue;}
            if(nums[i]==nums[i-1])continue;
            temp.push_back(nums[i]);
        }
        int n=nums.size()-1,ans=1e9;
        for(int i=0;i<temp.size();i++)
        {
            int ind=upper_bound(temp.begin(),temp.end(),temp[i]+n)-temp.begin();
            ans=min(ans,(n+1-(ind-i)));
            // cout<<ans<<endl;
        }
        return ans;
    }
};