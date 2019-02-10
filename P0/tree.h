//
//  tree.h
//  P0
//
//  Created by Eric Goodwin on 2/10/19.
//  Copyright © 2019 umsl. All rights reserved.
//

#ifndef tree_h
#define tree_h

#include <string.h>
#include "node.h"


class tree
{
    public:
        tree();
    
        void buildTree(int key, string word);
        node *search(int key);
        void destroy_tree();
    
    private:
        void destroy_tree(node *leaf);
        void insert(int key, node *leaf, string word);
        void *search(int key, node *leaf);
    
        node *root;
    
        //prototypes
     //   void buildTree();
        void printInorder();
        void printPreorder();
        void printPostorder();

    
};




#endif /* tree_h */
