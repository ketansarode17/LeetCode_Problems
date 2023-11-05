class Solution {
public:
    int getWinner(vector<int>& arr, int k) {
        k=min(k,(int)arr.size()-1);
        int prev=arr[0];
        int cnt=0;
        for(int i=1;i<arr.size();i++)
        {
            if(prev>arr[i])cnt++;
            else
            {
                prev=arr[i];cnt=1;
            }
            if(cnt==k)return prev;
        }
        return prev;
    }
};