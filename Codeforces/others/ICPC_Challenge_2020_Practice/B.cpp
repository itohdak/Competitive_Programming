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
  fin.open("in/"+filename+".in");
  if(fin.fail()) return;
  int n, m;
  fin >> n >> m;
  uniform_real_distribution<> dist(0, n);
  vector<set<int>> G(n);
  rep(i, m) {
    int a, b;
    fin >> a >> b;
    a--; b--;
    G[a].insert(b);
    G[b].insert(a);
  }
  vector<bool> avail(n, true);
  set<pair<int, int>> se;
  vector<int> cnt(n);
  rep(i, n) {
    cnt[i] = G[i].size();
    se.emplace(cnt[i], i);
  }
  vector<bool> bestVec(n);
  int best = 0;
  while(!se.empty()) {
    int i = se.begin()->second;
    bestVec[i] = true;
    best++;
    for(int ne: G[i]) {
      se.erase({cnt[ne], ne});
      avail[ne] = false;
      for(int ne2: G[ne]) {
        if(ne2 == i) continue;
        G[ne2].erase(ne);
      }
    }
    for(int ne: G[i]) {
      for(int ne2: G[ne]) {
        if(ne2 == i) continue;
        if(avail[ne2]) {
          se.erase({cnt[ne2], ne2});
          se.emplace(G[ne2].size(), ne2);
          cnt[ne2] = G[ne2].size();
        }
      }
    }
    se.erase({cnt[i], i});
    avail[i] = false;
    cerr << se.size() << endl;
  }
  fout.open("out/"+filename+".out");
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
