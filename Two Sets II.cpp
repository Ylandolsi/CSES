#include <bits/stdc++.h>
using namespace std ; 
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define pb push_back
typedef long long ll ; typedef pair<ll,ll> pi ; typedef vector<int> vi ; 
#define len(v) (int)v.size()
#ifndef ONLINE_JUDGE
#include "debugger.cpp"
#else
#define dbg(...)
#define tala3(...)
#endif
#define F_OR(i, a, b, s) for (int i=(a); (s)>0?i<(b):i>=(b); i+=(s))
#define F_OR1(e) F_OR(i, 0, e, 1)
#define F_OR2(i, e) F_OR(i, 0, e, 1)
#define F_OR3(i, b, e) F_OR(i, b, e, 1)
#define F_OR4(i, b, e, s) F_OR(i, b, e, s)
#define GET5(a, b, c, d, e, ...) e
#define F_ORC(...) GET5(__VA_ARGS__, F_OR4, F_OR3, F_OR2, F_OR1)
#define forr(...) F_ORC(__VA_ARGS__)(__VA_ARGS__)
#define all(x) x.begin(), x.end() 
#define getunique(vt)  vt.erase(unique(all(vt)), vt.end()) // greater_equal -> multiset dec , greater set dec
template<class T> using indexed_set_dec = tree<T, null_type, greater_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;
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
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////

template<int MOD>
struct mint {
  ll x;
  mint(ll x=0):x((x%MOD+MOD)%MOD){}
  mint& operator+=(const mint a) {if ((x += a.x) >= MOD) x -= MOD;return *this;}
  mint& operator-=(const mint a) {if ((x += MOD-a.x) >= MOD) x -= MOD;return *this;}
  mint& operator*=(const mint a) {(x *= a.x) %= MOD;return *this;}
  mint operator+(const mint a) const {mint res(*this);return res+=a;}
  mint operator-(const mint a) const {mint res(*this);return res-=a;}
  mint operator*(const mint a) const {mint res(*this);return res*=a;}
  bool operator==(const mint& rhs) const { return val() == rhs.val(); }
  bool operator!=(const mint& rhs) const { return !(val() == rhs.val()); }
  bool operator>(const mint& rhs) const { return (val() > rhs.val()); }
  bool operator>=(const mint& rhs) const { return (val() >= rhs.val()); }
  bool operator<=(const mint& rhs) const { return (val() <= rhs.val()); }
  bool operator<(const mint& rhs) const { return (val() < rhs.val()); }
  int val() const { return x; }
  mint pow(ll b) const {
    mint res(1), a(*this);
    while (b) {
      if (b & 1) res *= a;
      a *= a;
      b >>= 1;
    }
    return res;
  }
  // for prime MOD
  mint inv() const {return pow(MOD-2);}
  mint& operator/=(const mint a) {return (*this) *= a.inv();}
  mint operator/(const mint a) const {mint res(*this);return res/=a;}
  std::string to_string() const { return std::string("{") + std::to_string(val()) + "}"; }


};
const int MOD = 1e9+ 7 ; 
using Mint=  mint<MOD>  ;
ostream& operator<<(ostream& os, const Mint& a) {os << a.x; return os;}

 
 
const int N = 505 , M = 250010 , mod = 1e9 +7 ; 
int dp[N][M]; 
int n ,  total  ; 
int rec ( int level , int sum ){
    if ( level == n + 1  ){
        if ( total - sum  ==  sum  ){
            return 1; 
        }
        else return 0 ; 
    }
    auto &ret = dp[level][sum];
    if ( ret != -1 ) return ret   ; 
    int ans =  0 ; 
    ans = ( ( ans  + rec ( level +1 , sum + level ) )%mod  + mod )% mod   ; 
    ans = (( ans + rec ( level +1 , sum  ) ) % mod + mod ) % mod    ;
    return ret = ans % mod   ;  
}


void solve(){
    total = 0 ; 
    cin >> n ; 
    total = n*(n+1)/2;

    if ( total % 2 != 0 ){ cout << 0 <<  endl ; return ;}
    memset(dp , -1 , sizeof(dp)); 
    Mint x = (Mint)rec ( 1 , 0 )  ; 
    x/=2 ; 
    cout << x << endl ;
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



