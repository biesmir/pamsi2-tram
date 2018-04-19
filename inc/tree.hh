/*
 * tree.hh
 *
 *  Created on: 18 kwi 2018
 *      Author: Jakub Cebulski
 */

#ifndef INC_TREE_HH_
#define INC_TREE_HH_

#include <memory>
#include <vector>

struct node{
	std::shared_ptr<node> parent;
	std::vector<std::shared_ptr<node>> child;
	int level;
	int ID;
	int time;
};

class tree{
private:
	node root;

public:
	tree(){
		root.parent=NULL;
		root.ID=0;
		root.time=0;
	}

	void add_node(int, int, int);
};


#endif /* INC_TREE_HH_ */
