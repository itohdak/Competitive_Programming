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

void Zalgorithm(string S, vector<int>& res) {
  res[0] = S.size();
  int i = 1, j = 0;
  while (i < S.size()) {
    while (i+j < S.size() && S[j] == S[i+j]) ++j;
    res[i] = j;
    if (j == 0) { ++i; continue;}
    int k = 1;
    while (i+k < S.size() && k+res[k] < j) res[i+k] = res[k], ++k;
    i += k; j -= k;
  }
}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int n; cin >> n;
  string t; cin >> t;
  string t1 = t.substr(0, n);
  string t2 = t.substr(n, n);
  reverse(all(t2));
  if(t1 == t2) {
    cout << t.substr(n) << endk;
    cout << 0 << endk;
    return 0;
  }
  string a = t1+t2;
  string b = t2+t1;
  vector<int> res1(2*n), res2(2*n);
  Zalgorithm(a, res1);
  Zalgorithm(b, res2);
  REP(i, 1, n) {
    if(res1[2*n-i] == i && res2[2*n-(n-i)] == (n-i)) {
      cout << t.substr(0, i) + t.substr(2*n-(n-i)) << endk;
      cout << i << endk;
      return 0;
    }
  }
  cout << -1 << endk;
  return 0;
}
