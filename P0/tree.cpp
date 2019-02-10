//
//  tree.cpp
//  P0
//
//  Created by Eric Goodwin on 2/10/19.
//  Copyright © 2019 umsl. All rights reserved.
//

#include <stdio.h>
#include "tree.h"
#include <string.h>
#include <iostream>
#include "node.h"
#include <set>
#include <stdlib.h>

/*
this code is credited to https://www.tutorialspoint.com/data_structures_algorithms/tree_data_structure.htm
minor edits made to that to code for this project
*/
 
using namespace std;

struct node *root = NULL;

void insert(int data, string word) {
    struct node *tempNode = (struct node*) malloc(sizeof(struct node));
    struct node *current;
    struct node *parent;
    
    tempNode->data = data;
    tempNode->words.insert(word);
    tempNode->leftChild = NULL;
    tempNode->rightChild = NULL;
    
    //if tree is empty, create root node
    if(root == NULL) {
        root = tempNode;
    } else {
        current = root;
        parent  = NULL;
        
        while(1) {
            parent = current;
            
            //go to left of the tree
            if(data < parent->data) {
                current = current->leftChild;
                
                //insert to the left
                if(current == NULL) {
                    parent->leftChild = tempNode;
                    return;
                }
            }
            
            //go to right of the tree
            else {
                current = current->rightChild;
                
                //insert to the right
                if(current == NULL) {
                    parent->rightChild = tempNode;
                    return;
                }
            }
        }
    }
}

//end cited code


void buildTree(int data, string words){
    insert(data, words);
}
