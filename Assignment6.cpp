//============================================================================
// Name        : Assignment6.cpp
// Author      : Sakshee
// Roll no : 23244 Batch : G10
// Problem statement : Consider friends network or a social website.Model it a a
//					   graph to represent each node as a user and link to represent
//					   friend relationship between them. Store data such as DOB, no.
//                     of comments. Find who has max friends and posted
//					   max and min comments. Find users having birthday in
//					   current month.
//============================================================================

#include<iostream>
#include<string.h>
#include<queue>
using namespace std;

class graphVertex;

	class graphEdge
	{
		graphEdge *nextEdge;
		graphVertex *destinationVertex;
		friend class graphSocialnetwork;

		public:
			graphEdge() {
				nextEdge = NULL;
				destinationVertex = NULL;
			}
	};
	class graphVertex
	{
		string name;
		int DOBd,DOBm,DOBy;
		int commentsMade;
		bool visited;
		graphEdge *nextEdge;
		graphVertex *nextVertex;
		int friends;
		friend class graphSocialnetwork;

		public :
			graphVertex() {
				commentsMade = 0;
				nextEdge = NULL;
				nextVertex = NULL;
				visited = false;
				DOBm = DOBy = DOBd = 0;
				friends = 0;
			}
	};
	class graphHead
	{
		int count;
		graphVertex *firstVertex;
		friend class graphSocialnetwork;
	};

class graphSocialnetwork {

	graphHead *G;
	//graphEdge E;

public:
	graphSocialnetwork();
	virtual ~graphSocialnetwork();
	void createGraph();
	void insertVertex();
	void insertEdge(string, string);
	void displayGraph();
	void birthday(int);
	int maxFriends();
	int maxComments();
	int minComments();
	void DFS(graphVertex*,int);
	void BFS(graphVertex*,int,int);
	graphVertex *getGraphHead();
	void clear();
	//other program related functions
};

graphSocialnetwork::graphSocialnetwork() {
	// TODO Auto-generated constructor stub
	G=NULL;
}

graphSocialnetwork::~graphSocialnetwork() {
	// TODO Auto-generated destructor stub
}

void graphSocialnetwork :: clear()
{
	graphVertex *curr = G->firstVertex;
	while(curr!=NULL) {
		curr->visited = false;
		curr = curr->nextVertex;
	}
}

void graphSocialnetwork :: createGraph()
{
	G=new graphHead;
	G->count=0;
	G->firstVertex=NULL;
}

graphVertex* graphSocialnetwork :: getGraphHead()
{
	return G->firstVertex;
}

void graphSocialnetwork :: insertVertex()
{
	graphVertex *newVertex,*curr;
	newVertex = new graphVertex;

	cout << "\n\tEnter user name : ";
	cin >> newVertex->name;
	cout << "\n\tEnter date of birth : ";
	cin >> newVertex->DOBd >> newVertex->DOBm >> newVertex->DOBy;
	cout << "\n\tEnter number of comments made : ";
	cin >> newVertex->commentsMade;

	if(G->firstVertex==NULL) {
		G->firstVertex = newVertex;
		return;
	}

	curr = G->firstVertex;
	while(curr->nextVertex!=NULL) {
		curr = curr->nextVertex;
	}
	curr->nextVertex = newVertex;
	G->count++;
	return;
}

void graphSocialnetwork :: insertEdge(string friend1, string friend2)
{
	graphVertex *curr1,*curr2;
	graphEdge *fr1,*fr2;
	//Insert Edge (friend of user and create the proper links)
	curr1 = G->firstVertex;
	curr2 = G->firstVertex;
	if(curr1!=NULL) {

		while(curr1->name!=friend1) {
			curr1 = curr1->nextVertex;
		}
	
		while(curr2->name!=friend2) {
			curr2 = curr2->nextVertex;
		}

		fr1 = curr1->nextEdge;
		if(fr1==NULL) {
			curr1->nextEdge = new graphEdge;
			fr1 = curr1->nextEdge;
			fr1->destinationVertex = curr2;
			//cout << "\nfr1dest : " << fr1->destinationVertex->name <<endl;
		}
		else {
			while(fr1->nextEdge!=NULL) {
				fr1 = fr1->nextEdge;
			}
			fr1->nextEdge = new graphEdge;
			fr1 = fr1->nextEdge;
			fr1->destinationVertex = curr2;
			//cout << "\nfr1dest in while : " << fr1->destinationVertex->name <<endl;
		}
		curr1->friends++;
		fr2 = curr2->nextEdge;
		if(fr2==NULL) {
			curr2->nextEdge = new graphEdge;
			fr2 = curr2->nextEdge;
			fr2->destinationVertex = curr1;
			//cout << "\nfr2dest : " << fr2->destinationVertex->name <<endl;
		}
		else {
			while(fr2->nextEdge!=NULL) {
				fr2 = fr2->nextEdge;
			}
			fr2->nextEdge = new graphEdge;
			fr2 = fr2->nextEdge;
			fr2->destinationVertex = curr1;
		}
		curr2->friends++;
	}

}

void graphSocialnetwork :: displayGraph()
{
	graphVertex *vertexPtr = G->firstVertex;
	graphEdge *edgePtr;
	while(vertexPtr!=NULL) { //loop for vertices
		cout << "\n\t" << vertexPtr->name;
		edgePtr = vertexPtr->nextEdge;

		if(edgePtr!=NULL) {//loop for edges
			while(edgePtr!=NULL) {
				cout << " -> " << edgePtr->destinationVertex->name;
				edgePtr = edgePtr->nextEdge;
			}
		}
		vertexPtr = vertexPtr->nextVertex;
	}
	cout << endl;
	//display the graph in adjacency list form
}

void graphSocialnetwork :: birthday(int month)
{
	graphVertex *curr=G->firstVertex;

	while(curr->DOBm!=month) {
		if(curr->nextVertex==NULL) {
			cout << "\n\tNo one has a birthday in this month." << endl;
			return;
		}
		curr = curr->nextVertex;
	}
	cout << "\n\t" << curr->name << " has birthday in this month." << endl;
}

int graphSocialnetwork :: maxFriends()
{
	graphVertex *curr=G->firstVertex;
	int max;
	max = G->firstVertex->friends;
	while(curr!=NULL) {
		if(curr->friends > max)
			max = curr->friends;
		curr = curr->nextVertex;
	}
	return max;
}

int graphSocialnetwork :: maxComments()
{
	graphVertex *curr=G->firstVertex;
	int max;
	max = G->firstVertex->commentsMade;
	while(curr!=NULL) {
		if(curr->commentsMade > max)
			max = curr->commentsMade;
		curr = curr->nextVertex;
	}
	return max;
}

int graphSocialnetwork :: minComments()
{
	graphVertex *curr=G->firstVertex;
	int min;
	min = G->firstVertex->commentsMade;
	while(curr!=NULL) {
		if(curr->commentsMade < min)
			min = curr->commentsMade;
		curr = curr->nextVertex;
	}
	return min;
}

void graphSocialnetwork :: DFS(graphVertex *vertex,int max) // searching using DFS algo
{
	if(vertex->friends==max) {
		cout << "\n\t" << vertex->name << " has maximum number of friends " << max << "." << endl;
		return;
	}
	if(vertex->nextVertex!=NULL) {
		while(vertex->nextVertex->visited==false) {
			DFS(vertex->nextVertex,max);
		}
	}
	else
		return;
}

void graphSocialnetwork :: BFS(graphVertex *vertex,int key,int ch) //searching using BFS algo
{
	clear();
	graphEdge *edge;
	queue<graphVertex*> q;
	
	q.push(vertex);
	while(!q.empty()) {
		vertex = q.front();
		q.pop();
		vertex->visited = true;
		
		if(vertex->commentsMade==key) {
			if(ch==1)
				cout << "\n\t" << vertex->name << " has made maximum number of comments " << key << "." << endl;
			else if(ch==0)
				cout << "\n\t" << vertex->name << " has made minimum number of comments " << key << "." << endl;
			break;
		}
		
		edge = vertex->nextEdge;
		while(edge!=NULL) {
			if(edge->destinationVertex->visited==false)
				q.push(edge->destinationVertex);
			edge = edge->nextEdge;
		}
	}
	
}

int main()
{
	int choice,mon;
	char flag='n';
	graphSocialnetwork U;
	string friend1,friend2;
	U.createGraph();
	do {
		cout << "\n\tMENU:\n\t(1)Insert a user.\n\t(2)Add friends\n\t(3)Display graph.\n\t(4)Find who has birthday this month.\n\t"
				"(5)Maximum friends\n\t(6)Maximum and minimum comments\n\t(7)Exit.\n\tEnter your choice : ";
		cin >> choice;
		switch(choice)
		{
			case 1 : do {
			         U.insertVertex();
			         cout << "\nEnter another user ? (y/n)";
			         cin >> flag;
			     	 }while(flag=='y');
					 break;

			case 2 : cout << "\n\tEnter friend1 : ";
					 cin >> friend1;
					 cout << "\n\tEnter friend2 : ";
					 cin >> friend2;
			         U.insertEdge(friend1, friend2);
					 break;

			case 3 : U.displayGraph();
					 break;

			case 4 : cout << "\n\tEnter current month : ";
					 cin >> mon;
				     U.birthday(mon);
				     break;
			
			case 5 : U.DFS(U.getGraphHead(),U.maxFriends());
					 break;
			
			case 6 : U.BFS(U.getGraphHead(),U.maxComments(),1);
					 U.BFS(U.getGraphHead(),U.minComments(),0);
					 break;
					 
			case 7 : return 0;
		}
	}while(1);

}

/*

        MENU:
        (1)Insert a user.
        (2)Add friends
        (3)Display graph.
        (4)Find who has birthday this month.
        (5)Maximum friends
        (6)Maximum and minimum comments
        (7)Exit.
        Enter your choice : 1

        Enter user name : Harry

        Enter date of birth : 31 07 83

        Enter number of comments made : 567

Enter another user ? (y/n)y

        Enter user name : Ron

        Enter date of birth : 3 12 90

        Enter number of comments made : 456

Enter another user ? (y/n)y

        Enter user name : Hermoine

        Enter date of birth : 6 09 95

        Enter number of comments made : 666

Enter another user ? (y/n)y

        Enter user name : Ginny

        Enter date of birth : 01 01 00

        Enter number of comments made : 634

Enter another user ? (y/n)n

        MENU:
        (1)Insert a user.
        (2)Add friends
        (3)Display graph.
        (4)Find who has birthday this month.
        (5)Maximum friends
        (6)Maximum and minimum comments
        (7)Exit.
        Enter your choice : 2

        Enter friend1 : Harry

        Enter friend2 : Ron

        MENU:
        (1)Insert a user.
        (2)Add friends
        (3)Display graph.
        (4)Find who has birthday this month.
        (5)Maximum friends
        (6)Maximum and minimum comments
        (7)Exit.
        Enter your choice : 2

        Enter friend1 : Harry

        Enter friend2 : Hermoine

        MENU:
        (1)Insert a user.
        (2)Add friends
        (3)Display graph.
        (4)Find who has birthday this month.
        (5)Maximum friends
        (6)Maximum and minimum comments
        (7)Exit.
        Enter your choice : 2

        Enter friend1 : Harry

        Enter friend2 : Ginny

        MENU:
        (1)Insert a user.
        (2)Add friends
        (3)Display graph.
        (4)Find who has birthday this month.
        (5)Maximum friends
        (6)Maximum and minimum comments
        (7)Exit.
        Enter your choice : 2

        Enter friend1 : Hermoine

        Enter friend2 : Ginny

        MENU:
        (1)Insert a user.
        (2)Add friends
        (3)Display graph.
        (4)Find who has birthday this month.
        (5)Maximum friends
        (6)Maximum and minimum comments
        (7)Exit.
        Enter your choice : 3

        Harry -> Ron -> Hermoine -> Ginny
        Ron -> Harry
        Hermoine -> Harry -> Ginny
        Ginny -> Harry -> Hermoine

        MENU:
        (1)Insert a user.
        (2)Add friends
        (3)Display graph.
        (4)Find who has birthday this month.
        (5)Maximum friends
        (6)Maximum and minimum comments
        (7)Exit.
        Enter your choice : 4

        Enter current month : 12

        Ron has birthday in this month.

        MENU:
        (1)Insert a user.
        (2)Add friends
        (3)Display graph.
        (4)Find who has birthday this month.
        (5)Maximum friends
        (6)Maximum and minimum comments
        (7)Exit.
        Enter your choice : 5

        Harry has maximum number of friends 3.

        MENU:
        (1)Insert a user.
        (2)Add friends
        (3)Display graph.
        (4)Find who has birthday this month.
        (5)Maximum friends
        (6)Maximum and minimum comments
        (7)Exit.
        Enter your choice : 6

        Hermoine has made maximum number of comments 666.

        Ron has made minimum number of comments 456.

        MENU:
        (1)Insert a user.
        (2)Add friends
        (3)Display graph.
        (4)Find who has birthday this month.
        (5)Maximum friends
        (6)Maximum and minimum comments
        (7)Exit.
        Enter your choice : 7

--------------------------------
Process exited after 186.6 seconds with return value 0
Press any key to continue . . .
*/
