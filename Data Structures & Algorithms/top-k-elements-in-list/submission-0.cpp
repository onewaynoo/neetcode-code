class Solution {
public:
    typedef pair<int,int> ppi;
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> ans;

        unordered_map<int,int> mp;
        for(auto x: nums)mp[x]++;

        priority_queue<ppi,vector<ppi>,greater<ppi>> minh;
        for(auto x:mp){
            minh.push({x.second,x.first});
            while(minh.size()>k){
                minh.pop();
            }
        }

        while(minh.size()>0){
            ans.push_back(minh.top().second);
            minh.pop();
        }
        return ans;
    }
};
