
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

#include<iostream>
#include<string>
using namespace std;

class treenode //node in a bst 
{
public:
	string county_name;      
	double population_size;
	treenode* lchild, * rchild; //left and right children pointers 
};

class bst 
{
public:
	bst(); //store the data file (“county_data.txt”) into initial bst. 
	~bst();//de-allocates dynamic memory allocate for tree bool empty(); checks to see if the tree is empty. 
	bool empty(); //return true if bst is null; otherwise false is retured.
	void insert(const string& item, const double& population); //auxiliary function.
	void insert(treenode*&, const string& item, const double& population); //inserts an item into the bst; this function is invoked, in main, by the auxiliary function described above.
	void del_name(string item); //auxiliary function. 
	void del_name(treenode*& loc_ptr, string item); //function deletes an item from the bst; this function is invoked, in main, by the auxiliary function described above.        
	treenode* search_tree(string item); //auxiliary fucntion
	treenode* search_tree(treenode*, string item); //returns a pointer to the node in bst with a county name county name that matches item; this function is invoked, in main, by the auxiliary function describes above.
	treenode* inorder_succ(treenode*); //returns a pointer to the inorder successor, based on county name. 
	void county_ranges(const string& min_name, const string& max_name); //auxiliary function.
	void county_ranges(treenode*&, const string& min_name, const string& max_name); //prints all the county names to the screen that lie between min_name and max_name, inclusive. 
	void print_tree();//auxiliary function. 
	void print_tree(treenode*&);//prints each county record to the screen sorted by county name.
	void sorted_info();//auxiliary function.
	void sorted_info(ofstream&, treenode*&);//prints each county record to a file called “county_info.txt” sorted by county name”.
	void empty_tree();//de-allocate all nodes that were allocated to the bst
private:
	treenode* root;
};
