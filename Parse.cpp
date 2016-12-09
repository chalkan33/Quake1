#include <iostream>
#include <stdio.h>
#include <sstream>
#include <map>
using namespace std;



void parse(){
		int game = 0, totalkill = 0, firstGame = 1, comecou_jogo = 0;
	string entrada,player1,player2, mod_kill;
	map<string,int> players, mode;
	// Enquanto haver coisas para ler
	
	while(getline(cin, entrada)){
		istringstream iss(entrada);
		iss >> entrada; // tira o cabe�alho (horas)
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
		if(player1 != "<world>") // Aumenta a pontuação caso não seja o <world>
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
