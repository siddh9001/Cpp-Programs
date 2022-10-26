/* C++ program to construct a binary tree from
the given string */
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

/* A binary tree node has data, pointer to left
child and a pointer to right child */
struct Node {
	int data;
	Node *left, *right;
};
/* Helper function that allocates a new node */
Node* newNode(int data)
{
	Node* node = (Node*)malloc(sizeof(Node));
	node->data = data;
	node->left = node->right = NULL;
	return (node);
}

/* This function is here just to test */
void preOrder(Node* node)
{
	if (node == NULL)
		return;
	printf("%d ", node->data);
	preOrder(node->left);
	preOrder(node->right);
}

// function to return the index of close parenthesis
int findIndex(string str, int si, int ei)
{
	if(si > ei) return -1;

    stack<char> st;

    for(int i=si;i<=ei;i++){
        if(str[i] == '(')
            st.push(str[i]);
        else if(str[i] == ')' && st.top() == '('){
            st.pop();
            if(st.empty()) return i;
        }
    }

    return -1;
}

// function to construct tree from string
Node* treeFromString(string str, int si, int ei)
{
	if(si > ei) return NULL;

    Node* root = newNode(str[si] - '0');

    int index=-1;

    if(si+1 <= ei && str[si+1] == '(')
        index = findIndex(str, si+1, ei);

    if(index != -1){

        root->left = treeFromString(str, si+2, index-1);
        root->right = treeFromString(str, index+2, ei-1);
    }

	return root;
}

// Driver Code
int main()
{
	string str = "4(2(3)(1))(6(5))";
	Node* root = treeFromString(str, 0, str.length() - 1);
	preOrder(root);
}
