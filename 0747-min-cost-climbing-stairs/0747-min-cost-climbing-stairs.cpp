class Solution {
    private:
    int dp[1002];
    int helper(vector<int>&cost,int ind)
    {
        if(ind>=cost.size())return 0;
        if(dp[ind]!=-1)return dp[ind];
        if(!ind)
        {
            return dp[ind]=min({cost[ind]+helper(cost,ind+1),cost[ind]+helper(cost,ind+2),helper(cost,ind+1)});
        }
        else
        {
            return dp[ind]=min(cost[ind]+helper(cost,ind+1),cost[ind]+helper(cost,ind+2));
        }
    }
public:
    int minCostClimbingStairs(vector<int>& cost) {
        memset(dp,-1,sizeof dp);
        return helper(cost,0);
    }
};