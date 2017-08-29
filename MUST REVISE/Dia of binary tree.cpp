Diameter of Binary Tree
***********************************************************************
int util(Node* root, int & dia){
    if(root == NULL)return 0;
    int l = util(root->left , dia);
    int r = util(root->right , dia);
    int ms = max(l,r)+1;
    int mo = max(l+r+1 , ms);
    dia = max(dia , mo);
    return ms;
}

int diameter(Node* node)
{
  int dia = 0;
  util(node , dia);
  return dia;
}
