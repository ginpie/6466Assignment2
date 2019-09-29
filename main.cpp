//============================================================================
// Name        : COMP6466.cpp
// Author      : Jinpei Chen
// uID		   : u6743886
// Version     :
// Copyright   :
// Description : Interval overlapping algorithm in C++, Ansi-style
//============================================================================

#include<iostream>
#include<fstream>
#include<string>
#include <vector>
#include <chrono>
#include <ctime>
#include "rbtree_template.h"
using namespace std;


int main(int argc,char **argv){
	if (argc!=2){
		cout<<"Error: Input file not specified or too many arguments"<<endl<<"Usage: Program FileName"<<endl;
		return -1;
	}
	ifstream fin(argv[1]);
	// Check if file has been opened properly
	if (!fin.is_open()){
		cout<<"Error: input file cannot be opened"<<endl;
		return -1;
	}

    // duration count starts
    auto start = std::chrono::system_clock::now();

    // construct a RB tree of all time indices as node
    RBTree<int,Attribute> treeIndex;
    int numIndex = 145;
    Attribute *a = new Attribute;
    a->maxValue=0;
    a->value=0;
    std::vector<int> l;
    a->lec = l;
    for (int i=1; i<=numIndex; i++){
        treeIndex.insert(i,*a);
    }
    // end construct

    // count number of lectures ongoing at each index
    int numLect;
    fin >> numLect;
    std::vector<int> startIndex(numLect), endIndex(numLect);
    int index;
    for (int i=0; i<numLect; i++){
        fin >> index >> startIndex[i] >> endIndex[i];
    }

    // update the value of all indices, add 1 on index value if there is lecture ongoing
    for (int i=0; i<numLect; i++){
        for (int j=startIndex[i]; j<endIndex[i]; j++){
            Node<int,Attribute> *idx = treeIndex.search(j);
            idx->value.value += 1;
            idx->value.lec.push_back(i+1);
            if (idx->value.maxValue < idx->value.value) {
                idx->value.maxValue = idx->value.value;
                idx->value.maxIndex = idx->key;
                idx->value.maxLec = idx->value.lec;
            }
            // update all the max value on the path from the changed node to root
            while (idx->parent != NULL && idx->parent->value.maxValue < idx->value.maxValue){
                idx->parent->value.maxValue = idx->value.maxValue;
                idx = idx->parent;
            }
        }
    }

    fin.close();
    treeIndex.print();

    // print results
    std::cout << "Result: \n" << treeIndex.root()->value.maxValue << endl;

    // duration count ends
    auto end = std::chrono::system_clock::now();
    std::chrono::duration<double> elapsed_seconds = end-start;
    std::time_t end_time = std::chrono::system_clock::to_time_t(end);
    std::cout << "finished computation at " << std::ctime(&end_time)
              << "elapsed time: " << elapsed_seconds.count() << "s\n";
}
