#ifndef _TAG_FILTERED_ENUMERATOR_H
#define _TAG_FILTERED_ENUMERATOR_H

#include <FilteredEnumerator.h>


template <class TaggedItemT, class TagT>
class TagFilteredEnumerator : public FilteredEnumerator<TaggedItemT> {
  protected:
    TagT _tag;

    virtual bool _matches(TaggedItemT item);
    
  public:    
    TagFilteredEnumerator<TaggedItemT, TagT>(LinkedList<TaggedItemT>* list, TagT tag) : _tag(tag), FilteredEnumerator<TaggedItemT>(list) { }
    
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