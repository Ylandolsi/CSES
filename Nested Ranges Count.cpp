#include <bits/stdc++.h>
using namespace std ; 
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
//----------TEMPLATES----------
template<class T> using indexed_set_dec = tree<T, null_type, greater<T>, rb_tree_tag, tree_order_statistics_node_update>;
template<class T> using indexed_set_inc = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template <class key, class value, class cmp = std::less<key>> using indexed_map = tree<key, value, cmp, rb_tree_tag, tree_order_statistics_node_update>;            
template<typename T> void ckmax(T& x,T y){x=max(x,y);}
template<typename T,typename... Args>void ckmax(T& x,T y,Args ...args){ckmax(x,y);ckmax(x,args...);}
template<typename T> void ckmin(T& x,T y){x=min(x,y);}
template<typename T,typename... Args>void ckmin(T& x,T y,Args ...args){ckmin(x,y);ckmin(x,args...);}                                                                                                                                                                                                                       
template<typename... T>void read(T&... args) {((cin >> args), ...);}
template<typename... T>void print(T&&... args) {((cout << args ), ...);}
template<class T> using MaxHeap = priority_queue<T>;
template<class T> using MinHeap = priority_queue<T, vector<T>, greater<T>>;
//----------MACROS----------
#define pb push_back
#define int long long  
typedef long long ll ; typedef pair<ll,ll> pi ; typedef vector<int> vi ; 
#define len(v) (int)v.size()
#define F_OR(i, a, b, s) for (int i=(a); (s)>0?i<(b):i>=(b); i+=(s))
#define F_OR1(e) F_OR(i, 0, e, 1)
#define F_OR2(i, e) F_OR(i, 0, e, 1)
#define F_OR3(i, b, e) F_OR(i, b, e, 1)
#define F_OR4(i, b, e, s) F_OR(i, b, e, s)
#define GET5(a, b, c, d, e, ...) e
#define F_ORC(...) GET5(__VA_ARGS__, F_OR4, F_OR3, F_OR2, F_OR1)
#define FOR(...) F_ORC(__VA_ARGS__)(__VA_ARGS__)
#define all(x) x.begin(), x.end() 
#define getunique(vt)  vt.erase(unique(all(vt)), vt.end()) // greater_equal -> multiset dec , greater set dec
#define vv(type,name,n,...)  vector<vector<type>> name(n,vector<type>(__VA_ARGS__))
//----------DEBUGGER----------
#ifndef ONLINE_JUDGE
#include "debugger.cpp"
#else
#define dbg(...)
#define tala3(...)
#endif
//----------CONSTANTS----------
const int64_t MAXI = __LONG_LONG_MAX__ ; 
const long double pi_ = atan2(0, -1) , eps = 1e-9; 
const int RANDOM = chrono::high_resolution_clock::now().time_since_epoch().count();
struct chash {
    static uint64_t splitmix64(uint64_t x) {
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }
    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};mt19937_64 rng(RANDOM);
inline ll rnd( ll l=0,ll r=1e18 ) { return uniform_int_distribution<ll>(l,r)(rng); }
// gp_hash_table<int, int, chash> dp[N];
//unordered_map<int,int ,chash> dp[N];
void input_output();




//----------SOLUTION----------
class SegmentTree {
public:
    ll merge(ll x, ll y) { return (x + y); }
    vector<ll> tree  ;
    int n , neutral = 0 ; 



    ll query(ll node, ll start, ll end, ll left_user, ll right_user) {

        if (left_user > right_user) 
            return neutral; 
        if (left_user == start && right_user == end) 
            return tree[node];
        ll tm = (start + end) / 2;
        return merge( query(node*2, start, tm, left_user, min(right_user, tm)) , query(node*2+1, tm+1, end, max(left_user, tm+1), right_user));
    }

    void set(int l,int r,int node,int idx,ll val1 ){
        if( l == r ){
            tree[node] += val1; 
            return;
        }
        int mid = ( l + r )/2 ; 
        int L =  2*node ; 
        int R =  2*node+1 ; 
        if( idx <= mid ) set( l, mid, L, idx , val1);
        else set( ( mid ) +1 , r , R , idx,  val1);
        tree[node]= merge( tree[L], tree[R] );
    }

    SegmentTree(int x ) {
        n = x;
        tree.resize(4 * n); 
    }

    void set(int idx,ll val1){
        set(0,n-1,1,idx,val1);
    }
    void del(){
        for ( int i=  0 ; i < 4*n ; i++) tree[i] = 0 ; 
    }
    ll query(ll l, ll r) {
        return query(1, 0, n - 1, l, r);
    }
    
    
};

struct Compressor {
    vector<ll> values;
    int n;
    void init() {
        values.clear();
        n = 0;
    }
    void add(ll x) { values.pb(x); }
    void run() {
        sort(all(values));
        values.resize(unique(all(values)) - values.begin());
        n = values.size();
    }
    int compress(ll x) { return lower_bound(all(values), x) - values.begin(); }
    int greatestSmallerThanOrEqual(ll x) {
        return (upper_bound(all(values), x) - values.begin()) - 1;
    }
    int greaterThanOrEqual(ll x) {
        return (lower_bound(all(values), x) - values.begin());
    }
    ll decompress(int p) { return values[p]; }
} ;

struct triplet {
    int left , right ,  index; 
    triplet(int l = 0  , int r = 0  , int e  = 0 ){
        left = l ; right = r ; index = e ;
    }   
};
void solve(){
    int n ; cin >> n ; 
    vi left(n) , right(n)  ,  ans1(n) , ans2(n); ;
    vector<triplet>intervals(n);
    Compressor comp ; 
    comp.init();
    FOR ( n ) {
        cin >> left[i] >> right[i];
        comp.add(left[i]);
        comp.add(right[i]);
    }   
    comp.run();
    FOR ( n ){
        left[i] = comp.compress(left[i]);
        right[i] = comp.compress(right[i]);
        intervals [i] = { left [i] , right[i ], i  }; 

    }
    sort( all(intervals ) , []( triplet&a , triplet b  ){
        if  ( a.left == b.left ) return a.right > b.right ;
        return a.left < b.left; 
    });


    SegmentTree sg(comp.n);

    FOR ( i ,n-1 , 0 , -1 ){
        ans1[intervals[i].index] = sg.query(0 , intervals[i].right);
        sg.set(intervals[i].right ,  1);
    }

    sg.del();
    
    FOR ( n ){
        ans2[intervals[i].index] = sg.query( intervals[i].right , comp.n-1); 
        sg.set(intervals[i].right ,  1);
    }

    FOR ( n ) cout << ans1[i] << " \n" [i == n - 1 ] ; 
    FOR ( n ) cout << ans2[i] << " \n" [i == n - 1 ] ; 
    


}
    


   
 
    
 

int32_t main() {
    input_output();
    int t = 1;
    for ( int i = 1 ; i <= t ; i++ ){
        tala3("------- Case-------" , i ,"\n" );
        solve();
        tala3("----------------------\n");      
    }     
    return (0.0) ;
}


void input_output() {
    cout.tie(0), cin.tie(0), ios_base::sync_with_stdio(0) ;  
    cout << fixed << setprecision(14) ; 
    srand(time(0)); 
    #ifndef ONLINE_JUDGE 
    freopen("inp.txt", "r", stdin); freopen("out.txt", "w", stdout); freopen("err.txt", "w", stderr); 
    #endif
}



