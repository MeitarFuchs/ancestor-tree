#include <string>
#include <iostream>
#include <cmath>
#include "FamilyTree.hpp"

using namespace std ;
using namespace family;


NodeTree* family::Tree::findChild(string childName,NodeTree* root)
{
    NodeTree* node=new NodeTree("");
    if (root==NULL)
    {
        cout<<"root is null\n";
        return root;
    }
    if (root->name == childName)
    {
        cout<<"the root is the child\n";
        return root;
    }
    else //sending the father and mother to this func--Recorcive
        {
            cout<<"rec find child\n";
            node=Tree::findChild(childName,root->father);
            cout<<"node\n";
            if(node==NULL)
                node=Tree::findChild(childName,root->mother);
        }

    return node;
}


Tree& family::Tree::addFather(string name,string fatherName)
{
   if (this->root==NULL)
   {
       cout<<("the tree is empty");
       throw out_of_range("the tree is empty");
   }
    else // if the tree is not empty
   {
       NodeTree *currnt=findChild(name, this->root);
       cout<<"bake from find child\n";
       if (currnt == NULL) // if there is not a child like this
       {
           cout<<("THERE IS NO CHILD");
           throw out_of_range("THERE IS NO CHILD");

       } else //THERE IS A CHILD LIKE THIS
       {
           if (currnt->father != NULL && currnt->father->name==fatherName)
           {
               cout<<("THERE IS already father");
               throw out_of_range("THERE IS already father");

           }
           else //dont have a father
               {
               cout<<"dont have father\n";
               currnt->father = new NodeTree(fatherName, (currnt->height)+ 1, 1);
               return *this;
           }
       }
   }
}

Tree& family::Tree::addMother(string name,string motherName)
{
    if (this->root==NULL)
    {
        cout<<("the tree is empty");
        throw out_of_range("the tree is empty");
        return *this;
    }
    else // if the tree is not empty
    {
        NodeTree *currnt = findChild(name, this->root);
        if (currnt==NULL) // if there is not a child like this
        {
            cout<<("THERE IS NO CHILD");
            throw out_of_range("THERE IS NO CHILD");
            return *this;
        }
        else //THERE IS A CHILD LIKE THIS
        {
            if (currnt->mother!=NULL)
            {
                cout<<("THERE IS already mother");
                throw out_of_range("THERE IS already mother");

                return *this;
            }

            else
            { //dont have a mother-adding mother
                currnt->mother = new NodeTree(motherName,(currnt->height)+1,2);
                return *this;
            }
        }
    }
}


string Tree::relation(string name)
{
    if (name== this->root->name)
        return "me";
   NodeTree *currNode= findChild(name, this->root);
   if (currNode==NULL)
   {
       cout<<("there is not a child like this");
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
          int i=0;
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


string Tree::find(string relation)
{
    if (relation=="me" && this->root!=NULL)
        return this->root->name;

    int count=0;
    int sex =0;
    int len=relation.length();
    string tempS = "";
    string ansName("");
    string temp("");

    if (relation=="father" || relation=="mother")
    {
        if (relation=="father" && (this->root->father)!=NULL )
            return this->root->father->name;
        if (relation=="mother"  && (this->root->mother)!=NULL)
            return this->root->mother->name; // maybe to check if it is not null??
        else
            throw out_of_range("there is no parent"); // if there is no mother/ father
    }
    if (relation=="grandfather" || relation=="grandmother" )
        {
            if (relation == "grandfather")
            {
                cout<<"grand\n";
                return findRelation(this->root , 2 ,1);
            }
            else
            if (relation == "grandmother")
                return findRelation(this->root , 2 ,2);

        }
        else {
            int i = 0;
            while (i<len)
            {
                if (relation[i] != '-')
                {
                    temp += relation[i];
                }
                if(relation[i]=='-' || i==(len-1))
                {
                    if (temp == "grandfather")
                    {
                        count += 2;
                        sex = 1;
                    }
                    else
                        if (temp == "grandmother")
                        {
                        count += 2;
                        sex = 2;
                        }
                        else
                            if (temp == "great")
                                count++;
                            else
                                throw out_of_range("it is not a good relation");

                    temp = "";
                }
                i++;
            }
    }
    cout<<"count: "<<count<<"\n";
    tempS= findRelation(this->root , count ,sex);
    if(tempS == "")
    {
        throw out_of_range("THE RELATION IS NOT ON THE TREE");
    }
        else
             return tempS;
}


string Tree::findRelation(NodeTree *root, int count, int sex)
{
    cout<<"hello findRelation\n";
    string s="";
    if (root==NULL)
        return "";
    if (root->sex==sex && root->height==count)//height root is 0
    {
        return root->name;
    }
    else
    {
        s=findRelation(root->father, count , sex );
        if (s.empty())
            s=findRelation(root->mother, count , sex );
    }
    cout<<"s: "<<s<<"\n";
    return s;
}

void Tree::remove(string name)
{
    NodeTree * currNode=findChild(name, this->root);
    if (currNode==NULL) {
        cout<<("this child dose not exist");
        throw out_of_range("this child dose not exist");
    }
    else
        {
        deleteRec(currNode);
        }
    return ;
}
 void Tree::deleteRec(NodeTree* root)
 {
    if (root==NULL)
        return;
    if (root->father==NULL && root ->mother==NULL)
        {
        root=nullptr;
        delete root;
        }
    else // the rec
    {
        deleteRec(root->father);
        deleteRec(root->mother);
    }

 }


void Tree::display()
{
    printTree(this->root,0);

}

void Tree::printTree(NodeTree* root, int space)
{
        if(root==NULL) return;
        space+=10;
        printTree(root->mother,space);
        cout<<endl;
        for (int i = 10; i < space; i++)
            cout<<" ";
        cout<<root->name<<"\n";
        printTree(root->father,space);

}