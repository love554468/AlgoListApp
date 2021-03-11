#ifndef NODE_CPP
#define NODE_CPP 1
#include<bits/stdc++.h>

using namespace std;

template <class T>
class Node
{
	private:
		T Elem;
		Node *Next;
	public:
		Node();
		Node *getnext();// tra lai dia chi node ke tiep
		void setnext(Node<T>*);
		T getElem();
		void setElem(T);	
};

template<class T>
Node<T>::Node()
{
	Next = NULL;
}

template<class T>
Node<T> *Node<T>::getnext()
{
	return Next;
}

template<class T>
void Node<T>::setnext(Node<T>*p )
{
	Next = p;
}

template<class T>
T Node<T>::getElem()
{
	return Elem;
}

template<class T>
void Node<T>::setElem(T e)
{
	Elem = e;//1
}
#endif
