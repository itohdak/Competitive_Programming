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
  int k; cin >> k;
  string s; cin >> s;
  int q; cin >> q;
  vector<int> A((1<<(k+1))-1);
  REP(i, (1<<k)-1, (1<<(k+1))-1) {
    A[i] = 1;
  }
  vector<int> id;
  unordered_map<int, int> idinv;
  int pw = 1;
  for(int i=0; i<1<<(k-1); i+=pw, pw*=2) {
    for(int j=i+pw-1; j>=i; j--) {
      id.push_back(j);
    }
  }
  reverse(all(id));
  rep(i, id.size()) {
    idinv[id[i]] = i;
  }
  assert(id.size() == s.size());
  rep(i, (1<<k)-1) {
    int c1 = A[2*id[i]+1], c2 = A[2*id[i]+2];
    if(s[i] == '0') A[id[i]] = c1;
    else if(s[i] == '1') A[id[i]] = c2;
    else A[id[i]] = c1 + c2;
  }
  rep(i, q) {
    int p; char c; cin >> p >> c;
    p--;
    s[p] = c;
    while(p < (1<<k)-1) {
      int c1 = A[2*id[p]+1], c2 = A[2*id[p]+2];
      if(s[p] == '0') A[id[p]] = c1;
      else if(s[p] == '1') A[id[p]] = c2;
      else A[id[p]] = c1 + c2;
      if(id[p] == 0) break;
      p = idinv[(id[p]-1)>>1];
    }
    cout << A[0] << endk;
  }
}
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int T = 1;
  // cin >> T;
  while(T--) solve();
  return 0;
}
