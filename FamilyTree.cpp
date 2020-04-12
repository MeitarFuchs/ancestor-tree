#include "FamilyTree.hpp"
#include <iostream>
#include <stdio.h>
#include <string>
#include <exception>

using namespace std;

namespace family {
    NodeTree::NodeTree() {
        this->myName = "";
        this->father = nullptr;
        this->mother = nullptr;
    }

    NodeTree::NodeTree(string name) {
        this->myName = name;
        this->father = nullptr;
        this->mother = nullptr;
    }

    Tree::Tree(string name) {
        NodeTree node(name);
        this->root = &node;
    }

    Tree &Tree::addFather(string child, string father) {
        return *this;
    }

    Tree &Tree::addMother(string child, string father) {
        return *this;
    }

    string relation(string name) { return "k"; }

    string find(string name) { return "k"; }

    void remove(string name) { ; }

    void display() { ; }

    string toString() // for the diplay function
    { return "k"; }
};