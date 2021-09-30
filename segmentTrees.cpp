#include<bits/stdc++.h>
#define mp make_pair
#define pii pair<int,int>
#define pll pair<ll,ll>
#define vll vector<ll>
#define vl vector<l>
#define vull vector<ull>
#define vi vector<int>
#define vs vector<string>
#define ss set<string>
#define in(a,n) for(int i=0;i<n;i++) cin>>a[i];
#define out(a,n,line) for(int i=0;i<n;i++) cout<<a[i]<<line;
#define mll map<ll,ll>
#define tii tuple<int,int,int>
using namespace std;
typedef long long unsigned ull;
typedef long long ll;
typedef long l;
typedef double d;
typedef float f;
const ll N = 1000001;
ll a[N], tree[4 * N], lazy[4 * N] , z[4 * N];


void rangeUpdateLazy(ll s, ll e, ll qs, ll qe, ll val, ll idx) {
    // out of bounds
    if (s > qe || e < qs) {
        return;
    }

    if (lazy[idx] != 0) {
        tree[idx] += lazy[idx];
        if (s != e) {
            lazy[2 * idx] += lazy[idx];
            lazy[2 * idx + 1] += lazy[idx];
        }
        lazy[idx] = 0;
    }

    //exact overlap
    if (s >= qs && e <= qe) {

        tree[idx] = 0;
        if (s != e) {
            z[2 * idx] = 1;
            z[2 * idx + 1] = 1;
        }
        return;
    }
    // partial overlap
    ll mid = (s + e) / 2;
    rangeUpdateLazy(s, mid, qs, qe, val, 2 * idx);
    rangeUpdateLazy(mid + 1, e, qs, qe, val, 2 * idx + 1);
    tree[idx] = tree[2 * idx] + tree[2 * idx + 1];
}


void updateTree(ll s, ll e, ll pos, ll val, ll idx) {
    if (pos < s || pos > e) {
        return;
    }
    if (z[idx]) {
        tree[idx] = 0;
        if (s != e) {
            z[2 * idx] = 1;
            z[2 * idx + 1] = 1;
        }
    }
    if (lazy[idx] != 0) {
        tree[idx] += lazy[idx];
        if (s != e) {
            lazy[2 * idx] += lazy[idx];
            lazy[2 * idx + 1] += lazy[idx];
        }
        lazy[idx] = 0;
    }

    //exact overlap
    if (s == e) {
        a[pos] += val;
        tree[idx] += val;
        return;
    }

    ll mid = (s + e) / 2;
    updateTree(s, mid, pos, val, 2 * idx);
    updateTree(mid + 1, e, pos, val, 2 * idx + 1);
    tree[idx] = tree[2 * idx] + tree[2 * idx + 1];
}

ll query(ll s, ll e, ll qs, ll qe, ll idx) {
    if (s > qe || e < qs) {
        return 0;
    }
    if (z[idx]) {
        tree[idx] = 0;
        if (s != e) {
            z[2 * idx] = 1;
            z[2 * idx + 1] = 1;
        }
    }
    if (lazy[idx] != 0) {
        tree[idx] += lazy[idx];
        if (s != e) {
            lazy[2 * idx] += lazy[idx];
            lazy[2 * idx + 1] += lazy[idx];
        }
        lazy[idx] = 0;
    }


    if (s >= qs && e <= qe) {
        return tree[idx];
    }

    ll mid = (s + e) / 2;
    ll lans = query(s, mid, qs, qe, 2 * idx);
    ll rans = query(mid + 1, e, qs, qe, 2 * idx + 1);

    return (lans + rans);
}
void solve() {
    ll Q;
    cin >> Q;
    while (Q--) {
        ll ea, eb;
        cin >> ea >> eb;
        if (ea == 1) {
            updateTree(0, N - 1, eb, 1, 1);
        } else {
            ll ans = query(0, N - 1, 0, eb, 1);
            rangeUpdateLazy(0, N - 1, 0, eb, 1, 1);
            cout << ans << endl;
        }
    }
    // for(ll i=1;i<2*n;i++){
    //     cout<<tree[i]<<" ";
    // }
    // for (ll i = 0; i < q; i++) {
    //     ll tp, le, r, v;
    //     cin >> tp >> le;
    //     if (tp == 1) {
    //         cin >> r >> v;
    //         rangeUpdateLazy(0, n - 1, le - 1, r - 1, v, 1);
    //     }
    //     else {
    //         cout << query(0, n - 1, le - 1, le - 1, 1) << "\n";
    //     }
    //     // else updateTree(0,n-1,le-1,r,1);
    // }
}



int main() {

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int t;
    t = 1;
    // cin>>t;
    while (t--) {
        solve();
    }

    return 0;
}
