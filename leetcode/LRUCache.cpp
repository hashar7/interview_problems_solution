#include <iostream>
#include <map>

/*
Design a data structure that follows the constraints of a Least Recently Used (LRU) cache.

Implement the LRUCache class:

LRUCache(int capacity) Initialize the LRU cache with positive size capacity.
int get(int key) Return the value of the key if the key exists, otherwise return -1.
void put(int key, int value) Update the value of the key if the key exists. Otherwise, add the key-value pair to the cache. If the number of keys exceeds the capacity from this operation, evict the least recently used key.
The functions get and put must each run in O(1) average time complexity.
 */

struct Node {
private:
    int     key;
    int     val;
    Node*   next;
    Node*   prev;
public:
    Node(int k, int v) :
        key(k), val(v),
        next(nullptr),
        prev(nullptr) {}

    int getKey() const {
        return key;
    }

    void setKey(int key) {
        Node::key = key;
    }

    int getVal() const {
        return val;
    }

    void setVal(int val) {
        Node::val = val;
    }

    Node *getNext() const {
        return next;
    }

    void setNext(Node *next) {
        Node::next = next;
    }

    Node *getPrev() const {
        return prev;
    }

    void setPrev(Node *prev) {
        Node::prev = prev;
    }

};

class FixedSizeDoubleLinkedList {
private:
    Node*   head;
    Node*   tail;
    size_t  max_size;
    size_t  cur_size;
public:
    FixedSizeDoubleLinkedList(int key, int val, size_t max_sz):
        head(new Node(key, val)),
        tail(head), max_size(max_sz),
        cur_size(1) {}

    Node *getHead() const {
        return head;
    }

    void setHead(Node *head) {
        FixedSizeDoubleLinkedList::head = head;
    }

    Node *getTail() const {
        return tail;
    }

    void setTail(Node *tail) {
        FixedSizeDoubleLinkedList::tail = tail;
    }

    size_t getMaxSize() const {
        return max_size;
    }

    void setMaxSize(size_t maxSize) {
        max_size = maxSize;
    }

    size_t getCurSize() const {
        return cur_size;
    }

    void setCurSize(size_t curSize) {
        cur_size = curSize;
    }

    Node* push_front(Node* node) {
        if (cur_size == 0) {
            head = node;
            tail = head;
            head->setPrev(nullptr);
            head->setNext(nullptr);
            return nullptr;
        }
        if (cur_size++ < max_size) {
            head->setPrev(node);
            node->setNext(head);
            node->setPrev(nullptr);
            head = node;
            return nullptr;
        }
        head->setPrev(node);
        node->setNext(head);
        head = node;
        Node* tmp = tail;
        tail = tail->getPrev();
        tail->setNext(nullptr);
        return tmp;
    }

    void move_to_front(Node* node) {
        if (node == head) {
            return;
        }
        if (node == tail) {
            tail = tail->getPrev();
            tail->setNext(nullptr);
            head->setPrev(node);
            node->setNext(head);
            node->setPrev(nullptr);
            head = node;
            return;
        }
        node->getPrev()->setNext(node->getNext());
        node->getNext()->setPrev(node->getPrev());
        head->setPrev(node);
        node->setNext(head);
        node->setPrev(nullptr);
        head = node;
    }

    void print_list() {
        std::cout << "list:" << std::endl;
        for (auto i = head; i != nullptr; i = i->getNext()) {
            std::cout << " " << i->getKey() << "-" << i->getVal();
        }
        std::cout << std::endl;
    }

};

class LRUCache {
private:
    std::map<int, Node*> cache;
    FixedSizeDoubleLinkedList* list;
    int capacity;

public:
    LRUCache(int cap) : capacity(cap), list(nullptr) {}

    int get(int key) {
        if (cache.find(key) == cache.end()) {
            return -1;
        }
        Node* tmp = cache.find(key)->second;
        list->move_to_front(tmp);
        return tmp->getVal();
    }

    void put(int key, int value) {
        if (list == nullptr) {
            list = new FixedSizeDoubleLinkedList(key, value, capacity);
            cache.insert({key, list->getHead()});
            return;
        }
        if (cache.find(key) == cache.end()) {
            auto tmp = list->push_front(new Node(key, value));
            if (tmp != nullptr) {
                cache.erase(tmp->getKey());
                delete tmp;
            }
            cache.insert({key, list->getHead()});
            return;
        }
        cache[key]->setVal(value);
        list->move_to_front(cache[key]);
    }

    void print_cache() {
        list->print_list();
        auto it = this->cache.begin();
        while (it != this->cache.end()) {
            std::cout << "(key: " << it->first << ", value: " << it->second->getVal() << ") ";
            ++it;
        }
        std::cout << std::endl;
    }

};

int main() {
  return 0;
}
