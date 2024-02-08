#include <bits/stdc++.h>
using namespace std ; 
#define pb push_back
#define SPEED cout.tie(0), cin.tie(0), ios_base::sync_with_stdio(0)
#define int long long 
#define endl "\n"
#define all(x) x.begin(), x.end()

 

class SegmentTree {
private:
    int n;
    vector<int> a, seg, lazy;
 
    void check(int p, int s, int e) {
        if (lazy[p] != 0) {
            seg[p] += lazy[p];
            if (s != e) {
                lazy[2 * p] += lazy[p];
                lazy[2 * p + 1] += lazy[p];
            }
            lazy[p] = 0;
        }
    }
 
    void build(int p, int s, int e) {
        check(p, s, e);
 
        if (s == e) {
            seg[p] = a[s];
            return;
        }
 
        build(2 * p, s, (s + e) / 2);
        build(2 * p + 1, (s + e) / 2 + 1, e);
 
        seg[p] = (seg[2 * p]+ seg[2 * p + 1]);
    }
 
 
    void update(int p, int s, int e, int a, int b, int v) {
        check(p, s, e);
 
        if (s >= a && e <= b) {
            seg[p] += v;
 
            if (s != e) {
                lazy[2 * p] += v;
                lazy[2 * p + 1] += v;
            }
 
            return;
        }
 
        if (s > b || e < a)
            return;
 
        update(2 * p, s, (s + e) / 2, a, b, v);
        update(2 * p + 1, (s + e) / 2 + 1, e, a, b, v);
 
        seg[p] = (seg[2 * p]+ seg[2 * p + 1]);
    }
 
    int get(int p, int s, int e, int a, int b) {
        check(p, s, e);
 
        if (s >= a && e <= b)
            return seg[p];
 
        if (s > b || e < a)
            return 0;
 
        return get(2 * p, s, (s + e) / 2, a, b)+ get(2 * p + 1, (s + e) / 2 + 1, e, a, b);
    }
 
public:
    SegmentTree(const vector<int>& arr) {
        n = arr.size();
        a = arr;
        seg.resize(4 * n);
        lazy.resize(4 * n);
        build(1, 0, n - 1);
    }
 
 
 
    void updateRange(int start, int end, int value) {
        update(1, 0, n - 1, start, end, value);
    }
 
    int getsum(int start, int end) {
        return get(1, 0, n - 1, start, end);
    }
};
 
 
class Solution {
    public :
    void solve(){
        int n , k ; 
        cin >> n >> k ;
        vector<int>a(n);
        for(auto &d : a )  cin>>d;
        SegmentTree tree( a );
        
        for ( int i = 0 ; i < k ; i++ )
        {
 
            int  operation ;
            cin >>  operation ;
            if ( operation == 1 )
            {
                
                int a , b , u ;
                cin >> a >> b >> u ; 
                a-- , b-- ;      
                tree.updateRange(a,b,u); 
            }
            else {
                int f ;
                cin >> f ;
                f--;
                cout << tree.getsum(f,f) << endl ; 
            }
            
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
    //cin >> t;
    Solution sol;  
    while (t--) sol.solve();
    return 0;
}
