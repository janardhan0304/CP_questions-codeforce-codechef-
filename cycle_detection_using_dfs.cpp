//janardhan's code
#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
#define allr(v) v.rbegin(), v.rend()
#define ll   long long int
#define mpll map<long long, long long>
#define mpcl map<char, long long>
#define pl   pair<ll,ll>
#define vvl  vector<vector<ll>>
#define vs   vector<string>
#define vl   vector<long long>
#define vd   vector<double>
#define vb   vector<bool>
#define vp   vector<pl>
#define mat  vector<vector<ll>>
#define nl   '\n'
#define sp   ' '
#define pb   push_back
#define pp   pop
#define ff first
#define ss second
using namespace std;

//ORDERED SET
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

#define ordered_set tree<ll, null_type,less_equal<ll>, rb_tree_tag,tree_order_statistics_node_update>
//use less_equal<T> for include even repetetions
//use greater<T>() for arranging in ascending order

//order_of_key(k) returns the index of the key
//find_by_order(K) return the iterator to the index k i.e returns the kth number in the ordered_set

///////////////////Write your code here......check number of testcases////////////////////////////////
//use \n dont use endl,check loops and breaking conditions
template<class t>
void read(t &v, int n) {
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
}

ll power(ll a, ll b, ll p = 1e18) {
    ll res = 1;
    while (b != 0) {
        if (b % 2 == 1) res = (res * a) % p;
        a = (a * a) % p;
        b /= 2;
    }
    return res;
}

mat adj;
vl vis;

int dfs(int s, int t = 1) {
    vis[s] = t;
    for (auto x : adj[s]) {
        if (vis[x] != 0 && abs(vis[s] - vis[x]) > 1) return 0;
        else if (vis[x] == 0) {
            bool flg = dfs(x, t + 1);
            if (!flg) return 0;
        }
    } return 1;
}

void _rUn_() {
    ll tc = 1;
    // dryrun the code once if it consists of *****loops*****....
    //cin >> tc;
    for (ll _ = 1; _ <= tc; _++) {
        //cycle detection using dfs:
        // idea is if a visited node is visited again then check the time differeces
        // between the source node and the node you have to visit next(i.e x), if the time difference
        //is eqaul to 1 it means it(it refers to node x ) is the immediate node to  the soure and we might
        //have visited it first and then came here(here in the sense the present source)....so it is not a cycle..


        //main idea is the time differeces(levels) should be 1 if a node is pointed
        //to a node that is alread visited
        ll n, m;
        cin >> n >> m;
        adj.resize(n + 1);
        vis.resize(n + 1);
        for (auto &x : vis) x = 0;
        for (int i = 0; i < m; i++) {
            ll u, v;
            cin >> u >> v;
            adj[u].pb(v);
            adj[v].pb(u);
        }
        bool flg = 1;
        ll count = 0;
        for (int i = 1; i <= n; i++) {
            if (vis[i] == 0) {
                count++;
                flg = dfs(i);
                if (!flg) break;
            }
        }
        if (flg && count == 1) {
            cout << "YES\n";
        } else cout << "NO\n";

    }
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    _rUn_();
}