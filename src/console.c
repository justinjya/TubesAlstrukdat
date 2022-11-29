#include "functions.c"
#include "./games/rng.c"
#include "./games/dinerdash.c"
// #include "./games/hangman.c"
// #include "./games/towerofhanoi.c"
#include "./games/snakeonmeteor.c"

int GAMEBUATAN()
{
    char *rand;
    int score;
    rand = (char *) malloc (1 * sizeof(char));
    score = (int) rand % 100;
    printf("Skor akhir: %d\n", score);
    return score;
}

void LOADFILE(ArrayDin *Games, Stack *History, Queue *GamesQueue, ArrayDin_SB *Scoreboard, char *inputfile, boolean Start)
{
    char placeholder[] = ".\\data\\";
    char directory[50];
    char txt[] = ".txt";
    char filename[25];

    concat(inputfile, txt, filename);
    concat(placeholder, filename, directory);

    char *temp;
    int score, amount, totalScoreboard;
    int arrayNumber = 1;
    int arrayScoreboard = 0;

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
        totalScoreboard = wordToInteger(currentWord);
        *Scoreboard = MakeArrayDin_SB(amount);
        while (arrayNumber <= totalScoreboard + 2)
        {
            if (amount != -9999)
            {
                for (int j = 0; j < amount; j++)
                {
                    ADVWORD(1);
                    temp = (char *) malloc (30 * sizeof(char));
                    wordToString(currentWord, temp);
                    if (arrayNumber == 1)
                    {
                        InsertLast(Games, temp);
                    }
                    else if (arrayNumber == 2)
                    {
                        Push(History, temp);
                    }
                    else
                    {
                        temp = splitStringInt(temp, &score);
                        Insert_M(&Scoreboard->A[arrayScoreboard], temp, score);
                    }
                }
            }
            if (arrayNumber > 2)
            {
                arrayScoreboard++;
            }
            ADVWORD(1);
            arrayNumber++;
            amount = wordToInteger(currentWord);
        }
        if (Start == true)
        {
            printf("File konfigurasi sistem berhasil dibaca. BNMO berhasil dijalankan.\n");
        }
        else
        {
            printf("File %s berhasil dibaca. BNMO berhasil dijalankan.\n", inputfile);
        }
        SortValueMap(&Scoreboard->A[0], false);
    }
}

void STARTBNMO(ArrayDin *Games, Stack *History, Queue *GamesQueue, ArrayDin_SB *Scoreboard)
{
    LOADFILE(Games, History, GamesQueue, Scoreboard, "config", true);
}

void SAVE(ArrayDin *Games, Stack *History, ArrayDin_SB *Scoreboard, char *inputfile)
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

    for (int i = 0; i < Scoreboard->Neff; i++)
    {
        fprintf(open, "%d\n", Scoreboard->A[i].Count);
        for (int j = 0; j < Scoreboard->A[i].Count; j++)
        {
            fprintf(open, "%s %d\n", Scoreboard->A[i].Elements[j]);
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

void CREATEGAME(ArrayDin *arrayGames, ArrayDin_SB *Scoreboard){
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
        AddNeff_SB(Scoreboard);
        printf("Game berhasil ditambahkan.\n");
    } else /* Kondisi ketika game seudah terdaftar */{
        printf("Game sudah terdaftar. Silahkan masukkan nama game lain.\n");
    }
}

void DELETEGAME(ArrayDin *arrayGames, Queue *queueGames, ArrayDin_SB *scoreboard){
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
            SubNeff_SB(scoreboard);
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

void PLAYGAME(ArrayDin *arraygame, Queue *queuegame, Stack *history, ArrayDin_SB *scoreboard)
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
            printf("Loading %s ...\n", HEAD(*queuegame));
            if (compareString(HEAD(*queuegame), "RNG") == true)
            {
                skor = RNG();
            }

            else if (compareString(HEAD(*queuegame), "DINER DASH") == true)
            {
                skor = DINERDASH();
            }

            else if (compareString(HEAD(*queuegame), "HANGMAN") == true)
            {
                skor = 0;
                // skor = HANGMAN();
            }
            
            else if (compareString(HEAD(*queuegame), "TOWER OF HANOI") == true)
            {
                skor = 0;
                // skor = TOWEROFHANOI();
            }

            else if (compareString(HEAD(*queuegame), "SNAKEONMETEOR") == true)
            {
                skor = SNAKEONMETEOR();
            }

            // else
            // {
            //     printf("Game %s masih dalam maintenance, belum dapat dimainkan. Silahkan pilih game lain.\n", HEAD(*queuegame));
            // }

        }

        else
        {
            printf("Loading %s ...\n", HEAD(*queuegame));
            skor = GAMEBUATAN();
        }
        inputNamaScoreboard(arraygame, queuegame, scoreboard, skor);
        dequeue(queuegame, &val);
        Push(history, val);
    }
}

void SKIPGAME(ArrayDin *arraygame, Queue *queuegame, Stack *history, ArrayDin_SB *scoreboard, int skips)
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
            PLAYGAME(arraygame, queuegame, history, scoreboard);
        }
	    
        else
        {
            printf("\nTidak ada permainan lagi dalam daftar game-mu.\n");
        }
    }
}

void QUIT(ArrayDin *Games, Queue *GamesQueue, Stack *History, ArrayDin_SB *Scoreboard, boolean saved){
    if (saved == true){
        DeallocateArrayDin(Games);
        ElType val;
        while (!isEmpty(*GamesQueue)){
            dequeue(GamesQueue, &val);
        }
        printf("\nAnda keluar dari game BNMO.\nBye bye ...\n\n");
    }
    else{
        char *input;
        input = (char *) malloc (7 * sizeof(char));
        printf("Anda belum melakukan SAVE! Apakah anda tetap ingin keluar\n");
        printf("dari game BNMO tanpa melakukan SAVE? (YA/TIDAK) ");
        inputString(0, input);
        if (compareString(input, "YA") == true){
            QUIT(Games, GamesQueue, History, Scoreboard, true);
        }
        else if (compareString(input, "TIDAK") == true){
            char *inputfile;
            inputfile = (char *) malloc (50 * sizeof(char));
            printf("\nSilahkan input nama file untuk disimpan (tanpa .txt): ");
            inputString(0, inputfile);
            SAVE(Games, History, Scoreboard, inputfile);
            QUIT(Games, GamesQueue, History, Scoreboard, true);
        }
        else{
            printf("\nCommand tidak dikenali. Silahkan input command (YA/TIDAK).\n\n");
            QUIT(Games, GamesQueue, History, Scoreboard, false);
        }
    }
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

void RESETSCOREBOARD(ArrayDin *Games, ArrayDin_SB *Scoreboard)
{
    int scoreboardIdx;
    printf("DAFTAR SCOREBOARD:\n");
    printf("0. ALL\n");
    for (int i = 0; i < Games->Neff; i++)
    {
        printf("%d. %s\n", i + 1, Games->A[i]);
    }
    printf("\n");
    printf("SCOREBOARD YANG INGIN DIHAPUS: ");
    inputInteger(&scoreboardIdx);
    if (scoreboardIdx >= 0 && scoreboardIdx < Games->Neff)
    {
        char *input;
        input = (char *) malloc (10 * sizeof(char));
        printf("\n");
        printf("APAKAH ANDA YAKIN INGIN MELAKUKAN RESET\n");
        if (scoreboardIdx > 0)
        {
            printf("SCOREBOARD %s? (YA/TIDAK) ", Games->A[scoreboardIdx] - 1);
        }
        else
        {
            printf("SCOREBOARD ALL? (YA/TIDAK) ");
        }
        inputString(0, input);
        if (compareString(input, "YA") == true)
        {
            if (scoreboardIdx == 0)
            {
                for (int i = 0; i < Scoreboard->Neff; i++)
                {
                    CreateEmpty_M(&Scoreboard->A[i]);
                }
            }
            else
            {
                CreateEmpty_M(&Scoreboard->A[scoreboardIdx - 1]);
            }
            printf("Scoreboard berhasil di-reset.\n");
        }
        else if (compareString(input, "TIDAK") == true)
        {
            printf("Scoreboard tidak berhasil di-reset.\n");
        }
        else
        {
            printf("Command tidak dikenali. Silahkan masukkan command (YA/TIDAK).\n\n");
            RESETSCOREBOARD(Games, Scoreboard);
        }
    }
    else
    {
        printf("SCOREBOARD TIDAK TERDAFTAR. SILAHKAN INPUT SCOREBOARD LAIN.\n");
    }
}
