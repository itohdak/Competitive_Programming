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
  ifstream fin;
  ofstream fout;
  fin.open("./sort.in");
  if(fin.fail()) return;
  int n;
  fin >> n;
  vector<int> A(n);
  rep(i, n) fin >> A[i];
  sort(all(A));
  fout.open("./sort.out");
  rep(i, n) {
    if(i) fout << ' ';
    fout << A[i];
  }
  fout << "\n";
  fin.close();
  fout.close();
}
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  solve();
  return 0;
}
