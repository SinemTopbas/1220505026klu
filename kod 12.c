#include <stdio.h>
#include <stdbool.h>

bool alt_kume_toplam_esit(int dizi[], int boyut) {
    int toplam = 0;
    int i;
    int j;
    
    for (i = 0; i < boyut; i++) {
        toplam += dizi[i];
    }
 
    if (toplam % 2 == 1) {
        return false;
    }
    int hedef = toplam / 2;
    bool alt_kume[toplam + 1];
    for (i = 0; i <= toplam; i++) {
        alt_kume[i] = false;
    }
    alt_kume[0] = true;
    for (i = 0; i < boyut; i++) {
        for (j = toplam; j >= dizi[i]; j--) {
            alt_kume[j] = alt_kume[j] || alt_kume[j - dizi[i]];
        }
    }
    return alt_kume[hedef];
}

int main() {
    int dizi[] = {1, 2, 3, 4, 5};
    int boyut = sizeof(dizi) / sizeof(dizi[0]);

    if (alt_kume_toplam_esit(dizi, boyut))
   {
        printf("Dizi iki alt kume halinde esit toplama sahiptir.");
    }
 else 
   {
        printf("Dizi iki alt kume halinde esit toplama sahip degildir.");
    }
    return 0;
 }


