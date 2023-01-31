vector<int> remonte_dijkstra(int node) {
	vector<int> soluce = {node};
	while (dij_t_min[node] != 0) {
		for (auto& arc : graph_parents[node]) {
			if (dij_t_min[arc.dest] + arc.size == dij_t_min[node]) {
				node = arc.dest;
				break;
			}
		}
		soluce.push_back(node);
	}
	reverse(soluce.begin(), soluce.end());
	return soluce;
}


