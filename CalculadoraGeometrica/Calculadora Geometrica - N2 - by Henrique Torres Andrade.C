#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//========================================================FUNCOES DE FIGURAS 2D========================================================
float QuadradoRetanguloAreaParalelogramo(float x, float y) {
    float area = x * y;
    return area;
}
float CircunferenciaArea(float raio) {
    float area = 3.14159265 * pow(raio, 2);
    return area;
}
float CircunferenciaComprimento(float raio) {
    float comprimento = 2 * 3.14159265 * raio;
    return comprimento;
}
float TrianguloArea1(float a, float b, float c) {
    float p = (a + b + c)/2, area;
    area = sqrt(p * (p - a) * (p - b) * (p - c));
    return area;
}
float TrianguloELosangoArea(float x, float y) {
    float area = (x * y) / 2;
    return area;
}

//========================================================FUNCOES DE FIGURAS 3D========================================================
float EsferaArea(float raio) {
    float area = 4 * 3.14159265 * pow(raio, 2);
    return area;
}
float EsferaVolume(float raio) {
    float volume = (4 * 3.14159265 * pow(raio, 3)) / 3;
    return volume;
}
float CilindroArea(float x, float y) {
    float area, ab = 3.14159265 * pow(x, 2), al = 2 * 3.14159265 * x * y ;
    area = al + (2 * ab);
    return area;
}
float CilindroVolume(float x, float y) {
    float ab = 3.14159265 * pow(x, 2), area;
    area = ab * y;
}
float PiramideArea(float ArestaBase, float Altura) {
    float AlturaLateral = sqrt(pow(Altura, 2) + pow((ArestaBase / 2), 2)), AreaLateral = TrianguloELosangoArea(ArestaBase, AlturaLateral);
    float Area = (AreaLateral * 4) + QuadradoRetanguloAreaParalelogramo(ArestaBase, ArestaBase);
    return Area;
}
float PiramideVolume(float ArestaBase, float Altura) {
    float AreaBase = QuadradoRetanguloAreaParalelogramo(ArestaBase, ArestaBase), Volume;
    Volume = (AreaBase * Altura) / 3;
    return Volume;
}
float ConeArea(float Raio, float Altura) {
    float Geratriz = sqrt(pow(Altura, 2) + pow(Raio, 2));
    float Area = CircunferenciaArea(Raio) + (3.14159265 * Raio * Geratriz);
    return Area;
}
float ConeVolume(float Raio, float Altura) {
    float AreaBase = CircunferenciaArea(Raio), Volume = (AreaBase * Altura) / 3;
    return Volume;
}
float CuboOuParalelepipedoArea(float l1, float l2, float l3) {
    float area = (2 * l1 * l2) + (2 * l2 * l3) + (2 * l1 * l3);
    return area;
}
float CuboOuParalelepipedoVolume(float l1, float l2, float l3) {
    float volume = l1 * l2 * l3;
    return volume;
}

//========================================================FUNCOES DE CARACTERES========================================================
//A funcao LimpaTela() serve para limpar a tela do terminal de execucao do programa
char LimpaTela(void) {
    system("cls");
    printf(" ==============================================\n");
    printf("      CALCULADORA DE FIGURAS GEOMETRICAS\n ==============================================\n");
}
//A funcao Linha() serve para escrever uma linha horizontal no Terminal de execucao do programa
char Linha(void) {
    printf(" ---------------------\n");
    return 0;
}
//A funcao Bloco1() serve como uma pausa no programa
char Bloco1() {
    float flag3 = 0;
    int resposta1;
    while (flag3 == 0) { 
        printf("     1. Voltar\n Resposta: "); 
        scanf("\n%d", &resposta1);
        if (resposta1 == 1) {flag3 = 1;} 
    } flag3 = 0;
    return 0;
}

//========================================================FUNCAO PRINCIPAL========================================================
int main(void) {
    int resposta, resposta1, flag1=0, flag2=0, flag3=0, teste=0;
    float b, h, r, l1, l2, l3;

    LimpaTela();
    //--------------------------------------------------------MENU PRINCIPAL--------------------------------------------------------
    while (flag1 == 0) {
        printf("  MENU: \n");
        Linha();
        printf(" |    1. Figuras 2D\n |    2. Figuras 3D\n |    3. Sair\n");
        Linha();
        printf(" Resposta: ");
        scanf("\n%d", &resposta);
        if (resposta == 1) {
            while (flag2 == 0) {
                LimpaTela();
                //--------------------------------------------------------MENU DE FIGURAS 2D--------------------------------------------------------
                printf("  FIGURAS 2D:\n");
                Linha();
                printf(" |    1. Quadrado/Retangulo\n |    2. Circunferencia\n |    3. Triangulo");
                printf("\n |    4. Losango\n |    5. Paralelogramo\n |    6. Voltar\n Resposta: ");
                scanf("\n%d", &resposta1);
                if (resposta1 == 1) {
                    LimpaTela();
                    //--------------------------RETANGULO--------------------------
                    printf(" RETANGULO\n"); 
                    Linha();
                    printf(" Base: "); scanf("\n%f", &b);
                    printf(" Altura: "); scanf("\n%f", &h);
                    Linha(); printf(" AREA = %.2f\n", QuadradoRetanguloAreaParalelogramo(b, h)); Linha();
                    Bloco1();
                } else {
                    if (resposta1 == 2) {
                    	//--------------------------CIRCUNFERENCIA--------------------------
                        LimpaTela(); printf(" CICRUNFERENCIA\n"); Linha();
                        printf(" Raio: "); scanf("\n%f", &r);
                        Linha(); printf(" AREA = %.2f\n Comprimento = %.2f\n", CircunferenciaArea(r), CircunferenciaComprimento(r)); Linha();
                        Bloco1();
                    } else {
                        if (resposta1 == 3) {
                            while (flag3 == 0) {
                            	//--------------------------TRIANGULO--------------------------
                                LimpaTela(); printf(" TRIANGULO\n"); Linha();
                                printf(" Possui o valor de todos os lados do triangulo? \n  1. Sim\n  2. Nao\n Resposta: ");
                                scanf("\n%d", &resposta1);
                                if (resposta1 == 1) {
                                    Linha(); printf("  FORMULA DE HERON\n"); Linha();
                                    printf(" Lado 1: "); scanf("\n%f", &l1);
                                    printf(" Lado 2: "); scanf("\n%f", &l2);
                                    printf(" Lado 3: "); scanf("\n%f", &l3);
                                    Linha(); printf(" AREA = %.2f\n", TrianguloArea1(l1, l2, l3)); Linha();
                                    flag3 = 1;
                                }
                                if (resposta1 == 2) {
                                    Linha(); 
                                    printf(" Base: "); scanf("\n%f", &b);
                                    printf(" Altura: "); scanf("\n%f", &h);
                                    Linha(); printf(" AREA = %.2f\n", TrianguloELosangoArea(b, h)); Linha();
                                    flag3 = 1;
                                }
                                if (resposta1 != 1 && resposta1 != 2) {
                                    continue;
                                }
                            } flag3 = 0;
                            Bloco1();
                        } else {
                            if (resposta1 == 4) {
                            	//--------------------------LOSANGO--------------------------
                                LimpaTela(); printf(" LOSANGO\n"); Linha();
                                printf(" Diagonal Maior: "); scanf("\n%f", &b);
                                printf(" Diagonal Menor: "); scanf("\n%f", &h);
                                Linha(); printf(" AREA = %.2f\n", TrianguloELosangoArea(b, h)); Linha();
                                Bloco1();
                            } else {
                                if (resposta1 == 5) {
                                	//--------------------------PARALELOGRAMO--------------------------
                                    LimpaTela(); printf(" PARALELOGRAMO\n"); Linha();
                                    printf(" Base: "); scanf("\n%f", &b);
                                    printf(" Altura: "); scanf("\n%f", &h);
                                    Linha(); printf(" AREA = %.2f\n", QuadradoRetanguloAreaParalelogramo(b, h)); Linha();
                                    Bloco1();
                                } else {
                                    if (resposta1 == 6) {
                                        flag2 = 1;
                                        LimpaTela();
                                    }
                                }
                            }
                        }
                    }
                }
            } flag2 = 0;
        } else {
            if (resposta == 2) {
                while (flag2 == 0) {
                    LimpaTela();
                    //--------------------------------------------------------MEU DE FIGURAS 3D--------------------------------------------------------
                    printf("  FIGURAS 3D: \n"); Linha(); printf(" |    1. Esfera\n |    2. Cilindro\n |    3. Piramide");
                    printf("\n |    4. Cone\n |    5. Cubo/Paralelepipedo\n |    6. Voltar\n Resposta: ");
                    scanf("\n%d", &resposta1);
                    if (resposta1 == 1) {
                        LimpaTela();
                        //--------------------------ESFERA--------------------------
                        printf(" ESFERA\n"); Linha(); 
                        printf(" Raio: "); scanf("\n%f", &r);
                        Linha(); printf(" Area = %.2f\n Volume = %.2f\n", EsferaArea(r), EsferaVolume(r)); Linha();
                        Bloco1();
                    }
                    if (resposta1 == 2) {
                        LimpaTela();
                        //--------------------------CILINDRO--------------------------
                        printf(" CILINDRO\n"); Linha();
                        printf(" Raio: "); scanf("\n%f", &r);
                        printf(" Altura: "); scanf("\n%f", &h);
                        Linha(); printf(" Area = %.2f\n Volume = %.2f\n", CilindroArea(r, h), CilindroVolume(r, h)); Linha();
                        Bloco1();
                    }
                    if (resposta1 == 3) {
                        LimpaTela();
                        //--------------------------PIRAMIDE--------------------------
                        printf(" PIRAMIDE\n"); Linha();
                        printf(" Aresta da base: "); scanf("\n%f", &b);
                        printf(" Altura: "); scanf("\n%f", &h);
                        Linha(); printf(" Area = %.2f\n Volume = %.2f\n", PiramideArea(b, h), PiramideVolume(b, h)); Linha();
                        Bloco1();
                    }
                    if (resposta1 == 4) {
                        LimpaTela();
                        //--------------------------CONE--------------------------
                        printf(" CONE\n"); Linha();
                        printf(" Raio da base: "); scanf("\n%f", &r);
                        printf(" Altura: "); scanf("\n%f", &h);
                        Linha(); printf(" Area = %.2f\n Volume = %.2f\n", ConeArea(r, h), ConeVolume(r, h)); Linha();
                        Bloco1();
                    }
                    if (resposta1 == 5) {
                        LimpaTela();
                        //--------------------------PARALELEPIPEDO--------------------------
                        printf(" PARALELEPIPEDO\n"); Linha();
                        printf(" Aresta 1: "); scanf("\n%f", &l1);
                        printf(" Aresta 2: "); scanf("\n%f", &l2);
                        printf(" Aresta 3: "); scanf("\n%f", &l3);
                        Linha(); printf(" Area = %.2f\n Volume = %.2f\n", CuboOuParalelepipedoArea(l1, l2, l3), CuboOuParalelepipedoVolume(l1, l2, l3)); Linha();
                        Bloco1();
                    }
                    if (resposta1 == 6) {
                        flag2 = 1;
                        LimpaTela();
                    }
                } flag2 = 0;
            } else {
                if (resposta == 3) {
                    flag1 = 1;
                } else {
                    LimpaTela();
                }
            }
        }
    } flag1 = 0;
}
