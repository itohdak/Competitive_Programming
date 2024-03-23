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
  string s; cin >> s;
  string t; cin >> t;
  int sz = s.size();
  vector<vector<int>> pos(26);
  vector<int> cnt(26);
  rep(i, sz) {
    pos[s[i]-'a'].push_back(i);
    cnt[s[i]-'a']++;
  }
  rep(i, 26) {
    int l = pos[i].size();
    rep(j, l) {
      pos[i].push_back(sz+pos[i][j]);
    }
  }
  auto next = [&](char c, ll p0, ll m) -> ll {
    auto& _pos = pos[c-'a'];
    int i = lower_bound(all(_pos), p0%sz) - begin(_pos);
    assert(i < _pos.size());
    ll p1 = p0/sz*sz + _pos[i];
    ll q = (m-1)/cnt[c-'a'], r = (m-1)%cnt[c-'a'];
    ll pm = p1/sz*sz + q*sz + _pos[i%cnt[c-'a']+r];
    return pm;
  };
  ll mx = longinf;
  auto bsearch = [&]() -> ll {
    auto test = [&](ll k) -> bool {
      ll ptmp = -1;
      rep(i, t.size()) {
        if(cnt[t[i]-'a'] == 0) return false;
        ptmp = next(t[i], ptmp+1, k);
        if(ptmp >= n*sz) return false;
      }
      return true;
    };
    ll ok = 0, ng = mx;
    while(abs(ok-ng) > 1) {
      ll mid = (ok+ng)/2;
      (test(mid) ? ok : ng) = mid;
    }
    return ok;
  };
  cout << bsearch() << endk;
  return 0;
}
