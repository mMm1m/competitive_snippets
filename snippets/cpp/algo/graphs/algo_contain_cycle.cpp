int gcc_state[MAX_NODES];

bool __graph_contain_cycle_recur(int node) {
	gcc_state[node] = 1;
	for (Arc arc : voisins[node]) {
		int v = arc.dest;
		if (gcc_state[v] == 1) {
			return true;
		}
		if (gcc_state[v] == 0 && __graph_contain_cycle_recur(v)) {
			return true;
		}
	}
	gcc_state[node] = 2;
	return false;
}

bool graph_contain_cycle() {
	fill(gcc_state, gcc_state+nbNodes, 0);
	for (int iNode = 0; iNode < nbNodes; iNode++) {
		if (gcc_state[iNode] == 0) {
			if (__graph_contain_cycle_recur(iNode)) {
				return true;
			}
		}
	}
	return false;
}


