//Link: https://putka-upm.acm.si/results/35205/

#include <iostream>

#include <algorithm>

#include <string>

#include <vector>

#include <map>

#include <queue>

#include <cstring>

#include <set>

using namespace std;

const int mx = 109;

set<pair<int, int> >f, s;

bool check(set < pair<int, int >> & k, int x, int y) {

  //h

  int cur = 1;

  for (int i = 1; k.find({ x + i,y }) != k.end() && cur < 5; ++i) {

    ++cur;

  }

  for (int i = 1; k.find({ x - i,y }) != k.end() && cur < 5; ++i) {

    ++cur;

  }

  if (cur >= 5) {

    return true;

  }

  cur = 1;

  for (int i = 1; k.find({ x,y + i }) != k.end() && cur < 5; ++i) {

    ++cur;

  }

  for (int i = 1; k.find({ x,y - i }) != k.end() && cur < 5; ++i) {

    ++cur;

  }

  if (cur >= 5) {

    return true;

  }

  cur = 1;

  for (int i = 1; k.find({ x + i,y + i }) != k.end() && cur < 5; ++i) {

    ++cur;

  }

  for (int i = 1; k.find({ x - i,y - i }) != k.end() && cur < 5; ++i) {

    ++cur;

  }

  if (cur >= 5) {

    return true;

  }

  cur = 1;

  for (int i = 1; k.find({ x - i,y + i }) != k.end() && cur < 5; ++i) {

    ++cur;

  }

  for (int i = 1; k.find({ x + i,y - i }) != k.end() && cur < 5; ++i) {

    ++cur;

  }

  if (cur >= 5) {

    return true;

  }

  return false;

}

int main() {

  int n;

  cin >> n;

  bool turn = false;

  int a, b;

  int t1 = 0, t2 = 0;

  for (int i = 0; i < n; ++i) {

    cin >> a >> b;

    if (i & 1) {

      t1++;

      f.insert({ a,b });

      if (check(f, a, b)) {

        cout <<"Linus "<< t1 << endl;

        return 0;

      }

    } else {

      t2++;

      s.insert({ a,b });

      if (check(s, a, b)) {

        cout << "Snoopy " << t2 << endl;

        return 0;

      }

    }

  }

  cout << "neodloceno\n";

}
