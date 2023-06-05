//treesort stats
//best case NlogN
//average NlogN
//worst case NlogN

// needs the following definition
#IFNDEF set
struct set {
	int length;
	int array[];
};
#ENDIF

struct Node {
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

bool compare(int item1, int item2){
	if(item2>item1){return true;}
	return false;
}

void tree_to_set(Node* root, set* arr, int &i){
	// the sorted result into set
	if (root != NULL){
		storeSorted(root->left, arr, i);
		arr->array[i] = root->key;
		i++;
		storeSorted(root->right, arr, i);
	}
}

