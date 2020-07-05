#include <iostream>
#include <boost/algorithm/string.hpp>
#include <vector>
#include <unordered_map>

using namespace std;

class mfs {
	private:
		struct node {
			bool is_d;
			string name;
			unordered_map<string, node*> children;
			int c_idx;
		};
		node *root;
		vector<string> files;

		node* create_node (string name, bool is_dir) {
			node* new_node = new node();
			new_node->name = name;
			new_node->is_d = is_dir;
		}
		//get file/dir
		node* get_node(string path) {
			vector<string> dirs;
			boost::split(dirs, path, boost::is_any_of("/"));
			vector<string> entries;

			node *curr = root;
			if (root == NULL)
					return NULL;
			for (int i = 0; i < dirs.size(); i++) {
				if (curr->children.find(dirs[i]) == curr->children.end()) {
					return NULL;
				}
				else {
					curr = curr->children[dirs[i]];
				}
			}
			return curr;
		}
	public:
		mfs () {
			//this->root = NULL;
			this->root = create_node("d", true);
		}
		vector<string> ls (string path) {
			vector<string> entries;
			node *curr = get_node(path);
			if (curr == NULL)
				return entries;
			if (curr->is_d) {
				for (auto entry = curr->children.begin(); entry != curr->children.end(); entry++) {
					entries.push_back(entry->first);
				}
			}
			else {
				entries.push_back(curr->name);
			}
			return entries;
		}

		void mkdir (string path) {
			vector<string> dirs;
			boost::split(dirs, path, boost::is_any_of("/"));
			node *curr = root;
			for (int i = 0; i < dirs.size(); i++) {
				if (curr->children.find(dirs[i]) == curr->children.end()) {
					curr->children[dirs[i]] = create_node(dirs[i], true);
					curr =  curr->children[dirs[i]];
				}
				else {
					curr = curr->children[dirs[i]];
				}
			}
		}

		void addContentToFile (string path, string content) {
			vector<string> dirs;
			boost::split(dirs, path, boost::is_any_of("/"));
			node *curr = root;
			for (int i = 0; i < dirs.size(); i++) {
				if (curr->children.find(dirs[i]) == curr->children.end()) {
					curr->children[dirs[i]] = create_node(dirs[i], true);
					curr =  curr->children[dirs[i]];
				}
				else {
					curr = curr->children[dirs[i]];
				}
			}
			//new file
			if (curr->is_d) {
				curr->is_d = false;	
				curr->c_idx = files.size();
				files.push_back(content);
			}
			//append the content
			else {
				//string cont = files[curr->c_idx];
				files[curr->c_idx] += content;
			}
		}

		string readContentFromFile(string path) {
			vector<string> dirs;
			boost::split(dirs, path, boost::is_any_of("/"));
			node *curr = root;
			for (int i = 0; i < dirs.size(); i++) {
				if (curr->children.find(dirs[i]) == curr->children.end()) {
					return "";
				}
				else {
						curr = curr->children[dirs[i]];
				}
			}
			return files[curr->c_idx];
		}
};

int main() {
	//create root
	mfs fs;
	vector<string> conts = fs.ls ("d");
	for (auto cont: conts)
			cout<<cont<<endl;
	cout<<"done1"<<endl;
	fs.mkdir ("d/a/b/c");
	fs.addContentToFile("d/a/b/c/d", "hello");
	conts = fs.ls ("d");
	for (auto cont: conts)
			cout<<cont<<endl;
	cout<<"done2"<<endl;
	cout<<fs.readContentFromFile("d/a/b/c/d")<<endl;
	return 0;
}
