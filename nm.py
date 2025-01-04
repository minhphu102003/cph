def sl(m,n):
    if m< 0 or n< 0: return 0
    if m==0 and n ==0 : return 1
    dp = [[0]* (m+1) for _ in range(n+1)]
    dp[0][0] = 1
    for k in range(1,n+1):
        for s in range(1,m+1):
            for d in range(10):
                if s -d >=0:
                    dp[k][s] += dp[k-1][s-d]
    result = sum(dp[k][m] for k in range(1,n+1))
    return result

print(sl(101,101))
