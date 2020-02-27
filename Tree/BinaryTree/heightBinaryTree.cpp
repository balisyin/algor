/* *
 * balisyin 20200223
 * all binary tree algorithm
 * */
//#include<bits/stdc++.h>
#include<iostream>
#include<stack>
#include<queue>

using namespace std;

struct tNode{
    int data;
    tNode* left;
    tNode* right;
    tNode(int i):data(i),left(nullptr),right(nullptr){}
};
int depthOfBinaryTree(tNode *root, int &maxDistance) {
    if (root == nullptr) {
        return -1;
    }
    int heightLeft = depthOfBinaryTree(root->left, maxDistance) +1;
    int heightRight = depthOfBinaryTree(root->right, maxDistance) +1;
    maxDistance = heightLeft + heightRight;

    return heightLeft > heightRight ? heightLeft : heightRight;
}
int main(int arg, char* args[]){



    return 0;
}