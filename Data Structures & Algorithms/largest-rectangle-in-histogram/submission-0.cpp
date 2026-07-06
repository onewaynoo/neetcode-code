class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
                vector<int> nsl(heights.size(),0);
        vector<int> nsr(heights.size(),0);
        stack<int> st;
        for(int i=0;i<heights.size();i++){
            while(!st.empty() && heights[st.top()]>=heights[i])st.pop();
            if(!st.empty())nsl[i]=st.top();
            else nsl[i]=-1;
            st.push(i);
        }
        st={};
        for(int i=heights.size()-1;i>=0;i--){
            while(!st.empty() && heights[st.top()]>=heights[i])st.pop();
            if(!st.empty())nsr[i]=st.top();
            else nsr[i]=heights.size();
            st.push(i);
        }
        
        int ans = 0;

        for(int i =0;i<heights.size();i++){

            int area = heights[i] * (nsr[i]-nsl[i]-1);
            ans = max(ans, area);
        }

        return ans;
    }
};
