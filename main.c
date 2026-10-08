#include <stdio.h>
int main(){
	
	int menu, qtdJogos, pontVitoria, pontEmpate, pontDerrota, pontTotal, totalVitoria, totalEmpate, totalDerrota;
	const int vitoria = 3, empate = 1, derrota = 0;

	printf("<===== MENU =====>\n");
	printf("1. Registrar resultados do campeonato\n");
	printf("2. Mostrar resumo do campeonato\n");
	printf("3. Mostrar regulamento\n");
	printf("4. Simular Campanha de uma Equipe\n");
	printf("5. Encerrar Sistema\n");
	printf("Escolha uma opção: ");
	scanf("%d", &menu);

	switch(menu){
		case 1:
			break;
		case 2: 
			break;
		case 3:
			break;
		case 4: { 
			
			int s, simJogos = 6, entradaValida, qtdSimulacao, simVitoria, simEmpate, simDerrota, simTotal, simTotalVitoria, simTotalEmpate, simTotalDerrota;
		
			printf("<===== SIMULADOR DE PONTUAÇÃO =====>\n Digite quantas simulações você deseja fazer (Somente entre 1 a 5): \n");
			scanf("%d", &qtdSimulacao);

				while (qtdSimulacao < 1 || qtdSimulacao > 5){
					printf("Digite um valor válido (Somente entre 1 a 5): \n");
					scanf("%d", &qtdSimulacao);
				}

			for(s = 1; s <= qtdSimulacao; s++){
				printf("Simulação %d\n", s);
				entradaValida = 0;

				while (entradaValida == 0) {

					printf("Quantas Vitórias, Empates e Derrotas a simulação da equipe terá.\n");
			
					printf("Digite a quantidade de vitórias: ");
					scanf("%d", &simVitoria);
			
					printf("Digite a quantidade de empates: ");
					scanf("%d", &simEmpate);
			
					printf("Digite a quantidade de derrotas: ");
					scanf("%d", &simDerrota);

					if (simVitoria < 0 || simEmpate < 0 || simDerrota < 0) {
						printf("Valores inválidos! Digite novamente.\n");
					} else if (simVitoria + simEmpate + simDerrota != simJogos) {
						printf("A soma das vitórias, empates e derrotas deve ser igual a %d. Digite novamente.\n", simJogos);
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
			break;

		default:
			printf("Opção inválida!\n");
			break;

	}
	return 0;
}
