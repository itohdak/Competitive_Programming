#include <bits/stdc++.h>
#include <print.hpp>
using namespace std;
// #include <atcoder/all>
// using namespace atcoder;
#define ll long long
#define ld long double
#define REP(i,m,n) for(int i=(int)(m); i<(int)(n); i++)
#define rep(i,n) REP(i,0,n)
#define RREP(i,m,n) for(int i=(int)(m); i>=(int)(n); i--)
#define rrep(i,n) RREP(i,(n)-1,0)
#define all(v) v.begin(), v.end()
#define endk '\n'
const int inf = 1e9+7;
const ll longinf = 1LL<<60;
const ll mod = 1e9+7;
const ll mod2 = 998244353;
const ld eps = 1e-10;
template<typename T1, typename T2> inline void chmin(T1 &a, T2 b){if(a>b) a=b;}
template<typename T1, typename T2> inline void chmax(T1 &a, T2 b){if(a<b) a=b;}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  ll n; cin >> n;
  map<ll, int> pw3;
  {
    ll pw = 1;
    int a = 0;
    while(1) {
      if(pw > 1) pw3[pw] = a;
      if(n/3 < pw) break;
      pw *= 3;
      a++;
    }
  }
  {
    ll pw = 5;
    int b = 1;
    while(1) {
      ll rem = n - pw;
      if(pw3.count(rem)) {
        cout << pw3[rem] << ' ' << b << endk;
        return 0;
      }
      if(n/5 < pw) break;
      pw *= 5;
      b++;
    }
  }
  cout << -1 << endk;
  return 0;
}
