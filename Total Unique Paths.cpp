#include <bits/stdc++.h>
#define ll long long
#define vi vector<int>
#define vvi vector<vi>
#define vl vector<long>
#define vvl vector<vl>
#define vll vector<ll>
#define vvll vector<vll>
#define vb vector<bool>
#define pb push_back
#define all(a) a.begin(), a.end()
#define allr(a) a.rbegin(), a.rend()
#define mp make_pair
#define int ll
#define rep(a, b, c) for (long long a = b; a <= c; ++a)
#define repr(a, b, c) for (long long a = b; a >= c; --a)
#define input(a, b, n)                 \
    for (long long i = b; i <= n; ++i) \
        cin >> a[i];
#define output(a, b, n)                \
    for (long long i = b; i <= n; ++i) \
        cout << a[i] << " ";
#define Mod 1000000007
using namespace std;
// Memoization
//  int fun(int i, int j, vector<vector<int>>& dp){
//  	if(i == 0 && j == 0)
//  		return 1;
//  	else if(i < 0 || j < 0)
//  		return 0;
//  	if(dp[i][j] != -1)
//  		return dp[i][j];
//  	int up = fun(i-1,j, dp);
//  	int right = fun(i, j-1, dp);
//  	return dp[i][j] = up+right;
//  }

// Tabulation
//  int fun(int m, int n, vector<vector<int>>& dp){
//  	for(int i = 0; i <= m; ++i){
//  		for(int j = 0; j <= n; ++j){
//  			int up = 0, left = 0;
//  			if(i == 0 and j == 0){
//  				dp[i][j] = 1;
//  				continue;
//  			}
//  			if(i - 1 >= 0)
//  				up = dp[i-1][j];
//  			if(j-1 >= 0)
//  				left = dp[i][j-1];
//  			dp[i][j] = up + left;
//  		}
//  	}
//  	return dp[m][n];
//  }

// Space Optimization
int fun(int m, int n, vector<int> &prev)
{
    for (int i = 0; i <= m; ++i)
    {
        vector<int> curr(n + 1, 0);
        for (int j = 0; j <= n; ++j)
        {
            int up = 0, left = 0;
            if (i == 0 and j == 0)
            {
                curr[j] = 1;
                continue;
            }
            if (i - 1 >= 0)
                up = prev[j];
            if (j - 1 >= 0)
                left = curr[j - 1];
            curr[j] = up + left;
        }
        prev = curr;
    }
    return prev[n];
}
int uniquePaths(int m, int n)
{
    vector<int> dp(n, -1);
    return fun(m - 1, n - 1, dp);
}
void solve()
{
    int t;
    cin >> t;
    while (t--)
    {
        int a, b;
        cin >> a >> b;
        int ans = uniquePaths(a, b);
        cout << ans << endl;
    }
}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    solve();
    return 0;
}