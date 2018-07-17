
// to check two tree with root1 and root2 are same
// functions takes roots of both the tree

bool check_same(node* root1,node* root2)
{
	if(root1==NULL && root2==NULL)
	return true;

	if(root1==NULL || root2==NULL)
	return false;

	return check_same(root1->data==root2->data)&&check_same(root1->left,root2->left)&&check_same(root1->right,root2->right);
}