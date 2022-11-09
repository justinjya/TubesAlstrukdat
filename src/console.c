#include "console.h"
#include "./ADT/arraydin/arraydin.c"
#include "./ADT/mesinkarakterv2/mesinkarakterv2.c"
#include "./ADT/mesinkata/mesinkata.c"
#include "./ADT/queue/queue.c"
#include "./ADT/arraydin/processedorder.h"
#include "./ADT/queue/circular_queue_of_pesanan.h"

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

void CREATEGAME(ArrayDin *arrayGames){
    char *gamesname;
    gamesname = (char *) malloc (50 * sizeof(char));
    int i = 0;
    boolean found = false;

    /* Input game yang ingin ditambah */
    printf("Masukkan nama game yang akan ditambahkan: ");
    inputString(1 , gamesname);
    
    /* Proses pencarian nama games yang diinput apakah sudah terdaftar sebelumnya */
    for (i; i < (*arrayGames).Neff; i++){
        if (compareString((*arrayGames).A[i], gamesname) == 1){
            found = true;
        }
    }
    if (found == false) /* Kondisi ketika game belum terdaftar */{
        InsertLast(arrayGames, gamesname);
        printf("Game berhasil ditambahkan");
    } else /* Kondisi ketika game seudah terdaftar */{
        printf("Game sudah terdaftar");
    }
}

void LISTGAME(ArrayDin *arrayGames){
    int i = 0;
    printf("Berikut adalah daftar game yang tersedia\n");
    
    /* Menampilkan list game dari nomor 1 indeks ke-0 */
    for (i; i < arrayGames->Neff; i++){
        printf("%d. %s\n", i + 1, arrayGames->A[i]);
    }
}

void DELETEGAME(ArrayDin *arrayGames){
	char *input;
    int i, a;
	input = (char *) malloc (5 * sizeof(char));

	LISTGAME(arrayGames);
	printf("Masukkan nomor game yang akan dihapus: ");
	inputInteger(&a);
	
	if ((a>=1) && (a<=5)){
		printf("Game gagal dihapus \n");
	}
	else if (a>5){
		i = a-1;
		DeleteAt(arrayGames, i);
		printf("Game berhasil dihapus \n");
		}
		
	}

void QUEUEGAME(ArrayDin *Games, Queue *Queue){
    int i, no;
    printf("Berikut adalah daftar antrian game-mu\n");

    // daftar antrian berjumlah >= 0
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
    printf("Berikut adalah daftar game yang tersedia\n");
    // dalam file konfigurasi default sudah terdapat minimal 3 game, sehingga pemeriksaan berupa apakah Games kosong tidak perlu dilakukan
    for (i=1;i<=Length(*Games);i++){
        printf("%d. %s\n", i, Games->A[i-1]);
    }
    printf("\n");

    // baca input user
    int nomor_game;
    printf("Nomor game yang mau ditambahkan ke antrian: ");
    inputInteger(&nomor_game);

    // validasi input
    if (nomor_game>=1 && nomor_game<=Length(*Games)){
        enqueue(Queue, Games->A[nomor_game-1]);
        printf("Game berhasil ditambahkan ke dalam daftar antrian.\n");        
    }
    else{
        printf("Nomor permainan tidak valid, silahkan masukkan nomor game pada list.\n");
    }
}

void PLAYGAME(ArrayDin *arraygame, Queue *queuegame)
{
    if (isEmpty(*queuegame))
    {
        printf("Belum ada antrian game yang kamu miliki\n");
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

            else if (compareString(HEAD(*queuegame), "DINNER DASH") == true)
            {
                printf("Loading %s ...\n", HEAD(*queuegame));
                // DINNERDASH();
            }

            else
            {
                printf("Game %s masih dalam maintenance, belum dapat dimainkan. SIlahkan pilih game lain.\n", HEAD(*queuegame));
            }

            dequeue(queuegame, &val);
        }
        else
        {
            printf("Loading %s ...\n", HEAD(*queuegame));
            GAMEBUATAN();
        }
    }
}

void SKIPGAME(ArrayDin *arraygames, Queue *queuegame, int skips)
{
    printf("Berikut adalah daftar game-mu:\n");
    for (IdxType i = IDX_HEAD(*queuegame); i <= IDX_TAIL(*queuegame); i++)
    {
        printf("%d. %s\n", i + 1, queuegame->buffer[i]);
    }

    ElType val;
    for (IdxType i = 0; i < skips; i++)
    {
        dequeue(queuegame, &val);
    }

    if (isEmpty(*queuegame))
    {
        printf("\nTidak ada permainan lagi dalam daftar game-mu.\n");
    }

    else
    {
        PLAYGAME(arraygames, queuegame);
    }
}

void QUIT(ArrayDin *Games, Queue *GamesQueue)
{
    DeallocateArrayDin(Games);
    ElType val;
    while (!isEmpty(*GamesQueue))
    {
        dequeue(GamesQueue, &val);
    }
    printf("\nAnda keluar dari game BNMO.\nBye bye ...\n");
}

void HELP()
{
    printf("DAFTAR COMMANDS:\n");
    printf("  1. START\n");
    printf("  2. LOAD <filename>\n");
    printf("  3. SAVE <filename>\n");
    printf("  4. CREATEGAME\n");
    printf("  5. LISTGAME\n");
    printf("  6. DELETEGAME\n");
    printf("  7. QUEUEGAME\n");
    printf("  8. PLAYGAME\n");
    printf("  9. SKIPGAME <n>\n");
    printf("  10. QUIT\n");
    printf("  11. HELP\n");
}

void RNG(){
	int jumlah, angka, tebak, skor;
    srand(time(NULL));
    angka = rand()% 100 + 1;
    jumlah = 0;

    printf("RNG Telah dimulai. Uji keberuntungan Anda dengan menebak X.\n");
    printf("Tebakan: ");
    inputInteger(&tebak);

    if (tebak == angka){
        printf("\n");
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
            inputInteger(&tebak);
        }
        if (tebak == angka){
            printf("\n");
            printf("Ya, X adalah %d \n", angka);
        }
    } skor = (25-jumlah)*4;
    printf("Skor = %d\n", skor); 
}

void GAMEBUATAN()
{
    char *rand;
    int score;

    rand = (char *) malloc (1 * sizeof(char));
    score = (int) rand % 100;

    printf("Skor = %d\n", score);
}
