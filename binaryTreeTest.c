#include <stdio.h>
#include "binaryTree.h"
#include "expr_assert.h"

BSTree tree;
Node* result;
Node* result1;
Node* result2;


void test_for_createBinaryTree_create_an_empty_list_and_gives_root_is_null(){
	tree = createBSTree();
	assert(tree.root == NULL);
};


void test_insertInto_function_add_the_node_in_the_root_of_the_tree(){
	int x=5;
	Node* root=NULL;
	result = insertInto(root,x);
	assertEqual(result->data, 5);
}

void test_insertInto_function_add_the_2_node_in_the_root_node(){
	int x=5,y=3;
	Node* root=NULL;

	result = insertInto(root,x);
	result1 = insertInto(result,y);
	assertEqual(result->data, 5);
	assertEqual(result->left->data, 3);
	assert(result1->right == NULL);

}

void test_insertInto_function_add_the_3_node_in_the_root_(){
	int x=5,y=3 ,z=6;
	Node* root=NULL;

	result = insertInto(root,x);
	result1 = insertInto(result,y);
	result2 = insertInto(result1,z);

	assertEqual(result->data, 5);
	assertEqual(result->left->data, 3);
	assertEqual(result->right->data, 6);
	assert(result1->right->left == NULL);

}

void test_insert_function_gives_1_if_insert_successful(){
	int x=4;
	tree = createBSTree();
	assertEqual(insert(&tree,x),1);
}

void test_insert_function_gives_data_of_the_root(){
	int x=4;
	tree = createBSTree();
	insert(&tree,x);
	assertEqual(tree.root->data,4);
}

void test_insert_function_gives_data_of_the_left_noad_from_the_r00t(){
	int x=14,y=12;
	tree = createBSTree();
	insert(&tree,x);
	insert(&tree,y);

	assertEqual(tree.root->data,14);
	assertEqual(tree.root->left->data,12);
	assert(tree.root->right == NULL);

}

void test_insert_function_gives_data_of_the_right_noad_from_the_r00t(){
	int x=14,y=16;
	tree = createBSTree();
	insert(&tree,x);
	insert(&tree,y);

	assertEqual(tree.root->data,14);
	assertEqual(tree.root->right->data,16);
	assert(tree.root->left == NULL);

}

void test_insert_function_gives_data_of_the_right_noad_from_the_r00t_if_integer_data_is_greater_than_root_data(){
	int x=14,y=16,z=65;
	tree = createBSTree();
	insert(&tree,x);
	insert(&tree,y);
	insert(&tree,z);

	assertEqual(tree.root->data,14);
	assertEqual(tree.root->right->data,16);
	assertEqual(tree.root->right->right->data,65);
	assert(tree.root->left == NULL);
}

void test_insert_function_gives_data_of_the_right_noad_from_the_r00t_if_integer_data_is_greater_than(){
	int x=14,y=116,z=65;
	tree = createBSTree();
	insert(&tree,x);
	insert(&tree,y);
	insert(&tree,z);

	assertEqual(tree.root->data,14);
	assertEqual(tree.root->right->data,116);
	assertEqual(tree.root->right->left->data,65);
	assert(tree.root->left == NULL);
};

void test_find_function_gives_node_from_related_data(){
	int x=14,y=12,z=34,a=4,b=23,c=47;
	tree = createBSTree();
	insert(&tree,x);
	insert(&tree,y);
	insert(&tree,z);
	insert(&tree,a);
	insert(&tree,b);
	insert(&tree,c);

	result = find(tree,34);
	assertEqual(result->data, 34);
	assertEqual(result->right->data, 47);
	assertEqual(result->left->data, 23);

}

void test_search_function__gives_the_node_of_related_data_(){
	int x=5,y=3 ,z=6,a=12;
	Node* root=NULL;
	Node * result3;
	Node * result4;

	result = insertInto(root,x);
	result1 = insertInto(result,y);
	result2 = insertInto(result1,z);
	result3 = insertInto(result2,a);

	result4 = search(result3,5);
	assertEqual(result4->data, 5);
	assertEqual(result4->left->data,3);
	
};

void print_element(int data){
	printf("%d\n",data);
}

void test_for_traverse_function_to_print_the_element_in_tree(){
	tree = createBSTree();

	insert(&tree,23);
	insert(&tree,1);
	insert(&tree,11);
	insert(&tree,6);
	traverse(tree,print_element);

}