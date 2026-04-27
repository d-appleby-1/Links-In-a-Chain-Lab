#pragma once
#include "link.hpp"
class Node {
private:
    Link* link;
    Node* nextNode;
public:
    Node(Link* link);
    Node(Link* link, Node* nextNode);
    Node* next() const;
    Link* get_link() const;
};
