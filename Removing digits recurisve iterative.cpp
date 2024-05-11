#include <bits/stdc++.h>
using namespace std ; 
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template<class T> using indexed_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template <typename T> using matrix  = vector<vector<T>>; //   matrix<int> mat;
template <typename T1 > using v = vector<T1> ; // v<char> ; 
template <typename T1, typename T2> using vp = vector<pair<T1, T2>> ; // vp<ll,ll>
template<class T> using MaxHeap = priority_queue<T>;
template<class T> using MinHeap = priority_queue<T, vector<T>, greater<T>>;
template<typename... T>void read(T&... args) {((cin >> args), ...);}
template<typename... T>void print(T&&... args) {((cout << args << " "), ...);}
template<typename... T>void printl(T&&... args) {((cout << args << "\n"), ...);}
template<class T , class V > bool ckmax(T& a, const V& b){return a < b ? a = b, 1 : 0;}
template<class T , class V > bool ckmin(T& a, const V& b){return a > b ? a = b, 1 : 0;}
#define pb push_back
#define FAST  cout.tie(0), cin.tie(0), ios_base::sync_with_stdio(0) ; 
typedef long long ll ; typedef long double ld ; typedef pair<ll,ll> pi;
#ifndef ONLINE_JUDGE
#include "debugger.cpp"
#else
#define dbg(...)
#endif
#define vll v<ll>
#define FOR( i , debut,  fin) for( ll i = debut ; i <= fin ; i++  )
#define FORR( i , debut,  fin) for( ll i = debut ; i >= fin ; i--  )
#define REP(i, n) for(int i = 0; i < int(n); i++) 
#define REPP(i, n) for(int i = int(n-1); i >= 0; i--) 
#define sz(vect) (int)vect.size()
#define all(x) x.begin(), x.end()
#define sortt(x) sort(all(x))
#define all1(v) (v).begin()+1,(v).end()
#define getunique(vt)  vt.erase(unique(all(vt)), vt.end())
#define rev(x)   reverse (all(x)) 
#define Yes cout <<"Yes\n"
#define No cout <<"No\n"
#define inf  __LONG_LONG_MAX__ 
#define Sum(x) accumulate( x.begin() , x.end() , 0ll ) 
#define  ibits(x) 32 - __builtin_clz(x) // 32 - bts(x) if int 
#define  lbits(x) 64 -  __builtin_clzll(x) // 64 - bts(x) if long long 
// msb(x) = 31 - __builtin_clz(x) int      .. msb(x) ll 63 - __builtin_clzll(x)  
bool sortinc(pi &a,pi &b){ if ( a.second == b.second ) return a.first < b.first ;  else  return a.second < b.second;}
bool sortdec(pi &a,pi &b){ if ( a.second == b.second ) return a.first > b.first ;  else  return a.second > b.second;}
 
 
 
void solve( int tc ){
    int n ; 
    read ( n ); 
    vll dp ( n +3 , -1 ); 
    auto rec =  [&] ( auto& rec  , ll x  ) -> ll {
        if ( x == 0 ) return 0 ; 
        if ( x < 0 ) return 1e15 ;
        auto &ret = dp[x];
        if ( ret !=-1 ) return ret ;
        ll answer = 1e15 ; 
        string numbers = to_string(x);
        for ( int i = 0 ; i < sz(numbers) ; i++ ){
            ll num = numbers[i] -'0'; 
            if ( num == 0 ) continue ; 
            ckmin( answer , 1 + rec (rec , x - num  ) ); 
        } 
        return ret = answer ; 
 
    };
    
    REP (i , n+1 ) dp[i] = 1e15 ; 
    dp[0] = 0; 
    for ( int i = 1 ; i <= n ; i++ ){
        string numbers = to_string(i);
        for ( int j = 0 ; j < sz(numbers) ; j++ ){
            ll num = numbers[j] -'0'; 
            if ( num == 0  or ( i - num < 0 )) continue ; 
            ckmin( dp[i] , 1 + dp[i-num]  ); 
        }
    }
    //ll ans = rec ( rec , n);
    ll ans = dp[n];
    print(ans);
}
       
 
    
 
int main() {
    FAST ; cout << fixed << setprecision(14) ; 
    #ifndef ONLINE_JUDGE 
    freopen("inp.txt", "r", stdin); freopen("out.txt", "w", stdout); freopen("err.txt", "w", stderr); 
    auto start = std::chrono::high_resolution_clock::now();
    #endif
    int t = 1; 
    while (t-- )  
    {
        solve(t);
        // if ( solve(t) )cout <<"YES\n"; else cout <<"NO\n";  
        
    }
    #ifndef ONLINE_JUDGE 
    auto end =chrono::high_resolution_clock::now(); auto duration = chrono::duration_cast<chrono::milliseconds>(end - start); cerr << "Execution time: " << duration.count() << " milliseconds" << std::endl ; 
    #endif
    return 0;
}
