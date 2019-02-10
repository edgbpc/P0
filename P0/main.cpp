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


//changed in delmar
//changed in xcode

using namespace std;

int main(int argc, const char * argv[]) {
    
    ifstream fileToRead; //get the data to be processed
    ofstream fileToWrite;
    
    string data; //variable that will be used in the tree
    string word;

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
            fileToRead.open(argv[1]);
            break;
    
        default:
            cout << "Error" << endl;
            break;
    }
    
    
    while (fileToRead >> word){
        cout << word << endl;

    }
    
    return 0;
}
