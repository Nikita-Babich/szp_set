//treesort stats
//best case NlogN
//average NlogN
//worst case NlogN

// needs the following definition
//struct set {
//	int length;
//	int array[];
//};

struct Node{
    int key;
    struct Node* left;
	struct Node* right;
};

struct Node* newNode(int item){
    struct Node* ptr = (struct Node*) malloc(sizeof(struct Node));
    ptr->key = item;
    ptr->left = NULL;
	ptr->right = NULL;
    return ptr;
}

