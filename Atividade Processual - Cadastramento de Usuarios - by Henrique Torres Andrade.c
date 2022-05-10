#include <stdio.h>
#include <stdlib.h>


int main() {
	
    int c, teste, teste1=0, qt_usuarios=0, codigo[10], sexon[10], idade[10], flag=0, numero_usuarios=1, flag1=0, flag2=0, flag3=0, contS=0;
	int FLAGZAO = 0, resposta, resposta1, alterar, flag4=0, flag5=0, flag6=0, informacoes;
    char sexo, cpf[10][11], CPF[11];
    float salario[10];
    
    for (int i = 0; i < 10; i++){
    	sexon[i] = 0;
	}
    
    printf(" ================= BANCO DE USARIOS =================\n");
    while (FLAGZAO == 0) {
        printf(" |	         ________MENU:________               |\n");
        printf(" |                                                   |\n");
        printf(" |   	 1. Cadastrar Usuario;                       |\n");
		printf(" |   	 2. Editar Usuario;                          |\n");
		printf(" |   	 3. Deletar Usuario;                         |\n");
		printf(" |   	 4. Exibir Usuario Pelo Seu Codigo;          |\n");
		printf(" |     	 5. Encerrar o Sistema.                      |\n");
		printf("Resposta: ");
		scanf("\n%d", &resposta);
        
        while (flag == 0) {
        	//MENU ---CADASTRAR USUARIO---
            if (resposta == 1) {
                system("cls");
                if (numero_usuarios > 10) {printf("---------------------------------------\n"); printf("LIMITE ATINGIDO\n"); break;}
                printf("---------------------------------------\n");
                
                //---ENTRADA DE DADOS---
                while (flag2 == 0) {
                    if (numero_usuarios <= 10) {
                        c = numero_usuarios - 1;
                        printf("---------------------------------------\n");
                        printf("::::USUARIO %d::::\n", numero_usuarios);
                        printf("Codigo de usuario: ");
                        scanf("\n%d", &codigo[c]);
                        printf("CPF: ");
                        scanf("\n%s", CPF);
						for (int i = 0; i < 10; i++) {
							for (int j = 0; j < 11; j++) {
								if (i == c) {
									cpf[i][j] = CPF[j];
								}
							}
						}
                        flag = 0;
                        while (flag == 0) {
                            printf("Sexo[m/f]: ");
                            scanf("\n%c", &sexo);
                            if (sexo == 'M' || sexo == 'm') {
                                sexon[c] = 2;
                                flag = 1;
                            } else {
                                if (sexo == 'f' || sexo == 'F') {
                                    sexon[c] = 1;
                                    flag = 1;
                                }
                                else {
                                    printf("INFORME APENAS f OU m.\n");
                                }
                            }
                            sexo = ' ';
                        }
                        printf("Idade: ");
                        scanf("\n%d", &idade[c]);
                        printf("Salario: ");
                        scanf("\n%f", &salario[c]);
                        printf("CADASTRADO COM SUCESSO\n");
                        qt_usuarios += 1;
                        printf("---------------------------------------\n");
                        int resposta = 0;
                        flag3 = 0;
                        while (flag3==0) {
                            printf("1. Cadastrar novo usuario;\n2. Parar de cadastrar.\nResposta: ");
                            scanf("\n%d", &resposta1);
                            if (resposta1 == 1) {
                                c += 1;
                                numero_usuarios += 1;
                                system("cls");
                                flag3 = 1;
                            } else {
								if (resposta1 == 2) {
									c += 1;
									numero_usuarios += 1;
									system("cls");
									flag2 = 1;
									flag3 = 1;
								} else {
									//---PREVENCAO DE ERROS---
									printf("OPCOES APENAS 1 OU 2\n");
								}
							}
						}
					} else {
                        printf("---------------------------------------\n");
						printf("LIMITE DE USUARIOS ATINGIDO\n");
						flag2 = 1;
					}
				}
				printf("---------------------------------------\n");
				flag2=0;
            }
            if (resposta == 2) {
            	//MENU ---EDITAR USUARIO---
                system("cls");
                printf("---------------------------------------\n");
                if (qt_usuarios == 0) {
                	printf("Usuarios cadastrados: %d\n", qt_usuarios);
	        		printf("Nao ha usuarios para editar!!!\n");
                	printf("---------------------------------------\n");
				} else {
	                while (flag5 == 0) {
	                    printf("Qual usuario deseja alterar? ");
	                    scanf("\n%d", &alterar);
	                    if (sexon[alterar-1] == 0) {printf("USUARIO %d AINDA NAO FOI CADASTRADO!!!\n", alterar); printf("---------------------------------------\n\n"); continue;}
	                    while (flag4 == 0) {
	                    	//MENU ---SAIDA DE DADOS---
	                        if (alterar >= 1 && alterar <= 10) {
	                            printf("DADOS DO USUARIO: \n Codigo: %d\n", codigo[alterar-1]);
	                            printf(" CPF: ");
								for (int i = 0; i < 10; i++) {
									for (int j = 0; j < 11; j++) {
										if (i == alterar-1) {
											printf("%c", cpf[i][j]);
										}
									}
								}
	                            printf("\n Sexo: ");
	                            if (sexon[alterar-1] == 2 ) {printf("Masculino\n");}
	                            if (sexon[alterar-1] == 1 ) {printf("Feminino\n");}
	                            if (sexon[alterar-1] == 0 ) {printf("Nao cadastrado\n");}
	                            printf(" Idade: %d\n Salario: R$%.2f\n", idade[alterar-1], salario[alterar-1]);
	                            printf("---------------------------------------\n");
	                            printf("Qual destas informacoes deseja alterar? \n");
	                            printf(" |  1. Codigo;   |\n |  2. CPF;      |\n |  3. Sexo;     |\n |  4. Idade;    |\n |  5. Salario.  |\nResposta: ");
	                            scanf("\n%d", &informacoes);
	                            //---ALTERACAO E MANIPULACAO DE DADOS---
	                            while (flag6 == 0) {
	                            	if (informacoes == 1) {
	                            		printf("Digite o novo codigo: ");
	                            		scanf("\n%d", &codigo[alterar-1]);
									} else {
		                            	if (informacoes == 2) {
		                            		printf("Digite o novo cpf: ");
		                            		scanf("\n%s", CPF);
											for (int i = 0; i < 10; i++) {
												for (int j = 0; j < 11; j++) {
													if (i == alterar-1) {
														cpf[i][j] = CPF[j];
													}
												}
											}
										} else {
			                            	if (informacoes == 3) {	
			                            		while (flag==0) {
			                            			printf("Digite o novo sexo[m/f]: ");
			                            			scanf("\n%c", &sexo);
			                            			if (sexo == 'M' || sexo == 'm') {
			                                			sexon[alterar-1] = 2;
			                                			flag = 1;
			                            			} else {
			                                			if (sexo == 'f' || sexo == 'F') {
			                                    			sexon[alterar-1] = 1;
			                                    			flag = 1;
			                                			}
			                                			else {
			                                				//---PREVENCAO DE ERROS---
			                                    			printf("INFORME APENAS f OU m.\n");
			                                			}
			                            			}
			                            			contS += 1;
												}flag2=0;		
											} else {
				                            	if (informacoes == 4) {
				                            		printf("Digite a nova idade: ");
				                            		scanf("\n%d", &idade[alterar-1]);
												} else {
					                            	if (informacoes == 5) {
					                            		printf("Digite o novo salario: ");
					                            		scanf("\n%f", &salario[alterar-1]);
													}
												}
											}
										}
									}
									printf("---------------------------------------\n");
									printf("ALTERADO COM SUCESSO!\n");
									flag6=1;
								} flag6 = 0;
	                            flag5=1;
	                        } else {
	                            printf("---------------------------------------\n");
	                            printf("USUARIO INEXISTENTE\n");
	                            printf("---------------------------------------\n");
	                        } 
							flag4=1;
	                    }
	                    flag4=0;
	                    flag5=1;
	                }
	            }
                flag5=0;
                flag=1;
            }
        	if (resposta == 3) {
        		while (flag2 == 0) {
        			//MENU ---DELETAR USUARIO---
        			system("cls");
	        		printf("---------------------------------------\n");
	        		if (qt_usuarios == 0) {
	        			printf("Usuarios cadastrados: %d\n", qt_usuarios);
	        			printf("Nao ha usuarios para deletar!\n");
	        			printf("---------------------------------------\n");
						flag=1;
						flag2=1;
					} else {
						while (flag4 == 0) {
							printf("Usuarios cadastrados: %d\n", qt_usuarios);
							printf("Informe qual usuario deseja detetar: ");
							scanf("\n%d", &resposta);
							//---PREVENCAO DE ERROS---
							if (resposta < 1 || resposta > 10) {printf("CAPACIDADE DE 10 USUARIOS!!!\n"); printf("---------------------------------------\n\n"); continue;} 
							else {
								if (sexon[resposta-1] == 0) {printf("USUARIO AINDA NAO FOI CADASTRADO!!!\n"); printf("---------------------------------------\n\n"); continue;}
							}
							if (resposta-1 < 9) {
								printf("\nATENCAO: Ao deletar o usuario %d, o \nusuario %d passara a ser o usuario %d,\ne assim sucessivamente!\n", resposta, resposta+1, resposta);
							}
							printf("---------------------------------------\n");
							//---SAIDA DE DADOS---
							printf("DADOS DO USUARIO: \n Codigo: %d\n", codigo[resposta-1]);
                            printf(" CPF: ");
                            for (int i = 0; i < 10; i++) {
								for (int j = 0; j < 11; j++) {
									if (i == resposta-1) {
										printf("%c", cpf[i][j]);
									}
								}
							}
                            printf("\n Sexo: ");
                            if (sexon[resposta-1] == 2 ) {printf("Masculino\n");}
                            if (sexon[resposta-1] == 1 ) {printf("Feminino\n");}
                            if (sexon[resposta-1] == 0 ) {printf("Nao cadastrado\n");}
                            printf(" Idade: %d\n Salario: R$%.2f\n", idade[resposta-1], salario[resposta-1]);
                            printf("---------------------------------------\n");
                            while (flag5 == 0) {
                            	printf("	1. Deletar usuario %d;\n	2. Voltar ao menu;\n	Resposta: ", resposta);
                        		scanf("\n%d", &resposta1);
                        		if (resposta1 != 1 && resposta1 != 2) {
                        			//---PREVENCAO DE ERROS---
									printf("Resposta invalida!!\n");
									continue;
								} else {
									if (resposta1 == 2) {
										system("cls");
										printf("---------------------------------------\n");
										flag5 = 1;
									} else {
										//---EXCLUSAO E MANIPULACAO DE DADOS---
										if (resposta1 == 1) {
											codigo[resposta-1] = 0;
											for (int i = 0; i < 10; i++) {
												for (int j = 0; j < 11; j++) {
													if (i == resposta-1) {
														cpf[i][j] = '0';
													}
												}
											}
											sexon[resposta-1] = 0;
											idade[resposta-1] = 0;
											salario[resposta-1] = 0;
											qt_usuarios -= 1;
											numero_usuarios -= 1;
											teste = resposta - 1;
											while (flag6 == 0) {
												if (teste < 9) {
													codigo[teste] = codigo[teste+1];
													codigo[teste+1] = 0;
													for (int i = 0; i < 10; i++) {
														for (int j = 0; j < 11; j++) {
															if (i == teste) {
																cpf[i][j] = cpf[i+1][j];
																cpf[i+1][j] = '0';
															}
														}
													}
													sexon[teste] = sexon[teste+1];
													sexon[teste+1] = 0;
													idade[teste] = idade[teste+1];
													idade[teste+1] = 0;
													salario[teste] = salario[teste+1];
													salario[teste+1] = 0;
													teste+=1;
												} else {
													flag6=1;
												}
											} flag6=0;
											system("cls");
											printf("---------------------------------------\n");
											printf("    USUARIO %d DELETADO COM SUCESSO!\n", resposta);
											printf("---------------------------------------\n\n");
											flag5=1;
										}
									}
								}
							} flag5=0;
                            flag4=1;
                            flag2=1;
                            flag=1;
						} flag4=0;
					}
				} flag2=0;
			}
			if (resposta == 4) {
				//MENU ---CONSULTAR USUARIO---
				system("cls");
            	printf("---------------------------------------\n         CONSULTA DE USUARIO\n---------------------------------------\n\n");
            	while (flag4 == 0) {
        			printf("Consulte um usuario pelo seu codigo: ");
        			scanf("\n%d", &resposta);
        			teste1=0;
        			//---SAIDA DE DADOS---
        			for (int i = 0; i < 10; i++) {
        				if (resposta == codigo[i]) {
        					printf("DADOS DO USUARIO:\n Codigo: %d\n", codigo[i]);
							printf(" CPF: ");
							for (int li = 0; li < 10; li++) {
								for (int j = 0; j < 11; j++) {
									if (li == i) {
										printf("%c", cpf[li][j]);
									}
								}
							}	
							printf("\n Sexo: ");
                            if (sexon[i] == 2 ) {printf("Masculino\n");}
                            if (sexon[i] == 1 ) {printf("Feminino\n");}
                            if (sexon[i] == 0 ) {printf("Nao cadastrado\n");}
                            printf(" Idade: %d\n Salario: R$%.2f\n", idade[i], salario[i]);
                            printf("---------------------------------------\n");
                            teste1=1;
						}
					}
					if (teste1 == 0) {
						printf("USUARIO NAO ENCONTRADO\n---------------------------------------\n");
					}
					while (flag5 == 0) {
						printf("1. Pesquisar novo usuario\n2. Voltar ao menu.\n Resposta: ");
						scanf("\n%d", &resposta);
						if (resposta == 1) {
							flag5=1;
							system("cls");
							printf("---------------------------------------\n         CONSULTA DE USUARIO\n---------------------------------------\n\n");
						} else {
							if (resposta == 2) {
								flag5=1;
								flag4=1;
								system("cls");
								printf("---------------------------------------\n");
							} else {
								//---PREVENCAO DE ERROS---
								printf("RESPOSTA INVALIDA\n");
							}
						}
					} flag5 = 0;
				} flag4 = 0;
            	flag=1;
			}
			if (resposta == 5) {
				//MENU ---ENCERRAR PROGRAMA---
				flag = 1;
				printf("Tem certeza que deseja sair? \n");
			}
			if (resposta != 1 && resposta != 2 && resposta != 3 && resposta != 4 && resposta != 5) {
				//---PREVENCAO DE ERROS---
				printf("RESPOSTA INVALIDA\n");
				break;
			}
		}
		flag = 0;
		while (flag4 == 0) {
	        printf("|	1. Encerrar o sistema;\n|	2. Voltar ao menu.\n");
	        printf("|	Resposta: ");
	        scanf("\n%d", &resposta);
	        if (resposta == 1) {system("cls"); printf("\nMuito obrigado, ate logo!\n"); FLAGZAO = 1; flag4 = 1; system("pause");} 
	        if (resposta == 2) {FLAGZAO = 0; flag4 = 1; system("cls");}
	        //---PREVENCAO DE ERROS---
	        if (resposta != 1 && resposta != 2) {printf("RESPOSTA INVALIDA!\n");}
	    } flag4 = 0;
	}
}
