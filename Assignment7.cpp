//============================================================================
// Name        : Assignment7.cpp
// Author      : Sakshee
// Roll no     : 23244 Batch : G 10
// Problem statement : Represent any real world problem in graph using adjacency list
//					   and find minimum spanning tree using Kruskal's algorithm.
//============================================================================

#include<iostream>
#include<string.h>
using namespace std;

class Vertex;

	class Edge
	{
		Edge *nextEdge;
		Vertex *destinationVertex;
		Vertex *startVertex;
		int weight;
		bool edgeInTree;
		friend class graphKruskals;
		
		public:
			Edge() {
				nextEdge = NULL;
				startVertex = NULL;
				destinationVertex = NULL;
				weight = 0;
				edgeInTree = false;
			}
	};
	class Vertex
	{
		string place;
		bool visited;
		Edge *nextEdge;
		Vertex *nextVertex;
		friend class graphKruskals;
		bool vertexInTree;
		public :
			Vertex() {
				visited = false;
				vertexInTree = false;
				nextEdge = NULL;
				nextVertex = NULL;
			}
	};
	class Head
	{
		int count;
		int numE;
		Vertex *firstVertex;
		friend class graphKruskals;
	};

class graphKruskals {

	Head *G;
	//graphEdge E;

public:
	graphKruskals();
	virtual ~graphKruskals();
	void createGraph();
	int insertVertex(string, int);
	void insertEdge(string, string, int, int);
	void displayGraph(int);
	Vertex *getGraphHead();
	void clear();
	void Kruskals();
	int minEdge(graphKruskals);
	void edgeKruskals(Vertex*, Vertex*);
	Edge *DFS(Vertex*,int);
	Edge *search(int, graphKruskals);
	int numEdges();
	int cycle(Vertex*, Vertex*);
	//other program related functions
};

graphKruskals::graphKruskals() {
	// TODO Auto-generated constructor stub
	G=NULL;
}

graphKruskals::~graphKruskals() {
	// TODO Auto-generated destructor stub
}

void graphKruskals :: createGraph()
{
	G=new Head;
	G->count=0;
	G->numE = 0;
	G->firstVertex = NULL; //graph head is created
}

void graphKruskals :: clear()
{
	Edge *edge;
	Vertex *curr = G->firstVertex;
	while(curr!=NULL) {
		curr->visited = false;
		curr->vertexInTree = false;
		edge = curr->nextEdge;
		while(edge!=NULL) {
			edge->edgeInTree=false;
			edge = edge->nextEdge;
		}
		curr = curr->nextVertex;
	}
	
}

Vertex* graphKruskals :: getGraphHead()
{
	return G->firstVertex;
}

int graphKruskals :: numEdges()
{
	return G->numE;
}

int graphKruskals :: insertVertex(string name, int tree)
{
	Vertex *newVertex,*curr;
	newVertex = new Vertex;

	newVertex->place = name;

	if(G->firstVertex==NULL) {//if head is null, insert new vertex as head
		G->firstVertex = newVertex;
		++G->count;
		return 1;
	}
	curr = G->firstVertex;//else traverse untill end of vertical list and insert vertex there
	while(curr->nextVertex!=NULL) {
		curr = curr->nextVertex;
	}
	curr->nextVertex = newVertex;
	++G->count;
	if(tree==1) newVertex->vertexInTree=true;

	return G->count;
}

int graphKruskals :: cycle(Vertex *v1, Vertex *v2)//Checks if cycle is formed 
{
	Edge *e1 = v1->nextEdge;
	Vertex *temp;
	Edge *curr;
	if(G->firstVertex==NULL) return 0;
	
	//to check mirror edge
	temp = G->firstVertex;
	while(temp!=NULL) {
		curr=temp->nextEdge;
		while(curr!=NULL) {
			if(curr->edgeInTree) {
				if(curr->startVertex->place==v2->place && curr->destinationVertex->place==v1->place) return 1;
			}
		curr = curr->nextEdge;
		}
		temp = temp->nextVertex;
	}
	
	while(e1!=NULL) {//traverses the edges of both vertices which are already present in the tree
		temp = e1->startVertex;
		if(temp==v2 && e1->edgeInTree) return 1;
		curr = temp->nextEdge;
		while(curr!=NULL) {
			if(curr->destinationVertex==v2 && curr->edgeInTree) return 1;//if any of the edges form a cycle
			curr = curr->nextEdge;
		}
		e1 = e1->nextEdge;
	}
	return 0;
}

int graphKruskals :: minEdge(graphKruskals spTree)//finds the minimum weight of the available edges
{
	Vertex *curr=G->firstVertex;
	Edge *e;
	int min=99999;
	if(curr!=NULL) {
		while(curr!=NULL) {
			e = curr->nextEdge;//traverse the graph
			while(e!=NULL) {
				if(min>e->weight) {
					if(e->edgeInTree==false) {
						if(!(e->startVertex->vertexInTree==false||e->destinationVertex->vertexInTree==false)) {//if both vertices present
							if(!spTree.cycle(e->startVertex, e->destinationVertex)) {//check for cycle
								min = e->weight;
							}
						}
						else {
							min = e->weight;
						}
						 
					}//ensures cycle is not formed
				} 
				e = e->nextEdge;
			}
			curr = curr->nextVertex;  
		}
	}
	return min;
}

void graphKruskals :: insertEdge(string place1, string place2, int d, int tree)
{
	
	Vertex *curr1,*curr2;
	Edge *p1,*p2;
	//Insert Edge (friend of user and create the proper links)
	curr1 = G->firstVertex;
	curr2 = G->firstVertex;
	if(curr1!=NULL) {

		while(curr1->place!=place1) {
			curr1 = curr1->nextVertex;
		}//find vertices with given name

		while(curr2->place!=place2) {
			curr2 = curr2->nextVertex;
		}
		//create edges v1<->v2
		p1 = curr1->nextEdge;
		if(p1==NULL) {
			curr1->nextEdge = new Edge;
			p1 = curr1->nextEdge;
			p1->weight = d;
			p1->destinationVertex = curr2;
			p1->startVertex = curr1;
			G->numE++;
		}
		else {
			while(p1->nextEdge!=NULL) {
				p1 = p1->nextEdge;
			}
			p1->nextEdge = new Edge;
			p1 = p1->nextEdge;
			p1->weight = d;
			p1->destinationVertex = curr2;
			p1->startVertex = curr1;
			G->numE++;
		}
		if(tree==1) p1->edgeInTree=true;
		if(tree==0) {
			p2 = curr2->nextEdge;
			if(p2==NULL) {
				curr2->nextEdge = new Edge;
				p2 = curr2->nextEdge;
				p2->weight = d;
				p2->destinationVertex = curr1;
				p2->startVertex = curr2;
				G->numE++;
			}
			else {
				while(p2->nextEdge!=NULL) {
					p2 = p2->nextEdge;
				}
				p2->nextEdge = new Edge;
				p2 = p2->nextEdge;
				p2->weight = d;
				p2->destinationVertex = curr1;
				p2->startVertex = curr2;
				G->numE++;
			}
		}
	} 
}

void graphKruskals :: displayGraph(int tree)
{
	Vertex *vertexPtr = G->firstVertex;
	Edge *edgePtr;
	while(vertexPtr!=NULL) {
		edgePtr = vertexPtr->nextEdge;
		if(tree==0)
			cout << "\n\t" << vertexPtr->place;//display normal adjacency list when its a graph, if spanning tree, display only edges 
		if(edgePtr!=NULL) {//loop for edges
			while(edgePtr!=NULL) {
				if(tree==0)
					cout << "\t-> " << edgePtr->destinationVertex->place << "[" << edgePtr->weight << "]";
				else
					cout << "\n\t" << edgePtr->startVertex->place << "\t-> " << edgePtr->destinationVertex->place << "[" << edgePtr->weight << "]" <<endl;
				edgePtr = edgePtr->nextEdge;
			}
		}
		vertexPtr = vertexPtr->nextVertex;
	}
	cout << endl;
	//display the graph in adjacency list form
}

void graphKruskals :: Kruskals()
{
	int i=0;
	Edge *min;
	graphKruskals spTree;
	Vertex *v1=NULL, *v2=NULL;
	spTree.createGraph();
	spTree.clear();
	while(spTree.numEdges()!=(G->count-1)) {//while num of edges is not equal to vertices-1,
		//min = DFS(G->firstVertex, minEdge()); 
		min = search(minEdge(spTree), spTree);
		if(min!=NULL) {//if edge is not present in tree, then
			v1 = min->startVertex;
			v2 = min->destinationVertex;
					spTree.insertVertex(v1->place,1);
					spTree.insertVertex(v2->place,1); 				
					spTree.insertEdge(v1->place, v2->place, min->weight, 1);//insert the edge in spanning tree
					v1->vertexInTree = true;
					v2->vertexInTree = true;
					min->edgeInTree = true;
					cout << "\n\tPASS WISE DISPLAY : ";
					spTree.displayGraph(1);
		}	
	}
	cout << "\n\t==========================================================" << endl;
	cout << "\n\tSPANNING TREE USING KRUSKAL'S ALGORITHM-" << endl;
	cout << "\n\t==========================================================" << endl;
	spTree.displayGraph(1);
	cout << "\n\t==========================================================" << endl;
}

Edge* graphKruskals :: DFS(Vertex *vertex,int min) // searching using DFS algo
{
	Edge *edgePtr=vertex->nextEdge;
	while(edgePtr!=NULL) {
		if(edgePtr->weight == min){
				return edgePtr;
		}
		edgePtr = edgePtr->nextEdge;
	}
	if(vertex->nextVertex!=NULL) {
		while(vertex->nextVertex->visited==false) {
			DFS(vertex->nextVertex,min);
		}
	}
	
	return NULL;
}

Edge* graphKruskals :: search(int min, graphKruskals spTree)
{
	Edge *edgePtr;
	Edge *result=NULL;
	Vertex *vertexPtr = G->firstVertex;

	while(vertexPtr!=NULL) {
		edgePtr = vertexPtr->nextEdge;
		while(edgePtr!=NULL) {
			if(edgePtr->weight==min) { //if weight is equal to min,
				if(edgePtr->edgeInTree==false) {//if the edge is absent in tree,
					if(!(edgePtr->startVertex->vertexInTree==false||edgePtr->destinationVertex->vertexInTree==false)) {//both vertices present,
						if(!spTree.cycle(edgePtr->startVertex, edgePtr->destinationVertex)) result = edgePtr;//cycle absent 
					}
					else {
						result = edgePtr;	
					}
					break;
				}
				if(result!=NULL) break;
			}
			if(result!=NULL) break;
			edgePtr = edgePtr->nextEdge;
		}
		if(result!=NULL) break;
		vertexPtr = vertexPtr->nextVertex;
	}
	return result;
}

int main()
{
	int choice,d;
	char flag='n';
	graphKruskals U;
	string place1,place2, name;
	U.createGraph();
		do {
			cout << "\n\tMENU:\n\t(1)Insert a place.\n\t(2)Add edges and distances.\n\t(3)Display graph.\n\t"
					"(4)Kruskal's algorithm.\n\t(5)Exit.\n\tEnter your choice : ";
			cin >> choice;
			switch(choice)
			{
				case 1 : do {
						 cout << "\n\tEnter name of the place : ";
						 cin >> name;
				         U.insertVertex(name, 0);
				         cout << "\nEnter another place ? (y/n)";
				         cin >> flag;
				     	 }while(flag=='y');
						 break;

				case 2 : cout << "\n\tEnter place1 : ";
						 cin >> place1;
						 cout << "\n\tEnter place2 : ";
						 cin >> place2;
						 cout << "\n\tEnter distance between " << place1 << " and " << place2 << " : " ;
						 cin >> d;
				         U.insertEdge(place1, place2, d, 0);
						 break;

				case 3 : cout << "\n\t==========================================================" << endl;
						 cout << "\n\tGRAPH IN ADJACENCY LIST FORMAT" << endl;
						 cout << "\n\t==========================================================" << endl;
				         U.displayGraph(0);
				         cout << "\n\t==========================================================" << endl;
						 break;
						 
				case 4 : U.Kruskals();
						 break;

				case 5 : return 0;
				
				default : cout << "\n\tINVALID CHOICE!";
			}
		}while(1);
}
/*

        MENU:
        (1)Insert a place.
        (2)Add edges and distances.
        (3)Display graph.
        (4)Kruskal's algorithm.
        (5)Exit.
        Enter your choice : 1

        Enter name of the place : A

Enter another place ? (y/n)y

        Enter name of the place : B

Enter another place ? (y/n)y

        Enter name of the place : C

Enter another place ? (y/n)y

        Enter name of the place : D

Enter another place ? (y/n)y

        Enter name of the place : E

Enter another place ? (y/n)y

        Enter name of the place : F

Enter another place ? (y/n)n

        MENU:
        (1)Insert a place.
        (2)Add edges and distances.
        (3)Display graph.
        (4)Kruskal's algorithm.
        (5)Exit.
        Enter your choice : 2

        Enter place1 : A

        Enter place2 : C

        Enter distance between A and C : 1

        MENU:
        (1)Insert a place.
        (2)Add edges and distances.
        (3)Display graph.
        (4)Kruskal's algorithm.
        (5)Exit.
        Enter your choice : 2

        Enter place1 : D

        Enter place2 : F

        Enter distance between D and F : 2

        MENU:
        (1)Insert a place.
        (2)Add edges and distances.
        (3)Display graph.
        (4)Kruskal's algorithm.
        (5)Exit.
        Enter your choice : 2

        Enter place1 : B

        Enter place2 : E

        Enter distance between B and E : 3

        MENU:
        (1)Insert a place.
        (2)Add edges and distances.
        (3)Display graph.
        (4)Kruskal's algorithm.
        (5)Exit.
        Enter your choice : 2

        Enter place1 : C

        Enter place2 : F

        Enter distance between C and F : 4

        MENU:
        (1)Insert a place.
        (2)Add edges and distances.
        (3)Display graph.
        (4)Kruskal's algorithm.
        (5)Exit.
        Enter your choice : 2

        Enter place1 : C

        Enter place2 : D

        Enter distance between C and D : 5

        MENU:
        (1)Insert a place.
        (2)Add edges and distances.
        (3)Display graph.
        (4)Kruskal's algorithm.
        (5)Exit.
        Enter your choice : 2

        Enter place1 : B

        Enter place2 : C

        Enter distance between B and C : 5

        MENU:
        (1)Insert a place.
        (2)Add edges and distances.
        (3)Display graph.
        (4)Kruskal's algorithm.
        (5)Exit.
        Enter your choice : 2

        Enter place1 : A

        Enter place2 : D

        Enter distance between A and D : 5

        MENU:
        (1)Insert a place.
        (2)Add edges and distances.
        (3)Display graph.
        (4)Kruskal's algorithm.
        (5)Exit.
        Enter your choice : 2

        Enter place1 : A

        Enter place2 : B

        Enter distance between A and B : 6

        MENU:
        (1)Insert a place.
        (2)Add edges and distances.
        (3)Display graph.
        (4)Kruskal's algorithm.
        (5)Exit.
        Enter your choice : 2

        Enter place1 : C

        Enter place2 : E

        Enter distance between C and E : 6

        MENU:
        (1)Insert a place.
        (2)Add edges and distances.
        (3)Display graph.
        (4)Kruskal's algorithm.
        (5)Exit.
        Enter your choice : 2

        Enter place1 : E

        Enter place2 : F

        Enter distance between E and F : 6

        MENU:
        (1)Insert a place.
        (2)Add edges and distances.
        (3)Display graph.
        (4)Kruskal's algorithm.
        (5)Exit.
        Enter your choice : 3

        ==========================================================

        GRAPH IN ADJACENCY LIST FORMAT

        ==========================================================

        A       -> C[1] -> D[5] -> B[6]
        B       -> E[3] -> C[5] -> A[6]
        C       -> A[1] -> F[4] -> D[5] -> B[5] -> E[6]
        D       -> F[2] -> C[5] -> A[5]
        E       -> B[3] -> C[6] -> F[6]
        F       -> D[2] -> C[4] -> E[6]

        ==========================================================

        MENU:
        (1)Insert a place.
        (2)Add edges and distances.
        (3)Display graph.
        (4)Kruskal's algorithm.
        (5)Exit.
        Enter your choice : 4

        PASS WISE DISPLAY :
        A       -> C[1]


        PASS WISE DISPLAY :
        A       -> C[1]

        D       -> F[2]


        PASS WISE DISPLAY :
        A       -> C[1]

        D       -> F[2]

        B       -> E[3]


        PASS WISE DISPLAY :
        A       -> C[1]

        C       -> F[4]

        D       -> F[2]

        B       -> E[3]


        PASS WISE DISPLAY :
        A       -> C[1]

        A       -> D[5]

        C       -> F[4]

        D       -> F[2]

        B       -> E[3]


        ==========================================================

        SPANNING TREE USING KRUSKAL'S ALGORITHM-

        ==========================================================

        A       -> C[1]

        A       -> D[5]

        C       -> F[4]

        D       -> F[2]

        B       -> E[3]


        ==========================================================

        MENU:
        (1)Insert a place.
        (2)Add edges and distances.
        (3)Display graph.
        (4)Kruskal's algorithm.
        (5)Exit.
        Enter your choice : 5
*/
