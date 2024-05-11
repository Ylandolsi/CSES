/*                Landolsi Mohamed Yassine !                */
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
#define vtake(x) for (auto &d : x) cin >> d;
#define FAST  cout.tie(0), cin.tie(0), ios_base::sync_with_stdio(0) ; 
typedef long long ll ; typedef long double ld ; typedef pair<ll,ll> pi;
typedef vector<ll> vll ; typedef vector<int> vii ; typedef vector<char> vcc ;  typedef vector<pi> vpp ; 
#ifndef ONLINE_JUDGE
#include "debugger.cpp"
#else
#define dbg(...)
#endif
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
void file() ; 
 
 
 
 
const ll N = 1e5 + 2 , MOD = 1e9 + 7 ;  
const ll M = 102 ; 
ll dp[N][M]  , n , m , a[N]; 
bool ordh = 1; 
ll rec ( int level , int current ) {
        if ( current > m  ) return 0 ; 
        if ( current <= 0 && level != 0 ) return 0 ; 
        if ( level == n -1   ) {
            if ( a[level] == current or a[level] == 0  ) return  1;
            else return 0 ; 
        } 
        auto &ret = dp[level][current];
        if ( ret != - 1 ) return ret;  
        
        if ( a[level] != 0 ) ordh = 0 ; 
        ll ans = 0 ; 
        
        if ( a[level] == 0 ){ 
            
            if ( ordh ){
                ordh = false ;
                for ( int i = 1 ; i <= m ; i++ ){
                    int x , y , z ; 
                    x = i -1 ; 
                    y = i + 1  ;
                    z = i ; 
 
                    ans += ( rec (  level +1 , x ) % MOD )  % MOD ;
                    ans += ( rec ( level +1 , y ) % MOD )  % MOD ;
                    ans += ( rec ( level +1 , z ) % MOD )  % MOD ;
                    
                }
                 
            }
            else ans = ( ( rec (level+1 , current-1 ) ) % MOD + ( rec ( level+1 ,current+1 ) )% MOD  + ( rec (level+1 , current ) ) % MOD )% MOD ; 
        }
        else if ( a[level] == current  ){
            ans = ( ( rec ( level+1 , a[level]-1 ) ) % MOD + ( rec (  level+1 ,a[level]+1 ) )% MOD  + ( rec (  level+1 , a[level] ) ) % MOD )% MOD ; 
            /*  rec ( level , current )
                current -→ representre ( l value eli hatineha f a[level+1])
            */
 
        }
 
        return ret = ans % MOD ;    
}
void solve(){ 
    memset(dp , -1 , sizeof(dp)) ; 
    read ( n , m ) ; 
    REP ( i , n ) read( a[i]);
    if ( n == 1 ){
        if (a[0] == 0 )print(m) ; 
        else print(1);
        return ; 
    }
    int ans = rec ( 0 , a[0] );  
    print(ans) ;
      
}
  
int main() {
    file();
    int t = 1;  
    while (t-- ) solve();     
    return 0;
}
void file(){
    FAST ; cout << fixed << setprecision(14) ; 
    #ifndef ONLINE_JUDGE 
    freopen("inp.txt", "r", stdin); freopen("out.txt", "w", stdout); freopen("err.txt", "w", stderr); 
    #endif
}
