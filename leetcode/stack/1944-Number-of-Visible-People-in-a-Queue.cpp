class Solution {
public:
    vector<int> canSeePersonsCount(vector<int>& heights) {
        stack<int> st;
        int n=heights.size();
        vector<int> v(n);
        for(int i=n-1; i>=0; i--){
            int cnt=0;
            while(!st.empty() && heights[i]>st.top()){
                st.pop();
                cnt++;
            }

            if(!st.empty()){
                cnt++;
            }
            v[i]=cnt;
            st.push(heights[i]);
        }

        return v;
    }
};