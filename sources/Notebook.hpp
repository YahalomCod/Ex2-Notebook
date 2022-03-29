#include <iostream>
#include "Direction.hpp"
using namespace std;
#include <string>
#include <vector>
#include "Page.hpp"
#pragma once
namespace ariel{
    /*This Class represents a Notebook build represented a dynamic vector of pages*/
    class Notebook{
    public:
        vector<Page> pages ;
        Notebook(){
            ariel::Page *pag = new ariel::Page();
            pages.push_back(*pag);
        }

        void write( int page,  int row,  int culomn, Direction d, string const& data);
        string read( int page,  int row,  int culomn, Direction d,  int length);
        void erase( int page,  int row,  int culomn, Direction d,  int length);
        void  show( int page);
    };
};