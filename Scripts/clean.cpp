#include<bits/stdc++.h>

using namespace std;

unordered_map<string, int> grados;
string acordes[7];

void mapas(){
	grados["I"] = 0;
	grados["i"] = 0;
	grados["II"] = 1;
	grados["ii"] = 1;
	grados["III"] = 2;
	grados["iii"] = 2;
	grados["IV"] = 3;
	grados["iv"] = 3;
	grados["V"] = 4;
	grados["v"] = 4;
	grados["VI"] = 5;
	grados["vi"] = 5;
	grados["VII"] = 6;
	grados["vii"] = 6;

	acordes[0] = "I";
	acordes[1] = "II";
	acordes[2] = "III";
	acordes[3] = "IV";
	acordes[4] = "V";
	acordes[5] = "VI";
	acordes[6] = "VII";
}

int main(int argc, char* argv[]){// argv[1] = genero, argv[2] = numero de canciones.
	ios::sync_with_stdio(), cin.tie(0);
	mapas();
	string genero = argv[1];
	string output = "/home/sebasdeloco/Documentos/Melisma/melisma2003/dataset/"+genero+"/data_"+genero+".txt";
	ofstream out(output);
	set<string> se;
	vector<int> lengths;
	for(int k = 1; k <= stoi(argv[2]); k++){
		//if(k >=29 && k <= 30 && k != 26) continue;
		string input = "/home/sebasdeloco/Documentos/Melisma/melisma2003/roman/"+genero+"/";
		input += to_string(k);
		ifstream in(input);
		string chord, key = "", grado, sec, last = "";
		char linea[256];
		for(int i=0; i<3; i++){
			in.getline(linea, 256);	
		}
		vector<string> ans;
		while(in >> chord){
			if(chord[chord.length() - 1] == ':'){
				key += chord+" ";
			}else{
				bool isSecundary = false, sept = false;
				sec = "";
				grado = "";
				if(!ans.empty()) last = ans.back();
				for(auto x : chord){
					if(x == '/') isSecundary = true;
					else if(x >= '0' && x <= '9') sept = true;
					else if(isSecundary && x != '.' && x != '|' && x != ']' && x != '\n') sec += x;
					else if(x != '.' && x != '|' && x != ']' && x != '\n') grado += x;
				}
				if(isSecundary) grado = acordes[ (grados[grado] + grados[sec]) % 7 ];
				if(sept) grado += "7";
				if(grado == "Dim") grado = "vii";
				if(grado != "" && grado != "Chr" &&grado != last) ans.push_back(grado);
			}
		}
		for(auto x : ans){
			out << x << " ";
			se.insert(x);
			
		}
		out << '\n';
		lengths.push_back(ans.size());	
	}
	ofstream ma("/home/sebasdeloco/Documentos/Melisma/melisma2003/dataset/"+genero+"/dataset_"+genero+"_describe.txt");
	ofstream le("/home/sebasdeloco/Documentos/Melisma/melisma2003/dataset/"+genero+"/lengths_"+genero+".txt");
	int l = 0;
	ma << (int) lengths.size() <<'\n';
	for(int x : lengths){ ma << x << " "; le << x << " ";}
	ma << '\n'; ma << '\n';
	ma << se.size() << '\n';
	ofstream st("/home/sebasdeloco/Documentos/Melisma/melisma2003/dataset/"+genero+"/states_"+genero+".txt");
	for(auto x : se){
		ma << x << " " << l << '\n';
		st << x << " ";
		l++;
	}
	st << '\n';
	return 0;
}

