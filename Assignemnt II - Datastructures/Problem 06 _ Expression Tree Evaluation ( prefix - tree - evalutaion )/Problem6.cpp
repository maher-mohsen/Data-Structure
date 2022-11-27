#include <stdlib.h>
#include<stack>
#include <iostream>
#include<vector>
#include<cmath>
#include<cctype>
#include<string>
#include <algorithm>
using namespace std;
#define COUNT 10
//Class TreeNode
class TreeNode{
  public:
  string data;
  TreeNode* left;
  TreeNode* right;
  TreeNode(string x){
    data =x;
    left=nullptr;
    right=nullptr;
    }
 

};
/*Pre: takes a char
  Post: return if it operator or not*/
bool isOperator(char x){ 
    switch(x){ 
      case '+': 
      case '-': 
      case '/': 
      case '*': 
      case '^': 
        return true; 
    } 
  return false; 
} 
/*Pre: takes a 2 vectors (pre & in ) to build Tree
  Post: build a tree and return the root pointer*/
  TreeNode* buildTreeAux(int preS,int inS,int inE ,vector<string> preorder,vector<string> inorder){
    if(preS > preorder.size() - 1 || inE > inE || inS > inE) return nullptr;
    TreeNode *root = new TreeNode(preorder[preS]);
    
    int inI = 0;
    for(int i = inS; i <= inE; i++){
      if(root->data == inorder[i]){
        inI = i;
        break;
      }
    }
    root->left = buildTreeAux(preS+1,inS,inI-1,preorder,inorder);
    root->right = buildTreeAux(preS+inI-inS+1,inI+1,inE,preorder,inorder);
    return root;
}
/*Pre: takes a 2 vectors (pre & in ) to build Tree
  Post: Aux function to callbuild Auxlary*/
TreeNode* buildTree(int preS,int inS,int inE ,vector<string> preorder,vector<string> inorder){
  return buildTreeAux(0,0,inorder.size(),preorder,inorder);
}
/*Pre: takes root pointer
  Post: traverse tree preorder  V L R */
void preRec(TreeNode *root){
  if(root!=nullptr){
  cout<<root->data<<' ';
  preRec(root->left);
  preRec(root->right);
  }
  
}

/*Pre: takes prefix expression
  Post: return the infix of expression*/
string prefixToInfix(string prefix_exp) { 
  stack<string> s; 
  
  int l = prefix_exp.size(); 
  string tmp = "";
  for(int i = l-1; i >= 0; i--){ 
  if(prefix_exp[i] != ' ' && isdigit(prefix_exp[i])){
    tmp += prefix_exp[i];
  } 
    else if(isOperator(prefix_exp[i])){ 
      string op1 = s.top()+' ';   
      s.pop(); 
      string op2 = ' '+s.top();   
      s.pop(); 
      string temp =  op1 + prefix_exp[i] + op2 ; 
      s.push(temp); 
    } 
    else{ 
      if(tmp != ""){
        reverse(tmp.begin(), tmp.end());
        s.push(tmp); 
      }
      
      tmp = "";
    } 
  } 
  
  return s.top(); 
} 
/*Pre: takess pointer to Tree
  Post: return the evaluation of espression (Helper function)*/
double eval(TreeNode *root){
  if(!root) return 0;
  if(!root->left&&!root->right) return stod(root->data);
  double l = eval(root->left);
  double r = eval(root->right);
  if(root->data=="+") return l+r;
  if(root->data=="-") return l-r;
  if(root->data=="*") return l*r;
  if(root->data=="/") return l/r;
  if(root->data=="^") return pow(l,r);
}
/*Pre: takess pointer to Tree
  Post: return the evaluation of espression*/
  double expressionTreeEvaluation(string x){
    string y= prefixToInfix(x);
    vector<string> fx;
    vector<string> fy;
    string tmp="";
    for(int i=0;i<x.size();i++){
       if(x[i]!=' '){
          tmp+=x[i];
       }
       else if(x[i]==' '){
          fx.push_back(tmp);
          tmp="";
       }
    }
    if(tmp!=""){
       fx.push_back(tmp);
    }
    tmp="";
   for(int i=0;i<y.size();i++){
    
       if(y[i]!=' '){
          tmp+=y[i];
       }
       else if(y[i]==' '){
          fy.push_back(tmp);
          tmp="";
       }
    }
    if(tmp!=""){
       fy.push_back(tmp);
    }
    TreeNode* root=buildTree(0,0,fx.size(),fx,fy);
    //preRec(root);
    cout<<eval(root);
  }
int main() {
   
   /*Test 1 : */string x= "+ 3 * 4 / 8 2";
      expressionTreeEvaluation(x);
      cout<<endl;

   /*Test 2 : */string y= "- 9 * 3 + 2 / 50 2";
   expressionTreeEvaluation(y);
   cout<<endl;
   /*Test 3 : */string v= "* 9 * 3 * 2 * 50 2";
      expressionTreeEvaluation(v);
      cout<<endl;
   /*Test 4 : */string h= "+ 9 + 3 + 2 + 50 2";
      expressionTreeEvaluation(h);
      cout<<endl;
   /*Test 5 : */string g= "/ 100 / 100 / 100 / 100 100";
      expressionTreeEvaluation(g);
      cout<<endl;

    /*Test 5 : */string m= "+ 2 + 2 + 2 ^ 2 3";
      expressionTreeEvaluation(m);
      cout<<endl;
  return 0;
}