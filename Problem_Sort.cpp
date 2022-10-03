#include <bits/stdc++.h>
using namespace std;

vector<int> score;
vector<pair<int,int>> users;

bool cmp(pair<int,int> &a, pair<int,int> &b) {
  return score[a.first] < score[b.first];  
}

bool cmp2(pair<int,int> &a, pair<int,int> &b) {
  if (a.first == b.first) {
    return a.second < b.second;
  }
  return a.first < b.first;
}

int main() {
  ios_base::sync_with_stdio(false);
  int P, S;
  cin >> P >> S;
  score.resize(S);
  users.resize(S);
  vector<pair<int,int>> v;
  for(int i = 1; i <= P; ++i) {
    for(int j = 0; j < S; ++j) {
      cin >> score[j];
    }
    int cnt = 0;
    for(int j = 0; j < S; ++j) {
      users[j].first = j;
      cin >> users[j].second;
    }
    sort(users.begin(), users.end(), cmp);
    for(int j = 0; j < S-1; ++j) {
      if (users[j].second > users[j+1].second) {
        cnt += 1;
      }
    }
    v.push_back({cnt, i});
    // cout << i << " " << cnt << "\n";
  }
  sort(v.begin(), v.end(), cmp2);
  for(int i = 0; i < P; ++i) {
    cout << v[i].second << "\n";
  }
  return 0;
}