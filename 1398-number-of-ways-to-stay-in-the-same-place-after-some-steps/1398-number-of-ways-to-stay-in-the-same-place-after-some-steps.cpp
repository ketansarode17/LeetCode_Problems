class Solution {
    private:
    int mod=1000000007;
    int dp[502][1002];
    int helper(int steps,int arrLen,int ptr)
    {
        if(!steps)
        {
            return (ptr==0)?1:0;
        }
        if(ptr>=arrLen or ptr<0)return 0;
        if(dp[steps][ptr]!=-1)return dp[steps][ptr];
        int ans=0;
        ans=(ans%mod+helper(steps-1,arrLen,ptr-1)%mod)%mod;
        ans=(ans%mod+helper(steps-1,arrLen,ptr+1)%mod)%mod;
        ans=(ans%mod+helper(steps-1,arrLen,ptr)%mod)%mod;
        return dp[steps][ptr]=ans%mod;
    }
public:
    int numWays(int steps, int arrLen) {
        memset(dp,-1,sizeof dp);
        return helper(steps,arrLen,0);
    }
};