class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
                unordered_set<int> st;
        for(int x:nums)st.insert(x);;
        int ans=0;

        for(int s:st){
            int curr=0;
            int start=s;
            if(st.find(s)!=st.end() && st.find(s-1)==st.end()){
                while(st.find(start)!=st.end()){
                    curr++;
                    start++;
                }
                ans=max(ans,curr);
            }
        }
        return ans;
    }
};
