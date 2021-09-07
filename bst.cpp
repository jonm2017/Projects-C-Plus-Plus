
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

/*
Name: Default
Preconsition: a bst is created
Postcondition: county names and their populations are added to the tree
Description: This function reads a list of county names and their populations from a text file and inserts them
			 a bst.
*/
bst::bst()
{
	cout << "Inside default constructor" << endl;
	root = 0;
	ifstream in;
	int x = 0;
	int limit = 0;
	string input = "";
	in.open("county_data.txt");
	if (in.fail()) //fails to open
	{
		cout << "\nFile did not open correctly.\n";
	}
	else
	{
		cout << "File opened correctly" << endl;
	}

	while (!in.eof())
	{
		getline(in, input, '\n');
		limit = (int)input.length();
		x = limit;
		while (x > 1)
		{
			if (input[x] == ' ')
			{
				insert(input.substr(0, x), stoi(input.substr(x, limit)));
				x = 0;
			}
			x--;
		}
	}
	in.close();
}

/*
Name: empty
Preconsition: a bst is checked to be empty
Postcondition: true or false is returned
Description: if the bst is empty, true is returned, otherwise false is returned
*/
bool bst::empty()
{
	return (root == 0);
}

/*
Name: insert
Precondition: main called
Postcondition: insert called
Description: aux function
*/
void bst::insert(const string &item, const double &population)
{
	insert(root, item, population);
}

/*
Name: insert
Precondition: a node is to be added
Postcondition: node is added
Description: this function will add nodes to the bst
*/
void bst::insert(treenode*& local_ptr, const string& item, const double& population)
{
	if (local_ptr == 0)
	{
		local_ptr = new treenode;
		local_ptr->lchild = local_ptr->rchild = 0;
		local_ptr->county_name = item;
		local_ptr->population_size = population;
	}
	else if (local_ptr->county_name > item)
		insert(local_ptr->lchild, item, population);
	else if (local_ptr->county_name < item)
		insert(local_ptr->rchild, item, population);
	else
		cout << "the item is already in the tree\n";
}

/*
Name: search_tree
Preconsition: called from main
Postcondition: search_tree is called
Description: aux function
*/
treenode* bst::search_tree(string item)
{
	return search_tree(root, item);
}

/*
Name: search_tree
Preconsition: a bst exists
Postcondition: a pointer is returned
Description: this function will search the tree and return the node matching the given county name
*/
treenode* bst::search_tree(treenode* loc_ptr, string item)
{
	if (loc_ptr != 0)
	{
		if (loc_ptr->county_name == item)
			return loc_ptr;
		else if (loc_ptr->county_name > item)
			return search_tree(loc_ptr->lchild, item);
		else
			return search_tree(loc_ptr->rchild, item);
	}
	else
		return loc_ptr;
}

/*
Name: del_name
Preconsition: called from main
Postcondition: del_name is called
Description: aux function
*/
void bst::del_name(string item)
{
	del_name(root, item);
}

/*
Name: del_name
Preconsition: a node is to be deleted
Postcondition: node is deleted
Description: a given node is deleted from the bst
*/
void bst::del_name(treenode*& loc_ptr, string item)
{

	if (loc_ptr == 0)
		cout << "item not in tree\n";

	else if (loc_ptr->county_name > item)
		del_name(loc_ptr->lchild, item);

	else if (loc_ptr->county_name < item)
		del_name(loc_ptr->rchild, item);

	else
	{
		treenode* ptr;
		if (loc_ptr->lchild == 0)
		{
			ptr = loc_ptr->rchild;
			delete loc_ptr;
			loc_ptr = ptr;
		}
		else if (loc_ptr->rchild == 0)
		{
			ptr = loc_ptr->lchild;
			delete loc_ptr;
			loc_ptr = ptr;
		}
		else
		{
			ptr = inorder_succ(loc_ptr);
			loc_ptr->county_name = ptr->county_name;
			del_name(loc_ptr->rchild, ptr->county_name);
		}
	}
}

/*
Name: inorder_succ
Preconsition: nodes are added to the bst
Postcondition: pointer is returned
Description: returns a pointer to the inorder successor, based on county name
*/
treenode* bst::inorder_succ(treenode* loc_ptr)
{
	treenode* ptr = loc_ptr->rchild;
	while (ptr->lchild != 0)
	{
		ptr = ptr->lchild;
	}
	return ptr;
}

/*
Name: print_tree
Preconsition: called from main
Postcondition: print_tree is called
Description: aux function
*/
void bst::print_tree()
{
	print_tree(root);
}

/*
Name: print_tree
Preconsition: a bst exists
Postcondition: bst printed to the screen
Description: this function traverses the bst and prints the nodes to the screen
*/
void bst::print_tree(treenode*& loc_ptr)
{
	if (loc_ptr != 0)
	{
		print_tree(loc_ptr->lchild);
		cout << loc_ptr->county_name << " " << loc_ptr->population_size << endl;
		print_tree(loc_ptr->rchild);
	}
}

/*
Name: destructor
Preconsition: main loop ends
Postcondition: nodes are deleted
Description: this function is called at the end of the main loop and will delete and deallocate every node
*/
bst::~bst()
{
	cout << "Inside destructor" << endl;
	while (root != 0)
	{
		del_name(root->county_name);
	}
}

/*
Name: county_ranges
Preconsition: county_ranges called from main
Postcondition: county_ranges is called
Description: aux function
*/
void bst::county_ranges(const string& min_name, const string& max_name)
{
	county_ranges(root, min_name, max_name);
}

/*
Name: county_ranges
Preconsition: a range is counties are to be printed
Postcondition: the counties inside the range are printed to the screen
Description: this function tarverses the bst and prints only counties whose name fall in the range.
*/
void bst::county_ranges(treenode*& loc_ptr, const string& min_name, const string& max_name)
{
	if (loc_ptr != 0)
	{
		county_ranges(loc_ptr->lchild, min_name, max_name);
		if ((loc_ptr->county_name >= min_name) && (loc_ptr->county_name <= max_name))
		{
			cout << loc_ptr->county_name << " " << loc_ptr->population_size << endl;
		}
		county_ranges(loc_ptr->rchild, min_name, max_name);
	}
}

/*
Name: sorted_info
Preconsition: sorted_info is called from main 
Postcondition: sorted_info is called
Description: aux function
*/
void bst::sorted_info()
{
	ofstream out;
	sorted_info(out, root);
}

/*
Name: sorted_info
Preconsition: a bst exists and is to be printed
Postcondition: the list is printed to a text file in order
Description: this function will print the nodes of the tree to an outfile in sorted order
*/
void bst::sorted_info(ofstream& out, treenode*& cur_node)
{
	out.setf(ios::fixed);
	out.precision(0);
	if (cur_node != 0)
	{
		sorted_info(out, cur_node->lchild);
		out.open("county_info.txt", ios::app);
		out << cur_node->county_name << " " << cur_node->population_size << endl;
		out.close();
		sorted_info(out, cur_node->rchild);
	}
}

/*
Name: empty tree
Preconsition: nodes are to be removed
Postcondition: memory for those nodes is deallocated
Description: this function deletes the nodes from a bst and deallocates the memory used by those nodes.
*/
void bst::empty_tree()
{
	while (root != 0)
	{
		del_name(root->county_name);
	}
}