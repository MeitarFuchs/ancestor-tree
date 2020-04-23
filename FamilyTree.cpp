#include <string>
#include <iostream>
#include <cmath>
#include "FamilyTree.hpp"

using namespace std ;
using namespace family;


NodeTree* family::Tree::findChild(string childName,NodeTree* root)
{
    NodeTree* node=new NodeTree("");
    if (root==NULL)//root is null
        return root;
    if (root->name == childName)//the root is the child
        return root;
    else //sending the father and mother to this func--Recorcive
        {
            node=Tree::findChild(childName,root->father);
            if(node==NULL)
                node=Tree::findChild(childName,root->mother);
        }

    return node;
}


Tree& family::Tree::addFather(string name,string fatherName)
{
   if (this->root==NULL)
       throw out_of_range("the tree is empty");
    else // if the tree is not empty
   {
       NodeTree *currnt=findChild(name, this->root);
       if (currnt == NULL) // if there is not a child like this
           throw out_of_range("THERE IS NO CHILD");
       else //THERE IS A CHILD LIKE THIS
       {
           if (currnt->father != NULL )
              throw out_of_range("THERE IS already father");
           else //dont have a father
           {
               currnt->father = new NodeTree(fatherName, (currnt->height)+ 1, 1);
               return *this;
            }
       }
   }
}

Tree& family::Tree::addMother(string name,string motherName)
{
    if (this->root==NULL)
        throw out_of_range("the tree is empty");
    else // if the tree is not empty
    {
        NodeTree *currnt = findChild(name, this->root);
        if (currnt==NULL) // if there is not a child like this
            throw out_of_range("THERE IS NO CHILD");
        else //THERE IS A CHILD LIKE THIS
        {
            if (currnt->mother!=NULL)
                throw out_of_range("THERE IS already mother");
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
       return "unrelated";
   else
   {
      int temp=(this->root-> height) + currNode->height;
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
    if (relation=="me" && this->root!=NULL) {
        return this->root->name;
    }
    int count=0;
    int sex =0;
    int len=relation.length();
    string tempS = "";
    string ansName("");
    string temp("");

    if (relation=="father" || relation=="mother")
    {
        if (relation=="father" && (this->root->father)!=NULL ) {
            return this->root->father->name;
        }
        if (relation=="mother"  && (this->root->mother)!=NULL) {
            return this->root->mother->name;
        }
        else
            throw out_of_range("there is no parent"); // if there is no mother/ father
    }
    if (relation=="grandfather" || relation=="grandmother" )
        {
            if (relation == "grandfather")
            {
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
                    temp += relation[i];
                if(relation[i]=='-' || i==(len-1))
                {
                    if (temp == "grandfather")
                    {   count += 2;
                        sex = 1;}
                    else
                        if (temp == "grandmother")
                        {   count += 2;
                            sex = 2;}
                        else
                            if (temp == "great")
                                count++;
                            else
                                throw out_of_range("it is not a good relation");
                    temp = ""; // restart temp
                }
                i++;
            }
    }
    tempS= findRelation(this->root , count ,sex);
    if(tempS == "")
        throw out_of_range("THE RELATION IS NOT ON THE TREE");
        else return tempS;
}

string Tree::findRelation(NodeTree *root, int count, int sex) //HELP TO FIND FUNC
{
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
    return s;
}

void Tree::display()
{
    printTree(this->root,0);

}

void Tree::printTree(NodeTree* root, int space) //HELP TO DISPLAY FUNC
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

void Tree::remove(std::string name){

    if(root->name==name)
        throw out_of_range("can not remove the root");
    if(relation(name)=="unrelated")
        throw out_of_range("unrelated");
    if(root->mother!=NULL) //there is a mother
    {
        if(root->mother->name==name){
            freeALLTreeFromCurrnt(root->mother);
            root->mother=nullptr;
        }
        else
            deleteT(root->mother,name);
    }
    if(root->father !=NULL)//there is a father
    {
        if(root->father->name==name){
            freeALLTreeFromCurrnt(root->father);
            root->father= nullptr;
        }
        else
            deleteT(root->father,name);
    }
}

void Tree::deleteT(NodeTree* currntN,string name){ //HELP TO REMOVE FUNC
    if(currntN->mother!=NULL)//there is a mother
    {
        if(currntN->mother->name==name){ //if it's the mother
            freeALLTreeFromCurrnt(currntN->mother);
            currntN->mother=NULL;
        }
        else //if it's not the mother
            deleteT(currntN->mother,name);
    }
    if(currntN->father!=NULL)//there is a father
    {
        if(currntN->father->name==name){ //if it's the father
            freeALLTreeFromCurrnt(currntN->father);
            currntN->father=NULL;
        }
        else //if it's not the father
            deleteT(currntN->father,name);
    }
}

void Tree::freeALLTreeFromCurrnt(NodeTree* currntN){  //HELP TO REMOVE FUNC
    if(currntN->mother !=NULL)//there is a mother
    {
        freeALLTreeFromCurrnt(currntN->mother);
    }
    if(currntN->father !=NULL)//there is a father
    {
        freeALLTreeFromCurrnt(currntN->father);
    }

    if((currntN->father==NULL) && (currntN->mother==NULL)) //ale
        delete(currntN);
}


