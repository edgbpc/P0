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
#include <stdlib.h>
#include "node.h"
#include "tree.h"

using namespace std;

//unused for this project.  keeping for future use
// bool doesFileExistAndReadable(ifstream filename);

int main(int argc, const char * argv[]) {
    
    ifstream fileToRead; //get the data to be processed
    ofstream fileToWrite;
    FILE *outFile;
   
    string fileName;
    string outFileNameBase;
    string outFileName;
    string data; //variable that will be used in the tree
    string word;
    int wordLength;
    
    tree myTree;

    //keyboard input or redirection
    switch (argc)
    {
    //keyboard input or redirection input
        case 1:
            cout << "Keyboard or Redirection Input Mode" << endl;
            fileToWrite.open("temp.dat");
            //hitting enter will end input.  simulated end of file?
            while (getline(cin, data)){
                fileToWrite << data << endl;
            }
            outFileNameBase = "out";
            
            //will need to work on redirection on delmar
            fileToRead.open("temp.dat");
            
            break;
    //file input
        case 2:
            cout << "File Input Mode" << endl;
            fileName = argv[1];
            fileName.append(".sp19");
       //     cout << fileName << endl;
            fileToRead.open(fileName.c_str());
            
            outFileNameBase = argv[1];
            
            break;
    
        default:
            cout << "Error" << endl;
            break;
    }
    
    if (fileToRead.good()){
        while (fileToRead >> word){
          //  cout << word << endl;

            wordLength = int(word.length());
            //cout << wordLength << endl;
            myTree.buildTree(wordLength, word);
        }
    } else {
            cout << "Error: Could not read file. Exiting" << endl;
	    exit 1;
    }
    
    outFileName = outFileNameBase + ".inorder";
    
    outFile = fopen(outFileName.c_str(), "w");
    cout << "Generating " << outFileNameBase << ".inorder" << endl;
    myTree.printInorder(myTree.getRoot(myTree), outFile);
    fclose(outFile);
    
    outFileName = outFileNameBase + ".preorder";
    
    outFile = fopen(outFileName.c_str(), "w");
    cout << "Generating " << outFileNameBase << ".preorder" << endl;
    myTree.printPreorder(myTree.getRoot(myTree), outFile);
    fclose(outFile);
    
    outFileName = outFileNameBase + ".postorder";
    
    outFile = fopen(outFileName.c_str(), "w");
    cout << "Generating " << outFileNameBase << ".postorder" << endl;
    myTree.printPostorder(myTree.getRoot(myTree), outFile);
    fclose(outFile);


    fileToRead.close();
    
    //clean up the temporary file created
    remove("temp.dat");
    
    return 0;
    
}

// bool doesFileExistAndReadable(ifstream filename){
//    return filename.good();
//}

