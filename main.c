/*
Matheus Vieira Rocha
Letícia ...
Kauã ...
*/

#include <stdio.h>
#include <stdlib.h>
int main(){
	system("chcp 65001 > nul");
	int menu, registrados = 0, qtdEquipes, qtdJogos, entradaValida, vFEmpates = 0, vFDerrotas = 0, vFVitorias = 0, totalFinal = 0, equipesExcelentes = 0, equipesBoas = 0, equipesRegulares = 0, equipesRuins = 0, maiorPont = 0, menorPont = 0, primeiraMaior = 0, primeiraMenor = 0, equipeMaior = 0, equipeMenor = 0;
	int vitoria = 3, empate = 1, derrota = 0;

	//Recebendo quantidades de jogos e equipes
	do
	{
		printf("DIGITE A QUANTIDADE DE EQUIPES (3-10):");
		scanf("%d", &qtdEquipes);
		if(qtdEquipes < 3 || qtdEquipes > 10)
			printf("Valor inválido!\n");
	} while (qtdEquipes < 3 || qtdEquipes > 10);
	do
	{
		printf("DIGITE A QUANTIDADE DE JOGOS POR EQUIPE (1-10):");
		scanf("%d", &qtdJogos);
		if(qtdJogos < 1 || qtdJogos > 10)
			printf("Valor inválido!\n");
	} while (qtdJogos < 1 || qtdJogos > 10);

	//Programa Principal
	do {
		//Exibindo Menu
		printf("\n<========== MENU ==========>\n");
		printf("1. Registrar resultados do campeonato\n");
		printf("2. Mostrar resumo do campeonato\n");
		printf("3. Mostrar regulamento\n");
		printf("4. Simular Campanha de uma Equipe\n");
		printf("5. Encerrar Sistema\n\n");
		printf("Escolha uma opção: ");
		scanf("%d", &menu);

		switch(menu){

			case 1:{
				int vitoriaEquipe, empateEquipe, derrotaEquipe, total;
				//Zerando variáveis para substituir registro anterior
				registrados = 0, vFEmpates = 0, vFDerrotas = 0, vFVitorias = 0, totalFinal = 0, equipesExcelentes = 0, equipesBoas = 0, equipesRegulares = 0, equipesRuins = 0, maiorPont = 0, menorPont = 0, primeiraMenor = 0, primeiraMaior = 0, equipeMaior = 0, equipeMenor = 0;

				//Passando de 1 até a quantidade de equipes
				for(int i = 1; i <= qtdEquipes; i++) {
					entradaValida = 0;
					while (!entradaValida){
						printf("\nEquipe %d:\n", i);
						printf("Digite a quantidade de vitórias: ");
						scanf("%d", &vitoriaEquipe);
				
						printf("Digite a quantidade de empates: ");
						scanf("%d", &empateEquipe);
				
						printf("Digite a quantidade de derrotas: ");
						scanf("%d", &derrotaEquipe);

						if(vitoriaEquipe < 0 || empateEquipe < 0 || derrotaEquipe < 0) {
							printf("Valores inválidos! Digite novamente.\n");
						} else if (vitoriaEquipe + empateEquipe + derrotaEquipe != qtdJogos) {
							printf("A soma das vitórias, empates e derrotas deve ser igual a %d. Digite novamente.\n", qtdJogos);
						} else {
							entradaValida = 1;
						}
					}
					//Aumentando valores para resumo
					vFVitorias += vitoriaEquipe;
					vFEmpates += empateEquipe;
					vFDerrotas += derrotaEquipe;
					total = vitoriaEquipe * vitoria + empateEquipe * empate + derrotaEquipe * derrota;
					//Pegando menor pontuação
					if(i == 1 || total < menorPont){
						menorPont = total;
						primeiraMenor = i;
						equipeMenor = 1;
					} else if(total == menorPont){
						equipeMenor++;
					}
					//Pegando maior pontuação
					if(i == 1 || total > maiorPont){
						maiorPont = total;
						primeiraMaior = i;
						equipeMaior = 1;
					} else if(total == maiorPont){
						equipeMaior++;
					}

					//Pegando pontuação final
					totalFinal += total;

					//Exibindo informações de cada equipe
					printf("\nEquipe %d: %d vitórias, %d empates e %d derrotas",i,vitoriaEquipe,empateEquipe,derrotaEquipe);
					printf("\nPontuação: %d", total);
					printf("\nSituação: ");
					if (total >= 15){
						printf("Excelente Campanha! \n\n");
						equipesExcelentes++;
					}
					else if (total >= 10){
						printf("Boa Campanha! \n\n");
						equipesBoas++;
					}
					else if (total >= 5){
						printf("Campanha Regular! \n\n");
						equipesRegulares++;
					}
					else{
						printf("Campanha Ruim! \n\n");
						equipesRuins++;
					}
				}

				//Permitindo o acesso ao resumo
				registrados=1;
				break;
			}
			case 2: 
				if (registrados == 1)
				{
					printf("\n\nQuantidade de equipes: %d\n", qtdEquipes);
					printf("Quantidade de jogos por equipe: %d\n", qtdJogos);
					printf("Total: %d vitórias, %d empates e %d derrotas\n", vFVitorias,vFEmpates,vFDerrotas);
					printf("Pontuação final: %d, Média: %.2f\n", totalFinal, (float) totalFinal / qtdEquipes);
					printf("Excelentes: %d, Boas: %d, Regulares: %d Ruins: %d\n",equipesExcelentes,equipesBoas,equipesRegulares,equipesRuins);
					printf("Maior pontuação: %d Primeira equipe: %d\nMenor pontuação: %d Primeira Equipe: %d", maiorPont, primeiraMaior, menorPont,primeiraMenor);
					printf("\nQuantidade de equipes empatadas na maior pontuação: %d", equipeMaior);
					printf("\nQuantidade de equipes empatadas na menor pontuação: %d\n\n", equipeMenor);
				} else{
					printf("\n\nRegistre os resultados primeiro.\n");
				}
				break;
			case 3:
				//Exibindo regulamento
				printf("\n\n<============ REGULAMENTO ============>\n");
				printf("Cada vitória equivale a %d pontos.\n", vitoria);
				printf("Cada empate equivale a %d ponto.\n", empate);
				printf("Cada derrota equivale a %d pontos.\n\n", derrota);
				
				printf("<============= SITUAÇÃO =============>\n");
				printf("15 ou mais pontos: Excelente campanha!\n");
				printf("Entre 10 e 14 pontos: Boa campanha!\n");
				printf("Entre 5 e 9 pontos: Campanha regular!\n");
				printf("Menos de 5 pontos: Campanha ruim!\n\n");
				
				printf("<============ REGULAMENTO ============>\n");
				printf("Você pode registrar de 3 a 10 equipes e de 1 a 10 jogos por equipe.\n\n");
				break;
			case 4: {
				//Inicializando variáveis para simulação
				int s, qtdSimulacao, simVitoria, simEmpate, simDerrota, simTotal, simTotalVitoria, simTotalEmpate, simTotalDerrota;
			
				printf("\n\n<========== SIMULADOR DE PONTUAÇÃO ==========>\n\n Digite quantas simulações você deseja fazer (Somente entre 1 a 5): ");
				scanf("%d", &qtdSimulacao);
				//Exibir caso o valor seja inválido
				while (qtdSimulacao < 1 || qtdSimulacao > 5){
					printf("Digite um valor válido (Somente entre 1 a 5): \n");
					scanf("%d", &qtdSimulacao);
				}

				for(s = 1; s <= qtdSimulacao; s++){
					printf("\n\n<========== SIMULAÇÃO %d ==========>\n\n", s);
					entradaValida = 0;

					while (!entradaValida) {

						printf("Quantas Vitórias, Empates e Derrotas a simulação da equipe terá?\n");
				
						printf("Digite a quantidade de vitórias: ");
						scanf("%d", &simVitoria);
				
						printf("Digite a quantidade de empates: ");
						scanf("%d", &simEmpate);
				
						printf("Digite a quantidade de derrotas: ");
						scanf("%d", &simDerrota);

						if (simVitoria < 0 || simEmpate < 0 || simDerrota < 0) {
							printf("Valores inválidos! Digite novamente.\n");
						} else if (simVitoria + simEmpate + simDerrota != qtdJogos) {
							printf("A soma das vitórias, empates e derrotas deve ser igual a %d. Digite novamente.\n", qtdJogos);
						} else {
							//Permitindo continuidade do programa
							entradaValida = 1;
						}
					}
					//Calculando valor final para exibir
					simTotalVitoria = simVitoria * vitoria;
					simTotalEmpate = simEmpate * empate;
					simTotalDerrota = simDerrota * derrota;
					simTotal = simTotalVitoria + simTotalEmpate + simTotalDerrota;

					printf("\n\nA equipe possui: %d pontos.", simTotal);
					if (simTotal >= 15){
						printf("\n Excelente Campanha! \n");
					}
					else if (simTotal >= 10){
						printf("\n Boa Campanha! \n");
					}
					else if (simTotal >= 5){
						printf("\n Campanha Regular! \n");
					}
					else{
						printf("\n Campanha Ruim! \n");
					}
				}
				break;
			}
			case 5:
				printf("\nSistema encerrado com sucesso.\nObrigado por utilizar o sistema.\n");
				break;

			default:
				printf("Opção inválida!\n");
				break;

		}
	} while(menu != 5);
	return 0;
}
