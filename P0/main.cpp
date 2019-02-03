//
//  main.cpp
//  P0
//
//  Created by Eric Goodwin on 2/3/19.
//  Copyright © 2019 umsl. All rights reserved.
//

#include <iostream>
#include <string>

using namespace std;

int main(int argc, const char * argv[]) {
    
    //keyboard input or redirection
    switch (argc)
    {
    //keyboard input or redirection input
        case 1:
            cout << "Keyboard or redirection";
            break;
    //file input
        case 2:
            cout << "File input";
            break;
    //improper input
        default:
            cout << "Error";
            break;
    }
    
    return 0;
}
