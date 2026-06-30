class Solution {
public:
    int maxArea(vector<int>& arr) {
        int i=0,j=arr.size()-1;
        int ans = 0;
        while(i<j){
            ans= max(ans,min(arr[i],arr[j])*(j-i));
            if(arr[j]>arr[i])i++;
            else j--;
        }
        return ans;
    }
};
