#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

struct node
{
    int data;
    struct node *left;
    struct node *right;
    struct node *parent;

    char color;
};
typedef struct node *node;

struct tree
{
    node root;
};
typedef struct tree *tree;
tree create_tree()
{
    tree new_tree = (tree)malloc(sizeof(struct tree));
    new_tree->root = NULL;
    return new_tree;
}

// creatw a node
node create_node(int data)
{
    node new_node = (node)malloc(sizeof(struct node));
    new_node->data = data;
    new_node->left = NULL;
    new_node->right = NULL;
    new_node->color = 'r';
    new_node->parent = NULL ;
    return new_node;
}

// left rotate
node left_rotate(node root){
    node temp=root->right;
    node temp2=temp->left;
    temp->left=root;
    root->right=temp2;
    root->parent=temp;
    if(temp2!=NULL)
        temp2->parent=root;
    return temp;
}

// right rotation no parent
node right_rotate(node root){
    node temp=root->left;
    node temp2=temp->right;
    temp->right=root;
    root->left=temp2;
    root->parent=temp;
    if(temp2!=NULL)
        temp2->parent=root;
    return temp;
}
char get_color(node root)
{
    if (!root)
        return 'b';
    return root->color;
}

node aux(node root, node x)
{
    int key = x->data;
    node y;
    if (root == NULL)
        return x;
    if (key <= root->data)
    {
        root->left = aux(root->left, x);
        root->left->parent = root;
        if (root->left->color == 'r')
        {
            if ((get_color(root->left->left) == 'r') || get_color(root->left->right) == 'r')
            {
                if (get_color(root->right) == 'b')
                {
                    if (get_color(root->left->left) == 'r')
                    {
                        y = right_rotate(root);
                        y->right->color = 'r';
                        y->color = 'b';

                        return y;
                    }
                    else
                    {
                        root->left = left_rotate(root->left);
                        y = right_rotate(root);
                        y->right->color = 'r';
                        y->color = 'b';
                        return y;
                    }
                }
                else
                {
                    root->right->color = 'b';
                    root->left->color = 'b';
                    root->color = 'r';
                }
            }
        }
    }
    else
    {
        root->right = aux(root->right, x);
        root->right->parent = root;
        if (get_color(root->right) == 'r')
        {
            if ((get_color(root->right->right) == 'r') || get_color(root->right->left) == 'r')
            {
                if (get_color(root->left) == 'b')
                {

                    if (get_color(root->right->right) == 'r')
                    {
                        y = left_rotate(root);
                        y->left->color = 'r';
                        y->color = 'b';
                        return y;
                    }
                    else
                    {
                        root->right = right_rotate(root->right);
                        y = left_rotate(root);
                        y->left->color = 'r';
                        y->color = 'b';
                        return y;
                    }
                }
                else if (get_color(root->left) == 'r')
                // else
                {
                    root->left->color = 'b';
                    root->right->color = 'b';
                    root->color = 'r';
                }
            }
        }
    }
    return root;
}

node rbinsert(node root, node x)
{
    root = aux(root, x);
    if (root->color == 'r')
    {
        root->color = 'b';
    }
    return root;
}

void print(node root)
{
    if (!root)
    {
        printf("( ) ");
        return;
    }

    printf("( ");
    printf("%d %c ", root->data, toupper(root->color));
    print(root->left);
    print(root->right);
    printf(") ");
}
// //check if there is atleast one black node at distance k from a node
int check_black(node root, int k)
{
    if (root == NULL)
        return 0;
    if (k == 0)
    {
        if (root->color == 'b')
            return 1;
        else
            return 0;
    }
    else
    {
        return check_black(root->left, k - 1) + check_black(root->right, k - 1);
    }
}

//check if kth ancestor is black
int check_ancestor(node root,int k)
{
    int i;
    if(!root)
        return 0;


    

        for( i=0;i<k;i++)
        {
            
           root=root->parent;
           if(root== NULL) break;
        }
        if(root&&root->color=='b'&&i==k)
            return 1;
        else
            return 0;
}

int traverse(node root, int k)
{
    // static int count = 0;
    if(!root)
        return 0;

    if(check_ancestor(root,k)+check_black(root,k)>0)
    {
       return 1+traverse(root->left,k)+traverse(root->right,k);
    }
   
    return 0+traverse(root->left,k)+traverse(root->right,k);


}


int main()
{
    int n,k;
    int data;
    scanf("%d",&k);
    scanf("%d",&n);
    if(n<k)
    {
    printf("%d",0);
    return 0;
    }
    tree t = create_tree();
    for(int i=0;i<n;i++)
    {
        scanf("%d",&data);
        node new_node = create_node(data);
        t->root = rbinsert(t->root, new_node);



    }
        printf("%d\n", traverse(t->root,k));
    //print
    // print(t->root);

   

    return 0;
}
