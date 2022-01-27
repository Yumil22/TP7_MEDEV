#include "huff_tree.h"

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
