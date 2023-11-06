class SeatManager {
    private:
    set<int>st;
public:
    SeatManager(int n) {
        for(int i=1;i<=n;i++)st.insert(i);
    }
    
    int reserve() {
        auto it=st.begin();
        int res=*it;
        st.erase(res);
        return res;
    }
    
    void unreserve(int seatNumber) {
        st.insert(seatNumber);
    }
};

/**
 * Your SeatManager object will be instantiated and called as such:
 * SeatManager* obj = new SeatManager(n);
 * int param_1 = obj->reserve();
 * obj->unreserve(seatNumber);
 */