/** @file MotorLoadSensor.h 
  *  Copyright (c) 2016 Ozbotics 
  *  Distributed under the MIT license (see LICENSE)
  */ 
#ifndef _ENUMERATOR_H
#define _ENUMERATOR_H

#include <Arduino.h>
#include <LinkedList.h>

/**
 * The base of all Eumerators
 *
 * Provides means to Iterate over a List
 */
class EnumeratorBase {
  public:
  
   /**
    * move to the next item in the list (if possible)
    *
    * @return true if there is an item available
    */  
    virtual bool moveNext()=0;
    
   /**
    * start at the begining of the list
    *
    * @return nothing
    */     
    virtual void reset();
};

/**
 * Eumerator class template
 *
 * Provides means to Iterate over a List of a particular Type
 */
template <class T>
class Enumerator : public EnumeratorBase {
  protected:
    LinkedList<T>* _list;  /**< pointer to the list to be iterated over */ 
    int _index;  /**< protected variable _index Index of the currently selected item (or -1, nothing selected) */ 
    
    
   /**
    * advance the index to the next valid item (if any)
    *
    * @return nothing
    */     
    virtual void _selectNext();
    
  public:
  
   /**
    * Constructor
    *
    * @param list Pointer to the list to be iterated over 
    */
    Enumerator<T>(LinkedList<T>* list) : _list(list), _index(-1), EnumeratorBase() { }
    
   /**
    * get the current Item
    *
    * @return the current item
    */     
    T getCurrent();

   /**
    * advance to the next valid item
    *
    * @return true if an Item is available
    */     
    virtual bool moveNext();
    
   /**
    * reset to the begining of the list
    *
    * @return nothing
    */     
    virtual void reset();
};    

template <class T>
void Enumerator<T>::_selectNext() {
  _index++;
}

template <class T>
T Enumerator<T>::getCurrent() {
  return _list->get(_index);
}

template <class T>
bool Enumerator<T>::moveNext() { 
  bool ret = false;
  int oldIndex = _index;
  
  _selectNext();
  
  if ( (_index > -1) && (_list->size() > _index) && (_index != oldIndex) ) {
    ret = true;
  }
  
  return ret;
}

template <class T>
void Enumerator<T>::reset() {
  _index = -1;
}

#endif  // _ENUMERATOR_H