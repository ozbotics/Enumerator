/** @file FilteredEnumerator.h 
  *  Copyright (c) 2016 Ozbotics 
  *  Distributed under the MIT license (see LICENSE)
  */ 
#ifndef _FILTERED_ENUMERATOR_H
#define _FILTERED_ENUMERATOR_H

#include <Enumerator.h>

/**
 * FilteredEnumerator class template
 *
 * Provides means to Iterate over a Filtered List of a particular Type
 *  extend FilteredEnumerator and over-ride _matches() to control filtering
 */
template <class T>
class FilteredEnumerator : public Enumerator<T> {
  protected:
  
   /**
    * advance the index to the next valid item (if any)
    *  using the _matches() to identify valid items
    *
    * @return nothing
    */
    virtual void _selectNext();
    
   /**
    * default implementation of filter match function (always true)
    *  over-ride to define filter behaviour
    *
    * @param item The item under consideration consider
    * @return true if targeted item matches filter
    */   
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