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
 
const int MOD = 1e9 + 7; 
 
void solve( int tc ){
    int n ; 
    read ( n ); 
    matrix<ll>dp ( n+3 , vll ( n+3 , 0 )) ;
    matrix<char> input( n +2 , v<char>( n +2 ) ) ;
    FOR ( i , 1 , n ){
        FOR ( j , 1 , n ) {
            char x ; read ( x );
            input[i][j] = x ; 
        }
    }
    auto rec =  [&] ( auto& rec  , int row  ,int colunm   ) -> ll {
        if ( row > n or colunm > n ) return 0 ; 
        if ( input[row][colunm ] =='*' ) return 0 ; 
        if ( row == colunm && row == n ) return 1  ; 
        auto &ret = dp[row][colunm];
        if ( ret !=-1 ) return ret ;
        ll answer = 0 ; 
        (answer += rec ( rec , row +1 , colunm ) % MOD ) %= MOD  ;
        (answer += rec ( rec , row , colunm +1   ) % MOD  ) %= MOD ;
        return ret = answer ; 
 
    };
    // ll ans = rec ( rec , 1 , 1 ); 
    /*  iterative */ 
 
 
    dp[n][n] = 1 ;
    for ( int row = n ; row >= 1 ; row-- ) {
        for ( int colunm = n ; colunm >= 1 ; colunm-- ){
 
            auto &ret = dp[row][colunm]; 
            if ( row == n && row == colunm && input[row][colunm] != '*' ) {
                ret = 1 ; 
                continue ;   
            }
            if ( input [row][colunm] =='*') { ret = 0 ; continue ; }  
            if ( row +1 <= n ) (ret+= dp[row+1][colunm] % MOD ) %= MOD  ;
            if ( colunm +1 <= n ) (ret+= dp[row][colunm+1] % MOD ) %= MOD  ;  
        }
    } 
    print(dp[1][1]);
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
 
