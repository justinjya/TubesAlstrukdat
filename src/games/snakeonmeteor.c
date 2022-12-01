#include "../functions.h"

List MakeSnake()
{
    List snake;
    CreateEmpty_LL(&snake);
    InsVLast_LL(&snake,CreatePoint(randomNumber(0,4),randomNumber(0,4)));
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
    while (p!=NULL)
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
    printf("---------------------\n");
    if(!compareString(TANDA[0],"0")){
        if(stringLen(TANDA[0]) == 2){
            printf("| %s |",TANDA[0]);
        }
        else{
            printf("| %s |",TANDA[0]);
        }
    }
    else{
        printf("|   |");
    }
    for(i=1;i<25;i++){
        if((i+5)%5==0){
            printf("\n---------------------\n|");
        }
        if(!compareString(TANDA[i],"0")){
            if(stringLen(TANDA[i])==2){
                printf(" %s |",TANDA[i]);
            }
            else{
                printf(" %s |",TANDA[i]);
            }
            
        }
        else{
            printf("   |");
        }
    }
    printf("\n---------------------");
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

int SNAKEONMETEOR()
{
    List Snake = MakeSnake();
    point Meteor = CreatePoint(-1,-1);
    point Obstacle = CreatePoint(randomNumber(0,4),randomNumber(0,4));
    point Food = CreatePoint(randomNumber(0,4),randomNumber(0,4));
    while (Search_LL(Snake,Obstacle)!=NULL || Search_LL(Snake,Food) != NULL || (Food.x == Obstacle.x && Food.y == Obstacle.y))
    {
        Obstacle = CreatePoint(randomNumber(0,4),randomNumber(0,4));
        Food = CreatePoint(randomNumber(0,4),randomNumber(0,4));
    }
    printf("\n==================================== SNAKE ON METEOR ====================================\n");
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
            if(compareString(lower(getCurrentWord(currentWord)), "a") || compareString(lower(getCurrentWord(currentWord)),"d") || compareString(lower(getCurrentWord(currentWord)),"s") || compareString(lower(getCurrentWord(currentWord)),"w")){
                if(Info(Next(First(Snake))).x == mod(Info(First(Snake)).x + 1,5) && Info(Next(First(Snake))).y == Info(First(Snake)).y){
                    if(!compareString(lower(getCurrentWord(currentWord)), "d")){
                        input_valid = true;           
                    }
                }
                else if(Info(Next(First(Snake))).x == mod(Info(First(Snake)).x - 1,5) && Info(Next(First(Snake))).y == Info(First(Snake)).y){
                    if(!compareString(lower(getCurrentWord(currentWord)), "a")){
                        input_valid = true;   
                    }
                }
                else if(Info(Next(First(Snake))).y == mod(Info(First(Snake)).y + 1,5) && Info(Next(First(Snake))).x == Info(First(Snake)).x){
                    if(!compareString(lower(getCurrentWord(currentWord)), "s")){
                        input_valid = true;
                    }
                }
                else if(Info(Next(First(Snake))).y == mod(Info(First(Snake)).y - 1,5) && Info(Next(First(Snake))).x == Info(First(Snake)).x){
                    if(!compareString(lower(getCurrentWord(currentWord)), "w")){
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

        if(compareString(lower(getCurrentWord(currentWord)),"w")){
            if(First(Snake)->info.y - 1 == Meteor.y && First(Snake)->info.x == Meteor.x && meteorhot && turn-temp == 1){
                printf("Meteor masih panas! Anda belum dapat kembali ke titik tersebut.\n");
                printf("Silahkan masukkan command lainnya\n\n");
            }
            else{
                meteorhot = false;
                temp = -999;
            }
        }
        else if(compareString(lower(getCurrentWord(currentWord)),"a")){
            if(First(Snake)->info.x - 1 == Meteor.x && First(Snake)->info.y == Meteor.y && meteorhot && turn-temp == 1){
                printf("Meteor masih panas! Anda belum dapat kembali ke titik tersebut.\n");
                printf("Silahkan masukkan command lainnya\n\n");
            }
            else{
                meteorhot = false;
                temp = -999;
            }
        }
        else if(compareString(lower(getCurrentWord(currentWord)),"d")){
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
            if(compareString(lower(getCurrentWord(currentWord)),"w")){
                ORDINAT(Info(First(Snake))) = mod(move(Info(First(Snake)),0,-1).y,5);
            }
            else if(compareString(lower(getCurrentWord(currentWord)),"s")){
                ORDINAT(Info(First(Snake))) = mod(move(Info(First(Snake)),0,1).y,5);
            }
            else if(compareString(lower(getCurrentWord(currentWord)),"a")){
                ABSIS(Info(First(Snake))) = mod(move(Info(First(Snake)),-1,0).x,5);
            }
            else{
                ABSIS(Info(First(Snake))) = mod(move(Info(First(Snake)),1,0).x,5);
            }

            address p = Next(First(Snake));
            while (p!=NULL)
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
                if(Search_LL(Snake,CreatePoint(mod((Last(Snake)->info.x - 1),5), Last(Snake)->info.y))==NULL && !(Obstacle.x == mod((Last(Snake)->info.x - 1),5) && Obstacle.y == Last(Snake)->info.y) && !(Meteor.x == mod((Last(Snake)->info.x - 1),5) && Meteor.y == Last(Snake)->info.y)){
                    InsVLast_LL(&Snake,CreatePoint(mod((Last(Snake)->info.x - 1),5), Last(Snake)->info.y));
                    while (Search_LL(Snake,Food) != NULL || (Food.x == Obstacle.x && Food.y == Obstacle.y))
                    {
                        Food = CreatePoint(randomNumber(0,4),randomNumber(0,4));
                    }
                }
                else if(Search_LL(Snake,CreatePoint(Last(Snake)->info.x, mod((Last(Snake)->info.y - 1),5))) == NULL && !(Obstacle.x == Last(Snake)->info.x && Obstacle.y == mod((Last(Snake)->info.y - 1),5)) && !(Meteor.x == Last(Snake)->info.x && Meteor.y == mod((Last(Snake)->info.y - 1),5))){
                    InsVLast_LL(&Snake,CreatePoint(Last(Snake)->info.x, mod((Last(Snake)->info.y - 1),5)));
                    while (Search_LL(Snake,Food) != NULL || (Food.x == Obstacle.x && Food.y == Obstacle.y))
                    {
                        Food = CreatePoint(randomNumber(0,4),randomNumber(0,4));
                    }
                }
                else if(Search_LL(Snake,CreatePoint(Last(Snake)->info.x, mod((Last(Snake)->info.y + 1),5))) == NULL && !(Obstacle.x == Last(Snake)->info.x && Obstacle.y == mod((Last(Snake)->info.y + 1),5)) && !(Meteor.x == Last(Snake)->info.x && Meteor.y == mod((Last(Snake)->info.y + 1),5))){
                    InsVLast_LL(&Snake,CreatePoint(Last(Snake)->info.x, mod((Last(Snake)->info.y + 1),5)));
                    while (Search_LL(Snake,Food) != NULL || (Food.x == Obstacle.x && Food.y == Obstacle.y))
                    {
                        Food = CreatePoint(randomNumber(0,4),randomNumber(0,4));
                    }
                }
                else if(Search_LL(Snake,CreatePoint(mod((Last(Snake)->info.x + 1),5), Last(Snake)->info.y)) == NULL && !(Obstacle.x == mod((Last(Snake)->info.x + 1),5) && Obstacle.y == Last(Snake)->info.y) && !(Meteor.x == mod((Last(Snake)->info.x + 1),5) && Meteor.y == Last(Snake)->info.y)){
                    InsVLast_LL(&Snake,CreatePoint(mod((Last(Snake)->info.x + 1),5), Last(Snake)->info.y));
                    while (Search_LL(Snake,Food) != NULL || (Food.x == Obstacle.x && Food.y == Obstacle.y))
                    {
                        Food = CreatePoint(randomNumber(0,4),randomNumber(0,4));
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
                Meteor = CreatePoint(randomNumber(0,4),randomNumber(0,4));
                while (Meteor.x == Food.x && Meteor.y == Food.y)
                {
                    Meteor = CreatePoint(randomNumber(0,4),randomNumber(0,4));
                }
                printf("Berhasil bergerak!\n");
                printf("Berikut merupakan peta permainan:\n");
                PrintArena(Snake,Meteor,Obstacle,Food);
                printf("\n");
                if(Search_LL(Snake,Meteor)!=NULL){
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
            printf("\n");
        }
    }
    printf("==================================== GAME BERAKHIR ====================================\n");
    printf("Skor akhir: %d\n",NbElmt_LL(Snake)*2);
    return NbElmt_LL(Snake)*2;
}
