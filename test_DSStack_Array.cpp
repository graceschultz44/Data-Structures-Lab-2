#define CATCH_CONFIG_MAIN
#include "catch2/catch.hpp"
#include "DSStack_Array.h"

TEST_CASE("push", "[DSStack_Array]")
{
    DSStack_Array<int> test1;
    test1.push(44);
    test1.push(99);
    REQUIRE(test1.peek() == 99);
    test1.push(-7777777);
    test1.push(777);
    test1.push(4);
    test1.push(0);
    REQUIRE(test1.peek() == 0);

    DSStack_Array<std::string> test2;
    test2.push("hi");
    test2.push("Grace");
    REQUIRE(test2.peek() == "Grace");
    test2.push("hola");
    test2.push("lol");
    test2.push("hello");
    REQUIRE(test2.peek() == "hello");

    DSStack_Array<char> test3;
    test3.push('c');
    test3.push('&');
    REQUIRE(test3.peek() == '&');
    test3.push('=');
    test3.push('!');
    REQUIRE(test3.peek() == '!');
}

TEST_CASE("pop", "[DSStack_Array]")
{
    DSStack_Array<int> test1;
    test1.push(44);
    test1.push(99);
    test1.pop();
    REQUIRE(test1.peek() == 44);
    test1.push(-7777777);
    test1.push(777);
    test1.push(4);
    test1.push(0);
    test1.pop();
    REQUIRE(test1.peek() == 4);

    DSStack_Array<std::string> test2;
    test2.push("hi");
    test2.push("Grace");
    test2.pop();
    REQUIRE(test2.peek() == "hi");
    test2.push("hola");
    test2.push("lol");
    test2.push("hello");
    test2.pop();
    REQUIRE(test2.peek() == "lol");

    DSStack_Array<char> test3;
    test3.push('c');
    test3.push('&');
    test3.pop();
    REQUIRE(test3.peek() == 'c');
    test3.push('=');
    test3.push('!');
    test3.pop();
    REQUIRE(test3.peek() == '=');
}

TEST_CASE("empty", "[DSStack_Array]")
{
    DSStack_Array<int> test1;
    REQUIRE(test1.empty() == true);
    test1.push(44);
    test1.push(99);
    REQUIRE(test1.empty() == false);
    test1.pop();
    test1.pop();
    REQUIRE(test1.empty() == true);
    test1.push(-7777777);
    test1.push(777);
    test1.push(4);
    test1.push(0);
    test1.pop();
    test1.pop();
    test1.pop();
    test1.pop();
    REQUIRE(test1.empty() == true);

    DSStack_Array<std::string> test2;
    test2.push("hi");
    test2.push("Grace");
    test2.pop();
    REQUIRE(test2.empty() == false);
    test2.pop();
    test2.push("hola");
    test2.pop();
    REQUIRE(test2.empty() == true);

    DSStack_Array<char> test3;
    REQUIRE(test3.empty() == true);
    test3.push('c');
    test3.push('&');
    test3.pop();
    test3.pop();
    test3.push('!');
    test3.pop();
    REQUIRE(test3.empty() == true);
}

TEST_CASE("peek", "[DSStack_Array]")
{
    DSStack_Array<int> test1;
    test1.push(44);
    test1.push(99);
    test1.pop();
    REQUIRE(test1.peek() == 44);
    test1.push(-7777777);
    test1.push(777);
    test1.push(4);
    test1.push(0);
    test1.pop();
    REQUIRE(test1.peek() == 4);

    DSStack_Array<std::string> test2;
    test2.push("hi");
    test2.push("Grace");
    test2.pop();
    REQUIRE(test2.peek() == "hi");
    test2.push("hola");
    test2.push("lol");
    test2.push("hello");
    test2.pop();
    REQUIRE(test2.peek() == "lol");

    DSStack_Array<char> test3;
    test3.push('c');
    test3.push('&');
    test3.pop();
    REQUIRE(test3.peek() == 'c');
    test3.push('=');
    test3.push('!');
    test3.pop();
    REQUIRE(test3.peek() == '=');
}
// you can run the test using Run CTest in the task bar or by running the tests executable.
