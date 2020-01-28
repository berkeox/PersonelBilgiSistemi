 #include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>



typedef struct {

   char isim[100];
   long long int tckimlikno;
   long long int telefon;
   char eposta[100];
   char adres[100];

 }  personel;




int cikis();





int main()
{
setlocale(LC_ALL, "Turkish");

   long long int aranantc,aranantcc;
    int msecim,i;
    char duzenlead[100],arananisim[100];
    int sayac,t;
    personel pbilgi,plistele,paranan;
    FILE *xd,*xf, *txd;
    char menus,ydene;
    int kontrol=0;
    





    printf("BERKE ÖNCÜL | UÐUR ÇÝFTÇÝ\n-------------------------\n 172803011  | 172803053\n");   // Bilgiler
 printf("-------------------------\n\n");







 menu:
 	kontrol=0;


        
        
        

 printf("\n\n-----------PERSONEL BÝLGÝ SÝSTEMÝ-----------\n\n");
 printf("ÝÞLEMLER\n\n");

 printf("1.Kayýt ekle\n");
 printf("2.Personel listele\n");
 printf("3.Kaydý düzenle\n");
 printf("4.TC Kimlik no ile kayýt bul\n");
 printf("5.Ýsim ile kayýt bul\n");
 printf("6.Kayýt sil\n");
 printf("0.Çýkýþ\n");

 printf("Seciminiz:");
 scanf("%d",&msecim);
 
 if(msecim<0 || msecim>6)
 {
 	printf("\nGeçersiz seçim");
 	goto menu;
 }


 switch (msecim)
 {
 case 1:  //KAYIT EKLE
    {

        printf("\nPersonel isim:");
        scanf("%s",&pbilgi.isim);

        printf("Personel TC kimlik no:");
        scanf("%lld",&pbilgi.tckimlikno);

        printf("Personel telefon no:");
        scanf("%lld",&pbilgi.telefon);

        printf("Personel eposta:");
        scanf("%s",&pbilgi.eposta);

        printf("Personel adres:");
        scanf("%s",&pbilgi.adres);

        sayac++;


        xd=fopen("Personel.txt","a");
        fwrite(&pbilgi,sizeof(pbilgi),1,xd);
        fclose(xd);
        
        if(sayac!=0)
        {
        	xf=fopen("sayac.txt","w");
        	fwrite(&sayac,sizeof(sayac),1,xd);
        	fclose(xf);
		}


        goto menu;



    }
 case 2: //KAYITLARI GÖRÜNTÜLE
    {
    	
    	xf=fopen("sayac.txt","r");
        fread(&sayac,sizeof(sayac),1,xf);
        fclose(xf);
        
          	
    	if(sayac==0)
    	{
    		printf("\nGörüntülenecek kayýt yok! \a\n");
    		printf("Devam etmek için herhangi bir tuþa basýn");
    		getch();
    		goto menu;
		}
    
    
    xd=fopen("Personel.txt","r");

     printf("------------------------------------");

     

     for(i=1;i<=sayac;i++)
     {


         if(fread(&plistele,sizeof(plistele),1,xd)==1)
    {
        printf("\nPersonel isim:%s",plistele.isim);
        printf("\nPersonel TC kimlik no:%lld",plistele.tckimlikno);
        printf("\nPersonel telefon no:%lld",plistele.telefon);
        printf("\nPersonel eposta:%s",plistele.eposta);
        printf("\nPersonel adres:%s\n",plistele.adres);
        printf("------------------------------------");
    }

     }


      fclose(xd);


        printf("\n\nMenüye dönülsün mü? (E/H):");
        scanf("%s", &menus);

        if(toupper(menus)=='E')
        {
           goto menu;
        }
        else
        {
            return 0;
        }



    }
 case 3: //KAYIT DÜZENLE
    {
    	
    	xf=fopen("sayac.txt","r");
        fread(&sayac,sizeof(sayac),1,xf);
        fclose(xf);
        
        
        
        
    	if(sayac==0)
    	{
    		printf("\nDüzenlenecek kayýt yok \a\n");
    		printf("Devam etmek için herhangi bir tuþa basýn");
    		getch();
    		goto menu;
		}
    	
    
    	 kayitduzenle:
    	 
   printf("\nDuzenlemek istediginiz personelin adi:");
     scanf("%s",&duzenlead);
     
     
     txd=fopen("tpersonel.txt","a");
     xd=fopen("Personel.txt","r");
     
      for(i=1;i<=sayac;i++)
     {
            
            if(fread(&plistele,sizeof(plistele),1,xd)==1)
            {
            	
             if(strcmp(duzenlead,plistele.isim)!=0)
                {              	
                
               		fwrite(&plistele, sizeof(personel), 1, txd);
					   kontrol++; 		
				}
				if (strcmp(duzenlead,plistele.isim)==0)
				{
					printf("\nPersonel isim:");
                    scanf("%s",&plistele.isim);

                    printf("Personel TC kimlik no:");
                    scanf("%lld",&plistele.tckimlikno);

                    printf("Personel telefon no:");
                    scanf("%lld",&plistele.telefon);

                    printf("Personel eposta:");
                    scanf("%s",&plistele.eposta);

                    printf("Personel adres:");
                    scanf("%s",&plistele.adres);
                    
                    fwrite(&plistele,sizeof(personel),1,txd);
                    
                    
                    
				}	
			}
                         
     }
     
     fclose(xd);
     fclose(txd);
     
     
    
     remove("Personel.txt");
    
     rename("tpersonel.txt","Personel.txt");
     
     txd=fopen("tpersonel.txt","w+");
     fclose(txd);
     
     
      if(kontrol==sayac)
     {
     	printf("Aradýðýniz isim bulunamadý! \a");
     	printf("\nYeniden denemek ister misiniz? (E/H):");
     	
     	scanf("%s" , &ydene);
        printf("\n");

        if(toupper(ydene)=='E')
        {
        	kontrol=0;
             goto kayitduzenle;
         }
        else
        {

            printf("Menüye dönülüyor\n\n");
            kontrol=0;

            goto menu;
        }
    }
     
     
     
     printf("\n\nKayýt düzenlendi!");
	printf("\nMenüye dönülsün mü? (E/H):");
     scanf("%s", &menus);

        if(toupper(menus)=='E')
        {
           goto menu;
        }
        else
        {
            return 0;
        }
    
    
 
    }
 case 4: // TC KIMLIK ILE ARAMA
    {
    	
    	
    	
    	xf=fopen("sayac.txt","r");
        fread(&sayac,sizeof(sayac),1,xf);
        fclose(xf);
        
        
        if(sayac==0)
    	{
    		printf("\nAranacak kayýt yok \a\n");
    		printf("Devam etmek için herhangi bir tuþa basýn");
    		getch();
    		goto menu;
		}
		
		tcarama:
    	
     printf("Aranacak kiþinin TC kimlik no'sunu giriniz:");
     scanf("%lld",&aranantc);
     
     xd=fopen("Personel.txt","r");
     
     for(i=1;i<=sayac;i++)
     {
     	 fread(&plistele,sizeof(plistele),1,xd);
     	 
     	
     	 if(aranantc==plistele.tckimlikno)
     {
	 
     
     printf("\n\n------------------------------------\n");
     printf("Personel isim: %s\n",plistele.isim);
     printf("Personel TC: %lld\n",plistele.tckimlikno);
     printf("Personel Telefon:%lld\n",plistele.telefon);
     printf("Personel e-posta:%s\n",plistele.eposta);
     printf("Personel adresi:%s\n",plistele.adres);
     printf("------------------------------------\n\n");
     kontrol++;
	 }
	 if(aranantc!=plistele.tckimlikno && i==sayac && kontrol!=1)
	 {
	 printf("Aradiðiniz TC bulunamadý\n");
	 printf("Yeniden denemek ister misiniz (E/H)");
	 
	 scanf("%s" , &ydene);
        printf("\n");

        if(toupper(ydene)=='E')
        {
        	kontrol=0;
             goto tcarama;
         }
        else
        {

            printf("Menüye dönülüyor\n\n");
            kontrol=0;

            goto menu;
        }
	 
	 }
	 
    }  
	 
	 fclose(xd);
	 
	 
	 printf("\n\nMenüye dönülsün mü? (E/H):");
     scanf("%s", &menus);

        if(toupper(menus)=='E')
        {
        	
           goto menu;
        }
        else
        {
            return 0;
        }
     
      
    
      }

    

      
 case 5: //ISIM ILE ARAMA
    {
    	xf=fopen("sayac.txt","r");
        fread(&sayac,sizeof(sayac),1,xf);
        fclose(xf);
        
        
        iarama:
        
        if(sayac==0)
    	{
    		printf("\nAranacak kayýt yok \a\n");
    		printf("Devam etmek için herhangi bir tuþa basýn");
    		getch();
    		goto menu;
		}
    	
    printf("Aranacak kiþinin ismini giriniz:");
     scanf("%s",&arananisim);
     
     xd=fopen("Personel.txt","r");
     
     
     for(i=1;i<=sayac;i++)
     {
     	
     fread(&plistele,sizeof(plistele),1,xd);
     
     if(strcmp(plistele.isim,arananisim)==0)
     {
	 printf("\n\n------------------------------------\n");
     printf("Personel isim: %s\n",plistele.isim);
     printf("Personel TC: %lld\n",plistele.tckimlikno);
     printf("Personel Telefon:%lld\n",plistele.telefon);
     printf("Personel e-posta:%s\n",plistele.eposta);
     printf("Personel adresi:%s\n",plistele.adres);
     printf("------------------------------------\n\n");
     kontrol++;
     }
	if(strcmp(plistele.isim,arananisim)!=0 && i==sayac && kontrol!=1)
	 {
	 printf("Aradiðiniz isim bulunamadý\n");
	 printf("Yeniden denemek ister misiniz (E/H)");
	 
	 scanf("%s" , &ydene);
        printf("\n");

        if(toupper(ydene)=='E')
        {
        	kontrol=0;
             goto iarama;
         }
        else
        {

            printf("Menüye dönülüyor\n\n");
            kontrol=0;

            goto menu;
        }
	 
	 }

    }
	 
	 
	 fclose(xd);
     
    
        printf("\n\nMenüye dönülsün mü? (E/H):");
        scanf("%s", &menus);

        if(toupper(menus)=='E')
        {
        	kontrol=0;
           goto menu;
        }
        else
        {
            return 0;
        }
    } 


    
    
 case 6: //KAYIT SILME
    {
    	
    	
    
    	
    	
    	xf=fopen("sayac.txt","r");
        fread(&sayac,sizeof(sayac),1,xf);
        fclose(xf);
        
        
        if(sayac==0)
    	{
    		printf("\nSilinecek kayýt yok \a\n");
    		printf("Devam etmek için herhangi bir tuþa basýn");
    		getch();
    		goto menu;
		}
        
        	kayitsilme:

    	

   printf("Silmek istediginiz kiþinin TC'sini giriniz:");
     scanf("%lld", &aranantcc);
     
     xd=fopen("Personel.txt","r");
     txd=fopen("tpersonel.txt","a");
     
      
          
    for(i=1;i<=sayac;i++)
     {
            
            if(fread(&plistele,sizeof(plistele),1,xd)==1)
            {
             if(aranantcc!=plistele.tckimlikno)
                {              	
                
               	fwrite(&plistele, sizeof(personel), 1, txd);
               	kontrol++;
               		
				}	
			}
                     
            
     }
     
     fclose(xd);
     fclose(txd);
     
   
     remove("Personel.txt");
    
     rename("tpersonel.txt","Personel.txt");
     
     txd=fopen("tpersonel.txt","w+");
     fclose(txd);
     
     
     
     
     if(kontrol==sayac)
     {
     	printf("Aradýðýniz TC bulunamadý! \a");
     	printf("\nYeniden denemek ister misiniz? (E/H):");
     	
     	scanf("%s" , &ydene);
        printf("\n");

        if(toupper(ydene)=='E')
        {
        	kontrol=0;
             goto kayitsilme;
         }
        else
        {

            printf("Menüye dönülüyor\n\n");
            kontrol=0;

            goto menu;
        }
        
	 }
     
     
            sayac--;
        	xf=fopen("sayac.txt","w");
        	fwrite(&sayac,sizeof(sayac),1,xd);
        	fclose(xf);
	
     
    
     printf("\nDosya silindi!\n");
     printf("Devam etmek için herhangi bir tuþa basýn");
     getch();
     goto menu;
    }
    
    
 case 0: //BÝTTÝ
    {
        csoru:
        	
        	
        t=cikis(); 	
        	
     if(t==0)
     {
      return 0;	
	 }
     	
	 if  (t==1)
	 {
	  goto menu;	
	 }

	 if  (t==2)
	 {
	 	goto csoru;
	 }
	 
    }
    
}






}


int cikis()  //CIKMA FONKSIYONU
{
	char scikis;
	
	printf("Çýkmak istediðinizden emin misiniz? E/H:");
        scanf("%s" , &scikis);
        printf("\n");

        if(toupper(scikis)=='E')
        {
             return 0;
        }
        if(toupper(scikis)=='H')
        {
            printf("Menüye dönülüyor\n\n");
            return 1;
        }
        else
        {

            printf("Geçersiz giriþ!\a\n\n");

            return 2;
        }

          
		}



