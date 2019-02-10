//
//  node.h
//  P0
//
//  Created by Eric Goodwin on 2/9/19.
//  Copyright © 2019 umsl. All rights reserved.
//



#include <set>
#include <string>
#include <stdio.h>

#ifndef node_h
#define node_h

using namespace std;

struct node{
    int data;
    set<string> words;
    struct node *leftChild;
    struct node *rightChild;
};



#endif /* node_h */
