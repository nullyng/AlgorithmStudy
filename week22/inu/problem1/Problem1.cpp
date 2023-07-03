#include <iostream>
#include <vector>

#define MAX 1000001

using namespace std;

vector<vector<int>> graph;
int arr[MAX];

void DFS(int cur) {
	for (int i = 0; i < (int)graph[cur].size(); i++) {
		int next = graph[cur][i];
		arr[next] += arr[cur];
		DFS(next);
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int N, M;

	cin >> N >> M;

	graph.assign(N + 1, vector<int>());

	for (int i = 1; i <= N; i++) {
		int parent;
		cin >> parent;
		if(parent != -1) graph[parent].push_back(i);
	}

	for (int i = 0; i < M; i++) {
		int n, m;
		cin >> n >> m;
		arr[n] += m;
	}
	
	DFS(1);

	for (int i = 1; i <= N; i++)
		cout << arr[i] << ' ';

	return 0;
}