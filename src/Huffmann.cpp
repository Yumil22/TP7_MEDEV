#include "huff_tree.h"

Huffmann::Huffmann(std::string) {
	treeRoot = new Huff_tree();
	compressedMessage = {};


}

Huff_tree* Huffmann::getTreeRoot() {
	return treeRoot;
}

td::vector<std::vector<bool>> Huffmann::getByteCodes() {
	return compressedMessage;
}

