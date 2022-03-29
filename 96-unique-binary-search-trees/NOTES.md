### Dp solution for catalan numbers:
​
dp[i] = no of bst with i nodes.
Optimal substructure -> dp[i+1] needs dp[i], because i+1th key added to a BST can depends on the number of trees we can make with i keys, and subsequently add i+1 to each of them somewhere.
​
Overlapping subproblems -> dp[i] will call need to know the number of ways to make BST for all keys less than it, because of which we can store subproblems in dp.
​
Time complexity = ```O(n^2)```.
​