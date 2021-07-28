#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>
#include <windows.h>

COORD coord = {0,0};
void gotoxy(int x,int y)
{
    coord.X=x;
    coord.Y=y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
}

char username[10],pass[10];
int c,batas;

struct kamus
{
    char bahasa_indonesia[20], bahasa_inggris[20], bahasa_spanyol[20], bahasa_itali[20], bahasa_perancis[20];
}kata[50];

void welcome(){
    system("cls");
	char w1[] = {" O       O    O O O O   O         O O O O   O O O O   O       O   O O O O "};
	char w2[] = {" O   O   O    O         O         O         O     O   O O   O O   O       "};
	char w3[] = {" O  O O  O    O O O O   O         O         O     O   O  O O  O   O O O O "};
	char w4[] = {" O O   O O    O         O         O         O     O   O   O   O   O       "};
	char w5[] = {" O       O    O O O O   O O O O   O O O O   O O O O   O       O   O O O O "};

	int nilai;
	int i=0;

	while(i != 2){
        int o = 1;
        system("COLOR 3F");
        system("cls");
        printf("\n\n\n\n\n\n\n\n\n\n\t\t\t%s",w1);Sleep(250);
		printf("\n\t\t\t%s",w2);Sleep(250);
		printf("\n\t\t\t%s",w3);Sleep (250);
		printf("\n\t\t\t%s",w4);Sleep (250);
		printf("\n\t\t\t%s",w5);Sleep (250);
		i=i+1;
	}
	login();
}

void login ()
{
    system("cls");
    int input;
    time_t w;
    time(&w);
    int i,j;
    gotoxy(35,7);printf(" ________________________________________________");Sleep(100);
    gotoxy(35,8);printf("|                                                |");Sleep(100);
    gotoxy(35,9);printf("|             %s",ctime(&w));
   gotoxy(35,10);printf("|________________________________________________|");Sleep(100);
   gotoxy(35,11);printf("|                                                |");Sleep(100);
   gotoxy(35,12);printf("|             USERNAME     :                     |");Sleep(100);
   gotoxy(35,13);printf("|             PASSWORD     :                     |");Sleep(100);
   gotoxy(35,14);printf("|                                                |");Sleep(100);
   gotoxy(35,15);printf("|________________________________________________|");Sleep(100);
    gotoxy(63,12);scanf("%s",&username);
    gotoxy(63,13);for (int i=0;i<10;i++){
    pass[i]=getch();
    if (pass[i]=='\r'){
        pass[i]=NULL;
        break;
    }if (pass[i]=='\b'){
        if(i!=0)printf("\b \b");
        pass[i]=NULL;
        pass[i-1]=NULL;
        i-=2;
        if(i<-1)i=-1;
            continue;
    }printf("*");
    }
    while(j<3) {
        char u=strcmp(username,"admin");
        char t=strcmp(pass,"admin");
        if(u == 0 && t == 0){
            gotoxy(50,17);
            printf("login berhasil");
            getch();
            system("cls");
            j=j+3;
            menu();
        }
        else {
            gotoxy(45,17);
            printf("Username atau Password salah");
            getch();
            system("cls");
            j++;
            if (j==3) {
                system("cls");
                gotoxy(35,19);printf("Anda sudah mencoba melebihi 3x, anda akan keluar dari program");
                break;
            }
            else {
                login();
            }
        }
    }
}

void menu()
{
    int input;
    time_t w;
    time(&w);
    do {
        system("cls");
        gotoxy(35,2);printf(" ________________________________________________");Sleep(100);
        gotoxy(35,3);printf("|                                                |");Sleep(100);
        gotoxy(35,3);printf("|             %s",ctime(&w));
        gotoxy(35,4);printf("|________________________________________________|");Sleep(100);
        gotoxy(35,5);printf("|                                                |");Sleep(100);
        gotoxy(35,6);printf("|             1>   TAMBAH DATA                   |");Sleep(100);
        gotoxy(35,7);printf("|             2>   LIHAT ISI KAMUS               |");Sleep(100);
        gotoxy(35,8);printf("|             3>   EDIT ISI KAMUS                |");Sleep(100);
        gotoxy(35,9);printf("|             4>   HAPUS ISI KAMUS               |");Sleep(100);
        gotoxy(35,10);printf("|             5>   CARI KOSA KATA                |");Sleep(100);
        gotoxy(35,11);printf("|             6>   PENGURUTAN ISI KAMUS          |");Sleep(100);
        gotoxy(35,12);printf("|             7>   KELUAR                        |");Sleep(100);
        gotoxy(35,13);printf("|                                                |");Sleep(100);
        gotoxy(35,14);printf("|________________________________________________|");Sleep(100);
        gotoxy(35,17);printf("            Masukkan menu yang dipilih :          ");
        gotoxy(76,17);scanf("%d",&input);
        switch(input){
        case 1:
            system("cls");
            tambah();
            break;
        case 2:
            system("cls");
            lihat();
            break;
        case 3:
            system("cls");
            edit();
            break;
        case 4:
            system("cls");
            hapus();
            break;
        case 5:
            system("cls");
            cari();
            break;
        case 6:
            system("cls");
            urut();
            break;
        case 7:
            system("cls");
            keluar();
            break;
        default :
            printf("Tidak ada menu !");
        }
    } while (input != 7);
}

void tambah()
{
    int a,b;
    gotoxy(53,1);printf("INPUT KATA");
    gotoxy(0,3);printf("Berapa kata yang ingin diinput : ");scanf("%d",&batas);
    system("cls");
    for(a=0+c;a<batas+c;a++) {
        system("cls");
        gotoxy(35,4);printf("_____________________________________________");Sleep(50);
        for(b=0; b<10; b++){
            gotoxy(34,5+b);printf("|                                             |");Sleep(50);
        }
        gotoxy(35,14);printf("_____________________________________________");Sleep(50);
        gotoxy(54,1);
        printf("Kata ke-%d\n",a+1);
        gotoxy(37,5);printf("Bahasa Indonesia : ");scanf("%s",&kata[a].bahasa_indonesia);
        gotoxy(37,7);printf("Bahasa Inggris : ");scanf("%s",&kata[a].bahasa_inggris);
        gotoxy(37,9);printf("Bahasa Spanyol : ");scanf("%s",&kata[a].bahasa_spanyol);
        gotoxy(37,11);printf("Bahasa Itali : ");scanf("%s",&kata[a].bahasa_itali);
        gotoxy(37,13);printf("Bahasa Perancis : ");scanf("%s",&kata[a].bahasa_perancis);
    }
    c=c+batas;
}

void lihat()
{
    if (c==0) {
        gotoxy(50,9);printf("Belum Ada Data !");
        getch();
    }
    else {
        int a,b,z=0;
        for(b=5; b<110; b++){
                gotoxy(b,0);printf("-");Sleep(5);
        }
        gotoxy(10,1);printf("Bahasa Indonesia");Sleep(100);
        gotoxy(30,1);printf("Bahasa Inggris");Sleep(100);
        gotoxy(50,1);printf("Bahasa Spanyol");Sleep(100);
        gotoxy(70,1);printf("Bahasa Itali");Sleep(100);
        gotoxy(90,1);printf("Bahasa Perancis");Sleep(100);
        for(b=5; b<110; b++){
                gotoxy(b,2);printf("-");Sleep(5);
        }
        for(a=0;a<c;a++) {
            gotoxy(10,4+z);printf("%s",kata[a].bahasa_indonesia);
            gotoxy(30,4+z);printf("%s",kata[a].bahasa_inggris);
            gotoxy(50,4+z);printf("%s",kata[a].bahasa_spanyol);
            gotoxy(70,4+z);printf("%s",kata[a].bahasa_itali);
            gotoxy(90,4+z);printf("%s",kata[a].bahasa_perancis);
            z=z+1;
        }
        getch();
    }
}

void edit()
{
    lihat();
    if (c == 0) {

    }
    else {
        system("cls");
        int a,b,z=-1;
        char u[50];
        printf("Masukkan Bahasa Indonesia untuk update : ");scanf("%s",&u);
        for(a=0;a<c;a++) {
            if(strcmp(u,kata[a].bahasa_indonesia)==0) {
                z=a;
            }
        }
        if (z == -1) {
            gotoxy(50,9);printf("Kata tidak ditemukan !");
            getch();
        } else {
            system("cls");
            gotoxy(53,1);printf("UPDATE KATA");
            gotoxy(35,4);printf("_____________________________________________");Sleep(50);
            for(b=0; b<10; b++){
                gotoxy(34,5+b);printf("|                                             |");Sleep(50);
            }
            gotoxy(35,14);printf("_____________________________________________");Sleep(50);
            gotoxy(37,5);printf("Bahasa Indonesia : ");scanf("%s",&kata[z].bahasa_indonesia);
            gotoxy(37,7);printf("Bahasa Inggris : ");scanf("%s",&kata[z].bahasa_inggris);
            gotoxy(37,9);printf("Bahasa Spanyol : ");scanf("%s",&kata[z].bahasa_spanyol);
            gotoxy(37,11);printf("Bahasa Itali : ");scanf("%s",&kata[z].bahasa_itali);
            gotoxy(37,13);printf("Bahasa Perancis : ");scanf("%s",&kata[z].bahasa_perancis);
        }
    }
}

void hapus()
{
    lihat();
    if (c == 0) {

    }
    else {
        system("cls");
        int a,z=-1;
        char u[50],temp[50];
        printf("Masukkan Bahasa Indonesia untuk dihapus : ");scanf("%s",&u);
        for(a=0;a<c;a++) {
            if(strcmp(u,kata[a].bahasa_indonesia)==0) {
                z=a;
            }
        }
        if (z == -1) {
            gotoxy(50,9);printf("Kata tidak ditemukan !");
            getch();
        }
        else {
            while(z+1 <c) {
                strcpy(kata[z].bahasa_indonesia,kata[z+1].bahasa_indonesia);
                strcpy(kata[z].bahasa_inggris,kata[z+1].bahasa_inggris);
                strcpy(kata[z].bahasa_spanyol,kata[z+1].bahasa_spanyol);
                strcpy(kata[z].bahasa_itali,kata[z+1].bahasa_itali);
                strcpy(kata[z].bahasa_perancis,kata[z+1].bahasa_perancis);
                z++;
            }
            c--;
        }
    }
}

void cari()
{
    if (c==0) {
        gotoxy(50,9);printf("Belum Ada Data !");
        getch();
    }
    else {
        int a,b,z=-1;
        char u[50];
        printf("Masukkan Bahasa Indonesia yang ingin dicari : ");scanf("%s",&u);
        for(a=0;a<c;a++) {
            if(strcmp(u,kata[a].bahasa_indonesia)==0) {
                z=a;
            }
        }
        if (z == -1) {
            gotoxy(50,9);printf("Kata tidak ditemukan !");
            getch();
        }
        else {
            system("cls");
            for(b=5; b<110; b++){
                    gotoxy(b,0);printf("-");Sleep(5);
            }
            gotoxy(10,1);printf("Bahasa Indonesia");Sleep(100);
            gotoxy(30,1);printf("Bahasa Inggris");Sleep(100);
            gotoxy(50,1);printf("Bahasa Spanyol");Sleep(100);
            gotoxy(70,1);printf("Bahasa Itali");Sleep(100);
            gotoxy(90,1);printf("Bahasa Perancis");Sleep(100);
            for(b=5; b<110; b++){
                    gotoxy(b,2);printf("-");Sleep(5);
            }
            gotoxy(10,4);printf("%s",kata[z].bahasa_indonesia);
            gotoxy(30,4);printf("%s",kata[z].bahasa_inggris);
            gotoxy(50,4);printf("%s",kata[z].bahasa_spanyol);
            gotoxy(70,4);printf("%s",kata[z].bahasa_itali);
            gotoxy(90,4);printf("%s",kata[z].bahasa_perancis);
            getch();
        }
    }
}

void urut()
{
    if (c==0) {
        gotoxy(50,9);printf("Belum Ada Data !");
        getch();
    }
    else {
        int a,b;
        char z[50];
        for(a = 0; a < c;a++) {
            for(b = a+1; b < c;b++) {
                if(strcmp(kata[a].bahasa_indonesia,kata[b].bahasa_indonesia) >= 0) {
                    strcpy(z,kata[a].bahasa_indonesia);
                    strcpy(kata[a].bahasa_indonesia,kata[b].bahasa_indonesia);
                    strcpy(kata[b].bahasa_indonesia,z);

                    strcpy(z,kata[a].bahasa_inggris);
                    strcpy(kata[a].bahasa_inggris,kata[b].bahasa_inggris);
                    strcpy(kata[b].bahasa_inggris,z);

                    strcpy(z,kata[a].bahasa_spanyol);
                    strcpy(kata[a].bahasa_spanyol,kata[b].bahasa_spanyol);
                    strcpy(kata[b].bahasa_spanyol,z);

                    strcpy(z,kata[a].bahasa_itali);
                    strcpy(kata[a].bahasa_itali,kata[b].bahasa_itali);
                    strcpy(kata[b].bahasa_itali,z);

                    strcpy(z,kata[a].bahasa_perancis);
                    strcpy(kata[a].bahasa_perancis,kata[b].bahasa_perancis);
                    strcpy(kata[b].bahasa_perancis,z);
                }
			}
		}
    }
}

void keluar()
{
    system("cls");
	char w1[] = {" O O O O     O       O     OO     O O O O O"};
	char w2[] = {" O             O   O       OO         O    "};
	char w3[] = {" O O O O         O         OO         O    "};
	char w4[] = {" O             O   O       OO         O    "};
	char w5[] = {" O O O O     O       O     OO         O    "};

	int nilai;
	int i=0;

	while(i != 2){
        int o = 1;
        system("COLOR 3F");
        system("cls");
        printf("\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t%s",w1);Sleep(250);
		printf("\n\t\t\t\t\t%s",w2);Sleep(250);
		printf("\n\t\t\t\t\t%s",w3);Sleep (250);
		printf("\n\t\t\t\t\t%s",w4);Sleep (250);
		printf("\n\t\t\t\t\t%s",w5);Sleep (250);
		i=i+1;
	}
	system("exit");
}

void main ()
{
    welcome();
}
