#include <bits/stdc++.h>
#include <print.hpp>
using namespace std;
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
const ld eps = 1e-10;
template<typename T1, typename T2> inline void chmin(T1 &a, T2 b){if(a>b) a=b;}
template<typename T1, typename T2> inline void chmax(T1 &a, T2 b){if(a<b) a=b;}

void solve() {
  int n; ll t, a, b; cin >> n >> t >> a >> b;
  vector<int> hard(n); rep(i, n) cin >> hard[i];
  vector<ll> T(n); rep(i, n) cin >> T[i];
  vector<ll> comp(n);
  copy(all(T), begin(comp));
  comp.push_back(t+1);
  sort(all(comp));
  comp.erase(unique(all(comp)), end(comp));
  vector<int> id(n);
  rep(i, n) id[i] = lower_bound(all(comp), T[i]) - begin(comp);
  int m = comp.size();
  vector<int> cntA(m), cntB(m);
  int na = 0, nb = 0;
  rep(i, n) {
    if(hard[i]) {
      nb++;
      cntB[id[i]]++;
    } else {
      na++;
      cntA[id[i]]++;
    }
  }
  int score = 0;
  ll need = 0;
  int ans = 0;
  rep(i, m) {
    if(need+a*na <= comp[i]-1) {
      chmax(ans, score+na+min((int)((comp[i]-1-need-a*na)/b), nb));
    } else if(need <= comp[i]-1) {
      chmax(ans, score+min((int)((comp[i]-1-need)/a), na));
    }
    score += cntA[i] + cntB[i];
    need += a * cntA[i] + b * cntB[i];
    na -= cntA[i];
    nb -= cntB[i];
  }
  cout << ans << endk;
}
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int T;
  cin >> T;
  while(T--) solve();
  return 0;
}
