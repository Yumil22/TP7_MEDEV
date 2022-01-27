#include <iostream>
#include <vector>
#include "huff_tree.h"
using namespace std;

Huffmann::Huffmann(std::vector<std::string> messages) {
	treeRoot = new Huff_tree();
	compressedMessages = {};

	// TODO compléter les constructeur

}

Huff_tree* Huffmann::getTreeRoot() {
	return treeRoot;
}

std::vector<std::vector<bool>> Huffmann::getByteCodes() {
	return compressedMessages;
}

float Huffmann::getCompressionRatio()
{
    return sizeof(compressedMessages) / sizeof(messages);
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
