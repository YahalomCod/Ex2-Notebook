#include "doctest.h"
#include "Notebook.hpp"
#include "Direction.hpp"
#include "doctest.h"
using namespace ariel;

#include <string>
#include <algorithm>
using namespace std;

TEST_CASE("Good input") {
    Direction hor = Direction::Horizontal;
    Direction ver = Direction::Vertical;
    Notebook note;
    CHECK(note.read(0, 2, 5, hor, 4) == "____");
    note.write(0, 0, 0, hor, "Hello World");
	CHECK(note.read(0, 0, 0, hor, 11) == "Hello World");

    note.erase(0, 0, 0, hor, 11);
    CHECK(note.read(0, 0, 0, hor, 11) == "~~~~~~~~~~~");
    
    note.erase(0, 0, 0, ver, 6);
    CHECK(note.read(0, 0, 0, ver, 8) == "~~~~~~__");

    note.write(1,1,1,ver,"Ani bobi boten");
    CHECK(note.read(1, 0, 1, ver, 15) == "_Ani bobi boten");
    
    note.write(1,0,0,hor,"are you writing this?");
    CHECK(note.read(1, 0, 0, hor, 22) == "are you writing this?_");
    note.erase(1, 0, 0, hor, 21);
    CHECK(note.read(1, 0, 0, hor, 5) == "~~~~~");

    CHECK(note.read(1, 0, 0, ver, 4) == "~___");
    note.erase(1,3,0,ver,1);
    CHECK(note.read(1, 0, 0, ver, 4) == "~__~");
    note.write(1,100,50,hor,"FIN");
    CHECK(note.read(1, 100, 49, hor, 5) == "_FIN_");
}

TEST_CASE("Bad input") {
    Direction hor = Direction::Horizontal;
    Direction ver = Direction::Vertical;
    Notebook note;
    CHECK_THROWS(note.write(1, 2, 99, hor, "FAIL"));
    CHECK_THROWS(note.write(0, 0, 101, ver, "FAIL"));
    note.write(0, 0, 0, ver, "WRITE THIS");
    CHECK_THROWS(note.write(0, 0, 0, ver, "CAN'T WRITE THIS"));
    note.erase(0,0,0,hor,10);
    CHECK_THROWS(note.write(0, 0, 0, hor, "Fail from failtown"));
    
    CHECK_THROWS(note.erase(12, 0, 100, hor, 3));
    CHECK_THROWS(note.erase(12, 0, 98, hor, 3));
    CHECK_THROWS(note.erase(12, 0, 101, ver, 3));

    CHECK_THROWS(note.read(1, 2, 99, hor, 2));
    CHECK_THROWS(note.read(1, 2, 100, ver, 5));
    CHECK_THROWS(note.read(1, 2, 102, ver, 5));

    CHECK_THROWS(note.read(-1, 2, 50, hor, 2));
    CHECK_THROWS(note.write(1, -2, 0, hor, "OP_TEST"));
    CHECK_THROWS(note.erase(1, 2, -42, hor, 2));

}