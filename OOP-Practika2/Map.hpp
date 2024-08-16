#ifndef _MAP_HPP
#define _MAP_HPP
#include<iostream>
#include<exception>
#include<initializer_list>

template<typename ANY1, typename ANY2>
class Map {
private:
	struct Node {
		ANY1 m_key = ANY1();
		ANY2 m_value = ANY2();
	};
	Node* node;
	size_t length;
public:
	Map() : node(nullptr), length(0) {}
	Map(const Map& other) : length(other.length) {
		if (length == 0) {
			node = nullptr;			
			return;
		}
		node = new Node[length]{};
		for (size_t i{}; i < length; ++i) {
			node[i] = other.node[i];			
		}		
	}
	/*
	Map(size_t size) : length(size) {
		node = new Node[length];
	}
	Map(const std::initializer_list<ANY1, ANY2>& init) : Map(init.size()){
		for (size_t i{}; i < length; ++i)
			node[i] = init[i];
	}*/
	~Map() {
		delete[] node;
	}
	// метод, кот. принимает ключ и значение, и добавляет их в новый элемент,
	// также осущ. проверку от повторение ключей:
	void setItem(const ANY1 key, const ANY2 value) {
		if (length == 0) {
			//std::cout << "Prog1\n";

			Node* new_node = new Node[1];
			new_node[0].m_key = key;
			new_node[0].m_value = value;
			node = new_node;
			++length;
			return;
		}
		// Добавить проверку
		for (size_t i{}; i < length; ++i) {
			if (key == node[i].m_key) {
				//std::cout << "Prog2\n";
				return;
			}
		}
		//std::cout << "Prog3\n";
		Node* new_node = new Node[length + 1];
		for (size_t i{}; i < length; ++i) {
			new_node[i] = node[i];
		}
		delete[] node;
		node = new_node;
		node[length].m_key = key;
		node[length].m_value = value;
		++length;
	}
	// метод возвращает ссылку на значение, переданного ключа:
	const ANY2& operator[](const ANY1& key)const {
		if (length == 0)
			return ANY2();	// ANY2()		
		for (size_t i{}; i < size(); ++i) {
			if (key == node[i].m_key) {
				//std::cout << "Prog4\n";
				return node[i].m_value;
			}			
		}
		//std::cout << "Prog5\n";
		return ANY2();	// ANY2()
	}
	// метод, возвращающий размер коллекции:
	size_t size()const {
		return length;
	}
	
	// метод очищает коллекцию:
	void clear() {
		delete[] node;
		node = nullptr;
		length = 0;
	}
};

#endif // _MAP_HPP
