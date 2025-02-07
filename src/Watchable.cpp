//
// Created by shachafk@wincs.cs.bgu.ac.il on 19/11/2019.
//


#include "../include/Watchable.h"

//Rule of 3/5 TBD
Watchable::Watchable(long id, int length, const std::vector<std::string>& tags):id(id),length(length),tags(tags),type(0){} //id should be the location in the content vector
Watchable::Watchable(Watchable& Watchable):id(),length(),tags(),type(0) {copy(Watchable);}
Watchable::~Watchable() = default; // destructor



void Watchable::copy (Watchable& Watchable){
    id = Watchable.getId();
    length = Watchable.getLength();
    tags = Watchable.getTag();
}



//getters
long Watchable::getId() const {return this->id;}
int Watchable::getLength() const { return this->length;}
const std::vector<std::string> & Watchable::getTag() const {return this->tags;}
int Watchable::getType() const { return type;}


//setters
void Watchable::setType (int i){
    type =i;
}


