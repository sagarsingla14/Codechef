// struct Node {
//     int data;
//     Node *left;
//     Node *right;
//
//     Node(int val) {
//         data = val;
//         left = right = NULL;
//     }
// };

struct box {
    bool ok;
    int mn , mx ,cnt;
    box(bool ok , int mn , int mx , int cnt) {
        this -> ok = ok;
        this -> mn = mn;
        this -> mx = mx;
        this -> cnt = cnt;
    }
};

box* solve(Node *root) {
    if(root == NULL) {
        box *cur = new box(true , INT_MAX , INT_MIN , 0);
        return cur;
    }

    if(root -> left == NULL && root -> right == NULL) {
        box *cur = new box(true , root -> data , root -> data , 1);
        return cur;
    }

    box *l = solve(root -> left);
    box *r = solve(root -> right);

    if(l -> ok && r -> ok && l -> mx < root -> data && r -> mn > root -> data) {
        return new box(true , min(root -> data , min(r -> mn , l -> mn)) , max(root -> data , max(r -> mx , l -> mx)) , l -> cnt + r -> cnt + 1);
    }
    else{
        return new box(false , 0 , 0 , max(l -> cnt , r -> cnt));
    }
}

int largestBst(Node *root) {
	if(!root) {
        return 0;
    }
    box *ans = solve(root);
    return ans -> cnt;
}
