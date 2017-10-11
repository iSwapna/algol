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
 * 7.1 Merge sorted lists
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


int main() {

    cout << "hello" << endl;

    shared_ptr<node_t<int>> head1(nullptr), head2(nullptr);

    head1 = append(3, head1); append(4, head1); append(6, head1);
    printL(head1);
    head2 = append(1, head2); append(2, head2); append(5, head2);
    printL(head2);
    head1 = mergeLists(head1, head2);
    printL(head1);
}
