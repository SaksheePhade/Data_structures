/*//============================================================================
// Name        : Assignment5.cpp
// Author      : Sakshee Roll no : 23244
// Problem Statement : Implement binary search tree and perform following operations:
						a. Insert
						b. Delete
						c. Search
						d. Mirror image
						e. Display
						f. Display level wise
//============================================================================
*/

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Tnode
{
	int data;
	Tnode *left;
	Tnode *right;
	friend class BST;
};

class BST
{
	Tnode *Root;
	public :
		BST(){
			Root=NULL;
		}
		void insert();
		Tnode* makenode(int);
		void display(Tnode*);
		void search(int);
		void levelwise_d();
		Tnode* getroot();
		int depth(Tnode*);
		void printlevel(Tnode*, int);
		void mirror(Tnode*);
		Tnode* deletenode(Tnode*,int);
		Tnode* minValueNode(Tnode*);
};

Tnode* BST :: getroot()
{
	return Root;
}

Tnode* BST :: deletenode(Tnode* q, int data) {

    if (q == NULL) return Root;

    if (data < q->data)
        q->left = deletenode(q->left, data);

    else if (data > q->data)
        q->right = deletenode(q->right, data);

    else
    {
        if (q->left == NULL)
        {
            Tnode *temp = q->right;
            free(q);
            return temp;
        }
        else if (q->right == NULL)
        {
            Tnode *temp = q->left;
            free(q);
            return temp;
        }

        Tnode* temp = minValueNode(q->right);

        // Copy the inorder successor's content to this node
        q->data = temp->data;

        // Delete the inorder successor
        q->right = deletenode(q->right, temp->data);
    }
    return q;
}

Tnode* BST :: minValueNode(Tnode* node) 
{
    Tnode* current = node;
    while (current && current->left != NULL)
        current = current->left;
    return current;
}

void BST :: levelwise_d()
{
	int i;
	cout << "\n\t";
	if(Root!=NULL) {
		for(i=0;i<depth(Root);i++)
			printlevel(Root,i+1);
	}
}

void BST :: printlevel(Tnode *root,int l)
{
	Tnode *temp = Root;
	if(root==NULL)
		return;
	if(l==1)
		cout << " " << root->data << " ";
	else {
		printlevel(root->left,l-1);
		printlevel(root->right,l-1);
	}
}

int BST :: depth(Tnode *root)
{
	Tnode* temp;
	temp = root;
	int dtl,dtr;
	if(temp==NULL)
		return 0;
	else {
		dtl = depth(temp->left)+1;
		dtr = depth(temp->right)+1;
	}
	if(dtl>dtr)
		return dtl;
	else
		return dtr;
}

void BST :: mirror(Tnode* root){
	if (root == NULL)
        return;
    else {
        Tnode* temp;
        mirror(root->left);
        mirror(root->right);
        temp = root->left;
        root->left = root->right;
        root->right = temp;
    }
    Root = root;
}

Tnode* BST :: makenode(int d)
{
	Tnode *temp=NULL;
	temp = new Tnode;
	temp->data = d;
	temp->left = NULL;
	temp->right = NULL;
	return temp;
}

void BST :: insert()
{
	int d;
	Tnode *temp = NULL;
	Tnode *insertnode = NULL;
	insertnode = new Tnode;
	if(Root==NULL) {
		cout << "\n\tEnter root node data : ";
		cin >> d;
		Root = makenode(d);
		return;
	}
	else {
		cout << "\n\tEnter data for node to be inserted : ";
		cin >> d;
		insertnode->data = d;
		temp = Root;

			while(1) {
				if(temp->data > d) {
					if(temp->left==NULL) {
						temp->left = insertnode;
						return;
					}
					else {
						temp = temp->left;
					}
				}
				else if(temp->data < d) {
						if(temp->right==NULL) {
							temp->right=insertnode;
							return;
						}
						else {
							temp = temp->right;
						}
				}
				else {
					cout << "\nGiven data already exists!!" << endl;
					return;
				}
			}
	}
}

void BST :: search(int data)
{
	int ht = 0;
	Tnode* temp = Root;
	while(temp != NULL){
		ht++;
		if(temp->data == data) {
			cout<<"\n\tSearched element found at level : "<< ht << "\n";
			return;
		}
		else if(temp->data > data)
			temp = temp->left;
		else
			temp = temp->right;
	}
	cout<<"\n\tData not found\n";
	return;
}

void BST :: display(Tnode *root)
{
	if(root!=NULL) {
		display(root->left);
		cout << " " << root->data << " ";
		display(root->right);
	}
}

int main()
{
	BST tree,mirr;
	int i,choice,num,search,del;
	do {
		cout << "\n\tMENU:\n\t(1)Insert node in BST\n\t(2)Display the BST\n\t"
				"(3)Search an element\n\t(4)Depth of tree\n\t(5)Level-wise display\n\t"
				"(6)Mirror image of the tree\n\t(7)Delete element\n\t(8)Exit\n\tEnter your choice : ";
		cin >> choice;
		switch(choice)
		{
		case 1 : cout << "\n\tEnter number of nodes you wish to insert : ";
				 cin >> num;
				 for(i=0;i<num;i++)
					 tree.insert();
				 break;

		case 2 : cout << "\n\tGiven BST is :-\n";
				 cout << "\t";
				 tree.display(tree.getroot());
				 break;

		case 3 : cout << "\n\tEnter element to be searched : ";
				 cin >> search;
				 tree.search(search);
				 break;

		case 4 : cout << "\n\tDepth of the given tree is : ";
				 cout << tree.depth(tree.getroot());
				 break;

		case 5 : cout << "\n\tLevel wise display :-\n";
				 tree.levelwise_d();
				 break;

		case 6 : cout << "\n\tMirror image :-";
				 cout << "\n\t";
				 mirr.mirror(tree.getroot());
				 mirr.display(mirr.getroot());
				 break;
		
		case 7 : cout << "\n\tEnter element to be deleted : ";
				 cin >> del;
				 tree.deletenode(tree.getroot(),del);
				 cout << "\n\tDeletion Successful.";
				 break;
			 
		case 8 : return 0;
		}

	}while(1);
}
/*
	MENU:
	(1)Insert node in BST
	(2)Display the BST
	(3)Search an element
	(4)Depth of tree
	(5)Level-wise display
	(6)Mirror image of the tree
	(7)Delete element
	(8)Exit
	Enter your choice : 1

	Enter number of nodes you wish to insert : 5

	Enter root node data : 6

	Enter data for node to be inserted : 2

	Enter data for node to be inserted : 8

	Enter data for node to be inserted : 7

	Enter data for node to be inserted : 1

	MENU:
	(1)Insert node in BST
	(2)Display the BST
	(3)Search an element
	(4)Depth of tree
	(5)Level-wise display
	(6)Mirror image of the tree
	(7)Delete element
	(8)Exit
	Enter your choice : 3

	Enter element to be searched : 3

	Data not found

	MENU:
	(1)Insert node in BST
	(2)Display the BST
	(3)Search an element
	(4)Depth of tree
	(5)Level-wise display
	(6)Mirror image of the tree
	(7)Delete element
	(8)Exit
	Enter your choice : 2

	Given BST is :-
	 1  2  6  7  8 
	MENU:
	(1)Insert node in BST
	(2)Display the BST
	(3)Search an element
	(4)Depth of tree
	(5)Level-wise display
	(6)Mirror image of the tree
	(7)Delete element
	(8)Exit
	Enter your choice : 3

	Enter element to be searched : 7

	Searched element found at level : 3

	MENU:
	(1)Insert node in BST
	(2)Display the BST
	(3)Search an element
	(4)Depth of tree
	(5)Level-wise display
	(6)Mirror image of the tree
	(7)Delete element
	(8)Exit
	Enter your choice : 4

	Depth of the given tree is : 3
	MENU:
	(1)Insert node in BST
	(2)Display the BST
	(3)Search an element
	(4)Depth of tree
	(5)Level-wise display
	(6)Mirror image of the tree
	(7)Delete element
	(8)Exit
	Enter your choice : 5

	Level wise display :-

	 6  2  8  1  7 
	MENU:
	(1)Insert node in BST
	(2)Display the BST
	(3)Search an element
	(4)Depth of tree
	(5)Level-wise display
	(6)Mirror image of the tree
	(7)Delete element
	(8)Exit
	Enter your choice : 6

	Mirror image :-
	 8  7  6  2  1 
	MENU:
	(1)Insert node in BST
	(2)Display the BST
	(3)Search an element
	(4)Depth of tree
	(5)Level-wise display
	(6)Mirror image of the tree
	(7)Delete element
	(8)Exit
	Enter your choice : 7

	Enter element to be deleted : 2
	Deletion Successful.

	MENU:
	(1)Insert node in BST
	(2)Display the BST
	(3)Search an element
	(4)Depth of tree
	(5)Level-wise display
	(6)Mirror image of the tree
	(7)Delete element
	(8)Exit
	Enter your choice : 2

	Given BST is :-
     1  6  7  8


*/
