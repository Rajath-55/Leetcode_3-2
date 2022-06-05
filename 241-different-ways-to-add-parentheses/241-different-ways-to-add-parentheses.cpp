class Solution {
public:
    
    int compute(int a, int b, char exp){
        switch(exp){
            case '+': 
                return a + b;
            case '-': 
                return a - b;
            case '*':
                return a*b;
            default:
                break;
        }
        return -1;
    }
    vector<int> diffWaysToCompute(string expression) {
        bool pureNumber = 1;
        vector<int>ans;
        for(int i = 0; i < expression.length(); ++i){
            if(!isdigit(expression[i])){
                char exp = expression[i];
                pureNumber = 0;
                vector<int>leftHandSide = diffWaysToCompute(expression.substr(0, i));
                vector<int>rightHandSide = diffWaysToCompute(expression.substr(i+1));
                for(auto a : leftHandSide){
                    for(auto b : rightHandSide){
                        ans.push_back(compute(a,b,exp));
                    }
                }
            }
        }
        if(pureNumber) return {stoi(expression)};
        return ans;
    }
};

/*
expression trees
each leaf is a number and each internal node is an operator.
Generate all possible trees and evaluate


   -          - 
            -   1
            2 1
  2  -
    1  1

*/