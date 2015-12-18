#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

class CategoryTree {
    string category;
    CategoryTree* child;
    CategoryTree* sibling;
    public:
    CategoryTree(string str=""): category(str), child(NULL), sibling(NULL) {}
    void InsertCategory(vector<string> category);
    void printLevelValues();
    void print();
};

void CategoryTree::InsertCategory(vector<string> category) {
    int sz = static_cast<int>(category.size());
    int index=0;
    CategoryTree* current = this;
    while (index<sz) {
	if (current->child==NULL) {
	    CategoryTree* cat = new CategoryTree(category[index]);
	    current->child=cat;
	    current=current->child;
	} else {
	    //find if already present
	    CategoryTree* pSibling = current->child;
	    while (pSibling->category.compare(category[index])) {
		if (pSibling->sibling) pSibling=pSibling->sibling;
		else break;
	    }
	    if (pSibling->category.compare(category[index])) {
		//new
		CategoryTree* cat = new CategoryTree(category[index]);
		pSibling->sibling = cat;
		current = cat;
	    } else {
		//already present
		current = pSibling;
	    }
	}
	++index;
    }
}

void CategoryTree::printLevelValues() {
    CategoryTree* current = this;
    if (!current) return;
    cout << "\t\t\t\tChildren= ";
    while (current) {
	cout << current->category;
	if (current->sibling) cout << ", ";
	current = current->sibling;
    }
    cout << endl;
}

void CategoryTree::print() {
    CategoryTree* current = this;
    if (!current || !current->child) return;
    cout << "\n\nRoot= " << current->category << endl;
    current->child->printLevelValues();
    if (current->child) current->child->print();
    if (current->sibling) current->sibling->print();
}

int main() {
    CategoryTree CatTree("Home");
    vector<string> category;
    string Line;
    ifstream inpfile("input.txt");
    while (getline(inpfile, Line)) {
	category.clear();
	size_t pos = Line.find_first_of("|");
	category.push_back(Line.substr(0, pos));
	while (pos != string::npos) {
	    size_t next_pos = Line.find_first_of("|", pos+1);
	    category.push_back(Line.substr(pos+1, next_pos-pos-1));
	    pos = next_pos;
	}
	CatTree.InsertCategory(category);
    }
    cout << "--------------------------------";
    cout << "\n Final Tree Contents \n";
    cout << "--------------------------------\n";
    CatTree.print();
    inpfile.close();
    cout << "\n---------------------------------------------------------------------------\n\n";
    return 0;
}
