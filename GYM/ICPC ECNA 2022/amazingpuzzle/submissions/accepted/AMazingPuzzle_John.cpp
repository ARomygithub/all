#include<iostream>
#include<queue>
using namespace std;

const string DIRECTIONS = "NESW";
const int NORTH = 0;
const int EAST = 1;
const int SOUTH = 2;
const int WEST = 3;
const int CDIRS[] = {0,1,0,-1};
const int RDIRS[] = {1,0,-1,0};

class Node;

class NodeList
{
public:
	int index;
	NodeList *next;

	NodeList(int nde, NodeList *nxt)
	{
		index = nde;
		next = nxt;
	}
};

class Node
{
public:
	int c1, r1, c2, r2;			// these may not be necessary
	int dist, bumps;
	NodeList *adj;

	void set(int i, int c, int r)
	{
		r2 = i % r;
		i /= r;
		c2 = i % c;
		i /= c;
		r1 = i % r;
		c1 = i / r;
		adj = 0;
		dist = -1;
		bumps = 0;
	}

	void set(int cc1, int rr1, int cc2, int rr2)
	{
		c1 = cc1;
		r1 = rr1;
		c2 = cc2;
		r2 = rr2;
		adj = 0;
		dist = -1;
		bumps = 0;
	}

	void addAdjacent(int index)
	{
		adj = new NodeList(index, adj);
	}
};

Node* bfs(Node* graph, int s, int exit);
//void printGraph(Node *graph, int size);

int main()
{
    int c, r, e, initc1, initr1, initc2, initr2, initd1, initd2;

    cin >> c >> r >> e;
    e--;
    cin >> initc1 >> initr1;
    initc1--, initr1--;
    char ch;
    cin >>ch;
    initd1 = DIRECTIONS.find(ch);
    cin >> initc2 >> initr2;
    cin >>ch;
    initc2--, initr2--;
    initd2 = DIRECTIONS.find(ch);

    bool adj[c][r][4];
    for(int i=0; i<c; i++)
        for(int j=0; j<r; j++)
            for(int k=0; k<4; k++)
                adj[i][j][k] = true;		// true ==> can move in that direction k from [i,j]
    for(int i=0; i<c; i++)
        adj[i][0][SOUTH] = adj[i][r-1][NORTH] = false;		// 0 - North, 2 - South
    for(int j=0; j<r; j++) {
        adj[0][j][WEST] = adj[c-1][j][EAST] = false;		// 1 - East, 3 - West
    }
    adj[e][0][SOUTH] = true;							// exit square

    int n;
    cin >> n;
    for(int i=0; i<n; i++) {
        int wc, wr;
        cin >> wc >> wr;
        wc--, wr--;
        adj[wc][wr][NORTH] = adj[wc][wr+1][SOUTH] = false;
    }
    cin >> n;
    for(int i=0; i<n; i++) {
        int wc, wr;
        cin >> wc >> wr;
        wc--, wr--;
        adj[wc][wr][EAST] = adj[wc+1][wr][WEST] = false;
    }
    // build search graph
    Node graph[c*r*c*r + 2*c*r + 1];
    for(int i=0; i<c*r*c*r; i++) {
        graph[i].set(i, c, r);
    }
    for(int i=0; i<r*c; i++) {
        int j = i + c*r*c*r;
        graph[j].set(e,-1,i/r,i%r);
    }
    for(int i=0; i<r*c; i++) {
        int j = i + c*r*c*r + c*r;
        graph[j].set(i/r,i%r, e, -1);
    }
    graph[c*r*c*r + 2*c*r].set(e,-1,e,-1);

    for(int i=0; i<c*r*c*r; i++) {
        int d1 = initd1;
        int d2 = initd2;
        int c1 = graph[i].c1;
        int r1 = graph[i].r1;
        int c2 = graph[i].c2;
        int r2 = graph[i].r2;
        if (c1 == c2 && r1 == r2)
            continue;
        for(int d=0; d<4; d++) {
            if(adj[c1][r1][d1] || adj[c2][r2][d2]) {
                int newc1 = c1;
                int newr1 = r1;
                int newc2 = c2;
                int newr2 = r2;
                if (adj[c1][r1][d1]) {
                    newc1 += CDIRS[d1];
                    newr1 += RDIRS[d1];
                }
                if (adj[c2][r2][d2]) {
                    newc2 += CDIRS[d2];
                    newr2 += RDIRS[d2];
                }
                if (newc1 != newc2 || newr1 != newr2) {
                    int index;
                    if (newr1 == -1)
                        index = r*c*r*c + newc2*r + newr2;
                    else if (newr2 == -1)
                        index = r*c*r*c + r*c + newc1*r + newr1;
                    else
                        index = newc1*r*c*r + newr1*c*r + newc2*r + newr2;
//cout << "add to node " << i << " node " << index << endl;
                    graph[i].addAdjacent(index);
//cout << " after return: " << graph[i].adj->node->c1 << "," << graph[i].adj->node->r1 << endl;
//cout << " after return: " << graph[i].adj->node->c1 << "," << graph[i].adj->node->r1 << endl;
//printGraph(graph, i+1);
                }
            }
            d1 = (d1+1)%4;
            d2 = (d2+1)%4;
        }
    }
    for(int i=0; i<c*r; i++) {
        int j = i+c*r*c*r;
        int c2 = graph[j].c2;		// c1,r1 = e,-1
        int r2 = graph[j].r2;
        for(int d=0; d<4; d++) {
            if (adj[c2][r2][d]) {
                int newc2 = c2+CDIRS[d];
                int newr2 = r2+RDIRS[d];
                int index;
                if (newr2 == -1)
                    index = c*r*c*r + 2*c*r;
                else
                    index = c*r*c*r + newc2*r + newr2;
                graph[j].addAdjacent(index);
            }
        }
    }
    for(int i=0; i<c*r; i++) {
        int j = i+c*r*c*r+c*r;
        int c1 = graph[j].c1;		// c1,r1 = e,-1
        int r1 = graph[j].r1;
        for(int d=0; d<4; d++) {
            if (adj[c1][r1][d]) {
                int newc1 = c1+CDIRS[d];
                int newr1 = r1+RDIRS[d];
                int index;
                if (newr1 == -1)
                    index = c*r*c*r + 2*c*r;
                else
                    index = c*r*c*r +c*r + newc1*r + newr1;
                graph[j].addAdjacent(index);
            }
        }
    }
    Node* exit = bfs(graph, (initc1*r*c*r + initr1*c*r + initc2*r + initr2), e);
    cout << exit->dist << " " << exit->bumps << endl;

}

Node* bfs(Node* graph, int s, int exit)
{
    queue<Node*> q;
    Node* start = graph+s;
    start->dist = 0;
    q.push(start);
    while(!q.empty()) {
        Node* node = q.front();
        q.pop();
        if (node->c1 == exit && node->r1 == -1 && node->c2 == exit && node->r2 == -1)
            return node;
        for(NodeList *nl = node->adj; nl != 0; nl = nl->next) {
            Node* n = graph + nl->index;
            int newDist = node->dist+1;
            int newBumps = node->bumps;
            if (node->c1 == n->c1 && node->r1 == n->r1 && node->r1 >= 0)
                newBumps++;
            else if (node->c2 == n->c2 && node->r2 == n->r2 && node->r2 >= 0)
                newBumps++;
            if (n->dist == -1 || newDist < n->dist || (newDist == n->dist && newBumps < n->bumps)) {
                n->dist = newDist;
                n->bumps = newBumps;
                q.push(n);
            }
        }
    }
    return 0;			// should never happen...but you never know
}


/*
void printGraph(Node *graph, int size)
{
    for(int i=0; i<size; i++) {
 //       if (graph[i] != null) {
            cout << '[' << graph[i].c1 << ',' << graph[i].r1 << ' ' <<  graph[i].c2 << ',' << graph[i].r2 << "] -->";
            for(NodeList *nl = graph[i].adj; nl != 0; nl = nl->next) {
                int j = nl->index;
                cout << '[' << graph[j].c1 << ',' << graph[j].r1 << ' ' <<  graph[j].c2 << ',' << graph[j].r2 << "] ";
            }
            cout << endl;
        }
 //   }
}

/**/

