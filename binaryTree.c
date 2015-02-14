#include <stdio.h>
#include "binaryTree.h"
#include <stdlib.h>

BSTree createBSTree(void){
	BSTree tree;
	tree.root = NULL;
	return tree;
};

Node* create_node(int data){
	Node* node = malloc(sizeof(Node));
	node->data = data;
	node->left = NULL;
	node->right = NULL;
	return node;
};

Node* insertInto(Node* root,int data){
	Node* temp = create_node(data);
	if(root == NULL){
		root = temp;
		return root;
	}
	else {
		if(data < root->data){
		  root->left = insertInto(root->left,data);
		}
		else 
		  root->right = insertInto(root->right,data);
		return root;
	};
};

int insert(BSTree *tree, int data) {
	Node* node = tree->root;
	tree->root = insertInto(node,data);
	return (tree->root != NULL);
}

Node* search(Node * root,int data){
	if(root == NULL || root->data == data)
		return root;
	if(data < root->data)
		return search(root->left,data);
	return search(root->right,data);
};

Node * find(BSTree tree, int data){
	Node* node ;
	node = search(tree.root,data);
	return node;
};

void inorder(Node* node,traverseFunc* print_element){
	if (node == NULL) return;
	 inorder(node->left,print_element);
	 print_element(node->data);
	 inorder(node->right,print_element);
}

void traverse(BSTree tree,traverseFunc*  print_element){
	  inorder(tree.root,print_element);
}

// Node * delete(BSTree *tree, int data){

// }