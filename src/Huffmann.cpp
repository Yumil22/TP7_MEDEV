#include "huff_tree.h"

Huffmann::Huffmann(std::vector<std::string> messages) {
	treeRoot = new Huff_tree();
	compressedMessage = {};


}

Huff_tree* Huffmann::getTreeRoot() {
	return treeRoot;
}

std::vector<std::vector<bool>> Huffmann::getByteCodes() {
	return compressedMessages;
}

