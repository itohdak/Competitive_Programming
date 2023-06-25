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
  map<ll, int> cnt;
  rep(i, n) cnt[B[i]]++;
  set<ll> ans;
  rep(i, n) {
    ll val = A[0]^B[i];
    map<ll, int> need;
    auto ok = [&]() {
      rep(j, n) need[val^A[j]]++;
      for(auto [v, c]: need) {
        if(!cnt.count(v)) return false;
        if(cnt[v] != c) return false;
      }
      return true;
    };
    if(ok()) ans.insert(val);
  }
  cout << ans.size() << endk;
  for(auto a: ans) cout << a << endk;
  return 0;
}
