 #include <cstdlib>   
#include <iomanip>    
#include <iostream>   
#include "bintree.h"
using namespace std;
namespace assignment3_yauheni_patapau {
	void tree_clear(binary_tree_node*& root_ptr) {
		if (root_ptr != NULL) {
			binary_tree_node* temp_left_ptr = root_ptr->left();
			binary_tree_node* temp_right_ptr = root_ptr->right();
			tree_clear(temp_left_ptr);
			tree_clear(temp_right_ptr);
			delete root_ptr;
			root_ptr = NULL;
		}
	}

	binary_tree_node* tree_copy(const binary_tree_node* root_ptr) {
		binary_tree_node* l_ptr;
		binary_tree_node* r_ptr;
		if (root_ptr == NULL) return NULL;
		else {
			l_ptr = tree_copy(root_ptr->left());
			r_ptr = tree_copy(root_ptr->right());
			return new binary_tree_node(root_ptr->data(), l_ptr, r_ptr);
		}
	}

	size_t tree_size(const binary_tree_node* node_ptr) {
		if (node_ptr == NULL) return 0;
		else return 1 + tree_size(node_ptr->left()) + tree_size(node_ptr->right());
	}

	void enter_tree(binary_tree_node*& entry_ptr, int new_entry) {
		if (entry_ptr == NULL) {
			entry_ptr = new binary_tree_node(new_entry);
			return;
		}
		if (new_entry <= entry_ptr->data()) {
			binary_tree_node* temp_ptr = entry_ptr->left();
			enter_tree(temp_ptr, new_entry);
			if (entry_ptr->left() == NULL) {
				entry_ptr->set_left(temp_ptr);
			}
		}
		else {
			binary_tree_node* temp_ptr = entry_ptr->right();
			enter_tree(temp_ptr, new_entry);
			if (entry_ptr->right() == NULL) {
				entry_ptr->set_right(temp_ptr);
			}
		}
	}
	void print(binary_tree_node* node_ptr, int depth) {
		if (node_ptr != NULL) {
			print(node_ptr->right(), depth + 1);
			cout << setw(4 * depth) << "";
			cout << node_ptr->data() << endl;
			print(node_ptr->left(), depth + 1);
		}
	}
}
using namespace assignment3_yauheni_patapau;
int main() {
	int new_entry = 1;
	binary_tree_node* root_node = NULL;
	binary_tree_node* another_root_node = NULL;
	while (new_entry != 0) {
		cout << "Enter any number to fill the first tree (0 to stop): ";
		cin >> new_entry;
		enter_tree(root_node, new_entry);
	}
	cout << "Size of the first tree: " << tree_size(root_node) << endl;
	cout << "Size of second (empty) tree: " << tree_size(another_root_node) << endl;
	cout << "Printing out the first tree..." << endl;
	print(root_node, 2);
	cout << endl;
	cout << "Now checking 'tree_copy' function..." << endl << "Copying first tree into the second empty tree..." << endl;
	another_root_node = tree_copy(root_node);
	cout << "New size of the second tree: " << tree_size(another_root_node) << endl;
	cout << "Printing out the second tree..." << endl;
	print(another_root_node, 2);
	cout << endl;
	cout << "Checking 'tree_clear' function for the first tree..." << endl;
	tree_clear(root_node);
	cout << "New size of the first tree: " << tree_size(root_node) << endl;
	return 0;
}



