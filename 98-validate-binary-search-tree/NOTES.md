if(root == NULL) return true;
if((left !=NULL && left->val >= root->val) || (right != NULL && root->val >= right->val))
{
return false;
}
return isValidBST(root->left, left, root) && isValidBST(root->right, root, right);