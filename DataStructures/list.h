#pragma once
#include <iostream>

namespace dc
{
	template<typename T>
	class list
	{
	private:
		struct node_t
		{
			node_t(const T& value) : _value{ value } {}

			T _value;
			node_t* _next{ nullptr }; // -> &address
			node_t* _prev{ nullptr }; // -> &address
		};

	public:
		list() {}
		list(const std::initializer_list<T>& ilist)
		{
			for (auto iter = ilist.begin(); iter != ilist.end(); iter++)
			{
				push_back(*iter);
			}
		}
		list& operator = (const list& other)
		{
			clear();

			node_t* node = other._head;
			while (node)
			{
				push_back(node->_value);
				node = node->_next;
			}
		
		}

		void push_front(const T& value)
		{
			node_t* new_node = new node_t(value);
			if (_head)
			{
				_head->_prev = new_node;
			}
			new_node->_next = _head;
			_head = new_node;
		}

		void pop_front()
		{
			if (_head)
			{
				node_t* temp_node = _head;
				_head = _head->_next;
				if (_head)
				{
					_head->_prev = nullptr;
				}
				delete temp_node;
			}
		}

		void push_back(const T& value)
		{
			node_t* new_node = new node_t(value);
			if (_head == nullptr)
			{
				_head = new_node;
			}
			else
			{
				node_t* tail_node = tail();
				tail_node->_next = new_node;
				new_node->_prev = tail_node;
			}
		}

		void pop_back()
		{
			node_t* tail_node = tail();
			if (tail_node)
			{
				node_t* prev_node = tail_node->_prev;
				if (prev_node) prev_node->_next = nullptr;
				if (tail_node == _head) _head == nullptr;
				delete prev_node;
			}
		}

		std::ostream& write(std::ostream& stream)
		{
			node_t* node = _head;
			while (node)
			{
				stream << node->_value << " ";
				node = node->_next;
			}
			stream << std::endl;

			return stream;
		}

		T& front()
		{
			return _head->_value;
		}

		const T& front() const
		{
			return _head->_value;
		}

		T& back()
		{
			return tail()->_value;
		}

		const T& back() const
		{
			return tail()->_value;
		}

		void resize(size_t new_size, const T& value)
		{
			node_t* node = new node_t(value);

			while (new_size < size())
			{
				pop_back();
			}
			while (new_size > size())
			{
				push_back(value);
			}
		}

		void clear()
		{
			node_t* node = _head;
			while (node)
			{
				node_t* next_node = node->_next;
				delete node;
				node = next_node;
			}
			_head = nullptr;
		}
		/*void remove()
		{

		}

		void reverse()
		{

		}*/

		size_t size()
		{
			size_t size = 0;
			node_t* node = _head;
			while (node)
			{
				size++;
				node = node->_next;
			}

			return size;
		}

		bool empty() { return (_head == nullptr); }

	private:
		node_t* tail()
		{
			node_t* node = _head;
			while (node && node->_next)
			{
				node = node->_next;
			}

			return node;
		}

	private:
		node_t* _head{ nullptr };
	};
}
