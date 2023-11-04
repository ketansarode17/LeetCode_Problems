class Solution {
public:
    int getLastMoment(int n, vector<int>& left, vector<int>& right) {
        int left_most=INT_MIN,right_most=INT_MAX;
        for(auto ele:left){
            left_most=max(ele,left_most);
        }
        for(auto ele:right){
            right_most=min(ele,right_most);
        }
        int time_left=left_most;
        int time_right=n-right_most;
        return max(time_left,time_right);
    }
};