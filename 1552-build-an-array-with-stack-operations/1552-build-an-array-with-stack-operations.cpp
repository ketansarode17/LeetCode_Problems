class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        int start=1;
        vector<string>ans;
        for(int i=0;i<target.size();i++)
        {
            if(target[i]==start)
            {
                ans.push_back("Push");
                start++;
            }
            else
            {
                ans.push_back("Push");
                ans.push_back("Pop");
                i--;
                start++;
            }
        }
        return ans;
    }
};