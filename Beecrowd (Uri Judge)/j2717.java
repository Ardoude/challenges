/******************************************************************************
Nome: Eduardo Pereira Costa
Submissão: 06/04/2018 10:35:20
Ordem de Complexidade:
*******************************************************************************/

import java.io.IOException;
import java.util.Scanner;

public class j2717 { 
    public static void main(String[] args) throws IOException {
        int n,a,b,temp;
        Scanner in = new Scanner(System.in);
        n=in.nextInt();
        a=in.nextInt();
        b=in.nextInt();
        temp=a+b;
        if(temp<=n)
            System.out.println("Farei hoje!");
        else
            System.out.println("Deixa para amanha!");
    }
 
}