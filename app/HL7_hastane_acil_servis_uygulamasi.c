#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_NAME_LENGTH 50      // AD SOYAD KARAKTER UZUNLUGU    
#define MAX_SYMPTOMS_LENGTH 200     // BULUNAN SEMPTOMLARIN KARAKTER UZUNLUGU
#define MAX_PRESCRIPTION_LENGTH 100     // RECETE KARAKTER UZUNLUGU

typedef struct {

    int patientId;
    int age;
    int priority;
    char name[MAX_NAME_LENGTH];
    char symptoms[MAX_SYMPTOMS_LENGTH];
    char prescription[MAX_PRESCRIPTION_LENGTH];
} Patient;

Patient *patients[100]; // MAX KABUL EDILEN HASTA SAYISI 100
int patientCount = 0;   //  HASTA KAYDI YAPILDIGINDA ARTACAK, KAYDI SILINDIGINDE AZALACAK SAYAC (indeks olarak kullanicaz)

// HASTA KAYDI OLUSTUR
void registerPatient(){

    if(patientCount < 100){

        patients[patientCount] = (Patient*) malloc(sizeof(Patient));
        Patient *newPatient = patients[patientCount];

        srand(time(NULL));
        newPatient->patientId = rand() % 1000 + 1;  // 1 ila 10000 arasinda rastgele ID 

        printf("Hasta ID: %d\n", newPatient->patientId);
        
        printf("Ad Soyad: ");
        scanf(" %[^\n]s", newPatient->name);

        printf("Yas: ");
        scanf("%d", &newPatient->age);

        printf("Sikayetler: ");
        scanf(" %[^\n]s", newPatient->symptoms);

        printf("Triyaj Onceligi (1-5, 1 en yuksek oncelik): ");
        scanf("%d", &newPatient->priority);

        strcpy(newPatient->prescription, "");

        patientCount++;

        printf("Hasta kaydedildi.\n");
    }else{

        printf("Maksimum hasta sayisina ulasildi.\n");
    }
}

// HASTALAR TRIYAJ ONCELIK SIRASINA GORE DIZ
void triagePatients(){

    if(patientCount == 0){

        printf("Kayitli hasta bulunmamaktadir. Oncelikle hasta kaydi yapin.\n");
        return;
    }

    for(int i=0; i < patientCount-1; i++){

        for(int j=0; j < patientCount-i-1; j++){

            if(patients[j]->priority > patients[j+1]->priority){

                Patient* temp = patients[j];
                patients[j] = patients[j+1];
                patients[j+1] = temp;
            }
        }
    }

    printf("Hastalar oncelik sirasina gore triyaj edildi.\n");
}

// HASTA RECETESI OLUSTUR
void prescribeMedication(){

    if(patientCount == 0){

        printf("Kayitli hasta bulunmamaktadir. Oncelikle hasta kaydi yapin.");
        return;
    }

    int patientId, found = 0;

    printf("Recete yazilacak hasta ID:");
    scanf("%d", &patientId);

    for(int i=0; i<patientCount; i++){

        if(patients[i]->patientId == patientId){

            printf("Recete: ");
            scanf(" %[^\n]s", patients[i]->prescription);
            
            printf("Recete yazildi.\n");

            found = 1;
            break;
        }
    }

    if(!found)
        printf("Hasta bulunamadi.\n");
}

// KISISEL HASTA BILGILERINI EKRANA YAZ
void displayPatientInfo(){

    if(patientCount == 0){

        printf("Kayitli hasta bulunmamaktadir. Oncelikle hasta kaydi yapin.");
        return;
    }

    int patientId, found = 0;

    printf("Goruntulenecek hasta ID: ");
    scanf("%d", &patientId);

    for(int i=0; i < patientCount; i++){

        if(patients[i]->patientId == patientId){

            printf("Hasta ID: %d\n", patientId);
            printf("Ad Soyad: %s\n", patients[i]->name);
            printf("Yas: %d\n", patients[i]->age);
            printf("Sikayetler: %s\n", patients[i]->symptoms);
            printf("Triyaj Onceligi: %d\n", patients[i]->priority);
            printf("Recete: %s", patients[i]->prescription);
            
            found = 1;
            break;
        }
    }

    if(!found)
        printf("Hasta bulunamadi.\n");
}

// TUM HASTALARIN BILGILERINI EKRANA YAZ
void displayAllPatients(){

    if(patientCount == 0){

        printf("Kayitli hasta bulunmamaktadir.\n");
        return;
    }

    for(int i=0; i < patientCount-1; i++){

        for(int j=0; j < patientCount-i-1; j++){
            
            if(patients[j]->priority > patients[j+1]->priority){

                Patient *temp = patients[j];
                patients[j] = patients[j+1];
                patients[j+1] = temp;
            }
        }
    }

    printf("\nHASTA LISTESI\n\n");
    printf("-----------------\n\n");

    for(int i=0; i < patientCount; i++){

        printf("ID: %d\n", patients[i]->patientId);
        printf("Ad Soyad: %s\n", patients[i]->name);
        printf("Yas: %d\n", patients[i]->age);
        printf("Oncelik sirasi: %d\n\n", patients[i]->priority);
    }
}

int main(){

    int choice;

    while(1){

        printf("\nACIL SERVIS SISTEMI\n\n");
        printf("---------------------\n\n");

        printf("1 --> HASTA KAYDI\n");
        printf("2 --> TRIYAJ SIRALAMA\n");
        printf("3 --> RECETE YAZMA\n");
        printf("4 --> KISISEL HASTA BILGILERI\n");
        printf("5 --> TUM HASTA BILGILERI\n");
        printf("6 --> CIKIS\n\n");

        printf("Seciminiz: ");
        scanf("%d", &choice);

        switch(choice){

            case 1:
                system("cls");
                registerPatient();
                break;
            
            case 2:
                system("cls");
                triagePatients();
                break;
            
            case 3:
                system("cls");
                prescribeMedication();
                break;

            case 4:
                system("cls");
                displayPatientInfo();
                break;
            
            case 5:
                system("cls");
                displayAllPatients();
                break;

            case 6:
                system("cls");
                printf("Program sonlandiriliyor");

                for(int i=0; i<3; i++){

                    sleep(1);
                    printf(".");
                }

                return 0;
        }
    }

    return 0;
}