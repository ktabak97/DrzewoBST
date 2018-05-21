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

void safeFile(node *root) {
	string linia;
	fstream sfile;

	sfile.open("safe.txt", ios::out | ios::trunc);
	if (sfile.good() == true)
	{
		if (root != NULL)
		{
			safeFile(root->left);
			sfile << root->key << endl;
			safeFile(root->right);
		}

		sfile.close();
	}
}


int main()
{
	struct node *root = NULL;
	root = add(root, 5);


	if (!loadFile(root,"data.txt"))
		std::cout << "Error, cant open file" << std::endl;
	paint(root, 0);
	safeFile(root);
	return 0;

}

