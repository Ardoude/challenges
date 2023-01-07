/******************************************************************************
Nome: Eduardo Pereira Costa
Submissão: 24/04/2018 22:41:02
Ordem de Complexidade:
*******************************************************************************/

import java.util.Scanner;

public class j2247 {
    public static void main(String[] args) {
    int n, j, z, teste=1, da, aux=0, x, w=0, d, aux1=0, aux3=0;
    int ns[] = new int [300];
    ns[0]=0;
    int resp[] = new int [3000];
    resp[0]=0;
    Scanner in = new Scanner(System.in);
    while(true){
        n=in.nextInt();
        if(n==0)
            break;
        x=0;
        ns[aux]=n;
        da=0;
        while(n>0){
            d=0;
            j=in.nextInt();
            z=in.nextInt();
            d=j-z+da;
            da=d;
            resp[w]=da;
            x++;
            w++;
            n--;
        }
    aux++;
    }

    w=0;
    if(ns[0]>0){
        System.out.println("Teste "+teste);
        teste++;
        for(x=0;x<aux;x++){
            for(int a=aux1;a<ns[x]+aux3;a++){
                System.out.println(resp[a]);
                aux1=a+1;
                if(aux1==ns[w]+aux3){
                    aux3=aux1;
                    System.out.println();
                    if(ns[w+1]==0){
                        aux3=-999;
                        break;
                    }
                    System.out.println("Teste "+teste);
                    w++;  
                    teste++;
                }
            }
        }
    }
} 
}
