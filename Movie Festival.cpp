#include <bits/stdc++.h>
using namespace std ; 
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template<class T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template<class T> using ordered_multiset = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;
#define pb push_back
#define FAST  cout.tie(0), cin.tie(0), ios_base::sync_with_stdio(0) ; 
typedef long long ll ;
typedef pair<ll,pair<ll,ll>> tup;
typedef pair<ll,ll> pi;
#ifndef ONLINE_JUDGE
#include "debug.cpp"
#endif
#define all(x) x.begin(), x.end()
#define sortt(x) sort(all(x))
#define getunique(vt)  vt.erase(unique(all(vt)), vt.end())
#define rev(x)   reverse (all(x)) 
#define Sum(x) accumulate( x.begin() , x.end() , 0ll ) 
#define  ibits(x) 32 - __builtin_clz(x) // 32 - bts(x) if int 
#define  lbits(x) 64 -  __builtin_clzll(x) // 64 - bts(x) if long long 
ll modInverse(ll a , ll modd) {return a <= 1 ? a : modd - (ll)(modd/a) * modInverse(modd % a , modd) % modd;}
void makemod(ll &a, ll md ) { a =  (a % md + md) % md;}
bool sortinc(pi &a,pi &b){ if ( a.second == b.second ) return a.first < b.first ;  else  return a.second < b.second;}
bool sortdec(pi &a,pi &b){ if ( a.second == b.second ) return a.first > b.first ;  else  return a.second > b.second;}
ll mceil( ll a , ll b ) { return (a+b-1)/b ; }
template<typename... T>void read(T&... args) {((cin >> args), ...);}
template<typename... T>void print(T&&... args) {((cout << args /*<< " "*/), ...);}
template<class T> bool ckmax(T& a, const T& b){return a < b ? a = b, 1 : 0;}
template<class T> bool ckmin(T& a, const T& b){return a > b ? a = b, 1 : 0;}
template<typename F, typename S>ostream& operator <<(ostream& ostream, pair<F, S>& p) {cout << p.first << " " << p.second;return ostream;}
template<typename T>ostream& operator <<(ostream& ostream, vector<T>& v) {for(auto& element : v) {cout << element << " ";}return ostream;}
template<typename T>ostream& operator <<(ostream& ostream, vector<vector<T>>& v) {for(auto& row : v) {for(auto& cell : row) {cout << cell << " ";}cout << "\n";}return ostream;}


void Test_Case(){
    ll n ; read (n);
    vector<pi>LR ; 
    for  ( int i = 0 ; i < n  ; i++ ){
        int l , r ; 
        read ( l , r );
        LR.emplace_back(l,r);
    }   
    vector<ll>dp(n+5 , 0 ) ,  L , R;
    sortt(LR);
    for ( auto d : LR ) L.pb(d.first),R.pb(d.second);
    dp[n-1] = 1 ; 
    for ( int i = n - 2 ; i >= 0 ; i-- ){
        int search = lower_bound(all(L) , R[i]) - L.begin();; 
        ll check1 = 0 ;
        if ( search < n ) check1 =  1 + dp[search];
        dp[i] = max ( dp[i+1] , check1 );
    }
    print ( dp[0]);
          
}
     




int main() {
    cout << fixed << setprecision(2) ;
    FAST
    #ifndef ONLINE_JUDGE
        freopen("inp.txt", "r", stdin);
        freopen("out.txt", "w", stdout);
        freopen("err.txt", "w", stderr);
    #endif
    int t = 1;
    while (t-- ) Test_Case();
    return 0;
}
