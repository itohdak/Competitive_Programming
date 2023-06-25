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
  int n; cin >> n;
  vector<int> A(n); rep(i, n) cin >> A[i];
  map<ll, int> mp;
  map<ll, int> even;
  rep(i, n) {
    mp[A[i]]++;
    if(A[i]%2==0) even[A[i]]++;
  }
  ll ans = 0;
  chmax(ans, mp.begin()->first);
  while(even.size()) {
    auto [v, c] = *(--even.end());
    even[v]--;
    if(even[v] == 0) even.erase(v);
    mp[v]--;
    if(mp[v] == 0) mp.erase(v);
    mp[v/2]++;
    if(v/2%2==0) even[v/2]++;
    auto [v2, c2] = *mp.begin();
    mp[v2]--;
    if(mp[v2] == 0) mp.erase(v2);
    mp[v2*3]++;
    if(v2%2==0) {
      even[v2]--;
      if(even[v2] == 0) even.erase(v2);
      even[v2*3]++;
    }
    // cout << mp << even << endk;
    chmax(ans, mp.begin()->first);
  }
  cout << ans << endk;
  return 0;
}
