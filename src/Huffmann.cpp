#include <iostream>
#include <vector>
#include "huff_tree.h"
using namespace std;

Huffmann::Huffmann(std::string) {
	treeRoot = new Huff_tree();
	compressedMessage = {};


}

Huff_tree* Huffmann::getTreeRoot() {
	return treeRoot;
}

std::vector<std::byte> Huffmann::getByteCodes() {
	return compressedMessage;
}

string decodage_huff(vector<bool> list, Huff_tree* root){
    string res;
    int n = list.size();

    Huff_tree* ptr = root;

    int i=0;

    while(i<n){
        if(ptr->fils0 == nullptr || ptr->fils1 == nullptr){
            res.push_back(ptr->val);
            ptr = root;
        }
        else{
            if(list[i])
                ptr = ptr->fils1;
            else
                ptr = ptr->fils0;
        }
        i++;
    }

    return res;
}
