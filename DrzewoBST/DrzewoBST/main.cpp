#include "Header.h"


void doOperation(struct node *root, string instruction, int number)
{
	if (instruction == "add")
	{
		add(root, number);
	}
	else if (instruction == "display")
	{
		display(root);
	}
	else if (instruction == "min")
	{
		findMinNode(root);
	}
	else if (instruction == "max")
	{
		findMaxNode(root);
	}
	else if (instruction == "delete")
	{
		deleteNode(root, number);
	}
	else
	{
		cout << "Error" << endl;
	}
}

bool loadFile(struct node *root, string fileName)
{
	ifstream file;
	file.open(fileName.c_str());
	if (!file.good())
		return false;

	while (true)
	{
		string a;
		int b;
		file >> a >> b;
		if (file.good()) {
			doOperation(root, a, b);
			//cout << a << b;//kontrola wejscia
		}
		else
			break;

	}
	return true;
}

void saveFile(node *root) {
	ofstream out;
	out.open("save.txt", ios::out | ios::app);
	if (out.good() == true)
	{
		if (root != NULL) 
		{
			saveFile(root->left);
			out << root->key << "  ";
			saveFile(root->right);
		}
	}
	out.close();
}


int main()
{
	struct node *root = NULL;
	root = add(root, 5);


	if (!loadFile(root,"data.txt"))
		std::cout << "Error, cant open file" << std::endl;
	paint(root, 0);
	saveFile(root);
	getchar();
	return 0;

}

