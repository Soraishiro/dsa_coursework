#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

int main(){
    int n; cin >> n;
    vector<pair<int, int>> p;
    for (int i = 0; i < n; i++) cin >> p[i].first;
    for (int i = 0; i < n; i++){
        vector<int> v;
        for (int j = 0, nums = p[i].first; j < nums; j++){
            int tmp; cin >> tmp;
            v.push_back(tmp);
        }
    }
    for (int i = 0; i < n; i++) cin >> p[i].second;
    for (int i = 0; i < n; i++){
        vector<int> preSum;
        for (int j = 0, nums = p[i].first; j < nums; j++){
            preSum[0] = 0;
            preSum[j]
        }

    }
}