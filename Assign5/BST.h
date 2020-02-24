#ifndef BST_H_
#define BST_H_

template <class T>
class Node{
	T data;
	Node<T> *left, *right;

	public:
		template <class U> 
		friend class BST;
};

template<class T>
class BST {
	Node<T> *root;
	void inorder();
	void preorder();	
	void postorder();
	void levelorder();
	void printGivenLevel(Node<T>*, int);
	Node<T>* deleteR(Node<T>*, T);
	Node<T>* minValueNode(Node<T>*);
	int height(Node<T>*);
	void mirrorR(Node<T>*);

public: 
	// ALL ARE Non-Recursive Functions
	BST();
	void create();						// create tree //
	void insert(T);						// insert single node //
	void search(T);						// search the element in tree //
	void disleafs();					// for leaf node //
	void deleteNode(T);
	void mirror();
	virtual ~BST();
};

#endif /* BST_H_ */