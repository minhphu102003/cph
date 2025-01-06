def solve(arr):
    count = [0] * 3
    for num in arr:
        count[num % 3] += 1
    pairs = 0
    pairs += count[0] * (count[0] - 1) // 2
    pairs += count[1] * count[2]
    return pairs

n = int(input())
arr = list(map(int, input().split()))

print(solve (arr))
