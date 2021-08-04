#include<stdio.h>
#include<stdlib.h>
struct node {
	int data;
	struct node *leftchild;
	struct node *rightchild;
};
struct node *root=NULL;
struct node *getnode()
{ 
  struct node *nn;
  nn=(struct node *)malloc(sizeof(struct node));
  nn->leftchild=nn->rightchild=NULL;
  return nn;
}
struct node *getnode1()
{ 
  struct node *nn;
  nn=(struct node *)malloc(sizeof(struct node));
  printf("enter the value");
  scanf("%d",&nn->data);
  nn->leftchild=nn->rightchild=NULL;
  return nn;
}
 
void add(struct node *root,struct node *temp)
{  
   if(root==NULL)
    {
    	root=getnode1();
	}
  else 
   {     
       if(temp->data < root->data)
            {   if(temp->leftchild !=NULL)
                  	add(root->leftchild,temp);
                 else 
				    root->leftchild=temp; 	
			}
		 if(temp->data > root->data)
            {   if(temp->rightchild !=NULL)
                  	add(root->rightchild,temp);
                 else 
				    root->rightchild=temp; 	
			}	
         
     
   }  	
}
struct node *min(struct node *root)
{
	if(root==NULL)
        return NULL;
    else if(root->leftchild != NULL) 
        return min(root->leftchild); 
    return root;
}
struct node *delete1(struct node *root,int x)
{  
    
    //searching for the item to be deleted
    if(root==NULL)
        return NULL;
    if (x>root->data)
        root->rightchild = delete1(root->rightchild, x);
    else if(x<root->data)
        root->leftchild = delete1(root->leftchild, x);
        
    else
    {
        //No Children
        if(root->leftchild==NULL && root->rightchild==NULL)
        {
            free(root);
            return NULL;
        }

        //One Child
        else if(root->leftchild==NULL || root->rightchild==NULL)
        {
            struct node *temp;
            if(root->leftchild==NULL)
                temp = root->rightchild;
            else
                temp = root->leftchild;
            free(root);
            return temp;
        }

        //Two Children
        else
        {
            struct node *temp = min(root->rightchild);
            root->data = temp->data;
            root->rightchild = delete1(root->rightchild, temp->data);
        }
    }
    return root;
    printf("element deleted");
}
void inorder(struct node *root)
{
    if(root!=NULL) // checking if the root is not null
    {  printf("in");
        inorder(root->leftchild); // visiting left child
        printf(" %d ", root->data); // printing data at root
        inorder(root->rightchild);// visiting right child
    }
    else
      printf("out");
}
int main()
{ int choice,x ;
struct node *temp;
  while(1)
  { printf("/n1.add 2.delete 3.display");
    scanf("%d",&choice);
    switch(choice)
    {
    	case 1:
    	       temp=getnode();
    	       printf("enrer value");
    	       scanf("%d",&temp->data);
		      
              add(root,temp);break;
    	case 2: 
		       printf("Enter element");
               scanf("%d",&x);
		    delete1(root,x);break;
    	case 3:inorder(root);break;
	}
  	
  }
	
}
