import java.util.*;

public class Main {
    public static void main(String[] args){

        String kembali;
        int pilih,jumlahMakanan,hapus;
        ArrayList<String> food = new ArrayList<>();
        Scanner inputUser = new Scanner(System.in);

        System.out.println("Selamat Datang \n");
        do{
        System.out.println("Silakan Pilih Menu");
        System.out.println("1. Tambah Daftar Makanan");
        System.out.println("2. Hapus Daftar Makanan");
        System.out.println("3. Tampilkan Daftar Makanan");
        System.out.print("Pilih Nomor = ");
        pilih = inputUser.nextInt();
        if(pilih == 1){
            System.out.print("Masukkan Jumlah Makanan = ");
            jumlahMakanan = inputUser.nextInt();
            inputUser.nextLine();
            for(int i = 1;i <= jumlahMakanan;i++){
                System.out.print("Masukkan makanan ke " + i + " = " );
                food.add(inputUser.nextLine());
            }
            System.out.print("Kembali ke Menu? (Y/y) ");
            kembali = inputUser.next();
        }
        else if(pilih == 2){
            System.out.print("Masukkan Nomor Makanan = ");
            hapus = inputUser.nextInt();
            hapus--;
            food.remove(hapus);
            System.out.print("Kembali ke Menu? (Y/y) ");
            kembali = inputUser.next();
        }
        else if(pilih == 3) {
            for (String i : food) {
                System.out.println(i);
            }
            System.out.print("Kembali ke Menu? (Y/y) ");
            kembali = inputUser.next();
        }
        else{
            System.out.println("Nomor Tidak Sesuai");
            System.out.print("Kembali ke Menu? (Y/y) ");
            kembali = inputUser.next();
        }
    }while(kembali.equals("y") || kembali.equals("Y"));
}}
