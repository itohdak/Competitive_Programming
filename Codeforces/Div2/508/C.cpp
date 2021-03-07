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
  vector<ll> A(n); rep(i, n) cin >> A[i];
  vector<ll> B(n); rep(i, n) cin >> B[i];
  map<ll, pair<int, int>> mp;
  rep(i, n) mp[A[i]].first++;
  rep(i, n) mp[B[i]].second++;
  ll ans = 0;
  rep(i, 2*n) {
    if(i%2) {
      if(mp.rbegin()->second.second) {
        ans -= mp.rbegin()->first;
        mp.rbegin()->second.second--;
        if(mp.rbegin()->second == make_pair(0, 0)) mp.erase(mp.rbegin()->first);
      } else {
        mp.rbegin()->second.first--;
        if(mp.rbegin()->second == make_pair(0, 0)) mp.erase(mp.rbegin()->first);
      }
    } else {
      if(mp.rbegin()->second.first) {
        ans += mp.rbegin()->first;
        mp.rbegin()->second.first--;
        if(mp.rbegin()->second == make_pair(0, 0)) mp.erase(mp.rbegin()->first);
      } else {
        mp.rbegin()->second.second--;
        if(mp.rbegin()->second == make_pair(0, 0)) mp.erase(mp.rbegin()->first);
      }
    }
  }
  cout << ans << endk;
  return 0;
}
