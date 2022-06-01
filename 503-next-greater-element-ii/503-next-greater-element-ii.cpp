class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        stack<int>st;
        int n = nums.size();
        vector<int>nextGreater(n, -1);
        
        for(int i = n-2; i >=0; --i) st.push(i);
        
        for(int i = n - 1; i >=0; --i){
            while(!st.empty() and nums[st.top()] <= nums[i]) st.pop();
            if(!st.empty()) nextGreater[i] = nums[st.top()];
            st.push(i);
        }
        return nextGreater;
        
    }
    
};

/*

1 2 1

1 2 

2 -1 





*/