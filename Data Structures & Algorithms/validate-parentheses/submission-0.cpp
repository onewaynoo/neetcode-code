class Solution {
public:
    char ulta(char c){
        if(c==')') return '(';
        if(c=='}') return '{';
        return '[';
    }
    bool isValid(string s) {
     stack<char> st;
     for(char c:s){
        if(c=='(' || c=='{' || c=='[')st.push(c);
        else {
            if(st.empty() || st.top()!=ulta(c)) return 0;
            st.pop();
        }
     }
    return st.empty();  
    }
};
