#include <catch2/catch.hpp>
#include <string>

auto is_permutation(std::string const& x, std::string const& y) -> bool;
TEST_CASE("is_permutation determines if x is a permutation of y") {}

TEST_CASE("numbers") {
    CHECK(1 < 2);
}