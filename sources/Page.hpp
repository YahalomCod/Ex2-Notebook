#include <iostream>
#include "Direction.hpp"
using namespace std;
#include <string>
#include <vector>
#pragma once
namespace ariel{
    /*This class represents a page inside the notebook builds from 2D char dynaminc vector*/
    class Page{
        public:
            vector<vector<char>> *rows ;
            Page(){
                rows = new vector<vector<char>> (1, vector<char>( 100, 0)) ;
                for (size_t i = 0; i < 100; i++)
                {
                   (*rows)[0][i] = '_';
                }
            }

            void write( int row,  int culomn, Direction d, string const& data)const;
            string read ( int row,  int culomn, Direction d,  int length)const;
            void erase( int row,  int culomn, Direction d,  int length)const;
    };
    
}