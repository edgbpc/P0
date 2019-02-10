//
//  node.h
//  P0
//
//  Created by Eric Goodwin on 2/9/19.
//  Copyright © 2019 umsl. All rights reserved.
//

#include <set>
#include <string.h>
#include <stdio.h>

#ifndef node_h
#define node_h

using namespace std;

struct ListNode {
    int data;
    ListNode *next;
};

struct node{
    int numCharacters;
    set<string> words;
    struct node *left;
    struct node *right;
};

#endif /* node_h */
