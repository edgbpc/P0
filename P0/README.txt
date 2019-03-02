
Write a program to build a tree and print it using different traversals. The program will be invoked as
P0 [file] where file is an optional argument. - DONE

If the file argument is not given the program reads data from the keyboard as a device (10%) up to end  of the file. - DONE

If the argument is given, the program reads data file file.sp19. (note that file is any basename and the extension is implicit). - DONE

P0 // read from the keyboard until simulated EOF - DONE - CTRL-D TERMINATES KEYBOARD INPUT.  RETURN CREATES NEW LINE

P0 < somefile // same as above except redirecting from somefile instead of keyboard, testing keyboard input - DONE

P0 somefile  // read from somefile.sp19 - DONE

If the input file is not readable for whatever reason, or command line arguments are not correct, the program will abort with an appropriate message - DONE

The program will read the data left to right and put them into a tree, which is a binary search tree (BST) with respect to the length of the string (that is strings of the length are considered the same data) - DONE

Tree is never balanced nor restructured other than growing new nodes
A node should contain all data that falls into the node except that literally the same strings will show up only once (set) - DONE
The program will subsequently output 3 files corresponding to the 3 traversals, named file.preorder, file.inorder and file.postorder. Note that file is the basename of the input file if given, and it is 'out' if the input is from the keyboard. - DONE
Treversals - DONE
preorder - DONE
inorder - DONE
postoder - DONE
Printing in traversal
a node will print, intended by 2 x depth of the node, the string length followed by list of strings from the node without repetitions - DONE


Standards related requirements:
Have the following functions minimum in addition to the main function (the types and arguments are up to you, the names are required) - DONE.  THESE FUNCTIONS MADE PART OF THE TREE CLASS.
buildTree() - DONE
printInorder() - DONE
printPreorder() - DONE
printPostorder() - DONE
Put the above four functions into file tree.c/tree.h - DONE
Keep the main function separate - DONE


i
Ideas for printing tree with indentations

static void printPreorder(nodeType *rootP,int level) {
if (rootP==NULL) return;
printf("%*c%d:%-9s ",level*2,' ',level,NodeId.info); // assume some info printed as string
printf("\n");
printPreorder(rootP->child1,level+1);
printPreorder(rootP->child2,level+1);
}

Testing

Create test files:
P0_test1.sp19 containing empty file - DONE.  FILES STILL CREATED BUT EMPTY
P0_test2.sp19 containing one string: adam - DONE.  FILES CREATED.  ALL THE SAME
P0_test3.sp19 containing some strings with same length (some repeats) and different length over multiple lines
adam ala - DONE.
susan adams adam jo yu up jo adamz suzan susan - DONE
if no error, and what the output files should look like - using the hand drawn trees for each file
