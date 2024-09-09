#include <stdio.h>
#include <stdlib.h>

long long saldo = 1337;

void lihat_saldo() {
    printf("Saldo Anda saat ini: Rp %lld\n", saldo);
}

void transfer_dana() {
    long long tujuan, jumlah;
    printf("Masukkan nomor rekening tujuan: ");
    scanf("%lld", &tujuan);
    printf("Masukkan jumlah dana yang ingin ditransfer: ");
    scanf("%lld", &jumlah);
    
    if (jumlah > saldo) {
        printf("Maaf, saldo tidak mencukupi untuk transfer sebesar Rp %lld\n", jumlah);
    } else {
        saldo -= jumlah;
        printf("Transfer berhasil! Saldo Anda saat ini: Rp %lld\n", saldo);
    }
}

void beli_flag() {
    if (saldo >= 100000000) {
        printf("Selamat! Anda berhasil membeli flag: ITDEL{jangan_lupakan_safety_saat_mengkoding_hnu073ku}\n");
    } else {
        printf("Maaf, saldo Anda tidak mencukupi untuk membeli flag.\n");
    }
}

void menu() {
    int pilihan;
    while (1) {
        printf("\nSelamat datang di Bank ITDEL!\n");
        printf("1. Lihat Saldo\n");
        printf("2. Transfer Dana\n");
        printf("3. Beli Flag (Harga Rp100 juta BTW wkwk)\n");
        printf("4. Keluar\n");
        printf("Masukkan pilihan Anda: ");
        scanf("%d", &pilihan);

        switch (pilihan) {
            case 1:
                lihat_saldo();
                break;
            case 2:
                transfer_dana();
                break;
            case 3:
                beli_flag();
                break;
            case 4:
                printf("Terima kasih telah menggunakan ATM Bank ITDEL. Sampai jumpa!\n");
                exit(0);
            default:
                printf("Pilihan tidak valid. Silakan coba lagi.\n");
        }
    }
}

int main() {
    setvbuf(stdout, NULL, 2, 0);
	setvbuf(stdin, NULL, 2, 0);
	setvbuf(stderr, NULL, 2, 0);
    menu();
    return 0;
}
