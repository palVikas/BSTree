typedef struct Node * node_ptr;
typedef struct tree BSTree;
typedef struct Node Node;
typedef void (traverseFunc)(int data);

struct Node {
	int data;	
	node_ptr left;
	node_ptr right;
};

struct tree{
	node_ptr root;
};

BSTree createBSTree(void);

Node* create_node(int data);

Node* insertInto(Node* root,int data);

int insert(BSTree *, int);

Node* search(Node * root,int data);

Node * find(BSTree, int);

void inorder(Node* node,traverseFunc* print_element);

void traverse(BSTree tree, traverseFunc* print_element);

// Node * delete(BSTree *tree, int data);