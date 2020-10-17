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

ifstream fin;
ofstream fout;
void solve() {
  int n; fin >> n;
  vector<ll> P(n);
  vector<ll> H(n);
 rep(i, n) fin >> P[i] >> H[i];
  set<pair<ll, ll>> st1;
  set<pair<ll, ll>, greater<pair<ll, ll>>> st2;
  rep(i, n) {
    st1.insert({P[i], P[i]+H[i]});
    st2.insert({P[i], P[i]-H[i]});
  }
  map<ll, ll> dp1, dp2;
  for(auto p: st1) {
    dp1[p.second] = max(dp1[p.first]+p.second-p.first, dp1[p.second]);
  }
  for(auto p: st2) {
    dp2[p.second] = max(dp2[p.first]+p.first-p.second, dp2[p.second]);
  }
  ll mx = 0;
  for(auto ele: dp1) {
    mx = max(ele.second+dp2[ele.first], mx);
  }
  for(auto ele: dp2) {
    mx = max(ele.second+dp1[ele.first], mx);
  }
  fout << mx << "\n";
}
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  string baseUrl = "/home/itohdak/facebook/2020_qual/";
  fin.open(baseUrl + "input/timber_input.txt");
  fout.open(baseUrl + "output/timber_output.txt");
  int T;
  fin >> T;
  rep(t, T) {
    cerr << "running test case " << t+1 << "\n";
    fout << "Case #" << t+1 << ": ";
    solve();
  }
  fin.close();
  fout.close();
  return 0;
}
