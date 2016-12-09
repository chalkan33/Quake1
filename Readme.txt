--Setup : Abrir o CMD , ir até o repositorio onde o programa está instalado, usar o comando [nome do programa] parse.exe <[nome do arquivo] entrada.in


--ler linha a linha do arquivos , assim que tiver o "Kill" coloca o valor do player nas variaveis e assim que ver que um jogo terminou então se reseta as variaveis.



--O Escopo do problema é pegar um log gerado pelo servidor de quake 3 arena e fazer um parse para que se gera algo neste estilo 
----------------------------------------------------------------------------------------------------------------------
game_1: {
    total_kills: 45;
    players: ["Dono da bola", "Isgalamido", "Zeh"]
    kills: {
      "Dono da bola": 5,
      "Isgalamido": 18,
      "Zeh": 20
    }
  }
----------------------------------------------------------------------------------------------------------------------
"game-1": {
    kills_by_means: {
        "MOD_SHOTGUN": 10,
        "MOD_RAILGUN": 2,
        "MOD_GAUNTLET": 1,
        "XXXX": N
    }
}
----------------------------------------------------------------------------------------------------------------------