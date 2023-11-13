class Solution {
    private:
    bool isVowel(char x)
    {
        x=tolower(x);
        return x=='a' or x=='e' or x=='o' or x=='i' or x=='u';
    }
public:
    string sortVowels(string s) {
        vector<char>vc;
        for(int i=0;i<s.size();i++)
        {
            if(isVowel(s[i]))
            {
                vc.emplace_back(s[i]);
                s[i]='#';
            }
        }
        sort(vc.begin(),vc.end());
        //for(auto it:vc)cout<<it<<" ";
        int ind=0;
        for(int i=0;i<s.size();i++)
        {
            if(s[i]=='#')s[i]=vc[ind++];
        }
        return s;
    }
};