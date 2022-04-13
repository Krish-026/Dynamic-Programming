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
int Solution(vi& arr, vi& dp, int n){
    if(n == 0) return arr[0];
    if(n < 0) return 0;
    if(dp[n] != -1)
        return dp[n];
    
    int pick = arr[n] + Solution(arr, dp, n-2);
    int NotPick = 0 + Solution(arr, dp, n-1);
    dp[n] = max(pick, NotPick);
    return dp[n];
}
int maximumNonAdjacentSum(vector<int> &arr)
{
    int n = arr.size();
    vi dp(n, -1);
    return Solution(arr, dp, n);
}
void solve()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vi arr(n);
        input(arr, 0, n-1);
        cout << maximumNonAdjacentSum(arr);
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