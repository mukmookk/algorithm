def solution(alp, cop, problems):
    MAX_ALP = 0
    MAX_COP = 0
    time = 0
    for alp_req, cop_req, alp_rwd, cop_rwd, cost in problems:
        MAX_ALP = max(MAX_ALP, alp_req)
        MAX_COP = max(MAX_COP, cop_req)
        # time += cost
        
    alp = min(alp, MAX_ALP)
    cop = min(cop, MAX_COP)
    dp = [[float('inf')] * (MAX_COP + 1) for _ in range(MAX_ALP + 1)]
    dp[alp][cop] = 0
    
    for i in range(alp, MAX_ALP + 1):
        for j in range(cop, MAX_COP + 1):
            
            if i < MAX_ALP:
                dp[i + 1][j] = min(dp[i + 1][j], dp[i][j] + 1)
            
            if j < MAX_COP:
                dp[i][j + 1] = min(dp[i][j + 1], dp[i][j] + 1)
            
            for alp_req, cop_req, alp_rwd, cop_rwd, cost in problems:
                if i >= alp_req and j >= cop_req:
                    next_alp = min(MAX_ALP, i + alp_rwd)
                    next_cop = min(MAX_COP, j + cop_rwd)
                    dp[next_alp][next_cop] = min(dp[next_alp][next_cop], dp[i][j] + cost)
    
    return dp[MAX_ALP][MAX_COP]