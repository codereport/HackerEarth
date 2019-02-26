# code_report Solution
# Video Link: https://youtu.be/9eBNy3wKcKc
# Problem Link: https://www.hackerearth.com/practice/algorithms/greedy/basics-of-greedy-algorithms/practice-problems/algorithm/toy-box-5044b3ed/

n, m = map(int,input().split())
l = [0]*(m+1)
for i in range(n):
    p, b = map(int,input().split())
    l[b] = max(p, l[b])
print(sum(l))
