class Solution {
    private:
    map<int,vector<int>>mp=
    {
        {5,{0,1,2,3,4}},{0,{1}},{1,{0,2}},{2,{0,1,3,4}},{3,{2,4}},{4,{0}}
    };
    int dp[20002][6];
int mod=1000000007;
int helper(int ind,int c)
{
    if(!ind)return 1;
    if(dp[ind][c]!=-1)return dp[ind][c];
    int ans=0;
    for(auto it:mp[c])
    {
        ans=(ans%mod+helper(ind-1,it)%mod)%mod;
    }
    return dp[ind][c]=ans;
}
public:
    int countVowelPermutation(int n) {
        memset(dp,-1,sizeof dp);
        return helper(n,5);
    }
};