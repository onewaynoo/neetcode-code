class MinStack {
public:
    vector<pair<int,int>> stk;
    MinStack() {
       
    }
    
    void push(int value) {
        if(!stk.size())stk.push_back({value,value});
        else{
            stk[stk.size()-1].second < value ?  stk.push_back({value,stk[stk.size()-1].second}) : stk.push_back({value,value});
        }
    }
    
    void pop() {
        stk.pop_back();
    }
    
    int top() {
        if(!stk.size())return -1;
        return stk[stk.size()-1].first;
    }
    
    int getMin() {
        if(!stk.size())return -1;
        return stk[stk.size()-1].second;
    }
};