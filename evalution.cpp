#include<iostream>
#include <bits/stdc++.h>
using namespace std;

// infix to postfix

struct stack1{
    int data;
    stack1* next;
    stack1* top;

    stack1(int data1){
        data = data1;
        next = top = nullptr;
    }
    stack1(){
        top = nullptr;
    }
    void push(int val){
        stack1* node = new stack1();
        node->data = val;
        node->next = top;
        top = node;
    }
    char pop(){
        int x = top->data;
        stack1* node = top;
        top = top->next;
        delete node;
        return x;
    }
    char Top(){
        return top->data;
    }
    bool isEmpty(){
        return top ==nullptr;
    }
};

int prec(char c){
    if(c=='^')
    return 3;

    else if(c=='*' || c=='/')
    return 2;

    else if(c=='+' || c=='-')
    return 1;

    else return -1;
}
void inToPost(string s){
    stack1 st;
    string result;
    for(int i=0; i<s.length();i++){
        char c = s[i];
        if((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z') || (c >= '0' && c <= '9')){
            result =result +c;
        }
        else if(c=='('){
            st.push('(');
        }
        else if(c==')'){
            while(st.Top()!='('){
                result = result + st.Top();
                st.pop();
            }
            st.pop();
        }
        else{
            while(!st.isEmpty() && prec(c)<=prec(st.Top())){
                result = result + st.Top();
                st.pop();
            }
            st.push(c);
        }
}
while (!st.isEmpty() ){
            result += st.Top();
            st.pop();
        }
    cout<<"Postfix is : "<<result<<endl;
};
void inToprefix(string s){
    stack1 st;
    string result;
    reverse(s.begin(),s.end());
    for(int i=0; i<s.length(); i++){
        if(s[i]=='('){
            s[i]=')';
        }
        else if(s[i]==')'){
            s[i]='(';
        }
    }
    for(int i=0; i<s.length();i++){
        char c = s[i];
        if((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z') || (c >= '0' && c <= '9')){
            result =result +c;
        }
        else if(c=='('){
            st.push('(');
        }
        else if(c==')'){
            while(st.Top()!='('){
                result = result + st.Top();
                st.pop();
            }
            st.pop();
        }
        else{
            while(!st.isEmpty() && prec(c)<=prec(st.Top())){
                result = result + st.Top();
                st.pop();
            }
            st.push(c);
        }
}
while (!st.isEmpty() ){
            result += st.Top();
            st.pop();
        }
    reverse(result.begin(),result.end());
    cout<<"prefix is : "<<result<<endl;
};
void evaluate(string s){
    stack1 st;
    for(int i=0; i<s.length();i++){
        int c = s[i];
        if((c >= '0' && c <= '9')){
            st.push(c - '0');
        }
        if(c=='+'){
            int y = st.pop();
            int x = st.pop();
            st.push(x+y);
        }
        if(c=='-'){
            int y = st.pop();
            int x = st.pop();
            st.push(x-y);
        }if(c=='*'){
            int y = st.pop();
            int x = st.pop();
            st.push(x*y);
        }if(c=='/'){
            int y = st.pop();
            int x = st.pop();
            st.push(x/y);
        }
    }
    int res = st.pop();
    cout<<"result is : "<<res<<endl;
}
int main(){
    string exp = "(x+y)*(p+q)";
    string exp1 = "12+34+*";
    inToPost(exp);
    inToprefix(exp);
    evaluate(exp1);
    return 0;
}