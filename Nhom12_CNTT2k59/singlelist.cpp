#ifndef SINGLELIST_CPP
#define SINGLELIST_CPP 2
#include"node.cpp"

template<class T>

class singleList
{
	private:
		Node<T> *header;
		Node<T> *trailer;
		long n;
	public:
		singleList();
		long size();
		int isEmpty();
		Node<T> *first();// tra lai dia chi cho con tro header
		Node<T> *last();
		void replace(Node<T> *p, T e);
		void remove(Node<T> *p);
		Node<T> *insertAfter(Node<T>*p, T e);
		Node<T> *insertFirst(T e);
		Node<T> *insertLast(T e);
		Node<T> *getNode(int i);
		void sort();
		void delList();
};

template<class T>
singleList<T>::singleList()
{
	header = NULL;
	trailer = NULL;
	n = 0;
}

template<class T>
long singleList<T>::size()
{
	return n;
}

template<class T>
int singleList<T>::isEmpty()
{
	return n == 0;
}

template<class T>
Node<T> *singleList<T>::first()
{
	return header;
}

template<class T>
Node<T> *singleList<T>::last()
{
	return trailer;
}

template<class T>
void singleList<T>::replace(Node<T>*p, T e)
{
	p->setElem(e);
}

template<class T>
Node<T> *singleList<T>::insertAfter(Node<T> *p, T e)
{
	Node<T> *q;//1
	q = new Node<T>;//1
	if (q == NULL || p == NULL) return NULL;//3
	
	q->setElem(e);//1+1
	q->setnext(p->getnext());//1+1+1+1
	p->setnext(q);//1+1
	if (p == trailer) q = trailer;//1+1
	n++;//1
	
	return q;//1
}
//dpt 16

template<class T>
Node<T> *singleList<T>::insertFirst(T e)
{
	Node<T> *q;
	q = new Node<T>;
	if (q == NULL) return NULL;
	
	q->setElem(e);
	if(isEmpty())
	{
		header = q;
		trailer = q;
	}
	else 
	{
		q->setnext(header);
		header = q;
	}
	n++;
	
	return q;
}

template<class T>
Node<T> *singleList<T>::insertLast(T e)
{
	Node<T> *q;//1
	q = new Node<T>;//1
	if(q == NULL) return NULL;//2
	
	q->setElem(e);//(setElem dpt 1) dpt 1+1=2
	if(isEmpty())//1
	{
		header = q;//1
		trailer = q;//1
	}
	else 
	{
		trailer->setnext(q);//2
		trailer = q;//1
	}
	n++;//1
	
	return q;//1
	//1+1+2+2+1+1+1+2+1+1=13
}

template<class T>
void singleList<T>::remove(Node<T> *p)
{
	Node<T> *q;
	if(p == header)
	{
		if(size() == 1)
		{
			header = trailer = NULL;
		}
		else
		{
			header = header->getnext();
		}
	}
	else
	{
		q = header;
		while(q->getnext() != p) q=q->getnext();
		if(q != NULL)
		{
			if(p != trailer) q->setnext(p->getnext());
			else trailer = q;
		} 
	}
	n--;
	
	delete [] p;	
}

template<class T>
Node<T> *singleList<T>::getNode(int i)
{
	if(i < 0 || isEmpty()) return NULL;//4
	
	Node<T> *p;//1
	p = new Node<T>;//1
	p = header;//1
	int dem = 0;//2
	while(dem < i && p != NULL)//n
	{
		dem++;//n
		p=p->getnext();//3n
	}
	
	return p;//1
}

template<class T>
void singleList<T>::sort()
{
	for(Node<T> *p = header; p->getnext() != NULL; p = p->getnext())
	for(Node<T> *q = p->getnext(); q != NULL; q = q->getnext())
	{
		if(p->getElem() > q->getElem())
		{
			T a = p->getElem();
			p->setElem(q->getElem());
			q->setElem(a);
		}
	}
}

template<class T>
void singleList<T>::delList()
{
	Node<T> *H = header;
	Node<T> *Next;
	while(!H)
	{
		Next = H->getnext();
		free(H);
		H = Next;
	}
	H = NULL;
}
#endif
