#ifndef HEAP_H
#define HEAP_H
#include <functional>
#include <stdexcept>
#include <vector>

template <typename T, typename PComparator = std::less<T> >
class Heap
{
public:
  /**
   * @brief Construct a new Heap object
   * 
   * @param m ary-ness of heap tree (default to 2)
   * @param c binary predicate function/functor that takes two items
   *          as an argument and returns a bool if the first argument has
   *          priority over the second.
   */
  Heap(int m=2, PComparator c = PComparator());

  /**
  * @brief Destroy the Heap object
  * 
  */
  ~Heap();

  /**
   * @brief Push an item to the heap
   * 
   * @param item item to heap
   */
  void push(const T& item);

  /**
   * @brief Returns the top (priority) item
   * 
   * @return T const& top priority item
   * @throw std::underflow_error if the heap is empty
   */
  T const & top() const;

  /**
   * @brief Remove the top priority item
   * 
   * @throw std::underflow_error if the heap is empty
   */
  void pop();

  /// returns true if the heap is empty

  /**
   * @brief Returns true if the heap is empty
   * 
   */
  bool empty() const;

    /**
   * @brief Returns size of the heap
   * 
   */
  size_t size() const;
  void heapifyup(unsigned int i);
  void heapifydown(unsigned int i);
  void swap(T& a, T& b);


private:
  /// Add whatever helper functions and data members you need below
  std::vector<T> heap;
  PComparator comp_;
  unsigned int number_;
};

// Add implementation of member functions here
template <typename T, typename PComparator>
Heap<T,PComparator>::Heap(int m, PComparator c){
  number_ = m;
  comp_ = c;
}

template <typename T, typename PComparator>
Heap<T,PComparator>::~Heap(){

}

template <typename T, typename PComparator>
size_t Heap<T,PComparator>::size() const{
  return heap.size();
}

template <typename T, typename PComparator>
void Heap<T,PComparator>::swap(T& a, T& b){
  T temp = b;
  b = a;
  a = temp;
}

template <typename T, typename PComparator>
void Heap<T,PComparator>::heapifydown(unsigned int i){
  int index = i;
  while (index*number_+1 < heap.size()){
    int better_children = (index*number_)+1;
    for (unsigned int i=2; i<=number_ && i<=heap.size(); i++){
      if ((index*number_)+i >= heap.size()){
        break;
      }
      else if (comp_(heap[(index*number_)+i],heap[better_children])){
        better_children = (index*number_)+i;
      }
    }
    if (comp_(heap[better_children],heap[index])){
      swap(heap[better_children],heap[index]);
      index = better_children;
    }
    else {
      break;
    }
  }
}

template <typename T, typename PComparator>
void Heap<T,PComparator>::heapifyup(unsigned int i){
  if (i <= 0){
    return;
  }
  unsigned int index = i;
  unsigned int parent = (index-1)/number_;
  if (comp_(heap[index],heap[parent])){
    swap(heap[index],heap[parent]);
    heapifyup(parent);
  }
}

template <typename T, typename PComparator>
bool Heap<T,PComparator>::empty() const{
  if (heap.size() > 0){
    return false;
  }
  return true;
}

template <typename T, typename PComparator>
void Heap<T,PComparator>::push(const T& item){
  if (empty()){
    heap.push_back(item);
  }
  else{
    heap.push_back(item);
    heapifyup(heap.size()-1);
  }
}



// We will start top() for you to handle the case of 
// calling top on an empty heap
template <typename T, typename PComparator>
T const & Heap<T,PComparator>::top() const
{
  // Here we use exceptions to handle the case of trying
  // to access the top element of an empty heap
  if(empty()){
    // ================================
    // throw the appropriate exception
    // ================================
    throw std::underflow_error("Empty Heap!");

  }
  // If we get here we know the heap has at least 1 item
  // Add code to return the top element
  else {
    return heap[0];
  }
}


// We will start pop() for you to handle the case of 
// calling top on an empty heap
template <typename T, typename PComparator>
void Heap<T,PComparator>::pop()
{
  if(empty()){
    // ================================
    // throw the appropriate exception
    // ================================
    throw std::underflow_error("Empty Head!");
  }
  else {
    heap[0] = heap[heap.size()-1];
    heap.pop_back();
    heapifydown(0);
  }
}



#endif