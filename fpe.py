import sys
import math


class TreeNode:
    def init(self, value):
        self.value = value
        self.gcd = value
        self.gcdSumOFChildren = 0


result = 0


def solve():
    n = int(input())
    ValuesOfNode = list(map(int, input().split()))
    values = {}
    for i in range(1, n+1):
        values[i] = TreeNode()
        values[i].value = ValuesOfNode[i-1]
        values[i].gcd = ValuesOfNode[i-1]
        values[i].gcdSumOFChildren = 0
    g = {}
    for i in range(1, n+1):
        g[i] = []
    for i in range(n-1):
        a, b = map(int, input().split())
        g[b].append(a)
        g[a].append(b)

    def helper(curr, parent):
        sumofgcd = 0
        for child in g[curr]:
            if child != parent:
                helper(child, curr)
                values[curr].gcd = math.gcd(
                    values[curr].gcd, values[child].gcd)
                sumofgcd += values[child].gcd
        values[curr].gcdSumOFChildren = sumofgcd
    helper(1, -1)
    global result
    result = 0

    def helper2(curr, parent, sum):
        sum += values[curr].gcdSumOFChildren
        global result
        result = max(result, sum)
        for child in g[curr]:
            if child != parent:
                helper2(child, curr, sum-values[child].gcd)
    helper2(1, -1, 0)
    print(result)


sys.setrecursionlimit(10**6)
numberOfTestCases = int(input())
for i in range(numberOfTestCases):
    solve()
