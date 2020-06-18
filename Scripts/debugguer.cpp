#include<iostream>
#include<cstdlib>
#include<fstream>

using namespace std;

int main(int argc, char* argv[]){
	string input = "/home/sebasdeloco/Documentos/Melisma/melisma2003/temp/";
	string arg = argv[1]; 
	input += arg;
	//cout << input << '\n';
	string output =  input;
	output += "_debug";
	//cout << output << '\n';	
	ifstream in(input);
	string first;
	in >> first;
	while(first != "Note"){
		char linea[256];
		in.getline(linea, 256);
		in >> first;
	}
	ofstream out(output);
	int begin, end, pitch;
	do{
		in >> begin >> end >> pitch;
		out << "Note  " << begin << "  " << (end >= begin ? end : begin + 1) << "  " << pitch << '\n';	
	}while(in >> first);
	in.close();
	out.close();
	return 0;
}