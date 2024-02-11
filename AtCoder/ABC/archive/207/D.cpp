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
  vector<pair<int, int>> S(n), T(n);
  for(auto& [x, y]: S) cin >> x >> y;
  for(auto& [x, y]: T) cin >> x >> y;
  rep(i, n) rep(j, n) { // 中心
    map<ll, vector<ld>> mpS, mpT;
    set<pair<ld, ll>> stS, stT;
    ld minAngS = M_PI + eps;
    rep(k, n) {
      if(k != i) {
        ll dx = S[k].first-S[i].first, dy = S[k].second-S[i].second;
        ld ang = atan2l(dy, dx);
        chmin(minAngS, ang);
        stS.insert({ang, dx*dx+dy*dy});
        mpS[dx*dx+dy*dy].push_back(ang);
      }
    }
    ld minAngT = M_PI + eps;
    rep(k, n) {
      if(k != j) {
        ll dx = T[k].first-T[j].first, dy = T[k].second-T[j].second;
        ld ang = atan2l(dy, dx);
        chmin(minAngT, ang);
        stT.insert({ang, dx*dx+dy*dy});
        mpT[dx*dx+dy*dy].push_back(ang);
      }
    }
    bool ok = true;
    for(auto [d2, v]: mpS) {
      if(!mpT.count(d2) || v.size() != mpT[d2].size()) {
        ok = false;
        break;
      }
      vector<ld> s, t;
      rep(k, v.size()) {
        {
          ld tmp = v[k] - minAngS;
          if(tmp < -M_PI) tmp += 2*M_PI;
          if(tmp > M_PI) tmp -= 2*M_PI;
          s.push_back(tmp);
        }
        {
          ld tmp = mpT[d2][k] - minAngT;
          if(tmp < -M_PI) tmp += 2*M_PI;
          if(tmp > M_PI) tmp -= 2*M_PI;
          t.push_back(tmp);
        }
      }
      sort(all(s));
      sort(all(t));
      rep(k, v.size()) {
        if(abs(s[k]-t[k]) > eps) {
          ok = false;
          break;
        }
      }
      if(!ok) break;
    }
    // for(auto [ang, d2]: stS) {
    //   ld tmpAng = ang-minAngS+minAngT;
    //   if(tmpAng < -M_PI) tmpAng += 2*M_PI;
    //   if(tmpAng > M_PI) tmpAng -= 2*M_PI;
    //   if(!stT.count({tmpAng, d2})) {
    //     ok = false;
    //     break;
    //   }
    // }
    if(ok) {
      cout << "Yes" << endk;
      return 0;
    }
  }
  cout << "No" << endk;
  return 0;
}
