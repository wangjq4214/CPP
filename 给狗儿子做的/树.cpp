#include <iostream>
#include <stack>
#include <queue>
#include <cmath> 

using namespace std;

//���������
template<class T>
struct BiTNode {
	T data;
	BiTNode<T>* lChild;
	BiTNode<T>* rChild;
};


//������
template<class T>
class BiTree {
	public:
		BiTree();
		~BiTree();


	public:
		//����ֲ㽨��
		BiTNode<T>* Create(T *pNodeData, int nNodeNum, T nEmptyNodeData, int nNodeIndex = 0);


		//������
		void Destroy(BiTNode<T>* pRoot);


		//���
		int GetDepth(BiTNode<T>* pRoot);


		//�ڵ����
		int GetNodeNum(BiTNode<T>* pRoot);


		//Ҷ�ӽڵ����
		int GetLeafNodeNum(BiTNode<T>* pRoot);


		//�ǲ���ƽ�������
		bool IsAVL(BiTNode<T>* pRoot, int *pHeight = NULL);


		//�ֲ����
		void LevelTraverse(BiTNode<T>* pRoot);


		//ǰ�����
		void PreOrderTraverse(BiTNode<T>* pRoot, bool brec);


		//�������
		void InOrderTraverse(BiTNode<T>* pRoot, bool brec);


		//�������
		void PostOrderTraverse(BiTNode<T>* pRoot, bool brec);


		//��ȡ�����
		BiTNode<T>* GetRoot();


	private:
		BiTNode<T> *m_pRoot;
};

template<class T>
BiTree<T>::BiTree() {
	m_pRoot = NULL;
}

template<class T>
BiTree<T>::~BiTree() {
	Destroy(m_pRoot);
}

//�ֲ㽨��
template<class T>
BiTNode<T>* BiTree<T>::Create(T *pNodeData, int nNodeNum, T nEmptyNodeData, int nNodeIndex) {
	if (pNodeData == NULL || nNodeNum <= 0 || nNodeIndex >= nNodeNum)
		return NULL;

	BiTNode<T>* p = NULL;
	if (nNodeIndex < nNodeNum && pNodeData[nNodeIndex] != nEmptyNodeData) {
		p = new BiTNode<T>;
		p->data = pNodeData[nNodeIndex];
		p->lChild = Create(pNodeData, nNodeNum, nEmptyNodeData, 2*nNodeIndex+1);
		p->rChild = Create(pNodeData, nNodeNum, nEmptyNodeData, 2*nNodeIndex+2);
	}

	return p;
}

//������,�ֲ�����
template<class T>
void BiTree<T>::Destroy(BiTNode<T>* pRoot) {
	if (pRoot) {
		Destroy(pRoot->lChild);
		Destroy(pRoot->rChild);

		delete pRoot;
		pRoot = NULL;
	}
}

//���
template<class T>
int BiTree<T>::GetDepth(BiTNode<T>* pRoot) {
	if (pRoot) {
		int depthLeft = GetDepth(pRoot->lChild);
		int depthRight = GetDepth(pRoot->rChild);
		return depthLeft > depthRight ? (depthLeft + 1) : (depthRight + 1);
	}

	return 0;
}

//�ڵ����
template<class T>
int BiTree<T>::GetNodeNum(BiTNode<T>* pRoot) {
	int num = 0;
	if (pRoot) {
		num += 1;
		num += GetNodeNum(pRoot->lChild);
		num += GetNodeNum(pRoot->rChild);
	}

	return num;
}

//Ҷ�ӽڵ����
template<class T>
int BiTree<T>::GetLeafNodeNum(BiTNode<T>* pRoot) {
	int num = 0;
	if (pRoot) {
		if (pRoot->lChild == NULL && pRoot->rChild == NULL) {
			num += 1;
		} else {
			num += GetLeafNodeNum(pRoot->lChild);
			num += GetLeafNodeNum(pRoot->rChild);
		}
	}

	return num;
}

//�ǲ���ƽ�������
template<class T>
bool BiTree<T>::IsAVL(BiTNode<T>* pRoot, int *pHeight) {
	if (pRoot) {
		int heightLeft = 0;
		bool resultLeft = IsAVL(pRoot->lChild, &heightLeft);

		int heightRight = 0;
		bool resultRight = IsAVL(pRoot->rChild, &heightRight);

		if (resultLeft && resultRight && abs(heightLeft-heightRight) <= 1) {
			if (pHeight)
				*pHeight = max(heightLeft, heightRight)+1;
			return true;
		} else {
			if (pHeight)
				*pHeight = max(heightLeft, heightRight)+1;
			return false;
		}
	} else {
		if (pHeight)
			*pHeight = 0;
		return true;
	}
}

//�ֲ����
template<class T>
void BiTree<T>::LevelTraverse(BiTNode<T>* pRoot) {
	if (pRoot) {
		BiTNode<T>* p = NULL;
		queue<BiTNode<T>*> q;
		q.push(pRoot);
		while (!q.empty()) {
			p = q.front();
			q.pop();
			cout<<p->data<<" ";

			if (p->lChild)
				q.push(p->lChild);
			if(p->rChild)
				q.push(p->rChild);
		}
	}
}

//ǰ�����������˳�򣺸�������
template<class T>
void BiTree<T>::PreOrderTraverse(BiTNode<T>* pRoot, bool brec) {
	if (pRoot) {
		if (brec) {
			cout<<pRoot->data<<" ";
			PreOrderTraverse(pRoot->lChild, brec);
			PreOrderTraverse(pRoot->rChild, brec);
		} else {
			stack<BiTNode<T>*> s;
			BiTNode<T>* p = pRoot;
			while(p != NULL || !s.empty()) {
				if (p != NULL) {
					cout<<p->data<<" ";
					s.push(p);
					p = p->lChild;
				} else {
					p = s.top();
					s.pop();

					p = p->rChild;
				}
			}
		}

	}
}

//�������������˳���󡢸�����
template<class T>
void BiTree<T>::InOrderTraverse(BiTNode<T>* pRoot, bool brec) {
	if (pRoot) {
		if (brec) {
			InOrderTraverse(pRoot->lChild, brec);
			cout<<pRoot->data<<" ";
			InOrderTraverse(pRoot->rChild, brec);
		} else {
			stack<BiTNode<T>*> s;
			BiTNode<T>* p = pRoot;
			while (p  != NULL || !s.empty()) {
				if (p != NULL) {
					s.push(p);
					p = p->lChild;
				} else {
					p = s.top();
					cout<<p->data<<" ";
					s.pop();

					p = p->rChild;
				}
			}
		}
	}
}

//�������������˳�����ҡ���
template<class T>
void BiTree<T>::PostOrderTraverse(BiTNode<T>* pRoot, bool brec) {
	if (pRoot) {
		if (brec) {
			PostOrderTraverse(pRoot->lChild, brec);
			PostOrderTraverse(pRoot->rChild, brec);
			cout<<pRoot->data<<" ";
		} else {
			stack<BiTNode<T>*> s;
			s.push(pRoot);
			BiTNode<T>* pre = NULL;
			BiTNode<T>* cur = NULL;
			while(!s.empty()) {
				cur = s.top();
				if( (cur->lChild == NULL && cur->rChild == NULL) ||//û���ӽ��
				        (pre != NULL)&& (pre == cur->lChild || pre == cur->rChild) ) { //���ӽ���ѷ���
					cout<<cur->data<<" ";
					s.pop();
					pre = cur;
				} else {
					if(cur->rChild)
						s.push(cur->rChild);
					if (cur->lChild)
						s.push(cur->lChild);
				}
			}
		}
	}
}

//��ȡ�����
template<class T>
BiTNode<T>* BiTree<T>::GetRoot() {
	return m_pRoot;
}

int main() {
	BiTree<int> temp;
}
