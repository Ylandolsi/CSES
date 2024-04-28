#include <bits/stdc++.h>
using namespace std ; 
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template<class T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template<class T , class V > using ordered_set_pair = tree<pair<T,V>, null_type, less<pair<T,V>>, rb_tree_tag, tree_order_statistics_node_update>;
template<class T> using ordered_multiset = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;
#define pb push_back
#define FAST  cout.tie(0), cin.tie(0), ios_base::sync_with_stdio(0) ; 
typedef long long ll ;
typedef long double ld ; 
typedef pair<ll,ll> pi;
#ifndef ONLINE_JUDGE
#include "debugger.cpp"
#endif
template <typename T> using matrix  = vector<vector<T>>; //   matrix<int> mat;
template <typename T1, typename T2> using vp = vector<pair<T1, T2>> ; // vp<ll,ll>
#define foor( i , debut,  fin) for( int i = debut ; i <= fin ; i++  )
#define foorr( i , debut,  fin) for( int i = debut ; i >= fin ; i--  )
#define sz(vect) (int)vect.size()
#define all(x) x.begin(), x.end()
#define sortt(x) sort(all(x))
#define all1(v) (v).begin()+1,(v).end()
#define getunique(vt)  vt.erase(unique(all(vt)), vt.end())
#define rev(x)   reverse (all(x)) 
#define yn(x) if ( x == 1 ) cout << "Yes\n"; else cout<<"No\n";
#define inf  __LONG_LONG_MAX__ 
#define Sum(x) accumulate( x.begin() , x.end() , 0ll ) 
#define  ibits(x) 32 - __builtin_clz(x) // 32 - bts(x) if int 
#define  lbits(x) 64 -  __builtin_clzll(x) // 64 - bts(x) if long long 
// msb(x) = 31 - __builtin_clz(x) int      .. msb(x) ll 63 - __builtin_clzll(x)  
bool sortinc(pi &a,pi &b){ if ( a.second == b.second ) return a.first < b.first ;  else  return a.second < b.second;}
bool sortdec(pi &a,pi &b){ if ( a.second == b.second ) return a.first > b.first ;  else  return a.second > b.second;}
template<typename... T>void read(T&... args) {((cin >> args), ...);}
template<typename... T>void print(T&&... args) {((cout << args << " "), ...);}
template<typename... T>void printl(T&&... args) {((cout << args << "\n"), ...);}
template<class T , class V > bool ckmax(T& a, const V& b){return a < b ? a = b, 1 : 0;}
template<class T , class V > bool ckmin(T& a, const V& b){return a > b ? a = b, 1 : 0;}
 
void solve(){
    int n ; read ( n ) ;
    vector<ll>a(n);
    ll ans = 0  ;
    foor ( i  , 0  , n -1 ) {
        read ( a[i]);  
    }
    sortt(a);
    if ( a[0] != 1 ) print(1);
    else {
        ans = a[0];
        foor ( i , 1 , n -1 ){
            if ( a[i] - a[i-1] > 1 && a[i] > ans + 1 ){
                print ( ans +1 );
                return ; 
            }
            ans += a[i];
        }
        print ( ans +1);
    }
}
    
 
int main() {
    FAST ; cout << fixed << setprecision(14) ; 
    #ifndef ONLINE_JUDGE 
    freopen("inp.txt", "r", stdin); freopen("out.txt", "w", stdout); freopen("err.txt", "w", stderr); 
    #endif
    auto start = std::chrono::high_resolution_clock::now();
    int t = 1; 
    while (t-- ) { solve(); }
    auto end =chrono::high_resolution_clock::now(); auto duration = chrono::duration_cast<chrono::milliseconds>(end - start); cerr << "Execution time: " << duration.count() << " milliseconds" << std::endl;
    return 0;
}
