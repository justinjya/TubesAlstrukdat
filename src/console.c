#include "console.h"
#include "./ADT/scoreboard/map.c"
#include "./ADT/arraydin/arraydin.c"
#include "./ADT/scoreboard/arraydin_sb.c"
#include "./ADT/mesinkarakterv2/mesinkarakterv2.c"
#include "./ADT/mesinkata/mesinkata.c"
#include "./ADT/queue/queue.c"
#include "./ADT/dinerdash/processedorder.c"
#include "./ADT/dinerdash/circular_queue_of_pesanan.c"
#include "./ADT/snakemeteor/listlinier.c"
#include "./ADT/snakemeteor/point.c"


boolean compareString(char *string1, char *string2)
{
    while (*string1 != '\0' || *string2 != '\0')
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

void addspace(char *string, int space) {
    int i;
    int length = stringlen(string);
    int temp = length;
    while (length < temp + space)
    {
        string[length] = ' ';
        length+=1;
    }
    string[length] = '\0';
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

void inputInteger(int *value)
{
    STARTWORD(NULL, 1);
    *value = wordToInteger(currentWord); 
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
        amount = wordToInteger(currentWord);
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

void CREATEGAME(ArrayDin *arrayGames,ArrayDin_SB scoreboard){
    char *gamesname;
    gamesname = (char *) malloc (50 * sizeof(char));
    int i = 0;
    boolean found = false;

    /* Input game yang ingin ditambah */
    LISTGAME(arrayGames);
    printf("\nMasukkan nama game yang akan ditambahkan: ");
    inputString(1 , gamesname);
    
    /* Proses pencarian nama games yang diinput apakah sudah terdaftar sebelumnya */
    for (i; i < (*arrayGames).Neff; i++){
        if (compareString((*arrayGames).A[i], gamesname) == 1){
            found = true;
        }
    }
    if (found == false) /* Kondisi ketika game belum terdaftar */{
        InsertLast(arrayGames, gamesname);
        printf("Game berhasil ditambahkan.\n");
        Map M;
        CreateEmpty_M(&M);
        InsertLast_SB(&scoreboard,M);
    } else /* Kondisi ketika game seudah terdaftar */{
        printf("Game sudah terdaftar. Silahkan masukkan nama game lain.\n");
    }
}

void LISTGAME(ArrayDin *arrayGames){
    int i = 0;
    printf("Berikut adalah daftar game yang tersedia:\n");
    
    /* Menampilkan list game dari nomor 1 indeks ke-0 */
    for (i; i < arrayGames->Neff; i++){
        printf("%d. %s\n", i + 1, arrayGames->A[i]);
    }
}

void DELETEGAME(ArrayDin *arrayGames, Queue *queueGames){
	char *input;
    int i, a;
    boolean found;
    found = false;
	input = (char *) malloc (5 * sizeof(char));

	LISTGAME(arrayGames);
	printf("\nMasukkan nomor game yang akan dihapus: ");
	inputInteger(&a);
	
	if ((a>=1) && (a<=5)){
		printf("Game gagal dihapus.\n");
	}
	else if (a>5){
		i = a-1;
        for (int j = 0; j <= IDX_TAIL(*queueGames); j++) {
            if (arrayGames->A[i] == queueGames->buffer[j]) {
                found = true;
            }
        }
        if (found == false) {
            DeleteAt(arrayGames, i);
            printf("Game berhasil dihapus.\n");
        }
        else {
            printf("Game gagal dihapus.\n");
        }
	}
}

void QUEUEGAME(ArrayDin *Games, Queue *Queue){
    int i, no;
    printf("Berikut adalah daftar antrean game-mu:\n");

    // daftar antrean berjumlah >= 0
    if (!isEmpty(*Queue)){
        i = IDX_HEAD(*Queue);
        no = 1;
        while (i != IDX_TAIL(*Queue))
        {
            printf("%d. %s\n", no, Queue->buffer[i]);
            i = (i+1) % CAPACITY;
            no++;
        }
        printf("%d. %s\n", no, Queue->buffer[i]);
    }

    printf("\n");
    printf("Berikut adalah daftar game yang tersedia:\n");
    // dalam file konfigurasi default sudah terdapat minimal 3 game, sehingga pemeriksaan berupa apakah Games kosong tidak perlu dilakukan
    for (i=1;i<=Length(*Games);i++){
        printf("%d. %s\n", i, Games->A[i-1]);
    }
    printf("\n");

    // baca input user
    int nomor_game;
    printf("Nomor game yang mau ditambahkan ke antrean: ");
    inputInteger(&nomor_game);

    // validasi input
    if (nomor_game>=1 && nomor_game<=Length(*Games)){
        enqueue(Queue, Games->A[nomor_game-1]);
        printf("Game berhasil ditambahkan ke dalam daftar antrean.\n");        
    }
    else{
        printf("Nomor permainan tidak valid, silahkan masukkan nomor game pada list.\n");
    }
}

void PLAYGAME(ArrayDin *arraygame, Queue *queuegame)
{
    if (isEmpty(*queuegame))
    {
        printf("Belum ada antrean game yang kamu miliki.\n");
    }

    else
    {
        IdxType index;
        ElType val;
        index = SearchArrayDin(*arraygame, HEAD(*queuegame));
        if (index < 5)
        {
            if (compareString(HEAD(*queuegame), "RNG") == true)
            {
                printf("Loading %s ...\n", HEAD(*queuegame));
                RNG();
            }

            else if (compareString(HEAD(*queuegame), "Diner Dash") == true)
            {
                printf("Loading %s ...\n", HEAD(*queuegame));
                DINERDASH();
            }

            else
            {
                printf("Game %s masih dalam maintenance, belum dapat dimainkan. Silahkan pilih game lain.\n", HEAD(*queuegame));
            }

        }
        else
        {
            printf("Loading %s ...\n", HEAD(*queuegame));
            GAMEBUATAN();
        }
        dequeue(queuegame, &val);
    }
}

void SKIPGAME(ArrayDin *arraygames, Queue *queuegame, int skips)
{
    printf("Berikut adalah daftar game-mu:\n");
    if (!isEmpty(*queuegame))
    {
        int k = 1;
        for (IdxType i = IDX_HEAD(*queuegame); i <= IDX_TAIL(*queuegame); i++)
        {
            printf("%d. %s\n", k, queuegame->buffer[i]);
            k++;
        }
    }
	
    else
    {
        printf("\nTidak ada permainan lagi dalam daftar game-mu.\n");
    }

    if (!isEmpty(*queuegame))
    {
        ElType val;
        for (IdxType i = 0; i < skips; i++)
        {
            if (!isEmpty(*queuegame))
            {
                dequeue(queuegame, &val);
            }
        }

        if (!isEmpty(*queuegame))
        {
            printf("\n");
            PLAYGAME(arraygames, queuegame);
        }
	    
        else
        {
            printf("\nTidak ada permainan lagi dalam daftar game-mu.\n");
        }
    }
}

void QUIT(ArrayDin *Games, Queue *GamesQueue){
    DeallocateArrayDin(Games);
    ElType val;
    while (!isEmpty(*GamesQueue)){
        dequeue(GamesQueue, &val);
    }
    printf("Anda keluar dari game BNMO.\nBye bye ...\n\n");
}

void HELP(int type){
    if (type == 0){
        printf("DAFTAR COMMANDS:\n");
        printf("  1. START - Menjalankan file configurasi default\n");
        printf("  2. LOAD <filename tanpa .txt> - Menjalankan file dari input user\n");
        printf("  3. QUIT - Keluar dari program\n");
        printf("  4. HELP - Menampilkan daftar command yang dapat dijalankan\n");
    }
    else{
        printf("DAFTAR COMMANDS:\n");
        printf("  1. SAVE <filename tanpa .txt> - Menyimpan state sistem ke dalam file dari input user\n");
        printf("  2. CREATE GAME - Membuat game baru dari input user\n");
        printf("  3. LIST GAME - Menampilkan daftar game yang dapat tersedia dalam sistem\n");
        printf("  4. DELETE GAME - Menghapus game yang tersedia dari sistem\n");
        printf("  5. QUEUE GAME - Menambahkan game ke dalam antrean game\n");
        printf("  6. PLAY GAME - Memainkan game yang berada di depan antrean\n");
        printf("  7. SKIP GAME <n> - Melewati game yang berada di dalam antrean sebanyak n kali\n");
        printf("  8. QUIT - Keluar dari program\n");
        printf("  9. HELP - Menampilkan daftar command yang dapat dijalankan\n");
    }
}

void RNG(){
	int jumlah, angka, tebak, skor;
    boolean nyerah;
    angka = rand()% 100 + 1;
    jumlah = 0;
    nyerah = false;

    printf("RNG Telah dimulai. Uji keberuntungan Anda dengan menebak X.\n");
    printf("Masukkan 0 jika ingin menyerah.\n");
    printf("Tebakan: ");
    inputInteger(&tebak);

    if (tebak == 0) {
        nyerah = true;
        jumlah = 25;
        printf("\n");
        printf("Anda kurang beruntung, X adalah %d \n", angka);
    } else if (tebak == angka){
        printf("\n");
        printf("Ya, X adalah %d", angka);
    } else if (tebak != angka && nyerah == false){
        while (tebak != angka && nyerah == false){
            jumlah += 1;
            if (tebak > angka){
                printf("Lebih kecil\n");
            } else if (tebak < angka){
                printf("Lebih besar\n");
            }
            printf("Tebakan: ");
            inputInteger(&tebak);
            if (tebak == 0) {
                nyerah = true;
                jumlah = 25;
            }
        }
        if (nyerah == true){
            printf("\n");
            printf("Anda kurang beruntung, X adalah %d \n", angka);
        } else if (tebak == angka && nyerah == false){
            printf("\n");
            printf("Ya, X adalah %d \n", angka);
        }
    } skor = (25-jumlah)*4;
    printf("Skor = %d\n", skor); 
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
    PushPesanan(&pesanan,CreatePesanan("M0",random_number(1,3),random_number(2,5),random_number(10,50) * 1000));
    PushPesanan(&pesanan,CreatePesanan("M1",random_number(1,3),random_number(2,5),random_number(10,50) * 1000));
    PushPesanan(&pesanan,CreatePesanan("M2",random_number(1,3),random_number(2,5),random_number(10,50) * 1000));
    printf("Selamat datang di Diner Dash!\n\n");
    boolean endGame = false;
    
    while(!endGame){
        printf("========================================================\n\n");
        printf("SALDO: %d\n\n",saldo);
        PrintUIPesanan(pesanan);
        PrintUIOnCook(oncook);
        PrintUIReadyToServe(readytoserve);
        printf("\n");
        printf("MASUKKAN COMMAND: ");
        STARTWORD(NULL,0);
        printf("\n");
        if(compareString(getCurrentWord(currentWord),"COOK") == true || compareString(getCurrentWord(currentWord),"SERVE") == true || compareString(getCurrentWord(currentWord),"SKIP") == true || compareString(getCurrentWord(currentWord),"QUIT") == true){
            if(compareString(getCurrentWord(currentWord),"COOK")==true){
                ADVWORD(0);
                if(currentChar == '\n'){
                    boolean found = false;
                    i = pesanan.HEAD;
                    while (i!=(pesanan.TAIL+1)%pesanan.MaxEl && found == false){
                        if(compareString(pesanan.Tab[i].makanan, getCurrentWord(currentWord))==true){
                            found = true;
                        }
                        i = (i+1)%pesanan.MaxEl;
                    }
                    
                    if(found){
                        if(LengthOfProcessedOrder(oncook)<GetProcessedOrderCapacity(oncook)){
                            int idx = (i-1) % pesanan.MaxEl;
                            printf("Berhasil memasak %s\n",pesanan.Tab[idx].makanan);/*currentWord.TabWord*/
                            PushPesanan(&pesanan,CreatePesanan(food_id_generator(LengthQueueOfPesanan(pesanan)+served_customer),random_number(1,5),random_number(1,5),random_number(10,50) * 1000));
                            
                            if (!IsProcessedOrderEmpty(oncook)){
                                for(i=0;i<LengthOfProcessedOrder(oncook);i++){
                                    oncook.A[i].sisa_durasi_or_ketahanan_masakan-=1;
                                }
                            }
                            int panjang = LengthOfProcessedOrder(readytoserve);
                            if(!IsProcessedOrderEmpty(readytoserve)){
                                for(i=0;i<panjang;i++){
                                    readytoserve.A[i].sisa_durasi_or_ketahanan_masakan-=1;
                                    if(readytoserve.A[i].sisa_durasi_or_ketahanan_masakan == 0){
                                        DeleteProcessedOrderAt(&readytoserve, i);
                                        i--;
                                        panjang--;
                                    }
                                }
                            }
                            panjang = LengthOfProcessedOrder(oncook);
                            for(i=0;i<panjang;i++){
                                if(oncook.A[i].sisa_durasi_or_ketahanan_masakan == 0){
                                    printf("Makanan %s telah selesai dimasak\n",oncook.A[i].makanan);
                                    int j = pesanan.HEAD;
                                    while(compareString(pesanan.Tab[j].makanan, oncook.A[i].makanan)!=true){
                                        j = (j+1) % pesanan.MaxEl;
                                    }
                                    InsertProcessedOrderLast(&readytoserve,MakeMasakan(pesanan.Tab[j].makanan, pesanan.Tab[j].ketahanan));
                                    DeleteProcessedOrderAt(&oncook, i);
                                    i--;
                                    panjang--;
                                }
                            }
                            
                            InsertProcessedOrderLast(&oncook, MakeMasakan(pesanan.Tab[idx].makanan,pesanan.Tab[idx].durasimasak));
                        }
                        else{
                            printf("Maaf kapasitas maksimum memasak telah dicapai. Silakan tunggu hingga terdapat makanan yang selesai dimasak!\n\n");
                        }
                    }
                    else{
                        printf("Maaf pesanan yang ingin dimasak tidak ditemukan\n\n");
                    }
                }
                else{
                    printf("Masukkan kembali command!\n\n");
                    while(!EndWord){
                        ADVWORD(0);
                    }
                }
            
            }
            else if(compareString(getCurrentWord(currentWord),"SERVE") == true){
                ADVWORD(0);
                if(currentChar == '\n'){
                    boolean found = false;
                    i = 0;
                    while (i<readytoserve.Neff && found == false){
                        if(compareString(readytoserve.A[i].makanan, getCurrentWord(currentWord)) == true){
                            found = true;
                        }
                        i++;
                    }
                    if(found){       
                        if (compareString(getCurrentWord(currentWord),pesanan.Tab[pesanan.HEAD].makanan) == true){
                            masakan m = MakeMasakan(pesanan.Tab[pesanan.HEAD].makanan,pesanan.Tab[pesanan.HEAD].ketahanan);
                            saldo += pesanan.Tab[pesanan.HEAD].harga;
                            printf("Berhasil mengantar %s\n",pesanan.Tab[pesanan.HEAD].makanan);
                            PopPesanan(&pesanan);
                            DeleteProcessedOrderAt(&readytoserve,SearchMasakan(readytoserve,m));
                            served_customer+=1;
                            
                            PushPesanan(&pesanan,CreatePesanan(food_id_generator(LengthQueueOfPesanan(pesanan)+served_customer),random_number(1,5),random_number(1,5),random_number(10,50) * 1000));
                            if (!IsProcessedOrderEmpty(oncook)){
                                for(i=0;i<LengthOfProcessedOrder(oncook);i++){
                                    oncook.A[i].sisa_durasi_or_ketahanan_masakan-=1;
                                }
                            }
                            int panjang = LengthOfProcessedOrder(readytoserve);
                            if(!IsProcessedOrderEmpty(readytoserve)){
                                for(i=0;i<panjang;i++){
                                    readytoserve.A[i].sisa_durasi_or_ketahanan_masakan-=1;
                                    if(readytoserve.A[i].sisa_durasi_or_ketahanan_masakan == 0){
                                        DeleteProcessedOrderAt(&readytoserve, i);
                                        i--;
                                        panjang--;
                                    }
                                }
                            }
                            panjang = LengthOfProcessedOrder(oncook);
                            for(i=0;i<panjang;i++){
                                if(oncook.A[i].sisa_durasi_or_ketahanan_masakan == 0){
                                    printf("Makanan %s telah selesai dimasak\n",oncook.A[i].makanan);
                                    int j = pesanan.HEAD;
                                    while(compareString(pesanan.Tab[j].makanan, oncook.A[i].makanan)!=true){
                                        j = (j+1) % pesanan.MaxEl;
                                    }
                                    InsertProcessedOrderLast(&readytoserve,MakeMasakan(pesanan.Tab[j].makanan, pesanan.Tab[j].ketahanan));
                                    DeleteProcessedOrderAt(&oncook, i);
                                    i--;
                                    panjang--;
                                }
                            }
                        }
                        else{
                            printf("%s belum dapat disajikan karena %s belum selesai\n\n",getCurrentWord(currentWord),pesanan.Tab[pesanan.HEAD].makanan);
                        }

                    }
                    else{
                        printf("Maaf pesanan yang ingin disajikan tidak ditemukan\n\n");
                    }
                }
                else{
                    printf("Masukkan kembali command!\n\n");
                    while (!EndWord)
                    {
                        ADVWORD(0);
                    }
                    
                }
            }
            else if(compareString(getCurrentWord(currentWord),"SKIP") == true){
                IgnoreBlanks();
                if(currentChar == '\n'){
                    PushPesanan(&pesanan,CreatePesanan(food_id_generator(LengthQueueOfPesanan(pesanan)+served_customer),random_number(1,5),random_number(1,5),random_number(10,50) * 1000));        
                    if (!IsProcessedOrderEmpty(oncook)){
                        for(i=0;i<LengthOfProcessedOrder(oncook);i++){
                            oncook.A[i].sisa_durasi_or_ketahanan_masakan-=1;
                        }
                    }
                    int panjang = LengthOfProcessedOrder(readytoserve);
                    if(!IsProcessedOrderEmpty(readytoserve)){
                        for(i=0;i<panjang;i++){
                            readytoserve.A[i].sisa_durasi_or_ketahanan_masakan-=1;
                            if(readytoserve.A[i].sisa_durasi_or_ketahanan_masakan == 0){
                                DeleteProcessedOrderAt(&readytoserve, i);
                                i--;
                                panjang--;
                            }
                        }
                    }
                    panjang = LengthOfProcessedOrder(oncook);
                    for(i=0;i<panjang;i++){
                        if(oncook.A[i].sisa_durasi_or_ketahanan_masakan == 0){
                            printf("Makanan %s telah selesai dimasak\n",oncook.A[i].makanan);
                            int j = pesanan.HEAD;
                            while(compareString(pesanan.Tab[j].makanan, oncook.A[i].makanan)!=true){
                                j = (j+1) % pesanan.MaxEl;
                            }
                            InsertProcessedOrderLast(&readytoserve,MakeMasakan(pesanan.Tab[j].makanan, pesanan.Tab[j].ketahanan));
                            DeleteProcessedOrderAt(&oncook, i);
                            i--;
                            panjang--;
                        }
                    }
                }
                else{
                    printf("Masukkan kembali command!\n\n");
                    while (!EndWord)
                    {
                        ADVWORD(0);
                    }
                    
                }
            }
            else if(compareString(getCurrentWord(currentWord),"QUIT") == true){
                    endGame = true;
            }

            if(LengthQueueOfPesanan(pesanan)>7 || served_customer == 15){
                endGame = true;
            }
        }
        else{
            printf("Masukkan kembali command!\n\n");
            while (!EndWord){
                ADVWORD(0);
            }
        }
    }
    printf("Skor akhir: %d\n",saldo);
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

char* getCurrentWord(Word string){
    char* string1 = malloc ((string.Length)*sizeof(char));
    int i;
    for(i=0;i<string.Length;i++){
        string1[i]=string.TabWord[i];
    }
    string1[i] = '\0';
    return string1;
}

void PrintUIPesanan(QueueOfPesanan pesanan){
    printf("Daftar Pesanan\n");
    printf("Makanan | Durasi Memasak | Ketahanan | Harga\n");
    printf("----------------------------------------------\n");
    int i;
    i = pesanan.HEAD;
    while(i!=(pesanan.TAIL+1)%pesanan.MaxEl){
        if(stringlen(pesanan.Tab[i].makanan)==2){
            printf("%s      | %d              | %d         | %d\n",pesanan.Tab[i].makanan,pesanan.Tab[i].durasimasak,pesanan.Tab[i].ketahanan,pesanan.Tab[i].harga);
        }
        else{
            printf("%s     | %d              | %d         | %d\n",pesanan.Tab[i].makanan,pesanan.Tab[i].durasimasak,pesanan.Tab[i].ketahanan,pesanan.Tab[i].harga);
        }
        i = (i+1)%pesanan.MaxEl;
    }
    printf("\n");
}

void PrintUIOnCook(processedorder oncook){
    printf("Daftar Makanan yang sedang dimasak\n");
    printf("Makanan | Sisa durasi memasak\n");
    printf("--------------------------------\n");
    int i;
    if(!IsProcessedOrderEmpty(oncook)){
        for(i=1;i<=LengthOfProcessedOrder(oncook);i++){
            if(stringlen(oncook.A[i-1].makanan) == 2){
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
}

void PrintUIReadyToServe(processedorder readytoserve){
    printf("Daftar Makanan yang siap disajikan\n");
    printf("Makanan | Sisa Ketahanan Makanan\n");
    printf("-----------------------------------\n");
    int i;
    if(!IsProcessedOrderEmpty(readytoserve)){
        for(i=1;i<=LengthOfProcessedOrder(readytoserve);i++){
            if(stringlen(readytoserve.A[i-1].makanan) == 2){
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
    printf("\n");
}

int stringlen(char* string){
    int i = 0;
    int count = 0;
    while(string[i]!='\0'){
        count++;
        i++;
    }
    return count;
}

void GAMEBUATAN()
{
    char *rand;
    int score;
    rand = (char *) malloc (1 * sizeof(char));
    score = (int) rand % 100;
    printf("Skor = %d\n", score);
}

void SCOREBOARD(ArrayDin_SB Scoreboard, ArrayDin Games){
    int i;
    for (i=0;i<Scoreboard.Neff;i++){
        printf("**** SCOREBOARD GAME %s ****\n", Get(Games,i));
        printf("| NAMA        | SKOR       |\n");
        if(IsEmpty_M(Scoreboard.A[i])){
            printf("---- SCOREBOARD KOSONG -----\n\n");
        }
        else{
            printf("|--------------------------|\n");
            int j;
            for (j=0;j<Scoreboard.A[i].Count;j++){
                if(stringlen(Scoreboard.A[i].Elements[j].Key) == 12){
                    if(stringlen(int_to_string(Scoreboard.A[i].Elements[j].Value))==1){
                        printf("| %s| %d          |\n",Scoreboard.A[i].Elements[j].Key,Scoreboard.A[i].Elements[j].Value);
                    }
                    else{
                        printf("| %s| %d         |\n",Scoreboard.A[i].Elements[j].Key,Scoreboard.A[i].Elements[j].Value);
                    }
                }
                else{
                    int k;
                    char *string3;
                    string3 = malloc(13*sizeof(char));
                    for (k=0;k<stringlen(Scoreboard.A[i].Elements[j].Key);k++){
                        string3[k] = Scoreboard.A[i].Elements[j].Key[k];
                    }
                    string3[k] = '\0';
                    int a = 12 - stringlen(string3); // maks nama 12 karakter
                    addspace(string3,a);
                    if(stringlen(int_to_string(Scoreboard.A[i].Elements[j].Value))==1){
                        printf("| %s| %d          |\n",string3,Scoreboard.A[i].Elements[j].Value);
                    }
                    else{
                        printf("| %s| %d         |\n",string3,Scoreboard.A[i].Elements[j].Value);
                    }
                }
            }
        }
        printf("\n");
    }
}

void SnakeMeteor(ArrayDin Games, ArrayDin_SB Scoreboard)
{
    /*makanan ga bs di body, makanan ga bs di obstacle, meteor ga bisa di makanan*/
    List Snake = MakeSnake();
    point Meteor = CreatePoint(-1,-1);
    point Obstacle = CreatePoint(random_number(0,4),random_number(0,4));
    point Food = CreatePoint(random_number(0,4),random_number(0,4));
    while (Search_LL(Snake,Obstacle)!=Nil || Search_LL(Snake,Food) != Nil || (Food.x == Obstacle.x && Food.y == Obstacle.y))
    {
        Obstacle = CreatePoint(random_number(0,4),random_number(0,4));
        Food = CreatePoint(random_number(0,4),random_number(0,4));
    }
    printf("Selamat datang di snake on meteor!\n\n");
    printf("Mengenerate peta, snake, dan makanan . . .\n\n");
    printf("Berhasil digenerate!\n\n");
    printf("------------------------------------------\n\n");
    printf("Berikut merupakan peta permainan\n");
    PrintArena(Snake,Meteor,Obstacle,Food);
    printf("\n\n");
    boolean endgame = false;
    int turn = 1;
    int temp = -999;
    boolean meteorhot = false;
    while(!endgame){
        boolean input_valid = false;
        while (input_valid == false)
        {
            printf("TURN %d\n",turn);
            printf("Silahkan masukkan command anda: ");
            STARTWORD(NULL,0);
            if(compareString(getCurrentWord(currentWord), "a") || compareString(getCurrentWord(currentWord),"d") || compareString(getCurrentWord(currentWord),"s") || compareString(getCurrentWord(currentWord),"w")){
                if(Info(Next(First(Snake))).x == mod(Info(First(Snake)).x + 1,5) && Info(Next(First(Snake))).y == Info(First(Snake)).y){
                    if(!compareString(getCurrentWord(currentWord), "d")){
                        input_valid = true;           
                    }
                }
                else if(Info(Next(First(Snake))).x == mod(Info(First(Snake)).x - 1,5) && Info(Next(First(Snake))).y == Info(First(Snake)).y){
                    if(!compareString(getCurrentWord(currentWord), "a")){
                        input_valid = true;   
                    }
                }
                else if(Info(Next(First(Snake))).y == mod(Info(First(Snake)).y + 1,5) && Info(Next(First(Snake))).x == Info(First(Snake)).x){
                    if(!compareString(getCurrentWord(currentWord), "s")){
                        input_valid = true;
                    }
                }
                else if(Info(Next(First(Snake))).y == mod(Info(First(Snake)).y - 1,5) && Info(Next(First(Snake))).x == Info(First(Snake)).x){
                    if(!compareString(getCurrentWord(currentWord), "w")){
                        input_valid = true;
                    }
                }
                else{
                    input_valid = true;
                }
                if(!input_valid){
                    printf("Anda tidak dapat bergerak ke tubuh anda sendiri!\n");
                    printf("Silahkan input command yang lain!\n\n");
                }
            }
            else{
                printf("Command tidak valid! Silahkan input command menggunakan huruf w/a/s/d\n\n");
            }
            while (!EndWord)
            {
                ADVWORD(0);
            }
        }

        if(compareString(getCurrentWord(currentWord),"w")){
            if(First(Snake)->info.y - 1 == Meteor.y && First(Snake)->info.x == Meteor.x && meteorhot && turn-temp == 1){
                printf("Meteor masih panas! Anda belum dapat kembali ke titik tersebut.\n");
                printf("Silahkan masukkan command lainnya\n\n");
            }
            else{
                meteorhot = false;
                temp = -999;
            }
        }
        else if(compareString(getCurrentWord(currentWord),"a")){
            if(First(Snake)->info.x - 1 == Meteor.x && First(Snake)->info.y == Meteor.y && meteorhot && turn-temp == 1){
                printf("Meteor masih panas! Anda belum dapat kembali ke titik tersebut.\n");
                printf("Silahkan masukkan command lainnya\n\n");
            }
            else{
                meteorhot = false;
                temp = -999;
            }
        }
        else if(compareString(getCurrentWord(currentWord),"d")){
            if(First(Snake)->info.x + 1 == Meteor.x && First(Snake)->info.y == Meteor.y && meteorhot && turn-temp == 1){
                printf("Meteor masih panas! Anda belum dapat kembali ke titik tersebut.\n");
                printf("Silahkan masukkan command lainnya\n\n");
            }
            else{
                meteorhot = false;
                temp = -999;
            }
        }
        else{
            if(First(Snake)->info.x == Meteor.x && First(Snake)->info.y + 1 == Meteor.y && meteorhot && turn-temp == 1){
                printf("Meteor masih panas! Anda belum dapat kembali ke titik tersebut.\n");
                printf("Silahkan masukkan command lainnya\n\n");
            }
            else{
                meteorhot = false;
                temp = -999;
            }
        }

        if(!meteorhot){
            int x_temp, y_temp, x_temp1, y_temp1;
            x_temp = ABSIS(Info(First(Snake)));
            y_temp = ORDINAT(Info(First(Snake)));
            if(compareString(getCurrentWord(currentWord),"w")){
                ORDINAT(Info(First(Snake))) = mod(move(Info(First(Snake)),0,-1).y,5);
            }
            else if(compareString(getCurrentWord(currentWord),"s")){
                ORDINAT(Info(First(Snake))) = mod(move(Info(First(Snake)),0,1).y,5);
            }
            else if(compareString(getCurrentWord(currentWord),"a")){
                ABSIS(Info(First(Snake))) = mod(move(Info(First(Snake)),-1,0).x,5);
            }
            else{
                ABSIS(Info(First(Snake))) = mod(move(Info(First(Snake)),1,0).x,5);
            }

            address p = Next(First(Snake));
            while (p!=Nil)
            {
                x_temp1 = ABSIS(Info(p));
                y_temp1 = ORDINAT(Info(p));
                ABSIS(Info(p)) = x_temp;
                ORDINAT(Info(p)) = y_temp;
                x_temp = x_temp1;
                y_temp = y_temp1;
                p = p->next;
            }
            
            if(First(Snake)->info.x == Food.x && First(Snake)->info.y == Food.y){
                if(Search_LL(Snake,CreatePoint(mod((Last(Snake)->info.x - 1),5), Last(Snake)->info.y))==Nil && !(Obstacle.x == mod((Last(Snake)->info.x - 1),5) && Obstacle.y == Last(Snake)->info.y) && !(Meteor.x == mod((Last(Snake)->info.x - 1),5) && Meteor.y == Last(Snake)->info.y)){
                    InsVLast_LL(&Snake,CreatePoint(mod((Last(Snake)->info.x - 1),5), Last(Snake)->info.y));
                    while (Search_LL(Snake,Food) != Nil || (Food.x == Obstacle.x && Food.y == Obstacle.y))
                    {
                        Food = CreatePoint(random_number(0,4),random_number(0,4));
                    }
                }
                else if(Search_LL(Snake,CreatePoint(Last(Snake)->info.x, mod((Last(Snake)->info.y - 1),5))) == Nil && !(Obstacle.x == Last(Snake)->info.x && Obstacle.y == mod((Last(Snake)->info.y - 1),5)) && !(Meteor.x == Last(Snake)->info.x && Meteor.y == mod((Last(Snake)->info.y - 1),5))){
                    InsVLast_LL(&Snake,CreatePoint(Last(Snake)->info.x, mod((Last(Snake)->info.y - 1),5)));
                    while (Search_LL(Snake,Food) != Nil || (Food.x == Obstacle.x && Food.y == Obstacle.y))
                    {
                        Food = CreatePoint(random_number(0,4),random_number(0,4));
                    }
                }
                else if(Search_LL(Snake,CreatePoint(Last(Snake)->info.x, mod((Last(Snake)->info.y + 1),5))) == Nil && !(Obstacle.x == Last(Snake)->info.x && Obstacle.y == mod((Last(Snake)->info.y + 1),5)) && !(Meteor.x == Last(Snake)->info.x && Meteor.y == mod((Last(Snake)->info.y + 1),5))){
                    InsVLast_LL(&Snake,CreatePoint(Last(Snake)->info.x, mod((Last(Snake)->info.y + 1),5)));
                    while (Search_LL(Snake,Food) != Nil || (Food.x == Obstacle.x && Food.y == Obstacle.y))
                    {
                        Food = CreatePoint(random_number(0,4),random_number(0,4));
                    }
                }
                else if(Search_LL(Snake,CreatePoint(mod((Last(Snake)->info.x + 1),5), Last(Snake)->info.y)) == Nil && !(Obstacle.x == mod((Last(Snake)->info.x + 1),5) && Obstacle.y == Last(Snake)->info.y) && !(Meteor.x == mod((Last(Snake)->info.x + 1),5) && Meteor.y == Last(Snake)->info.y)){
                    InsVLast_LL(&Snake,CreatePoint(mod((Last(Snake)->info.x + 1),5), Last(Snake)->info.y));
                    while (Search_LL(Snake,Food) != Nil || (Food.x == Obstacle.x && Food.y == Obstacle.y))
                    {
                        Food = CreatePoint(random_number(0,4),random_number(0,4));
                    }
                }
                else{
                    endgame = true;
                    printf("Snake tidak dapat menambah ekornya lagi!\n");
                }
            }
            else if(First(Snake)->info.x == Obstacle.x && First(Snake)->info.y == Obstacle.y){
                endgame = true;
                printf("Snake menabrak obstacle!\n");
            }
            else if(Search_LL(SnakeBody(Snake),First(Snake)->info)){
                endgame = true;
                printf("Snake menabrak komponennya sendiri!\n");
            }

            
            if(!endgame){
                Meteor = CreatePoint(random_number(0,4),random_number(0,4));
                while (Meteor.x == Food.x && Meteor.y == Food.y)
                {
                    Meteor = CreatePoint(random_number(0,4),random_number(0,4));
                }
                printf("Berhasil bergerak!\n");
                printf("Berikut merupakan peta permainan:\n");
                PrintArena(Snake,Meteor,Obstacle,Food);
                printf("\n");
                if(Search_LL(Snake,Meteor)!=Nil){
                    if(First(Snake)->info.x == Meteor.x && First(Snake)->info.y == Meteor.y){
                        endgame = true;
                        DelP_LL(&Snake,Meteor);
                        printf("Kepala snake terkena meteor!\n");
                    }
                    else{
                        printf("Anda terkena meteor!\n");
                        printf("Berikut merupakan peta permainan sekarang:\n");
                        DelP_LL(&Snake,Meteor);
                        PrintArena(Snake,Meteor,Obstacle,Food);
                        printf("\n");
                        printf("Silahkan lanjutkan permainan!\n\n");
                    }
                }
                else{
                    printf("Anda beruntung tidak terkena meteor! Silahkan lanjutkan permainan!\n\n");
                }
                meteorhot = true;
                temp = turn;
            }
            turn++;
            PrintInfo_LL(Snake);
            printf("\n\n");
        }
    }
    printf("Game berakhir. Skor: %d\n",NbElmt_LL(Snake)*2);
    STARTWORD(NULL,0);
    int i;
    char stringnama[13];
    if(currentWord.Length > 12){
        for(i=0;i<12;i++){
            stringnama[i] = currentWord.TabWord[i];
        }
    }
    else{
        for (i=0;i<currentWord.Length;i++){
            stringnama[i] = currentWord.TabWord[i];
        }
    }
    stringnama[i] = '\0';
    Insert_M(&Scoreboard.A[SearchArrayDin(Games,"Snake On Meteor")],stringnama,NbElmt_LL(Snake) * 2);
    int el_idx = Scoreboard.A[SearchArrayDin(Games,"Snake On Meteor")].Count-1;
    infotype temp1;
    while (Scoreboard.A[SearchArrayDin(Games,"Snake On Meteor")].Elements[el_idx].Value > Scoreboard.A[SearchArrayDin(Games,"Snake On Meteor")].Elements[el_idx-1].Value){
        temp1.Key = Scoreboard.A[SearchArrayDin(Games,"Snake On Meteor")].Elements[el_idx].Key;
        temp1.Value = Scoreboard.A[SearchArrayDin(Games,"Snake On Meteor")].Elements[el_idx].Value;
        Scoreboard.A[SearchArrayDin(Games,"Snake On Meteor")].Elements[el_idx].Key = Scoreboard.A[SearchArrayDin(Games,"Snake On Meteor")].Elements[el_idx-1].Key;
        Scoreboard.A[SearchArrayDin(Games,"Snake On Meteor")].Elements[el_idx].Value = Scoreboard.A[SearchArrayDin(Games,"Snake On Meteor")].Elements[el_idx-1].Value;
        Scoreboard.A[SearchArrayDin(Games,"Snake On Meteor")].Elements[el_idx-1].Key = temp1.Key;
        Scoreboard.A[SearchArrayDin(Games,"Snake On Meteor")].Elements[el_idx-1].Value = temp1.Value;
        el_idx--;
    }
}

List MakeSnake()
{
    List snake;
    CreateEmpty_LL(&snake);
    InsVLast_LL(&snake,CreatePoint(random_number(0,4),random_number(0,4)));
    if(Info(First(snake)).x >= 2){
        InsVLast_LL(&snake, CreatePoint(Info(First(snake)).x - 1, Info(First(snake)).y));
        InsVLast_LL(&snake, CreatePoint(Info(First(snake)).x - 2, Info(First(snake)).y));
    }
    else{
        if(Info(First(snake)).x == 0){
            if(Info(First(snake)).y <= 1){
                InsVLast_LL(&snake,CreatePoint(0,Info(First(snake)).y + 1));
                InsVLast_LL(&snake,CreatePoint(0,Info(First(snake)).y + 2));
            }
            else{
                InsVLast_LL(&snake, CreatePoint(0, Info(First(snake)).y - 1));
                InsVLast_LL(&snake, CreatePoint(0, Info(First(snake)).y - 2));
            }
        }
        else{
            if(Info(First(snake)).y == 0){
                InsVLast_LL(&snake, CreatePoint(0,0));
                InsVLast_LL(&snake, CreatePoint(0,1));
            }
            else{
                InsVLast_LL(&snake, CreatePoint(Info(First(snake)).x - 1, Info(First(snake)).y));
                InsVLast_LL(&snake, CreatePoint(Info(First(snake)).x - 1, Info(First(snake)).y - 1));
            }
        }
    }
    return snake;
}

void PrintArena(List snake, point meteor, point obstacle, point food)
{
    char* TANDA[25];
    int i;
    for (i=0;i<25;i++){
        TANDA[i] = "0";
    }
    TANDA[Info(First(snake)).x + Info(First(snake)).y * 5] = "H";
    address p = Next(First(snake));
    int count = 1;
    while (p!=Nil)
    {
        TANDA[Info(p).x + Info(p).y * 5] = int_to_string(count);
        count++;
        p = p->next;
    }
    TANDA[obstacle.x + obstacle.y * 5] = "b";
    TANDA[food.x + food.y * 5] = "o";
    if(meteor.x != -1 && meteor.y != -1){
        TANDA[meteor.x + meteor.y * 5] = "m"; 
    }
    printf("----------------\n");
    if(!compareString(TANDA[0],"0")){
        if(stringlen(TANDA[0]) == 2){
            printf("|%s|",TANDA[0]);
        }
        else{
            printf("|%s |",TANDA[0]);
        }
    }
    else{
        printf("|  |");
    }
    for(i=1;i<25;i++){
        if((i+5)%5==0){
            printf("\n----------------\n|");
        }
        if(!compareString(TANDA[i],"0")){
            if(stringlen(TANDA[i])==2){
                printf("%s|",TANDA[i]);
            }
            else{
                printf("%s |",TANDA[i]);
            }
            
        }
        else{
            printf("  |");
        }
    }
    printf("\n----------------");
}

char* int_to_string(int num){
    if(num == 0){
        char* result = "0";
        return result;
    }
    else{
        int temp;
        char* result;
        int idx_max = -1;
        temp = num;
        while (temp != 0){
            idx_max++;
            temp /= 10;
        }
        result = malloc ((idx_max+2)*sizeof(char));
        result[idx_max+1]='\0';
        while (num!=0)
        {
            temp = num%10;
            num/=10;
            result[idx_max] = temp+'0';
            idx_max--;
        }
        return result;
    }
}

List SnakeBody(List Snake){
    if(IsEmpty_LL(Snake)){
        return Snake;
    }
    else if(First(Snake)==Last(Snake)){
        List BodyEmpty;
        CreateEmpty_LL(&BodyEmpty);
        return BodyEmpty;
    }
    else{
        List Body;
        CreateEmpty_LL(&Body);
        Body.First = Next(First(Snake));
        Body.Last = Last(Snake);
        return Body;
    }
}

int mod(int x, int y){
    if(x>=0){
        return x%y;
    }
    else{
        while (x<0)
        {
            x+=y;
        }
        return x;
    }
}