#include "Notebook.hpp"
#include <iostream>
#include <stdexcept>
#include "Page.hpp"
using namespace std;
#include <vector>
using namespace ariel;
#include <string>
const unsigned int limit = 100;
/*
This function checks if the input is legit or not
*/
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
/*
This function write inside a certain page of a notebook the if the page is not created yet so the function creates the pages
then send them to function write of the depertment Page
*/
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

/*
This function reads inside a certain page of a notebook the if the page is not created yet so the function creates the pages
then send them to function read of the depertment Page
*/
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

/*
This function erase inside a certain page of a notebook the if the page is not created yet so the function creates the pages
then send them to function erase of the depertment Page
*/
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
/*
This function shows inside a certain page of a notebook the if the page is not created yet so the function creates the pages
then runs on all the rows of a page reads a string of each row with the length of 100 with the read function of Page
*/
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