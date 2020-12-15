//Link: https://putka-upm.acm.si/tasks/t/256-odtenkov-sive/

#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <string>
using namespace std;
int arr[109][109];
int main() {
  int w, h;
  cin >> w >> h;
  int s;
  for (int i = 0; i < h; ++i) {
    for (int j = 0; j < w; ++j) {
      cin >> s;
 
      int b = s & 255;
      s >>= 8;
      int g = s & 255;
      s >>= 8;
      int r = s & 255;
      s >>= 8;
      arr[i][j]= (0.11 * b + 0.59 * g + 0.30 * r + 0.5);
    }
  }
  cout << w << " " << h << endl;
  for (int i = 0; i < h; ++i) {
    for (int j = 0; j < w; ++j) {
      cout << arr[i][j] << " \n"[j == w - 1];
    }
  }

}



