//
// Created by victor21 on 28.09.2021.
//

#ifndef WORD1_BST_H
#define WORD1_BST_H
struct tnode {                // узел дерева
    char* word;                  // указатель на строку (слово)
    int count;                   // число вхождений
    struct tnode* left;          // левый потомок
    struct tnode* right;         // правый потомок
};
// Функция добавления узла к дереву
struct tnode* addtree(struct tnode* root, char* word) {

    int comp_res; // результат сравнения строк
    if (root == NULL) { //если дерева нет, то создаем
        root = (struct tnode*)malloc(sizeof(struct tnode)); //возращает указатель на начало структуры (костыль из C)
        root->word = strdup(word); //возращает указатель на слово (костыль из C)
        root->count = 1;
        root->left = root->right = NULL;
    }
    else if ((comp_res = strcmp(word, root->word)) == 0) //слова равны (костыль из C)
        root->count++;
    else if (comp_res < 0) //заходим в левое поддерево
        root->left = addtree(root->left, word); //рекурсивно вызываем создание поддерева
    else
        root->right = addtree(root->right, word); //заходим в правое дерево и рекурсивно вызываем создание поддерева
    return root; //корень
}
// Функция удаления поддерева
void freemem(tnode* tree) {
    if (tree != NULL) {
        freemem(tree->left);
        freemem(tree->right);
        free(tree->word);
        free(tree);
    }
}
// Функция вывода дерева с рекурсивным проходом левая ветка-корень-правая ветка
void treeprint(struct tnode* word) {
    if (word != NULL) {
        treeprint(word->left);
        printf("%d %s\n", word->count, word->word);
        if (max1 == NULL or word->count >= max1->count) { //выявляем слова с наибольшим количеством вхождений
            max3 = max2;
            max2 = max1;
            max1 = word;
        }
        else if (max2 == NULL or word->count >= max2->count) {
            max3 = max2;
            max2 = word;
        }
        else if (max2 == NULL or word->count >= max3->count) {
            max3 = word;
        }
        treeprint(word->right);
    }
}


#endif //WORD1_BST_H
