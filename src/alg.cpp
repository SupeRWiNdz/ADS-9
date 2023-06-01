// Copyright 2021 NNTU-CS
#include  "bst.h"

BST<std::string> makeTree(const char* filename) {
    std::ifstream file(filename);
    BST<std::string> tree;
    std::string text;
    if (file) {
        while (!file.eof()) {
            text.erase();
            while (true) {
                char chr = file.get();
                if (chr >= 'A' && chr < 'Z'
                   || chr >= 'a' && chr <= 'z')
                    text += tolower(chr);
                else
                    break;
                }
            if (!text.empty())
                tree.newNode(text);
        }
        file.close();
    } else {
        std::cout << "File error!" << std::endl;
    }
    return tree;
}
