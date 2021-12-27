#include "sequence2.h"
#include <cstdlib>
using namespace std;
namespace assignment_sequence2 {
	sequence::sequence() {
		current_ptr = NULL;
		head_ptr = NULL;
		tail_ptr = NULL;
		previous_ptr = NULL;
		many_nodes = 0;
	}
	sequence::sequence(const sequence& source) {
		many_nodes = source.many_nodes;
		list_copy(source.head_ptr, head_ptr, tail_ptr);
		node* temp_src_head_ptr;
		temp_src_head_ptr = source.head_ptr;
		previous_ptr = head_ptr;
		if (source.current_ptr == NULL) {
			if (source.previous_ptr == NULL) {
				current_ptr = NULL;
				previous_ptr = NULL;
			}
			else {
				previous_ptr = tail_ptr;
				current_ptr = NULL;
			}
		}
		else {
			if (source.previous_ptr == NULL) {
				current_ptr = head_ptr;
				previous_ptr = NULL;
			}
			else {
				while (temp_src_head_ptr != source.previous_ptr) {
					temp_src_head_ptr = temp_src_head_ptr->link();
					previous_ptr = previous_ptr->link();
				}
				current_ptr = previous_ptr->link();
			}
		}
	}
	sequence::~sequence() {
		list_clear(head_ptr);
	}
	void sequence::start() {
		current_ptr = head_ptr;
		previous_ptr = NULL;
	}
	bool sequence::is_item() const {
		return (current_ptr != NULL);
	}
	sequence::size_type sequence::size() const {
		return many_nodes;
	}
	sequence::value_type sequence::current() const {
		return current_ptr->data();
	}
	void sequence::advance() {
		if (is_item()) {
			previous_ptr = current_ptr;
			current_ptr = current_ptr->link();
		}
	}
	void sequence::insert(const sequence::value_type& entry) {
		if (is_item()) {
			if (previous_ptr != NULL) {
				list_insert(previous_ptr, entry);
				current_ptr = previous_ptr->link();
			}
			else {
				list_head_insert(head_ptr, entry);
				previous_ptr = NULL;
				current_ptr = head_ptr;
			}
		}
		else {
			if (many_nodes == 0) {
				list_head_insert(head_ptr, entry);
				previous_ptr = NULL;
				current_ptr = head_ptr;
				tail_ptr = head_ptr;
			}
			else {
				list_head_insert(head_ptr, entry);
				previous_ptr = NULL;
				current_ptr = head_ptr;
			}
		}
		many_nodes++;
	}
	void sequence::attach(const sequence::value_type& entry) {
		if (is_item()) {
			if (current_ptr->link() == NULL) {
				list_insert(current_ptr, entry);
				previous_ptr = current_ptr;
				current_ptr = current_ptr->link();
				tail_ptr = current_ptr;
			}
			else {
				list_insert(current_ptr, entry);
				previous_ptr = current_ptr;
				current_ptr = current_ptr->link();
			}
		}
		else {
			if (many_nodes == 0) {
				list_head_insert(head_ptr, entry);
				previous_ptr = NULL;
				current_ptr = head_ptr;
				tail_ptr = head_ptr;
			}
			else {
				previous_ptr = tail_ptr;
				list_insert(tail_ptr, entry);
				tail_ptr = tail_ptr->link();
				current_ptr = tail_ptr;
			}
		}
		many_nodes++;
	}
	void sequence::remove_current() {
		if (is_item()) {
			many_nodes--;
			if (previous_ptr == NULL) {
				list_head_remove(head_ptr);
				current_ptr = head_ptr;
			}
			else {
				current_ptr = current_ptr->link();
				list_remove(previous_ptr);
			}
		}
	}
	void sequence::operator =(const sequence& source) {
		if (source.head_ptr != head_ptr) {
			list_clear(head_ptr);
		}
		many_nodes = source.many_nodes;
		list_copy(source.head_ptr, head_ptr, tail_ptr);
		node* temp_src_head_ptr;
		temp_src_head_ptr = source.head_ptr;
		previous_ptr = head_ptr;
		if (source.current_ptr == NULL) {
			if (source.previous_ptr == NULL) {
				current_ptr = NULL;
				previous_ptr = NULL;
			}
			else {
				previous_ptr = tail_ptr;
				current_ptr = NULL;
			}
		}
		else {
			if (source.previous_ptr == NULL) {
				current_ptr = head_ptr;
				previous_ptr = NULL;
			}
			else {
				while (temp_src_head_ptr != source.previous_ptr) {
					temp_src_head_ptr = temp_src_head_ptr->link();
					previous_ptr = previous_ptr->link();
				}
				current_ptr = previous_ptr->link();
			}
		}
	}
}