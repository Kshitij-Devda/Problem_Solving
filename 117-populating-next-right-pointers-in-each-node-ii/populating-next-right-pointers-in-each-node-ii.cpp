class Solution {
public:    
    Node* connect(Node* root) {
        if(root==nullptr){
            return nullptr;
        }
        queue<Node*> q;
        q.push(root);
        while(!empty(q)){
            int y=q.size();
            for(int i=0;i<y;i++){
                Node* x=q.front();
                if(x->left!=nullptr){
                    q.push(x->left);
                }
                if(x->right!=nullptr){
                    q.push(x->right);
                }
                if(i!=y-1){
                    q.pop();
                    x->next=q.front();
                }
                else{
                    q.pop();
                    x->next=nullptr;
                }
            }
        } 
        return root;
    }
};