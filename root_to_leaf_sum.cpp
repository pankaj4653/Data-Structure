

// function take root of the tree 
// vector to store the elements from root to leaf whose sum is equal to required sum

bool root_to_leaf_sum(node* root,vector<int> &vec,int sum)
{
	if(root==NULL)
		return false;
	
	if(root->left == NULL && root->right==NULL) // leaf node
	{
		if(root->data == sum)
		{
			vec.push_back(root->data);
			return true;
		}
		else
		{
			return false;
		}
	}


	if(root->left,vec,sum-root->data)
	{
		vec.push_back(root->data);
		return true;
	}


	if(root->right,vec,sum-root->data)
	{
		vec.push_back(root->data);
		return true;
	}

	return false;

}