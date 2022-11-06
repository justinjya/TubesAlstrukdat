#include "console.h"
#include <time.h>

boolean compareString(char *string1, char *string2)
{
    while (*string1 != '\0' && *string2 != '\0')
    {
        if (*string1 != *string2)
        {
            return false;
        }
        string1++;
        string2++;
    }
    return true;
}

void concat(char *string1, char *string2, char *string3)
{
    int i = 0;
    int j = 0;

    while (string1[i] != '\0') {
        string3[j] = string1[i];
        i++;
        j++;
    }

    i = 0;
    while (string2[i] != '\0') {
        string3[j] = string2[i];
        i++;
        j++;
    }
    string3[j] = '\0';
}

void wordToString(Word currentWord, char *string)
{
    int i = 0;
    while (i < currentWord.Length)
    {
        string[i] = currentWord.TabWord[i];
        i++;
    }
    string[i] = '\0';
}

int wordToInteger(Word currentWord)
{
    int value = 0;
    int satuan = 1;
    int i = currentWord.Length - 1;
    while (i >= 0)
    {
        value += (currentWord.TabWord[i] - 48) * satuan;
        satuan *= 10;
        i--;
    }
    return value;
}

void inputString(int type, char* value)
{
    STARTWORD(NULL, type);
    wordToString(currentWord, value);
}

int random_number(int lowerlimit, int upperlimit){
    int number;
    number = (rand() % (upperlimit - lowerlimit + 1)) + lowerlimit;
    return number; 
}

char* food_id_generator(int id){
    int angka1 = id;
    int angka2 = id;
    int count = 0;
    while (angka1!=0){
        angka1/=10;
        count++;
    }
    char *food_id = malloc (sizeof(char) * count+2);
    int i;
    for (i=count;i>=0;i--){
        if(i==0){
            food_id[i] = 'M';
        }
        else{
            food_id[i] = (angka2 % 10)+'0';
            angka2 /= 10;
        }
    }
    food_id [count+1] = '\0'; 
    return food_id;
}

void STARTBNMO(ArrayDin *Games)
{
    LOADFILE(Games, "config");
}

void LOADFILE(ArrayDin *Games, char *inputfile)
{
    char placeholder[] = ".\\data\\";
    char directory[50];
    char txt[] = ".txt";
    char filename[25];

    concat(inputfile, txt, filename);
    concat(placeholder, filename, directory);

    char string[50];
    char *temp;
    int i;
    int amount;
    int arrayNumber = 0;

    START(directory);
    if (pita == NULL)
    {
        printf("File tidak dapat dibuka. Silahkan masukkan nama file lain.\n");
    }
    else
    {
        fclose(pita);
        STARTWORD(directory, 1);
        wordToString(currentWord, string);
        amount = atoi(string);
        ADVWORD(1);
        for (int j = 0; j < amount; j++)
        {
            wordToString(currentWord, string);
            temp = (char *) malloc (currentWord.Length * sizeof(char));
            i = 0;
            while (i <= currentWord.Length)
            {
                temp[i] = string[i];
                i++;
            }
            InsertLast(Games, temp);
            ADVWORD(1);
        }
        if (directory == "config.txt")
        {
            printf("File konfigurasi sistem berhasil dibaca. BNMO berhasil dijalankan.\n");
        }
        else
        {
            printf("File %s berhasil dibaca. BNMO berhasil dijalankan.\n", inputfile);
        }   
    }
}

void SAVE(ArrayDin *Games, char *inputfile)
{
    char placeholder[] = ".\\data\\";
    char directory[50];
    char txt[] = ".txt";
    char filename[25];

    concat(inputfile, txt, filename);
    concat(placeholder, filename, directory);

    FILE *open;
    open = fopen(directory, "w");

    fprintf(open, "%d\n", Games->Neff);
    for (int i = 0; i < Games->Neff; i++)
    {
        fprintf(open, "%s\n", Games->A[i]);
    }

    fprintf(open, ".");
    fclose(open);
    printf("Save file berhasil disimpan.\n");
}

void CREATEGAME (ArrayDin *arrayGames){
    char *gamesname;
    int i = 0;
    boolean found = false;

    /* Input game yang ingin ditambah */
    printf("Masukkan nama game yang akan ditambahkan: "); scanf("%[^\n]", &gamesname);
    
    /* Proses pencarian nama games yang diinput apakah sudah terdaftar sebelumnya */
    for (i; i < (*arrayGames).Neff; i++){
        if ((*arrayGames).A[i] == gamesname){
            found = true;
        }
    }
    if (found) /* Kondisi ketika game belum terdaftar */{
        InsertLast(arrayGames, gamesname);
        printf("Game berhasil ditambahkan");
    } else /* Kondisi ketika game seudah terdaftar */{
        printf("Game sudah terdaftar");
    }
}

void LISTGAME (ArrayDin arrayGames){
    int i = 0;
    printf("Berikut adalah daftar game yang tersedia");
    
    /* Menampilkan list game dari nomor 1 indeks ke-0 */
    for (i; i < arrayGames.Neff; i++){
        printf("%d. %s\n", i + 1, arrayGames.A[i]);
    }
}

void DELETEGAME (ArrayDin *arrayGames){
	int a, i;
	
	LISTGAME(*arrayGames);
	printf("Masukkan nomor game yang akan dihapus: ");
	scanf("%d", &a);
	
	if ((a>=1) && (a<=5)){
		printf("Game gagal dihapus \n");
	}
	else if (a>5){
		i = a-1;
		DeleteAt(arrayGames, i);
		printf("Game berhasil dihapus \n");
		}
		
	}

void QUEUEGAME(QueueOfString Queue, ArrayDin Games){
    int i, no;
    printf("Berikut adalah daftar antrian game-mu\n");
    // daftar antrian berjumlah >= 0
    if (!IsQueueOfStringEmpty(Queue)){
        i = Queue.HEAD;
        no = 1;
        while (i != Queue.TAIL)
        {
            printf("%d. %s\n",no,Queue.Tab[i]);
            i = (i+1) % Queue.MaxEl;
            no++;
        }
        printf("%d. %s\n",no,Queue.Tab[i]);
    }
    printf("\n");
    printf("Berikut adalah daftar game yang tersedia\n");
    // dalam file konfigurasi default sudah terdapat minimal 3 game, sehingga pemeriksaan berupa apakah Games kosong tidak perlu dilakukan
    int i;
    for (i=1;i<=Length(Games);i++){
        printf("%d. %s\n",i,Games.A[i-1]);
    }
    printf("\n");
    // baca input user
    int nomor_game;
    printf("Nomor game yang mau ditambahkan ke antrian: ");
    scanf("%d",&nomor_game);
    // validasi input
    if(nomor_game>=1 && nomor_game<=Length(Games)){
        PushString(&Queue,Games.A[nomor_game-1]);
        printf("Game berhasil ditambahkan ke dalam daftar antrian.\n");        
    }
    else{
        printf("Nomor permainan tidak valid, silahkan masukkan nomor game pada list.\n");
    }
    
}


void RNG(){
	
	int jumlah, angka, tebak, skor;
    srand(time(NULL));
    angka = rand()% 100 + 1;
    jumlah = 0;
    
    /* printf("%d", angka); */


    printf("RNG Telah dimulai. Uji keberuntungan Anda dengan menebak X.\n");
    printf("Tebakan: ");
    scanf("%d", &tebak);

    if (tebak == angka){
        printf("Ya, X adalah %d", angka);
    
    } else if (tebak != angka){
        while (tebak != angka){
            jumlah += 1;
            if (tebak > angka){
                printf("Lebih kecil\n");
            } else if (tebak < angka){
                printf("Lebih besar\n");
            }
            printf("Tebakan: ");
            scanf("%d", &tebak);
        }
        if (tebak == angka){
            printf("Ya, X adalah %d \n", angka);
    }
    
} skor = (25-jumlah)*4;
    printf("Skor = %d", skor); 

}

void DINERDASH(){
    int i;
    int saldo = 0;
    int served_customer = 0;
    QueueOfPesanan pesanan;
    processedorder oncook;
    processedorder readytoserve;
    pesanan = CreateQueueOfPesanan(10);
    oncook = MakeProcessedOrder(5);
    readytoserve = MakeProcessedOrder(InitialSize);
    PushPesanan(&pesanan,CreatePesanan(food_id_generator(1),random_number(1,5),random_number(1,5),random_number(10000,50000)));
    PushPesanan(&pesanan,CreatePesanan(food_id_generator(2),random_number(1,5),random_number(1,5),random_number(10000,50000)));
    PushPesanan(&pesanan,CreatePesanan(food_id_generator(3),random_number(1,5),random_number(1,5),random_number(10000,50000)));
    printf("Selamat datang di Diner Dash!\n\n");
    printf("SALDO: %d\n\n",saldo);
    printf("Daftar Pesanan\n");
    printf("Makanan | Durasi Memasak | Ketahanan | Harga\n");
    printf("----------------------------------------------\n");
    i = pesanan.HEAD;
    while(i!=(pesanan.TAIL+1)%pesanan.MaxEl){
        if(strlen(pesanan.Tab[i].makanan)==2){
            printf("%s      | %d              | %d         | %d\n",pesanan.Tab[i].makanan,pesanan.Tab[i].durasimasak,pesanan.Tab[i].ketahanan,pesanan.Tab[i].harga);
        }
        else{
            printf("%s     | %d              | %d         | %d\n",pesanan.Tab[i].makanan,pesanan.Tab[i].durasimasak,pesanan.Tab[i].ketahanan,pesanan.Tab[i].harga);
        }
        i = (i+1)%pesanan.MaxEl;
    }
    printf("\n");
    printf("Daftar Makanan yang sedang dimasak\n");
    printf("Makanan | Sisa durasi memasak\n");
    printf("--------------------------------\n");
    if(!IsProcessedOrderEmpty(oncook)){
        for(i=1;i<=LengthOfProcessedOrder(oncook);i++){
            if(strlen(oncook.A[i-1].makanan) == 2){
                printf("%s      | %d\n",oncook.A[i-1].makanan,oncook.A[i-1].sisa_durasi_or_ketahanan_masakan);
            }
            else{
                printf("%s     | %d\n",oncook.A[i-1].makanan,oncook.A[i-1].sisa_durasi_or_ketahanan_masakan);
            }
        }
        
    }
    else{
        printf("        |  \n");
    }
    printf("\n");
    printf("Daftar Makanan yang siap disajikan\n");
    printf("Makanan | Sisa Ketahanan Makanan\n");
    printf("-----------------------------------\n");
    if(!IsProcessedOrderEmpty(readytoserve)){
        for(i=1;i<=LengthOfProcessedOrder(readytoserve);i++){
            if(strlen(readytoserve.A[i-1].makanan) == 2){
                printf("%s      | %d\n",readytoserve.A[i-1].makanan,readytoserve.A[i-1].sisa_durasi_or_ketahanan_masakan);
            }
            else{
                printf("%s     | %d\n",readytoserve.A[i-1].makanan,readytoserve.A[i-1].sisa_durasi_or_ketahanan_masakan);
            }
        }
    }
    else{
        printf("        |  \n");
    }
    printf("\n\n");
    boolean endGame = false;
    char* command;
    char* attribut;
    attribut = (char*) malloc(99*sizeof(char));
    command = (char*) malloc(99*sizeof(char));
    printf("MASUKKAN COMMAND: ");
    scanf("%s %s",command,attribut);
    printf("\n");
    while(!endGame){
        if(compareString(command,"COOK")==1){
            boolean found = false;
            i = pesanan.HEAD;
            while (i!=(pesanan.TAIL+1)%pesanan.MaxEl && found == false){
                if(compareString(pesanan.Tab[i].makanan, attribut)==1){
                    found = true;
                }
                i = (i+1)%pesanan.MaxEl;
            }
            
            if(found){
                if(LengthOfProcessedOrder(oncook)<GetProcessedOrderCapacity(oncook)){
                    int idx = (i-1) % pesanan.MaxEl;
                    
                    printf("Berhasil memasak %s\n",attribut);
                    PushPesanan(&pesanan,CreatePesanan(food_id_generator(LengthQueueOfPesanan(pesanan)+served_customer+1),random_number(1,5),random_number(1,5),random_number(10000,50000)));
                    
                    if (!IsProcessedOrderEmpty(oncook)){
                        for(i=0;i<LengthOfProcessedOrder(oncook);i++){
                            oncook.A[i].sisa_durasi_or_ketahanan_masakan-=1;
                        }
                    }
                    if(!IsProcessedOrderEmpty(readytoserve)){
                        for(i=0;i<LengthOfProcessedOrder(readytoserve);i++){
                            readytoserve.A[i].sisa_durasi_or_ketahanan_masakan-=1;
                            if(readytoserve.A[i].sisa_durasi_or_ketahanan_masakan == 0){
                                DeleteProcessedOrderAt(&readytoserve, i);
                            }
                        }
                    }
                    for(i=0;i<LengthOfProcessedOrder(oncook);i++){
                        if(oncook.A[i].sisa_durasi_or_ketahanan_masakan == 0){
                            printf("Makanan %s telah selesai dimasak\n",oncook.A[i].makanan);
                            int j = pesanan.HEAD;
                            while(compareString(pesanan.Tab[j].makanan, oncook.A[i].makanan)!=1){
                                j = (j+1) % pesanan.MaxEl;
                            }
                            InsertProcessedOrderLast(&readytoserve,MakeMasakan(pesanan.Tab[j].makanan, pesanan.Tab[j].ketahanan));
                            DeleteProcessedOrderAt(&oncook, i);
                        }
                    }
                    
                    InsertProcessedOrderLast(&oncook, MakeMasakan(pesanan.Tab[idx].makanan,pesanan.Tab[idx].durasimasak));
                    
                    printf("========================================================\n\n");
                    printf("SALDO: %d\n\n",saldo);
                    printf("Daftar Pesanan\n");
                    printf("Makanan | Durasi Memasak | Ketahanan | Harga\n");
                    printf("----------------------------------------------\n");
                    //pesanan tidak mungkin kosong
                    i = pesanan.HEAD;
                    while(i!=pesanan.TAIL){
                        if(strlen(pesanan.Tab[i].makanan)==2){
                            printf("%s      | %d              | %d         | %d\n",pesanan.Tab[i].makanan,pesanan.Tab[i].durasimasak,pesanan.Tab[i].ketahanan,pesanan.Tab[i].harga);
                        }
                        else{
                            printf("%s     | %d              | %d         | %d\n",pesanan.Tab[i].makanan,pesanan.Tab[i].durasimasak,pesanan.Tab[i].ketahanan,pesanan.Tab[i].harga);
                        }
                        i = (i+1)%pesanan.MaxEl;
                    }
                    if(strlen(pesanan.Tab[i].makanan)==2){
                        printf("%s      | %d              | %d         | %d\n",pesanan.Tab[i].makanan,pesanan.Tab[i].durasimasak,pesanan.Tab[i].ketahanan,pesanan.Tab[i].harga);
                    }
                    else{
                        printf("%s     | %d              | %d         | %d\n",pesanan.Tab[i].makanan,pesanan.Tab[i].durasimasak,pesanan.Tab[i].ketahanan,pesanan.Tab[i].harga);
                    }
                    printf("\n");
                    printf("Daftar Makanan yang sedang dimasak\n");
                    printf("Makanan | Sisa durasi memasak\n");
                    printf("--------------------------------\n");
                    if(!IsProcessedOrderEmpty(oncook)){
                        for(i=0;i<LengthOfProcessedOrder(oncook);i++){
                            if(strlen(oncook.A[i].makanan) == 2){
                                printf("%s      | %d\n",oncook.A[i].makanan,oncook.A[i].sisa_durasi_or_ketahanan_masakan);
                            }
                            else{
                                printf("%s     | %d\n",oncook.A[i].makanan,oncook.A[i].sisa_durasi_or_ketahanan_masakan);
                            }
                        }
                        
                    }
                    else{
                        printf("        |  \n");
                    }
                    printf("\n");
                    printf("Daftar Makanan yang siap disajikan\n");
                    printf("Makanan | Sisa Ketahanan Makanan\n");
                    printf("-----------------------------------\n");
                    if(!IsProcessedOrderEmpty(readytoserve)){
                        for(i=0;i<LengthOfProcessedOrder(readytoserve);i++){
                            if(strlen(readytoserve.A[i].makanan) == 2){
                                printf("%s      | %d\n",readytoserve.A[i].makanan,readytoserve.A[i].sisa_durasi_or_ketahanan_masakan);
                            }
                            else{
                                printf("%s     | %d\n",readytoserve.A[i].makanan,readytoserve.A[i].sisa_durasi_or_ketahanan_masakan);
                            }
                        }
                    }
                    else{
                        printf("        |  \n");
                    }
                    printf("\n\n");
                }
                else{
                    printf("Maaf kapasitas maksimum memasak telah dicapai. Silakan tunggu hingga terdapat makanan yang selesai dimasak!\n\n");
                }
            }
            else{
                printf("Maaf pesanan yang ingin dimasak tidak ditemukan\n\n");
            }
        
        }
        else if(compareString(command,"SERVE") == 1){
            if(compareString(attribut,pesanan.Tab[pesanan.HEAD].makanan) == 1){
                boolean found = false;
                i = 0;
                while (i<readytoserve.Neff && found == false){
                    if(compareString(readytoserve.A[i].makanan, attribut) == 1){
                        found = true;
                    }
                    i++;
                }
                if (found){
                    masakan m = MakeMasakan(pesanan.Tab[pesanan.HEAD].makanan,pesanan.Tab[pesanan.HEAD].ketahanan);
                    saldo += pesanan.Tab[pesanan.HEAD].harga;
                    PopPesanan(&pesanan);
                    DeleteProcessedOrderAt(&readytoserve,SearchMasakan(readytoserve,m));
                    served_customer+=1;
                    printf("Berhasil mengantar %s\n",attribut);
                    PushPesanan(&pesanan,CreatePesanan(food_id_generator(LengthQueueOfPesanan(pesanan)+served_customer+1),random_number(1,5),random_number(1,5),random_number(10000,50000)));
                    if (!IsProcessedOrderEmpty(oncook)){
                        for(i=0;i<LengthOfProcessedOrder(oncook);i++){
                            oncook.A[i].sisa_durasi_or_ketahanan_masakan-=1;
                        }
                    }
                    if(!IsProcessedOrderEmpty(readytoserve)){
                        for(i=0;i<LengthOfProcessedOrder(readytoserve);i++){
                            readytoserve.A[i].sisa_durasi_or_ketahanan_masakan-=1;
                            if(readytoserve.A[i].sisa_durasi_or_ketahanan_masakan == 0){
                                DeleteProcessedOrderAt(&readytoserve, i);
                            }
                        }
                    }
                    for(i=0;i<LengthOfProcessedOrder(oncook);i++){
                        if(oncook.A[i].sisa_durasi_or_ketahanan_masakan == 0){
                            printf("Makanan %s telah selesai dimasak\n",oncook.A[i].makanan);
                            int j = pesanan.HEAD;
                            while(compareString(pesanan.Tab[j].makanan, oncook.A[i].makanan)!=1){
                                j = (j+1) % pesanan.MaxEl;
                            }
                            InsertProcessedOrderLast(&readytoserve,MakeMasakan(pesanan.Tab[j].makanan, pesanan.Tab[j].ketahanan));
                            DeleteProcessedOrderAt(&oncook, i);
                        }
                    }
                    
                    printf("========================================================\n\n");
                    printf("SALDO: %d\n\n",saldo);
                    printf("Daftar Pesanan\n");
                    printf("Makanan | Durasi Memasak | Ketahanan | Harga\n");
                    printf("----------------------------------------------\n");
                    // pesanan tidak mungkin kosong
                    i = pesanan.HEAD;
                    while(i!=pesanan.TAIL){
                        if(strlen(pesanan.Tab[i].makanan)==2){
                            printf("%s      | %d              | %d         | %d\n",pesanan.Tab[i].makanan,pesanan.Tab[i].durasimasak,pesanan.Tab[i].ketahanan,pesanan.Tab[i].harga);
                        }
                        else{
                            printf("%s     | %d              | %d         | %d\n",pesanan.Tab[i].makanan,pesanan.Tab[i].durasimasak,pesanan.Tab[i].ketahanan,pesanan.Tab[i].harga);
                        }
                        i = (i+1)%pesanan.MaxEl;
                    }
                    if(strlen(pesanan.Tab[i].makanan)==2){
                        printf("%s      | %d              | %d         | %d\n",pesanan.Tab[i].makanan,pesanan.Tab[i].durasimasak,pesanan.Tab[i].ketahanan,pesanan.Tab[i].harga);
                    }
                    else{
                        printf("%s     | %d              | %d         | %d\n",pesanan.Tab[i].makanan,pesanan.Tab[i].durasimasak,pesanan.Tab[i].ketahanan,pesanan.Tab[i].harga);
                    }
                    printf("\n");
                    printf("Daftar Makanan yang sedang dimasak\n");
                    printf("Makanan | Sisa durasi memasak\n");
                    printf("--------------------------------\n");
                    if(!IsProcessedOrderEmpty(oncook)){
                        for(i=0;i<LengthOfProcessedOrder(oncook);i++){
                            if(strlen(oncook.A[i].makanan) == 2){
                                printf("%s      | %d\n",oncook.A[i].makanan,oncook.A[i].sisa_durasi_or_ketahanan_masakan);
                            }
                            else{
                                printf("%s     | %d\n",oncook.A[i].makanan,oncook.A[i].sisa_durasi_or_ketahanan_masakan);
                            }
                        }
                        
                    }
                    else{
                        printf("        |  \n");
                    }
                    printf("\n");
                    printf("Daftar Makanan yang siap disajikan\n");
                    printf("Makanan | Sisa Ketahanan Makanan\n");
                    printf("-----------------------------------\n");
                    if(!IsProcessedOrderEmpty(readytoserve)){
                        for(i=0;i<LengthOfProcessedOrder(readytoserve);i++){
                            if(strlen(readytoserve.A[i].makanan) == 2){
                                printf("%s      | %d\n",readytoserve.A[i].makanan,readytoserve.A[i].sisa_durasi_or_ketahanan_masakan);
                            }
                            else{
                                printf("%s     | %d\n",readytoserve.A[i].makanan,readytoserve.A[i].sisa_durasi_or_ketahanan_masakan);
                            }
                        }
                    }
                    else{
                        printf("        |  \n");
                    }
                    printf("\n\n");
                }
                else{
                    printf("Maaf pesanan yang ingin disajikan tidak ditemukan\n\n");
                }

            }
            else{
                printf("%s belum dapat disajikan karena %s belum selesai\n\n",attribut,pesanan.Tab[pesanan.HEAD].makanan);
            }
        }

        if(LengthQueueOfPesanan(pesanan)>7 || served_customer == 15){
            endGame = true;
        }
        else{
            free(command);
            free(attribut);
            attribut = (char*) malloc(99*sizeof(char));
            command = (char*) malloc(99*sizeof(char));
            printf("MASUKKAN COMMAND: ");
            scanf("%s %s",command,attribut);
            printf("\n");
        }
    }
    printf("Skor akhir: %d\n",saldo);
}
