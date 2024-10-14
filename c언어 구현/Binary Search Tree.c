#include<stdio.h>
#include<stdlib.h>

typedef struct node {
    struct node *left, *right, *parent;
    int key;
} node;

typedef struct tree {
    node *child;
} tree;

void initTree(tree *tree) {
    tree->child = NULL;
}

void initNode(node *parent, node *node, int key) {
    node->parent=parent;
    node->key=key;
    node->left=node->right=NULL;
}

void print(node *node) {
    printf(" %d", node->key);
    if(node->left) print(node->left);
    if(node->right) print(node->right);
}

void insertItem(tree *tree, int key) {
    node *nextNode = (node*)malloc(sizeof(node));
    initNode(NULL, nextNode, key);

    if(!tree->child) {
        tree->child = nextNode;
        return;
    }

    node *n = tree->child;
    while(1) {
        if(key<n->key) {
            if(n->left) n = n->left;
            else {
                n->left = nextNode;
                nextNode->parent = n;
                return;
            }
        } else {
            if(n->right) n = n->right;
            else {
                n->right = nextNode;
                nextNode->parent = n;
                return;
            }
        }
    }
}

int searchItem(tree *tree, int key) {
    if(!tree->child) return 0;
    node *n = tree->child;
    while(1) {
        if(key==n->key) return 1;
        if(key<n->key && n->left) n = n->left;
        else if(key>n->key && n->right) n = n->right;
        else return 0;
    }
}

int deleteItem(tree *tree, int key) {
    if(!tree->child) return 0;
    node *n = tree->child;

    while(1) {
        if(key==n->key) break;
        if(key<n->key && n->left) n = n->left;
        else if(key>n->key && n->right) n = n->right;
        else return 0;
    }

    if(!n->left && !n->right) {
        if(n->parent==NULL) tree->child=NULL;
        else if(n->parent->left == n) n->parent->left=NULL;
        else n->parent->right=NULL;
    } else if(!n->left) {
        if(n->parent==NULL) {
            tree->child = n->right;
            n->right->parent = NULL;
        } else {
            if(n->parent->left == n) n->parent->left = n->right;
            else n->parent->right = n->right;
            n->right->parent = n->parent;
        }
    } else if(n->left && !n->right) {
        if(n->parent==NULL) {
            tree->child = n->left;
            n->parent=NULL;
        } else {
            if(n->parent->left == n) n->parent->left = n->left;
            else n->parent->right = n->left;
            n->left->parent = n->parent;
        }
    } else {
        node *change = n->right;
        while(change->left) change = change->left;
        n->key = change->key;
        if(!change->right) {
            if(change->parent->left == change) change->parent->left = NULL;
            else change->parent->right = NULL;
        } else {
            if(change->parent->left == change) change->parent->left = change->right;
            else change->parent->right = change->right;
            change->right->parent = change->parent;
        }
    }
    return 1;
}

int main(void) {
    tree *head = (tree*)malloc(sizeof(tree));
    initTree(head);

    // format
    // p -> PreOrder printing
    // q -> quit
    // i x -> insert x
    // s x -> search x
    // d x -> delete x
    while(1) {
        char ch; scanf("%c", &ch);
        if(ch=='q') return 0;
        if(ch=='p') {
            getchar(); // enter
            if(head->child) print(head->child);
        } else {
            int key; scanf("%d", &key); getchar(); // enter
            if(ch=='i') {
                insertItem(head, key);
            } else if(ch=='d') {
                if(deleteItem(head, key)) printf("%d", key);
                else printf("X");
            } else {
                if(searchItem(head, key)) printf("%d", key);
                else printf("X");
            }
        }
        printf("\n");
    }
}