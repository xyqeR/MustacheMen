#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main(){
	ofstream INPUT;
	INPUT.open("INPUT.txt");
	string Reserv;
	for (int i = 0; i < 256; i++){
	Reserv += char(i);
	Reserv += " ";
	}
	INPUT << Reserv;
	
}

