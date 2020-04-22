
#ifndef UNTITLED4_FAMILYTREE_H
#define UNTITLED4_FAMILYTREE_H

#pragma once
#include <iostream>

using namespace  std;
namespace family {
class NodeTree{
public:
    string name;
    int sex; //1-- father 2--mother
    int height;
    NodeTree *father;
    NodeTree *mother;

    NodeTree(string name)
    {
        this->name =name;
        this->father=nullptr;
        this->mother=nullptr;
        this->sex=0;
        this->height=0;
    };
    NodeTree(string name, int height, int sex)
    {
        this->name =name;
        this->father=nullptr;
        this->mother=nullptr;
        this->sex=sex;
        this->height=height;
    };
    ~NodeTree()
    {
        this->father=NULL;
        this->mother=NULL;
    }

};

    class Tree {

    public:
        NodeTree *root;

	Tree()
        {
            this->root= nullptr;
        };

        Tree(string name)
        {
            this->root = new NodeTree(name);
        };

        Tree &addFather(string,string);
        Tree &addMother(string,string);

        string relation(string);
        string find(string);

        void display();
        void remove(string);
        void deleteRec(NodeTree* );

        NodeTree* findChild(string,NodeTree*);
        string findRelation(NodeTree*, int , int);

        void printTree(NodeTree* , int );

    };
}


#endif //UNTITLED4_FAMILYTREE_H

