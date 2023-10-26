class Solution {
    private:
    int mod=1000000007;
    unordered_map<int,int>mp;
    int dp[1002];
    int helper(vector<int>&arr,int ind)
    {
        if(dp[ind]!=-1)return dp[ind];
        int num=arr[ind];
        int temp=1;
        for(auto it:mp)
        {
            if(num%it.first==0 and mp.find(num/it.first)!=mp.end())
            {
                int temp1=(helper(arr,it.second)%mod*1LL*helper(arr,mp[num/it.first])%mod)%mod;
                temp=(temp%mod+temp1%mod)%mod;
            }
        }
        return dp[ind]=temp;
    }
public:
    int numFactoredBinaryTrees(vector<int>& arr) {
        memset(dp,-1,sizeof dp);
        for(int i=0;i<arr.size();i++)
        {
            mp[arr[i]]=i;
        }
        int ans=0;
        for(int i=0;i<arr.size();i++)
        {
            ans=(ans%mod+helper(arr,i)%mod)%mod;
        }
        return ans;
    }
};