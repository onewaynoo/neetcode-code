class Solution {
public:
    int trap(vector<int>& arr) {
        int i=0,j=arr.size()-1,leftMax=0,rightMax=0,ans=0;
        while(i<j){
            leftMax = max(leftMax,arr[i]);
            rightMax = max(rightMax,arr[j]);
            if(leftMax<rightMax){
                ans += leftMax - arr[i];
                i++;
            }
            else {
                ans += rightMax - arr[j];
                j--;
            }
        }
        return ans;
    }
};
