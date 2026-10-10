#include <stdio.h>
#include <stdlib.h>
int main(){
	system("chcp 65001 > nul");
	int menu, qtdEquipes, qtdJogos, entradaValida, vFEmpates = 0, vFDerrotas = 0, vFVitorias = 0, totalFinal = 0, equipesExcelentes = 0, equipesBoas = 0, equipesRegulares = 0, equipesRuins = 0, maiorPont = 0, menorPont = 0, primeiraMaior = 0, primeiraMenor = 0, equipeMaior = 0, equipeMenor = 0;
	const int vitoria = 3, empate = 1, derrota = 0;
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
	do {
		printf("\n<========== MENU ==========>\n");
		printf("1. Registrar resultados do campeonato\n");
		printf("2. Mostrar resumo do campeonato\n");
		printf("3. Mostrar regulamento\n");
		printf("4. Simular Campanha de uma Equipe\n");
		printf("5. Encerrar Sistema\n\n");
		printf("Escolha uma opção: ");
		scanf("%d", &menu);

		switch(menu){
			case 1:
				int vitoriaEquipe, empateEquipe, derrotaEquipe, total;
				vFEmpates = 0, vFDerrotas = 0, vFVitorias = 0, totalFinal = 0, equipesExcelentes = 0, equipesBoas = 0, equipesRegulares = 0, equipesRuins = 0, maiorPont = 0, menorPont = 100, primeiraMenor = 0, primeiraMaior = 0, equipeMaior = 0, equipeMenor = 0;
				for(int i = 1; i <= qtdEquipes; i++) {
					entradaValida = 0;
					while (!entradaValida)
					{
						printf("Equipe %d: DIGITE A QUANTIDADE DE VITÓRIAS, EMPATES E DERROTAS (v,e,d): ",i);
						scanf("%d,%d,%d", &vitoriaEquipe,&empateEquipe,&derrotaEquipe);

						if(vitoriaEquipe < 0 || empateEquipe < 0 || derrotaEquipe < 0) {
							printf("Valores inválidos! Digite novamente.\n");
						} else if (vitoriaEquipe + empateEquipe + derrotaEquipe != qtdJogos) {
							printf("A soma das vitórias, empates e derrotas deve ser igual a %d. Digite novamente.\n", qtdJogos);
						} else {
							entradaValida = 1;
						}
					}
					vFVitorias += vitoriaEquipe;
					vFEmpates += empateEquipe;
					vFDerrotas += derrotaEquipe;
					total = vitoriaEquipe * vitoria + empateEquipe * empate + derrotaEquipe * derrota;
					if(i == 1 || total < menorPont){
						menorPont = total;
						primeiraMenor = i;
						equipeMenor = 1;
					} else if(total == menorPont){
						equipeMenor++;
					}

					if(i == 1 || total > maiorPont){
						maiorPont = total;
						primeiraMaior = i;
						equipeMaior = 1;
					} else if(total == maiorPont){
						equipeMaior++;
					}
					totalFinal += total;
					printf("\nEquipe %d: %d vitórias, %d empates e %d derrotas",i,vitoriaEquipe,empateEquipe,derrotaEquipe);
					printf("\nPontuação: %d", total);
					printf("\nSituação: ");
					if (total >= 15){
						printf("Excelente Campanha! \n\n", total);
						equipesExcelentes++;
					}
					else if (total >= 10){
						printf("Boa Campanha! \n\n", total);
						equipesBoas++;
					}
					else if (total >= 5){
						printf("Campanha Regular! \n\n", total);
						equipesRegulares++;
					}
					else{
						printf("Campanha Ruim! \n\n", total);
						equipesRuins++;
					}
				}
				break;
			case 2: 
				if (totalFinal != 0)
				{
					printf("\n\nQuantidade de equipes: %d\n", qtdEquipes);
					printf("Quantidade de jogos por equipe: %d\n", qtdJogos);
					printf("Total: %d vitórias, %d empates e %d derrotas\n", vFVitorias,vFEmpates,vFDerrotas);
					printf("Pontuação final: %d, Média: %.2f\n", totalFinal, (float) totalFinal / qtdEquipes);
					printf("Excelentes: %d, Boas: %d, Regulares: %d Ruins: %d\n",equipesExcelentes,equipesBoas,equipesRegulares,equipesRuins);
					printf("Maior pontuação: %d Primeira equipe: %d\nMenor pontuação: %d Primeira Equipe: %d", maiorPont, primeiraMaior, menorPont,primeiraMenor);
					printf("\nQuantidade de equipes empatadas na maior pontuação: %d", equipeMaior);
					printf("\nQuantidade de equipes empatadas na menor pontuação: %d", equipeMenor);
				} else{
					printf("\n\nRegistre os resultados primeiro.\n");
				}
				break;
			case 3:
				printf("<============ REGULAMENTO ============>\n");
				printf("Cada vitória equivale a 3 pontos.\n");
				printf("Cada empate equivale a 1 ponto.\n");
				printf("Cada derrota equivale a 0 pontos.\n\n");
				
				printf("<============= SITUAÇÃO =============>\n");
				printf("15 ou mais pontos: Excelente campanha!\n");
				printf("Entre 10 e 14 pontos: Boa campanha!\n");
				printf("Entre 5 e 9 pontos: Campanha regular!\n");
				printf("Menos de 5 pontos: Campanha ruim!\n\n");
				
				printf("<============ REGULAMENTO ============>\n");
				printf("Você pode registrar de 3 a 10 equipes e de 1 a 10 jogos por equipe.\n\n");
				break;
			case 4: { 
				int s, qtdSimulacao, simVitoria, simEmpate, simDerrota, simTotal, simTotalVitoria, simTotalEmpate, simTotalDerrota;
			
				printf("<========== SIMULADOR DE PONTUAÇÃO ==========>\n\n Digite quantas simulações você deseja fazer (Somente entre 1 a 5): ");
				scanf("%d", &qtdSimulacao);

				while (qtdSimulacao < 1 || qtdSimulacao > 5){
					printf("Digite um valor válido (Somente entre 1 a 5): \n");
					scanf("%d", &qtdSimulacao);
				}

				for(s = 1; s <= qtdSimulacao; s++){
					printf("<========== SIMULAÇÃO %d ==========>\n\n", s);
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
							entradaValida = 1;
						}
					}

					simTotalVitoria = simVitoria * vitoria;
					simTotalEmpate = simEmpate * empate;
					simTotalDerrota = simDerrota * derrota;
					simTotal = simTotalVitoria + simTotalEmpate + simTotalDerrota;

					if (simTotal >= 15){
						printf("A equipe possui: %d pontos. \n Excelente Campanha! \n", simTotal);
					}
					else if (simTotal >= 10){
						printf("A equipe possui: %d pontos. \n Boa Campanha! \n", simTotal);
					}
					else if (simTotal >= 5){
						printf("A equipe possui: %d pontos. \n Campanha Regular! \n", simTotal);
					}
					else{
						printf("A equipe possui: %d pontos. \n Campanha Ruim! \n", simTotal);
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
