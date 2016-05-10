/** @file LedActuatorSerialProxy.h 
  *  Copyright (c) 2016 Ozbotics 
  *  Distributed under the MIT license (see LICENSE)
  */ 
#ifndef _TAGGED_ITEM_H
 #define _TAGGED_ITEM_H

 /**
  *  TaggedItem<T> struct template. 
  */
template <typename ItemT, typename TagT>
struct TaggedItem {
  ItemT item;  /**< variable item  The Item */ 
  TagT tag;    /**< variable tag  The Tag */ 
  
 /**
  * does my tag match the specified tag
  *
  * @return true is the my tag matches the specified tag
  */ 
  bool matchesTag(TagT t) {
    return (tag == t);
  }
};

#endif  // _TAGGED_ITEM_H