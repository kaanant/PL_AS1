#include <stdio.h>
#include <time.h>
#include <stdlib.h>


int passArea(char areaMtr[10][100],int racerNum,int areaSize);
int raceTour(int racerNum,int areaSize,char areaMtr[10][100],int waitingTime);


int main(){
	
	int racerNum=5;			//racerNum yarışcı sayısını tutan degisken mainde 5 olarak atandı ancak kullanıcı degistirebilir.
	int areaSize=50;		//areaSize parkur büyüklüğü koşulacak toplam mesafe 50 olarak atandı ancak kullanıcı 
	char areaMtr[10][100];		//areaMtr print edilecek parkur
	int waitingTime=1;
	int menuCont=5,i,j;
	srand(time(NULL));
	for(i=0;i<10;i++){
		for(j=0;j<100;j++){		// önce tüm matrisi '_' olarak atayıp üzerinde gerekli oynamaları fonk icerisinde yapılacak
			areaMtr[i][j]='_';
		}
	}
	do{
	printf("----MENU----\n");
	printf("0-Yarisi Baslatmak icin basiniz\n");
	printf("1-Yarisci sayisini girmek icin basiniz\n");
	printf("2-Parkur uzunlugunu girmek icin basiniz\n");
	printf("3-Bekleme süresini girmek icin basiniz\n\n");
	scanf("%d",&menuCont);
	if (menuCont==1){
		printf("Yarisci sayisini giriniz:");
		scanf("%d",&racerNum);
	}
	else if (menuCont==2){
		printf("\nParkur uzunlugunu giriniz:");
		scanf("%d",&areaSize);
	}
	else if (menuCont==3){
		printf("\nBekleme suresini giriniz:");
		scanf("%d",&waitingTime);
	}
	else{}
	}while(menuCont!=0);
	
	for(i=0;i<racerNum;i++){
		areaMtr[i][0]='A'+i;	
	}
	raceTour(racerNum,areaSize,areaMtr,waitingTime);	//fonkisyona tüm bilgiler eklenir


return 0;
}
int raceTour(int racerNum,int areaSize,char areaMtr[10][100],int waitingTime){
	int i,j,counter;
	int lastSit[]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
	
	do{
	counter=0;		//counter degiskeni  ile fonksiyonun ne kadar devam edecegi kontrol edilir

	passArea(areaMtr,racerNum,areaSize);	// passArea fonksiyonu ekrana bilgileri bastırma fonksiyonudur 						     			   		    
	
	for(i=0;i<racerNum;i++){			// bu for icerisinde her turda yarışcılar hareket ettirilir.
		areaMtr[i][lastSit[i]]='_';
		int speed=1+rand()%5;				     
		int move=lastSit[i]+speed;	//speed degiskeni her turda ilerlemeyi rastgele olarak belirler			      
		areaMtr[i][move]='A'+i;		// Matris char oldugunu icin yarışcılar 'A,B,C..' olarak atanır
		lastSit[i]=move;		// son kalınan yerin kaybolmaması için son kordinatlar kaydedilir		
		if (lastSit[i]>=areaSize){	// lastSit dizisinde
			areaMtr[i][areaSize-1]='A'+i;	// eger herhangi bir yarışcı parkuru tamamlamış ise kontrol
			}				// edilir ver parkurun son elemanı yarışcı olarak atanır.
	}
	for(j=0;j<racerNum;j++){
		if(lastSit[j]>areaSize)
			counter=counter+1;	// do..while kontrolü yapmak icin tüm yarışcıların parkuru bitirip 	
	}					// bitirmedigi kontrol edilir
	printf("\n\ncounter:%d\n\n",counter);
	
	}while(counter!=racerNum);

}

int passArea(char areaMtr[10][100],int racerNum,int areaSize){
	int i,j;

	for(i=0;i<racerNum;i++){
		for(j=0;j<areaSize;j++){
			printf("%c",areaMtr[i][j]);
		}
		printf("\n");
	}
	
}







