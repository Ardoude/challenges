/******************************************************************************
Nome: Eduardo Pereira Costa
Submissão: 08/03/2018 18:03:45
Ordem de Complexidade:
*******************************************************************************/

import java.io.IOException;
import java.util.Scanner;

public class j2496 {
    public static boolean theOnlyChance(char[] v,int m,int troca,char[] ord){
        for(int aux=0;aux<m;aux++){
            if(v[aux]!=ord[aux])
                troca++;   
        }

        if(troca>2)
            return false;
        else
            return true;
    }

    public static void main(String[] args) throws IOException{
        int n,m,troca=0;
        char[] vetor;
        String cadeia;
        char[] ord;
        char x=65;

        Scanner in = new Scanner (System.in);

        n = in.nextInt();
        while (n>0){
            m = in.nextInt();
            vetor = new char[m];
            ord = new char [m];

            for(int i=0;i<m;i++){
                ord[i]=x;
                x++;
            }
            x=65;
            cadeia = in.next();

            for(int i=0;i<m;i++)
                vetor[i]=cadeia.charAt(i);

            if(theOnlyChance(vetor,m,troca,ord))
                System.out.println("There are the chance.");
            else
                System.out.println("There aren't the chance.");
            n--;
        } 
    }
}