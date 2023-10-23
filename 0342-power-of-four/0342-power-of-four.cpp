class Solution {
public:
    bool isPowerOfFour(int n) {
        if(n<=0)return false;
        int cnt = 0,pos=0;
        for(int i=0;i<31;i++)
        {
            if(n&(1<<i)){cnt++;pos=i;}
        }
        if(cnt>1)return false;
        return !(pos%2);
    }
};