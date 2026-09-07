#include "bst.h"

int main() {
    SentinelBST tree;

    int q;
    std::cin >> q;

    while (q--) {
        std::string command;
        std::cin >> command;

        if (command == "I") {
            int x;
            std::cin >> x;
            tree.insert(x);
        }
        else if (command == "D") {
            int x;
            std::cin >> x;
            tree.erase(x);
        }
        else if (command == "S") {
            int x;
            std::cin >> x;
            std::cout << (tree.search(x) ? "FOUND" : "NOT FOUND") << "\n";
        }
        else if (command == "MIN") {
            int x;
            if (tree.minimum(x))
                std::cout << x << "\n";
            else
                std::cout << "NONE\n";
        }
        else if (command == "MAX") {
            int x;
            if (tree.maximum(x))
                std::cout << x << "\n";
            else
                std::cout << "NONE\n";
        }
        else if (command == "SUCC") {
            int x, result;
            std::cin >> x;
            if (tree.successor(x, result))
                std::cout << result << "\n";
            else
                std::cout << "NONE\n";
        }
        else if (command == "PRED") {
            int x, result;
            std::cin >> x;
            if (tree.predecessor(x, result))
                std::cout << result << "\n";
            else
                std::cout << "NONE\n";
        }
        else if (command == "HEIGHT") {
            std::cout << tree.height() << "\n";
        }
        else if (command == "PRINT") {
            std::vector<int> values = tree.inorder();
            for (size_t i = 0; i < values.size(); ++i) {
                if (i) std::cout << ' ';
                std::cout << values[i];
            }
            std::cout << "\n";
        }
        else if (command == "CLEAR") {
            tree.clear();
        }
    }

    return 0;
}
