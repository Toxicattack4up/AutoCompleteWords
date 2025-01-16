
## Структура данных

Программа использует структуру **Trie** для хранения словарных данных. Trie представляет собой дерево, в котором каждый узел соответствует символу слова, и с помощью этой структуры можно эффективно искать слова, начинающиеся с данного префикса.

### Основные функции:

- `insert(root, word)` — вставка слова в дерево Trie.
- `searchPrefix(root, prefix)` — поиск узла, соответствующего последнему символу введенного префикса.
- `findWordsWithPrefix(node, current, result)` — рекурсивный поиск всех слов, начинающихся с заданного префикса.

## Установка

1. Склонируйте репозиторий: git clone https://github.com/yourusername/autocomplete-trie.git

2. Перейдите в директорию проекта: cd autocomplete-trie

3. Скомпилируйте программу:
Для Linux/macOS: g++ -o autocomplete autocomplete.cpp

Для Windows: g++ -o autocomplete autocomplete.cpp

4. Запустите программу: ./autocomplete

## Как использовать

1. При запуске программа запросит ввод префикса.
2. Введите префикс и программа выведет все слова, начинающиеся с этого префикса.
3. Для выхода из программы введите `exit`.
