//
// Created by roei on 12/01/2020.
//

#ifndef SECONDMILESTONE__FILECACHEMANAGER_H_
#define SECONDMILESTONE__FILECACHEMANAGER_H_

#include <stdio.h>
#include <string>
#include <vector>
#include <map>
#include <unordered_map>
#include <iostream>
#include <list>
#include <fstream>
#include <functional>
#include "CacheManager.h"

using namespace std;

//global to run the loop
template<typename P, typename S>
class FileCacheManager : public CacheManager<P, S> {
    unsigned int cacheSize;
    unordered_map<std::string, std::pair<S, typename list<P>::iterator>> cacheMemory;
    list<P> myList;

    void updateCache(P);
    void writeToFile(P, S);
    void deleteLRU();
    bool containsKey(P);
    void addToMap(P, S);

public:
    void insert(P, S);
    FileCacheManager(int);
    S get(P);

    void foreach(const function<void(S &)>);

};


//constructor
template<typename P, typename S>
FileCacheManager<P, S>::FileCacheManager(int size) {
    this->cacheSize = size;

}


//insert method
template<typename P, typename S>
void FileCacheManager<P, S>::insert(P key, S obj) {

    //check if the key is already in the cache
    if (this->containsKey(key)) {
        updateCache(key);
        //list<string>::iterator it = myList.begin();
        //update new obj and iterator
        list<string>::iterator it = myList.begin();
        cacheMemory[key] = {obj, it};
        // his key isnt it the cache
    } else {
        //first need to delete
        if (this->cacheMemory.size() == cacheSize) {
            deleteLRU();
            //add to map
            addToMap(key, obj);
        }
        if (this->cacheMemory.size() < cacheSize) {
            addToMap(key, obj);
        }
    }
    writeToFile(key, obj);
}


template<typename P, typename S>
S FileCacheManager<P, S>::get(P key) {
    //this key is in the cache
    if (this->containsKey(key)) {
        //we updated the LRU algorithm
        updateCache(key);
        //return our key object
        return cacheMemory[key].first;
    } else {
        //todo solve the class_name while writing and saving objct.
        //string b = S::class_name + key;
        string b = key;

        //todo solve the class_name while writing and saving objct.
        //std::ifstream reader(S::class_name + key, std::ios::binary);
        std::ifstream reader(key, std::ios::binary);
        if (!reader || !reader.is_open()) {
            throw "No such object";
        }
        S buffer;
        //reading out object from a file
        reader.read((char *) &buffer, sizeof(S));
        //check if file open currectly
        if (!reader) {
            throw "error happened in opening file for reading";
        }
        //check our cache size
        if (this->cacheMemory.size() == cacheSize) {
            deleteLRU();
            //add to map
            addToMap(key, buffer);
        } else {
            addToMap(key, buffer);
        }
        reader.close();
        //return wanted object
        return buffer;
    }
}



//update our cache order for existing key
template<typename P, typename S>
void FileCacheManager<P, S>::updateCache(P key) {
    //delete current key recently used from prev location.
    myList.erase(cacheMemory[key].second);
    //our last used key will be first now.
    myList.push_front(key);
}


template<typename P, typename S>
void FileCacheManager<P, S>::deleteLRU() {
    //delete last used item
    P buffer = myList.back();
    cacheMemory.erase(buffer);
    myList.pop_back();
}


template<typename P, typename S>
//check if out map contains th key.
bool FileCacheManager<P, S>::containsKey(P key) {
    typename std::unordered_map<std::string, std::pair<S,
            typename list<P>::iterator>>::iterator it
            = cacheMemory.find(key);
    if (it != cacheMemory.end()) {
        return true;
    }
    return false;
}


//add key value to the map with iterator.
template<typename P, typename S>
void FileCacheManager<P, S>::addToMap(P key, S value) {
    myList.push_front(key);
    typename list<P>::iterator it = myList.begin();
    cacheMemory[key] = {value, it};
}


template<typename P, typename S>
void FileCacheManager<P, S>::writeToFile(P key, S obj) {
    //open a stream for writing
    //todo solve the class name
    //std::ofstream writer(S::class_name + key, std::ios::binary | std::ofstream::trunc);
    std::ofstream writer(key, std::ios::binary | std::ofstream::trunc);

    if (!writer || !writer.is_open()) {
        throw "error happened in opening file for writing";
    }
    writer.write((char *) &obj, sizeof(obj));

    if (writer.fail()) {
        throw "Error happened in writing to file";
    }
    writer.close();
}


template<typename P, typename S>
void FileCacheManager<P, S>::foreach(const function<void(S &)> func) {
    for (auto i : myList) {
        func(cacheMemory[i].first);
    }
}

#endif //SECONDMILESTONE__FILECACHEMANAGER_H_
