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

// RECURSION
// ll fun(vector<vector<ll>> &arr, ll days, ll last)
// {
//     if (days == 0)
//     {
//         ll maxm = 0;
//         rep(i, 0, 2)
//         {
//             if (i != last)
//             {
//                 maxm = max(maxm, arr[days][i]);
//             }
//         }
//         return maxm;
//     }
//     ll maxm = 0;
//     rep(i, 0, 2)
//     {
//         if (i == last)
//             continue;
//         ll temp = arr[days][i] + fun(arr, days - 1, i);
//         maxm = max(maxm, temp);
//     }
//     return maxm;
// }

// MEMOIZATION
// ll fun(vector<vector<ll>> &arr, ll days, ll last, vector<vector<ll>> &dp)
// {
//     if (days == 0)
//     {
//         ll maxm = 0;
//         rep(i, 0, 2)
//         {
//             if (i != last)
//             {
//                 maxm = max(maxm, arr[days][i]);
//             }
//         }
//         return maxm;
//     }
//     if (dp[days][last] != -1)
//         return dp[days][last];
//     ll maxm = 0;
//     rep(i, 0, 2)
//     {
//         if (i == last)
//             continue;
//         ll temp = arr[days][i] + fun(arr, days - 1, i, dp);
//         maxm = max(maxm, temp);
//     }
//     return dp[days][last] = maxm;
// }

// TABULARTION
// ll fun(vector<vector<ll>> &arr, ll ndays, ll lst, vector<vector<ll>> &dp)
// {
//     dp[0][0] = max(arr[0][1], arr[0][2]);
//     dp[0][1] = max(arr[0][0], arr[0][2]);
//     dp[0][2] = max(arr[0][0], arr[0][1]);
//     dp[0][3] = max(arr[0][0], max(arr[0][1], arr[0][2]));
//     rep(days, 1, ndays)
//     {
//         rep(last, 0, 3)
//         {
//             dp[days][last] = 0;
//             rep(task, 0, 2)
//             {
//                 if (task == last)
//                     continue;
//                 ll temp = arr[days][task] + dp[days - 1][task];
//                 dp[days][last] = max(dp[days][last], temp);
//             }
//         }
//     }
//     return dp[ndays][3];
// }

ll fun(vector<vector<ll>> &arr, ll ndays, ll lst, vector<vector<ll>> &No_use)
{
    vll prev(4, 0);
    prev[0] = max(arr[0][1], arr[0][2]);
    prev[1] = max(arr[0][0], arr[0][2]);
    prev[2] = max(arr[0][0], arr[0][1]);
    prev[3] = max(arr[0][0], max(arr[0][1], arr[0][2]));
    rep(days, 1, ndays)
    {
        vll curr(4, 0);
        rep(last, 0, 3)
        {
            curr[last] = 0;
            // ll maxm = 0;
            // rep(task, 0, 2)
            // {
            //     if (task == last)
            //         continue;
            //     ll temp = arr[days][task] + prev[task];
            //     maxm = max(maxm, temp);
            // }
            // curr[last] = maxm;
            rep(task, 0, 2)
            {
                if (task != last)
                    curr[last] = max(curr[last], arr[days][task] + prev[task]);
            }
        }
        prev = curr;
    }
    return prev[3];
}
ll ninjasTraining(vector<vector<ll>> &arr, ll days, ll last)
{
    vector<vector<ll>> dp(days + 1, vector<ll>(4, -1));
    return fun(arr, days, last, dp);
}

void solve()
{
    ll t;
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;
        vector<vector<ll>> arr(n, vector<ll>(3));
        rep(i, 0, n - 1)
        {
            rep(j, 0, 2)
            {
                cin >> arr[i][j];
            }
        }
        ll ans = ninjasTraining(arr, n - 1, 3);
        cout << ans << endl;
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