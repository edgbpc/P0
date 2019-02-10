//
//  node.h
//  P0
//
//  Created by Eric Goodwin on 2/9/19.
//  Copyright © 2019 umsl. All rights reserved.
//


#ifndef node_h
#define node_h

#include <set>
#include <string.h>
#include <stdio.h>



using namespace std;

struct node{
    int data;
    set<string> words;
    struct node *leftChild;
    struct node *rightChild;
};



#endif /* node_h */
