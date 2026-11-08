/*
 * Author: Kawser Ahmmed
 * File:   string_matching.cpp
 */
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
 
using namespace std;
using namespace __gnu_pbds;
 
#define ll long long
#define ull unsigned long long
#define lld long double
#define mod 1000000007
#define FOR(a, c) for (int(a) = 0; (a) < (c); (a)++)
#define FORL(a, b, c) for (int(a) = (b); (a) <= (c); (a)++)
#define FORR(a, b, c) for (int(a) = (b); (a) >= (c); (a)--)
#define INF 1000000000000000003
#define vi vector<long long>
#define pi pair<long long,long long>
#define F first
#define S second
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(),x.rend()
#define PB push_back
#define POB pop_back
#define MP make_pair
#define ln '\n'
#define fast_code  ios::sync_with_stdio(0);  cin.tie(NULL);
 
// Debugger
#define printarr(arr) for(int i = 0; i < sizeof(arr) / sizeof(arr[0]); i++) cout<<arr[i]<<" "; cout<<'\n';
#define debug(x) cout<<#x<<" = "; _print(x); cout<<'\n';
 
// _print functions
void _print(ll x){ cout << x; }  // Fixed typo here
void _print(int x){ cout << x; }  
void _print(double x){ cout << x; }
void _print(string x){ cout << x; }
void _print(char x){ cout << x; }
void _print(bool x){ cout << (x ? "true" : "false"); }
 
 
template<class T>void _print(vector<T> v){ cout << "[ "; for(T i : v){ _print(i); cout << " "; } cout << "]"; }
template<class T>void _print(set<T> v){ cout << "[ "; for(T i : v){ _print(i); cout << " "; } cout << "]"; }
template<class T>void _print(unordered_set<T> v){ cout << "[ "; for(T i : v){ _print(i); cout << " "; } cout << "]"; }
template<class T, class V>void _print(pair<T,V> p){ cout << "{"; _print(p.first); cout << ", "; _print(p.second); cout << "}"; }
template<class T, class V>void _print(map<T,V> m){ cout << "[ "; for(auto i : m){ _print(i); cout << " "; } cout << "]"; }
template<class T, class V>void _print(unordered_map<T,V> um){ cout << "[ "; for(auto i:um){ _print(i); cout << " "; } cout << "]"; }
 
//pbds
template <typename T>using pbds = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
 
const int p1 = 137, mod1 = 127657753, p2 = 277, mod2 = 987654319;
const int N = 1e6 + 9;
 
int power(long long x, long long n, int MOD) { // O(logn)
   int ans = 1 % MOD;
   while (n > 0) {
      if (n & 1) {
         ans = 1LL * ans * x % MOD;
      }
      x = 1LL * x * x % MOD;
      n >>= 1;
   }
   return ans;
}
 
pair<int, int> pw[N], ipw[N];
 
void prec() { // O(n)
   pw[0] = { 1,1 };
   for (int i = 1;i < N;i++) {
      pw[i].first = 1LL * pw[i - 1].first * p1 % mod1;
      pw[i].second = 1LL * pw[i - 1].second * p2 % mod2;
   }
   int ip1 = power(p1, mod1 - 2, mod1);
   int ip2 = power(p2, mod2 - 2, mod2);
   ipw[0] = { 1,1 };
   for (int i = 1;i < N;i++) {
      ipw[i].first = 1LL * ipw[i - 1].first * ip1 % mod1;
      ipw[i].second = 1LL * ipw[i - 1].second * ip2 % mod2;
   }
}
 
pair<int, int> string_hash(string s) { // O(n)
   int n = s.size();
   pair<int, int> hs({ 0,0 });
   for (int i = 0;i < n;i++) {
      hs.first = (hs.first % mod1 + 1LL * s[i] * pw[i].first % mod1) % mod1;
      hs.second = (hs.second % mod2 + 1LL * s[i] * pw[i].second % mod2) % mod2;
   }
   return hs;
}
 
pair<int, int> pref[N];
void build(string s) { // O(n)
   int n = s.size();
   for (int i = 0;i < n;i++) {
      pref[i].first = 1LL * s[i] * pw[i].first % mod1;
      if (i) pref[i].first = (pref[i].first + pref[i - 1].first) % mod1;
      pref[i].second = 1LL * s[i] * pw[i].second % mod2;
      if (i) pref[i].second = (pref[i].second + pref[i - 1].second) % mod2;
   }
}
 
pair<int, int> get_hash(int i, int j) { // O(1)
   pair<int, int> hs({ 0,0 });
   hs.first = pref[j].first;
   if (i) hs.first = (hs.first - pref[i - 1].first + mod1) % mod1;
   hs.first = 1LL * hs.first * ipw[i].first % mod1;
 
   hs.second = pref[j].second;
   if (i) hs.second = (hs.second - pref[i - 1].second + mod2) % mod2;
   hs.second = 1LL * hs.second * ipw[i].second % mod2;
 
   return hs;
}
 
 
int main()
{
    fast_code
    
    prec();
 
    string a,b;cin>>a>>b;
   
   int n=a.size(),m=b.size();
   build(a);
 
   pair<int,int> s2=string_hash(b);
   int ans=0;
 
   for(int i=0;i+m-1<n;i++)
   {
 
        if(s2==get_hash(i,i+m-1))
        {
           
         ans++;
        }
   }
 
   cout<<ans<<ln;
}
