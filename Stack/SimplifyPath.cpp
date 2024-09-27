You are given an absolute path for a Unix-style file 
system, which always begins with a slash '/'. Your task 
is to transform this absolute path into its simplified 
canonical path.

The rules of a Unix-style file system are as follows:

A single period '.' represents the current directory.
A double period '..' represents the previous/parent 
directory.
Multiple consecutive slashes such as '//' and '///' are 
treated as a single slash '/'.
Any sequence of periods that does not match the rules 
above should be treated as a valid directory or file name.
For example, '...' and '....' are valid directory or file
names.
The simplified canonical path should follow these rules:

The path must start with a single slash '/'.
Directories within the path must be separated by exactly 
one slash '/'.
The path must not end with a slash '/', unless it is the 
root directory.
The path must not have any single or double periods 
('.' and '..') used to denote current or parent directories.
Return the simplified canonical path.

//code
class Solution {
public:
    string simplifyPath(string path) {
        // stack<string> st;: Initializes an empty stack st 
        // to store directory names.
        stack<string> st;

        // string dir;: Initializes an empty string dir to 
        // accumulate characters of a directory name.
        string dir;

        //path += '/';: Appends a trailing slash to the input 
        path += '/';

        //for(char c : path): Iterates over each character
        // c in the modified path.
        for(char c : path) {
            //if(c == '/'): Checks if the current character 
            //is a slash /, indicating the end of a directory name.
            if(c == '/') {
                //if(dir == ".."): Checks if the accumulated 
                //directory name dir is .., which means to go up one 
                //directory level.
                if(dir == "..") {
                //if(!st.empty()) { st.pop(); }: If the 
                // stack is not empty, it pops the top 
                // element, effectively going up one 
                // directory level.
                    if(!st.empty()) {
                        st.pop();
                    }
                }
                //else if(dir != "." && dir != ""): Checks 
                //if dir is not . (current directory) and not 
                //an empty string.
                else if(dir != "." && dir != "") {
                //st.push(dir);: Pushes the accumulated 
                //directory name dir onto the stack.
                    st.push(dir);
                }
                //dir = "";: Resets dir to an empty string
                // to accumulate the next directory name.
                dir = "";
            }
            else {
            //else { dir += c; }: If the current character 
            //is not a slash, it adds the character to dir.
                dir += c;
            }
        }

        //string ans = "";: Initializes an empty string 
        //ans to construct the simplified path.
        string ans = "";
        //while(!st.empty()): Iterates while the stack is not empty.
        // ans = "/" + st.top() + ans;: Prepends the top 
        //element of the stack (a directory name) to ans, 
        //adding a leading slash.
        // st.pop();: Pops the top element from the stack.

        while(!st.empty()) {
            ans = "/" + st.top() + ans;
            st.pop();
        }
        //Returns the simplified path. If ans is empty, 
        //it returns / (root directory); otherwise, it 
        //returns ans.
        return ans.empty() ? "/" : ans;
    }
};














