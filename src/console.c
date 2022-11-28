#include "functions.c"
#include "./games/rng.c"
#include "./games/dinerdash.c"
// #include "./games/hangman.c"
// #include "./games/towerofhanoi.c"
#include "./games/snakeonmeteor.c"

void GAMEBUATAN()
{
    char *rand;
    int score;
    rand = (char *) malloc (1 * sizeof(char));
    score = (int) rand % 100;
    printf("Skor = %d\n", score);
}

void LOADFILE(ArrayDin *Games, Stack *History, char *inputfile, int numberOfArrays)
{
    char placeholder[] = ".\\data\\";
    char directory[50];
    char txt[] = ".txt";
    char filename[25];

    concat(inputfile, txt, filename);
    concat(placeholder, filename, directory);

    char *temp;
    int score;
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
        while (arrayNumber < numberOfArrays)
        {
            printf("amount = %d\n", amount);
            if (amount != -9999)
            {
                for (int j = 0; j < amount; j++)
                {
                    if (arrayNumber < 2)
                    {
                        ADVWORD(1);
                    }
                    else
                    {
                        ADVWORD(0);
                    }

                    temp = (char *) malloc (currentWord.Length * sizeof(char));
                    wordToString(currentWord, temp);
                    printf("%s\n", temp);

                    if (arrayNumber == 0)
                    {
                        InsertLast(Games, temp);
                    }
                    else if (arrayNumber == 1)
                    {
                        Push(History, temp);
                    }
                    // else if (arrayNumber == 2)
                    // {
                    //     InsertSet(namesRNG, temp);
                    //     ADVWORD(0);
                    //     ADV();
                    //     score = wordToInteger(currentWord);
                    //     InsertMap(scoreRNG, j, score);
                    // }
                    // else if (arrayNumber == 3)
                    // {
                    //     InsertSet(namesDinerDash, temp);
                    //     ADVWORD(0);
                    //     ADV();
                    //     score = wordToInteger(currentWord);
                    //     InsertMap(scoreDinerDash, j, score);
                    // }
                    // else if (arrayNumber == 4)
                    // {
                    //     InsertSet(namesHangman, temp);
                    //     ADVWORD(0);
                    //     ADV();
                    //     score = wordToInteger(currentWord);
                    //     InsertMap(scoreHangman, j, score);
                    // }
                    // else if (arrayNumber == 5)
                    // {
                    //     InsertSet(namesTowerOfHanoi, temp);
                    //     ADVWORD(0);
                    //     ADV();
                    //     score = wordToInteger(currentWord);
                    //     InsertMap(scoreTowerOfHanoi, j, score);
                    // }
                    // else if (arrayNumber == 6)
                    // {
                    //     InsertSet(namesSnakeOnMeteor, temp);
                    //     ADVWORD(0);
                    //     ADV();
                    //     score = wordToInteger(currentWord);
                    //     InsertMap(scoreSnakeOnMeteor, j, score);
                    // }
                }
            }
            printf("arrayNumber = %d\n", arrayNumber);
            if (arrayNumber <= 1)
            {
                ADVWORD(1);
            }
            else
            {
                ADVWORD(0);
            }
            arrayNumber++;
            amount = wordToInteger(currentWord);
            if (arrayNumber > 1)
            {
                ADV();
            }
        }
        if (compareString(filename, "config.txt") == true)
        {
            printf("File konfigurasi sistem berhasil dibaca. BNMO berhasil dijalankan.\n");
        }
        else
        {
            printf("File %s berhasil dibaca. BNMO berhasil dijalankan.\n", inputfile);
            printf("\nHistory:\n");
            for (int i = Top(*History); i >= 0; i--)
            {
                printf("%s\n", History->T[i]);
            }
            // printf("\nscoreboardRNG:\n");
            // for (int i = 0; i < namesRNG->Count; i++)
            // {
            //     printf("%s %d\n", namesRNG->Elements[i], scoreRNG->Elements[i].Value);
            // }
            // printf("\nscoreboardDinerDash:\n");
            // for (int i = 0; i < namesDinerDash->Count; i++)
            // {
            //     printf("%s %d\n", namesDinerDash->Elements[i], scoreDinerDash->Elements[i].Value);
            // }
            // printf("\nscoreboardHangman:\n");
            // for (int i = 0; i < namesHangman->Count; i++)
            // {
            //     printf("%s %d\n", namesHangman->Elements[i], scoreHangman->Elements[i].Value);
            // }
            // printf("\nscoreboardTowerOfHanoi:\n");
            // for (int i = 0; i < namesTowerOfHanoi->Count; i++)
            // {
            //     printf("%s %d\n", namesTowerOfHanoi->Elements[i], scoreTowerOfHanoi->Elements[i].Value);
            // }
            // printf("\nscoreboardSnakeOnMeteor:\n");
            // for (int i = 0; i < namesSnakeOnMeteor->Count; i++)
            // {
            //     printf("%s %d\n", namesSnakeOnMeteor->Elements[i], scoreSnakeOnMeteor->Elements[i].Value);
            // }
        }
    }
}

void STARTBNMO(ArrayDin *Games, Stack *History)
{
    LOADFILE(Games, History, "config", 1);
}

void SAVE(ArrayDin *Games, Stack *History, char *inputfile)
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

    if (!IsEmptyStack(*History))
    {
        fprintf(open, "%d\n", Top(*History) + 1);
        for (int i = 0; i <= Top(*History); i++)
        {
            fprintf(open, "%s\n", History->T[i]);
        }
    }

    fprintf(open, ".");
    fclose(open);
    printf("Save file berhasil disimpan.\n");
}

void LISTGAME(ArrayDin *arrayGames){
    int i = 0;
    printf("Berikut adalah daftar game yang tersedia:\n");
    
    /* Menampilkan list game dari nomor 1 indeks ke-0 */
    for (i; i < arrayGames->Neff; i++){
        printf("%d. %s\n", i + 1, arrayGames->A[i]);
    }
}

void CREATEGAME(ArrayDin *arrayGames){
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
    } else /* Kondisi ketika game seudah terdaftar */{
        printf("Game sudah terdaftar. Silahkan masukkan nama game lain.\n");
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

void PLAYGAME(ArrayDin *arraygame, Queue *queuegame, Stack *history)
{
    if (isEmpty(*queuegame))
    {
        printf("Belum ada antrean game yang kamu miliki.\n");
    }

    else
    {
        IdxType index;
        ElType val;
        int skor;
        index = SearchArrayDin(*arraygame, HEAD(*queuegame));
        if (index < 5)
        {
            if (compareString(HEAD(*queuegame), "RNG") == true)
            {
                printf("Loading %s ...\n", HEAD(*queuegame));
                skor = RNG();
            }

            else if (compareString(HEAD(*queuegame), "Diner Dash") == true)
            {
                printf("Loading %s ...\n", HEAD(*queuegame));
                skor = DINERDASH();
            }

            else if (compareString(HEAD(*queuegame), "Hangman") == true)
            {
                printf("Loading %s ...\n", HEAD(*queuegame));
                // skor = HANGMAN();
            }
            
            else if (compareString(HEAD(*queuegame), "Tower of Hanoi") == true)
            {
                printf("Loading %s ...\n", HEAD(*queuegame));
                // skor = TOWEROFHANOI();
            }

            else if (compareString(HEAD(*queuegame), "Snake on Meteor") == true)
            {
                printf("Loading %s ...\n", HEAD(*queuegame));
                skor = SNAKEONMETEOR();
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
        Push(history, val);
    }
}

void SKIPGAME(ArrayDin *arraygames, Queue *queuegame, Stack *history, int skips)
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
            PLAYGAME(arraygames, queuegame, history);
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
                if(stringLen(Scoreboard.A[i].Elements[j].Key) == 12){
                    if(stringLen(int_to_string(Scoreboard.A[i].Elements[j].Value))==1){
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
                    for (k=0;k<stringLen(Scoreboard.A[i].Elements[j].Key);k++){
                        string3[k] = Scoreboard.A[i].Elements[j].Key[k];
                    }
                    string3[k] = '\0';
                    int a = 12 - stringLen(string3); // maks nama 12 karakter
                    addspace(string3,a);
                    if(stringLen(int_to_string(Scoreboard.A[i].Elements[j].Value))==1){
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

void HISTORY(Stack *History, int n)
{
    idxTypeStack last;
    last = (Top(*History) + 1) - n;
    if (last < 0)
    {
        last = 0;
    }

    printf("Berikut adalah daftar Game yang telah dimainkan:\n");
    int number = 1;
    for (idxTypeStack i = Top(*History); i >= last; i--)
    {
        printf("%d. %s\n", number, History->T[i]);
        number++;
    }
}

void RESETHISTORY(Stack *History)
{
    char *input;
    input = (char *) malloc (10 * sizeof(char));
    printf("APAKAH KAMU YAKIN INGIN MELAKUKAN RESET HISTORY? (YA/TIDAK) ");
    inputString(0, input);
    if (compareString(input, "YA") == true)
    {
        CreateEmptyStack(History);
    }
    else if (compareString(input, "TIDAK") == true)
    {
        printf("History tidak jadi di-reset. Berikut adalah daftar Game yang telah dimainkan:\n");
        {
            int number = 1;
            for (idxTypeStack i = Top(*History); i >= 0; i--)
            {
                printf("%d. %s\n", number, History->T[i]);
                number++;
            }
        }
    }
    else
    {
        printf("Command tidak dikenali. Silahkan masukkan command (YA/TIDAK).\n\n");
        RESETHISTORY(History);
    }
}
