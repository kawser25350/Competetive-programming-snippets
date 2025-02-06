
/*
 * Author: Kawser Ahmmed
 * File:   factory_machine.cpp
 */
    #include<bits/stdc++.h>
using namespace std;

#define int long long  
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
void _print(int x){ cout << x; }  // `int` now covers `long long`
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

 
int32_t main()
{
    fast_code
    
 
   int n,t;cin>>n>>t;

   vi v(n); FOR(i,n)cin>>v[i];




 auto ok=[&](long long mid)
    {
        int total=0;
        for (int i = 0;i < n;i++) {
            total += (mid / v[i]);
            if (total >= t) {
                return true;
            }
        }
        return false;
        };


   int l=0,r=1e18,ans,mid;

   while(l<=r){

      mid=l+(r-l)/2;

      if(ok(mid)){

         r=mid-1;

         ans=mid;

      }
      else{

         l=mid+1;
      }
   }

   cout<<ans<<ln;


        
    

    return 0;
}