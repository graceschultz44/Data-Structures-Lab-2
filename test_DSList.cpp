#define CATCH_CONFIG_MAIN
#include "catch2/catch.hpp"
#include "DSList.h"

TEST_CASE("getSize", "[DSList]")
{
    DSList<int> test1;
    REQUIRE(test1.getSize() == 0);
    test1.insertBeginning(2);
    REQUIRE(test1.getSize() == 1);
    test1.removeLast();
    REQUIRE(test1.getSize() == 0);

    DSList<std::string> test2;
    REQUIRE(test2.getSize() == 0);
    test2.insertBeginning("HELLOOO");
    test2.insertEnd("hiiiii");
    test2.insertBeginning("HELLOOO");
    test2.insertEnd("hiiiii");
    test2.insertBeginning("HELLOOO");
    test2.insertEnd("hiiiii");
    test2.insertBeginning("HELLOOO");
    test2.insertEnd("hiiiii");
    test2.insertBeginning("HELLOOO");
    test2.insertEnd("hiiiii");
    REQUIRE(test2.getSize() == 10);

    DSList<char> test3;
    test3.insertBeginning('c');
    test3.insertBeginning('!');
    test3.insertBeginning('e');
    test3.insertBeginning('E');
    test3.insertBeginning('j');
    test3.insertBeginning('.');
    REQUIRE(test3.getSize() == 6);
}

TEST_CASE("empty", "[DSList]")
{
    DSList<int> test1;
    REQUIRE(test1.empty() == true);
    test1.insertBeginning(-100000000);
    test1.insertBeginning(0);
    test1.insertBeginning(1);
    REQUIRE(test1.empty() == false);
    test1.removeLast();
    test1.removeLast();
    test1.removeLast();
    REQUIRE(test1.empty() == true);

    DSList<std::string> test2;
    REQUIRE(test2.empty() == true);
    test2.insertEnd("HELLOOO");
    test2.insertEnd("HELLOOO");
    REQUIRE(test2.empty() == false);
    test2.removeLast();
    test2.removeLast();
    REQUIRE(test2.empty() == true);

    DSList<char> test3;
    REQUIRE(test3.empty() == true);
    test3.insertBeginning('!');
    test3.insertBeginning('c');
    test3.insertBeginning('E');
    test3.insertBeginning('g');
    test3.insertBeginning('!');
    test3.insertBeginning('?');
    REQUIRE(test3.empty() == false);
    test3.removeLast();
    test3.removeLast();
    test3.removeLast();
    test3.removeLast();
    test3.removeLast();
    test3.removeLast();
    REQUIRE(test3.empty() == true);
}

TEST_CASE("clear", "[DSList]")
{
    DSList<int> test1;
    test1.insertBeginning(-7777777);
    test1.insertBeginning(777);
    test1.insertBeginning(4);
    test1.insertBeginning(0);
    test1.clear();
    REQUIRE(test1.empty() == true);

    DSList<std::string> test2;
    test2.insertBeginning("HELLOOO");
    REQUIRE(test2.empty() == false);
    test2.clear();
    REQUIRE(test2.empty() == true);
    test2.insertBeginning("hi");
    test2.insertBeginning("Grace");
    test2.insertBeginning("hola");
    test2.insertBeginning("lol");
    test2.insertBeginning("hello");
    REQUIRE(test2.empty() == false);
    test2.clear();
    REQUIRE(test2.empty() == true);

    DSList<char> test3;
    test3.insertBeginning('!');
    test3.clear();
    REQUIRE(test3.empty() == true);
    test3.insertBeginning('&');
    test3.insertBeginning('c');
    test3.insertBeginning('!');
    test3.insertBeginning('!');
    REQUIRE(test3.empty() == false);
    test3.clear();
    REQUIRE(test3.empty() == true);
}

TEST_CASE("find", "[DSList]")
{
    DSList<int> test1;
    test1.insertEnd(44);
    test1.insertEnd(99);
    REQUIRE(test1.find(44) == 0);
    test1.insertBeginning(-7777777);
    test1.insertBeginning(777);
    test1.insertBeginning(4);
    test1.insertBeginning(0);
    REQUIRE(test1.find(777) == 2);

    DSList<std::string> test2;
    test2.insertBeginning("hi");
    test2.insertBeginning("Grace");
    test2.insertBeginning("hola");
    test2.insertBeginning("lol");
    test2.insertBeginning("hello");
    REQUIRE(test2.find("hi") == 4);

    DSList<char> test3;
    test3.insertBeginning('&');
    test3.insertBeginning('c');
    test3.insertBeginning('!');
    test3.insertBeginning('!');
    REQUIRE(test3.find('c') == 2);
}

TEST_CASE("insertBeginning", "[DSList]")
{
    DSList<int> test1;
    test1.insertBeginning(-111);
    test1.insertEnd(0);
    test1.insertEnd(100000000);
    REQUIRE(test1.find(-111) == 0);

    DSList<std::string> test2;
    test2.insertBeginning("hi");
    test2.insertBeginning("Grace");
    test2.insertBeginning("hola");
    test2.insertBeginning("lol");
    test2.insertBeginning("hello");
    REQUIRE(test2.find("hello") == 0);

    DSList<char> test3;
    test3.insertBeginning('&');
    test3.insertBeginning('c');
    test3.insertBeginning('=');
    test3.insertBeginning('!');
    REQUIRE(test3.find('!') == 0);
}

TEST_CASE("insertEnd", "[DSList]")
{
    DSList<int> test1;
    test1.insertEnd(44);
    test1.insertEnd(99);
    REQUIRE(test1.find(44) == 0);
    test1.insertBeginning(-7777777);
    test1.insertBeginning(777);
    test1.insertBeginning(4);
    test1.insertBeginning(0);
    REQUIRE(test1.find(99) == 5);

    DSList<std::string> test2;
    test2.insertBeginning("helloooo");
    test2.insertEnd("abcdefg");
    test2.insertEnd("lololololol");
    test2.insertEnd("hahahahahhaha");
    REQUIRE(test2.find("hahahahahhaha") == 3);

    DSList<char> test3;
    test3.insertEnd('&');
    test3.insertBeginning('c');
    test3.insertEnd('=');
    test3.insertEnd('!');
    REQUIRE(test3.find('!') == 3);
}

TEST_CASE("removeFirst", "[DSList]")
{
    DSList<int> test1;
    test1.insertEnd(44);
    test1.insertEnd(99);
    REQUIRE(test1.find(44) == 0);
    test1.insertBeginning(-7777777);
    test1.insertBeginning(777);
    test1.insertBeginning(4);
    test1.insertBeginning(0);
    test1.removeFirst();
    REQUIRE(test1.find(4) == 0);

    DSList<std::string> test2;
    test2.insertBeginning("hi");
    test2.insertBeginning("Grace");
    test2.insertBeginning("hola");
    test2.insertBeginning("lol");
    test2.insertBeginning("hello");
    test2.removeFirst();
    REQUIRE(test2.find("lol") == 0);

    DSList<char> test3;
    test3.insertBeginning('c');
    test3.insertEnd('&');
    test3.insertEnd('=');
    test3.insertEnd('!');
    test3.removeFirst();
    REQUIRE(test3.find('&') == 0);
}

TEST_CASE("removeLast", "[DSList]")
{
    DSList<int> test1;
    test1.insertBeginning(-7777777);
    test1.insertBeginning(777);
    test1.insertBeginning(4);
    test1.insertBeginning(0);
    test1.insertEnd(44);
    test1.insertEnd(99);
    test1.removeLast();
    REQUIRE(test1.getSize() == 5);

    DSList<std::string> test2;
    test2.insertBeginning("hi");
    test2.insertBeginning("Grace");
    test2.insertBeginning("hola");
    test2.insertBeginning("lol");
    test2.insertBeginning("hello");
    test2.removeLast();
    REQUIRE(test2.getSize() == 4);

    DSList<char> test3;
    test3.insertBeginning('c');
    test3.insertEnd('&');
    test3.insertEnd('=');
    test3.insertEnd('!');
    test3.removeLast();
    REQUIRE(test3.getSize() == 3);
}

TEST_CASE("brackets operator", "[DSList]")
{
    DSList<int> test1;
    test1.insertBeginning(-7777777);
    test1.insertBeginning(777);
    test1.insertBeginning(4);
    test1.insertBeginning(0);
    test1.insertEnd(44);
    test1.insertEnd(99);
    REQUIRE(test1[0] == 0);
    REQUIRE(test1[5] == 99);

    DSList<std::string> test2;
    test2.insertBeginning("hi");
    test2.insertBeginning("Grace");
    test2.insertBeginning("hola");
    test2.insertBeginning("lol");
    test2.insertBeginning("hello");
    REQUIRE(test2[0] == "hello");
    REQUIRE(test2[2] == "hola");
    REQUIRE(test2[4] == "hi");

    DSList<char> test3;
    test3.insertBeginning('c');
    test3.insertEnd('&');
    test3.insertEnd('=');
    test3.insertEnd('!');
    REQUIRE(test3[0] == 'c');
    REQUIRE(test3[3] == '!');
}
