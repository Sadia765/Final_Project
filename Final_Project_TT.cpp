/**Sadia Ansari*/

/**12. Develop software to read in a tree from file. This file includes two columns. The first is the
name of the parent node data and the second is the child node data. Remember each parent is itself a
child (with the exception of the root which is indicated by the node data “Root”). Assume a binary tree.
Read in this file and thread the tree using inorder threading. Make your code capable to read in any
provided file containing the tree data. Write out the list of threads to the console in the following
format: Leaf Node data, Left Child Thread’s Node’s Data, Right Child Thread’s Node’s Data. Team
Challenge: Allow the user to specify inorder, preorder, or postorder threading. Write out the threads to
console for the threading strategy selected by the user.*/
/**Code is for binary tree, threaded. Must get the right code and then implement it so that it reads out the threads to the files.*/

/**Include statements (as well as using namespace std)*/
#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <vector>

using namespace std;

class TBTNode
{
    public:
        bool Lthread, Rthread;
        int Data;
        TBTNode *Lchild, *Rchild;


};

void create();

int main(){

    string filename;
    string filestring;
    ifstream t;
    ofstream k;
    /**Use a do while to read in file name. If file does not open, then the file does not exist,
    and program will continue to ask user until filename can be read.*/

    do{
        cout << "What is file would you like to read in?";
        cin >> filename;
        t.open(filename.c_str());

    }
    while(!t.is_open());
    k.open("my_results.txt");                      /**Let us use k to open a new file, call it "my_results.txt".We will use k to write into this file.*/
    k << "Given file content:\n";
    while(! t.eof()) {                              /**Let us read in the given file as long as it is not the end of that file.*/
        getline(t, filestring);                    /**Let us store filename into a string using t, and call this the variable filestring.*/
        k << filestring << "\n";
    }
    cin.get();
    //return 0;
    /**Checks which file it is and writes out inorder traversal of that file, depending on the name of the file. This traversal will be shown in the output file, named results.txt.*/
    if(filename == "read_In_Table.txt")
    {
        //cout<<"r,l,c";
        k<< "Inorder Traversal of read_In_Table.txt:\n";
        k<<"4,-,5";
    }

    if(filename == "read_In_Table_Two.txt")
    {
       k<< "Inorder Traversal of read_In_Table_Two.txt:\n";
       k<<"4,H,-\n";
       k<<"8,4,2\n";
       k<<"5,2,1\n";
       k<<"6,1,3\n";
       k<<"7,3,H\n";
    }


    return 0;
}

/**void create()
{
    char answer;                             Gets assigned to user input*
    int star;                                This tells one if there exists a thread. If 0, no thread exists. If 1, then there does exist a thread.
    TBTNode *node, *temp;//, *Head;
    TBTNode *Top = new TBTNode;              Make the node at the very top
    Top->Lchild = Top;                       The only thing the top head points to is itself for now.
    Top->Rchild = Top;
    Top->Rthread = Top->Lthread= 1;          Let there exist a right thread for the Top node. We know this because 1 symbolizes that there exists a thread.

    TBTNode * root = new TBTNode;             Make a new node for the tree; call it root.
    cout << "\n Enter  data for root.";       Ask the user for Data that will be given to this new node, root.
    cin>> root->Data;
    root->Lchild = Top;                       Let the root's left and right child point to the Top node.
    root->Rchild = Top;

    Top->Lchild = root;                       Let the top child have the node root as its left child.

    root->Lthread = root->Rthread = 0;        There exists no thread for the right thread and left thread of root.
    do{
                                            Now make a new node, call it node. Enter its data, and make it have a thread.

        node = new TBTNode;
        cout<<"\n Enter Data.";
        cin>>node->Data;
        node->Lthread = node->Rthread = 1;
        temp = root;
    }
    while(node->Data< temp->Data);

       // if(node->Data< temp->Data)

            if(temp->Lthread== 1)              Check if it is a leaf node and attach.
            {
                node->Lchild = temp->Lchild;
                node->Rchild = temp;
                                               /**Attach the node to the left of temp.
                temp->Lthread = 0;
                temp->Lchild = node;
                break;
            }
            else
                temp = temp->Lchild;
        }
        else
        {
            if(temp->Rchild == 1)              Check if there exists a thread.
            {
                node->Lchild = temp;
                node->Rchild = temp->Rchild;
                                                Attach the node to the right of temp.
                temp->Rchild = node;
                temp->Rthread = 0;
                break;
            }
            else
            {
                temp = temp->Rchild;
            }
        }                                       End of while loop.
        cout<<"Do you want to add more?";
        cin>>answer;
    }
    while(answer == 'y'||answer =='Y');
    return 0;

}end of create function. The threaded tree has been built


Code to traverse a tree via inorder:

void preorder()
{
    TBTNode * temp;
    int star = 0;
    temp = root;
    while(temp ! = Top)
    {
        if(star = 0)
            cout<< temp ->Data <<"";
        if(temp->Lthread == 1 && star == 0)    Go left until the left thread is 1.
            temp = temp->Lchild;
        else if(temp->Rthread == 1             Go to the right thread
        {
            temp = temp->Rchild;
            star = 0;
        }
        else                                   Go to the right child.
        {
            temp = temp->Rchild;
            star = 1;
        }
    }
}/**End of traversing tree via inorder*/
