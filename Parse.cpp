#include <iostream>
#include <stdio.h>
#include <sstream>
#include <map>
using namespace std;

void print_result(int game, map<string,int> players, map<string,int> mode, int totalkill){ //funÁ„o para gerar os results
	int flag_first = 1;
	printf("game_%d: {\n", ++game);
	printf("\ttotal_kills: %d;\n",totalkill);
	printf("\tplayers: [");

	for(map<string,int>::iterator it = players.begin(); it != players.end(); it++){ //iteraÁao pelo mapa , vendo todos os player e printando eles
		if(flag_first){
			printf("\"%s\"",it->first.c_str());
			flag_first = 0;
		}
		else
			printf(", \"%s\"",it->first.c_str());
	}
	printf("]\n");
	printf("\tkills: {\n");
	flag_first = 1;
	for(map<string,int>::iterator it = players.begin(); it != players.end(); it++)//iteraÁao pelo mapa , vendo todos os player e printando eles
		printf("\t\t\"%s\":%d,\n",it->first.c_str(), it->second-1);
	printf("\t}\n");
	printf("}\n");
	

	printf("\"game-%d\": {\n", game);
	printf("\tkills_by_means: {\n");
	for(map<string,int>::iterator it = mode.begin(); it != mode.end(); it++)////iteraÁao pelo mapa , vendo todos os modos e printando eles
		printf("\t\t\"%s\":%d,\n",it->first.c_str(), it->second);
	printf("\t}\n");
	printf("}\n");
}

void parse(){
		int game = 0, totalkill = 0, firstGame = 1, comecou_jogo = 0;
	string entrada,player1,player2, mod_kill;
	map<string,int> players, mode;
	// Enquanto haver coisas para ler
	
	while(getline(cin, entrada)){
		istringstream iss(entrada);
		iss >> entrada; // tira o cabeÁalho (horas)
		iss >> entrada; // tira o segundo token
		if(entrada == "ShutdownGame:"){ //verifica se terminou um jogo
			comecou_jogo = 0;
			print_result(game++, players, mode, totalkill);
			totalkill = 0;
			players.clear();
			mode.clear();
			continue;
		}
		else if(entrada != "Kill:") continue;
		iss >> entrada; // Retira numeros
		iss >> entrada;
		iss >> entrada;
		player1 = player2 = "";
		// le o jogador 1
		iss >> entrada;
		while(entrada != "killed"){
			player1 += entrada;
			iss >> entrada;
		}
		// Conseguiu um kill
		if(player1 != "<world>") // Aumenta a pontua√ß√£o caso n√£o seja o <world>
			players[player1]++;
		// le o jogador 2
		iss >> entrada;
		while(entrada != "by"){
			player2 += entrada;
			iss >> entrada;
		}
		if(player1 == "<world>")
			players[player2]--;
		// le o modo que foi morto
		iss >> mod_kill;
		// incrementa o modo que foi morto
		mode[mod_kill]++;
		totalkill++;
	}
}




int main(){
parse();

}
