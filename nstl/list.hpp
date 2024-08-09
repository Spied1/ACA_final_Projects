#pragma once

template<typename T>
struct node
{
	node* m_next{};
	T m_val{};

	node(T val) : m_val(val), m_next(nullptr) {}
};

template<typename T>
class list
{
private:
	node<T>* m_head;
public:
	list() : m_head(nullptr) {}

	~list() {
		while (m_head) {
			node<T>* temp = m_head;
			m_head = m_head->m_next;
			delete temp;
		}
	}

	void push_front(T val)
	{
		node<T>* newNode = new node<T>(val);
		if (m_head == nullptr)
		{
			m_head = newNode;
		}
		else
		{
			node<T>* current = m_head;
			while (current->m_next != nullptr)
			{
				current = current->m_next;
			}
			current->m_next = newNode;
		}
	}

	void pop_front()
	{
		if (m_head == nullptr)
		{
			return;
		}

		node<T>* temp = m_head;
		m_head = m_head->m_next;
		delete temp;
	}

	void insert(T val, size_t i)
	{
		node<T>* newNode = new node<T>(val);
		if (m_head == nullptr)
		{
			m_head = newNode;
			return;
		}

		if (i == 0) {
			newNode->m_next = m_head;
			m_head = newNode;
			return;
		}

		size_t temp = 0;
		node<T>* current = m_head;
		while (temp < i - 1 && current->m_next != nullptr)
		{
			current = current->m_next;
			temp++;
		}
		newNode->m_next = current->m_next;
		current->m_next = newNode;
	}

	void reverse()
	{
		node<T>* previous = nullptr;
		node<T>* current = m_head;
		node<T>* next = nullptr;

		while (current != nullptr)
		{
			next = current->m_next;
			current->m_next = previous;
			previous = current;
			current = next;
		}
		m_head = previous;
	}

	class iterator
	{
	private:
		node<T>* m_current;
	public:

		iterator(node<T>* start) : m_current(start) {}

		T& operator*()
		{
			return m_current->m_val;
		}

		iterator& operator++()
		{
			m_current = m_current->m_next;
			return *this;
		}

		bool operator!=(const iterator& other)
		{
			return m_current != other.m_current;
		}

		bool operator==(const iterator& other)
		{
			return m_current == other.m_current;
		}
	};

	iterator begin()
	{
		return iterator(m_head);
	}

	iterator end()
	{
		return iterator(nullptr);
	}
};
