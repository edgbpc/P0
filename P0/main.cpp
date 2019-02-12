//
//  main.cpp
//  P0
//
//  Created by Eric Goodwin on 2/3/19.
//  Copyright © 2019 umsl. All rights reserved.
//

#include <iostream>
#include <string.h>
#include <fstream>
#include <stdio.h>
#include "node.h"
#include "tree.h"

using namespace std;

int main(int argc, const char * argv[]) {
    
    ifstream fileToRead; //get the data to be processed
    ofstream fileToWrite;
    ofstream file;
    
    string fileName;
    string data; //variable that will be used in the tree
    string word;
    int wordLength;
    
    tree myTree;


    //keyboard input or redirection
    switch (argc)
    {
    //keyboard input or redirection input
        case 1:
            cout << "Keyboard or redirection" << endl;
            fileToWrite.open("temp.dat");
            //hitting enter will end input.  simulated end of file?
            getline(cin, data);
            //will need to work on redirection on delmar
            fileToWrite << data << endl;
            fileToRead.open("temp.dat");
            break;
    //file input
        case 2:
            cout << "File Input Mode" << endl;
            fileName = argv[1];
            fileName.append(".sp19");
       //     cout << fileName << endl;
            fileToRead.open(fileName.c_str());
            break;
    
        default:
            cout << "Error" << endl;
            break;
    }
    
    while (fileToRead >> word){
      //  cout << word << endl;

        wordLength = int(word.length());
        //cout << wordLength << endl;
        myTree.buildTree(wordLength, word);
    }
    freopen("out.InOrder", "w", stdout);
    cout << "In order:" << endl;
    myTree.printInorder(myTree.getRoot(myTree));
    cout << endl;
    freopen("out.PostOrder", "w", stdout);
    cout << "Post order" << endl;
    myTree.printPostorder(myTree.getRoot(myTree));
    cout << endl;
    freopen("out.PreOrder", "w", stdout);
    cout << "Preorder" << endl;
    myTree.printPreorder(myTree.getRoot(myTree));
    cout << endl;

    //clean up the temporary file created
    remove("temp.dat");
    
    return 0;
}
