import java.util.*;

public class Main {
    public static void main(String[] args){

        int nilaiAwal, nilaiAkhir, Total;
        Scanner inputUser = new Scanner(System.in);
        System.out.print("Masukkan Nilai Awal = ");
        nilaiAwal = inputUser.nextInt();
        System.out.print("Masukkan Nilai Akhir = ");
        nilaiAkhir = inputUser.nextInt();
        System.out.print("Masukkan Nilai Total = ");
        Total = inputUser.nextInt();
        System.out.println("Total Awal = " + Total);
        //do while
      do {
            Total = Total + nilaiAwal;
            System.out.println("Total ditambah dengan " + nilaiAwal + " menjadi " + Total);
            nilaiAwal++;
        } while(nilaiAwal <= nilaiAkhir);
       //for loop
        for (int i = nilaiAwal;i<=nilaiAkhir;i++){
            Total = Total + i;
            System.out.println("Total ditambah dengan " + i + " menjadi " + Total);
        }
    }
}
