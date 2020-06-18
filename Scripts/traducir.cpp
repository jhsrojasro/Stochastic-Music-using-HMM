#include<bits/stdc++.h>

using namespace std;

int main(int argc, char* argv[]){//argv[1] = genero
	unordered_map<string, int> ma;
	string genero = argv[1];
	ifstream in_map("/home/sebasdeloco/Documentos/Melisma/melisma2003/dataset/"+genero+"/dataset_"+genero+"_describe.txt");
	ofstream out("/home/sebasdeloco/Documentos/Melisma/melisma2003/dataset/"+genero+"/data_"+genero+"_tr.txt");
	int n, c, key;
	in_map >> n;
	int lengths[n];
	for(int i=0; i<n; i++){
		in_map >> lengths[i];
	}
	in_map >> c;
	string chord;
	for(int i=0; i<c; i++){
		in_map >> chord >> key;
		ma[chord] = key;
	}
	in_map.close();
	ifstream in_data("/home/sebasdeloco/Documentos/Melisma/melisma2003/dataset/"+genero+"/data_"+genero+".txt");
	for(int i=0; i<n; i++){
		for(int j = 0; j < lengths[i]; j++){
			in_data >> chord;
			out << ma[chord] << " ";
		}
	}
	return 0;
}