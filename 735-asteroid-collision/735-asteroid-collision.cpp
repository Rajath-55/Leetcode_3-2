class Solution {
public:
    
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int>st;
        
        for(int i = 0; i < asteroids.size(); ++i){
            if(asteroids[i] > 0){
                st.push(asteroids[i]);
                continue;
            }
            while(!st.empty() and st.top() > 0 and st.top() < -asteroids[i]){
                st.pop();
            }
            
            if(!st.empty() and st.top() > 0 and abs(st.top()) == abs(asteroids[i])){
                st.pop();
                continue;
            }
            
            if(!st.empty() and st.top() >0 and st.top() > -asteroids[i]) continue;
            st.push(asteroids[i]);
        }
        asteroids.clear();
        while(!st.empty()){
            asteroids.push_back(st.top());
            st.pop();
        }
        reverse(asteroids.begin(), asteroids.end());
        return asteroids;
        
    }
};

/*
While the stack top is positive and the upcoming asteroid is negative and has a greater magnitude keep poping the stack.
Check if there is stack and the stack top is positive and the upcoming asteroid is negative and of same magnitude, pop the stack once and go to the next iteration.
Check if there is stack and the stack top is positive and the upcoming asteroid is negative and the magnitude of stack top is greater than the asteroid then continue to the next iteration.
If none of this is true simply append the asteroid to the stack.
Return the stack itself.


*/