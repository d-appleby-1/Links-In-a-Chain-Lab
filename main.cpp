#include <iostream>

#include "src/Node.hpp"
#include "src/link.hpp"


int main() {
    Link gold("Gold");
    Node* node_one = new Node(&gold);

    Link silver("Silver");
    Node* node_two = new Node(&silver, node_one);

    Link bronze("Bronze");
    Node* node_three = new Node(&bronze, node_two);

    Node* retrieved_node_two = node_three->next();
    Node* retrieved_node_one = retrieved_node_two->next();

    Node* current = node_three; // head of the list

    while (current != nullptr) {
        std::cout << current->get_link()->get_material() << std::endl;
        current = current->next();
    }

}

