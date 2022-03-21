package com.belajar;
import java.util.Scanner;

public class Main{

    public static void main(String[] args) {
	int panjang,lebar,tinggi,volume;
    Scanner userInput = new Scanner(System.in);
        System.out.print("panjang = ");
        panjang = userInput.nextInt();
        System.out.print("lebar = ");
        lebar = userInput.nextInt();
        System.out.print("tinggi = ");
        tinggi = userInput.nextInt();
        volume = panjang * lebar * tinggi;
        System.out.println("Volume = " + volume);

    }

}
