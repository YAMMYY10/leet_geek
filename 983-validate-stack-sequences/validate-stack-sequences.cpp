class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        int i=0,j=0;
        vector<int> st;
        int n=pushed.size();
        for(int i=0;i<n;i++){
            st.push_back(pushed[i]);
            while(st.size()){
               if(st.back()==popped[j]){
                    j++;
                    st.pop_back();
                }else
                    break;
            }
        }
        return (j==n);
    }
};