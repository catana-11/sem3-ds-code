/*
Implement a dictionary using a binary search tree where the dictionary stores keywords & its meanings. Perform following operations:
i.	Insert a keyword
ii.	Delete a keyword
iii.Create mirror image 
iv. Display level wise
v.	Copy
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct node {
    char word[20];
    char meaning[20];
    struct node *left, *right;
};

// queue for level-wise -->
struct node *q[100];
int f = -1, r = -1;

void insertq(struct node *t)
{
    r++;
    q[r] = t;
}

struct node *deleteq()
{
    struct node *t = NULL;
    if (f == r) return NULL; 
    f++;
    t = q[f];
    return t;
}

int qempty()
{
   if(f == r)
   return (1);
   else
   return (0);
}


// mirror tree recursively -->
void mirror_rec(struct node *root)
{
    struct node *temp;
    if (root != NULL)
    {
        temp = root->left;
        root->left = root->right;
        root->right = temp;
        mirror_rec(root->left);
        mirror_rec(root->right);
    }
}

// create BST non-rec -->
void create_bst_nonrec(struct node *root)
{
    char ch = 'y';

    do {
        struct node *temp, *ptr;
        int flag = 1;
        temp = root;

        ptr = (struct node *)malloc(sizeof(struct node));
        ptr->left = NULL; ptr->right = NULL;

        printf("\nEnter new node word: "); scanf("%s", ptr->word);
        printf("Enter new node meaning: "); scanf("%s", ptr->meaning);

        while (flag == 1) {
            if (strcmp(ptr->word, temp->word) <= 0) {
                if (temp->left == NULL) {
                    temp->left = ptr;
                    flag = 0;
                } else {
                    temp = temp->left;
                }
            } else {
                if (temp->right == NULL) {
                    temp->right = ptr;
                    flag = 0;
                } else {
                    temp = temp->right;
                }
            }
        }

        printf("\nDo you want to continue? Type 'y' for yes: "); scanf(" %c", &ch);
    } while (ch == 'y');
}

// delete node by word-->
struct node* delete_bst(struct node *root, char key[20]) {
    struct node *parent = NULL, *curr = root, *temp, *s;

    // Step 1: Find node to delete
    while (curr != NULL && strcmp(curr->word, key) != 0) {
        parent = curr;
        if (strcmp(key, curr->word) < 0)
            curr = curr->left;
        else
            curr = curr->right;
    }

    if (curr == NULL) {
        printf("\nKeyword '%s' not found!\n", key);
        return root;
    }

    //now curr is the node to be deleted

    // ------------------------
    // CASE 1: Deleting Root
    // ------------------------
    if (curr == root) {
        if (curr->right == NULL)
            root = curr->left;
        else if (curr->left == NULL)
            root = curr->right;
        else if (curr->right != NULL && curr->left != NULL) { 
            temp = curr->left;
            root = curr->right;
            s = curr->right;
            while (s->left != NULL)
                s = s->left;
            s->left = temp;
        }
        free(curr);
        return root;
    }

    // ------------------------
    // CASE 2: Leaf Node
    // ------------------------
    if (curr->left == NULL && curr->right == NULL) {
        if (parent->left == curr)
            parent->left = NULL;
        else
            parent->right = NULL;
    }

    // ------------------------
    // CASE 3: One Child (Right)
    // ------------------------
    else if (curr->left == NULL) {
        if (parent->left == curr)
            parent->left = curr->right;
        else
            parent->right = curr->right;
    }

    // ------------------------
    // CASE 4: One Child (Left)
    // ------------------------
    else if (curr->right == NULL) {
        if (parent->left == curr)
            parent->left = curr->left;
        else
            parent->right = curr->left;
    }

    // ------------------------
    // CASE 5: Two Children
    // ------------------------
    else {
        s = curr->right;
        temp = curr->left;
        while (s->left != NULL)
            s = s->left;
        s->left = temp;

        if (parent->left == curr)
            parent->left = curr->right;
        else
            parent->right = curr->right;
    }

    curr->left = curr->right = NULL;
    free(curr);
    return root;
}


// level wise traversal using queue-->
void levelwise(struct node *root)
{
    if (root == NULL) return;
    f = -1; r = -1;

    insertq(root);
    while (!qempty())
    {
        struct node *temp = deleteq();
        if (temp == NULL) break;
        printf("{%s\t%s}\n", temp->word, temp->meaning);
        if (temp->left != NULL) insertq(temp->left);
        if (temp->right != NULL) insertq(temp->right);
    }
}

// single insertion (non-recursive) -->
void insert_bst(struct node *root)
{
    struct node *temp, *ptr;
    int flag = 1;
    temp = root;

    ptr = (struct node *)malloc(sizeof(struct node));
    ptr->left = ptr->right = NULL;

    printf("\nEnter new node word: ");
    scanf("%19s", ptr->word);
    printf("Enter new node meaning: ");
    scanf("%19s", ptr->meaning);

    while (flag == 1) {
        if (strcmp(ptr->word, temp->word) <= 0) {
            if (temp->left == NULL) {
                temp->left = ptr;
                flag = 0;
            } else {
                temp = temp->left;
            }
        } else {
            if (temp->right == NULL) {
                temp->right = ptr;
                flag = 0;
            } else {
                temp = temp->right;
            }
        }
    }
}

// non-recursive search: returns pointer if found, else NULL-->
struct node *search_bst_nonrec(struct node *root, const char word[20])
{
    struct node *temp = root;
    while (temp != NULL) {
        int cmp = strcmp(word, temp->word);
        if (cmp == 0) {
            printf("\nKey '%s' is found with meaning '%s'\n", temp->word, temp->meaning);
            return temp;
        } else if (cmp < 0) {
            temp = temp->left;
        } else {
            temp = temp->right;
        }
    }
    printf("\nKey '%s' not found\n", word);
    return NULL;
}

// inorder display  -->
void inorder_rec(struct node *root)
{
    if (root != NULL) {
        inorder_rec(root->left);
        printf("{%s: %s}    ", root->word, root->meaning);
        inorder_rec(root->right);
    }
}

// copy of tree (recursive)-->
struct node *copy_rec(struct node *root)
{
    struct node *temp = NULL;
    if (root != NULL) {
        temp = (struct node *)malloc(sizeof(struct node));
        strcpy(temp->word, root->word);
        strcpy(temp->meaning, root->meaning);
        temp->left = copy_rec(root->left);
        temp->right = copy_rec(root->right);
    }
    return temp;
}

int main()
{
    struct node *root = NULL, *copy = NULL;
    root = (struct node *)malloc(sizeof(struct node));
    root->left = root->right = NULL;

    printf("\nEnter root node word: ");
    scanf("%19s", root->word);
    printf("Enter root node meaning: ");
    scanf("%19s", root->meaning);

    create_bst_nonrec(root);

    printf("\nInorder (BST) :\n");
    inorder_rec(root);
    printf("\n");

    printf("\nNow implementing insert node: \n");
    insert_bst(root);
    printf("\nInorder after insert:\n");
    inorder_rec(root);
    printf("\n");

    // delete node-->
    {
        char key[20];
        printf("\nNow implementing delete node. Enter keyword to delete: ");
        scanf("%s", key);
        root = delete_bst(root, key);
        printf("Inorder after delete:\n");
        inorder_rec(root);
        printf("\n");
    }

    printf("\nNow implementing levelwise traversal:\n");
    levelwise(root);
    printf("\n");

    printf("\nNow implementing copy:\n");
    copy = copy_rec(root);
    inorder_rec(copy);
    printf("\n");

    printf("\nNow mirroring original tree (in-place):\n");
    mirror_rec(root);
    inorder_rec(root);
    printf("\n");

    return 0;
}
