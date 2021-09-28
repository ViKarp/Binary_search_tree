#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include <string>
#include <cstddef>
#include <iostream>
#include <algorithm>
#include <fstream>
#include "BST.h"

#define MAXWORD 100000
struct tnode* max1 = NULL;
struct tnode* max2 = NULL;
struct tnode* max3 = NULL;


int main() {
    struct tnode* root;
    char word[MAXWORD];
    root = NULL; //корень
    while (word[0] != '0') { // условие выхода – ввод символа '0'
        scanf("%s", word, MAXWORD); //читать по строчке
        if (word[0] != '0') {
            std::string st = std::string(word); //переводим в строку
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
    getchar();
    return 0;
}