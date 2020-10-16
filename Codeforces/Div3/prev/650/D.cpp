#include <bits/stdc++.h>
#include "/home/itohdak/Codeforces/000/print.hpp"
using namespace std;
#define ll long long
#define REP(i,m,n) for(int i=(int)(m); i<(int)(n); i++)
#define rep(i,n) REP(i,0,n)
#define RREP(i,m,n) for(int i=(int)(m); i>=(int)(n); i--)
#define rrep(i,n) RREP(i,n-1,0)
#define all(v) v.begin(), v.end()
const int inf = 1e9+7;
const ll longinf = 1LL<<60;
const ll mod = 1e9+7;

void solve() {
  string s;
  int m;
  cin >> s >> m;
  vector<int> b(m);
  vector<int> cnt(26);
  for(char c: s) cnt[c-'a']++;
  rep(i, m) cin >> b[i];
  vector<bool> done(m);
  auto calc = [&](int pos) {
    int val = 0;
    rep(j, m) if(done[j]) val += abs(pos-j);
    return val;
  };
  int tmp = 25;
  vector<char> ans(m, 'x');
  int i = 0;
  int rem = m;
  while(rem > 0) {
    vector<int> pos;
    vector<int> val(m);
    rep(i, m) {
      val[i] = calc(i);
      if(val[i] == b[i] && !done[i]) {
        pos.push_back(i);
        rem--;
      }
    }
    while(cnt[tmp] < (int)pos.size()) tmp--;
    for(int p: pos) {
      ans[p] = 'a'+tmp;
      done[p] = true;
    }
    tmp--;
  }
  for(char c: ans) cout << c; cout << endl;
}
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int T;
  cin >> T;
  rep(t, T) solve();
  return 0;
}
