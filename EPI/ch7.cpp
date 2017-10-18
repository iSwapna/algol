/***

    Chapter 7 of EPI

***/


#include <iostream>
//#include <vector>

using namespace std;

template <typename T> struct node_t {
  T data;
  shared_ptr<node_t<T>> next;
  node_t(T dat): data(dat), next(nullptr) {};
};

template <typename T> shared_ptr<node_t<T>> append(T data,
						   shared_ptr<node_t<T>> head) {
  auto res = make_shared<node_t<T>>(node_t<T>(data));
  if(head == NULL) {
    return res;
  }
  auto curr = head;
  while(curr->next) curr = curr->next;
  curr->next = res;
  return head;
}

template <typename T> void printL(shared_ptr<node_t<T>> head) {
  cout << "List: " ;
  while(head) {
    cout << head->data << " ";
    head = head->next;
  }
  cout << endl;
}

/*
 * 7.1 helpers
 */
template<typename T>
void appendNode(shared_ptr<node_t<T>>* head,
		shared_ptr<node_t<T>>* tail, shared_ptr<node_t<T>>* n) {
  *head ? (*tail)->next = *n : *head = *n;
  *tail = *n;
}
template<typename T>
void appendNodeAndAdvance(shared_ptr<node_t<T>>* head,
			  shared_ptr<node_t<T>>* tail, shared_ptr<node_t<T>>* n) {
  appendNode(head, tail, n);
  *n = (*n)->next; // advance n

}


/*
 * 7.1 Merge sorted lists - version 2
 *
 */
template <typename T> shared_ptr<node_t<T>> mergeLists2(shared_ptr<node_t<T>> L, shared_ptr<node_t<T>> R) {

  shared_ptr<node_t<T>> sortedHead = nullptr, tail = nullptr;

  while(R && L) {
    appendNodeAndAdvance(&sortedHead, &tail, R->data < L->data ? &R : &L);
    
  }
  if(R) {
    appendNode(&sortedHead, &tail, &R);
  }
  if(L) {
    appendNode(&sortedHead, &tail, &L);
  }
  return sortedHead;

}

/*
 * 7.1 Merge sorted lists - version 1
 *
 */
template <typename T> shared_ptr<node_t<T>> mergeLists(shared_ptr<node_t<T>> L, shared_ptr<node_t<T>> R) {

  if(L == NULL) return R;
  else if(R == NULL) return L;
  auto one = L; auto curr = L; auto other = R;
  if(R->data < L->data) {
    one = curr = R;
    other = L;
  }
  auto head = curr;
  one = one->next;
  
  while(one && other) {
    if(one->data < other->data) {
      curr->next = one;
      one = one->next;
    } else {
      curr->next = other;
      other = other->next;
    }
    curr = curr->next;
  }
  if(one) curr->next = one;
  if(other) curr->next = other;
  return head;
}

/*
* Helpers to test 7.2
*/
template<typename T>
void appendCycle(int n, const shared_ptr<node_t<T>> head) {

  shared_ptr<node_t<T>> tail = head;
  while(tail->next != nullptr) {
    tail = tail->next;
  }
  shared_ptr<node_t<T>> curr = head;
  while(n-- > 0) {
    curr = curr->next;
  }
  tail->next = curr;

}
template<typename T>
int createCycle(shared_ptr<node_t<T>>* head,
		vector<T> values) {
  for(auto &item: values) {
    *head = append(item, *head);
  }
  printL(*head);
  appendCycle(values.size()/2, *head);

  return values.size()/2;
}


/*
 * 7.2 Find Cycle in List
 *
 */
template <typename T>
shared_ptr<node_t<T>> hasCycle(const shared_ptr<node_t<T>>& head) {

  shared_ptr<node_t<T>> fast = head, slow = head;

  while(slow && slow->next && fast && fast->next && fast->next->next) {
    slow = slow->next, fast = fast->next->next;
    if(slow == fast) { //there is a cycle
      //calculate the cycle length.
      int cycleLen = 0;
      do {
	++cycleLen;
	fast = fast->next;
      }while(slow != fast);

      //tries to find the start of the cycle.
      slow = head, fast = head;
      //fast pointer advances cycleLen first.
      while(cycleLen--) {
	fast = fast->next;
      }
      //both pointers advance at the same time.
      while(slow != fast) {
	slow = slow->next; fast = fast->next;
      }
      return slow;
    }
  }
  return nullptr;
}


#include <vector>
int main() {

    cout << "hello" << endl;

    shared_ptr<node_t<int>> head1(nullptr), head2(nullptr);

    head1 = append(3, head1); append(4, head1); append(6, head1);
    printL(head1);
    head2 = append(1, head2); append(2, head2); append(5, head2);
    printL(head2);
    head1 = mergeLists2(head1, head2);
    printL(head1);

    shared_ptr<node_t<int>> hd(nullptr);
    vector<int> values = {3, 5, 7, 8, 9, 11, 13};
    int len = createCycle(&hd, values);
    cout << "Cycle len: " << len << endl;
    cout << hasCycle(hd)->data << endl;
}
