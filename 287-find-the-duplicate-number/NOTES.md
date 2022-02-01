### Tortoise and Hare Algorithm
Complexity `O(n) space, O(1) time`
​
The idea is to build two pointers slow and fast, one moving twice as fast as the other. It is equivalent to finding the linked list cycle, and the point at which they intersect is the point which is duplicated.