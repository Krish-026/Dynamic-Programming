// https://www.codingninjas.com/codestudio/problems/frog-jump_3621012?leftPanelTab=0
// Basically it is Fibonacci series where we need to calculate the minimum absolute difference of heights[]
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

//-----------------------Memoization-----------------------------------------
// int minEnergy(vector<int> &dp, int n, vector<int> &arr)
// {
//     if (n == 0)
//         return 0;
//     if (dp[n + 1] != -1)
//         return dp[n + 1];
//     int onejump = minEnergy(dp, n - 1, arr) + abs(arr[n] - arr[n - 1]);
//     int twojump = INT_MAX;
//     if (n > 1)
//         twojump = minEnergy(dp, n - 2, arr) + abs(arr[n] - arr[n - 2]);
//     return dp[n + 1] = min(onejump, twojump);
// }
// int frogJump(int n, vector<int> &heights)
// {
//     vector<int> dp(n + 1, -1);
//     return minEnergy(dp, n - 1, heights);
// }

// ---------------------------Tabulation-------------------------------------
int frogJump(int n, vector<int> &arr)
{
    vector<int> dp(n, 0);
    dp[1] = abs(arr[1] - arr[0]);
    for (int i = 2; i < n; ++i)
    {
        int oneStep = dp[i - 1] + abs(arr[i] - arr[i - 1]);
        int twoStep = dp[i - 2] + abs(arr[i] - arr[i - 2]);
        dp[i] = min(oneStep, twoStep);
    }
    return dp[n - 1];
}
void solve()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> heights(n, 0);
        input(heights, 0, n - 1);
        cout << frogJump(n, heights) << endl;
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    solve();
    return 0;
}