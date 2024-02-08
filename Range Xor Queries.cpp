#include <bits/stdc++.h>
using namespace std ; 
#define pb push_back
#define SPEED cout.tie(0), cin.tie(0), ios_base::sync_with_stdio(0)
#define int long long 
#define endl "\n"
#define all(x) x.begin(), x.end()

 
 
class SegmentTreeMax {
private:
    vector<int> tree;
    int n;
    void build(const vector<int>& arr, int v, int tl, int tr) {
        if (tl == tr) tree[v] = arr[tl];
        else {
            int tm = (tl + tr) / 2;
            build(arr, v*2, tl, tm);
            build(arr, v*2+1, tm+1, tr);
            tree[v] = (tree[v*2] ^ tree[v*2+1]);
        }
    }
 
    int query(int v, int tl, int tr, int l, int r) {
        if (l > r) return 0; 
        if (l == tl && r == tr) return tree[v];
        int tm = (tl + tr) / 2;
        return (query(v*2, tl, tm, l, min(r, tm)) ^ query(v*2+1, tm+1, tr, max(l, tm+1), r));
    }
 
    void update(int v, int tl, int tr, int pos, int val) {
        if (tl == tr) tree[v] = val;
         else {
            int tm = (tl + tr) / 2;
            if (pos <= tm) update(v*2, tl, tm, pos, val);
            else update(v*2+1, tm+1, tr, pos, val);
            tree[v] = (tree[v*2] ^ tree[v*2+1]);
        }
    }
 
public:
    SegmentTreeMax(const vector<int>& arr) {
        n = arr.size();
        tree.resize(4 * n); 
        build(arr, 1, 0, n - 1); 
    }
 
    int query(int l, int r) {
        return query(1, 0, n - 1, l, r);
    }
 
    void update(int pos, int val) {
        update(1, 0, n - 1, pos, val);
    }
};
 
 
class Solution {
    public :
    void solve(){
        int n , k ; 
        cin >> n >> k ;
        vector<int>a(n);
        for(auto &d : a )  cin>>d;
        SegmentTreeMax tree( a );
        for ( int i = 0 ; i < k ; i++ )
        {
            int  a_k , b_u ;
            cin >>  a_k >>  b_u ;
            cout << tree.query(a_k-1 , b_u-1) << endl ;
        }
    }
};
signed main() {
     SPEED;
    #ifndef ONLINE_JUDGE
        freopen("inp.txt", "r", stdin);
        freopen("out.txt", "w", stdout);
        freopen("err.txt", "w", stderr);
    #endif
 
    int t = 1;
    Solution sol;  
    while (t--) sol.solve();
    return 0;
}
