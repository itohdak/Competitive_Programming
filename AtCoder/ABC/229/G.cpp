#include <bits/stdc++.h>
#include <print.hpp>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
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
  string s; cin >> s;
  ll k; cin >> k;
  int n = s.size();
  vector<int> diff;
  int tmp = 0;
  rep(i, n) if(s[i] == 'Y') diff.push_back(i-(tmp++));
  int m = diff.size();
  vector<ll> cum(m+1); rep(i, m) cum[i+1] = cum[i] + diff[i];
  auto bsearch = [&]() {
    auto test = [&](int t) {
      rep(i, m) {
        if(i+t > m) break;
        int med = i+t/2;
        ll x = diff[med];
        ll need = (x*(med-i)-(cum[med]-cum[i])) + ((cum[i+t]-cum[med])-x*(t-med+i));
        // cout << cum << endk;
        // cout << i << ' ' << t << ' ' << need << endk;
        if(need <= k) return true;
      }
      return false;
    };
    int ok = 0, ng = n+1;
    while(abs(ok-ng)>1) {
      int mid = (ok+ng)/2;
      (test(mid) ? ok : ng) = mid;
    }
    return ok;
  };
  cout << bsearch() << endk;
  return 0;
}
