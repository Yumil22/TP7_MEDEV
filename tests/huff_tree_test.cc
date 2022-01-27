#include <gtest/gtest.h>
#include "iostream"
#include "huff_tree.h"

// Demonstrate some basic assertions.
TEST(test_huff_tree, TestDecodage) {

    std::string phrase ="MAMAN";
    std::string decoded_phrase;
    /*Huffmann huff_graph = Huffmann(phrase);

    std::vector<bool> list_bool = huff_graph.getByteCodes();
    */

    Huff_tree* m;
    m->val = 'M';
    Huff_tree* n;
    n->val = 'N';
    Huff_tree* a;
    a->val = 'A';
    Huff_tree* node;
    node->fils0 = n;
    node->fils1 = a;
    Huff_tree* root;
    root->fils0 = m;
    root->fils1 = node;

    std::vector<bool> list_bool = {0,1,1,0,1,1,1,0};

    Huffmann huff({" "});
    decoded_phrase = huff.decodage_huff(list_bool,root);

	// Expect decoded phrase to be equal to phrase
	EXPECT_TRUE(phrase==decoded_phrase);
}