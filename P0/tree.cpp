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
    } else if (key >= leaf->key_value){
        if(leaf->right != NULL)
            insert(key, leaf->right, word);
        else{
            leaf->right = new node;
            leaf->right->key_value = key;
            leaf->right->words.insert(word);
            leaf->right->left = NULL;
            leaf->right->right = NULL;
        }
    }
}

void tree::buildTree(int key, string word){
    cout << key << endl;
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








