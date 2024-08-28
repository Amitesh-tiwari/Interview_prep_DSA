Given a text file file.txt that contains a list of phone 
numbers (one per line), write a one-liner bash script 
to print all valid phone numbers.

You may assume that a valid phone number must appear 
in one of the following two formats: (xxx) xxx-xxxx 
or xxx-xxx-xxxx. (x means a digit)

You may also assume each line in the text file must not 
contain leading or trailing white spaces.

Example:

Assume that file.txt has the following content:

987-123-4567
123 456 7890
(123) 456-7890
Your script should output the following valid phone 
numbers:

987-123-4567
(123) 456-7890

//code

// C++ program to check if given mobile number
// is valid.
#include <iostream>
#include <regex>
using namespace std;

bool isValid(string s)
{
	// The given argument to pattern()
	// is regular expression. With the help of
	// regular expression we can validate mobile
	// number.
	// 1) Begins with 0 or 91
	// 2) Then contains 6,7 or 8 or 9.
	// 3) Then contains 9 digits
const regex pattern("(0|91)?[6-9][0-9]{9}");

// regex_match() is used to
// to find match between given number
// and regular expression
if(regex_match(s, pattern))
{
	return true;
}
else
{
	return false;
}
}

// Driver Code
int main()
{
string s = "347873923408";
if(isValid(s))
{
	cout << "Valid";
}
else
{
	cout<<"Invalid";
}
return 0;
}


