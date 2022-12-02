#include "functions.c"
#include "./games/rng.c"
#include "./games/dinerdash.c"
#include "./games/hangman.c"
#include "./games/towerofhanoi.c"
#include "./games/snakeonmeteor.c"

int GAMEBUATAN()
{
    int score;
    score = randomNumber(0, 100);
    printf("Skor akhir: %d\n", score);
    return score;
}

void LOADFILE(ArrayDin *Games, Stack *History, Queue *GamesQueue, ArrayDin_SB *Scoreboard, char *inputfile, boolean Start)
{
    #ifdef _WIN32
        char *placeholder = ".\\data\\";
    #else
        char *placeholder = "./data/";
    #endif
    char *txt = ".txt";
    char *filename;
    char *directory;
    filename = (char *) malloc (25 * sizeof(char));
    directory = (char *) malloc (50 * sizeof(char));
    concat(inputfile, txt, filename);
    concat(placeholder, filename, directory);

    FILE *file;
    file = fopen(directory, "r");
    if (file == NULL)
    {
        printf("File tidak dapat dibuka. Silahkan masukkan nama file lain.\n");
    }
    else
    {
        fclose(file);
        int amount, score, totalScoreboard, i, j;
        char *temp;

        STARTWORD(directory, 1);
        amount = wordToInteger(currentWord);
        totalScoreboard = wordToInteger(currentWord);
        *Scoreboard = MakeArrayDin_SB(amount);

        for (i = 0; i < amount; i++)
        {
            ADVWORD(1);
            temp = (char *) malloc (30 * sizeof(char));
            wordToString(currentWord, temp);
            InsertLast(Games, temp);
        }

        if (Start == true)
        {
            printf("File konfigurasi sistem berhasil dibaca. BNMO berhasil dijalankan.\n");
        }
        else
        {
            ADVWORD(1);
            amount = wordToInteger(currentWord);
            for (i = 0; i < amount; i++)
            {
                ADVWORD(1);
                temp = (char *) malloc (30 * sizeof(char));
                wordToString(currentWord, temp);
                Push(History, temp);
            }
            for (i = 0; i < totalScoreboard; i++)
            {
                ADVWORD(1);
                amount = wordToInteger(currentWord);
                for (j = 0; j < amount; j++)
                {
                    ADVWORD(1);
                    temp = (char *) malloc (30 * sizeof(char));
                    wordToString(currentWord, temp);
                    temp = splitStringInt(temp, &score);
                    Insert_M(&Scoreboard->A[i], temp, score);
                }
            }
            printf("File %s berhasil dibaca. BNMO berhasil dijalankan.\n", inputfile);
        }
        fclose(pita);
    }
}

void STARTBNMO(ArrayDin *Games, Stack *History, Queue *GamesQueue, ArrayDin_SB *Scoreboard)
{
    LOADFILE(Games, History, GamesQueue, Scoreboard, "config", true);
}

void SAVE(ArrayDin *Games, Stack *History, ArrayDin_SB *Scoreboard, char *inputfile)
{
    #ifdef _WIN32
        char *placeholder = ".\\data\\";
    #else
        char *placeholder = "./data/";
    #endif
    char *txt = ".txt";
    char *filename;
    char *directory;
    filename = (char *) malloc (25 * sizeof(char));
    directory = (char *) malloc (50 * sizeof(char));
    concat(inputfile, txt, filename);
    concat(placeholder, filename, directory);

    FILE *open;
    open = fopen(directory, "w");

    fprintf(open, "%d\n", Games->Neff);
    for (int i = 0; i < Games->Neff; i++)
    {
        fprintf(open, "%s\n", Games->A[i]);
    }

    fprintf(open, "%d\n", Top(*History) + 1);
    for (int i = 0; i <= Top(*History); i++)
    {
        fprintf(open, "%s\n", History->T[i]);
    }

    for (int i = 0; i < Scoreboard->Neff; i++)
    {
        fprintf(open, "%d\n", Scoreboard->A[i].Count);
        for (int j = 0; j < Scoreboard->A[i].Count; j++)
        {
            fprintf(open, "%s %d\n", Scoreboard->A[i].Elements[j].Key, Scoreboard->A[i].Elements[j].Value);
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

void CREATEGAME(ArrayDin *arrayGames, ArrayDin_SB *Scoreboard, boolean *saved){
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
        if (compareString((*arrayGames).A[i], upper(gamesname)) == 1){
            found = true;
        }
    }
    if (found == false) /* Kondisi ketika game belum terdaftar */{
        InsertLast(arrayGames, upper(gamesname));
        AddNeff_SB(Scoreboard);
        printf("Game berhasil ditambahkan.\n");
	*saved = false;
    } else /* Kondisi ketika game seudah terdaftar */{
        printf("Game sudah terdaftar. Silahkan masukkan nama game lain.\n");
    }
}

void DELETEGAME(ArrayDin *arrayGames, Queue *queueGames, ArrayDin_SB *scoreboard, boolean *saved){
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
	    *saved = false;
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
                skor = HANGMAN();
            }
            
            else if (compareString(HEAD(*queuegame), "TOWER OF HANOI") == true)
            {
                skor = TOWEROFHANOI();
            }

            else if (compareString(HEAD(*queuegame), "SNAKE ON METEOR") == true)
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
        if (compareString(upper(input), "YA") == true){
            QUIT(Games, GamesQueue, History, Scoreboard, true);
        }
        else if (compareString(upper(input), "TIDAK") == true){
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
        printf("  8. SCOREBOARD - Menampilkan scoreboard setiap game yang tersedia dari sistem\n");
        printf("  9. RESET SCOREBOARD - Menghapus isi scoreboard setiap game/suaatu game yang tersedia dari sistem\n");
        printf("  10. HISTORY - Menampilkan riwayat permainan user\n");
        printf("  11. RESET HISTORY - Menghapus riwayat permainan user\n");
        printf("  12. QUIT - Keluar dari program\n");
        printf("  13. HELP - Menampilkan daftar commands yang dapat dijalankan\n");
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
                int k;
                char *string1;
                char *string2;
                char *temp;
                string1 = malloc(13*sizeof(char));
                string2 = malloc(11*sizeof(char));
                for (k=0;k<stringLen(Scoreboard.A[i].Elements[j].Key);k++){
                    string1[k] = Scoreboard.A[i].Elements[j].Key[k];
                }
                string1[stringLen(Scoreboard.A[i].Elements[j].Key)] = '\0';
                temp = int_to_string(Scoreboard.A[i].Elements[j].Value);
                for (k=0;k<stringLen(temp);k++){
                    string2[k] = temp[k];
                }
                string2[stringLen(temp)] = '\0';
                if(stringLen(string1) < 12){
                    int a = 12 - stringLen(string1); // maks nama 11 karakter
                    addspace(string1,a);
                }
                if(stringLen(string2) < 11){
                    int b = 11 - stringLen(string2); // maks angka 10 karakter
                    addspace(string2,b);
                }
                printf("| %s| %s|\n",string1,string2);
            }
            printf("\n");
        }
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
    if (scoreboardIdx >= 0 && scoreboardIdx <= Games->Neff)
    {
        char *input;
        input = (char *) malloc (10 * sizeof(char));
        printf("\n");
        printf("APAKAH ANDA YAKIN INGIN MELAKUKAN RESET\n");
        if (scoreboardIdx > 0)
        {
            printf("SCOREBOARD %s? (YA/TIDAK) ", Games->A[scoreboardIdx - 1]);
        }
        else
        {
            printf("SCOREBOARD ALL? (YA/TIDAK) ");
        }
        inputString(0, input);
        if (compareString(upper(input), "YA") == true)
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
        else if (compareString(upper(input), "TIDAK") == true)
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

void HISTORY(Stack *history, int n)
{
    idxTypeStack last;
    last = (Top(*history) + 1) - n;
    if (last < 0)
    {
        last = 0;
    }

    if (Top(*history) == Nil)
    {
        printf("Anda belum memiliki riwayat permainan.\n");
    }

    else
    {
        printf("Berikut adalah daftar Game yang telah dimainkan:\n");
        int number = 1;
        for (idxTypeStack i = Top(*history); i >= last; i--)
        {
            printf("%d. %s\n", number, history->T[i]);
            number++;
        }
    }
}

void RESETHISTORY(Stack *history)
{
    char *input;
    input = (char *) malloc (10 * sizeof(char));
    printf("APAKAH KAMU YAKIN INGIN MELAKUKAN RESET HISTORY? (YA/TIDAK) ");
    inputString(0, input);

    if (compareString(upper(input), "YA") == true)
    {
        CreateEmptyStack(history);
    }

    else if (compareString(upper(input), "TIDAK") == true)
    {
        printf("\nHistory tidak jadi di-reset. Berikut adalah daftar Game yang telah dimainkan:\n");
        {
            HISTORY(history, Top(*history) + 1);
        }
    }

    else
    {
        printf("Command tidak dikenali. Silahkan masukkan command (YA/TIDAK).\n\n");
        RESETHISTORY(history);
    }
}
