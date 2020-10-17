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
  string s; fin >> s;
  vector<int> cnt(2);
  rep(i, n) cnt[s[i]=='B']++;
  fout << (abs(cnt[0]-cnt[1])==1 ? "Y" : "N") << "\n";
}
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  string baseUrl = "/home/itohdak/facebook/2020_qual/";
  fin.open(baseUrl + "input/alchemy_input.txt");
  fout.open(baseUrl + "output/alchemy_output.txt");
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
