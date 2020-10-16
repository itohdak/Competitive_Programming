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

random_device seed_gen;
mt19937 engine(seed_gen());

void solve(string filename) {
  ifstream fin;
  ofstream fout;
  fin.open(filename+".in");
  if(fin.fail()) return;
  int n, m;
  fin >> n >> m;
  uniform_real_distribution<> dist(0, n);
  vector<vector<int>> G(n);
  rep(i, m) {
    int a, b;
    fin >> a >> b;
    a--; b--;
    G[a].push_back(b);
    G[b].push_back(a);
  }
  set<int> se;
  rep(i, n) se.insert(i);
  int n_itr = 100;
  int rand_itr = n;
  int best = 0;
  vector<bool> bestVec(n);
  rep(i, n_itr) {
    set<int> ans;
    rep(j, rand_itr) {
    int r = dist(engine);
    if(!se.count(r)) continue;
    ans.insert(r);
    for(int ne: G[r]) se.erase(ne);
    se.erase(r);
    }
    if((int)ans.size() > best) {
      bestVec = vector<bool>(n);
      for(int v: ans) bestVec[v] = true;
      best = ans.size();
    }
  }
  fout.open(filename+".out");
  fout << best << "\n";
  rep(i, n) {
    if(i) fout << ' ';
    fout << bestVec[i];
  }
  fout << "\n";
  fin.close();
  fout.close();
}
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  string file[] = {"b1", "b2", "b3", "b4"};
  rep(i, 4) {
    cerr << "file " << file[i] << " processing..." << endl;
    solve(file[i]);
  }
  return 0;
}
