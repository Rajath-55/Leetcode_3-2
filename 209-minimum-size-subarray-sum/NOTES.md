`2 pointer solution`
​
Sliding window:
​
Take 2 pointers `i` and `j`. Then increase i, add the content to sum, and check if its greater than target. Keep increasing j as well until <= target . Then change answer to be max of ans, and the current Length.
​