#include <iostream>
#include <stdexcept>
#include "Page.hpp"
using namespace std;
#include <vector>
using namespace ariel;
#include <string>
const unsigned int limit = 100;

void Page::erase(int row, int culomn, Direction d, int length)const{
    unsigned int unrow = static_cast<unsigned int>(row);
    unsigned int uncul = static_cast<unsigned int>(culomn);
    unsigned int unlen = static_cast<unsigned int>(length);
    if(d == Direction::Horizontal){
        if(row >= (*rows).size()){
            unsigned int size = (*rows).size();
            (*rows).resize(unrow + 1);
            for (size_t j = size; j < unrow + 1; j++){    
                (*rows)[j].resize(limit);
                for (size_t i = 0; i < limit; i++){
                    (*rows)[j][i] = '_';
                }
            }
        }
        for (unsigned int i = uncul; i < unlen + uncul; i++){
            (*rows)[unrow][i] = '~';
        }
    }
    else{
        if(unrow + unlen >= (*rows).size()){
            (*rows).resize(unrow + unlen + 1);
            for (size_t j = unrow; j < unrow + unlen + 1; j++){    
                (*rows)[j].resize(limit);
                for (size_t i = 0; i < limit; i++){
                    (*rows)[j][i] = '_';
                } 
            }
        }
        for (unsigned int i = unrow; i < unrow + unlen; i++){
            (*rows)[i][uncul] = '~';
        }
    }
}

void Page::write( int row, int culomn, Direction d, string const& data)const{
    unsigned int unrow = static_cast<unsigned int>(row);
    unsigned int uncul = static_cast<unsigned int>(culomn);
    if(d == Direction::Horizontal){
        if(row >= (*rows).size()){
            unsigned int size = (*rows).size();
            (*rows).resize(unrow + 1);
            for (size_t j = size; j < unrow + 1; j++){    
                (*rows)[j].resize(limit);
                for (size_t i = 0; i < limit; i++){
                    (*rows)[j][i] = '_';
                }
            }
        }
        for (unsigned int i = 0; i < data.size(); i++){
            if((*rows)[unrow][i + uncul] == '_'){
                (*rows)[unrow][i + uncul] = data.at(i);
            }
            else{
                throw invalid_argument("Can't write in a written/erased place");
            }
        }
    }
    else{
        if(unrow + data.size() >= (*rows).size()){
            unsigned int size = (*rows).size();
            (*rows).resize(unrow + data.size() + 1);
            for (size_t j = size; j < unrow + data.size()+1; j++){    
                (*rows)[j].resize(limit);
                for (size_t i = 0; i < limit; i++){
                    (*rows)[j][i] = '_';
                } 
            }
        }
        for (unsigned int i = 0; i < data.size(); i++){
            if((*rows)[i + unrow][uncul] == '_'){
                (*rows)[i + unrow][uncul] = data.at(i);
            }
            else{
                throw invalid_argument("Can't write in a written/erased place");
            }
        }
    }
}

string Page::read ( int row, int culomn, Direction d, int length)const{
    string ans;
    unsigned int unrow = static_cast<unsigned int>(row);
    unsigned int uncul = static_cast<unsigned int>(culomn);
    unsigned int unlen = static_cast<unsigned int>(length);
    if(d == Direction::Horizontal){
        if(row >= (*rows).size()){
            unsigned int size = (*rows).size();
            (*rows).resize(unrow+1);
            for (size_t j = size; j < row+1; j++){
                (*rows)[j].resize(limit);
                for (size_t i = 0; i < limit; i++){
                    (*rows)[j][i] = '_';
                }
            }
        }
        for (unsigned int i = uncul; i < unlen + uncul; i++){
            char temp = (*rows)[unrow][i];
            ans += temp;
        }
    }
    else{
        if(unrow + unlen >= (*rows).size()){
            unsigned int size = (*rows).size();
            (*rows).resize(unrow + unlen + 1);
            for (size_t j = size; j < unrow + unlen + 1; j++){    
                (*rows)[j].resize(limit);
                for (size_t i = 0; i < limit; i++){
                    (*rows)[j][i] = '_';
                }
            }
        }
        for (unsigned int i = unrow; i < unlen + unrow; i++){
            ans += (*rows)[i][uncul];
        }
    }
    return ans;
}
