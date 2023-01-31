const char DFS_PAS_VU = 0, DFS_EN_COURS = 1, DFS_VU = 2;
char dfs_state[MAX_NODES];

int dfs_recur(int node) {
	if (dfs_state[node] != DFS_PAS_VU) {
		return 0;
	}
	dfs_state[node] = true;

	for (auto v : voisins[node]) {
		if (dfs_state[v.dest] == DFS_PAS_VU) {
			int result = dfs_recur(v.dest);
		} else if (dfs_state[v.dest] == DFS_EN_COURS) {

		}
	}
	return 0;
}

void start_dfs() {
	for (int iNode = 0; iNode < nbNodes; iNode++) {
		if (dfs_state[iNode] == DFS_PAS_VU) {
			int result = dfs_recur(iNode);
		}
	}
}


