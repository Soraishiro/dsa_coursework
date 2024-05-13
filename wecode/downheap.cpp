// /*Su dung multiset - tle 3 test case*/
// #include <iostream>
// #include <set>

// using namespace std;
 
// int main()
// {
//     ios_base::sync_with_stdio(false);
//     cin.tie(nullptr); cout.tie(nullptr);
//     int n, m; cin >> n >> m;
//     multiset<int, greater<int>> ms;
//     for (int i = 0; i < n; ++i){
//         int tmp; cin >> tmp;
//         ms.insert(tmp);
//     }
//     if (ms.empty()) return -1;
//     while (m--){
//         int tmp; cin >> tmp;
//         if (tmp == -1) ms.erase(ms.begin());
//         if (tmp == -2){
//             int max_value = *ms.begin();
//             ms.erase(max_value);
//         } 
//         if (tmp == -3){
//             int t; cin >> t;
//             int max_value = *ms.begin() - t;
//             ms.erase(ms.begin());
//             ms.insert(max_value);
//         }
//         if (tmp == -4){
//             int t; cin >> t;
//             int max_value = *ms.begin();
//             int count = ms.count(max_value);
//             ms.erase(max_value);
//             max_value -= t;
//             for (int i = 0; i < count; ++i) ms.insert(max_value);
//         }
//     }
//     for (auto it : ms) cout << it << endl;
//     return 0;
// }

/*Su dung priority queue - tle 6 test case*/
// #include <iostream>
// #include <queue>

// using namespace std;

// int main() {
//     ios_base::sync_with_stdio(false);
//     cin.tie(nullptr); cout.tie(nullptr);
//     int n, m; cin >> n >> m;
//     priority_queue<int> pq;
//     for (int i = 0; i < n; ++i) {
//         int tmp; cin >> tmp;
//         pq.push(tmp);
//     }
//     if (pq.empty()) return -1;
//     while (m--) {
//         int task; cin >> task;
//         switch (task) {
//             case -1: 
//                 pq.pop();
//                 break;
//             case -2: { 
//                 int max_value = pq.top();
//                 while (!pq.empty() && pq.top() == max_value) {
//                     pq.pop();
//                 }
//                 break;
//             }
//             case -3: { 
//                 int t; cin >> t;
//                 int max_value = pq.top(); pq.pop();
//                 pq.push(max_value - t);
//                 break;
//             }
//             case -4: { 
//                 int t; cin >> t;
//                 int max_value = pq.top();
//                 priority_queue<int> new_pq;
//                 while (!pq.empty()) {
//                     if (pq.top() == max_value) new_pq.push(pq.top() - t);
//                     else new_pq.push(pq.top());
//                     pq.pop();
//                 }
//                 pq = new_pq;
//                 break;
//             }
//         }
//     }
//     while (!pq.empty()) {
//         cout << pq.top() << endl;
//         pq.pop();
//     }
//     return 0;
// }

/*Su dung heap - */

#include <bits/stdc++.h>
using namespace std;

void heapify(int v[], const int size, int pos){
    int l = 2*pos + 1, r = 2*pos + 2;
    int max = pos;
    if (l < size && v[l] > v[max]) max = l;
    if (r < size && v[r] > v[max]) max = r;
    if (max != pos){
        swap(v[max], v[pos]);
        heapify(v, size, max);
    }
}

void buildHeap(int v[], const int size){
    for (int i = size/2 - 1; i >= 0; i--) heapify(v, size, i);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    int n, m; cin >> n >> m;
    int v[n];
    for (int i = 0; i < n; i++) cin >> v[i];
    buildHeap(v, n);
    int tmp, t;
    while (m--){
        cin >> tmp;
        if (tmp == -1) {
            swap(v[0], v[n-1]);
            n--;
            heapify(v, n, 0);
        }
        else if (tmp == -2) {
            int max_value = v[0];
            int count = 0;
            for (int i = 0; i < n; i++) {
                if (v[i] != max_value) {
                    v[count] = v[i];
                    count++;
                }
            }
            n = count;
            buildHeap(v, n);
        }
        else if (tmp == -3) {
            cin >> t;
            v[0] -= t;
            heapify(v, n, 0);
        }
        else {
            cin >> t;
            int max_value = v[0];
            for (int i = 0; i < n; i++) if (v[i] == max_value) v[i] -= t;
            buildHeap(v, n);     
        }
    }
    while (n > 0) {
        cout << v[0] << endl;
        swap(v[0], v[n-1]);
        n--;
        heapify(v, n, 0);
    }
    for (int i = 0; i < n; i++) cout << v[i] << endl;
    return 0;
}