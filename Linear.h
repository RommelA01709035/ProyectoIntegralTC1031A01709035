#ifndef LINEAR_H
#define LINEAR_H

#include <functional>
#include <iostream>
#include <vector>

template <class Key, class Value> class Linear {
private:
  struct Node {
    Key key;
    Value value;
    bool filled;

    Node() : filled(false) {}
  };

  Node *table;
  unsigned int size;
  Key initialValue;
  std::hash<Key> hashFunction;

public:
  Linear(unsigned int tableSize, Key initial)
      : size(tableSize), initialValue(initial) {
    table = new Node[size];
  }

  ~Linear() { delete[] table; }

  void put(const Key &key, const Value &value) {
    unsigned int index = hashFunction(key) % size;
    unsigned int originalIndex = index;

    while (table[index].filled) {
      index = (index + 1) % size;
      if (index == originalIndex) {

        std::cerr << "Error: Tabla llena" << std::endl;
        return;
      }
    }

    table[index].key = key;
    table[index].value = value;
    table[index].filled = true;
  }

  Value get(const Key &key) {
    unsigned int index = hashFunction(key) % size;
    unsigned int originalIndex = index;

    while (table[index].filled) {
      if (table[index].key == key) {
        return table[index].value;
      }

      index = (index + 1) % size;
      if (index == originalIndex) {
        throw std::runtime_error("Key not found");
      }
    }

    throw std::runtime_error("Key not found");
  }
  std::string toString() const {
    std::stringstream aux;
    for (unsigned int i = 0; i < size; i++) {
      if (table[i].filled) {
        aux << "(" << i << " " << table[i].key << " : "
            << "Nombre: " << table[i].value.getNombre()
            << ", Liga: " << table[i].value.getLiga()
            << ", Valor: " << table[i].value.getValor()
            << ", Goles: " << table[i].value.getGoles() << ") ";
      }
    }
    return aux.str();
  }
};

#endif
