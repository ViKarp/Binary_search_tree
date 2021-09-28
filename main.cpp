#include <ctype.h>
#include <string.h>
#include <string>
#include <iostream>
#include <fstream>
#include "Struct.h"

int main() {
    struct tnode* root;
    root = NULL; //корень
    std::ifstream inf("/home/victor21/CLionProjects/untitled/text");
    std::string st;
    if (inf.is_open()) {
        while (inf >> st) {
            transform(st.begin(), st.end(), st.begin(), ::tolower); //переводим в нижний регистр
            st.erase(std::remove_if(st.begin(), st.end(), ispunct), st.end()); //удаляем знаки пунктуации
            root = addtree(root, st.data()); //создаем дерево, переводя строку обратно в char
        }
    }
    treeprint(root); //вывод дерева
    std::cout << "Больше всего встречалось слово: "<< max1->word
              <<' '<< max1->count<<std::endl
              << "Далее: " << max2->word << ' ' << max2->count<<std::endl
              << "На третьем месте: " << max3->word << ' ' << max3->count << std::endl;
    freemem(root); //удаляем все дерево
    return 0;
}