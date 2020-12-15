/* Link to the problem https://putka-upm.acm.si/tasks/t/cini/ */

#include <queue>

#include <vector>

#include <iostream>

#include <cstring>

#include <fstream>

#include <algorithm>

#include <set>

#include <string>

#include <map>

#include <vector>

using namespace std;

const int inf = 1e3 + 9;

int n, m;

vector<int> adj[inf], ans;

map<string, int> mp;

string rnk[inf], names[inf];

int rating[inf], level[inf];

 

void dfs(int u, int par) {

 

  for (auto v : adj[u])

    if (v != par)

      level[v] = level[u] + 1, dfs(v, u);

}

 

bool cmp(int x, int y) {

 

  if (rating[x] == rating[y]) {

    if (level[x] == level[y])

      cout << "ZARADI SLABEGA VREMENA PARADA ODPADE" << endl, exit(0);

    return level[x] < level[y];

  }

  return rating[x] > rating[y];

}

 

int main() {

 

  cin >> n >> m;

  string ss;

  getline(cin, ss);

  for (int i = 1; i <= n; i++) {

    getline(cin, ss);

    //cout<<ss<<endl;

    mp[ss] = i * 2;

  }

 

  for (int i = 1; i <= m; i++) {

    string tmp, cur = "";

    getline(cin, tmp, '\n');

    int l = 0, r = tmp.size() - 1, par = 0;

    for (; l < tmp.size() && tmp[l] != ':'; l++)

      cur += tmp[l];

    names[i] = cur;

    cur = "";

    l++;

    for (; r >= 0 && tmp[r] != ' '; r--)

      cur += tmp[r];

    r--;

    reverse(cur.begin(), cur.end());

    if (cur == "-1")

      par = 0;

    else {

      par = atoi(cur.c_str());

    }

    adj[par].push_back(i), adj[i].push_back(par);

    cur = "";

    cur = tmp.substr(l, r - l + 1);

    if (cur.size() > 3) {

      if (cur.substr(0, 3) == "pod") {

        rating[i] = mp[cur.substr(3)] - 1;

      } else if (cur.substr(0,3) == "nad"){

        rating[i] = mp[cur.substr(3)] + 1;

      } else {

        rating[i] = mp[cur];

      }

    } else {

      rating[i] = mp[cur];

    }

  }

 

  dfs(0, -1);

 

  for (int i = 1; i <= m; i++)

    ans.push_back(i);

  sort(ans.begin(), ans.end(), cmp);

  for (auto o : ans)

    cout << names[o] << endl;

}
