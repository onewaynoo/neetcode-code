class KthLargest {
public:
    priority_queue<int,vector<int>,greater<int>> minh;
    int kth;
    KthLargest(int k, vector<int>& nums) {
        kth=k;
        for(auto i : nums){
            minh.push(i);
            while(minh.size()>k)minh.pop();
        }
    }
    
    int add(int val) {
        minh.push(val);
        while(minh.size()>kth)minh.pop();
        return minh.top();
    }
};