// Importa a biblioteca padrao de entrada e saida (Standard Input Output). 
// Necessaria para usar os comandos printf (mostrar na tela) e scanf (ler do teclado).
#include <stdio.h> 

// Importa a biblioteca para manipulacao de strings (textos).
#include <string.h> 

// 'typedef struct' cria um tipo de dado personalizado. 
// Estamos criando um "molde" chamado 'Questao' para organizar os dados do quiz.
typedef struct {
    // 'char' cria uma variavel de texto. '[200]' define o tamanho maximo de 200 caracteres.
    char pergunta[200];       
    
    // Matriz de caracteres: 4 linhas (opcoes) com ate 50 caracteres cada.
    char opcoes[4][50];       
    
    // 'int' cria uma variavel de numero inteiro para guardar o numero da resposta certa.
    int alternativaCorreta;   
    
    // Variavel de texto para guardar a explicacao da resposta.
    char justificativa[200];  
} Questao; // Nome do nosso tipo personalizado.

// Funcao principal do programa. O computador comeca a executar o codigo por aqui.
int main() 
{
    // Cria uma variavel de texto (vetor de caracteres) que pode guardar ate 15 letras para o nome.
    char nomejogador[15];
    
    // Cria variaveis inteiras. 'resultado' ja comeca valendo 0 para nao ter lixo de memoria.
    int opcao, resultado, alternativa, jogarNovamente; 

    // Cria um array (lista) chamado 'quiz' que contem 20 elementos do tipo 'Questao' que criamos la em cima.
    Questao quiz[20] = {
        // --- 10 PERGUNTAS NORMAIS ---
        {
            "1. Qual e o numero do Pikachu na Pokedex Nacional?",
            {"1) #001", "2) #025", "3) #052", "4) #151"},
            2,
            "O Pikachu e o 25 numero da Pokedex Nacional."
        },
        {
            "2. Qual desses Pokemon NAO e do tipo Dragao puro?",
            {"1) Dratini", "2) Dragonair", "3) Dragonite", "4) Haxorus"},
            3,
            "Dragonite e dos tipos Dragao e Voador, os outros sao Dragao puro."
        },
        {
            "3. Qual e a evolucao do Eevee que e ativada com uma Pedra do Trovao?",
            {"1) Jolteon", "2) Flareon", "3) Vaporeon", "4) Espeon"},
            1,
            "A Pedra do Trovao evolui o Eevee para Jolteon."
        },
        {
            "4. Qual o nome da regiao introduzida na Geracao 1 (Red/Blue/Yellow)?",
            {"1) Johto", "2) Hoenn", "3) Kanto", "4) Sinnoh"},
            3,
            "A primeira geracao de jogos se passa na regiao de Kanto."
        },
        {
            "5. Qual tipo de movimento e super efetivo contra Pokemon do tipo Psiquico?",
            {"1) Inseto", "2) Lutador", "3) Venenoso", "4) Fogo"},
            1,
            "Os tipos Inseto, Fantasma e Sombrio sao super efetivos contra Psiquico."
        },
        {
            "6. Quem e conhecido como o 'Deus Pokemon', responsavel por criar o universo?",
            {"1) Mewtwo", "2) Arceus", "3) Dialga", "4) Rayquaza"},
            2,
            "De acordo com a mitologia, Arceus criou todo o universo Pokemon."
        },
        {
            "7. Qual e a tipagem correta do Pokemon inicial Charizard?",
            {"1) Fogo / Dragao", "2) Fogo Puro", "3) Fogo / Voador", "4) Dragao / Voador"},
            3,
            "Apesar de parecer um dragao, Charizard e dos tipos Fogo e Voador."
        },
        {
            "8. Quantas evolucoes possiveis o Eevee possui atualmente?",
            {"1) 3", "2) 5", "3) 7", "4) 8"},
            4,
            "O Eevee possui 8 evolucoes diferentes atualmente."
        },
        {
            "9. Qual item e necessario para fazer o Pikachu evoluir para Raichu?",
            {"1) Pedra do Trovao", "2) Pedra Solar", "3) Subir de nivel", "4) Alta Amizade"},
            1,
            "O Pikachu precisa ser exposto a uma Pedra do Trovao para evoluir."
        },
        {
            "10. Qual e o Pokemon inicial do tipo Planta da regiao de Hoenn (Geracao 3)?",
            {"1) Bulbasaur", "2) Treecko", "3) Chikorita", "4) Turtwig"},
            2,
            "Treecko e o inicial de Planta da regiao de Hoenn."
        },
        
        // --- 5 PERGUNTAS DIFICEIS ---
        {
            "11. (DIFICIL) Qual item dobra o Ataque Especial exclusivo do Pikachu?",
            {"1) Lucky Egg", "2) Light Ball", "3) Everstone", "4) Quick Claw"},
            2,
            "A Light Ball (Bola de Luz) e um item especifico que dobra o Atk e Sp.Atk do Pikachu."
        },
        {
            "12. (DIFICIL) Qual destas frutas (Berries) cura o status de Paralisia?",
            {"1) Pecha Berry", "2) Aspear Berry", "3) Cheri Berry", "4) Chesto Berry"},
            3,
            "A Cheri Berry cura Paralisia. Pecha cura veneno, Aspear congelamento e Chesto sono."
        },
        {
            "13. (DIFICIL) Qual e a habilidade exclusiva do Pokemon Mimikyu?",
            {"1) Disguise", "2) Illusion", "3) Prankster", "4) Cursed Body"},
            1,
            "Disguise (Disfarce) permite que Mimikyu receba um ataque sem sofrer dano na primeira vez."
        },
        {
            "14. (DIFICIL) Qual e o unico Pokemon capaz de aprender o movimento Chatter (Tagarela)?",
            {"1) Pidgeot", "2) Chatot", "3) Jigglypuff", "4) Exploud"},
            2,
            "Chatot e o unico Pokemon que aprende Chatter, que antigamente permitia gravar audio no microfone do DS."
        },
        {
            "15. (DIFICIL) Qual Pokemon tem o maior atributo base de Velocidade (Base Speed) de todos?",
            {"1) Ninjask", "2) Deoxys (Speed Forme)", "3) Regieleki", "4) Electrode"},
            3,
            "Introduzido na geracao 8, Regieleki possui uma Base Speed absurda de 200, superando Deoxys."
        },

        // --- 5 PERGUNTAS IMPOSSIVEIS ---
        {
            "16. (IMPOSSIVEL) Qual foi o PRIMEIRO Pokemon a ser desenhado pelos criadores da Game Freak?",
            {"1) Bulbasaur", "2) Mew", "3) Pikachu", "4) Rhydon"},
            4,
            "Rhydon foi o primeiro Pokemon criado. Por isso, as estatuas nos ginasios originais tem o formato dele."
        },
        {
            "17. (IMPOSSIVEL) Quantas insignias Gary Oak conseguiu juntar na regiao de Kanto no anime original?",
            {"1) 8", "2) 10", "3) 12", "4) 15"},
            2,
            "Gary exibe orgulhosamente 10 insignias no anime, provando que existem mais de 8 ginasios em Kanto."
        },
        {
            "18. (IMPOSSIVEL) Qual e o valor exato da chance base original de encontrar um Pokemon Shiny na geracao 2?",
            {"1) 1 em 4096", "2) 1 em 8192", "3) 1 em 10000", "4) 1 em 2048"},
            2,
            "Nas geracoes mais antigas (2 a 5), a chance base era de exatamente 1 em 8192."
        },
        {
            "19. (IMPOSSIVEL) Qual e a soma exata dos Atributos Base (Base Stats) do lendario Arceus?",
            {"1) 600", "2) 680", "3) 700", "4) 720"},
            4,
            "Arceus tem 120 pontos em cada um dos seus 6 atributos, totalizando impressionantes 720 de Base Stat."
        },
        {
            "20. (IMPOSSIVEL) Quem foi o compositor original da famosa trilha sonora de Pokemon Red e Blue?",
            {"1) Koji Kondo", "2) Junichi Masuda", "3) Nobuo Uematsu", "4) Yoko Shimomura"},
            2,
            "Junichi Masuda foi o responsavel por compor as classicas musicas de Kanto usando os recursos limitados do Game Boy."
        }
    };

    // 'printf' imprime um texto na tela do usuario. O '\n' serve para pular uma linha.
    printf("======== RECRUTAMENTO DA LIGA POKEMON ======== \n");
    printf("Identifique-se, Treinador! Digite seu nome: ");      
    
    // 'scanf' le o que o usuario digita. O '%s' indica que estamos lendo uma string (texto) e salvamos em 'nomejogador'.
    scanf(" %s", nomejogador);                                 
    
    printf("============================================== \n\n\n"); 

    // O comando 'do' (faca) inicia um laco de repeticao. Tudo dentro dele sera executado pelo menos uma vez.
    // Este e o Game Loop principal (Loop do Jogo).
    do 
    {
        // Atribui o valor 0 a variavel resultado. Essencial para zerar os pontos se o jogador reiniciar a partida.
        resultado = 0; 
        
        // Imprime a mensagem de boas vindas. O '%s' e substituido pela variavel 'nomejogador'.
        printf("==================== Seja bem-vindo, Treinador %s! ==================== \n\n", nomejogador); 

        // Sequencia de 'printf' para exibir as regras do jogo.
        printf("=================== REGRAS DA SUA JORNADA DE CONHECIMENTO =================== \n");
        printf("1 - Sua Pokedex sera testada com 20 perguntas cruciais sobre o mundo Pokemon. \n");
        printf("2 - As perguntas vao do nivel basico ate o nivel IMPOSSIVEL. \n");
        printf("3 - Cada batalha possui 4 caminhos possiveis (alternativas de 1 a 4). \n");
        printf("4 - Apenas uma estrategia o levara a vitoria na rodada.\n");
        printf("5 - Acertar a resposta lhe garante 1 Ponto de Experiencia (XP).\n");
        printf("6 - Cuidado! Errar a resposta confunde sua equipe e voce PERDERA 1 ponto.\n");
        printf("7 - Se o oponente for forte demais, use a opcao (5) para Fugir/Pular a questao.\n");
        printf("8 - Ao fugir, seus pontos ficam intactos, mas voce perde a chance de pontuar.\n");
        printf("9 - Analise o campo de batalha com atencao antes de lancar sua Pokebola.\n\n");
        printf("Mostre que voce nao e apenas mais um no matinho e conquiste suas insignias! \n");
        printf("========================================================================== \n");
        
        // Outro laco 'do'. Este serve especificamente para prender o usuario no menu ate ele digitar uma opcao valida.
        do 
        {
            // Exibe as opcoes do menu.
            printf("Os seus Pokemon estao prontos! Vai encarar o desafio? \n");
            printf("Escolha seu comando: \n");
            printf("(1) Entrar na Arena e Comecar o Quiz! \n");
            printf("(2) Correr da batalha (Sair). \n");   

            // Le um numero inteiro digitado pelo usuario ('%d') e salva no endereco de memoria ('&') da variavel 'opcao'.
            scanf("%d", &opcao);

            // Estrutura condicional 'if' (se). Verifica se a opcao e DIFERENTE (!=) de 1 E (&&) DIFERENTE de 2.
            if(opcao != 1 && opcao != 2)
            {
                // Se a condicao for verdadeira (ele digitou 3, por exemplo), exibe mensagem de erro.
                printf("\nOpcao invalida! A Equipe Rocket sabotou o painel... Tente novamente!\n\n");
            }

        // 'while' (enquanto) testa a condicao do laco 'do' do menu. 
        // Ele continuara repetindo ENQUANTO a opcao for diferente de 1 e 2.
        } while (opcao != 1 && opcao != 2);

        // Verifica se a opcao escolhida no menu validado acima foi IGUAL (==) a 1.
        if(opcao == 1) 
        {
            // Imprime mensagem de inicio de jogo.
            printf("\n\n============= QUE SUA JORNADA COMECE!!!============= \n");
            
            // Laco 'for' (para). Cria uma variavel 'i' que comeca em 0; repete ENQUANTO 'i' for menor que 20; 
            // a cada repeticao, aumenta 'i' em 1 (i++). Serve para passar por todas as 20 questoes.
            for(int i = 0; i < 20; i++)
            {
                // Linha de separacao visual.
                printf("============================================================================= \n");
                
                // Imprime a string ('%s') que esta guardada dentro da 'pergunta' da questao atual ('quiz[i]').
                printf("%s \n", quiz[i].pergunta); 
                
                // Outro laco 'for' interno. Serve para passar pelas 4 alternativas da pergunta atual.
                for(int j = 0; j < 4; j++) {
                    // Imprime a opcao especifica. '[i]' indica qual a pergunta, '[j]' indica qual das 4 alternativas.
                    printf("%s \n", quiz[i].opcoes[j]); 
                }
                
                // Imprime a opcao fixa de pular, que nao esta no array.
                printf("5) Pular questao...\n\n"); 
                
                // Le o numero da alternativa que o jogador escolheu e salva na variavel 'alternativa'.
                scanf("%d", &alternativa); 

                // Verifica SE a alternativa escolhida e MAIOR OU IGUAL a 1 E MENOR OU IGUAL a 4.
                if(alternativa >= 1 && alternativa <= 4) 
                {
                    printf("\n---------------------------------------------------\n");
                    
                    // Mostra o texto da justificativa da questao atual armazenada na struct.
                    printf("DADOS DA POKEDEX: %s\n", quiz[i].justificativa); 
                    printf("---------------------------------------------------\n");

                    // Verifica SE a alternativa escolhida pelo jogador e exatamente igual a 'alternativaCorreta' cadastrada.
                    if(alternativa == quiz[i].alternativaCorreta) 
                    {
                        // Se acertou, mostra mensagem de sucesso.
                        printf("Efetivo! Alternativa correta! Voce ganhou 1 ponto! \n\n");
                        
                        // O comando '+=' adiciona 1 ao valor atual da variavel 'resultado' (soma 1 ponto).
                        resultado += 1; 
                    }
                    // 'else' (senao). Cai aqui se a condicao do 'if' acima for falsa (ou seja, ele errou).
                    else 
                    {
                        // Mostra mensagem de erro e qual era a alternativa certa (usando '%d' para imprimir o numero inteiro).
                        printf("O ataque falhou! Resposta incorreta! A certa era a alternativa %d. \n\n", quiz[i].alternativaCorreta);
                        
                        // Verifica se o resultado e maior que zero. Isso evita que o jogador fique com pontos negativos.
                        if(resultado > 0) 
                        {
                            // O comando '-=' subtrai 1 do valor atual da variavel 'resultado' (perde 1 ponto).
                            resultado -= 1; 
                        }
                    }
                }
                // 'else if' (senao se). Se a primeira condicao for falsa, testa esta. Verifica se digitou 5.
                else if(alternativa == 5) 
                {
                    // Mensagem informando que pulou a questao. Nenhum ponto e somado ou subtraido.
                    printf("Voce usou 'Fly'!... pulando questao em seguranca sem perder pontos! \n\n");
                }
                // Ultimo caso ('senao'). Se ele digitou qualquer numero que nao seja de 1 a 5.
                else 
                {
                    // Mensagem de erro de comando invalido.
                    printf("Comando invalido! Seus Pokemon ficaram confusos e passaram a vez...\n\n");
                }
            }

            // ====== TELA DE RESULTADOS ======
            // Ao sair do laco 'for' das 20 perguntas, o jogo acaba e exibimos o placar.
            printf("=================================== PLACAR DA LIGA POKEMON ====================================== \n");
            
            // Exibe o nome do jogador novamente para personalizar a tela final.
            printf("Avaliando o desempenho do Treinador %s... \n", nomejogador);
            
            // Imprime a pontuacao total armazenada na variavel 'resultado'.
            printf("Sua pontuacao final: %d Pontos de Experiencia (XP) de 20 possiveis! \n\n", resultado);
            
            // Sequencia de condicoes (if / else if) para definir qual mensagem final mostrar baseada na pontuacao.
            
            // Se o resultado for menor ou igual a 6.
            if(resultado <= 6) 
            {
                printf("[RANK: TREINADOR NOVATO]\n");
                printf("Parece que voce acabou de sair da Cidade de Pallet. Nao desanime, ate o Ash perdia no comeco!\n");
                printf("Compre mais pocoes, estude sua Pokedex e desafie a Liga novamente quando estiver pronto. \n\n");
            } 
            // Senao, se o resultado for maior ou igual a 7 E menor ou igual a 13.
            else if (resultado >= 7 && resultado <= 13) 
            {
                printf("[RANK: LIDER DE GINASIO]\n");
                printf("Muito bem! Voce ja tem o respeito de muitos treinadores e conquistou algumas insignias.\n");
                printf("Voce conhece bem o basico, mas para enfrentar as lendas, precisara treinar um pouco mais! \n\n");
            } 
            // Senao, se o resultado for maior ou igual a 14 E menor ou igual a 19.
            else if (resultado >= 14 && resultado <= 19) 
            {
                printf("[RANK: ELITE DOS QUATRO]\n");
                printf("Incrivel! Sua estrategia foi quase perfeita e voce raspou no topo do Hall da Fama!\n");
                printf("Voce passou pelas dificeis e se virou nas impossiveis. Faltou muito pouco para a perfeicao! \n\n");
            } 
            // Senao, se o resultado for exatamente igual a 20 (acertou tudo sem errar nenhuma).
            else if(resultado == 20)  
            {
                printf("[RANK: CAMPEAO DA LIGA / MESTRE POKEMON] \n");
                printf("INACREDITAVEL!!! Voce demonstrou um conhecimento supremo e capturou todos os pontos!\n");
                printf("O proprio Professor Carvalho esta impressionado. Seu nome foi gravado para sempre no Hall da Fama! \n\n");
            }
            // Linha visual para fechar o placar.
            printf("================================================================================================= \n\n");
            
            // ====== MENU DE JOGAR NOVAMENTE ======
            // Outro laco 'do' para garantir que o jogador responda corretamente se quer jogar de novo.
            do 
            {
                // Pergunta se o jogador quer jogar novamente, usando seu nome.
                printf("Deseja testar seus conhecimentos novamente, %s?\n", nomejogador);
                printf("(1) Sim, tentar novamente!\n");
                printf("(2) Nao, voltar para casa.\n");
                
                // Le a escolha e salva na variavel 'jogarNovamente'.
                scanf("%d", &jogarNovamente);
                
                // Se a opcao for invalida (nao for 1 nem 2).
                if(jogarNovamente != 1 && jogarNovamente != 2)
                {
                    // Exibe mensagem de erro. O laco vai repetir por causa do 'while' abaixo.
                    printf("\nComando invalido! O Centro Pokemon nao entendeu seu pedido.\n\n");
                }
            
            // 'while' deste menu secundario: repete se a entrada nao for nem 1 nem 2.
            } while (jogarNovamente != 1 && jogarNovamente != 2);
            
            // Se ele escolheu 2 (Nao quer jogar mais).
            if(jogarNovamente == 2)
            {
                // Imprime mensagem de despedida final.
                printf("\nVoce decidiu descansar. Ate a proxima batalha, Treinador!\n");
            }
        }
        // Este 'else if' pertence ao primeiro 'if' la de cima (o menu inicial onde ele escolhe entrar ou fugir).
        // Se a opcao la do começo foi 2 (Sair).
        else if(opcao == 2) 
        {
            // Mensagem dizendo que fugiu.
            printf("Voce fugiu da batalha com seguranca e voltou para o Centro Pokemon... \n\n");
            
            // Forca a variavel 'jogarNovamente' a valer 2 para que o Game Loop principal termine e o jogo feche.
            jogarNovamente = 2; 
        }

    // Este 'while' fecha o Game Loop principal gigante. 
    // Ele verifica se 'jogarNovamente' e exatamente igual a 1. Se for, o codigo volta la pro topo do primeiro 'do'.
    } while (jogarNovamente == 1); 

    // O comando 'return 0' informa ao sistema operacional que o programa rodou perfeitamente e finalizou com sucesso.
    return 0; 
}