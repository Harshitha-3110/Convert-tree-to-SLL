/*Converting given tree structure into Linked list structure*/

#include <stdio.h>
#include <stdlib.h>
#define SIZE 20

typedef struct tree_node
{
    struct tree_node *left,*right;
    int data;
}Tree;
typedef struct Slist_node
{
    int data;
    struct Slist_node *next;
}Slist;

Slist *head = NULL;

void convert_to_SLL(Tree **root);
int insert_last(int data);
void print_list(Slist *head);
Tree *create_tree(int data);

int main()
{
    Tree *root = NULL;

    root = create_tree(1);
    root->right = create_tree(3);
    root->left = create_tree(2);
    root->left->left = create_tree(4);
    root->left->right = create_tree(5);
    root->right->left = create_tree(6);

    convert_to_SLL(&root);

    printf("Converted Singly Linked List: ");
    print_list(head);
}
Tree *create_tree(int data)
{
    Tree *node = malloc(sizeof(Tree));
    if(node == NULL)
    return NULL;
    else
    {
        node->data=data;
        node->left=NULL;
        node->right=NULL;
    }
    
    return node;
}
void convert_to_SLL(Tree **root)
{
    Tree *queue[SIZE] ;
    int front=0,rear=0;
    /* Levelorder traversal*/
    if(*root == NULL)
    return;
    queue[rear++] = *root; //enqueue root node
    while(front<rear)
    {
        Tree *temp = queue[front++]; // dequeue node
        insert_last(temp->data); //insert to SLL
        if(temp->left)
        queue[rear++]=temp->left;//enqueue
        if(temp->right)
        queue[rear++]=temp->right;//enqueue
    }
 
}
/*Insert to SLL*/
int insert_last(int data)
{
    Slist *new = malloc(sizeof(Slist));//create node
    if(new == NULL)
    return -1;
    else{
        if(head == NULL)//list is empty
        head = new;
        else{
            Slist *t = head;
            while(t->next)//traverse untill last node
            {
                t=t->next;
            }
            t->next = new;
        }
        new->data = data;
        new->next = NULL;
    }
    return 0;
}
void print_list(Slist *head)
{
    while(head != NULL)
    {
        printf("%d -> ", head -> data);
		head = head -> next;
    }
printf("NULL\n");
}