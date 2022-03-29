//#include "sources/Direction.hpp"
#include "sources/Notebook.hpp"
// #include "sources/Notebook.cpp"
using namespace ariel;
using ariel::Direction;
#include <string>
int main(){
    ariel::Notebook notebook;
    notebook.write(1, 1, 10, Direction::Horizontal, "hell");
    notebook.write(1, 1, 8, Direction::Horizontal, "bye");
}