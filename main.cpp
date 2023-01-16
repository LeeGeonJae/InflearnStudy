#include <iostream>
#include <vector>
#include <list>
#include <deque>
#include <map>
#include <set>
#include <algorithm>

using namespace std;

// 오늘의 주제 : 스마트 포인터 (smart pointer)

class Knight
{
public:
	Knight() { cout << "Knight 생성" << endl; }
	~Knight() { cout << "Knight 소멸" << endl; }

	void Attack()
	{
		// 타겟이 유효하지 않은가?
		if (_target.expired() == false)
		{
			// 유효하면 shared_ptr로 변환해서 사용
			shared_ptr<Knight> sptr =  _target.lock();

			sptr->_hp -= _damage;
			cout << "HP : " << sptr->_hp << endl;
		}
	}

public:
	int _hp = 100;
	int _damage = 10;
	weak_ptr<Knight> _target;
};

class RefCountBlock
{
public:
	int _refCount = 1;
	int _weakCount = 1;
};

template<typename T>
class SharedPtr
{
public:
	SharedPtr() {}
	SharedPtr(T* ptr) : _ptr(ptr)
	{
		if (_ptr != nullptr)
		{
			_block = new RefCountBlock();
			cout << "RefCount : " << _block->_refCount << endl;
		}
	}

	SharedPtr(const SharedPtr& sptr) : _ptr(sptr._ptr), _block(sptr._block)
	{
		if (_ptr != nullptr)
		{
			_block->_refCount++;
			cout << "RefCount : " << _block->_refCount << endl;
		}
	}

	void operator=(const SharedPtr& sptr)
	{
		_ptr = sptr._ptr;
		_block = sptr._block;

		if (_ptr != nullptr)
		{
			_block->_refCount++;
			cout << "RefCount : " << _block->_refCount << endl;
		}
	}

	~SharedPtr()
	{
		if (_ptr != nullptr)
		{
			_block->_refCount--;
			cout << "RefCount : " << _block->_refCount << endl;

			if (_block->_refCount == 0)
			{
				delete _ptr;
				//delete _block;
				cout << "Delete Data" << endl;
			}
		}
	}

public:
	T* _ptr = nullptr;
	RefCountBlock* _block = nullptr;
};


int main()
{
	{
		//Knight* k1 = new Knight();
		//Knight* k2 = new Knight();

		//k1->_target = k2;

		//delete k2;

		//k1->Attack();
	}

	// 스마트 포인터 : 포인터를 알맞는 정책에 따라 관리하는 객체 (포인터를 래핑해서 사용)
	// shared_ptr, weak_ptr, unique_ptr
	{
		SharedPtr<Knight> k2;
		{
			SharedPtr<Knight> k1(new Knight());
			k2 = k1;
		}
	}

	cout << " --------------------------------------- " << endl;

	{
		shared_ptr<Knight> k1 = make_shared<Knight>();
		{
			shared_ptr<Knight> k2 = make_shared<Knight>();

			k1->_target = k2;
			k2->_target = k1;
		}
		k1->Attack();
	}

	cout << "---------------------------------------" << endl;

	{
		unique_ptr<Knight> uptr = make_unique<Knight>();
		unique_ptr<Knight> uptr2 = std::move(uptr);
	}

	return 0;
}