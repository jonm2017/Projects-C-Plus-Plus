
/********************************************************************************************
Name: Jonathan Masino											Z#: Z23510843
Course: Date Structures and Algorithm Analysis (COP3530)		Professor: Dr. Lofton Bullard
Due Date: 4/18/2021												Due Time: 11:59 PM
Total Points: 100												Assignment 6: bst
Description: This assignment uses a binary search tree (bst). We have many functions to allow us to use create the
			 tree, add from the tree, delete from the tree, print the tree, and delete the tree. We have a text file
			 where we get the county names and populations from. We also have another text file that we can print to.
			 The default creates the list and pulls counties from the text file, the destructor deleted the tree,
			 insert adds nodes to the list, del_name deleted nodes from the list, search_tree returns a pointer to a
			 specific node, inorder_succ returns a pointer to the inorder successor, county_ranges will print the
			 counties that fall in a range, print_tree will print the tree to the screen, sorted_info prints the tree
			 in a sorted fashion to a text file, empty_tree is the same as the destructor,
*********************************************************************************************/

#include <iostream>
#include <fstream>
#include <string>
#include "bst.h"
using namespace std;
int main( )
{
	cout << "**************************************************************" << endl;
	cout << "Test1: default constuctor" << endl;
	bst myTree;
	cout << "Print contents of bst inorder to the screen" << endl << endl;
	myTree.print_tree();
	cout << "*************End Test1*****************************************" << endl;
	cout<<endl<<endl;
	cout << "**************************************************************" << endl;
	cout << "Test2: insert" << endl;
	myTree.insert("New County", 234658);
	cout <<endl<< "Print contents of bst inorder to the screen" << endl << endl;
	myTree.print_tree();
	cout << "*************End Test2*****************************************" << endl;
	cout << endl << endl;
	cout << "**************************************************************" << endl;
	cout << "Test3: county_ranges" << endl;
	cout << "Print contents of bst range between B and K inorder to the screen" << endl << endl;
	myTree.county_ranges("B","K");
	cout << "*************End Test3*****************************************" << endl;
	cout << endl << endl;
	cout << "**************************************************************" << endl;
	cout<<"Test4: del_name"<<endl;
	myTree.del_name("Miami Dade");
	cout << endl << "Print contents of bst inorder, with Miami Dade removed, to the screen" << endl << endl;
	myTree.print_tree();
	cout << "*************End Test4*****************************************" << endl;
	cout << endl << endl;
	cout << "**************************************************************" << endl;
	cout<<"Test5: sorted_info"<<endl<<endl;
	cout << "Print contents of bst inorder to the output file, county_info.txt, with nameand associated population size shown" << endl << endl;
	myTree.sorted_info();
	cout << " * ************End Test5 * ****************************************" << endl;
	cout << endl << endl;
	cout << " * *************************************************************" << endl;
	cout << "Test6: empty_tree" << endl << endl;
	myTree.empty_tree();
	cout << endl << "Print contents of an empty bst to the screen" << endl << endl;
	myTree.print_tree();
	cout << " * ************End Test6 * ****************************************" << endl;
	cout << endl << endl;
	return 0;
}