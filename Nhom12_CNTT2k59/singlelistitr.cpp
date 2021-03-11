#ifndef SINGLE_LIST_ITR
#define SINGLE_LIST_ITR 3
#include"singlelist.cpp"

template<class T>

class singleListItr
{
	private:
		singleList<T> *slist;
		Node<T> *curNode;
	public:
		singleListItr(singleList<T> *list)
		{
			slist = list;
			curNode = slist->first();
		}
		void resest()
		{
			curNode = slist->first();
		}
		int hasnext()
		{
			return curNode != NULL;
		}
		T next()
		{
			T e;
			e = curNode->getElem();
			curNode = curNode -> getnext();
			return e;
		}
};
#endif
