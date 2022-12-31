#include <iostream>
#include <vector>
#include <queue>



int main() {
	int n, m;
	std::cin >> n >> m;
	std::vector<std::vector<int>> graph(n);
	std::vector<int> visited(n, 0);

	for (int i = 0; i < m; i++) {
		int a, b;
		std::cin >> a >> b;
		a--; b--;

		graph[a].push_back(b);
		graph[b].push_back(a);
	}

	std::queue<std::pair<int, int>> q;
	for (int i = 0; i < n; i++) {
		if (visited[i] == 0) {
			q.push({ i,1 });
			while (!q.empty()) {
				std::pair<int, int> c = q.front();
				q.pop();


				if (visited[c.first] == c.second) continue;

				if (visited[c.first] == 0) 
					visited[c.first] = c.second;
				
				else {
					std::cout << "IMPOSSIBLE";
					return 0;
				}


				for (int j : graph[c.first]) {

					//c.second == 1 ? q.push({ j,2 }) : q.push({ j,1 });
					q.push({ j, (c.second == 1 ? 2 : 1) });
				}

			}
		}
		for (int i = 0; i < n; i++) {
			std::cout << visited[i] << " ";
		}
		
	}
	
	
	



	return 0;
}

