#include "rediscpp/rediscpp.hpp"

#include <catch2/catch.hpp>

TEST_CASE("Name is rediscpp", "[library]")
{
  REQUIRE(name() == "rediscpp");
}
