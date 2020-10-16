#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <numeric> // accumulate(v.begin(), v.end(), 0)

using namespace std;
#define ll long long

struct data{
  ll val;
  int prev;
};

bool comp(data d1, data d2){
  if(d1.val == d2.val)
    return d1.prev <= d2.prev;
  else
    return d1.val <= d2.val;
}

int main(){
  int k;
  cin >> k;
  vector< vector<data> > memo(k, vector<data>(0));
  vector<ll> sum(k, 0LL);
  for(int i=0; i<k; i++){
    int len;
    cin >> len;
    for(int j=0; j<len; j++){
      ll in;
      cin >> in;
      sum[i] += in;
      data d = {in, j};
      memo[i].push_back(d);
    }
    sort(memo[i].begin(), memo[i].end(), comp);
  }
  for(int i=0; i<k; i++){
    for(int j=i+1; j<k; j++){
      ll diff = sum[i] - sum[j];
      vector<data> m1, m2;
      if(diff > 0)
	m1 = memo[i], m2 = memo[j];
      else
	m1 = memo[j], m2 = memo[i];
      diff = abs(diff);
      int it1 = 0, it2 = 0;
      while(it1 < (int)m1.size() && it2 < (int)m2.size()){
	while(m1[it1].val < m2[it2].val + diff && it1 < (int)m1.size())
	  it1++;
	if(it1 == (int)m1.size())
	  break;
	if(m1[it1].val == m2[it2].val + diff){
	  cout << "YES" << endl;
	  cout << i+1 << ' ' << m1[it1].prev+1 << ' ' << endl
	       << j+1 << ' ' << m2[it2].prev+1 << ' ' << endl;
	  return 0;
	}
	while(m1[it1].val > m2[it2].val + diff && it2 < (int)m2.size())
	  it2++;
	if(it2 == (int)m2.size())
	  break;
	if(m1[it1].val == m2[it2].val + diff){
	  cout << "YES" << endl;
	  cout << i+1 << ' ' << m1[it1].prev+1 << ' ' << endl
	       << j+1 << ' ' << m2[it2].prev+1 << ' ' << endl;
	  return 0;
	}
      }
    }
  }
  cout << "NO" << endl;
  return 0;
}

