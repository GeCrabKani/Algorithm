#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

int GetParent(vector<int> &parent, int node) {
    if (parent[node] == node) return node;
    return parent[node] = GetParent(parent, parent[node]);
}

void UnionParent(vector<int> &parent, vector<int> &size, int nodeX, int nodeY) {
    nodeX = GetParent(parent, nodeX);
    nodeY = GetParent(parent, nodeY);

    if (nodeX != nodeY) {
        if (size[nodeX] < size[nodeY]) {
            parent[nodeX] = nodeY;
            size[nodeY] += size[nodeX];
        } else {
            parent[nodeY] = nodeX;
            size[nodeX] += size[nodeY];
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, f;
    cin >> n;

    while (n--) {
        unordered_map<string, int> um;
        vector<int> parent(200000);
        vector<int> size(200000, 1);
        int index = 0;

        cin >> f;

        for (int j = 0; j < f; j++) {
            string x, y;
            cin >> x >> y;

            if (um.find(x) == um.end()) {
                parent[index] = index;
                um[x] = index++;
            }
            if (um.find(y) == um.end()) {
                parent[index] = index;
                um[y] = index++;
            }

            UnionParent(parent, size, um[x], um[y]);

            int root = GetParent(parent, um[x]);
            cout << size[root] << "\n";
        }
    }

    return 0;
}
