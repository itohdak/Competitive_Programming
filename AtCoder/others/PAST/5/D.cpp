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
  vector<string> S(n);
  rep(i, n) cin >> S[i];
  vector<pair<string, int>> T(n);
  rep(i, n) {
    int j = 0;
    while(j < S[i].size() && S[i][j] == '0') j++;
    T[i].first = S[i].substr(j);
    T[i].second = j;
  }
  vector<int> id(n);
  rep(i, n) id[i] = i;
  sort(all(id), [&](int i, int j) {
    if(T[i].first.size() != T[j].first.size()) {
      return T[i].first.size() < T[j].first.size();
    } else if(T[i].first != T[j].first) {
      return T[i].first < T[j].first;
    } else {
      return T[i].second > T[j].second;
    }
  });
  for(int i: id) cout << S[i] << endk;
  return 0;
}