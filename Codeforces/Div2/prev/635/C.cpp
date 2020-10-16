#include <bits/stdc++.h>
// #include "/home/itohdak/Codeforces/000/print.hpp"
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

vector<vector<int> > E;
vector<ll> leaves;
vector<int> nchild;
int dfs(int tmp, int par, ll value){
  int cnt = 0;
  for(int c: E[tmp])
    if(c != par)
      cnt += dfs(c, tmp, value+1);
  nchild[tmp] = cnt;
  leaves.push_back(value-nchild[tmp]);
  return cnt+1;
}
int main() {
  int N, K;
  cin >> N >> K;
  vector<int> U(N), V(N);
  E = vector<vector<int> >(N);
  nchild = vector<int>(N);
  rep(i, N-1) {
    cin >> U[i] >> V[i];
    U[i]--, V[i]--;
    E[U[i]].push_back(V[i]);
    E[V[i]].push_back(U[i]);
  }
  dfs(0, -1, 0LL);
  sort(all(leaves), greater<ll>());
  cout << accumulate(leaves.begin(), leaves.begin()+K, 0LL) << endl;
  return 0;
}
