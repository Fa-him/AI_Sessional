# include <bits/stdc++.h>
using namespace std;

struct Node{
    int value;
    bool isMax;

    Node* left;
    Node* right;
};


int minimax(Node* node)
{
    if (node->left == NULL && node->right==NULL)
        return node->value;

    int leftVal= minimax(node->left);
    int rightVal= minimax(node->right);

    if(node->isMax)
        node->value=max(leftVal, rightVal);
    else
        node->value=min(leftVal, rightVal);

    return node->value;
}


int main()
{
    Node* n= NULL;

    Node L1= {-1, false, n, n};
    Node L2= {8, false, n, n};
    Node L3= {-3, false, n, n};
    Node L4= {-1, false, n, n};
    Node L5= {2, false, n, n};
    Node L6= {1, false, n, n};
    Node L7= {-3, false, n, n};
    Node L8= {4, false, n, n};


    Node D= {0, true, &L1, &L2};
    Node E= {0, true, &L3, &L4};
    Node F= {0, true, &L5, &L6};
    Node G= {0, true, &L7, &L8};

    Node B= {0, false, &D, &E};
    Node C= {0, false, &F, &G};

    Node A= {0, true, &B, &C};

    int utility= minimax(&A);

    cout<< "Utility = "<<utility<<endl;

    cout<< "Path: A-> ";

    if (A.value==B.value)
    {
        cout<< "B->";
        if (B.value==D.value)
            cout<<"D-> "<<D.value<<endl;
        else
            cout<<"E-> "<<E.value<<endl;
    }
    else
    {
        cout<<"C-> ";
        if (C.value==F.value)
            cout<<"F-> "<<F.value<<endl;
        else
            cout<<"G-> "<<G.value<<endl;
    }

    return 0;

}
