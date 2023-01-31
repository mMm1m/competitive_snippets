//#define GRAPH_ORIENTED
//#define GRAPH_TREE
//#define GRAPH_PONDERE

const int MAX_NODES = 1e5;
const int MAX_ARCS = 1e5;
const int IDS_FIRST = 0; // Si les indices commencent a 1 dans l'entree, permet de decaler

struct Arc {
	int dest;

	#ifdef GRAPH_PONDERE
	int size;
	#endif
};

vector<Arc> voisins[MAX_NODES+IDS_FIRST];
#ifdef GRAPH_ORIENTED
vector<Arc> graph_parents[MAX_NODES+IDS_FIRST];
#else
auto &graph_parents = voisins;
#endif
int nbNodes, nbArcs;



