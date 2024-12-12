   //infix to prefix
    #include <iostream>
#include <algorithm>

using namespace std;

class Node{
    public :
    char data;
    Node* next;


    Node(int val){
        data = val;
        // next =  NULL;
    }
};
//stack class
class stack1{
    Node* head;

    public:
    stack1(){
        head = NULL;
    }

    void push(char val){
        //push-front
         Node* newNode = new Node(val);
       if( head == NULL){
        head = newNode;
         }else{
            newNode->next = head;
            head = newNode;
         }
  
    }
    void pop(){
        //pop_front
      Node* temp = head;

      head = temp->next;
    // temp->next = head; //not correct logic
      temp ->next =NULL;
      delete temp;
    }


    char top (){
   return head->data;
    }
    
    bool isEmpty(){
        return head == NULL;
    }
};





int check_prec(char c){
   if(c == '^'){
    return 3;
   }
   else if(c == '*' || c == '/'){
    return 2;
   }
   else if(c == '+' || c == '-'){
    return 1;
   }else {
    return -1;
   }
}

  string infix_to_postfix (string s){
    stack1 st;
    string res;

    for (int i=0; i<s.length(); i++){ //iterate on the string that we are passing

        if(s[i]>= 'a' && s[i]<= 'z' || s[i] >= 'A' && s[i] <= 'Z'){ //1.checking for the operator
            res += s[i];
        }
        else if(s[i] == '('){ //2.checking for the opening parenthethisis
            st.push(s[i]);
        }
        else if(s[i] == ')'){  //3.checking for the closing bracket
            while(!st.isEmpty() && st.top() != '('){
                res += st.top();
                st.pop();
            }
            if(!st.isEmpty()){
                st.pop();  //for poping the opening parenthethisis
            }
        }
        else { //4.checking for the operator
            while(!st.isEmpty() && check_prec(st.top()) >= check_prec(s[i])){
                res += st.top();
                st.pop();
            }
            st.push(s[i]);
        }
    }  //for loop ends here 
    while(!st.isEmpty()){  //while loop for checking that stack is non empty
        res += st.top();
        st.pop();
    }

    return res;
    }

 
// Function to check the precedence of operators
int check_prec(char c){
   if(c == '^'){
       return 3;
   }
   else if(c == '*' || c == '/'){
       return 2;
   }
   else if(c == '+' || c == '-'){
       return 1;
   }else {
       return -1;
   }
}

// Function to convert infix to prefix
string infix_to_prefix(string s) {
    // Reverse the infix expression
    reverse(s.begin(), s.end());

    // Replace '(' with ')' and vice versa
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == '(') {
            s[i] = ')';
        }
        else if (s[i] == ')') {
            s[i] = '(';
        }
    }

    stack1 st;
    string res;

    // Loop through the reversed string
    for (int i = 0; i < s.length(); i++) {
        // If character is an operand, add it to the result
        if (s[i] >= 'a' && s[i] <= 'z' || s[i] >= 'A' && s[i] <= 'Z') {
            res += s[i];
        }
        // If character is '(', push it to the stack
        else if (s[i] == '(') {
            st.push(s[i]);
        }
        // If character is ')', pop from the stack until '(' is encountered
        else if (s[i] == ')') {
            while (!st.isEmpty() && st.top() != '(') {
                res += st.top();
                st.pop();
            }
            st.pop();  // Remove the '(' from the stack
        }
        // If an operator is encountered
        else {
            while (!st.isEmpty() && check_prec(st.top()) >= check_prec(s[i])) {
                res += st.top();
                st.pop();
            }
            st.push(s[i]);
        }
    }

    // Pop all the remaining operators from the stack
    while (!st.isEmpty()) {
        res += st.top();
        st.pop();
    }

    // Reverse the result to get the final prefix expression
    reverse(res.begin(), res.end());

    return res;
}

int main() {
    string infix = "(a-b/c)*(a/k-l)";
    cout << "Prefix: " << infix_to_prefix(infix) << endl;
     cout<< infix_to_postfix("(a-b/c)*(a/k-l)");
    return 0;
}


