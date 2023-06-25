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
  vector<string> S(n); rep(i, n) cin >> S[i];
  int N = 52*52*52;
  vector<vector<int>> G(N);
  vector<vector<int>> from(N);
  auto id = [&](string s) {
    int ret = 0;
    assert(s.size() == 3);
    int pw = 1;
    rrep(i, 3) {
      ret += (s[i] >= 'a' && s[i] <= 'z' ? s[i]-'a' : s[i]-'A'+26) * pw;
      pw *= 52;
    }
    return ret;
  };
  rep(i, n) {
    string pre = S[i].substr(0, 3);
    string suf = S[i].substr(S[i].size()-3, 3);
    int idpre = id(pre), idsuf = id(suf);
    G[idpre].push_back(idsuf);
    from[idsuf].push_back(idpre);
  }
  vector<int> out(N);
  rep(i, N) out[i] = G[i].size();
  vector<int> win(N, -1);
  queue<int> q;
  rep(i, N) {
    if(out[i] == 0) {
      win[i] = 0;
      q.push(i);
    }
  }
  while(q.size()) {
    int cur = q.front(); q.pop();
    assert(win[cur] != -1);
    for(int ne: from[cur]) {
      if(out[ne] == 0 || win[ne] == 1) continue;
      out[ne]--;
      chmax(win[ne], 1-win[cur]);
      if(out[ne] == 0 || win[ne] == 1) {
        q.push(ne);
      }
    }
    // for(int ne: from[cur]) {
    //   if(win[ne] == -1) {
    //     out[ne]--;
    //     if(win[cur] == 0) {
    //       win[ne] = 1; q.push(ne);
    //     } else if(out[ne] == 0) {
    //       win[ne] = 0; q.push(ne);
    //     }
    //   }
    // }
  }
  rep(i, N) if(out[i] && !win[i]) win[i] = -1;
  rep(i, n) {
    string suf = S[i].substr(S[i].size()-3, 3);
    int idsuf = id(suf);
    if(win[idsuf] == 1) cout << "Aoki" << endk;
    else if(win[idsuf] == 0) cout << "Takahashi" << endk;
    else cout << "Draw" << endk;
  }
  return 0;
}
