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

void solve(ifstream& fin, ofstream& fout) {
  int n; fin >> n;
  string I, O; fin >> I >> O;
  vector<string> ans(n, string(n, 'N'));
  rep(i, n) rep(j, n) {
    if(i == j) ans[i][j] = 'Y';
    else if(i < j) {
      bool ok = true;
      for(int k=i; k<j; k++) if(O[k]=='N') ok = false;
      for(int k=i+1; k<=j; k++) if(I[k]=='N') ok = false;
      ans[i][j] = (ok ? 'Y' : 'N');
    } else {
      bool ok = true;
      for(int k=i; k>j; k--) if(O[k]=='N') ok = false;
      for(int k=i-1; k>=j; k--) if(I[k]=='N') ok = false;
      ans[i][j] = (ok ? 'Y' : 'N');
    }
  }
  rep(i, n) {
    rep(j, n) {
      fout << ans[i][j];
    }
    fout << "\n";
  }
}
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  ifstream fin; fin.open("/home/itohdak/facebook/2020_qual/input/travel_restrictions_input.txt");
  ofstream fout; fout.open("/home/itohdak/facebook/2020_qual/output/travel_restrictions_output.txt");
  int T;
  fin >> T;
  rep(t, T) {
    cerr << "running test case " << t+1 << "\n";
    fout << "Case #" << t+1 << ":\n";
    solve(fin, fout);
  }
  fin.close();
  fout.close();
  return 0;
}
