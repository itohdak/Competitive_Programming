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

void solve() {
  int n, q; cin >> n >> q;
  vector<string> S(n);
  vector<int> scores(n);
  rep(i, n) cin >> S[i] >> scores[i];
  if(n == 3 || q > 40) {
    cout << endk;
    return;
  }
  if(q == 1) {
    ll cntAll = 0;
    vector<int> E(q);
    rep(i, 1<<q) {
      string s;
      rep(j, q) s += ((i>>j)&1 ? 'T' : 'F');
      bool ok = true;
      rep(j, n) {
        int p = 0;
        rep(k, q) if(S[j][k] == s[k]) p++;
        if(scores[j] != p) ok = false;
      }
      if(ok) {
        cntAll++;
        rep(j, q) {
          if(s[j] == 'T') E[j]++;
        }
      }
    }
    string ans;
    ll exp = 0;
    rep(i, q) {
      if(2*E[i] > cntAll) {
        ans += 'T';
        exp += E[i];
      } else {
        ans += 'F';
        exp += cntAll - E[i];
      }
    }
    ll g = __gcd(exp, cntAll);
    cout << ans << ' ' << exp/g << "/" << cntAll/g << endk;
  } else {
    int q1 = q/2, q2 = q-q1;
    map<vector<int>, pair<vector<ll>, ll>> cnt;
    rep(i, 1<<q1) {
      vector<ll> val(q);
      vector<int> points(n);
      rep(j, q1) {
        if((i>>j)&1) { // T
          val[j]++;
          rep(k, n) if(S[k][j] == 'T') points[k]++;
        } else {
          rep(k, n) if(S[k][j] == 'F') points[k]++;
        }
      }
      if(!cnt.count(points)) {
        cnt[points] = {val, 1};
      } else {
        auto next = cnt[points].first;
        rep(j, q) next[j] += val[j];
        cnt[points].first = next;
        cnt[points].second++;
      }
    }
    map<vector<int>, pair<vector<ll>, ll>> cnt2;
    rep(i, 1<<q2) {
      vector<ll> val(q);
      vector<int> points(n);
      rep(j, q2) {
        if((i>>j)&1) { // T
          val[q1+j]++;
          rep(k, n) if(S[k][q1+j] == 'T') points[k]++;
        } else {
          rep(k, n) if(S[k][q1+j] == 'F') points[k]++;
        }
      }
      if(!cnt2.count(points)) {
        cnt2[points] = {val, 1};
      } else {
        auto next = cnt2[points].first;
        rep(j, q) next[j] += val[j];
        cnt2[points].first = next;
        cnt2[points].second++;
      }
    }
    vector<ll> valAll(q);
    ll cntAll = 0;
    for(auto [points, p]: cnt) {
      auto [val, c] = p;
      vector<int> point2(n);
      rep(i, n) point2[i] = scores[i] - points[i];
      if(!cnt2.count(point2)) continue;
      auto p2 = cnt2[point2];
      auto [val2, c2] = p2;
      rep(i, q) {
        valAll[i] += val[i] * c2;
        valAll[i] += val2[i] * c;
      }
      cntAll += c * c2;
    }
    string ans;
    ll exp = 0;
    rep(i, q) {
      if(2*valAll[i] > cntAll) {
        ans += 'T';
        exp += valAll[i];
      } else {
        ans += 'F';
        exp += cntAll - valAll[i];
      }
    }
    ll g = __gcd(exp, cntAll);
    cout << ans << ' ' << exp/g << "/" << cntAll/g << endk;
  }
}
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int t; cin >> t;
  rep(i, t) {
    cout << "Case #" << i+1 << ": ";
    solve();
  }
  return 0;
}
