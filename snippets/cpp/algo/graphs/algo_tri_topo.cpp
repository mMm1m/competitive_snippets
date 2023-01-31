int atp_nbParents[MAX_NODES];

vector<int> tri_topo() {
	fill(atp_nbParents, atp_nbParents+nbNodes, 0);
	for (int iNode = 0; iNode < nbNodes; iNode++) {
		for (auto arc : voisins[iNode]) {
			atp_nbParents[arc.dest]++;
		}
	}

    vector<int> result;
    deque<int> waiting_list;

    for (int iNode = 0; iNode < nbNodes; iNode++) {
        if (atp_nbParents[iNode] == 0) {
        	waiting_list.push_back(iNode);
        }
    }
    while (!waiting_list.empty()) {
    	result.push_back(waiting_list.front());
    	for (auto arc : voisins[waiting_list.front()]) {
    		atp_nbParents[arc.dest]--;
    		if (atp_nbParents[arc.dest] == 0) {
    			waiting_list.push_back(arc.dest);
    		}
    	}
    	waiting_list.pop_front();
    }
    if ((int)result.size() != nbNodes) {
    	return {};
    }
    return result;
}


