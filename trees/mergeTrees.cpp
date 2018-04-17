/*
 * Merge 2 trees into a balaned Tree
 *
 */

Node* insert(Node* node, int val) {
    if(node == nullptr)
        return new Node(val);
    if(val < node->val)
        node->left = insert(node->left, val);
    else
        node->right = insert(node->right, val);
    return node;
}
Node* makeNewTree(Node* node, vector<int>& v1, vector<int>& v2) {
    vector<int> merged;
    int s1 = 0; int s2 = 0;
    while(s1 < v1.size() && s2 < v2.size()) {
        if(v1[s1] < v2[s2]) {
            merged.push_back(v1[s1]);
            s1++;
        } else {
            merged.push_back(v2[s2]);
            s2++;
        }
    }
    while(s1 < v1.size())
        merged.push_back(v1[s1++]);
    while(s2 < v2.size())
        merged.push_back(v2[s2++]);
    int mid = (v1.size() + v2.size())/2;
    int left = mid -1; int right = mid;
    for(int i = mid; i < merged.size(); ++i)
        node = insert(node, merged[i]);
    for(int i = mid -1; i >= 0; --i)
        node = insert(node, merged[i]);
    
    return node;
}
void orderTree(Node* node, vector<int>& arr) {
    if(node == nullptr) return;
    orderTree(node->left, arr);
    arr.push_back(node->val);
    orderTree(node->right, arr);
}
Node* mergeTrees(Node* n1, Node* n2) {
    vector<int> v1, v2;
    orderTree(n1, v1);
    orderTree(n2, v2);
    Node* node = nullptr;
    return makeNewTree(node, v1, v2);
}
