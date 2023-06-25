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
  vector<ll> A(2*n);
  vector<char> C(2*n);
  map<char, vector<ll>> mp;
  rep(i, 2*n) {
    cin >> A[i] >> C[i];
    mp[C[i]].push_back(A[i]);
  }
  for(auto& [_, v]: mp) sort(all(v));
  int r = mp['R'].size(), g = mp['G'].size(), b = mp['B'].size();
  auto calc = [&](vector<ll>& a, vector<ll>& b, vector<ll>& c) {
    ll ret = longinf;
    rep(i, a.size()) {
      int j = lower_bound(all(b), a[i]) - begin(b);
      if(j < b.size()) chmin(ret, abs(b[j]-a[i]));
      if(j-1 >= 0) chmin(ret, abs(b[j-1]-a[i]));
    }
    vector<ll> mnA(c.size(), longinf);
    vector<ll> mnB(c.size(), longinf);
    rep(i, c.size()) {
      int j = lower_bound(all(a), c[i]) - begin(a);
      if(j < a.size()) chmin(mnA[i], abs(a[j]-c[i]));
      if(j-1 >= 0) chmin(mnA[i], abs(a[j-1]-c[i]));
    }
    rep(i, c.size()) {
      int j = lower_bound(all(b), c[i]) - begin(b);
      if(j < b.size()) chmin(mnB[i], abs(b[j]-c[i]));
      if(j-1 >= 0) chmin(mnB[i], abs(b[j-1]-c[i]));
    }
    vector<int> idA(c.size()), idB(c.size());
    iota(all(idA), 0);
    iota(all(idB), 0);
    sort(all(idA), [&](int i, int j) {
      return mnA[i] < mnA[j];
    });
    sort(all(idB), [&](int i, int j) {
      return mnB[i] < mnB[j];
    });
    rep(i, min(2, (int)c.size())) {
      rep(j, min(2, (int)c.size())) {
        if(idA[i] == idB[j]) continue;
        chmin(ret, mnA[idA[i]]+mnB[idB[j]]);
      }
    }
    return ret;
  };
  if(r%2==0 && g%2==0 && b%2==0) {
    cout << 0 << endk;
  } else if(r%2==0) {
    cout << calc(mp['G'], mp['B'], mp['R']) << endk;
  } else if(g%2==0) {
    cout << calc(mp['R'], mp['B'], mp['G']) << endk;
  } else if(b%2==0) {
    cout << calc(mp['R'], mp['G'], mp['B']) << endk;
  } else {
    assert(false);
  }
  return 0;
}
