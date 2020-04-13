
#ifndef UNTITLED4_FAMILYTREE_H
#define UNTITLED4_FAMILYTREE_H

#pragma once
#include <iostream>

using namespace  std;
namespace family {
class NodeTree{
public:
    string name;
    NodeTree *father;
    NodeTree *mother;

    NodeTree(string name)
    {
        this->name =name;
        this->father=nullptr;
        this->mother=nullptr;

    };

};

    class Tree {

    public:
        NodeTree *root;

        int size ;//how many nodes in the tree

	Tree()
        {
            this->root= nullptr;
            size=0; 
        };

        Tree(string name)
        {
            this->root = new NodeTree(name);
            size=1; //have just the root
        };

        Tree &addFather(string,string);
        Tree &addMother(string,string);

        string relation(string);
        string find(string);

        void display();
        void remove(string);

    };
}


#endif //UNTITLED4_FAMILYTREE_H

