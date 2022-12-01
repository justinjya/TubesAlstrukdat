#include "../functions.h"

/* Menerima input berupa id bertipe integer serta mengembalikan Food ID bertipe char* dengan format "M(id)"
 */
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

/* Menampikan daftar pesanan di Diner Dash
 * Menerima input berupa sebuah QueueOfPesanan
 */
void PrintUIPesanan(QueueOfPesanan pesanan){
    printf("Daftar Pesanan\n");
    printf("Makanan | Durasi Memasak | Ketahanan | Harga\n");
    printf("----------------------------------------------\n");
    int i;
    i = pesanan.HEAD;
    while(i!=(pesanan.TAIL+1)%pesanan.MaxEl){
        if(stringLen(pesanan.Tab[i].makanan)==2){
            printf("%s      | %d              | %d         | %d\n",pesanan.Tab[i].makanan,pesanan.Tab[i].durasimasak,pesanan.Tab[i].ketahanan,pesanan.Tab[i].harga);
        }
        else{
            printf("%s     | %d              | %d         | %d\n",pesanan.Tab[i].makanan,pesanan.Tab[i].durasimasak,pesanan.Tab[i].ketahanan,pesanan.Tab[i].harga);
        }
        i = (i+1)%pesanan.MaxEl;
    }
    printf("\n");
}

/* Menampilkan daftar pesanan yang sedang dimasak di Diner Dash
 * Menerima input berupa sebuah processedorder
 */
void PrintUIOnCook(processedorder oncook){
    printf("Daftar Makanan yang sedang dimasak\n");
    printf("Makanan | Sisa durasi memasak\n");
    printf("--------------------------------\n");
    int i;
    if(!IsProcessedOrderEmpty(oncook)){
        for(i=1;i<=LengthOfProcessedOrder(oncook);i++){
            if(stringLen(oncook.A[i-1].makanan) == 2){
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

/* Menampilkan daftar pesanan yang siap untuk disajikan di Diner Dash
 * Menerima input berupa processedorder
 */
void PrintUIReadyToServe(processedorder readytoserve){
    printf("Daftar Makanan yang siap disajikan\n");
    printf("Makanan | Sisa Ketahanan Makanan\n");
    printf("-----------------------------------\n");
    int i;
    if(!IsProcessedOrderEmpty(readytoserve)){
        for(i=1;i<=LengthOfProcessedOrder(readytoserve);i++){
            if(stringLen(readytoserve.A[i-1].makanan) == 2){
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

/* Permainan mengantarkan makanan namun terurut berdasarkan prioritasnya.
 */
int DINERDASH(){
    int i;
    int saldo = 0;
    int served_customer = 0;
    QueueOfPesanan pesanan;
    processedorder oncook;
    processedorder readytoserve;
    pesanan = CreateQueueOfPesanan(10);
    oncook = MakeProcessedOrder(5);
    readytoserve = MakeProcessedOrder(InitialSize);
    PushPesanan(&pesanan,CreatePesanan("M0",randomNumber(1,3),randomNumber(2,5),randomNumber(10,50) * 1000));
    PushPesanan(&pesanan,CreatePesanan("M1",randomNumber(1,3),randomNumber(2,5),randomNumber(10,50) * 1000));
    PushPesanan(&pesanan,CreatePesanan("M2",randomNumber(1,3),randomNumber(2,5),randomNumber(10,50) * 1000));
    printf("\n====================================== DINER DASH ======================================\n");
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
        if(compareString(upper(getCurrentWord(currentWord)),"COOK") == true || compareString(upper(getCurrentWord(currentWord)),"SERVE") == true || compareString(upper(getCurrentWord(currentWord)),"SKIP") == true || compareString(upper(getCurrentWord(currentWord)),"QUIT") == true){
            if(compareString(upper(getCurrentWord(currentWord)),"COOK")==true){
                ADVWORD(0);
                if(currentChar == '\n'){
                    boolean found = false;
                    i = pesanan.HEAD;
                    while (i!=(pesanan.TAIL+1)%pesanan.MaxEl && found == false){
                        if(compareString(pesanan.Tab[i].makanan, upper(getCurrentWord(currentWord)))==true){
                            found = true;
                        }
                        i = (i+1)%pesanan.MaxEl;
                    }
                    
                    if(found){
                        if(LengthOfProcessedOrder(oncook)<GetProcessedOrderCapacity(oncook)){
                            int idx = (i-1) % pesanan.MaxEl;
                            printf("Berhasil memasak %s\n",pesanan.Tab[idx].makanan);/*currentWord.TabWord*/
                            PushPesanan(&pesanan,CreatePesanan(food_id_generator(LengthQueueOfPesanan(pesanan)+served_customer),randomNumber(1,5),randomNumber(1,5),randomNumber(10,50) * 1000));
                            
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
            else if(compareString(upper(getCurrentWord(currentWord)),"SERVE") == true){
                ADVWORD(0);
                if(currentChar == '\n'){
                    boolean found = false;
                    i = 0;
                    while (i<readytoserve.Neff && found == false){
                        if(compareString(readytoserve.A[i].makanan, upper(getCurrentWord(currentWord))) == true){
                            found = true;
                        }
                        i++;
                    }
                    if(found){       
                        if (compareString(upper(getCurrentWord(currentWord)),pesanan.Tab[pesanan.HEAD].makanan) == true){
                            masakan m = MakeMasakan(pesanan.Tab[pesanan.HEAD].makanan,pesanan.Tab[pesanan.HEAD].ketahanan);
                            saldo += pesanan.Tab[pesanan.HEAD].harga;
                            printf("Berhasil mengantar %s\n",pesanan.Tab[pesanan.HEAD].makanan);
                            PopPesanan(&pesanan);
                            DeleteProcessedOrderAt(&readytoserve,SearchMasakan(readytoserve,m));
                            served_customer+=1;
                            
                            PushPesanan(&pesanan,CreatePesanan(food_id_generator(LengthQueueOfPesanan(pesanan)+served_customer),randomNumber(1,5),randomNumber(1,5),randomNumber(10,50) * 1000));
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
                            printf("%s belum dapat disajikan karena %s belum selesai\n\n",upper(getCurrentWord(currentWord)),pesanan.Tab[pesanan.HEAD].makanan);
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
            else if(compareString(upper(getCurrentWord(currentWord)),"SKIP") == true){
                IgnoreBlanks();
                if(currentChar == '\n'){
                    PushPesanan(&pesanan,CreatePesanan(food_id_generator(LengthQueueOfPesanan(pesanan)+served_customer),randomNumber(1,5),randomNumber(1,5),randomNumber(10,50) * 1000));        
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
            else if(compareString(upper(getCurrentWord(currentWord)),"QUIT") == true){
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
    printf("\n===================================== GAME BERAKHIR ====================================\n");
    printf("Skor akhir: %d\n",saldo);
    return saldo;
}
