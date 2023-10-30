class Solution {
    private:
    static bool comp(int i,int j)
    {
        int bits1=__builtin_popcount(i);
        int bits2=__builtin_popcount(j);
        if(bits1==bits2)return i<=j;
        return bits1<bits2;
    }
public:
    vector<int> sortByBits(vector<int>& arr) {
        sort(arr.begin(),arr.end(),comp);
        return arr;
    }
};