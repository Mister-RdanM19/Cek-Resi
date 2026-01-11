#include <stdio.h>
#include <string.h>
#include <ctype.h>

void strtoupper(char *s){
    for(int i=0;s[i];i++) s[i]=toupper(s[i]);
}

int main(){
    char resi[100], kurir[20]="";

    printf("Masukkan nomor resi: ");
    scanf("%99s", resi);
    strtoupper(resi);

    if (strncmp(resi,"JNE",3)==0 || strncmp(resi,"JP",2)==0)
        strcpy(kurir,"jne");
    else if (strncmp(resi,"JX",2)==0 || strncmp(resi,"JT",2)==0)
        strcpy(kurir,"jnt");
    else if (strncmp(resi,"SCP",3)==0 || strncmp(resi,"002",3)==0)
        strcpy(kurir,"sicepat");
    else if (resi[0]=='P')
        strcpy(kurir,"pos");
    else{
        printf("Kurir tidak terdeteksi, isi manual: ");
        scanf("%19s", kurir);
    }

    char *url;
    if(strcmp(kurir,"jne")==0)
        url="https://www.jne.co.id/tracking-package?awb=";
    else if(strcmp(kurir,"jnt")==0)
        url="https://www.jet.co.id/track?awb=";
    else if(strcmp(kurir,"sicepat")==0)
        url="https://www.sicepat.com/checkAwb/";
    else if(strcmp(kurir,"pos")==0)
        url="https://www.posindonesia.co.id/id/tracking/";
    else if(strcmp(kurir,"anteraja")==0)
        url="https://anteraja.id/tracking?awb=";
    else{
        printf("Kurir tidak valid\n");
        return 1;
    }

    printf("Tracking URL: %s%s\n", url, resi);
    return 0;
}
