#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>
#include <future>
#include <string>

using namespace std;

TEST_CASE("async returns valid future") {
  using namespace literals::string_literals;

  auto the_future = async([] { return "female"s; });
  REQUIRE(the_future.valid());
}

TEST_CASE("future invalid by default") {
  future<bool> default_future;
  REQUIRE_FALSE(default_future.valid());
}

TEST_CASE("get returns value") {
  using namespace literals::string_literals;

  auto the_future = async([] { return "female"s; });
  REQUIRE(the_future.get() == "female");
}

TEST_CASE("get may throw ") {
  auto ghostrider = async([] { throw runtime_error{ "The pattern is full." }; });
  REQUIRE_THROWS_AS(ghostrider.get(), runtime_error);
}

TEST_CASE("wait_until indicates whether a task is ready") {
  using namespace literals::chrono_literals;

  auto sleepy = async(launch::async, [] { this_thread::sleep_for(100ms); }); // 1
  const auto not_ready_yet = sleepy.wait_for(25ms);  // 2
  REQUIRE(not_ready_yet == future_status::timeout);  // 3
  const auto totally_ready = sleepy.wait_for(100ms); // 4
  REQUIRE(totally_ready == future_status::ready); // 5
}


// std::future<FuncReturnType> std::async([policy], func, Args&&... args);
