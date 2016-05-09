/** @file TagFilteredEnumerator.h 
  *  Copyright (c) 2016 Ozbotics 
  *  Distributed under the MIT license (see LICENSE)
  */ 
#ifndef _TAG_FILTERED_ENUMERATOR_H
#define _TAG_FILTERED_ENUMERATOR_H

#include <FilteredEnumerator.h>

/**
 * TagFilteredEnumerator class template
 *
 * Provides means to Iterate over a Filtered List of a particular Type
 *  selecting only the items that have matching Tag
 */
template <class TaggedItemT, class TagT>
class TagFilteredEnumerator : public FilteredEnumerator<TaggedItemT> {
  protected:
    TagT _tag; /**< protected variable  _tag  The filter tag */

   /**
    * selects only the items that have matching tag
    * 
    * @param item The item under consideration consider
    * @return true if supplied item matches the filter
    */   
    virtual bool _matches(TaggedItemT item);
    
  public: 
  
   /**
    * Constructor
    *
    * @param list Pointer to the list to be iterated over 
    * @param tag The default filter tag
    */
    TagFilteredEnumerator<TaggedItemT, TagT>(LinkedList<TaggedItemT>* list, TagT tag) : _tag(tag), FilteredEnumerator<TaggedItemT>(list) { }
    
   /**
    * specify the filter tag
    *
    * @param tag The filter tag
    */
    void setFilterTag(TagT tag);
};

template <class TaggedItemT, class TagT>
bool TagFilteredEnumerator<TaggedItemT, TagT>::_matches(TaggedItemT item) {
  return item.matchesTag(_tag);
}

template <class TaggedItemT, class TagT>
void TagFilteredEnumerator<TaggedItemT, TagT>::setFilterTag(TagT tag) {
  _tag = tag;
}

#endif  // _TAG_FILTERED_ENUMERATOR_H