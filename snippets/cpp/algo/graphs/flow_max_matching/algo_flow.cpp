//@title Ford-Fulkerson algorithm with flow of size 2^k
//@defines pushFlow, getMaxFlow
//@doc "flow" will contain the flow passing through an edge (positive or negative).
//@
const int MAX_NODES = 501;
const bool IS_FLOW_ORIENTED = true;
int sourceId = 1, puitId = 1;

int cap[MAX_NODES][MAX_NODES];
int flow[MAX_NODES][MAX_NODES];
int flowExploMark[MAX_NODES];
int flowExploMarkId = 1;
int nbNodes, nbArcs;

struct __Flow__init {
	__Flow__init() {
		for (int l = 0; l < MAX_NODES; l++) {
			fill(cap[l], cap[l]+MAX_NODES, 0);
			fill(flow[l], flow[l]+MAX_NODES, 0);
		}
		fill(flowExploMark, flowExploMark+MAX_NODES, 0);
	}
} __flow__init;

bool pushFlow(int node, int push) {
	if (node == puitId) {
		return true;
	} else if (flowExploMark[node] == flowExploMarkId) {
		return false;
	}
	flowExploMark[node] = flowExploMarkId;
	for (int v = 0; v < MAX_NODES; v++) {
		if (flow[node][v] + push <= cap[node][v]) {
			if (pushFlow(v, push)) {
				flow[node][v] += push;
				flow[v][node] -= push;
				return true;
			}
		}
	}
	return false;
}

int getMaxFlow() {
	int tryToPush = 1;
	int capMax = 0;
	for (int el1 = 0; el1 < MAX_NODES; el1++) {
		capMax = max(capMax, *max_element(cap[el1], cap[el1]+MAX_NODES));
	}
	while (tryToPush*2 <= capMax) {
		tryToPush *= 2;
	}
	int pushedFlow = 0;
	while (tryToPush) {
		while (++flowExploMarkId && pushFlow(sourceId, tryToPush)) {
			pushedFlow += tryToPush;
			if (pushedFlow >= INF) {
				return INF;
			}
		}
		tryToPush /= 2;
	}
	return pushedFlow;
}

