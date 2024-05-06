#include <iostream>
#include <queue>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, x;
    cin >> n;

    priority_queue<int> max_heap;
    priority_queue<int, vector<int>, greater<int>> min_heap;

    for (int i = 0; i < n; ++i) {
        cin >> x;
        if (max_heap.empty() || x <= max_heap.top()) {
            max_heap.push(x);
        }
        else {
            min_heap.push(x);
        }

        if (max_heap.size() < min_heap.size()) {
            max_heap.push(min_heap.top());
            min_heap.pop();
        }
        else if (max_heap.size() > min_heap.size() + 1) {
            min_heap.push(max_heap.top());
            max_heap.pop();
        }

        cout << max_heap.top() << '\n';
    }
    return 0;
}
