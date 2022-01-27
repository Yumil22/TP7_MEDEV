struct Huff_tree
{
    Huff_tree* fils0 = nullptr;
    Huff_tree* fils1 = nullptr;
    char val = '';
};

class Huffmann
{
public :
    Huff_tree* treeRoot;
    std::vector<std::byte> compressedMessage;

    Huffmann(std::string);
    Huff_tree* getTreeRoot();
    std::vector<std::byte> getByteCodes();
};