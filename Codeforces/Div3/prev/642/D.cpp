#include <bits/stdc++.h>
#include "/home/itohdak/Codeforces/000/print.hpp"
using namespace std;
#define ll long long
#define REP(i,m,n) for(int i=(int)(m); i<(int)(n); i++)
#define rep(i,n) REP(i,0,n)
#define RREP(i,m,n) for(int i=(int)(m); i>=(int)(n); i--)
#define rrep(i,n) RREP(i,n-1,0)
#define REPL(i,m,n) for(ll i=(ll)(m); i<(ll)(n); i++)
#define repl(i,n) REPL(i,0,n)
#define all(v) v.begin(), v.end()
const int inf = 1e9+7;
const ll longinf = 1LL<<60;
const ll mod = 1e9+7;

void solve() {
  int N;
  cin >> N;
  priority_queue<pair<int, int>> Q; // length, -begin
  Q.push(make_pair(N, -0));
  vector<int> ans(N);
  int i = 1;
  while(!Q.empty()) {
    auto top = Q.top();
    Q.pop();
    ans[-top.second+(top.first-1)/2] = i;
    int length = (top.first-1)/2;
    if(length > 0) Q.push(make_pair(length, top.second));
    if(top.first-1-length > 0) Q.push(make_pair(top.first-1-length, top.second-(top.first+1)/2));
    i++;
  }
  rep(i, N) cout << ans[i] << ' ';
  cout << endl;
}
int main() {
  int T;
  cin >> T;
  rep(t, T) solve();
  return 0;
}
