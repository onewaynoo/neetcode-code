class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
                stack<pair<int,int>> st;
        vector<pair<int,int>> car;
        for(int i=0;i<speed.size();i++)
            car.push_back({position[i],speed[i]});

        sort(car.begin(),car.end());

        for(int i=car.size()-1;i>=0;i--){
            st.push(car[i]);
            if(st.size()>=2){
                auto car1 = st.top();
                double t1 = ((double)target-(double)car1.first)/car1.second;
                st.pop();
                auto car2 = st.top();
                double t2 = ((double)target-(double)car2.first)/car2.second;
                if(t1>t2){
                    //can't collide so keep it
                    st.push(car1);
                }
            }
        }
        return st.size();
    }
};
