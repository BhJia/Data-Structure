#include<bits/stdc++.h>
using namespace std;
int cuttingRope(int n)
{
    if (n == 2)
        return 1;
    if (n == 3)
        return 2;
    vector<int> dp(n + 1, 0);
    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 3;
    for (int i = 4; i <= n; i++)
        for (int j = 1; j < i; j++)
            dp[i] = max(dp[i], dp[j] * (i - j));
    return dp[n];
}