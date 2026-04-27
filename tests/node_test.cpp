#include <catch2/catch_test_macros.hpp>
#include <catch2/benchmark/catch_benchmark.hpp>
#include <catch2/benchmark/catch_constructor.hpp>
#include <catch2/generators/catch_generators_range.hpp>
#include "../src/Node.hpp"
#include "../src/link.hpp"

TEST_CASE("Node stores and returns Link correctly", "[node]") {
    Link gold("Gold");
    Node node(&gold);

    REQUIRE(node.get_link() != nullptr);
    REQUIRE(node.get_link()->get_material() == "Gold");
}

TEST_CASE("Node next() returns nullptr when no next node is set", "[node]") {
    Link silver("Silver");
    Node node(&silver);

    REQUIRE(node.next() == nullptr);
}

TEST_CASE("Node can link to another node", "[node]") {
    Link gold("Gold");
    Node node1(&gold);

    Link silver("Silver");
    Node node2(&silver, &node1);

    REQUIRE(node2.next() == &node1);
    REQUIRE(node2.next()->get_link()->get_material() == "Gold");
}

TEST_CASE("Chained nodes form a valid singly linked list", "[node][list]") {
    Link bronze("Bronze");
    Link silver("Silver");
    Link gold("Gold");

    Node node1(&gold);
    Node node2(&silver, &node1);
    Node node3(&bronze, &node2);

    SECTION("Traversal from head yields correct order") {
        Node* current = &node3;

        REQUIRE(current->get_link()->get_material() == "Bronze");
        current = current->next();

        REQUIRE(current->get_link()->get_material() == "Silver");
        current = current->next();

        REQUIRE(current->get_link()->get_material() == "Gold");
        current = current->next();

        REQUIRE(current == nullptr);
    }
}
