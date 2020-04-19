#include <string>
#include <iostream>
#include <cmath>
#include "FamilyTree.hpp"

using namespace std ;
using namespace family;


NodeTree* family::Tree::findChild(string childName,NodeTree* root)
{
    if (root==NULL)
        return root;
    else
    {
        if (root->name == childName)
            return root;
        else //sending the father and mother to this func--Recorcive
        {
            family::Tree::findChild(childName,root->father);
            family::Tree::findChild(childName,root->mother);
        }
    }

}


Tree& family::Tree::addFather(string name,string fatherName)
{
   if (this->root==NULL)
   {
       printf("the tree is empty");
       return *this;
   }
    else // if the tree is not empty
   {
       NodeTree *currnt = findChild(name, this->root);
       if (currnt == NULL) // if there is not a child like this
       {
           printf("THERE IS NO CHILD");
           return *this;
       } else //THERE IS A CHILD LIKE THIS
       {
           if (currnt->father != NULL) {
               printf("THERE IS already father");
               return *this;
           } else { //dont have a father
               this->size++;
               currnt->father = new NodeTree(fatherName, (currnt->height) - 1, 1);
               return *this;
           }
       }
   }
}

Tree& family::Tree::addMother(string name,string motherName)
{

    if (this->root==NULL)
    {
        printf("the tree is empty");
        return *this;
    }
    else // if the tree is not empty
    {
        NodeTree *currnt = findChild(name, this->root);
        if (currnt==NULL) // if there is not a child like this
        {
            printf("THERE IS NO CHILD");
            return *this;
        }
        else //THERE IS A CHILD LIKE THIS
        {
            if (currnt->mother!=NULL)
            {
                printf("THERE IS already mother");
                return *this;
            }

            else
            { //dont have a mother-adding mother
                this->size++;
                currnt->mother = new NodeTree(motherName,(currnt->height)-1,2);
                return *this;
            }
        }
    }
}


string Tree::relation(string name)
{
   NodeTree *currNode= findChild(name, this->root);
   if (currNode==NULL)
   {
       printf("there is not a child like this");
       return "unrelated";
   }
   else
   {
      int temp=(this->root-> height) - currNode->height;
      if (temp==1)
      {
          if (currNode->sex==1)
              return "father";
          if (currNode->sex==2)
              return "mother";
      }
      else
      {
          string ans="";
          for (i=0; i<temp-2; i++)
              ans+="great-";

          if (currNode->sex==1)
              ans+="grandfather";
          if (currNode->sex==2)
              ans+="grandmother";

          return ans;
      }
   }

    return name ;
}

string Tree::find(string name)
{
    //NodeTree *currNode= nullptr;

    return name ;

}

void Tree::remove(string name)
{
    //NodeTree *currNode= nullptr;

    return ;
}

void Tree::display()
{
    return;
}


