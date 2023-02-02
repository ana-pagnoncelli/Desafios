#include <bits/stdc++.h>
#define infi 1000000000
using namespace std;

// C++ implementation to find the
// shortest path in a directed
// graph from source vertex to
// the destination vertex

// Class of the node
class Node {
public:
	int vertexNumber;

	// Adjacency list that shows the
	// vertexNumber of child vertex
	// and the weight of the edge
	vector<pair<int, int> > children;
	Node(int vertexNumber)
	{
		this->vertexNumber = vertexNumber;
	}

	// Function to add the child for
	// the given node
	void add_child(int vNumber, int length){
		pair<int, int> p;
		p.first = vNumber;
		p.second = length;
		children.push_back(p);
	}

  bool is_bidirectional(int u){
    for (int i = 0; i < children.size(); i++){      
      if(u == children[i].first) {
        children[i].second = 0;
        return true;
      }
    }
    return false;
  }
};

// Function to find the distance of
// the node from the given source
// vertex to the destination vertex
vector<int> dijkstraDist(
	vector<Node*> g,
	int s, vector<int>& path)
{
	// Stores distance of each
	// vertex from source vertex
	vector<int> dist(g.size());

	// Boolean array that shows
	// whether the vertex 'i'
	// is visited or not
	bool visited[g.size()];
	for (int i = 0; i < g.size(); i++) {
		visited[i] = false;
		path[i] = -1;
		dist[i] = infi;
	}
	dist[s] = 0;
	path[s] = -1;
	int current = s;

	// Set of vertices that has
	// a parent (one or more)
	// marked as visited
	unordered_set<int> sett;
	while (true) {

		// Mark current as visited
		visited[current] = true;
		for (int i = 0;
			i < g[current]->children.size();
			i++) {
			int v = g[current]->children[i].first;
			if (visited[v])
				continue;

			// Inserting into the
			// visited vertex
			sett.insert(v);
			int alt
				= dist[current]
				+ g[current]->children[i].second;

			// Condition to check the distance
			// is correct and update it
			// if it is minimum from the previous
			// computed distance
			if (alt < dist[v]) {
				dist[v] = alt;
				path[v] = current;
			}
		}
		sett.erase(current);
		if (sett.empty())
			break;

		// The new current
		int minDist = infi;
		int index = 0;

		// Loop to update the distance
		// of the vertices of the graph
		for (int a: sett) {
			if (dist[a] < minDist) {
				minDist = dist[a];
				index = a;
			}
		}
		current = index;
	}
	return dist;
}

// Function to print the path
// from the source vertex to
// the destination vertex
void printPath(vector<int> path,
			int i, int s)
{
	if (i != s) {

		// Condition to check if
		// there is no path between
		// the vertices
		if (path[i] == -1) {
			cout << "Path not found!!";
			return;
		}
		printPath(path, path[i], s);
		cout << path[i] << " ";
	}
}

int main()
{
  int number_of_arrests, number_of_vertices, number_of_queries;
  int v, u, w, source, dest; 

  cin >> number_of_vertices >> number_of_arrests;

  while (!(number_of_arrests == 0 && number_of_vertices == 0)){

    vector<Node*> nodes_vector;

	for (int i = 0; i < number_of_vertices; i++) {
		Node* a = new Node(i);
		nodes_vector.push_back(a);
	}

    for(int i = 0; i < number_of_arrests; i ++) {
        cin >> u >> v>> w;
        u --;
        v --;
      
        if(nodes_vector[v]->is_bidirectional(u)){
            nodes_vector[u]->add_child(v, 0);
        } else {
            nodes_vector[u]->add_child(v, w);
        }
    }


    ///// queries
    cin >> number_of_queries;
    vector<int> path(nodes_vector.size());

    for (int i=0; i < number_of_queries; i++){
        cin >> source >> dest;
        source --;
        dest --;

        vector<int> dist = dijkstraDist(nodes_vector, source, path);

        if (dist[dest] == infi) {
            cout << "Nao e possivel entregar a carta" << endl;
            continue;
        }
        cout << dist[dest] << endl;
  	}

    cout << endl;
    
    cin >> number_of_vertices >> number_of_arrests;
  }
  
	return 0;
}

