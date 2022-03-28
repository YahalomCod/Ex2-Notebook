#include "Notebook.hpp"
#include <iostream>
#include <stdexcept>
#include "Page.hpp"
using namespace std;
#include <vector>
using namespace ariel;
#include <string>
const unsigned int limit = 100;
void check_input(int page_num, int row, int culomn, Direction d, string const &data = ""){
    if(culomn >= limit){
        throw invalid_argument("Culomn must be lower then 99");
    }
    if(culomn >= limit -data.size() && d == Direction::Horizontal){
        throw invalid_argument("Data extands row boundries");
    }
    if(page_num < 0 || row < 0 || culomn < 0){
        throw invalid_argument("page rows and culomns must be positive");
    }
    for(size_t i = 0; i < data.size(); i++){
        if(data.at(i) < '!' || data.at(i) >= '~'){
            if(data.at(i) != ' '){
                throw std :: invalid_argument("ASCII value of chars needs to be between 33-126");
            }
        }
    }
}

void check_input(int page_num, int row, int culomn, Direction d, int length){
    if(culomn >= limit){
        throw invalid_argument("Culomn must be lower then 99");
    }
    if(culomn + length - 1 >= limit && d == Direction::Horizontal){
        throw invalid_argument("Data extands row boundries");
    }
    if(page_num < 0 || row < 0 || culomn < 0){
        throw invalid_argument("page rows and culomns must be positive");
    }
}

void Notebook::write(int page_num, int row, int culomn, Direction d, string const &data){
    check_input(page_num, row, culomn, d, data);
    if(pages.size() <= page_num){
        unsigned int size = pages.size();
        for (size_t i = size; i < page_num+1; i++){
            ariel::Page *pag = new ariel::Page();
            pages.push_back(*pag);
        }
    }
    pages[static_cast<unsigned int>(page_num)].write(row, culomn, d, data);
}

string Notebook::read(int page, int row, int culomn, Direction d, int length){
    check_input(page,row,culomn,d,length);
    if(pages.size() <= page){
        unsigned int size = pages.size();
        for (size_t i = size; i < page+1; i++){
            ariel::Page *pag = new ariel::Page();
            pages.push_back(*pag);
        }
    }
    return pages[static_cast<unsigned int>(page)].read(row,culomn,d,length);
}

void Notebook::erase(int page, int row, int culomn, Direction d, int length){
    check_input(page,row,culomn,d,length);
    if(pages.size() <= page){
        unsigned int size = pages.size();
        for (size_t i = size; i < page+1; i++){
            ariel::Page *pag = new ariel::Page();
            pages.push_back(*pag);
        }
    }
    pages[static_cast<unsigned int>(page)].erase(row, culomn, d, length);
}

void Page::show()const{
    for(size_t i = 0; i < (*rows).size(); i++){
        cout << i << this->read(i,0,Direction::Horizontal,limit) << endl;
    }
}
void Notebook::show(int page){
    if(page < 0 ){
        throw invalid_argument("page rows and culomns must be positive");
    }
    if(page >= pages.size()){
        unsigned int size = pages.size();
        for (size_t i = size; i < page+1; i++){
            ariel::Page *pag = new ariel::Page();
            pages.push_back(*pag);
        }
    }
    unsigned int upage = static_cast<unsigned int>(page);
    for (size_t i = 0; i < pages[upage].rows->size(); i++){
        cout << i << pages[upage].read(i,0,Direction::Horizontal,limit) << endl;
    }
}