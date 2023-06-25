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
  set<string> st;
  vector<int> id(n);
  iota(all(id), 0);
  do {
    vector<bool> done(n);
    string s;
    rep(i, n) {
      if(done[id[i]]) continue;
      s += char('a'+id[i]);
      done[id[i]] = true;
      if(id[i]-2 >= 0 && done[id[i]-2]) done[id[i]-1] = true;
      if(id[i]+2 < n && done[id[i]+2]) done[id[i]+1] = true;
    }
    st.insert(s);
  } while(next_permutation(all(id)));
  // for(auto ele: st) cout << ele << endk;
  map<char, vector<string>> cnt;
  for(auto ele: st) {
    cnt[ele.back()].push_back(ele);
  }
  cout << cnt['b'] << endk;
  cout << cnt['c'] << endk;
  // cout << cnt << endk;
  cout << st.size() << endk;
  return 0;
}
