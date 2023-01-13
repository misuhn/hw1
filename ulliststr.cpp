#include <cstddef>
#include <stdexcept>
#include "ulliststr.h"

ULListStr::ULListStr()
{
  head_ = NULL;
  tail_ = NULL;
  size_ = 0;
}

ULListStr::~ULListStr()
{
  clear();
}

bool ULListStr::empty() const
{
  return size_ == 0;
}

size_t ULListStr::size() const
{
  return size_;
}

std::string* ULListStr::getValAtLoc(size_t loc) const {
  if (loc >= size_) {
    return NULL;
  }
  Item* current = head_;
  size_t buf = 0;
  while (buf + current->last - current->first <= loc) {
    buf += current->last - current->first;
    current = current->next;
  }
  return &(current->val[loc - buf + current->first]);
}
// Writing my code here fr fr
void ULListStr::push_back(const std::string& val) {
  if (tail_ == NULL || tail_->last == ARRSIZE) {
    Item* newItem = new Item();
    newItem->first = 0;
    newItem->last = 1;
    newItem->val[0] = val;
    newItem->next = NULL;
    newItem->prev = tail_;
    if (tail_ != NULL) {
      tail_->next = newItem;
    }
    tail_ = newItem;
    if (head_ == NULL) {
      head_ = tail_;
    }
  } else {
    tail_->val[tail_->last] = val;
    tail_->last++;
  }
  size_++;
}

void ULListStr::push_front(const std::string& val) {
  if (head_ == NULL || head_->first == 0) {
    Item* newItem = new Item();
    newItem->last = 1;
    newItem->first = 0;
    newItem->val[0] = val;
    newItem->next = head_;
    newItem->prev = NULL;
    head_ = newItem;
    if (tail_ == NULL) {
      tail_ = head_;
    }
  } else {
    head_->first--;
    head_->val[head_->first] = val;
  }
  size_++;
}

void ULListStr::pop_front() {
  if (head_ == NULL) {
    return;
  }
  if (head_->first == head_->last - 1) {
    Item* temp = head_->next;
    delete head_;
    head_ = temp;
  } else {
    head_->first++;
  }
  size_--;
  if(size_ == 0) { // Update head and tail pointers
    head_ = NULL;
    tail_ = NULL;
  }
}

void ULListStr::pop_back() {
  if (tail_ == NULL) {
    return;
  }
  if (tail_->last-1 == tail_->first) {
    Item* temp = tail_;
    tail_ = tail_->prev;
    if (tail_ != NULL) {
      tail_->next = NULL;
    }
    delete temp;
  } else {
    tail_->last--;
  }
  size_--;
  if(size_ == 0) { // Update head and tail pointers
    head_ = NULL;
    tail_ = NULL;
  }
}

std::string const & ULListStr::back() const {
  if (tail_ == NULL) { // Empty
    throw std::out_of_range("L");
  }
  return tail_->val[tail_->last-1];
}

std::string const & ULListStr::front() const {
  if (head_ == NULL) { // Empty
    throw std::out_of_range("L");
  }
  return head_->val[head_->first];
}

void ULListStr::set(size_t loc, const std::string& val)
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  *ptr = val;
}

std::string& ULListStr::get(size_t loc)
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  return *ptr;
}

std::string const & ULListStr::get(size_t loc) const
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  return *ptr;
}

void ULListStr::clear()
{
  while(head_ != NULL){
    Item *temp = head_->next;
    delete head_;
    head_ = temp;
  }
  tail_ = NULL;
  size_ = 0;
}
