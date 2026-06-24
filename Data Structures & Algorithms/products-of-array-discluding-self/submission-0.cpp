class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> left;
        vector<int> right;
        int lt=1,rt=1;
        left.push_back(1);
        right.push_back(1);
        for(int i=0;i<nums.size();i++){
            lt*=nums[i];
            rt*=nums[nums.size()-i-1];
            left.push_back(lt);
            right.push_back(rt);
        }
        for(int i=0;i<nums.size();i++){
            nums[i]=left[i]*right[nums.size()-i-1];
        }
        return nums;
    }
};
