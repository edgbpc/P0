//
//  tree.cpp
//  P0
//
//  Created by Eric Goodwin on 2/10/19.
//  Copyright © 2019 umsl. All rights reserved.
//

#include "tree.h"
#include <stdio.h>
#include <iostream>
#include "node.h"


/*
this code is credited to https://www.cprogramming.com/tutorial/lesson18.html
minor edits made to that to code for this project
*/
 
using namespace std;

//TEST TREE BUILDING

tree::tree()
{
    root = NULL;
}

void tree::insert(int key, node *leaf, string word){
    if (key < leaf->key_value) {
        if(leaf->left != NULL)
            insert(key, leaf->left, word);
        else {
            leaf->left = new node;
            leaf->left->key_value=key;
            leaf->left->words.insert(word);
            leaf->left->left = NULL;
            leaf->left->right = NULL;
        }
    } else if (key > leaf->key_value){
        if(leaf->right != NULL)
            insert(key, leaf->right, word);
        else{
            leaf->right = new node;
            leaf->right->key_value = key;
            leaf->right->words.insert(word);
            leaf->right->left = NULL;
            leaf->right->right = NULL;
        }
    } else {
        leaf->words.insert(word);
    }
}

void tree::buildTree(int key, string word){
  //  cout << key << endl;
    if (root != NULL)
        insert(key, root, word);
    else {
        root = new node;
        root->key_value = key;
        root->words.insert(word);
        root->left = NULL;
        root->right = NULL;
    }
}

void tree::printInorder(struct node* node){
    if (node == NULL)
        return;
    
    printInorder(node->left);
    for (set<string>::const_iterator it=node->words.begin(); it != node->words.end(); ++it){
        cout << node->key_value << ":";
        int depth = getLevel(root, int(node->key_value));
        for (int i = 1; i <= depth; i++){
            cout << " ";
        }
        cout << *it << endl;
    }

    printInorder(node->right);
}


void tree::printPreorder(struct node* node){
    if (node == NULL)
        return;

    for (set<string>::const_iterator it=node->words.begin(); it != node->words.end(); ++it){
        cout << node->key_value << ":";
        int depth = getLevel(root, int(node->key_value));
        for (int i = 1; i <= depth; i++){
            cout << " ";
        }
        cout << *it << endl;
    }

    printPreorder(node->left);
    printPreorder(node->right);
    
}

void tree::printPostorder(struct node* node){
    if (node == NULL)
        return;
    printPostorder(node->left);
    printPostorder(node->right);

//    cout << node->key_value << ":";
    
    for (set<string>::const_iterator it=node->words.begin(); it != node->words.end(); ++it){
        cout << node->key_value << ":";
        int depth = getLevel(root, int(node->key_value));
        for (int i = 1; i <= depth; i++){
            cout << " ";
        }
        cout << *it << endl;
    }
}


node * tree::getRoot(tree myTree){
    return myTree.root;
}

//https://www.geeksforgeeks.org/get-level-of-a-node-in-a-binary-tree

int tree::getLevelUtil(struct node * node, int key_value, int level){
    if (node == NULL)
        return 0;
    if (node->key_value == key_value)
        return level;
    int downlevel = getLevelUtil(node->left, key_value, level + 1);
    if (downlevel != 0)
        return downlevel;
    downlevel = getLevelUtil(node->right, key_value, level + 1);    
    return downlevel;
}

int tree::getLevel(struct node *node, int key_value){
    return getLevelUtil(node, key_value, 1);
}

    









