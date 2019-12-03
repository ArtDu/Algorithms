#include <iostream>
#include <cstring>
#include <vector>
#include "TTree.h"
#include <ctime>


int main() {

    srand(time(NULL));
    vector<int64_t > randInts(101,0);

    TTree tree;

    string plus;
    uint64_t key;
    uint64_t pr;

    while(cin >>plus) {
        if (plus == "+") {
            cin >> key;
            while (true) {
                pr = (rand() % 100) + 1;
                if (randInts[pr] == 0) {
                    randInts[pr] = 1;
                    break;
                }
            }
            tree.InsertMS(key, pr);
        }
        else if (plus == "-") {
            cin >> key;
            tree.DeleteMS(key);
        }

    }

    tree.PrintTree();

    return 0;
}
