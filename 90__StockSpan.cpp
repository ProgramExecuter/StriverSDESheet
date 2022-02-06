class StockSpanner {
    stack<pair<int, int>> st;
    int idx = 0;
public:
    StockSpanner() {
        
    }
    
    int next(int price) {
        if(st.empty()) {
            st.push({price, idx++});
            return 1;
        }
        else {
            while(!st.empty() && price >= st.top().first) {
                st.pop();
            }
            int res = 0;
            res = st.empty() ? idx + 1 : idx - st.top().second;
            st.push({price, idx++});
            return res;
        }
    }
};