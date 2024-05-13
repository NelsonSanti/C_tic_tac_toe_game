/*
	Name: Jogo do Galo
	Copyright: Nelson Santiago
	Author: Nelson Santiago
	Date: 22/03/24 21:01
	Description: Projeto no âmbito do curso J+D Programação em Python, UFCD 10790
*/



#include <stdio.h>
#include <stdbool.h>
#include<stdlib.h>
#include<windows.h>
#include<math.h>
#include<conio.h>
#include<time.h>
#include<locale.h>

char grelha[3][3];
bool ocupada[9];

char botao;
char botao1;
char escolha;
char jogador;
int jogadorX_vitorias=0;
int jogadorO_vitorias=0;
char respJogosGanhos;

//matriz com tabela inicial.
//Loop de linhas i e loop de colunas j
//i*3 calcula número correspondente à linha em que estamos. como sáo 3 linhas, multiplicamos 1 por 3, 2 por 3, 3 por 3.
// j representa a movimentação da coluna, que vai de 0 a 2 (3 indexes). somado ao resultado i*3 por cada repetição, obtemos o número de cada casa.
// exemplo: se i=0 e j=1 , 0 * 3 == 0. 0+1 == 1 -> casa 1
//Exemplo: se i=0 e j=2, 0 * 3 == 0. 0+2 == 2 -> casa 2 
//exemplo: se i=1 e j=0, 1 * 3 == 3. 3+0 == 3 -> casa 3 e assim sucessivamente.
//'1' é o decimal 49 e representa o caractere que vai corresponder a cada posição na tabela e vai subindo até ao 9. Se começássemos por exemplo no 2, a nona casa seria ':'
//que corresponde ao 10 na tabela ASCII
void tabela_inicial() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            grelha[i][j] = '1' + (i * 3) + j;
        }
    }
}



//função print da grelha e respetiva distribuição das casas de acordo com a linha (0,1,2) e a coluna (0,1,2)
void print_grelha() {
    printf("\n");
    printf(" %c | %c | %c \n", grelha[0][0], grelha[0][1], grelha[0][2]);
    printf("-----------\n");
    printf(" %c | %c | %c \n", grelha[1][0], grelha[1][1], grelha[1][2]);
    printf("-----------\n");
    printf(" %c | %c | %c \n", grelha[2][0], grelha[2][1], grelha[2][2]);
    printf("\n");
}
//função booleana que verifica o vencedor e retorna verdadeiro se as condições forem reunidas, com o parâmetro 'jogador'
bool verifica_vencedor(char jogador) {
    // verifica se o jogador preencheu todas as casas numa linha ao fim de cada jogada. Se sim, é verdadeiro, se não, retorna falso e sai do loop.
    for (int i = 0; i < 3; i++) {
        if (grelha[i][0] == jogador && grelha[i][1] == jogador && grelha[i][2] == jogador)
            return true;
    }

    // verifica se o jogador preencheu todas as casas numa coluna ao fim de cada jogada. Se sim, é verdadeiro, se não, retorna falso sai do loop.
    for (int i = 0; i < 3; i++) {
        if (grelha[0][i] == jogador && grelha[1][i] == jogador && grelha[2][i] == jogador)
            return true;
    }

     // verifica se o jogador preencheu todas as casas ao fim de cada jogada numa diagonal OU na outra diagonal. Se sim, é verdadeiro, se não, retorna falso sai do loop.
    if ((grelha[0][0] == jogador && grelha[1][1] == jogador && grelha[2][2] == jogador) ||
        (grelha[0][2] == jogador && grelha[1][1] == jogador && grelha[2][0] == jogador))
        return true;

    return false;
}
	//função que configura a opção 1 do menu e que imprime o número de jogos ganhos por cada jogador
	//A variavel e o operador condicional não influenciam aqui para o número de jogos ganhos.
	//coloquei aqui por uma questão de leitura. O jogador_atual é inicialmente 'X' e a operação condicional
	//verifica se o jogador_atual é 'X'. Se ao fim da jogada, o jogador for 'X', ele altera para 'O' para a próxima jogada
	//se não for, ele volta a alterar para 'X' no fim da jogada 'O'.
	//jogadorX_vitorias e jogadorO_vitorias são duas variáveis que contam o número de jogos ganhos por cada jogador.
void jogos_ganhos(){
	char jogador_atual = 'X';
	jogador_atual = (jogador_atual == 'X') ? 'O' : 'X';
	
	printf("\nNumero de jogos ganhos pelo jogador X: %d", jogadorX_vitorias);
	printf("\nNumero de jogos ganhos pelo jogador O: %d", jogadorO_vitorias);
	

}



int main() {
	
		//Abertura do jogo
	//Splash screen com astericos, um em cada índice para poder fazer os laterais.
	//Desafio foi colocar todas as backslashes para que as backslashes individuais aparececem
	char splash[10][500]={"\n*     ----.                          .___         ________       .__             *",
	                      "*    |    | ____   ____   ____     __| _/____    /  _____/_____  |  |   ____     *",
						  "*    |    |/  _ \\ / ___\\ /  _ \\   / __ |/  _ \\  /   \\  ___\\__  \\ |  |  /  _ \\    *""",
					      "*/\\__|    (  <_> ) /_/  >  <_> ) / /_/ (  <_> ) \\    \\_\\  \\/ __ \\|  |_(  <_> )   *",
					      "*\\________|\\____/\\___  / \\____/  \\____ |\\____/   \\______  (____  /____/\\____/    *",
					      "*               /_____/               \\/                \\/     \\/                *",
						  "*                                                                                *",
						  "*                                                                                *"};
	
	
	menu_principal:
	for(int contEstrelas=0; contEstrelas <=80; contEstrelas++){
		printf("*");
	}
	
	
	for(int i=0; i <=7; i++){
		printf("%s\n", splash[i]);	
	}
	printf("\n");
	for(int contEstrelas1=0; contEstrelas1 <=80; contEstrelas1++){
		printf("*");
		}
	

	printf("\n              ** Prima 'e' para ir para o Menu Principal **");
	botao=getch();
	if(botao=='e' || botao=='E'){
		printf("\a");
		Sleep(3000);
		system("CLS");
	}
	else{
		if(botao!='e' || botao=='E'){
			printf("\a");
			system("color c0");
			printf("\n               Prima apenas a tecla 'e' ou 'E' para entrar");
			Sleep(3000);
			system("CLS");
			system("color 0f");
			goto menu_principal;
		}
	}
	
	//Início do jogo
	numero_escolhas:
	for(int contEstrelas2=0; contEstrelas2<=48;contEstrelas2++){
		printf("*");
	}
	system("color f0");
	printf("\n* Jogo do Galo - Nelson Santiago | Menu Inicial *\n");
	for(int contEstrelas2=0; contEstrelas2<=44; contEstrelas2++){
		printf("*");
	}
	printf("2024");
	
	printf("\n1: Jogos ganhos por cada utilizador");
	printf("\n2: Iniciar jogo");
	printf("\n3: Sair do jogo");
	printf("\n\nPrima o numero correspondente a sua escolha: ");
	do{
	escolha=getch();
	if(escolha !='1' && escolha !='2' && escolha != '3'){
		printf("\a");
		system("color c0");
		printf("\nPrima apenas a tecla '1' ou '2' ou a '3'");
		Sleep(3000);
		system("CLS");
		system("color 0f");
		goto numero_escolhas;
	}
	}while(escolha !='1' && escolha !='2' && escolha != '3');
	
	//Sair
	if(escolha=='3'){
		printf("\nA sair do jogo!");
		Sleep(3000);
		system("CLS");
	}
	if(escolha=='2'){
		system("CLS");
		Sleep(3000);
	//jogar	
	repetir_jogo:
	for(int reset=0; reset<9; reset++){
		ocupada[reset]=0;
	}
    tabela_inicial();
    char jogador_atual = 'X';

    while (true) {
    	joga_outra_vez:
    	for(int contEstrelas3=0; contEstrelas3<=48;contEstrelas3++){
			printf("                 *");
		}
			printf("\n                           *     Comecou! Por favor, escolha um numero     *\n");
		
		printf("\n\n");
        print_grelha();
		
		//Queremos que as posições sejam ocupadas por caracteres mas enquanto escolha do utilizador e para usar o getch
		//Tive de usar posições em int e convertê-las em char (Não estava a funcionar de outra forma).
		//Utilizando a tabela ASCII verifiquei os valores de char (0 a 9) correspondentes aos decimais (48 ao 57).
		//Ao valor de char clicado pelo utilizador, vai ser subtraído o valor de char 0, que é 48.
		//Assim, se por exemplo o utilizador clicar em 3 (51 em decimais), fazemos 51 - 48 == 3.
		//'X' ou 'O' ocuparia a casa 3.
        printf("Jogador %c, escolha um numero (1-9): ", jogador_atual);
        int posicao;
        char ch;
        ch=getch();
        posicao=int(ch-48);
        
        
        
        if (posicao < 1 || posicao > 9) {
        	printf("\a");
			system("color c0");
        	printf("Posicao invalida. Por favor escolha um numero entre 1 e 9.\n");
        	Sleep(3000);
        	system("CLS");
        	system("color f0");
        	goto joga_outra_vez;
        }
        
        
        //a variável "ocupada[posicao -1]" é booleana com 9 índices e retorna verdadeiro mais em baixo, se alguma das casas estiver ocupada quando outro jogador tenta lá jogar, impedindo assim a jogada.
        if (ocupada[posicao - 1]) {
            printf("\a");
			system("color c0");
        	printf("Posicao ocupada. Por favor, escolha outra.\n");
        	Sleep(3000);
        	system("CLS");
        	system("color f0");
        	goto joga_outra_vez;
        }
        
        system("CLS");
		//serve para inserir a linha e a coluna em que a jogada ficará
		//linha é o int indicado pelo jogador de 1 a 9, e -1 para corresponder ao lugar do indice que vai de 0 a 8
		//(posicao -1) / 3 divide o valor do número introduzido pelo utilizador por 3. o resultado dita a linha onde estará a posição, sem ter em conta as casas decimais (apenas 1, 2 ou 3)
		//posicao -1) % 3 calcula o RESTO da divisão do número introduzido, por 3. e dá-nos o número da coluna.
		//cada um dos números introduzidos são assignadas aos respetivos índices em baixo na grelha.
        int linha = (posicao - 1) / 3;
        int coluna = (posicao - 1) % 3;

        grelha[linha][coluna] = jogador_atual;
        ocupada[posicao - 1] = true;
		
		//Verifica o vencedor.
		//contém duas variáveis, "jogadorX_vitorias" e "jogadorO_vitorias" que são um contador de vitórias e que foram inicializadas em cima como zero.
		//serão depois utilizadas na opção 1, para verificar o número de vitórias de cada jogador.
		//Aqui, depois de ultrapassadas todas as condições, é chamada a função verificar_vencedor, com o argumento "jogador_atual".
		//Se na jogada anterior a esta verificação o jogador_atual for 'X', 'X' vence, caso contrário, 'O' vence.
        if (verifica_vencedor(jogador_atual)) {
        	if(jogador_atual == 'X'){
        		jogadorX_vitorias++;
			}
			else{
				jogadorO_vitorias++;
			}
        	system("color 2f");
            print_grelha();
            printf("Jogador %c venceu! Parabens \n", jogador_atual);
            Sleep(4000);
            break;
            
        }
		//Verifica se há empate
		//a variável "empate" é booleana e está declarada como verdadeira. O código verifica depois se é verdade ou não.
		//em 9 iterações que representam as posições na grelha, são verificados os 9 índices da variável "ocupada".
		//O operador de negação '!' em !ocupada[i] significa que se !ocupada[i] é verdade se a posição não estiver 'i' não estiver ocupada, retorna falso e sai do ciclo para a próxima jogada.
		//se um índice estiver ocupado, o programa mantém o ciclo e procura outro índice.
		//se os 9 índices estiverem ocupados, o programa assume a variável inicial 'empate' como verdadeira.
        bool empate = true;
        for (int i = 0; i < 9; i++) {
            if (!ocupada[i]) {
                empate = false;
                break;
            }
        }

        if (empate) {
            print_grelha();
            printf("Jogo empatado!\n");
            break;
        }
		//verifica se o jogador_atual é 'X'. Se ao fim da jogada, o jogador for 'X', ele altera para 'O' para a próxima jogada
		//se não for, ele volta a alterar para 'X' no fim da jogada 'O'.
       jogador_atual = (jogador_atual == 'X') ? 'O' : 'X'; 
        
    }
    	char repetir;
        puts("\n\nDeseja repetir o jogo? s[im], n[ao]: ");
        puts("\nPrima apenas 's/S' para sim ou 'n/N' para nao");
        do{	
        repetir=getch();
        if(repetir!='s' && repetir!='S' && repetir!='n' && repetir!='N'){
        	printf("\a");
			system("color c0");
        	Sleep(3000);
        	system("color f0");
        	
        }
		}while(repetir!='s' && repetir!='S' && repetir!='n' && repetir!='N');
        if(repetir=='s' || repetir=='S'){
        	system("CLS");
        	system("color f0");
        	goto repetir_jogo;
        	
		}
		else
			if(repetir=='n' || repetir=='N'){
				
				printf("\nDeseja ver o numero de jogos ganhos?\n s[im], n[ao]: ");
				puts("\nPrima apenas 's/S' para sim ou 'n/N' para nao");
				do{
				respJogosGanhos=getch();
				if(respJogosGanhos != 's' && respJogosGanhos!='S' && respJogosGanhos!='n' && respJogosGanhos!='N'){
					printf("\a");
					system("color c0");
        			Sleep(3000);
        			system("color f0");
				}
			}while(respJogosGanhos !='s' && respJogosGanhos!='S' && respJogosGanhos!='n' && respJogosGanhos!='N');
				if(respJogosGanhos == 's' || respJogosGanhos == 'S'){
					goto verifica_jogos;
				}
				else
					if(respJogosGanhos == 'n' || respJogosGanhos == 'N'){
						printf("\nVai ser redirecionado para o menu principal. Escolha a opcao 3 para sair.");
						Sleep(3000);
						system("color 0f");
						system("CLS");
						goto menu_principal;
					}
				
			}
	
	}
	char voltar_menu;
	if(escolha=='1'){
		verifica_jogos:
		system("color 0f");
		system("CLS");
		Sleep(3000);
		printf("\n\t\tJogos ganhos por cada utilizador");
		printf("\n\n");
		jogos_ganhos();
		printf("\n\n\nVoltar ao menu principal? s[im] n[ao]");
		printf("\nPrima apenas 's/S' para sim ou 'n/N' para nao");
		do{
		voltar_menu=getch();
		if(voltar_menu != 's' && voltar_menu!='S' && voltar_menu!='n' && voltar_menu!='N'){
			printf("\a");
			system("color c0");
        	Sleep(3000);
        	system("color 0f");
		}	
		}while(voltar_menu != 's' && voltar_menu!='S' && voltar_menu!='n' && voltar_menu!='N');
		if(voltar_menu=='s' || voltar_menu=='S'){
			printf("\nVai ser redirecionado para o menu principal. Escolha a opcao 3 para sair.");
			Sleep(3000);
			system("color 0f");
			system("CLS");
			goto menu_principal;
		}
		else
			if(voltar_menu=='n' || voltar_menu=='N'){
				printf("\nObrigado por ter jogado ao meu jogo. O programa vai fechar!");
				Sleep(3000);
				system("CLS");
			}
			
		//FIM
		
}
	
	
	
}
