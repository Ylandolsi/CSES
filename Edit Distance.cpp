/*                Landolsi Mohamed Yassine !                */
#include <bits/stdc++.h>
using namespace std ; 
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template<class T> using indexed_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template <typename T> using matrix  = vector<vector<T>>; //   matrix<int> mat;
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
#define inf  __LONG_LONG_MAX__ 
#define Sum(x) accumulate( x.begin() , x.end() , 0ll ) 
#define  ibits(x) 32 - __builtin_clz(x) // 32 - bts(x) if int 
#define  lbits(x) 64 -  __builtin_clzll(x) // 64 - bts(x) if long long 
// msb(x) = 31 - __builtin_clz(x) int      .. msb(x) ll 63 - __builtin_clzll(x)  
bool sortinc(pi &a,pi &b){ if ( a.second == b.second ) return a.first < b.first ;  else  return a.second < b.second;}
bool sortdec(pi &a,pi &b){ if ( a.second == b.second ) return a.first > b.first ;  else  return a.second > b.second;}

void file() ; 
const int N = 5000 + 2  ;
int dp[N][N]; 
string s , t ; 
int n , m ; 
int go ( int sp , int tp )
{
   if ( tp == m  && sp == n ){
      return 0 ; 
   }
   auto &mem = dp[sp][tp];
   if ( mem != -1 ) return mem ; 
   int ans = 1e8 ; 
   if ( sp < n && tp < m && s[sp] == t[tp]){
      ans = min ( ans , go (sp +1 , tp+1) ); 
   }
   else {
      // replace 
      if ( sp < n && tp < m ) ans = min (ans , go ( sp +1 , tp+1  ) +1 ) ; 
      // add ;
      if ( tp < m )  ans = min ( ans , go ( sp , tp+1) + 1 ) ;  
      // del 
      if ( sp < n )  ans = min ( ans , go ( sp + 1  , tp ) + 1 ) ;  

   }
   return mem = ans ; 

}

void solve(){
   read ( s , t );
   n = sz(s) , m = sz(t); 
   memset(dp , -1 , sizeof(dp));
   cout << go( 0 , 0 ) ; 
}

int main() {
    file();
    int t = 1; 
    while (t-- ) { 
      solve(); 
    } 
    return 0;
}
void file(){
   FAST ; cout << fixed << setprecision(14) ; 
   #ifndef ONLINE_JUDGE 
   freopen("inp.txt", "r", stdin); freopen("out.txt", "w", stdout); freopen("err.txt", "w", stderr); 
   #endif
}

