#include<bits/stdc++.h>
using namespace std;
struct node
{
    int data;
    node *left;
    node *right;
};

node *tree=NULL;

node* insert(node *tree,int ele){
    if(tree==NULL){
            tree=new node;
            tree->left = tree->right=NULL;
            tree->data = ele;
            cont++;
    }
    else{
        if(ele == tree->data){

        }
        else if(ele < tree->data){
            tree->left = insert(tree->left,ele);
        }
        else{
            tree->right = insert(tree->right,ele);
        }
    }
        return(tree);
}

void preorder(node *tree){
    if(tree!=NULL){
        cout << tree->data;
        preorder(tree->left);
        preorder(tree->right);
    }
}
void inorder(node *tree){
    if(tree!=NULL){
        inorder(tree->left);
        cout<<tree->data;
        inorder(tree->right);
        }
}

void postorder(node *tree){
    if(tree!=NULL){
        postorder(tree->left);
        postorder(tree->right);
        cout<<tree->data;
    }
}


int cont=1;

int main(){

    int ch,ele;
    string ch
    do{
        cin>>ch;
        switch(ch){
            case 1:
                cin>>ele;
                tree=insert(tree,ele);
                break;
            case 2:
                preorder(tree);
                break;
            case 3:
                inorder(tree);
                break;
            case 4:
                postorder(tree);
                break;
            case 5:
                exit(0);
            }
        }while(ch!=5);
    return 0;
}

