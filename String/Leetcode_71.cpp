#include<iostream>
#include<stack>
#include<string>
using namespace std;

string simplifyPath(string path){

    stack<string> st;
    string temp = "";

    for(int i = 0; i <= path.size(); i++){

        // reached '/' or end of string
        if(i == path.size() || path[i] == '/'){

            // go to parent directory
            if(temp == ".."){
                if(!st.empty()){
                    st.pop();
                }
            }

            // push valid directory name
            else if(temp != "" && temp != "."){
                st.push(temp);
            }

            // reset for next folder name
            temp = "";
        }
        else{
            temp += path[i];
        }
    }

    // build final path
    string ans = "";

    while(!st.empty()){
        ans = "/" + st.top() + ans;
        st.pop();
    }

    return ans == "" ? "/" : ans;
}

int main(){

    string path = "/home//foo/../bar/";

    cout << simplifyPath(path) << endl;

    return 0;
}