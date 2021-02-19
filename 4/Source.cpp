#include <iostream>
#include <string>
#include <conio.h>
#include <fstream>

using namespace std;

class Huffman {
private:
	struct Node {
		double p;
		char c;
		Node *left, *right, *parent;
	};
	Node *trees[256], *symbols[256];
	int size;
public:
	Huffman(int k) {
		size = k;
	}
	void read(char c, double p, int i) {
			trees[i] = new Node;
			symbols[i] = trees[i];
			cout << "Symbol: "; trees[i]->c = c; cout << trees[i]->c << endl;
			cout << "Prob: "; trees[i]->p = p; cout << trees[i]->p << endl;
			cout << endl;
			trees[i]->left = 0;
			trees[i]->right = 0;
			trees[i]->parent = 0;
	}
	void makeTree(int col) {
		if (col > 1) {
			double min1 = 1;
			int n1 = 0;
			for (int i = 0; i<size; i++)
				if (trees[i] != NULL && trees[i]->p < min1) {
					min1 = trees[i]->p;
					n1 = i;
				}
			double min2 = 1;
			int n2 = 0;
			for (int i = 0; i<size; i++)
				if (trees[i] != NULL && trees[i]->p < min2 && i != n1) {
					min2 = trees[i]->p;
					n2 = i;
				}
			Node *tmp = new Node;
			tmp->left = trees[n1];
			tmp->right = trees[n2];
			trees[n1]->parent = tmp;
			trees[n2]->parent = tmp;
			tmp->p = min1 + min2;
			tmp->parent = NULL;
			trees[n1] = tmp;
			trees[n2] = NULL;
			makeTree(col - 1);
		}
	}
void Show(string *Catch) {
				*Catch += "[";
		if (size == 1) cout << symbols[0]->c << "-" << 0 << endl;
		else {
			for (int i = 0; i < size; i++) {
				Node *tmp = symbols[i];
				string code = " ";
				while (tmp->parent != NULL) {
					if (tmp->parent->left == tmp)
						code = "0" + code;
					else code = "1" + code;
					tmp = tmp->parent;
				}
				cout << symbols[i]->c << ": " << code << endl;
				*Catch += symbols[i]->c;
				*Catch += ": ";
				*Catch += code;
				if(i + 1 != size)*Catch += ",";
			}
				
		}
				*Catch += "]";
	}

};

void main() {
	//START COUNT
	ifstream INPUT;
	string STRCOPY;
	string tmp123;
	int Herz[256];
	int i = 0;
	int count = 0;
	INPUT.open("INPUT.txt");
	while (!INPUT.eof()) { getline(INPUT, tmp123); STRCOPY += tmp123; }
	for (int i = 0; i < 256; i++) { Herz[i] = 0; }
	//cout << STRCOPY << endl;DEBUG
	//cout << STRCOPY.length() << endl;DEBUG
	while (i != (tmp123.length())) { Herz[int(tmp123[i])]++; i++; }i = 0;//Узнаем колличество битовых вхождений
	for (int i = 0; i < 256; i++) { if (Herz[i] != 0) { count++; } }
	Huffman tree(count);
	int j = 0;
	for (int i = 0; i < 256; i++) { if (Herz[i] != 0) { double temp = double(Herz[i]) / double(STRCOPY.length()); cout << char(i) << ":" << temp << endl; tree.read(char(i), temp, j++);}  }
	//END COUNT
	tree.makeTree(count);
	cout << endl;
	string Catch = "";
	tree.Show(&Catch);
	cout << Catch << endl;
	//KOD
	INPUT.close();
	ofstream OUTPUT;
	OUTPUT.open("OUTPUT.txt");
	OUTPUT << Catch;
	OUTPUT.close();
	system("pause");
};
		
