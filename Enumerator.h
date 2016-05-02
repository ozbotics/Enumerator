#ifndef _ENUMERATOR_H
#define _ENUMERATOR_H

#include <Arduino.h>
#include <LinkedList.h>


class EnumeratorBase {
  public:
    virtual bool moveNext()=0;
    virtual void reset();
};

template <class T>
class Enumerator : public EnumeratorBase {
  protected:
    LinkedList<T>* _list;
    int _index;
    
    virtual void _selectNext();
    
  public:    
    Enumerator<T>(LinkedList<T>* list) : _list(list), _index(-1), EnumeratorBase() { }
    
    T getCurrent();
    virtual bool moveNext();
    virtual void reset();
};    

template <class T>
void Enumerator<T>::_selectNext() {
  //Serial.print("Using Enumerator::_selectNext, _index: ");
  //Serial.println(_index);
  
  _index++;
}

template <class T>
T Enumerator<T>::getCurrent() {
  //Serial.print("Attempting to getCurrent ");
  //Serial.println(_index);
  
  return _list->get(_index);
}

template <class T>
bool Enumerator<T>::moveNext() { 
  bool ret = false;
  int oldIndex = _index;
  
  //Serial.print("_index is now ");
  //Serial.println(_index);
  
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