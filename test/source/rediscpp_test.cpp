#include <rediscpp/rediscpp.hpp>

auto main() -> int
{
  auto result = name();
  return result == "rediscpp" ? 0 : 1;
}
