#include"node.cpp"
#include"singlelist.cpp"
#include"singlelistitr.cpp"

using namespace std;

typedef long long ll;

class NumberList
{
	private:
		singleList<ll> v;
	public:
		int menu();
		void run();
		void InputArray();
		void Insert();
		void CountValue();
		void ThreeEvenNumber();
		void SortInc();
		void DelPrime();
		void DelDuplicate();
		void OutPut();
		friend int PrimeNumber(ll);
		friend int even(ll);
};

int NumberList::menu()
{
	cout<<"1. Nhap day (nhap dau # de dung).";
	cout<<"\n2. Chen phan tu.";
	cout<<"\n3. Dem gia tri k.";
	cout<<"\n4. Kiem tra 3 so chan dung canh nhau (neu co se in vi tri).";
	cout<<"\n5. Sap xep danh sach tang dan.";
	cout<<"\n6. Xoa tat ca so nguyen to.";
	cout<<"\n7. Xoa nhung phan tu trung nhau va giu lai 1 phan tu.";
	cout<<"\n8. In danh sach.";
	cout<<"\n9. Thoat";
	cout<<"\nNhap thao tac: ";
	int select;
	cin >> select;
	
	return select;
}

void NumberList::run()
{
	
	int sel;	
	do
	{
		system("cls");
		sel = menu();
		system("cls");
		switch(sel)
		{
			case 1:
				InputArray();
				break;
			case 2:
				Insert();
				break;
			case 3:
				CountValue();
				break;
			case 4:
				ThreeEvenNumber();
				break;
			case 5:
				SortInc();
				break;
			case 6:
				DelPrime();
				break;
			case 7:
				DelDuplicate();
				break;
			case 8:
				OutPut();
				break;	
		}	
	}
	while(sel != 9);	
}


void NumberList::InputArray()
{
	ll e;
	char c[100];
	Node<ll> *p;		
	while(1)
	{
		cout<<"\nNhap gia tri: ";
		cin >> c;
		if(c[0] == '#')
		{
			cout << "\nKet thuc qua trinh nhap!\n";
			break;
		} 
		sscanf(c, "%lld", &e);
		p = v.insertLast(e);
		if (p) cout << "\nChen thanh cong!";
		else cout<<"\nKhong the chen them!";
	}
	
	system("pause");
}

void NumberList::Insert()
{
	int i;
	ll e;
	Node<ll> *p;
	cout << "\nNhap gia tri phan tu: ";
	cin >> e;
	cout << "\nNhap vi tri muon chen: ";
	cin >> i;
	if(i == 0)
	{
		if(v.insertFirst(e)) cout << "\nChen thanh cong!";
		else cout << "\nLoi chen!\n";
	}
	else
	{
		p = v.getNode(i - 1);
		if (v.insertAfter(p,e)) cout << "\nChen thanh cong!";
		else cout << "\nLoi chen!\n";
	}
	
	system("pause");
}

void NumberList::CountValue()
{
	if(!v.isEmpty())
	{
		ll k, dem = 0;
		do
		{
			cout << "\nNhap gia tri khac 0: ";
			cin >> k;
			if(!k) cout << "\nLoi. Nhap lai!";
		}
		while(!k);
		Node<ll> *p;
		p = v.first();
		while(p != NULL)
		{
			if(p->getElem() == k) dem++;
			p = p->getnext();
		}
		cout << "\nGia tri " << k << " co " << dem << " phan tu.";	
	}
	else cout << "\nDanh sach trong!";
	
	system("pause");
}

int even(ll a)
{
	return (!(a % 2 ) && a > 0);
}

void NumberList::ThreeEvenNumber()
{
	if(!v.isEmpty())
	{
		int count = 0, index = 0, check = 0;
		for(Node<ll>*p = v.first(); p != NULL; p = p->getnext())
		{		
			if(even(p->getElem())) count++;
			else count = 0;	
			if(count >= 3)
			{
				check = 1;
				cout << "\nVi tri 3 so chan dung canh nhau: ";
				cout << index - 2 << " " << index - 1 << " " << index << endl;
			}
			index++;
		}
		if(!check) cout << "\nKhong co 3 phan tu chan duong nao dung canh nhau!";
	}
	else cout << "\nDanh sach trong!";
	
	system("pause");
}

int PrimeNumber(ll a)
{
	if (a < 2) return 0;	
	if (a == 2) return 1;	
	if (!(a % 2)) return 0;
	
	ll root;
	root = sqrt((double)a);
	for(int i = 3; i <= root; i += 2 )
	{
		if (!(a % i)) return 0;
	}
	
	return 1;
}

void NumberList::DelPrime()
{	

	singleList<ll> New;
	if(!v.isEmpty())
	{
		for(Node<ll> *p = v.first(); p != NULL; p = p->getnext())
		{	
			if(!PrimeNumber(p->getElem()))
			{
				New.insertLast(p->getElem());
			}
	 	}
	 	v.delList();
	 	v = New;
 	 	cout << "\nDa xoa het so  nguyen to.";
	}
 	else cout << "\nDanh sach trong!";
 	
 	system("pause");
}

ll dem[100000008];
void NumberList::DelDuplicate()
{

	if(!v.isEmpty())
	{
		singleList<ll> New;
		for(Node<ll> *p = v.first(); p != NULL; p = p->getnext())
		{
			if(dem[p->getElem()]) continue;
			New.insertLast(p->getElem());
			dem[p->getElem()] = 1;
		}
		v.delList();
	 	v = New;
		cout << "\nXoa thanh cong!";
	}
	else cout << "\nDanh sach trong!";
	
	system("pause");
}

void NumberList::SortInc()
{
	if(!v.isEmpty())
	{
		v.sort();
		cout << "\nSap xep thanh cong!";
	}
	else cout << "\nDanh sach trong!";	
	
	system("pause");
}

void NumberList::OutPut()
{
	if(!v.isEmpty())
	{
		singleListItr<ll> itr(&v);
		itr.resest();
		while(itr.hasnext())
		{
			cout << itr.next() << " ";
		}
	}
	else cout << "\nDanh sach trong!";
	
	system("pause");
}

