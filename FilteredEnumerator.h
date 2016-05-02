#ifndef _FILTERED_ENUMERATOR_H
#define _FILTERED_ENUMERATOR_H

#include <Enumerator.h>

template <class T>
class FilteredEnumerator : public Enumerator<T> {
  protected:
    T item;

    virtual void _selectNext();
    virtual bool _matches(T item);
    
  public:    
    FilteredEnumerator<T>(LinkedList<T>* list) : Enumerator<T>(list) { }
};    

template <class T>
void FilteredEnumerator<T>::_selectNext() {
  int oldIndex = this->_index;
  bool found = false;
  
  while (this->_index < this->_list->size()) {
    this->_index++;

    if (_matches(this->_list->get(this->_index))) {
      found = true;
      break;
    }
  }

  if (!found) {
    this->_index = oldIndex;
  }
}

template <class T>
bool FilteredEnumerator<T>::_matches(T item) {
  return true;
}

#endif  // _FILTERED_ENUMERATOR_H