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

ll countDistinctWayToClimbStair(long long nStairs)
{
    if (nStairs == 0)
        return 1;

    long long prev1 = 1, prev2 = 0, curr = 0;
    for (long long i = 2; i <= nStairs + 1; ++i)
    {
        curr = ((prev1 % Mod) + (prev2 % Mod)) % Mod;
        prev2 = (prev1 % Mod);
        prev1 = (curr % Mod);
    }
    return prev1 % Mod;
}
void solve()
{
    ll num = 0;
    cin >> num;
    num = countDistinctWayToClimbStair(num);
    cout << num << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}