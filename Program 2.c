void playchessgame(){

        char wmove[8]={"0"};
        char bmove[8]={"0"};
        int gameinplay =0;
        char movehistory[650]={"0"};
        char gamehistory[950]={"0"};
        char mate[]={"mate"};

        while(gameinplay==0){

        printf("\nWhite to play.Enter move:\n");
        scanf("%s",wmove);
        if(strcmp(wmove,mate)== 0){
            printf("Game over CHECKMATE\n");
            break;
        }

        printf("Black to play.Enter move:\n");
        scanf("%s",bmove);
        if(strcmp(bmove,mate)== 0){
            printf("Game over CHECKMATE\n");
            break;
        }

        strcat(wmove,bmove);
        strcpy(movehistory,wmove);
        strcat(gamehistory,movehistory);
        printf("\n");
        printf("%s",gamehistory);
    }
        return 0;
    };
