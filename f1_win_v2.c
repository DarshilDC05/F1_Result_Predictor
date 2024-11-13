#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>

//team pointer

/*
Driver Parameters:
    Number
    Start
    Management
    Pace
    Awarness
    Team
    Grid Position
    Rating
    Points
    Crash Probablity Parameter

Team Parameters:
    Name
    Rank
    Strategy
    Pitstops
    Car
    Points
    Reliability

Ranks:
1. RedBull
2. Mercedes
3. Ferrari
4. Mclaren
5. Aston Martin
6. Alpine
7. Williams
8. Alfa
9. Alphatauri
10. Haas
*/

typedef enum{VER = 1, SAR = 2, RIC = 3, NOR = 4, GAS = 10, PER = 11, ALO = 14, LEC = 16, STR = 18, MAG = 20, TSU = 22, ALB = 23, ZHO = 24, HUL = 27, OCO = 31, HAM = 44, SAI = 55, RUS = 63, BOT = 77, PIA = 81} d_num;
typedef enum{RB = 1, AMG = 2, SF = 3, MCL = 4, AMR = 5, ALP = 6, WIL = 7, SAU = 8, TOR = 9, HAS = 10} t_num;

struct team{
    char name[15];
    int strategy;
    int pitstops;
    int car;
    t_num rank;
    int points;
    int reliability;
};


typedef struct team * TEAM;

struct driver{
    char tag[4];
    char name[20];
    d_num num;
    int start;
    int management;
    int pace;
    int awarness;
    int grid_pos;
    TEAM tm; 
    int rating;
    int points;
    int crash_rating;
 };


typedef struct driver * DRIVER;

TEAM team_data();
DRIVER driver_data(TEAM team_list);
void predict(DRIVER grid, TEAM team_list);
int d_rate(DRIVER d1);
int t_rate(DRIVER d1);


void main(){
    // printf("%d\n", sizeof(struct team));
    printf("Welcome to F1 result predictor v2!\n\n");
    TEAM team_list = team_data();
    DRIVER grid = driver_data(team_list);
    char grid_list[20][4];
    printf("Enter the starting grid to simulate the results:\nNOTE : Enter the three letter driver tags.\n");
    // printf("\n\nDriver List :\n\n");
    // printf("RedBull :\tMax Verstappen\t\tVER\n\t\tSergio Perez\t\tPER\n\n");
    // printf("Mercedes :\tLewis Hamilton\t\tHAM\n\t\tGeorge Russell\t\tRUS\n\n");
    // printf("Ferrari :\tCharles LecLerc\t\tLEC\n\t\tCarlos Sainz\t\tSAI\n\n");
    // printf("McLaren :\tLando Norris\t\tNOR\n\t\tOscar Piastri\t\tPIA\n\n");
    // printf("Aston Martin :\tFernando Alonso\t\tALO\n\t\tLance Stroll\t\tSTR\n\n");
    for(int i=0; i<20; i++){
        printf("%d. ", i+1);
        scanf("%s", grid_list[i]);   
        for(int j=0; j<20; j++){
            if(strcmp(grid_list[i], grid[j].tag) == 0){
                grid[j].grid_pos = i+1;
                if(i<9){
                    printf("   %s\n\n", grid[j].name);
                }
                else{
                    printf("    %s\n\n", grid[j].name);
                }
            }
        }
    }


    // printf("Here\n");
    // for(int j=0; j<20; j++){
    //     printf("%d. %d - %d\n",j+1 , grid[j].num, grid[j].grid_pos);
    // }

    printf("\n\n");
    predict(grid, team_list);
    sleep(10000);
}

TEAM team_data(){
    TEAM team_list = (TEAM) malloc(10 * sizeof(struct team));

    //Team Data

    //RedBull
    strcpy(team_list[0].name, "RedBull");
    team_list[0].rank = 1;
    team_list[0].car = 95;
    team_list[0].strategy = 90;
    team_list[0].pitstops = 90;
    team_list[0].points = 0;
    team_list[0].reliability = 17;

    //Mercedes
    strcpy(team_list[1].name, "Mercedes");
    team_list[1].rank = 2;
    team_list[1].car = 90;
    team_list[1].strategy = 90;
    team_list[1].pitstops = 86;
    team_list[1].points = 0;
    team_list[1].reliability = 21;

    //Ferrari
    strcpy(team_list[2].name, "Ferrari");
    team_list[2].rank = 3;
    team_list[2].car = 93;
    team_list[2].strategy = 80;
    team_list[2].pitstops = 84;
    team_list[2].points = 0;
    team_list[2].reliability = 15;

    //Mclaren
    strcpy(team_list[3].name, "McLaren");
    team_list[3].rank = 4;
    team_list[3].car = 92;
    team_list[3].strategy = 85;
    team_list[3].pitstops = 90;
    team_list[3].points = 0;
    team_list[3].reliability = 17;

    //Aston Martin
    strcpy(team_list[4].name, "Aston Martin");
    team_list[4].rank = 5;
    team_list[4].car = 87;
    team_list[4].strategy = 85;
    team_list[4].pitstops = 80;
    team_list[4].points = 0;
    team_list[4].reliability = 15;

    //Alpine
    strcpy(team_list[5].name, "Alpine");
    team_list[5].rank = 6;
    team_list[5].car = 82;
    team_list[5].strategy = 85;
    team_list[5].pitstops = 80;
    team_list[5].points = 0;
    team_list[5].reliability = 11;

    //Williams
    strcpy(team_list[6].name, "Williams");
    team_list[6].rank = 7;
    team_list[6].car = 70;
    team_list[6].strategy = 85;
    team_list[6].pitstops = 85;
    team_list[6].points = 0;
    team_list[6].reliability = 16;

    //Sauber
    strcpy(team_list[7].name, "Sauber");
    team_list[7].rank = 8;
    team_list[7].car = 75;
    team_list[7].strategy = 75;
    team_list[7].pitstops = 80;
    team_list[7].points = 0;
    team_list[7].reliability = 16;

    //Alphatauri
    strcpy(team_list[8].name, "Alphatauri");
    team_list[8].rank = 9;
    team_list[8].car = 75;
    team_list[8].strategy = 80;
    team_list[8].pitstops = 80;
    team_list[8].points = 0;
    team_list[8].reliability = 13;

    //Haas
    strcpy(team_list[9].name, "Haas ");
    team_list[9].rank = 10;
    team_list[9].car = 75;
    team_list[9].strategy = 75;
    team_list[9].pitstops = 75;
    team_list[9].points = 0;
    team_list[9].reliability = 11;

    return team_list;

}


DRIVER driver_data(TEAM team_list){
    DRIVER driver_list = (DRIVER) malloc(20 * sizeof(struct driver));

    
    //Driver data

    //Max Verstappen
    strcpy(driver_list[0].name, "Max Verstappen");
    strcpy(driver_list[0].tag, "VER");
    driver_list[0].num = 1;
    driver_list[0].tm = team_list;
    driver_list[0].start = 95;
    driver_list[0].pace = 95;
    driver_list[0].management = 95;
    driver_list[0].awarness = 95;
    driver_list[0].grid_pos = 20;
    driver_list[0].rating = 0;
    driver_list[0].points = 0;
    driver_list[0].crash_rating = 20;


    //Sergio Perez
    strcpy(driver_list[1].name, "Sergio Perez");
    strcpy(driver_list[1].tag, "PER");
    driver_list[1].num = 11;
    driver_list[1].tm = team_list;
    driver_list[1].start = 85;
    driver_list[1].pace = 85;
    driver_list[1].management = 95;
    driver_list[1].awarness = 90;
    driver_list[1].grid_pos = 20;
    driver_list[1].rating = 0;
    driver_list[1].points = 0;
    driver_list[1].crash_rating = 13;

    //Lewis Hamilton
    strcpy(driver_list[2].name, "Lewis Hamilton");
    strcpy(driver_list[2].tag, "HAM");
    driver_list[2].num = 44;
    driver_list[2].tm = team_list + 1;
    driver_list[2].start = 90;
    driver_list[2].pace = 95;
    driver_list[2].management = 95;
    driver_list[2].awarness = 95;
    driver_list[2].grid_pos = 20;
    driver_list[2].rating = 0;
    driver_list[2].points = 0;
    driver_list[2].crash_rating = 20;

    //George Russell
    strcpy(driver_list[3].name, "George Russell");
    strcpy(driver_list[3].tag, "RUS");
    driver_list[3].num = 63;
    driver_list[3].tm = team_list + 1;
    driver_list[3].start = 90;
    driver_list[3].pace = 91;
    driver_list[3].management = 93;
    driver_list[3].awarness = 80;
    driver_list[3].grid_pos = 20;
    driver_list[3].rating = 0;
    driver_list[3].points = 0;
    driver_list[3].crash_rating = 12;

    //Charles Leclerc
    strcpy(driver_list[4].name, "Charles Leclerc");
    strcpy(driver_list[4].tag, "LEC");
    driver_list[4].num = 16;
    driver_list[4].tm = team_list + 2;
    driver_list[4].start = 90;
    driver_list[4].pace = 95;
    driver_list[4].management = 87;
    driver_list[4].awarness = 90;
    driver_list[4].grid_pos = 20;
    driver_list[4].rating = 0;
    driver_list[4].points = 0;
    driver_list[4].crash_rating = 15;

    //Carlos Sainz
    strcpy(driver_list[5].name, "Carlos Sainz");
    strcpy(driver_list[5].tag, "SAI");
    driver_list[5].num = 55;
    driver_list[5].tm = team_list + 2;
    driver_list[5].start = 85;
    driver_list[5].pace = 90;
    driver_list[5].management = 95;
    driver_list[5].awarness = 95;
    driver_list[5].grid_pos = 20;
    driver_list[5].rating = 0;
    driver_list[5].points = 0;
    driver_list[5].crash_rating = 17;

    //Lando Norris
    strcpy(driver_list[6].name, "Lando Norris");
    strcpy(driver_list[6].tag, "NOR");
    driver_list[6].num = 4;
    driver_list[6].tm = team_list + 3;
    driver_list[6].start = 85;
    driver_list[6].pace = 95;
    driver_list[6].management = 95;
    driver_list[6].awarness = 95;
    driver_list[6].grid_pos = 20;
    driver_list[6].rating = 0;
    driver_list[6].points = 0;
    driver_list[6].crash_rating = 18;

    //Oscar Piastri
    strcpy(driver_list[7].name, "Oscar Piastri");
    strcpy(driver_list[7].tag, "PIA");
    driver_list[7].num = 81;
    driver_list[7].tm = team_list + 3;
    driver_list[7].start = 85;
    driver_list[7].pace = 90;
    driver_list[7].management = 85;
    driver_list[7].awarness = 90;
    driver_list[7].grid_pos = 20;
    driver_list[7].rating = 0;
    driver_list[7].points = 0;
    driver_list[7].crash_rating = 15;

    //Fernando Alonso
    strcpy(driver_list[8].name, "Fernando Alonso");
    strcpy(driver_list[8].tag, "ALO");
    driver_list[8].num = 14;
    driver_list[8].tm = team_list + 4;
    driver_list[8].start = 95;
    driver_list[8].pace = 95;
    driver_list[8].management = 95;
    driver_list[8].awarness = 95;
    driver_list[8].grid_pos = 20;
    driver_list[8].rating = 0;
    driver_list[8].points = 0;
    driver_list[8].crash_rating = 20;

    //Lance Stroll
    strcpy(driver_list[9].name, "Lance Stroll");
    strcpy(driver_list[9].tag, "STR");
    driver_list[9].num = 18;
    driver_list[9].tm = team_list + 4;
    driver_list[9].start = 85;
    driver_list[9].pace = 80;
    driver_list[9].management = 85;
    driver_list[9].awarness = 80;
    driver_list[9].grid_pos = 20;
    driver_list[9].rating = 0;
    driver_list[9].points = 0;
    driver_list[9].crash_rating = 11;

    //Estaban Ocon
    strcpy(driver_list[10].name, "Estaban Ocon");
    strcpy(driver_list[10].tag, "OCO");
    driver_list[10].num = 31;
    driver_list[10].tm = team_list + 5;
    driver_list[10].start = 85;
    driver_list[10].pace = 85;
    driver_list[10].management = 85;
    driver_list[10].awarness = 80;
    driver_list[10].grid_pos = 20;
    driver_list[10].rating = 0;
    driver_list[10].points = 0;
    driver_list[10].crash_rating = 15;

    //Pierre Gasly
    strcpy(driver_list[11].name, "Pierre Gasly");
    strcpy(driver_list[11].tag, "GAS");
    driver_list[11].num = 10;
    driver_list[11].tm = team_list + 5;
    driver_list[11].start = 85;
    driver_list[11].pace = 85;
    driver_list[11].management = 85;
    driver_list[11].awarness = 85;
    driver_list[11].grid_pos = 20;
    driver_list[11].rating = 0;
    driver_list[11].points = 0;
    driver_list[11].crash_rating = 15;

    //Alexander Albon
    strcpy(driver_list[12].name, "Alexander Albon");
    strcpy(driver_list[12].tag, "ALB");
    driver_list[12].num = 23;
    driver_list[12].tm = team_list + 6;
    driver_list[12].start = 85;
    driver_list[12].pace = 90;
    driver_list[12].management = 95;
    driver_list[12].awarness = 90;
    driver_list[12].grid_pos = 20;
    driver_list[12].rating = 0;
    driver_list[12].points = 0;
    driver_list[12].crash_rating = 17;

    //Logan Sargeant
    strcpy(driver_list[13].name, "Logan Sargeant");
    strcpy(driver_list[13].tag, "SAR");
    driver_list[13].num = 2;
    driver_list[13].tm = team_list + 6;
    driver_list[13].start = 80;
    driver_list[13].pace = 80;
    driver_list[13].management = 80;
    driver_list[13].awarness = 75;
    driver_list[13].grid_pos = 20;
    driver_list[13].rating = 0;
    driver_list[13].points = 0;
    driver_list[13].crash_rating = 11;

    //Valtteri Bottas
    strcpy(driver_list[14].name, "Valtteri Bottas");
    strcpy(driver_list[14].tag, "BOT");
    driver_list[14].num = 77;
    driver_list[14].tm = team_list + 7;
    driver_list[14].start = 80;
    driver_list[14].pace = 85;
    driver_list[14].management = 90;
    driver_list[14].awarness = 95;
    driver_list[14].grid_pos = 20;
    driver_list[14].rating = 0;
    driver_list[14].points = 0;
    driver_list[14].crash_rating = 16;

    //Zhou Guanyu
    strcpy(driver_list[15].name, "Zhou Guanyu");
    strcpy(driver_list[15].tag, "ZHO");
    driver_list[15].num = 24;
    driver_list[15].tm = team_list + 7;
    driver_list[15].start = 80;
    driver_list[15].pace = 80;
    driver_list[15].management = 80;
    driver_list[15].awarness = 80;
    driver_list[15].grid_pos = 20;
    driver_list[15].rating = 0;
    driver_list[15].points = 0;
    driver_list[15].crash_rating = 13;

    //Daniel Ricciardo
    strcpy(driver_list[16].name, "Daniel Ricciardo");
    strcpy(driver_list[16].tag, "RIC");
    driver_list[16].num = 3;
    driver_list[16].tm = team_list + 8;
    driver_list[16].start = 85;
    driver_list[16].pace = 85;
    driver_list[16].management = 85;
    driver_list[16].awarness = 90;
    driver_list[16].grid_pos = 20;
    driver_list[16].rating = 0;
    driver_list[16].points = 0;
    driver_list[16].crash_rating = 17;

    //Yuki Tsunoda
    strcpy(driver_list[17].name, "Yuki Tsunoda");
    strcpy(driver_list[17].tag, "TSU");
    driver_list[17].num = 22;
    driver_list[17].tm = team_list + 8;
    driver_list[17].start = 90;
    driver_list[17].pace = 85;
    driver_list[17].management = 85;
    driver_list[17].awarness = 80;
    driver_list[17].grid_pos = 20;
    driver_list[17].rating = 0;
    driver_list[17].points = 0;
    driver_list[17].crash_rating = 15;

    //Nico Hulkenberg
    strcpy(driver_list[18].name, "Nico Hulkenberg");
    strcpy(driver_list[18].tag, "HUL");
    driver_list[18].num = 27;
    driver_list[18].tm = team_list + 9;
    driver_list[18].start = 90;
    driver_list[18].pace = 80;
    driver_list[18].management = 75;
    driver_list[18].awarness = 95;
    driver_list[18].grid_pos = 20;
    driver_list[18].rating = 0;
    driver_list[18].points = 0;
    driver_list[18].crash_rating = 15;

    //Kevin Magnussen
    strcpy(driver_list[19].name, "Kevin Magnussen");
    strcpy(driver_list[19].tag, "MAG");
    driver_list[19].num = 20;
    driver_list[19].tm = team_list + 9;
    driver_list[19].start = 85;
    driver_list[19].pace = 85;
    driver_list[19].management = 75;
    driver_list[19].awarness = 80;
    driver_list[19].grid_pos = 20;
    driver_list[19].rating = 0;
    driver_list[19].points = 0;
    driver_list[19].crash_rating = 11;

    return driver_list;

}

void predict(DRIVER grid, TEAM team_list){
    int chaos_factor;
    printf("On a scale of 1 to 10, how chaotic do you expect the Race to be?\nWith 1 being very calm and 10 being very chotic (like more than Germany 2019)\n");
    scanf("%d", &chaos_factor);
    printf("\n\n");
    srand(time(0));
    for(int i=0; i<20; i++){
        grid[i].rating = (d_rate(grid+i) + t_rate(grid+i));
        // srand(time(0));

        // printf("%d\n", grid[i].crash_rating);
        int d_skill = grid[i].crash_rating - chaos_factor + 1;
        int d_crash = rand()%d_skill;
        if(d_crash == 0){
            d_crash = 1;
        }
        // printf("%d - %d\n", grid[i].num, d_crash);
        int c_broke = rand()%grid[i].tm->reliability;
        // printf("%d - %d\n", grid[i].num, d_crash);
        if(d_crash == 1){
            grid[i].rating = 0;
        }
        if(c_broke == 1){
            grid[i].rating = 0;
        }
    }
    for(int i=0; i<20; i++){
        for(int j=i+1; j<20; j++){
            if(grid[j].rating > grid[i].rating){
                struct driver temp = grid[i];
                grid[i] = grid[j];
                grid[j] = temp;
            }
        }
    }
    for(int i=0; i<10; i++){
        switch(i){
            case 0  :grid[i].points = 25;
                        break;
            case 1  :grid[i].points = 18;
                        break;
            case 2  :grid[i].points = 15;
                        break;
            case 3  :grid[i].points = 12;
                        break; 
            case 4  :grid[i].points = 10;
                        break;      
            case 5  :grid[i].points = 8;
                        break;     
            case 6  :grid[i].points = 6;
                        break;
            case 7  :grid[i].points = 4;
                        break;
            case 8  :grid[i].points = 2;
                        break;
            case 9  :grid[i].points = 1;
                        break;
            default :grid[i].points = 0;
                        break;
        }
    }
    for(int i=0; i<20; i++){
        grid[i].tm->points += grid[i].points;
    }
    for(int i=0; i<10; i++){
        for(int j=i+1; j<10; j++){
            if(team_list[i].points < team_list[j].points){
                struct team temp = team_list[i];
                team_list[i] = team_list[j];
                team_list[j] = temp;
            }
        }
    }
    printf("Final Positions:\n");
    // for(int i=0; i<20; i++){
    //     printf("%d. %s   \t\t(%d)\t%d Points\t- %d\n",i+1, grid[i].name, grid[i].num, grid[i].points, grid[i].rating);
    // }


    int j=0;
    while(grid[j].rating != 0){
        printf("%d. %s   \t\t(%d)\t%d Points\t- %d\n",j+1, grid[j].name, grid[j].num, grid[j].points, grid[j].rating);        
        j++;
    }

    // printf("%d\n", j);

    while(j<20){
        printf("DNF %s   \t\t(%d)\t%d Points\t- %d\n", grid[j].name, grid[j].num, grid[j].points, grid[j].rating);
        j++;
    }


    printf("\n\nTeam Standings:\n");
    for(int i=0; i<10; i++){
        printf("%d. %s        \t- %d Points\n", i+1, team_list[i].name, team_list[i].points);
    }
}

int d_rate(DRIVER d1){
    int d_rating = (100 - (d1->grid_pos*5)) + d1->pace + d1->start + d1->management + d1->awarness;
    return d_rating;
}

int t_rate(DRIVER d1){
    int t_rating = (3*(d1->tm->car)) + d1->tm->strategy + d1->tm->pitstops;
    return t_rating;
}