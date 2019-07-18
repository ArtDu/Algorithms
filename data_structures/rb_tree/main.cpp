#include <iostream>
#include <cstring>
#include "TTree.h"
#include <ctime>

int main() {

    TTree tree;

    string op;
    string key;
    uint64_t val;

    while(cin >> op) {

        if (op == "+") {
            cin >> key;
            cin >> val;
            tree.Insert(key, val);
        }
        else if (op == "-") {
            cin >> key;
            tree.DeleteNode(key);
        }

    }
    tree.PrintTree();


    return 0;
}
