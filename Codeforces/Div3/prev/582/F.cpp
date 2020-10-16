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
  int n, k; cin >> n >> k;
  vector<int> P(n);
  rep(i, n) {
    cin >> P[i];
    P[i]--;
  }
  vector<int> Q(n);
  rep(i, n) {
    cin >> Q[i];
    Q[i]--;
  }
  vector<set<int>> vst;
  int last = -1;
  vst.push_back(set<int>());
  rep(i, n) {
    vst.back().insert(P[i]);
    vst.back().insert(Q[i]);
    if((int)vst.back().size() == i-last) {
      vst.push_back(set<int>());
      last = i;
    }
  }
  vst.pop_back();
  if((int)vst.size() < k) {
    cout << "NO" << endk;
  } else {
    cout << "YES" << endk;
    string ans(n, ' ');
    char c = 'a';
    for(auto st: vst) {
      for(int i: st) {
        ans[i] = c;
      }
      if(c < 'z') c++;
    }
    cout << ans << endk;
  }
}
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int T = 1;
  while(T--) solve();
  return 0;
}
