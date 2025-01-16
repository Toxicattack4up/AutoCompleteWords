#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

const int ALPHABET_SIZE = 26;

// Структура узла Trie
struct TrieNode {
    unordered_map<char, TrieNode*> children;
    bool isEndOfWord;

    TrieNode() : isEndOfWord(false) {}
};

// Функция для вставки слова в Trie
void insert(TrieNode* root, const string& word) {
    TrieNode* node = root;
    for (char c : word) {
        if (node->children.find(c) == node->children.end()) {
            node->children[c] = new TrieNode();
        }
        node = node->children[c];
    }
    node->isEndOfWord = true;
}

// Функция для поиска узла по префиксу
TrieNode* searchPrefix(TrieNode* root, const string& prefix) {
    TrieNode* node = root;
    for (char c : prefix) {
        if (node->children.find(c) == node->children.end()) {
            return nullptr; // Префикс не найден
        }
        node = node->children[c];
    }
    return node;
}

// Рекурсивная функция для поиска всех слов с данным префиксом
void findWordsWithPrefix(TrieNode* node, string current, vector<string>& result) {
    if (node->isEndOfWord) {
        result.push_back(current); // Добавляем слово, если оно завершено
    }

    // Рекурсивно проходим по всем детям узла
    for (auto& child : node->children) {
        findWordsWithPrefix(child.second, current + child.first, result);
    }
}

int main() {
    setlocale(LC_ALL, "Russian");
    TrieNode* root = new TrieNode();
    vector<string> dictionary = { "dog", "dot", "dove", "duck", "cat", "call", "cult", "run", "rut", "answer", "hero", "heroplane", "the" };

    // Вставляем слова в Trie
    for (const string& word : dictionary) {
        insert(root, word);
    }

    string prefix;
    while (true) {
        cout << "Введите префикс для автодополнения (или 'exit' для выхода): ";
        getline(cin, prefix);

        if (prefix == "exit") {
            break;
        }

        // Ищем узел, соответствующий последнему символу префикса
        TrieNode* node = searchPrefix(root, prefix);

        if (!node) {
            cout << "Нет совпадений для префикса \"" << prefix << "\".\n";
        }
        else {
            vector<string> result;
            findWordsWithPrefix(node, prefix, result); // Ищем все слова с данным префиксом

            if (result.empty()) {
                cout << "Нет совпадений для префикса \"" << prefix << "\".\n";
            }
            else {
                cout << "Варианты для \"" << prefix << "\":\n";
                for (const string& word : result) {
                    cout << word << "\n";
                }
            }
        }
    }

    return 0;
}
