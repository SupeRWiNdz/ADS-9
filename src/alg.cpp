// Copyright 2021 NNTU-CS
#include <fstream>
#include  "bst.h"

BST<std::string> makeTree(const char* filename) {
    std::ifstream file(filename);
    BST<std::string> tree;
    std::string text;
    if (file) {
        while (file.eof() != 0) {
            text.erase();
            while (true) {
                char chr = file.get();
                if (chr >= 'A' && chr < 'Z') {
                    chr += 32;
                    text += chr;
                } else if (chr >= 'a' && chr <= 'z') {
                    text += chr;
                } else {
                    break;
                }
            }
            if (text.empty()) {
                continue;
            } else {
                tree.newNode(text);
            }
        }
        file.close();
    } else {
        std::cout << "File error!" << std::endl;
    }
    return tree;
}
