class Solution {
    private:
    pair<int,int>helper(string& s,int ind)
    {
        int ans1=1;
        int p1=ind-1,p2=ind+1;
        int s1=ind,s2=ind,s3=-1,s4=-1;
        while(p1>=0 and p2<s.size())
        {
            if(s[p1]==s[p2])
            {
                ans1+=2;
                s1=p1,s2=p2;
                p1--,p2++;
                continue;
            }
            break;
        }
        int ans2=0;
        p1=ind-1,p2=ind;
        while(p1>=0 and p2<s.size())
        {
            if(s[p1]==s[p2])
            {
                ans2+=2;
                s3=p1,s4=p2;
                p1--,p2++;
                continue;
            }
            break;
        }
        if(ans1>ans2)
        {
            return {s1,s2};
        }
        return {s3,s4};
    }
public:
    string longestPalindrome(string s) {
        int n=s.size();
        if(n==1)return s;
        int maxi=0,p1,p2;
        for(int i=1;i<n;i++)
        {
            pair<int,int>temp1=helper(s,i);
            if(maxi<temp1.second-temp1.first+1)
            {
                maxi=temp1.second-temp1.first+1;
                p1=temp1.first,p2=temp1.second;
            }
        }
        string res="";
        for(int i=p1;i<=p2;i++)res+=s[i];
        return res;
    }
};