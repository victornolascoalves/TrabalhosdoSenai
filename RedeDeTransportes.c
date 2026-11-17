#include <stdio.h>

int main()
{

        //Declaração de variáveis
    float Distancia, Peso, Frete, CustoKm, TaxaFrete, FretePeso, FreteBruto, CupomDes, FreteDistanciaTotal, FretePesoTotal, FreteDescontoDistancia;
    int entrega, Cupom, opcao, quantidadeEncomendas, Continuar, QuantidadePadrao, QuantidadeExpressa, QuantidadePrioritaria;
    float Meta;
    float totalDistancia = 0;
    float totalPeso = 0;
    float totalReceita = 0;
    int fretesGratuitos = 0;
    float maiorFrete;
    float menorFrete;
    quantidadeEncomendas = 0;
    opcao = 0;

    QuantidadePadrao = 0;
    QuantidadeExpressa = 0;
    QuantidadePrioritaria = 0;
    maiorFrete = 0;
    menorFrete = 0;

  while(opcao !=4)
    {


    //Exibição do menu de opções
    printf("=================================================================\n");
    printf("\t\tEscolha a opcao desejada;\n");
    printf("\t1 - Cadastrar e processar encomenada;\n");
    printf("\t2 - Exibir resumo Estatistico do dia;\n");
    printf("\t3 - Exibir indicadores;\n");
    printf("\t4 - Sair;\n");
    printf("=================================================================\n");
    if (scanf("%d", &opcao) != 1)
{
    printf("Entrada invalida! Digite uma opcao de 1 a 4.\n");

    while (getchar() != '\n');

    opcao = 0;
}


    //Processamento das opções
    
    
           switch (opcao)
        {
        
      case 1:
      
              Continuar = 1;

              do{
            
            //Entrada de dados
            do
            {
                 printf("Digite a distancia em quilometros:\n");

                 if (scanf("%f", &Distancia) != 1)
             {
                   printf("Entrada invalida! Digite um numero.\n");

                 while (getchar() != '\n');

                 Distancia = -1;
                  }
                  else if (Distancia <= 0)
         {
                 printf("Distancia invalida! Digite um valor maior que zero.\n");
                  }

                 } while (Distancia <= 0);
                totalDistancia += Distancia;
            do  
            {
                printf("Digite o peso em kg:\n");

                  if (scanf("%f", &Peso) != 1)
             {
                  printf("Entrada invalida! Digite um numero.\n");

                   while (getchar() != '\n');

                 Peso = -1;
              }
                 else if (Peso <= 0)
                {
                    printf("Peso invalido! Digite um valor maior que zero.\n");
                 }

                } while (Peso <= 0);

                totalPeso += Peso;
            do
            {
                 printf("Digite o tipo de entrega (1 - Padrao, 2 - Expressa, 3 - Prioritaria):\n");

                if (scanf("%d", &entrega) != 1)
                {
                printf("Entrada invalida! Digite 1, 2 ou 3.\n");

                 while (getchar() != '\n');

                 entrega = 0;
                }
                else if (entrega < 1 || entrega > 3)
                {
                printf("Tipo de entrega invalido! Digite um valor entre 1 e 3.\n");
                }

                } while (entrega < 1 || entrega > 3);

            do
            {
                printf("Digite o codigo do cupom (0 - nenhum, 1020 - LOG10, 2030 - DESCONTO15):\n");

                if (scanf("%d", &Cupom) != 1)
                {
                printf("Entrada invalida! Digite 0, 1020 ou 2030.\n");

                while (getchar() != '\n');

                Cupom = -1;
                }
                else if (Cupom != 0 && Cupom != 1020 && Cupom != 2030)
                {
                printf("ERRO: Codigo de cupom invalido.\n");
                printf("Digite 0, 1020 ou 2030.\n");
                }

                }
                 while (Cupom != 0 && Cupom != 1020 && Cupom != 2030);
                     //Cálculo do custo por quilometro


            if (entrega == 1)
            {
                CustoKm= 1.20;
                QuantidadePadrao++;
            }
            else if (entrega == 2)
            {
                CustoKm = 1.80;
                QuantidadeExpressa++;
            }

            else if (entrega == 3)
            {
                CustoKm = 2.50;
                QuantidadePrioritaria++; 
            }        
                     //Cálculo da taxa de frete

            if (entrega == 1)
                TaxaFrete = 0.00;
            else if (entrega == 2)
                TaxaFrete = 15.00;
            else if (entrega == 3)
                TaxaFrete = 30.00;

            //Cálculo do valor do peso do frete

            if (Peso <= 5.00)
                FretePeso = 2.00;
            else if (Peso > 5.00)
                FretePeso = 3.50;

                //Cálculo do frete total
                 FreteDistanciaTotal= Distancia * CustoKm;
                 FretePesoTotal = FretePeso * Peso;

                 FreteBruto = FreteDistanciaTotal + TaxaFrete + FretePesoTotal;

            //Cupom de desconto

                if (Cupom == 1020)
                 CupomDes = FreteBruto * 0.10;
                   else if (Cupom == 2030)
                   CupomDes = 15;
                else
                   CupomDes = 0;

                if (entrega == 1 && Peso <= 2.00 && Distancia <= 10.00)
                {
                Frete = 0;
                fretesGratuitos++;
                }
                 else if (Distancia > 100.00)
                {
                     FreteDescontoDistancia = FreteBruto * 0.10;
                    Frete = FreteBruto - FreteDescontoDistancia - CupomDes;
                }
                    else
                     Frete = FreteBruto - CupomDes;

                if (Frete < 0)
                    Frete = 0; 

                totalReceita += Frete;
            //Exibição do resultado
        


                 printf("==================================================================\n");
                 printf("LOGTECH - COMPROVANTE DE FRETE\n");
                 printf("===================================================================\n");
                 quantidadeEncomendas++;
                    if (quantidadeEncomendas == 1)
                        {
                         maiorFrete = Frete;
                    menorFrete = Frete;
                    }
                    else
                    {
                    if (Frete > maiorFrete)
                     maiorFrete = Frete;

                    if (Frete < menorFrete)
                    menorFrete = Frete;
                    }


                 printf("Encomenda nº: \t%d\n", quantidadeEncomendas);
                 printf("Categoria Selecionada: \t%d\n", entrega);
                 printf("Peso Registrado: \t%.2f kg\n", Peso);
                 printf("Distancia Percorrida:  \t%.2f km\n", Distancia);
                 printf("Cupom Aplicado: \t%d\n", Cupom);
                 printf("-------------------------------------------------------------------\n");
                 printf("Valor Bruto do Frete: R$ %.2f\n", FreteBruto);
                 printf("Valor Final Calculado: R$ %.2f\n", Frete);
                 printf("Status: \t\t\t Processado com Sucesso\n");
                 printf("===================================================================\n");


                do
                { 

                printf("Deseja cadastrar outra encomenda? (1 - Sim, 2 - Nao):\n");

                  if (scanf("%d", &Continuar) != 1)
                {
                   printf("Entrada invalida! Digite 1 para Sim ou 2 para Nao.\n");

                    while (getchar() != '\n');

                 Continuar = 0;
                    }
                    else if (Continuar != 1 && Continuar != 2)
                    {
                printf("Opcao invalida! Digite 1 para Sim ou 2 para Nao.\n");
                }

            } while (Continuar != 1 && Continuar != 2);

            } while (Continuar == 1 && quantidadeEncomendas < 100);

            break;
    

     case 2:
                        if (quantidadeEncomendas == 0)
                        {
                        printf("Nenhuma encomenda cadastrada. Utilize a opcao 1 primeiro.\n");
                        }

                        else
                        {

                  //Exibir resumo estatístico do dia

                   printf("==================================================================\n");
                   printf("\t\tResumo Financeiro e Operacional\n");
                   printf("==================================================================\n");
                   printf("Faturamento total em fretes     : R$ %.2f\n", totalReceita);
                   printf("Média de peso das encomendas    : %.2f kg\n", totalPeso / quantidadeEncomendas);
                   printf("Média de distância percorrida   : %.2f km\n", totalDistancia / quantidadeEncomendas);
                   printf("------------------------------------------------------------------\n");
                   printf("Maior frete individual cobrado  : R$ %.2f\n", maiorFrete);
                   printf("Menor frete individual cobrado  : R$ %.2f\n", menorFrete);
                   printf("Total de isenções (Frete Grátis): %d\n", fretesGratuitos);
                   printf("==================================================================\n");
                        }
                    break;



     case 3:

                        if(quantidadeEncomendas == 0)
                        {
                        printf("Nenhuma encomenda cadastrada. Utilize a opcao 1 primeiro.\n");
                        }
                        else
                        {
                  
                   //Exibir indicadores

                   printf ("Qual a meta de faturamento em frestes do dia?");
                   scanf("%f", &Meta);
                   printf("==================================================================\n");
                   printf("Meta de Faturamento: R$ %.2f\n", Meta);
                   if (totalReceita >= Meta)
                   {
                       printf("Meta atingida!\n");
                   }
                   else
                   {
                       printf("Faltam R$ %.2f para atingir a meta.\n", Meta - totalReceita);
                   }
                    
                   if (QuantidadePadrao > QuantidadeExpressa && QuantidadePadrao > QuantidadePrioritaria)
                    {
                    printf("Categoria mais utilizada no dia: Padrao\n");
                    }
                    else if (QuantidadeExpressa > QuantidadePadrao && QuantidadeExpressa > QuantidadePrioritaria)
                    {
                    printf("Categoria mais utilizada no dia: Expressa\n");
                    }
                    else if (QuantidadePrioritaria > QuantidadePadrao && QuantidadePrioritaria > QuantidadeExpressa)
                    {
                    printf("Categoria mais utilizada no dia: Prioritaria\n");
                    }
                    else
                    {
                    printf("Houve empate entre categorias.\n");
                    }

                    printf("Taca de Entregas com frete Grátis: %.2f%%\n", (float)fretesGratuitos / quantidadeEncomendas * 100);


                }


                 break;

     case 4:
                      //Sair do programa
                 printf("Saindo do programa...\n");
                    break;
                    

                    default:

                
                   printf("Opcao invalida!\n");
                }

            

            }
        
        


                return 0;


}