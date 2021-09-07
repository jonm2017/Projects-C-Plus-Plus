
/********************************************************************************************
Name: Jonathan Masino											Z#: Z23510843
Course: Date Structures and Algorithm Analysis (COP3530)		Professor: Dr. Lofton Bullard
Due Date: 3/25/2021												Due Time: 11:59 PM
Total Points: 100												Assignment 6: recursive_functions
Description: This assignment is an introduction to recursive functions. The user will enter a string and a boolean
			 recursive function is called to check if the entered string is a palindrome. If it is, true is returned.
			 If it is not, false is returned. A recursive function is then called to reverse the order of the string, 
			 which is then printed to the screen. Finally, a normal function is called to reverse the order of the
			 string, which is then printed onto the screen.
*********************************************************************************************/

#include <iostream>
#include <string>
using namespace std;

string temp = ""; //global variable

/*
Name: palindrome
Precondition: a string is passed
Postcondition: either true or false is returned
Description: This is a recursive function to check to see if a string is a palindrome. The function checks
			 if the first and last element of the string are the same. If they are, the function is called
			 again with a substring starting at the next element and ending at the element before the last
			 one. This process continues until there are two or less elements in the substring. If all goes
			 well, true will be returned. If at any point the first and last elements do not equal eachother, 
			 false is returned.
*/
bool palindrome(const string& s)
{
	int length = s.length(); //string length
	char beginning = s[0]; //first element
	char end = s[0]; //last element
	if (length > 1)
	{
		end = s[length-1]; //end is last element in the string
	}
	if (beginning == end && length <= 2) //elements are equal and length <= 2
	{
		return true;
	}
	else if (beginning != end) //not the same
	{
		return false;
	}
	else
	{
		return palindrome(s.substr(1, s.size() - 2)); //call function with substring of next element and previous of the last element
	}
};

/*
Name: print reverse l
Precondition: a string is passed
Postcondition: the reverse of the string is returned
Desctiption: This function will add the last element in the string to temp. While length does not equal 0,
			 the function is called again but the last element in the substring is removed. Temp is then returned.
*/
string printReversel(const string& s)
{
	int len = (s.length() - 1); //string length - 1
	if (s.length() != 0) //length is not 0
	{
		temp += s[len]; //add last element to temp
		return printReversel(s.substr(0, (s.length() - 1))); //call function with substring minus last element
	}
	else
	{
		return temp;
	}
};

/*
Name: print Iter Reverse
Precondition: a string is passed
Postcondition: the string is returned in reverse order
Desctiption: This function will iterate a string and add each element to t in reverse order. t is then returned. 
*/
string printIterReverse(const string& s)
{
	string t = "";
	for (int i = (s.length() - 1); i >= 0; i--) //i is last element and greater or equal to 0
	{
		t += s[i]; //add elements in reverse
	}
	return t;
};

int main()
{
	string s = "";
	string response = "y";
	while (response == "y" || response == "Y")
	{
		temp = "";
		cout << endl << "please enter string: ";
		getline(cin, s);
		if (palindrome(s) == true)
		{
			cout << s << " is a palindrome \n";
		}
		else
		{
			cout << s << " is a not palindrome \n";
		}
		cout << "The Rec-reverse of \"" << s << "\" is \"" << printReversel(s) << "\"" << endl;
		cout << "The Iter-reverse of \"" << s << "\" is \"" << printIterReverse(s) << "\"" << endl;
		cout << endl << "Do you wish to continue? (y or Y for yes; n or N for no) ";
		cin >> response;
		cin.ignore();
	}
	return 0;
}