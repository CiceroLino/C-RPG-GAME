#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <math.h>
#include <locale.h>
#include <string.h>
#include <time.h>




// VARIABLES
int godmode = 0; // GAMEMODE
char gamestarter[10], nome[20], startroll[10], invname[20] = "INVENTARIO", itemchoice[15], chinventory; // names - ROLLS & CHOICES
int numroll, choices, invuse; // numbers - ROLLS & CHOICES
int a, b, c = 1, i, loop = 0, luckloop = 0, jeweloop = 0; length, columns, rows; // DESIGN
int provisions = 10, gold, hability = 99, first_hability, energy = 99, first_energy, luck = 99, first_luck, dards; // STATUS POINTS

int hability_potion = 0, luck_potion = 0, energy_potion = 0, jewel = 0, emerald = 0, sapphire = 0, iron_hook = 0, iron_key = 0, wood_tube = 0, rope = 0, metal_bell = 0, brass_bell = 0, chalice = 0, morph_potion = 0, leather_wristband = 0, monkey_amulet = 0, dagger = 0, ruby = 0, topaz = 0, wooden_legs = 0, old_bone = 0, shield = 0, wish_ring = 0, moringa_acid = 0, diamond = 0, grenade = 0, energy_ring = 0; // ITENS

int read_skeleton_scroll = 0, high_temperature_potion = 0, knowledge_morph_potion = 0, knowledge_bloody_beast = 0, skill_trap_potion = 0, knowledge_deadgirl_poem = 0, disarmed = 0;// SKILLS AND KNOWLEDGE

int status_OP006 = 0, status_OP226 = 0, status_OP162 = 0, status_OP257 = 0, status_OP150 = 0, status_OP011 = 0, status_OP020 = 0, status_OP028 = 0, status_OP033 = 0, status_OP052 = 0, status_OP171 = 0, status_OP244 = 0, status_OP256 = 0, status_OP094 = 0, status_OP095 = 0, status_OP105 = 0, status_OP106 = 0, status_OP114 = 0, status_OP123 = 0, status_OP147 = 0, status_OP157 = 0, status_OP169 = 0, status_OP175 = 0, status_OP229 = 0, status_OP240 = 0, status_OP251 = 0, status_OP270 = 0, status_OP285 = 0, status_OP308 = 0, status_OP337 = 0, status_OP363 = 0, status_OP375 = 0, status_OP391 = 0, status_OP397 = 0, status_OP026 = 0, status_OP038 = 0, status_OP042 = 0, status_OP045 = 0, status_OP072 = 0, status_OP057 = 0, status_OP103 = 0, status_OP158 = 0, status_OP165 = 0, status_OP167 = 0, status_OP341 = 0, status_OP269 = 0, status_OP330 = 0, status_OP336 = 0, status_OP127 = 0, status_OP115 = 0; //status no repating variables

// COMBAT VARIABLES
int combatloop = 0, combatloop2 = 0, defenseloop = 0, monsenergy, monsenergy2, monshability, monshability2, damagemonster, damagemonster2, numrollmonster, playerhabil, monschoice, fight1, fight2, atkseries;
char combatroll[8], luckhit[5];

// SAVE VARIABLES
int stageops;

// COLORS
void colors(){
    system("COLOR 0A");
    printf("\033[1;30m a"); // BLACK
    printf("\033[1;31m a"); // RED
    printf("\033[1;32m a"); // GREEN
    printf("\033[1;33m a"); // YELLOW
    printf("\033[1;34m a"); // BLUE
    printf("\033[1;35m a"); // PURPLE
    printf("\033[1;36m a"); // CYAN
    printf("\033[0;37m a"); // WHITE
    system("cls");
}

// SAVING PROCESS
void save(){
    FILE * fSave;

    fSave = fopen("save.txt", "w");
    
    fprintf(fSave, "ITENS: %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n", hability_potion, luck_potion, energy_potion, jewel, emerald, sapphire, iron_hook, iron_key, wood_tube, rope, metal_bell, brass_bell, chalice, morph_potion, leather_wristband, monkey_amulet, dagger, ruby, topaz, wooden_legs, old_bone, shield, wish_ring, moringa_acid, diamond, grenade, energy_ring); // ITENS

    fprintf(fSave, "STATUS: %d %d %d %d %d\n", energy, hability, provisions, luck, gold); // STATUS

    fprintf(fSave, "stageops: %d\n", stageops);

    fprintf(fSave, "godmode: %d\n", godmode);

    fprintf(fSave, "NAME: %s\n", nome); // NAME

    fprintf(fSave, "NO-REPEATING: %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n", status_OP006, status_OP226, status_OP162, status_OP257, status_OP150, status_OP011, status_OP020, status_OP028, status_OP033, status_OP052, status_OP171, status_OP244 , status_OP256, status_OP094, status_OP095, status_OP105, status_OP106, status_OP114, status_OP123, status_OP147, status_OP157, status_OP169, status_OP175, status_OP229, status_OP240, status_OP251, status_OP270, status_OP285, status_OP308, status_OP337, status_OP363, status_OP375, status_OP391, status_OP397, status_OP026, status_OP038, status_OP042, status_OP045, status_OP072, status_OP057, status_OP103, status_OP158, status_OP165, status_OP167, status_OP341, status_OP269, status_OP330, status_OP336, status_OP127, status_OP115); // no repeating

    fprintf(fSave, "SKILLS:%d %d %d %d %d %d %d\n", read_skeleton_scroll, high_temperature_potion, knowledge_morph_potion, knowledge_bloody_beast, skill_trap_potion, knowledge_deadgirl_poem, disarmed);


    fclose(fSave);
}
// SAVE GAME LOAD
void load(){

    FILE * fSave;


    fSave = fopen(".save.txt", "r");

    fscanf(fSave, "ITENS: %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n", &hability_potion, &luck_potion, &energy_potion, &jewel, &emerald, &sapphire, &iron_hook, &iron_key, &wood_tube, &rope, &metal_bell, &brass_bell, &chalice, &morph_potion, &leather_wristband, &monkey_amulet, &dagger, &ruby, &topaz, &wooden_legs, &old_bone, &shield, &wish_ring, &moringa_acid, &diamond, &grenade, &energy_ring); // ITENS

    fscanf(fSave, "STATUS: %d %d %d %d %d\n", &energy, &hability, &provisions, &luck, &gold); // STATUS

    fscanf(fSave, "stageops: %d\n", &stageops);

    fscanf(fSave, "godmode: %d\n", &godmode);

    fscanf(fSave, "NAME: %s\n", &nome); // NAME

    fscanf(fSave, "NO-REPEATING: %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n", &status_OP006, &status_OP226, &status_OP162, &status_OP257, &status_OP150, &status_OP011, &status_OP020, &status_OP028, &status_OP033, &status_OP052, &status_OP171, &status_OP244 , &status_OP256, &status_OP094, &status_OP095, &status_OP105, &status_OP106, &status_OP114, &status_OP123, &status_OP147, &status_OP157, &status_OP169, &status_OP175, &status_OP229, &status_OP240, &status_OP251, &status_OP270, &status_OP285, &status_OP308, &status_OP337, &status_OP363, &status_OP375, &status_OP391, &status_OP397, &status_OP026, &status_OP038, &status_OP042, &status_OP045, &status_OP072, &status_OP057, &status_OP103, &status_OP158, &status_OP165, &status_OP167, &status_OP341, &status_OP269, &status_OP330, &status_OP336, &status_OP127, &status_OP115); // no repeating


    fscanf(fSave, "SKILLS:%d %d %d %d %d %d %d\n", &read_skeleton_scroll, &high_temperature_potion, &knowledge_morph_potion, &knowledge_bloody_beast, &skill_trap_potion, &knowledge_deadgirl_poem, &disarmed);

    fclose(fSave);

    printf("\nBem vindo novamente %s\n", nome);
    printf("\033[1;32m\nSKILLS INSTAURADAS");
    printf("\nITENS INSTAURADOS");
    printf("\nSTATUS INSTAURADOS");
    printf("\nEST�GIO: %d\n\033[0;37m", stageops);
    if(stageops == 0){
        printf("\n\nVoc� n�o possui save");
        enter();
        startchar();
    }else if(stageops == 1){
        printf("\n\nVoc� ir� para o est�gio de onde parou");
        enter();
        OP001();
    }else if(stageops == 9){
        printf("\n\nVoc� ir� para o est�gio de onde parou");
        enter();
        OP009();
    }else if(stageops == 10){
        printf("\n\nVoc� ir� para o est�gio de onde parou");
        enter();
        OP010();
    }else if(stageops == 11){
        printf("\n\nVoc� ir� para o est�gio de onde parou");
        enter();
        OP011();
    }else if(stageops == 12){
        printf("\n\nVoc� ir� para o est�gio de onde parou");
        enter();
        OP012();
    }else if(stageops == 13){
        printf("\n\nVoc� ir� para o est�gio de onde parou");
        enter();
        OP013();
    }else if(stageops == 14){
        printf("\n\nVoc� ir� para o est�gio de onde parou");
        enter();
        OP014();
    }else if(stageops == 16){
        printf("\n\nVoc� ir� para o est�gio de onde parou");
        enter();
        OP016();
    }else if(stageops == 22){
        printf("\n\nVoc� ir� para o est�gio de onde parou");
        enter();
        OP022();
    }else if(stageops == 24){
        printf("\n\nVoc� ir� para o est�gio de onde parou");
        enter();
        OP024();
    }else if(stageops == 31){
        printf("\n\nVoc� ir� para o est�gio de onde parou");
        enter();
        OP031();
    }else if(stageops == 35){
        printf("\n\nVoc� ir� para o est�gio de onde parou");
        enter();
        OP035();
    }else if(stageops == 37){
        printf("\n\nVoc� ir� para o est�gio de onde parou");
        enter();
        OP037();
    }else if(stageops == 39){
        printf("\n\nVoc� ir� para o est�gio de onde parou");
        enter();
        OP039();
    }else if(stageops == 41){
        printf("\n\nVoc� ir� para o est�gio de onde parou");
        enter();
        OP041();
    }else if(stageops == 43){
        printf("\n\nVoc� ir� para o est�gio de onde parou");
        enter();
        OP043();
    }else if(stageops == 47){
        printf("\n\nVoc� ir� para o est�gio de onde parou");
        enter();
        OP047();
    }else if(stageops == 49){
        printf("\n\nVoc� ir� para o est�gio de onde parou");
        enter();
        OP049();
    }else if(stageops == 52){
        printf("\n\nVoc� ir� para o est�gio de onde parou");
        enter();
        OP052();
    }else if(stageops == 53){
        printf("\n\nVoc� ir� para o est�gio de onde parou");
        enter();
        OP053();
    }else if(stageops == 55){
        printf("\n\nVoc� ir� para o est�gio de onde parou");
        enter();
        OP055();
    }else if(stageops == 56){
        printf("\n\nVoc� ir� para o est�gio de onde parou");
        enter();
        OP056();
    }else if(stageops == 59){
        printf("\n\nVoc� ir� para o est�gio de onde parou");
        enter();
        OP059();
    }else if(stageops == 60){
        printf("\n\nVoc� ir� para o est�gio de onde parou");
        enter();
        OP060();
    }else if(stageops == 62){
        printf("\n\nVoc� ir� para o est�gio de onde parou");
        enter();
        OP062();
    }else if(stageops == 65){
        printf("\n\nVoc� ir� para o est�gio de onde parou");
        enter();
        OP065();
    }else if(stageops == 66){
        printf("\n\nVoc� ir� para o est�gio de onde parou");
        enter();
        OP066();
    }else if(stageops == 68){
        printf("\n\nVoc� ir� para o est�gio de onde parou");
        enter();
        OP068();
    }else if(stageops == 73){
        printf("\n\nVoc� ir� para o est�gio de onde parou");
        enter();
        OP073();
    }else if(stageops == 74){
        printf("\n\nVoc� ir� para o est�gio de onde parou");
        enter();
        OP074();
    }else if(stageops == 75){
        printf("\n\nVoc� ir� para o est�gio de onde parou");
        enter();
        OP075();
    }else if(stageops == 76){
        printf("\n\nVoc� ir� para o est�gio de onde parou");
        enter();
        OP076();
    }else if(stageops == 78){
        printf("\n\nVoc� ir� para o est�gio de onde parou");
        enter();
        OP078();
    }else if(stageops == 81){
        printf("\n\nVoc� ir� para o est�gio de onde parou");
        enter();
        OP081();
    }else if(stageops == 88){
        printf("\n\nVoc� ir� para o est�gio de onde parou");
        enter();
        OP088();
    }else if(stageops == 90){
        printf("\n\nVoc� ir� para o est�gio de onde parou");
        enter();
        OP090();
    }else if(stageops == 93){
        printf("\n\nVoc� ir� para o est�gio de onde parou");
        enter();
        OP093();
    }else if(stageops == 99){
        printf("\n\nVoc� ir� para o est�gio de onde parou");
        enter();
        OP099();
    }else if(stageops == 100){
        printf("\n\nVoc� ir� para o est�gio de onde parou");
        enter();
        OP100();
    }else if(stageops == 102){
        printf("\n\nVoc� ir� para o est�gio de onde parou");
        enter();
        OP102();
    }else if(stageops == 105){
        printf("\n\nVoc� ir� para o est�gio de onde parou");
        enter();
        OP105();
    }else if(stageops == 107){
        printf("\n\nVoc� ir� para o est�gio de onde parou");
        enter();
        OP107();
    }else if(stageops == 108){
        printf("\n\nVoc� ir� para o est�gio de onde parou");
        enter();
        OP108();
    }else if(stageops == 109){
        printf("\n\nVoc� ir� para o est�gio de onde parou");
        enter();
        OP109();
    }else if(stageops == 110){
        printf("\n\nVoc� ir� para o est�gio de onde parou");
        enter();
        OP110();
    }else if(stageops == 113){
        printf("\n\nVoc� ir� para o est�gio de onde parou");
        enter();
        OP113();
    }else if(stageops == 114){
        printf("\n\nVoc� ir� para o est�gio de onde parou");
        enter();
        OP114();
    }else if(stageops == 117){
        printf("\n\nVoc� ir� para o est�gio de onde parou");
        enter();
        OP117();
    }else if(stageops == 119){
        printf("\n\nVoc� ir� para o est�gio de onde parou");
        enter();
        OP119();
    }else if(stageops == 120){
        printf("\n\nVoc� ir� para o est�gio de onde parou");
        enter();
        OP120();
    }else if(stageops == 121){
        printf("\n\nVoc� ir� para o est�gio de onde parou");
        enter();
        OP121();
    }else if(stageops == 122){
        printf("\n\nVoc� ir� para o est�gio de onde parou");
        enter();
        OP122();
    }else if(stageops == 126){
        printf("\n\nVoc� ir� para o est�gio de onde parou");
        enter();
        OP126();
    }else if(stageops == 128){
        printf("\n\nVoc� ir� para o est�gio de onde parou");
        enter();
        OP128();
    }else if(stageops == 129){
        printf("\n\nVoc� ir� para o est�gio de onde parou");
        enter();
        OP129();
    }else if(stageops == 132){
        printf("\n\nVoc� ir� para o est�gio de onde parou");
        enter();
        OP132();
    }else if(stageops == 134){
        printf("\n\nVoc� ir� para o est�gio de onde parou");
        enter();
        OP134();
    }else if(stageops == 136){
        printf("\n\nVoc� ir� para o est�gio de onde parou");
        enter();
        OP136();
    }else if(stageops == 137){
        printf("\n\nVoc� ir� para o est�gio de onde parou");
        enter();
        OP137();
    }else if(stageops == 138){
        printf("\n\nVoc� ir� para o est�gio de onde parou");
        enter();
        OP138();
    }else if(stageops == 146){
        printf("\n\nVoc� ir� para o est�gio de onde parou");
        enter();
        OP146();
    }else if(stageops == 153){
        printf("\n\nVoc� ir� para o est�gio de onde parou");
        enter();
        OP153();
    }else if(stageops == 155){
        printf("\n\nVoc� ir� para o est�gio de onde parou");
        enter();
        OP155();
    }else if(stageops == 156){
        printf("\n\nVoc� ir� para o est�gio de onde parou");
        enter();
        OP156();
    }else if(stageops == 159){
        printf("\n\nVoc� ir� para o est�gio de onde parou");
        enter();
        OP159();
    }else if(stageops == 163){
        printf("\n\nVoc� ir� para o est�gio de onde parou");
        enter();
        OP163();
    }else if(stageops == 164){
        printf("\n\nVoc� ir� para o est�gio de onde parou");
        enter();
        OP164();
    }else if(stageops == 168){
        printf("\n\nVoc� ir� para o est�gio de onde parou");
        enter();
        OP168();
    }else if(stageops == 170){
        printf("\n\nVoc� ir� para o est�gio de onde parou");
        enter();
        OP170();
    }else if(stageops == 173){
        printf("\n\nVoc� ir� para o est�gio de onde parou");
        enter();
        OP173();
    }else if(stageops == 179){
        printf("\n\nVoc� ir� para o est�gio de onde parou");
        enter();
        OP179();
    }else if(stageops == 182){
        printf("\n\nVoc� ir� para o est�gio de onde parou");
        enter();
        OP182();
    }else if(stageops == 183){
        printf("\n\nVoc� ir� para o est�gio de onde parou");
        enter();
        OP183();
    }else if(stageops == 184){
        printf("\n\nVoc� ir� para o est�gio de onde parou");
        enter();
        OP184();
    }else if(stageops == 185){
        printf("\n\nVoc� ir� para o est�gio de onde parou");
        enter();
        OP185();
    }else if(stageops == 187){
        printf("\n\nVoc� ir� para o est�gio de onde parou");
        enter();
        OP187();
    }else if(stageops == 188){
        printf("\n\nVoc� ir� para o est�gio de onde parou");
        enter();
        OP188();
    }else if(stageops == 192){
        printf("\n\nVoc� ir� para o est�gio de onde parou");
        enter();
        OP192();
    }else if(stageops == 194){
        printf("\n\nVoc� ir� para o est�gio de onde parou");
        enter();
        OP194();
    }else if(stageops == 197){
        printf("\n\nVoc� ir� para o est�gio de onde parou");
        enter();
        OP197();
    }else if(stageops == 200){
        printf("\n\nVoc� ir� para o est�gio de onde parou");
        enter();
        OP200();
    }else if(stageops == 205){
        printf("\n\nVoc� ir� para o est�gio de onde parou");
        enter();
        OP205();
    }else if(stageops == 207){
        printf("\n\nVoc� ir� para o est�gio de onde parou");
        enter();
        OP207();
    }else if(stageops == 210){
        printf("\n\nVoc� ir� para o est�gio de onde parou");
        enter();
        OP210();
    }else if(stageops == 213){
        printf("\n\nVoc� ir� para o est�gio de onde parou");
        enter();
        OP213();
    }else if(stageops == 214){
        printf("\n\nVoc� ir� para o est�gio de onde parou");
        enter();
        OP214();
    }else if(stageops == 216){
        printf("\n\nVoc� ir� para o est�gio de onde parou");
        enter();
        OP216();
    }else if(stageops == 218){
        printf("\n\nVoc� ir� para o est�gio de onde parou");
        enter();
        OP218();
    }else if(stageops == 220){
        printf("\n\nVoc� ir� para o est�gio de onde parou");
        enter();
        OP220();
    }else if(stageops == 221){
        printf("\n\nVoc� ir� para o est�gio de onde parou");
        enter();
        OP221();
    }else if(stageops == 222){
        printf("\n\nVoc� ir� para o est�gio de onde parou");
        enter();
        OP222();
    }else if(stageops == 226){
        printf("\n\nVoc� ir� para o est�gio de onde parou");
        enter();
        OP226();
    }else if(stageops == 230){
        printf("\n\nVoc� ir� para o est�gio de onde parou");
        enter();
        OP230();
    }else if(stageops == 232){
        printf("\n\nVoc� ir� para o est�gio de onde parou");
        enter();
        OP232();
    }else if(stageops == 234){
        printf("\n\nVoc� ir� para o est�gio de onde parou");
        enter();
        OP234();
    }else if(stageops == 237){
        printf("\n\nVoc� ir� para o est�gio de onde parou");
        enter();
        OP237();
    }else if(stageops == 239){
        printf("\n\nVoc� ir� para o est�gio de onde parou");
        enter();
        OP239();
    }else if(stageops == 240){
        printf("\n\nVoc� ir� para o est�gio de onde parou");
        enter();
        OP240();
    }else if(stageops == 241){
        printf("\n\nVoc� ir� para o est�gio de onde parou");
        enter();
        OP241();
    }else if(stageops == 249){
        printf("\n\nVoc� ir� para o est�gio de onde parou");
        enter();
        OP249();
    }else if(stageops == 250){
        printf("\n\nVoc� ir� para o est�gio de onde parou");
        enter();
        OP250();
    }else if(stageops == 258){
        printf("\n\nVoc� ir� para o est�gio de onde parou");
        enter();
        OP258();
    }else if(stageops == 259){
        printf("\n\nVoc� ir� para o est�gio de onde parou");
        enter();
        OP259();
    }else if(stageops == 260){
        printf("\n\nVoc� ir� para o est�gio de onde parou");
        enter();
        OP260();
    }else if(stageops == 262){
        printf("\n\nVoc� ir� para o est�gio de onde parou");
        enter();
        OP262();
    }else if(stageops == 263){
        printf("\n\nVoc� ir� para o est�gio de onde parou");
        enter();
        OP263();
    }else if(stageops == 264){
        printf("\n\nVoc� ir� para o est�gio de onde parou");
        enter();
        OP264();
    }else if(stageops == 267){
        printf("\n\nVoc� ir� para o est�gio de onde parou");
        enter();
        OP267();
    }else if(stageops == 273){
        printf("\n\nVoc� ir� para o est�gio de onde parou");
        enter();
        OP273();
    }else if(stageops == 281){
        printf("\n\nVoc� ir� para o est�gio de onde parou");
        enter();
        OP281();
    }else if(stageops == 282){
        printf("\n\nVoc� ir� para o est�gio de onde parou");
        enter();
        OP282();
    }else if(stageops == 284){
        printf("\n\nVoc� ir� para o est�gio de onde parou");
        enter();
        OP284();
    }else if(stageops == 285){
        printf("\n\nVoc� ir� para o est�gio de onde parou");
        enter();
        OP285();
    }else if(stageops == 287){
        printf("\n\nVoc� ir� para o est�gio de onde parou");
        enter();
        OP287();
    }else if(stageops == 288){
        printf("\n\nVoc� ir� para o est�gio de onde parou");
        enter();
        OP288();
    }else if(stageops == 292){
        printf("\n\nVoc� ir� para o est�gio de onde parou");
        enter();
        OP292();
    }else if(stageops == 293){
        printf("\n\nVoc� ir� para o est�gio de onde parou");
        enter();
        OP293();
    }else if(stageops == 299){
        printf("\n\nVoc� ir� para o est�gio de onde parou");
        enter();
        OP299();
    }else if(stageops == 300){
        printf("\n\nVoc� ir� para o est�gio de onde parou");
        enter();
        OP300();
    }else if(stageops == 301){
        printf("\n\nVoc� ir� para o est�gio de onde parou");
        enter();
        OP301();
    }else if(stageops == 305){
        printf("\n\nVoc� ir� para o est�gio de onde parou");
        enter();
        OP305();
    }else if(stageops == 307){
        printf("\n\nVoc� ir� para o est�gio de onde parou");
        enter();
        OP307();
    }else if(stageops == 308){
        printf("\n\nVoc� ir� para o est�gio de onde parou");
        enter();
        OP308();
    }else if(stageops == 310){
        printf("\n\nVoc� ir� para o est�gio de onde parou");
        enter();
        OP310();
    }else if(stageops == 315){
        printf("\n\nVoc� ir� para o est�gio de onde parou");
        enter();
        OP315();
    }else if(stageops == 316){
        printf("\n\nVoc� ir� para o est�gio de onde parou");
        enter();
        OP316();
    }else if(stageops == 318){
        printf("\n\nVoc� ir� para o est�gio de onde parou");
        enter();
        OP318();
    }else if(stageops == 320){
        printf("\n\nVoc� ir� para o est�gio de onde parou");
        enter();
        OP320();
    }else if(stageops == 321){
        printf("\n\nVoc� ir� para o est�gio de onde parou");
        enter();
        OP321();
    }else if(stageops == 324){
        printf("\n\nVoc� ir� para o est�gio de onde parou");
        enter();
        OP324();
    }else if(stageops == 328){
        printf("\n\nVoc� ir� para o est�gio de onde parou");
        enter();
        OP328();
    }else if(stageops == 330){
        printf("\n\nVoc� ir� para o est�gio de onde parou");
        enter();
        OP330();
    }else if(stageops == 337){
        printf("\n\nVoc� ir� para o est�gio de onde parou");
        enter();
        OP337();
    }else if(stageops == 338){
        printf("\n\nVoc� ir� para o est�gio de onde parou");
        enter();
        OP338();
    }else if(stageops == 339){
        printf("\n\nVoc� ir� para o est�gio de onde parou");
        enter();
        OP339();
    }else if(stageops == 341){
        printf("\n\nVoc� ir� para o est�gio de onde parou");
        enter();
        OP341();
    }else if(stageops == 342){
        printf("\n\nVoc� ir� para o est�gio de onde parou");
        enter();
        OP342();
    }else if(stageops == 343){
        printf("\n\nVoc� ir� para o est�gio de onde parou");
        enter();
        OP343();
    }else if(stageops == 344){
        printf("\n\nVoc� ir� para o est�gio de onde parou");
        enter();
        OP344();
    }else if(stageops == 351){
        printf("\n\nVoc� ir� para o est�gio de onde parou");
        enter();
        OP351();
    }else if(stageops == 352){
        printf("\n\nVoc� ir� para o est�gio de onde parou");
        enter();
        OP352();
    }else if(stageops == 356){
        printf("\n\nVoc� ir� para o est�gio de onde parou");
        enter();
        OP356();
    }else if(stageops == 357){
        printf("\n\nVoc� ir� para o est�gio de onde parou");
        enter();
        OP357();
    }else if(stageops == 360){
        printf("\n\nVoc� ir� para o est�gio de onde parou");
        enter();
        OP360();
    }else if(stageops == 364){
        printf("\n\nVoc� ir� para o est�gio de onde parou");
        enter();
        OP364();
    }else if(stageops == 365){
        printf("\n\nVoc� ir� para o est�gio de onde parou");
        enter();
        OP365();
    }else if(stageops == 367){
        printf("\n\nVoc� ir� para o est�gio de onde parou");
        enter();
        OP367();
    }else if(stageops == 368){
        printf("\n\nVoc� ir� para o est�gio de onde parou");
        enter();
        OP368();
    }else if(stageops == 376){
        printf("\n\nVoc� ir� para o est�gio de onde parou");
        enter();
        OP376();
    }else if(stageops == 379){
        printf("\n\nVoc� ir� para o est�gio de onde parou");
        enter();
        OP379();
    }else if(stageops == 381){
        printf("\n\nVoc� ir� para o est�gio de onde parou");
        enter();
        OP381();
    }else if(stageops == 382){
        printf("\n\nVoc� ir� para o est�gio de onde parou");
        enter();
        OP382();
    }else if(stageops == 385){
        printf("\n\nVoc� ir� para o est�gio de onde parou");
        enter();
        OP385();
    }else if(stageops == 388){
        printf("\n\nVoc� ir� para o est�gio de onde parou");
        enter();
        OP388();
    }else if(stageops == 390){
        printf("\n\nVoc� ir� para o est�gio de onde parou");
        enter();
        OP390();
    }else if(stageops == 392){
        printf("\n\nVoc� ir� para o est�gio de onde parou");
        enter();
        OP392();
    }else if(stageops == 393){
        printf("\n\nVoc� ir� para o est�gio de onde parou");
        enter();
        OP393();
    }else if(stageops == 394){
        printf("\n\nVoc� ir� para o est�gio de onde parou");
        enter();
        OP394();
    }else if(stageops == 396){
        printf("\n\nVoc� ir� para o est�gio de onde parou");
        enter();
        OP396();
    }else if(stageops == 397){
        printf("\n\nVoc� ir� para o est�gio de onde parou");
        enter();
        OP397();
    }
}

// MENU START GAME
void startmenu(){
    loop = 0;

    colors();
    printf("\033[1;37m----------------------------------------------------------------------------------------------------------- A MASMORRA DA MORTE ------------------------------------------------------------------------------------------------------------\033[0;37m");
    printf("                                                                                                        Digite \033[1;35m\"START\"\033[0;37m para come�ar                                                                                                         \n");
    printf("                                                                                                         Digite \033[1;35m\"LOAD\"\033[0;37m para carregar                                                                                                         \n");

    printf("                                                                                                                      ");
    while(loop<1){
        gets(gamestarter);
        if(strcasecmp(gamestarter, "start") == 0){
            printf("\n\tNo interior do labirinto escuro e sinuoso de Fang h� horrores desconhecidos � sua espera. Concebido pela mente diab�lica do bar�o Sukumvit, o labirinto est� infestado de armadilhas mortais e monstros sedentos sangue, os quais submeter�o SUAS habilidades a testes quase al�m do limite poss�vel de resist�ncia. In�meros aventureiros aceitaram o desafio da \"Prova dos Campe�es\" e atravessaram a porta talhada em forma de boca do labirinto para nunca mais voltar. VOC� se atreve a entrar?\n\tTentado pela promessa de um pr�mio fabuloso, e pelo fasc�nio do desafio nunca superado, VOC� est� entre os seis guerreiros experientes que se preparam para enfrentar o labirinto. Somente um pode chegar � sa�da e vencer, os demais perecer�o... \033[1;33mPor fim, diga-me aventureiro, quem � voc�?\033[0;37m");
            loop++;
        }
        if(strcasecmp(gamestarter, "load") == 0){
            loop++;
            printf("LOAD CARREGADO COM SUCESSO\n");
            load();
        }
    }
    enter();
    startchar();
}

// GOD MODE ACTIVATION
void godmodeactivation(){
    system("cls");
    first_energy = 100;
    first_hability = 100;
    first_luck = 100;
    energy = 100;
    hability = 100;
    luck = 100;
    gold = 100;
    provisions = 100;

    printf("\t\033[1;33m- GODMODE FOI ATIVADO -\n\n");
    printf("SEUS STATUS FORAM TODOS DEFINIDOS PARA 100\033[0;37m");
    printf("\n\n\033[1;33mSua ENERGIA:\033[0;37m %i", energy);
    printf("\n\033[1;33mSua HABILIDADE:\033[0;37m %i", hability);
    printf("\n\033[1;33mSua SORTE:\033[0;37m %i", luck);
    printf("\n\033[1;33mSeu GOLD:\033[0;37m %d", gold);
    printf("\n\033[1;33mSuas PROVIS�ES:\033[0;37m %d\n\n", provisions);
    printf("\033[1;36mTODOS OS ITENS COLET�VEIS AGORA EST�O NO SEU INVENT�RIO\n");
    hability_potion = 1; luck_potion = 1, energy_potion = 1, emerald = 1, sapphire = 1, iron_hook = 0, iron_key = 1, wood_tube = 1, rope = 1, metal_bell = 1, brass_bell = 1, chalice = 1, morph_potion = 1, leather_wristband = 1, monkey_amulet = 1, dagger = 1, ruby = 1, topaz = 1, wooden_legs = 1, old_bone = 1, shield = 1, wish_ring = 1, moringa_acid = 1, diamond = 1;
    printf("TODOS AS SKILLS COLET�VEIS AGORA EST�O NO SEU INVENT�RIO\033[0;37m\n");
    read_skeleton_scroll = 1, high_temperature_potion = 1, knowledge_morph_potion = 1, knowledge_bloody_beast = 1, skill_trap_potion = 1, knowledge_deadgirl_poem = 1;
    enter();
    OP001();
}

// CREATION OF CHARACTER
void startchar(){
    loop = 0;
    printf("\033[0;31m");
    printf("INSIRA SEU NOME: ");
    printf("\033[0;37m");
    gets(nome);
    if(godmode != 0)
        printf("GODMODE - Para ativar digite \"GODMODE\"\n\n");
    printf("Muito bem %s, agora vamos definir seus valores de habilidade e energia.\n\033[1;33mDigite \"ROLL\" para rolar os dados.\033[0;37m\n\n", nome);
    while(loop < 1){
        gets(startroll);
        if(strcasecmp(startroll, "roll") == 0){
            system("cls");

            dice1();
            printf("\nSua HABILIDADE foi setada para:");
            printf("\033[1;32m %d", numroll + 6);
            printf("\033[0;37m");
            first_hability = numroll + 6;
            hability = first_hability;

            printf("\nSua ENERGIA foi setada para:");
            printf("\033[1;31m %d", numroll + 12);
            printf("\033[0;37m\n");
            first_energy = numroll + 12;
            energy = first_energy;

            dice2();
            printf("\nSua SORTE foi setada para:");
            printf("\033[1;33m %d", numroll + 6);
            printf("\033[0;37m");
            first_luck = numroll + 6;
            luck = first_luck;
            loop++;
        }if(strcasecmp(startroll, "godmode")== 0){
            loop++;
            godmodeactivation();
        }
    }

    enter();
    loop = 0;

        printf("Escolha uma das tr�s po��es para carregar na sua jornada\n\n");
        printf("PO��O DE \033[0;32mHABILIDADE\033[0;37m - Rep�e os pontos de HABILIDADE.");
        printf("\nPO��O DA \033[0;31mFORCA\033[0;37m - rep�e os pontos de ENERGIA.");
        printf("\nPO��O DA \033[0;33mFORTUNA\033[0;37m - rep�e os pontos de SORTE e acrescenta 1 ponto � SORTE Inicial");

    while(loop < 1){
        printf("\033[1;35m");
        printf("\n\n Digite o nome colorido da po��o escolhida para selecionar: ");
        gets(itemchoice);
        if(strcasecmp(itemchoice, "habilidade") == 0){
            hability_potion += 1;
            printf("A po��o de HABILIDADE foi adicionada a seu invent�rio");
            loop++;
        } else if (strcasecmp(itemchoice, "forca") == 0){
            energy_potion += 1;
            printf("A po��o de FOR�A foi adicionada a seu invent�rio");
            loop++;
        } else if (strcasecmp(itemchoice, "fortuna") == 0){
            luck_potion += 1;
            printf("A po��o de FORTUNA foi adicionada a seu invent�rio");
            loop++;
        }
    }
    provisions = 10;
    printf("\033[1;37m");
    save();
    enter();
    resume();
}

// COMBATS

//  DO DAMAGE
void luck_damage(){
    printf("\n\033[1;33mVoc� deseja testar sua SORTE? (digite \"sim\" ou \"nao\")\n");
    printf("Sua SORTE ATUAL: %d\n\n\033[0;37m", luck);
    while(loop < 1){
        gets(luckhit);
        if(strcasecmp(luckhit, "sim") == 0){
            dice2();
            if(numroll <= luck){
                luck--;
                printf("\n\nSua SORTE: %d", luck);
                monsenergy -= 2;
                loop++;
            }
            else{
                luck--;
                printf("\n\nSua SORTE: %d", luck);
                monsenergy += 1;
                loop++;
            }
            printf("\n\n");
        }
        else if(strcasecmp(luckhit, "nao") == 0){
            loop++;
        }
    }
}

// TAKE DAMAGE 
void luck_defense(){
    printf("\n\033[1;33mVoc� deseja testar sua SORTE? (digite \"sim\" ou \"nao\")\n");
    printf("Sua SORTE ATUAL: %d\n\n\033[0;37m", luck);
    while(loop < 1){
        gets(luckhit);
        if(strcasecmp(luckhit, "sim") == 0){
            dice2();
            if(numroll <= luck){
                luck--;
                printf("\n\nSua SORTE: %d", luck);
                energy += 1;
                loop++;
            }
            else{
                luck--;
                printf("\n\nSua SORTE: %d", luck);
                energy -= 1;
                loop++;
            }
            printf("\n\n");
        }
        else if(strcasecmp(luckhit, "nao") == 0){
            loop++;
        }
    }
}

// COMBAT 1V1
void combat1(){
    printf("COME�OU O COMBATE!");
    combatloop = 0;
    while(combatloop < 1){
        loop = 0;
        printf("\nRode os dados:\n");
        printf("\033[0;31m");
        printf("DIGITE ROLL\n");
        printf("\033[0;37m");
        gets(combatroll);
        if(strcasecmp(combatroll, "roll") == 0){
            dice2();
            playerhabil = numroll + hability;
            printf("\n\nSUA FOR�A DE ATAQUE: %d\n\n", playerhabil);

            dice2();
            damagemonster = numroll + monshability;
            printf("\n\nFOR�A DE ATAQUE DO MONSTRO: %d\n", damagemonster);
        }
        if(strcasecmp(combatroll, "roll") == 0 && playerhabil > damagemonster){
            printf("\nVOC� CAUSOU DANO\n");
            monsenergy -= 2;
            luck_damage();
            printf("HP MONSTRO: %d", monsenergy);
            enter();
        }
        else if(strcasecmp(combatroll, "roll") == 0 && playerhabil < damagemonster){
            printf("\nVOCE LEVOU DANO\n");
            luck_defense();
            energy -= 2;
            printf("SEU HP: %d", energy);
            enter();
        }
        else if(strcasecmp(combatroll, "roll") == 0 && playerhabil == damagemonster){
            printf("\nAMBOS CONSEGUIRAM SE DEFENDER E NINGU�M SE MACHUCOU");
            enter();
        }
        if(energy <= 0){
            death();
        }
        else if (monsenergy <= 0){
            combatloop += 1;
            printf("VOCE GANHOU O COMBATE");
            enter();
        }
        system("cls");
    }
}

// COMBAT 2V2
void combat2(){
    printf("COME�OU O COMBATE!");
    combatloop = 0;
    fight1 = 0;
    fight2 = 0;
    while(combatloop < 1){
        loop = 0;
        combatloop2 = 0;
        printf("\nRode os dados:\n");
        printf("\033[1;31m");
        printf("DIGITE ROLL\n");
        printf("\033[0;37m");
        while(combatloop2 < 1){
        gets(combatroll);
            if(strcasecmp(combatroll, "roll") == 0){
                printf("DIGITE O INIMIGO QUE VOCE QUER ATACAR\n");
                if(monsenergy > 0)
                    printf("MONSTRO 1: \"digite 1\"\n");
                if(monsenergy2 > 0)
                    printf("MONSTRO 2: \"digite 2\"\n");
                else
                    printf("\n");
            }
            scanf("%d", &monschoice);
            if(monschoice == 1 && monsenergy > 0){
                defenseloop = 0;
                fight1 = 0;
                loop = 0;
                while(fight1 < 1){
                    if(strcasecmp(combatroll, "roll") == 0){
                        dice2();
                        playerhabil = numroll + hability;
                        printf("\n\nSUA FOR�A DE ATAQUE: %d\n", playerhabil);

                        dice2();
                        damagemonster = numroll + monshability;
                        printf("\nFOR�A DE ATAQUE DO MONSTRO 1: %d\n", damagemonster);
                    }
                    if(strcasecmp(combatroll, "roll") == 0 && playerhabil > damagemonster){
                        printf("\nVOC� CAUSOU DANO\n");
                        monsenergy -= 2;
                        luck_damage();
                        printf("HP MONSTRO: %d", monsenergy);
                        enter();
                        printf("A VEZ DOS MONSTROS: DEFENDA-SE!");
                        while(defenseloop < 1){
                            loop = 0;
                            printf("\nRode os dados:\n");
                            printf("\033[0;31m");
                            printf("DIGITE ROLL\n");
                            printf("\033[0;37m");
                            gets(combatroll);
                            if(strcasecmp(combatroll, "roll") == 0){
                                dice2();
                                damagemonster2 = numroll + monshability;
                                printf("\n\nFOR�A DE ATAQUE DOS MONSTROS: %d\n", damagemonster2);
                                dice2();
                                playerhabil = numroll + hability;
                                printf("\n\nSUA DEFESA: %d\n", playerhabil);
                            }
                            if(strcasecmp(combatroll, "roll") == 0 && playerhabil > damagemonster2){
                                printf("\nVOC� CONSEGUIU SE DEFENDER!");
                                defenseloop += 1;
                                fight1 += 1;
                                combatloop2 += 1;
                                enter();
                            }
                            if(strcasecmp(combatroll, "roll") == 0 && playerhabil < damagemonster2){
                                printf("\nVOCE LEVOU DANO\n");
                                luck_defense();
                                energy -= 2;
                                printf("SEU HP: %d", energy);
                                fight1 += 1;
                                defenseloop += 1;
                                combatloop2 += 1;
                                enter();
                            }
                        }
                    }
                    else if(strcasecmp(combatroll, "roll") == 0 && playerhabil < damagemonster){
                        printf("\nVOCE LEVOU DANO\n");
                        printf("\n\033[1;33mVoc� deseja testar sua SORTE? (digite \"sim\" ou \"nao\")\n");
                        printf("Sua SORTE ATUAL: %d\n\n\033[0;37m", luck);
                        while(loop < 1){
                            gets(luckhit);
                            if(strcasecmp(luckhit, "sim") == 0){
                                dice2();
                                if(numroll <= luck){
                                    luck--;
                                    printf("\n\nSua SORTE: %d", luck);
                                    energy += 1;
                                    loop++;
                                }
                                else{
                                    luck--;
                                    printf("\n\nSua SORTE: %d", luck);
                                    energy -= 1;
                                    loop++;
                                }
                                printf("\n\n");
                            }
                            else if(strcasecmp(luckhit, "nao") == 0){
                                loop++;
                            }
                        }
                        energy -= 2;
                        printf("SEU HP: %d", energy);
                        enter();
                        printf("A VEZ DOS MONSTROS: DEFENDA-SE!");
                        while(defenseloop < 1){
                            loop = 0;
                            printf("\nRode os dados:\n");
                            printf("\033[0;31m");
                            printf("DIGITE ROLL\n");
                            printf("\033[0;37m");
                            gets(combatroll);
                            if(strcasecmp(combatroll, "roll") == 0){
                                dice2();
                                damagemonster2 = numroll + monshability;
                                printf("\nFOR�A DE ATAQUE DOS MONSTROS: %d\n", damagemonster2);

                                dice2();
                                playerhabil = numroll + hability;
                                printf("\n\nSUA DEFESA: %d\n", playerhabil);
                            }
                            if(strcasecmp(combatroll, "roll") == 0 && playerhabil > damagemonster2){
                                printf("\nVOC� CONSEGUIU SE DEFENDER!");
                                defenseloop += 1;
                                fight1 += 1;
                                combatloop2 += 1;
                                enter();
                            }
                            if(strcasecmp(combatroll, "roll") == 0 && playerhabil < damagemonster2){
                                printf("\nVOCE LEVOU DANO\n");
                                printf("\n\033[1;33mVoc� deseja testar sua SORTE? (digite \"sim\" ou \"nao\")\n");
                                printf("Sua SORTE ATUAL: %d\n\n\033[0;37m", luck);
                                while(loop < 1){
                                    gets(luckhit);
                                    if(strcasecmp(luckhit, "sim") == 0){
                                        dice2();
                                        if(numroll <= luck){
                                            luck--;
                                            printf("\n\nSua SORTE: %d", luck);
                                            energy += 1;
                                            loop++;
                                        }else{
                                            luck--;
                                            printf("\n\nSua SORTE: %d", luck);
                                            energy -= 1;
                                            loop++;
                                        }
                                        printf("\n\n");
                                    } else if(strcasecmp(luckhit, "nao") == 0)
                                        loop++;
                                }
                                energy -= 2;
                                printf("SEU HP: %d", energy);
                                defenseloop += 1;
                                enter();
                            }
                        }
                    }
                    if(energy <= 0){
                        death();
                    }
                    else if (monsenergy <= 0){
                        fight1 += 2;
                        printf("VOCE GANHOU O COMBATE\n\n");
                        printf("COME�E O COMBATE COM O PROXIMO MONSTRO");
                        monshability = monshability2;
                        monsenergy = monsenergy2;
                        enter();
                        combat1();
                    }
                    if(fight1 == 2 && fight2 == 2){
                        combatloop2 += 1;
                        combatloop += 1;
                        system("cls");
                    }
                }
            }
            if(monschoice == 2 && monsenergy2 > 0){
                defenseloop = 0;
                fight2 = 0;
                loop = 0;
                while(fight2 < 1){
                    if(strcasecmp(combatroll, "roll") == 0){
                        dice2();
                        playerhabil = numroll + hability;
                        printf("\n\nSUA FOR�A DE ATAQUE: %d\n", playerhabil);

                        dice2();
                        damagemonster2 = numroll + monshability2;
                        printf("\nFOR�A DE ATAQUE DO MONSTRO 1: %d\n", damagemonster2);
                    }
                    if(strcasecmp(combatroll, "roll") == 0 && playerhabil > damagemonster2){
                        printf("\nVOC� CAUSOU DANO\n");
                        monsenergy2 -= 2;
                        printf("\n\033[1;33mVoc� deseja testar sua SORTE? (digite \"sim\" ou \"nao\")\n");
                        printf("Sua SORTE ATUAL: %d\n\n\033[0;37m", luck);
                        while(loop < 1){
                            gets(luckhit);
                            if(strcasecmp(luckhit, "sim") == 0){
                                dice2();
                                if(numroll <= luck){
                                    luck--;
                                    printf("\n\nSua SORTE: %d", luck);
                                    monsenergy2 -= 2;
                                    loop++;
                                }
                                else{
                                    luck--;
                                    printf("\n\nSua SORTE: %d", luck);
                                    monsenergy2 += 1;
                                    loop++;
                                }
                                printf("\n\n");
                            }
                            else if(strcasecmp(luckhit, "nao") == 0){
                                loop++;
                            }
                        }
                        printf("HP MONSTRO: %d", monsenergy2);
                        enter();
                        printf("A VEZ DOS MONSTROS: DEFENDA-SE!");
                        while(defenseloop < 1){
                            loop = 0;
                            printf("\nRode os dados:\n");
                            printf("\033[0;31m");
                            printf("DIGITE ROLL\n");
                            printf("\033[0;37m");
                            gets(combatroll);
                            if(strcasecmp(combatroll, "roll") == 0){
                                dice2();
                                damagemonster = numroll + monshability;
                                printf("\nFOR�A DE ATAQUE DOS MONSTROS: %d\n", damagemonster);
                                dice2();
                                playerhabil = numroll + hability;
                                printf("\n\nSUA DEFESA: %d\n", playerhabil);

                            }if(strcasecmp(combatroll, "roll") == 0 && playerhabil > damagemonster){
                                printf("VOC� CONSEGUIU SE DEFENDER!");
                                defenseloop += 1;
                                fight2 += 1;
                                combatloop2 += 1;
                                enter();

                            }if(strcasecmp(combatroll, "roll") == 0 && playerhabil < damagemonster){
                                printf("\nVOCE LEVOU DANO\n");
                                printf("\n\033[1;33mVoc� deseja testar sua SORTE? (digite \"sim\" ou \"nao\")\n");
                                printf("Sua SORTE ATUAL: %d\n\n\033[0;37m", luck);
                                while(loop < 1){
                                    gets(luckhit);
                                    if(strcasecmp(luckhit, "sim") == 0){
                                        dice2();
                                        if(numroll <= luck){
                                            luck--;
                                            printf("\n\nSua SORTE: %d", luck);
                                            energy += 1;
                                            loop++;
                                        }else{
                                            luck--;
                                            printf("\n\nSua SORTE: %d", luck);
                                            energy -= 1;
                                            loop++;
                                        }
                                        printf("\n\n");
                                    } else if(strcasecmp(luckhit, "nao") == 0)
                                        loop++;
                                }

                                energy -= 2;
                                printf("SEU HP: %d", energy);
                                defenseloop += 1;
                                fight2 += 1;
                                combatloop2 += 1;
                                enter();

                            }
                        }
                    }
                    else if(strcasecmp(combatroll, "roll") == 0 && playerhabil < damagemonster2){
                        printf("\nVOCE LEVOU DANO\n");
                        printf("\n\033[1;33mVoc� deseja testar sua SORTE? (digite \"sim\" ou \"nao\")\n");
                        printf("Sua SORTE ATUAL: %d\n\n\033[0;37m", luck);
                        while(loop < 1){
                            gets(luckhit);
                            if(strcasecmp(luckhit, "sim") == 0){
                                dice2();
                                if(numroll <= luck){
                                    luck--;
                                    printf("\n\nSua SORTE: %d", luck);
                                    energy += 1;
                                    loop++;
                                }
                                else{
                                    luck--;
                                    printf("\n\nSua SORTE: %d", luck);
                                    energy -= 1;
                                    loop++;
                                }
                                printf("\n\n");
                            }
                            else if(strcasecmp(luckhit, "nao") == 0){
                                loop++;
                            }
                        }
                        energy -= 2;
                        printf("SEU HP: %d", energy);
                        enter();
                        printf("A VEZ DOS MONSTROS: DEFENDA-SE!");
                        while(defenseloop < 1){
                            loop = 0;
                            printf("\nRode os dados:\n");
                            printf("\033[0;31m");
                            printf("DIGITE ROLL\n");
                            printf("\033[0;37m");
                            gets(combatroll);
                            if(strcasecmp(combatroll, "roll") == 0){
                                dice2();
                                damagemonster = numroll + monshability;
                                printf("\nFOR�A DE ATAQUE DOS MONSTROS: %d\n", damagemonster);

                                dice2();
                                playerhabil = numroll + hability;
                                printf("\n\nSUA DEFESA: %d\n", playerhabil);

                            }if(strcasecmp(combatroll, "roll") == 0 && playerhabil > damagemonster){
                                printf("VOC� CONSEGUIU SE DEFENDER!");
                                defenseloop += 1;
                                fight2 += 1;
                                combatloop2 += 1;
                                enter();

                            }if(strcasecmp(combatroll, "roll") == 0 && playerhabil < damagemonster){
                                printf("\nVOCE LEVOU DANO\n");
                                printf("\n\033[1;33mVoc� deseja testar sua SORTE? (digite \"sim\" ou \"nao\")\n");
                                printf("Sua SORTE ATUAL: %d\n\n\033[0;37m", luck);
                                while(loop < 1){
                                    gets(luckhit);
                                    if(strcasecmp(luckhit, "sim") == 0){
                                        dice2();
                                        if(numroll <= luck){
                                            luck--;
                                            printf("\n\nSua SORTE: %d", luck);
                                            energy += 1;
                                            loop++;
                                        }else{
                                            luck--;
                                            printf("\n\nSua SORTE: %d", luck);
                                            energy -= 1;
                                            loop++;
                                        }
                                        printf("\n\n");
                                    } else if(strcasecmp(luckhit, "nao") == 0)
                                        loop++;
                                }

                                energy -= 2;
                                printf("SEU HP: %d", energy);
                                defenseloop += 1;
                                fight2 += 1;
                                combatloop2 += 1;
                                enter();

                            }
                        }
                    }
                    if(energy <= 0){
                        death();
                    }
                    else if (monsenergy2 <= 0){
                        combatloop2 += 1;
                        fight2 += 2;
                        printf("VOCE GANHOU O COMBATE\n\n");
                        printf("COME�E O COMBATE COM O PROXIMO MONSTRO");
                        enter();
                        combat1();
                    }
                    if(fight1 == 2 && fight2 == 2){
                        combatloop2 += 1;
                        combatloop += 1;
                    system("cls");
                    }
                }
            }
        }
    }
}

// DICES

void dice1(){ // RODA UM DADO
    for(i = 0; i < 1; i++){
        numroll = (rand() % 6 - 1 + 1) + 1;
        printf("Resultado do dado: %d", numroll);
    }
}

void dice2(){ // RODA DOIS DADOS
    for(i = 0; i < 1; i++){
        numroll = (rand() % 12 - 2 + 1) + 2; // (upper - lower + 1)) + lower
        printf("Resultado dos dados: %d", numroll);
    }
}

// MORTE
void death(){
    provisions = 0, gold = 0, hability = 0, first_hability, energy = 0, first_energy, luck = 0, first_luck, dards; // STATUS POINTS

    hability_potion = 0, luck_potion = 0, energy_potion = 0, jewel = 0, emerald = 0, sapphire = 0, iron_hook = 0, iron_key = 0, wood_tube = 0, rope = 0, metal_bell = 0, brass_bell = 0, chalice = 0, morph_potion = 0, leather_wristband = 0, monkey_amulet = 0, dagger = 0, ruby = 0, topaz = 0, wooden_legs = 0, old_bone = 0, shield = 0, wish_ring = 0, moringa_acid = 0, diamond = 0, grenade = 0; // ITENS RESET

    read_skeleton_scroll = 0, high_temperature_potion = 0, knowledge_morph_potion = 0, knowledge_bloody_beast = 0, skill_trap_potion = 0, knowledge_deadgirl_poem = 0, disarmed = 0;// SKILLS AND KNOWLEDGE

    status_OP006 = 0, status_OP226 = 0, status_OP162 = 0, status_OP257 = 0, status_OP150 = 0, status_OP011 = 0, status_OP020 = 0, status_OP028 = 0, status_OP033 = 0, status_OP052 = 0, status_OP171 = 0, status_OP244 = 0, status_OP256 = 0, status_OP094 = 0, status_OP095 = 0, status_OP105 = 0, status_OP106 = 0, status_OP114 = 0, status_OP123 = 0, status_OP147 = 0, status_OP157 = 0, status_OP169 = 0, status_OP175 = 0, status_OP229 = 0, status_OP240 = 0, status_OP251 = 0, status_OP270 = 0, status_OP285 = 0, status_OP308 = 0, status_OP337 = 0, status_OP363 = 0, status_OP375 = 0, status_OP391 = 0, status_OP397 = 0, status_OP026 = 0, status_OP038 = 0, status_OP042 = 0, status_OP045 = 0, status_OP072 = 0, status_OP057 = 0, status_OP103 = 0, status_OP158 = 0, status_OP165 = 0, status_OP167 = 0, status_OP341 = 0, status_OP269 = 0, status_OP330 = 0, status_OP336 = 0;
    
    stageops = 0; // Stage


    save();
    printf("\n\n                                                                               Sua aventura chegou ao fim h�roi. Aperte \033[1;31m\"ENTER\"\033[0;37m para retornar a tela inicial.                                                                               ");
    enter();
    startmenu();
}

// PRESS ENTER DESIGN EFFECT
void enter(){
    printf("\n\n                                                                                                        Aperte \033[1;35m\"ENTER\"\033[0;37m para continuar                                                                                                        ");
    getch();
    system("cls");
}

// INVENTORY 
void inventory(){
    system("cls");
    while(loop < 1){
    length = strlen(invname);

    columns = length + 4;
    rows = (length / 2)>=3 ? length/2 : 1;

    /* Iterate over each row */
    for(a=1; a<=rows; a++)
    {
        /* Iterate over each column */
        for(b=1; b<=columns; b++)
        {
            if(a==1 || a==rows || b==1 || b==columns)
            {
                /* Print star for 1st and last row, column */
                printf("*");
            }
            else
            {
                if(a==rows/2+1 && b>=3 && b<=columns-2)
                    printf("%c", invname[b-3]);
                else
                    printf(" ");
            }
        }

        /* Move to the next line/row */
        printf("\n");
    }

    printf("\n\nHABILIDADE: ");
    printf("\033[1;32m");
    printf("%d", hability);
    printf("\033[0;37m");
    printf("\nENERGIA: ");
    printf("\033[1;31m");
    printf("%d", energy);
    printf("\033[0;37m");
    printf("\nSORTE: ");
    printf("\033[1;33m");
    printf("%d", luck);
    printf("\033[0;37m");

    printf("\033[1;33m");
    printf("\n\nOURO: %d", gold);
    printf("\033[0;37m");
    printf("\033[1;34m");
    printf("\nPROVIS�ES: %d, se deseja usar suas provis�es digite \033[1;33m\"9\"\033[0;37m ", provisions);
    printf("\033[0;37m");

    printf("\n\nPO��ES:\n");
    if(energy_potion == 0 && luck_potion == 0 && hability_potion == 0)
        printf("\n\033[1;31mVoc� n�o possui PO��ES\033[0;37m");
    if(luck_potion != 0)
        printf("\nPo��o de fortuna: x%d, se deseja usar este item aperte \033[1;33m\"1\"\033[0;37m", luck_potion);
    if(energy_potion != 0)
        printf("\nPo��o de for�a: x%d, se deseja usar este item aperte \033[1;33m\"2\"\033[0;37m", energy_potion);
    if(hability_potion != 0)
        printf("\nPo��o de habilidade: x%d, se deseja usar este item aperte \033[1;33m\"3\"\033[0;37m", hability_potion);
    
    printf("\n\nITENS COLETADOS:\n");
    if(iron_hook == 0 && iron_key == 0 && wood_tube == 0 && rope == 0 && metal_bell == 0 && chalice == 0 && morph_potion == 0 && leather_wristband == 0 && energy_ring == 0 && wish_ring == 0)
        printf("\n\033[1;31mVoce n�o possui ITENS\033[0;37m");
    if(iron_hook != 0)
        printf("\nGancho de Ferro: x%d", iron_hook);
    if(iron_key != 0)
        printf("\nChave de Ferro: x%d", iron_key);
    if(wood_tube != 0)
        printf("\nTubo oco de Madeira: x%d", wood_tube);
    if(rope != 0)
        printf("\nRolo de Corda: x%d", rope);
    if(metal_bell != 0)
        printf("\nSino de Metal: x%d", metal_bell);
    if(chalice != 0)
        printf("\nC�lice: x%d", chalice);
    if(morph_potion != 0)
        printf("\nPo��o de R�plica: x%d", morph_potion);
    if(leather_wristband != 0)
        printf("\nMunhequeira de Couro: x%d", leather_wristband);
    if(energy_ring != 0)
        printf("\nAnel de Energia: x%d", energy_ring);
    if(wish_ring != 0)
        printf("\nAnel dos Desejos: x%d", wish_ring);

    printf("\n\nJOIAS COLETADAS:\n");
    if(emerald == 0 && jewel == 0 && sapphire == 0 && diamond == 0 && ruby == 0 && topaz == 0)
        printf("\n\033[1;31mVoc� n�o possui JOIAS\033[0;37m");
    if(emerald != 0)
        printf("\nEsmeralda: %d", emerald);
    if(diamond != 0)
        printf("\nDiamante: %d", diamond);
    if(ruby != 0)
        printf("\nRubi: %d", ruby);
    if(topaz != 0)
        printf("\nTopazio: %d", topaz);
    if(sapphire != 0)
        printf("\nSafira: %d", sapphire);
    if(jewel != 0)
        printf("\nJoia: %d", jewel);

    printf("\n\nSKILLS\n");
    if(read_skeleton_scroll == 0 && high_temperature_potion == 0 && knowledge_morph_potion == 0 && knowledge_bloody_beast == 0 && skill_trap_potion == 0 && knowledge_deadgirl_poem == 0 && disarmed == 0)
        printf("\n\033[1;31mVoc� n�o possui SKILLS\033[0;37m");
    if(knowledge_deadgirl_poem != 0)
        printf("\nCONHECIMENTO DO POEMA DA GAROTA MORTA");
    if(read_skeleton_scroll != 0)
        printf("\nCONHECIMENTO PERGAMINHO DO ESQUELETO");
    if(knowledge_bloody_beast != 0)
        printf("CONHECIMENTO DA BESTA SANGRENTA");
    if(high_temperature_potion != 0)
        printf("\nCORPO VULCANICO - RESISTE A ALTAS TEMPERATURAS");
    if(skill_trap_potion != 0)
        printf("6 SENTIDO - VOC� ENXERGA ARMADILHAS");
    if(disarmed != 0)
        printf("\nVoc� est� DESARMADO");

    printf("\n\nSe deseja sair aperte \"4\"\n");
    printf("Se deseja ler as regras aperte \"0\"\n\n");
        scanf("%d", &invuse);
        if(invuse == 1 && luck_potion > 0){ // LUCK
            luck_potion -= 1;
            luck = first_luck + 1;
            printf("\nSUA PO��O FOI USADA");
            printf("\n\033[1;33mSua sorte atual: %d\033[0;37m", luck);
            enter();
        }else if(invuse == 2 && energy_potion > 0){
            energy_potion -= 1;
            energy = first_energy;
            printf("\nSUA PO��O FOI USADA");
            printf("\033[1;32mSua energia atual: %d\033[0;37m", energy);
            enter();
        }else if(invuse == 3 && hability_potion > 0){
            hability_potion -= 1;
            hability = first_hability;
            printf("\nSUA PO��O FOI USADA");
            printf("\n\033[1;31mSua habilidade atual: %d\033[0;37m", hability);
            enter();
        }else if(invuse == 9 && provisions > 0){
            provisions -= 1;
            energy += 2;
            printf("\nUMA DE SUAS PROVIS�ES FOI UTILIZADA");
            printf("\n\033[1;32mSua ENERGIA atual: %d\033[0;37m", energy);
            enter();
        }else if(invuse == 4){
            loop++;
        }else if(invuse == 0){
            rules();
        }
    }
}

//RULES
void rules(){
    system("cls");
    printf("\t\t------------REGRAS DO JOGO-------------\n\n");
    printf("\tAntes de voc� poder continuar aventureiro, temos que explicar algumas coisas sobre o jogo. O jogo � bem simples, haver� um texto como esse que voc� l� e logo abaixo ter� sua op��es de escolha iguais aos exemplos abaixo:\n\nSe voc� quiser seguir para a esquerda, \033[1;35mdigite 1.\033[0;37m\nSe quiser ir para a direita, \033[1;35mdigite 2.\033[0;37m\n\n\tAssim voc� ir� digitar o n�mero da op��o que voc� quiser e ser� levado para tal n�mero e ir� executar o que tem escrito no texto seguinte e assim voc� ir� progredir no jogo. \033[1;31mCUIDADO, SE VOC� ESCOLHER A OP��O ERRADA, N�O H� VOLTA!\033[0;37m Em dados momentos do jogo voc� receber� itens, ganhar� \033[1;31mHABILIDADE,  \033[1;32mENERGIA\033[0;37m e \033[1;33mSORTE\033[0;37m assim como as perder�, al�m disso, voc� pode receber o que n�s chamamos de \033[1;35mSKILL\033[0;37m ou talvez \033[1;31mlutar contra um monstro amedrontador\033[0;37m. HABILIDADE � o atributo que te ajudar� em batalhas e em certas situa��es que exigem certa destrez. Sua SORTE � utilizada em situa��es espec�ficas ou durante o combate para tentar causar mais dano ou receber menos danos. Sua \033[1;32mENERGIA\033[0;37m � a quantidade de dano que voc� aguentar receber, se sua ENERGIA chegar a \033[1;31m0\033[0;37m o jogo acaba e voc� ter� que retornar ao in�cio com um novo personagem. As \033[1;35mSKILL\033[0;37m s�o algum tipo de conhecimento que se adquire ao longo de sua jornada, por exemplo ler um livro, voc� adquire o conhecimento dentro do livro, por�m n�o leva o livro consigo, assim � considerado uma SKILL um item n�o f�sico.\n\n\tO combate contra monstros e outras criaturas n�o � complicado e tudo ser� bem autom�tico, al�m disso todas as informa��es sobre ser�o ditas em tela, basta voc� digitar \033[1;33m\"ROLL\"\033[0;37m quando for pedido. Ap�s rolar os dados, o resultado � somado a sua \033[1;31mHABILIDADE\033[0;37m e assim resultando na sua \033[1;31mFOR�A DE ATAQUE\033[0;37m. O seu advers�rio faz o mesmo e tamb�m junta sua FOR�A DE ATAQUE. Quem tiver maior FOR�A DE ATAQUE causa 2 de dano ao seu oponente e, usando sua sorte, voc� poder� dobrar o dano ou receber metade do dano.\n\n\tCertas situa��es tamb�m exigiram algum tipo de teste, podendo ser um teste de \033[1;31mHABILIDADE\033[0;37m ou um teste de \033[1;33mSORTE\033[0;37m. O texto ir� pedir para voc� rolar dados e se o resultado for IGUAL OU MENOR que o valor atual do seu atributo, voc� passou no teste, se o resultado for MAIOR que o valor atual do seu atributo, voc� falhou no teste...Por�m, voc� n�o saber� o resultado dos dados e nem mesmo se passou ou n�o, voc� apenas ser� levado at� o respectivo texto e voc� ter� que ler as consequ�ncias nele, dessa forma criamos uma tens�o maior dentro do jogo.\n\n\tPor fim, voc� ainda poder� conseguir itens ao longo do jogo com efeitos diversos. Maioria dos itens s�o para situa��es espec�ficas e s�o usados apenas quando se � pedido no texto, voc� notar� isso quando se deparar com uma op��o como esta:\n\nSe voc� tiver uma chave e quiser abrir a porta, \033[1;35mdigite 1.\033[0;37m\nSe n�o tiver o item ou n�o quiser, \033[1;35mdigite 2.\033[0;37m\n\n\tMesmo que voc�, jogador malandro, tente ser mais esperto que o jogo e minta tentando digitar o n�mero para ir adiante mesmo n�o tendo o item, n�s, programadores do jogo, fizemos com que isso n�o aconte�a, logo jogue justo e n�o trapaceie.\n\n\tBom, voc� est� pronto para a aventura, sempre que precisar, \"digite 0\" fora de combate e fora de testes de atributo para acessar seu invent�rio sempre que for necess�rio!\n\n\t\033[1;33mSEU JOGO SEMPRE � SALVO EM OP��ES DE MULTIPLAS ESCOLHAS!\n\n\tBOM JOGO E OBRIGADO POR JOGAR!\033[0;37m");
    enter();
    inventory();
}

// OPENING
void resume(){
    printf("\t...Sua vis�o � escura e relaxante. De muito longe voc� ouve gritos de alegria e aclama��o, o forte e fren�tico bater de palmas de uma multid�o e um certo ritmo feito por tambores e berrantes. Todo esse barulho come�a aumentar e sua vis�o � ofuscada pela luz da janela de sua cabine, for�ando-o a acordar assustado. Voc� olha ao redor, retomando o f�lego, logo se recorda de onde est�... Voc� havia se inscrevido para participar do desafio da Prova dos Campe�es, cujo vencedor receber� 1 milh�o de pe�as de ouro. O desafio fica em Fang, uma cidade conhecida apenas por essa prova que ocorre anualmente. Voc� fora escolhido para participar da prova e acaba de acordar no barco que veleja pelo rio Kok at� Fang.\n\tVoc� e outros 5 desafiantes desembarcam no porto da cidade. Um grande aglomerado de centenas de pessoas os recebem com grande felicidade e hospitalidade. Todos voc�s s�o levados por uma guia de pele escura e longos cabelos negros ondulados vestindo um simples vestido de pano branco, tal guia os leva at� uma grande estalagem, talvez a melhor da cidade, chamada Lagarto Trovejante. Voc� chega na estalagem com o sol alto no c�u e at� seu anoitecer voc� � tratado quase como um rei, tudo que � pedido logo � atendido por algum servi�al da cidade. Comida ex�tica e t�pica da regi�o lhe � dada assim como a bebida. Finalmente o sol se p�e atr�s do rio Kok e voc� � levado para seus aposentos, uma su�te privada enorme para seu descanso e conforto.\n\tVoc� se deita em sua cama confort�vel, por�m mal consegue dormir, a ansiedade o mant�m acordado por boa parte da noite. Voc� n�o sabe o que esperar, os perigos que ir� encontrar... Isso o deixa um pouco nervoso... Voc� finalmente acorda na manh� do dia seguinte. A mesma guia leva voc� e os outros desafiantes at� um est�dio pequeno onde se encontra um grande estande com v�rias espadas penduradas. Voc� seleciona a espada que melhor te agrada, ent�o uma armadura de couro batido te � entregue, por fim, voc� recebe uma mochila grande com provis�es suficientes para 10 refei��es e um enorme cantil para 10 dias de �gua.\n\tVoc� e os outros desafiantes se aquecem por mais ou menos uma hora at� que o som de um alto berrante ecoa por toda a cidade, o chamado para o in�cio da aventura... Voc� � o quarto da fila dos desafiantes seguindo o caminho formado por pessoas de ambos os lados at� finalmente chegar numa grande caverna no formato de uma boca de serpente com duas grandes presas bem aparentes. O primeiro competidor adentra a bocanha e uma hora ap�s o primeiro, o segundo entra e assim vai at� que sua vez chega. Seu cora��o bate forte e o nervosismo bate... Voc� � chamado, voc� respira fundo e come�a a caminhar para dentro do calabou�o da morte...\n\nLembre-se, voc� pode acessar seu invent�rio digitando \"00\" sempre que necess�rio (voc� n�o poder� abrir o invent�rio em batalhas).");

    enter();
    OP001();
}

// OPCAO 001
void OP001(){
    stageops = 1;
    save();
    loop = 0;

    printf("\t1 - O clamor dos espectadores excitados some gradualmente atr�s de voc�, que se aventura cada vez mais fundo na penumbra do t�nel da caverna... Grandes cristais pendem do teto do t�nel a intervalos de 20 metros, irradiando uma luz suave, apenas suficiente para que veja por onde anda. � medida que seus olhos v�o pouco a pouco se acostumando � quase escurid�o, voc� come�a a ver movimentos � sua volta. Aranhas e besouros sobem e descem pelas paredes entalhadas, desaparecendo em frestas e gretas ao sentir sua aproxima��o, al�m disso ratazanas e ratos correm pelo ch�o � sua frente. Pingos de �gua caem em pequenas po�as com um sinistro som gotejante que ecoa pelo t�nel. O ar � frio, �mido e pesado. Depois de caminhar lentamente pelo t�nel por uns cinco minutos, voc� chega a uma mesa de pedra encostada contra a parede � sua esquerda. Nela h� seis caixas, uma das quais tem seu nome pintado na tampa.\n\nSe voc� quiser abrir a caixa, \033[1;35mdigite 270.\033[0;37m\nSe preferir continuar caminhando para o norte, \033[1;35mdigite 66.\033[0;37m\n\n");

    printf("\033[1;34mLEMBRE-SE, VOC� PODE ACESSAR SEU INVENT�RIO DIGITANDO 0\033[0;37m\n\n");

    while(loop<1){
        scanf("%d", &choices);
        switch (choices)
        {
        case 270:
            loop++;
            system("cls");
            OP270();
            break;

        case 66:
            loop++;
            system("cls");
            OP066();
            break;

        case 0:
            inventory();
            enter();
            OP001();
            break;

        }
    }
}

//OP��O 002
void OP002(){
    loop = 0;

    printf("\t2 - O Escorpi�o consegue prend�-lo nas garras por tempo suficiente para mover a cauda segmentada para frente, por sobre a cabe�a, e cravar em voc� o ferr�o venenoso. \033[1;31mO efeito � fatal, e voc� desaba no ch�o da Arena da Morte, imaginando se Throm conseguir� vencer.\033[0;37m");
    death();
}

//OP��O 003
void OP003(){
    loop = 0;

    printf("\t3 - O Gnomo sacode a cabe�a e diz: \"Temo que voc� n�o tenha passado pela Prova dos Campe�es. Os segredos do Calabou�o da Morte do Bar�o Sukumvit ficar�o guardados por mais um ano, pois voc� n�o ter� permiss�o para sair daqui. Voc� foi indicado para ser meu servo pelo resto dos seus dias; \033[1;31mpreparar� e modificar� o subterr�neo para competidores futuros. Talvez em outra vida voc� tenha sucesso...\033[0;37m\"");
    death();
}

//OP��O 004
void OP004(){
    loop = 0;

    printf("\t4 - Na escurid�o total, voc� n�o v� a curva do cano para baixo. Escorrega e, incapaz de se segurar no cano cheio de limo, desliza pela borda. Seus gritos ecoam pelo tubo, enquanto voc� cai 50 metros at� o fundo. \033[1;31mVoc� fracassou na Prova dos Campe�es.\033[0;37m");
    death();
}

//OP��O 005
void OP005(){
    loop = 0;

    printf("\t5 - Voc� se arrasta pelo ch�o e se v� no covil de uma tribo de TROGLODITAS. Ao engatinhar passando por eles, sua bainha bate em uma pedra. \033[1;33mDigite \"ROLL\" e teste sua SORTE.\033[0;37m\n\n");

    while(loop < 1){
        gets(startroll);
        if(strcasecmp(startroll, "roll") == 0){
            dice2();
            if(numroll <= luck){
                luck--;
                system("cls");
                OP185();
            }else{
                luck--;
                system("cls");
                OP395();
            }
        }
    }
}

//OP��O 006
void OP006(){
    loop = 0;
    monsenergy = 11;
    monshability = 11;

    printf("\t6 - Sabendo que o Mant�cora disparar� os espinhos da cauda, Voc� corre para se proteger atr�s de um dos pilares. Antes que consiga chegar l�, uma saraivada de espinhos voa pelo ar, e um deles penetra-lhe o bra�o. Voc� perde 2 pontos de ENERGIA. N�o perca tempo e ataque o Mant�cora com espada, antes que ele possa disparar mais espinhos.\n\n\033[1;31mMANT�CORA   HABILIDADE 11   ENERGIA 11\033[0;37m\n\n");

    if(status_OP006 == 0){
        energy -= 2;
        status_OP006 += 1;
        printf("\n\nSua ENERGIA: %i", energy);
        enter();
        combat1();
        printf("\n\nSua ENERGIA: %i", energy);
        printf("\n\nVoc� conseguiu sobreviver ao monstro!");
        enter();
        OP364();
    }else{
        enter();
        OP364();
    }
}

//OP��O 007
void OP007(){
    loop = 0;
    printf("\t7 - Antes que voc� tenha tempo de chegar a uma porta, o rochedo j� est� sobre voc�, \033[1;31mque grita de dor e medo quando ele o esmaga no ch�o.\033[0;37m");
    death();
}

//OP��O 008
void OP008(){
    loop = 0;

    printf("\t8 - O Dem�nio do Espelho agarra-o pelo pulso. Imediatamente, ele come�a a pux�-lo na dire��o do espelho. A for�a dele � incr�vel, e, apesar de todos os seus esfor�os, voc� n�o consegue evitar que o arraste progressivamente na dire��o do espelho. Quando ele toca o espelho, parece desaparecer diretamente atrav�s dele. Horrorizado, voc� v� seu pr�prio bra�o desaparecer, seguido pelo resto do corpo. \033[1;31mVoc� est� agora em um mundo de espelhos de outra dimens�o, do qual jamais retornar�.\033[0;37m");
    death();
}

//OP��O 009
void OP009(){
    stageops = 9;
    save();
    loop = 0;

    printf("\t9 - Os Hobgoblins n�o t�m nada que lhe seja �til, por isso voc� resolve abrir o saco no ch�o. Dentro, acha uma moringa de barro arrolhada. Voc� a desarrolha e cheira o l�quido que cont�m. O odor � penetrante e acre.\n\nSe quiser beber um pouco do l�quido, \033[1;35mdigite 158.\033[0;37m\nSe quiser mergulhar um peda�o de pano nele, \033[1;35mdigite 375.\033[0;37m\n\n");

    printf("\033[1;34mLEMBRE-SE, VOC� PODE ACESSAR SEU INVENT�RIO DIGITANDO 0\033[0;37m\n\n");

    while(loop < 1){
        scanf("%i", &choices);
        switch(choices){
            case 158:
                loop++;
                system("cls");
                OP158();
                break;
            case 375:
                loop++;
                system("cls");
                OP375();
                break;
            case 0:
                inventory();
                enter();
                OP009();
                break;
        }
    }
}

//OP��O 010
void OP010(){
    stageops = 10;
    save();
    loop = 0;

    printf("\t10 - Ainda correndo o mais r�pido poss�vel, voc� enfia a m�o na mochila e tira o tubo de madeira. Seu plano � ficar sob a �gua, respirando pelo tubo. Com sorte, os Trogloditas pensar�o que voc� ser� arrastado at� a morte rio abaixo, pois a torrente desaparece nas profundezas da montanha. Voc� segura o tubo entre os dentes e mergulha na �gua. Segurando-se em um dos pilares da ponte embaixo d'�gua, voc� fica absolutamente im�vel por 10 minutos. Quando finalmente acha que os Trogloditas foram embora, voc� sobe a superf�cie e olha em volta. N�o h� ningu�m � vista, e voc� sai do rio e atravessa a ponte para a margem norte. Quaisquer Provis�es restantes que voc� possa ter est�o agora encharcadas e imprest�veis. Elas foram removidas do seu invent�rio. Voc� segue pela vasta caverna at� que, finalmente, v� um t�nel na parede do outro lado. Voc� caminha at� uma pesada porta de madeira, que est� trancada.\n\nSe voc� tiver uma chave de ferro e quiser abrir, \033[1;35mdigite 86.\033[0;37m\nSe n�o quiser, \033[1;35mdigite 276.\033[0;37m");

    printf("\033[1;34mLEMBRE-SE, VOC� PODE ACESSAR SEU INVENT�RIO DIGITANDO 0\033[0;37m\n\n");

    while(loop < 1){
        scanf("%i", &choices);
        switch(choices){
            case 86:
                loop++;
                system("cls");
                OP086();
                break;
            case 276:
                loop++;
                if(iron_key != 0){
                    system("cls");
                    OP276();
                } else{
                    printf("Voc� n�o possui este item.");
                    enter();
                    OP010();
                }
                break;
            case 0:
                inventory();
                enter();
                OP010();
                break;
        }
    }
}

//OP��O 011
void OP011(){
    stageops = 11;
    save();
    loop = 0;

    printf("\t11 - Voc� olha para baixo e v� os corpos esparramados dos Guardi�es Voadores im�veis no ch�o. Ent�o, come�a a for�ar o olho de esmeralda do �dolo para retir�-lo com a ponta da espada. Finalmente, ele se solta, e voc� fica surpreso com o peso da j�ia. Esperando que possa ser �til mais tarde, voc� o coloca na mochila.\n\nSe quiser agora retirar o olho direito, \033[1;35mdigite 140.\033[0;37m\nSe preferir descer do �dolo, \033[1;35mdigite 46.\033[0;37m\n\n");

    printf("\033[1;34mLEMBRE-SE, VOC� PODE ACESSAR INVENT�RIO DIGITANDO 0\033[0;37m\n\n");


    while(loop < 1){
        if(status_OP011 == 0){
            jewel += 1;
            status_OP011 += 1;
            printf("Esmelda foi adicionada ao seu invent�rio.");
            scanf("%i", &choices);
            switch(choices){
                case 140:
                    loop++;
                    system("cls");
                    OP140();
                    break;
                case 46:
                    loop++;
                    system("cls");
                    OP046();
                    break;
                case 0:
                    inventory();
                    enter();
                    OP011();
                    break;
            }
        }else{
            printf("\033[1;31mVoc� j� esteve aqui, nada foi adicionado ao seu invent�rio.\033[0;37m\n\n");
            scanf("%i", &choices);
            switch(choices){
                case 140:
                    loop++;
                    system("cls");
                    OP140();
                    break;
                case 46:
                    loop++;
                    system("cls");
                    OP046();
                    break;
                case 0:
                    inventory();
                    enter();
                    OP011();
                    break;
            }
        }
    }
}

//OP��O 012
void OP012(){
    stageops = 12;
    save();
    loop = 0;

    printf("\t12 - A porta abre para um grande aposento iluminado por velas, repleto das mais extraordin�rias est�tuas, de apar�ncia real, representando guerreiros e cavaleiros. Um velho de cabelos brancos, trajando trapos esfarrapados, salta de tr�s de uma das est�tuas e come�a a dar risinhos. Uma centelha nos olhos dele faz com que voc� pense que algo se esconde por tr�s daquela apar�ncia de idiota. Numa voz estridente, ele diz: \"Bom, mais uma pedra para meu jardim. Fico feliz que voc� tenha vindo se juntar a seus amigos. Sou um homem justo, e por isso vou lhe fazer uma pergunta. Se responder corretamente, ficar� livre - mas, se sua resposta estiver errada, eu o transformarei em pedra!\" Ele volta a dar risadinhas, obviamente feliz com sua chegada. Voc�:\n\nEsperar� pela pergunta? \033[1;35mDigite 382.\033[0;37m\nVai atac�-lo com sua espada? \033[1;35mDigite 195.\033[0;37m\nCorrer� para a porta? \033[1;35mDigite 250.\033[0;37m\n\n");

    printf("\033[1;34mLEMBRE-SE, VOC� PODE ACESSAR SEU INVENT�RIO DIGITANDO 0\033[0;37m\n\n");

    while(loop < 1){
        scanf("%i", &choices);
        switch(choices){
            case 382:
                loop++;
                system("cls");
                OP382();
                break;
            case 195:
                loop++;
                system("cls");
                OP195();
                break;
            case 250:
                loop++;
                system("cls");
                OP250();
                break;
            case 0:
                inventory();
                enter();
                OP012();
                break;
        }
    }
}

//OPCAO 013
void OP013(){
    stageops = 13;
    save();
    loop = 0;

    printf("\t13 - O t�nel faz uma curva abrupta para a esquerda e se dirige para o norte, tanto quanto a sua vista alcan�a. As pegadas que voc� est� seguindo come�am a sumir � medida que o t�nel vai ficando mais seco. Logo n�o v� mais o teto gotejante e as po�as no ch�o. Voc� repara que o ar est� se tornando mais quente, e se v� ofegante, embora esteja andando bem devagar. Em uma pequena reentr�ncia da parede da esquerda, voc� v� um peda�o de bambu na vertical. Levantando-o, repara que ele est� cheio de um l�quido claro. Sua garganta est� dolorosamente seca, e voc� se sente um pouco tonto por causa do calor no t�nel.\n\nSe quiser beber o l�quido, \033[1;35mdigite 147.\033[0;37m\nSe n�o quiser se arriscar a beber e preferir continuar para o norte, \033[1;35mdigite 182.\033[0;37m\n\n");

    printf("\033[1;34mLEMBRE-SE, VOC� PODE ACESSAR SEU INVENT�RIO DIGITANDO 0\033[0;37m\n\n");

    while(loop < 1){
        scanf("%i", &choices);
        switch (choices){
            case 147:
                loop++;
                system("cls");
                OP147();
                break;
            case 182:
                loop++;
                system("cls");
                OP182();
                break;
            case 0:
                inventory();
                enter();
                OP013();
                break;
        }
    }
}

//OPCAO 014
void OP014(){
    stageops = 14;
    save();
    loop = 0;

    printf("\t14 - O t�nel conduz a uma c�mara escura, coberta de espessas teias de aranha. Abrindo caminho entre elas, voc� trope�a em um pequeno cofre de madeira.\n\nSe quiser tentar abrir o cofre, \033[1;35mdigite 157.\033[0;37m\nSe preferir continuar para o norte, \033[1;35mdigite 310.\033[0;37m\n\n");

    printf("\033[1;34mLEMBRE-SE, VOC� PODE ACESSAR SEU INVENT�RIO DIGITANDO 0\033[0;37m\n\n");

    while(loop < 1){
        scanf("%i", &choices);
        switch(choices){
            case 157:
                loop++;
                system("cls");
                OP157();
                break;
            case 310:
                loop++;
                system("cls");
                OP310();
                break;
            case 0:
                inventory();
                enter();
                OP014();
                break;
        }
    }
}

//OPCAO 015
void OP015(){
    loop = 0;

    printf("\t15 - Uma sensa��o de c�cegas desce pela sua espinha enquanto voc� se arrasta cuidadosamente para fora do aposento. De volta ao t�nel, voc� solta um suspiro de al�vio e fecha a porta com for�a. Feliz com sua boa sorte, parte para o oeste mais uma vez.");

    enter();
    OP074();
}

//OPCAO 016
void OP016(){
    stageops = 16;
    save();
    loop = 0;

    printf("\t16 - Voc� s� teve tempo de ouvir o Gnomo dizer: \"Tr�s cr�nios\", antes que um raio branco de energia disparasse da fechadura e o atingisse no peito, derrubando-o inconsciente. Jogue um dado, o resultado mais 1 � reduzido do total da sua ENERGIA. Se voc� ainda estiver vivo, recupera a consci�ncia e o Gnomo manda que tente de novo. Voc� escolheu as gemas erradas da outra vez; portanto, n�o tentar� aquela combina��o novamente.\n\n    A         B         C     \nEsmeralda|Diamante |Safira    -> \033[1;35mDigite 16.\033[0;37m\nDiamante |Safira   |Esmeralda -> \033[1;35mDigite 392.\033[0;37m\nSafira   |Esmeralda|Diamante  -> \033[1;35mDigite 177.\033[0;37m\nEsmeralda|Safira   |Diamante  -> \033[1;35mDigite 287.\033[0;37m\nDiamante |Esmeralda|Safira    -> \033[1;35mDigite 132.\033[0;37m\nSafira   |Diamante |Esmeralda -> \033[1;35mDigite 249.\033[0;37m\n\n");

    printf("\033[1;34mLEMBRE-SE, VOC� PODE ACESSAR SEU INVENT�RIO DIGITANDO 0\033[0;37m\n\n");

    while(loop < 1){
        scanf("%i", &choices);
        switch(choices){
            case 16:
                loop++;
                system("cls");
                OP016();
                break;
            case 392:
                loop++;
                system("cls");
                OP392();
                break;
            case 177:
                loop++;
                system("cls");
                OP177();
                break;
            case 287:
                loop++;
                system("cls");
                OP287();
                break;
            case 132:
                loop++;
                system("cls");
                OP132();
                break;
            case 249:
                loop++;
                system("cls");
                OP249();
                break;
            case 0:
                inventory();
                enter();
                OP016();
                break;
        }
    }
}

//OPCAO 017
void OP017(){
    loop = 0;

    printf("\t17 - Voc� n�o � forte o bastante para for�ar e abrir a pesada porta. A �gua j� est� na cintura agora, e voc� est� exausto por causa dos esfor�os. O n�vel da �gua sobe rapidamente, e voc� se v� boiando cada vez mais alto. At� que seu rosto fica imprensado contra o teto. \033[1;31mLogo fica completamente imerso e n�o tem como prender a respira��o por mais tempo.\033[0;37m");
    death();
}

//OPCAO 018
void OP018(){
    loop = 0;

    printf("\t18 - Para sorte sua, os dentes da naja se cravam na munhequeira de couro que voc� est� usando. A serpente se enrosca de novo bem depressa, pronta para lan�ar outro ataque, quando o An�o ordena que voc� fa�a mais uma tentativa. \033[1;33mDigite \"ROLL\" e teste sua HABILIDADE.\033[0;37m\n\n");


    while(loop < 1){
        gets(startroll);
        if(strcasecmp(startroll, "roll") == 0){
            dice2();
            if(numroll <= hability){
                system("cls");
                OP055();
            }else{
                system("cls");
                OP202();
            }
        }
    }
}

//OPCAO 19
void OP019(){
    loop = 0;

    printf("\t19 - Voc� n�o consegue resistir ao olhar hipn�tico da Medusa quando seus olhares se encontram. \033[1;31mSente os membros enrijecerem e entra em p�nico, indefeso, enquanto se transforma em pedra.\033[0;37m");
    death();
}

//OPCAO 20
void OP020(){
    loop = 0;

    printf("\t20 - Somente sua incr�vel for�a poderia resistir � mordida da aranha venenosa. Contudo, voc� est� enfraquecido e repara que sua m�o est� tremendo ao colocar a Pe�a de Ouro no bolso. \033[1;31mReduza sua HABILIDADE em 1 ponto\033[0;37m. Voc� amaldi�oa a pessoa que largou a mochila e parte para o norte de novo.\n\n");

    if(status_OP020 == 0){
        hability -= 1;
        gold += 1;
        status_OP020 += 1;
        printf("Voc� perdeu 1 de HABILIDADE");
        printf("\nSua HABILIDADE: %i", hability);
        printf("\033[1;33m");
        printf("\n\nVoc� ganhou 1 de GOLD");
        printf("\033[0;37m");
        printf("\nSeu GOLD: %d", gold);
        enter();
        OP279();
    }else{
        printf("\033[1;31mVoc� j� esteve aqui, nada foi adicionado ao seu invent�rio.\033[0;37m\n\n");
        enter();
        OP279();
    }
}

//OPCAO 21
void OP021(){
    loop = 0;

    printf("\t21 - O ferimento n�o teve qualquer efeito sobre a Besta Sangrenta, que continua a atac�-lo t�o furiosamente quanto antes. \033[1;33mDigite \"ROLL\" e teste sua SORTE.\033[0;37m\n\n");

    while(loop < 1){
        gets(startroll);
        if(strcasecmp(startroll, "roll") == 0){
            dice2();
            if(numroll <= luck){
                luck--;
                system("cls");
                OP097();
            }else{
                luck--;
                system("cls");
                OP116();
            }
        }
    }
}

//OPCAO 22
void OP022(){
    stageops = 22;
    save();
    loop = 0;

    printf("\t22 - Embora voc�s fiquem um pouco perturbados na companhia um do outro, sabendo que s� pode haver um vencedor na Prova dos Campe�es, ambos est�o contentes por compartilhar os benef�cios de uma alian�a tempor�ria. Contam um ao outro as explora��es que fizeram at� agora, falam dos monstros e armadilhas que encontraram e dos perigos que venceram. Caminhando em frente, voc�s logo chegam � borda de um po�o largo. � profundo e escuro demais para verem-lhe o fundo. O B�rbaro se oferece para ajud�-lo descer ao fundo com a corda dele, dizendo que tem uma tocha com a qual voc� poder� iluminar o caminho. Voc�:\n\nAceitar� a oferta do B�rbaro? \033[1;35mDigite 63.\033[0;37m\nOferece-se para ajudar a descida dele, j� que ele est� t�o ansioso para investigar o po�o? \033[1;35mDigite 184.\033[0;37m\nSugerir� que, em vez disso, ambos pulem por cima do po�o?\033[1;35m Digite 311.\033[0;37m\n\n");

    printf("\033[1;34mLEMBRE-SE, VOC� PODE ACESSAR SEU INVENT�RIO DIGITANDO 0\033[0;37m\n\n");

    while(loop < 1){
        scanf("%i", &choices);
        switch (choices){
            case 63:
                loop++;
                system("cls");
                OP063();
                break;

            case 184:
                loop++;
                system("cls");
                OP184();
                break;
            case 311:
                loop++;
                system("cls");
                OP311();
                break;
            case 0:
                inventory();
                enter();
                OP022();
                break;
        }
    }
}

//OPCAO 23
void OP023(){
    loop = 0;

    printf("\t23 - O papel traz uma advert�ncia simples, escrita em sangue seco:\033[1;31m \"Cuidado com os Ju�zes da Prova.\"\033[0;37m.Voc� recoloca o papel no prego e corre de volta pelo t�nel para se reunir ao B�rbaro.");

    enter();
    OP154();
}

//OPCAO 24
void OP024(){
    stageops = 24;
    save();
    loop = 0;

    printf("\t24 - Colocada em uma alcova em arco na parede do t�nel, voc� v� uma cadeira de madeira ornamentada, esculpida na forma de uma ave de rapina de apar�ncia demon�aca.\n\nSe voc� quiser se sentar na cadeira, \033[1;35mdigite 324.\033[0;37m\nSe preferir continuar seguindo para o norte, \033[1;35mdigite 188.\033[0;37m\n\n");

    printf("\033[1;34mLEMBRE-SE, VOC� PODE ACESSAR SEU INVENT�RIO DIGITANDO 0\033[0;37m\n\n");

    while(loop < 1){
        scanf("%i", &choices);
        switch(choices){
            case 324:
                loop++;
                system("cls");
                OP324();
                break;
            case 188:
                loop++;
                system("cls");
                OP188();
                break;
            case 0:
                inventory();
                enter();
                OP024();
                break;
        }
    }
}

//OPCAO 25
void OP025(){
    loop = 0;

    printf("\t25 - Embora a temperatura no t�nel esteja mais alta do que voc� conseguiria normalmente tolerar, o l�quido do bambu mant�m-no vivo.");

    enter();
    OP197();
}

//OPCAO 26
void OP026(){
    loop = 0;

    printf("\t26 - A p�lula faz com que voc� se sinta mole e let�rgico. Voc� perde 2 pontos de HABILIDADE. O An�o diz que agora voc� pode prosseguir para o segundo est�gio do teste. Ele pega uma cesta de vime e lhe diz que ela cont�m uma serpente. Vira a cesta e a serpente cai no ch�o. � uma naja, e se ergue no ar, pronta para dar o bote. O An�o diz que pretende testar suas rea��es. Voc� dever� agarrar a naja, com as m�os nuas, pelo pesco�o, evitando as presas mortais. Voc� se agacha, tensionando os m�sculos para o momento decisivo. \033[1;33mDigite \"ROLL\" e teste sua HABILIDADE.\033[0;37m\n\n");

    if(status_OP026 == 0){
        hability -= 2;
        status_OP026 += 1;
        while(loop < 1){
            gets(startroll);
            if(strcasecmp(startroll, "roll") == 0){
                dice2();
                if(numroll <= hability){
                    system("cls");
                    OP055();
                }else{
                    system("cls");
                    OP202();
                }
            }
        }
    }else{
        while(loop < 1){
            gets(startroll);
            if(strcasecmp(startroll, "roll") == 0){
                dice2();
                if(numroll <= hability){
                    system("cls");
                    OP055();
                }else{
                    system("cls");
                    OP202();
                }
            }
        }
    }
}

//OPCAO 27
void OP027(){
    loop = 0;

    printf("\t27 - Voc� caminha at� o apavorado homem e corta a corrente com sua espada. Ele cai de joelhos e se inclina, agradecendo, repetidamente. Diz que, h� quatro anos, entrou na Prova dos Campe�es, mas fracassou. Ele caiu em um po�o e teve que ser resgatado por um Juiz da Prova, um dos administradores do calabou�o do Bar�o Sukumvit. Foi-lhe, ent�o, oferecida a op��o de morrer ou servir como lacaio no Calabou�o da Morte. Para sobreviver, ele trabalhou como escravo, at� que n�o p�de mais suportar e tentou escapar. L�stima, n�o teve �xito e foi capturado pelos Orcas, os guardas volantes do Juiz da Prova. Como corretivo, cortaram-lhe uma das m�os e condenaram-no a um ano de pris�o nessa cela. Voc� pergunta se ele tem alguma informa��o que lhe possa ser �til. Ele co�a a cabe�a: \"Bem, n�o cheguei a me sair exatamente bem aqui, mas, de fato, sei que voc� precisa juntar gemas e pedras preciosas, se espera escapar. N�o sei por que, mas � isso.\" Sem mais dizer, o esfarrapado prisioneiro dispara para fora do aposento, virando � esquerda no t�nel. Voc� resolve prosseguir para o norte e vira � direita no t�nel.");

    enter();
    OP078();
}

//OPCAO 28
void OP028(){
    loop = 0;

    printf("\t28 - A cota de malha do An�o � de ferro da melhor qualidade, obviamente feita por um mestre armeiro. Voc� a tira do corpo dele e a coloca sobre sua cabe�a. \033[1;32mAcrescente 1 ponto de HABILIDADE\033[0;37m. N�o h� mais nada de �til na c�mara, portanto voc� decide investigar o novo t�nel.\n\n");

    if(status_OP028 == 0){
        hability += 1;
        printf("Voc� recebeu 1 de HABILIDADE");
        printf("\nSua HABILIDADE: %i", hability);
        enter();
        OP213();
    }else{
        printf("\033[1;31mVoc� j� esteve aqui, nada foi adicionado ao seu invent�rio.\033[0;37m\n\n");
        enter();
        OP213();
    }
}

//OPCAO 29
void OP029(){
    loop = 0;

    printf("\t29 - O t�nel conduz ao norte por alguma dist�ncia, antes de chegar a um beco sem sa�da. A entrada de um escorrega se projeta da parede leste do t�nel. Parece ser a �nica maneira de sair. Voc� resolve se arriscar e sobe no escorrega. Deslizando suavemente, voc� desce em um aposento, onde aterrissa de costas.");

    enter();
    OP090();
}

//OPCAO 30
void OP030(){
    loop = 0;

    printf("\t30 - Dando um passo � frente, voc� salta para a borda do outro lado do po�o. \033[1;33mDigite \"ROLL\" e teste sua SORTE.\033[0;37m\n\n");

    while(loop < 1){
        gets(startroll);
        if(strcasecmp(startroll, "roll") == 0){
            dice2();
            if(numroll <= luck){
                luck--;
                system("cls");
                OP160();
            }else{
                luck--;
                system("cls");
                OP319();
            }
        }
    }
}

//OPCAO 31
void OP031(){
    stageops = 31;
    save();
    loop = 0;

    printf("\t31 - O Gnomo sorri e diz: \"Bom. Agora, voc� possui uma safira?\".\n\nSe voc� de fato tiver uma safira, \033[1;35mdigite 376.\033[0;37m\nSe n�o, \033[1;35mdigite 3.\033[0;37m\n\n");

    printf("\033[1;34mLEMBRE-SE, VOC� PODE ACESSAR SEU INVENT�RIO DIGITANDO 0\033[0;37m\n\n");

    while(loop < 1){
        scanf("%i", &choices);
        switch(choices){
            case 3:
                loop++;
                system("cls");
                OP003();
                break;
            case 376:
                loop++;
                if(sapphire != 0){
                    system("cls");
                    OP376();
                } else{
                    printf("Voc� n�o possui este item.");
                    enter();
                    OP031();
                }
                break;
            case 0:
                inventory();
                enter();
                OP031();
                break;
        }
}
}

//OPCAO 32
void OP032(){
    loop = 0;

    printf("\t32 - Voc� logo chega a uma outra encruzilhada no t�nel. Um bra�o leva para o leste, mas as pegadas �midas que voc� vem seguindo continuam para o norte, e voc� resolve continuar na trilha delas.");

    enter();
    OP037();
}

//OPCAO 33
void OP033(){
    loop = 0;

    printf("\t33 - Foi um erro ter tateado no interior do buraco com o bra�o da espada. Est� coberto de marcas de suc��o e d� a sensa��o de ter sido esmagado. \033[1;31mVoc� perde 3 pontos de HABILIDADE\033[0;37m. Voc� d� uma espiada para dentro do buraco e v� o toco do tent�culo ensanguentado que pende inerte. Cuidadosamente, retira o gancho e a bolsa de couro, na qual encontra um min�sculo sino de lat�o. Voc� guarda suas novas posses na mochila e segue para o norte.\n\n");

    if(status_OP033 == 0){
        hability -= 3;
        iron_hook += 1;
        brass_bell += 1;
        status_OP033 += 1;

        printf("Voc� perdeu 3 de HABILIDADE");
        printf("\nSua HABILIDADE: %i", hability);
        printf("\033[1;34m");
        printf("\n\nSino de Lat�o foi adicionado a seu invent�rio");
        printf("\nGancho foi adicionado a seu invent�rio");
        enter();
        OP292();
    }else{
        printf("\033[1;31mVoc� j� esteve aqui, nada foi adicionado ao seu invent�rio.\033[0;37m\n\n");
        enter();
        OP292();
    }
}

//OPCAO 34
void OP034(){
    loop = 0;

    printf("\t34 - Voc� tenta for�ar por baixo da esmeralda com a ponta da espada. Para sua grande surpresa, a esmeralda se despeda�a com o contato, soltando um jato de g�s venenoso diretamente no seu rosto. \033[1;31mO g�s o faz desmaiar, e voc� solta a corda, despenca do �dolo e cai no ch�o de pedra.\033[0;37m");
    death();
}

//OPCAO 35
void OP035(){
    stageops = 35;
    save();
    loop = 0;

    printf("\t35 - O t�nel continua para o oeste por v�rias centenas de metros, terminando finalmente em alguns degraus que conduzem a um al�ap�o fechado. Voc� sobe os degraus lentamente, ouvindo vozes abafadas acima. Na penumbra, voc� pode ver que o al�ap�o n�o est� trancado.\n\nSe quiser bater na porta do al�ap�o, \033[1;35mdigite 333.\033[0;37m\nSe preferir irromper pela porta com a espada desembainhada, \033[1;35mdigite 124\033[0;37m\n\n");

    printf("\033[1;34mLEMBRE-SE, VOC� PODE ACESSAR SEU INVENT�RIO DIGITANDO 0\033[0;37m\n\n");

    while (loop < 1){
        scanf("%i", &choices);
        switch (choices){
            case 333:
                loop++;
                system("cls");
                OP333();
                break;
            case 124:
                loop++;
                system("cls");
                OP124();
                break;
            case 0:
                inventory();
                enter();
                OP035();
                break;
        }
    }
}

//OPCAO 36
void OP036(){
    loop = 0;

    printf("\t36- Embora voc� jamais tenha corrido tanto em toda a sua vida, o rochedo chega cada vez mais perto. \033[1;33mDigite \"ROLL\" e teste sua HABILIDADE e ENERGIA.\033[0;37m\n\n");

    while(loop < 1){
        gets(startroll);
        if(strcasecmp(startroll, "roll") == 0){
            dice2();
            if(numroll <= hability && numroll <= energy){
                system("cls");
                OP340();
            }else{
                system("cls");
                OP007();
            }
        }
    }
}

//OPCAO 37
void OP037(){
    stageops = 37;
    save();
    loop = 0;

    printf("\t37 - A passagem se alarga em uma ampla caverna, mais escura, mas muito mais seca. As pegadas desaparecem gradualmente � sua frente. H� um grande �dolo no centro da caverna, com cerca de seis metros de altura. Os olhos da est�tua s�o j�ias, cada uma do tamanho do seu punho. Duas criaturas empalhadas, com apar�ncia de p�ssaros, encontram-se de p� em cada lado do �dolo.\n\nSe voc� quiser subir no �dolo para pegar as j�ias, \033[1;35mdigite 351.\033[0;37m\nSe preferir atravessar a caverna para o t�nel na parede do outro lado, \033[1;35mdigite 239.\033[0;37m\n\n");

    printf("\033[1;34mLEMBRE-SE, VOC� PODE ACESSAR SEU INVENT�RIO DIGITANDO 0\033[0;37m\n\n");

    while(loop < 1){
        scanf("%i", &choices);
        switch (choices){
            case 351:
                loop++;
                system("cls");
                OP351();
                break;
            case 239:
                loop++;
                system("cls");
                OP239();
                break;
            case 0:
                inventory();
                enter();
                OP037();
                break;
        }
    }
}

//OPCAO 38
void OP038(){
    loop = 0;

    printf("\t38 - Em sil�ncio, o homem fica de lado enquanto voc� engole a �gua e devora o p�o. Uma dor aguda lhe invade o est�mago, e voc� cai de joelhos. O velho olha para voc� com desprezo e diz: \"Bem, o que pode esperar quem come comida envenenada?\". \033[1;31mVoc� perde 3 pontos de ENERGIA\033[0;37m. Ele se afasta, arrastando os p�s, e o deixa se contorcendo em dores no ch�o. Voc� acaba recuperando for�a bastante para continuar para o oeste.\n\n");

    if(status_OP038 == 0){
        energy -= 3;
        status_OP038 += 1;
        printf("Voc� perdeu 3 de ENERGIA");
        printf("\nSua ENERGIA: %i\n\n", energy);
        if(energy <= 0){
            death();
        }else{
            printf("Voc� acaba recuperando for�a o bastante para continuar para o oeste.");
            enter();
            OP109();
        }
    }else{
        printf("Voc� perdeu 3 de ENERGIA");
        printf("\nSua ENERGIA: %i\n\n", energy);
        if(energy <= 0){
            death();
        }else{
            printf("Voc� acaba recuperando for�a o bastante para continuar para o oeste.");
            enter();
            OP109();
        }
    }
}

//OPCAO 39
void OP039(){
    stageops = 39;
    save();
    loop = 0;
    monsenergy = 8;
    monshability = 7;

    printf("\t39 - Voc� consegue se desviar das pernas estendidas da Mosca Gigante que mergulha sobre voc�. Recuando, voc� desembainha a espada e se prepara para lutar contra o horroroso inseto, quando ele se volta para atac�-lo outra vez.\n\n\033[1;31mMOSCA GIGANTE HABILIDADE 7 ENERGIA 8\033[0;37m\n\nVoc� pode fugir, correndo de volta para o t�nel, para prosseguir ao norte, \033[1;35mdigite 267.\033[0;37m\nSe preferir ficar e lutar, \033[1;35mdigite 111.\033[0;37m\n\n");

    printf("\033[1;34mLEMBRE-SE, VOC� PODE ACESSAR SEU INVENT�RIO DIGITANDO 0\033[0;37m\n\n");

    while(loop < 1){
        scanf("%i", &choices);
        switch(choices){
            case 267:
                loop++;
                system("cls");
                OP267();
                break;
            case 111:
                loop++;
                system("cls");
                combat1();
                printf("\n\nVoc� derrotou a MOSCA GIGANTE!\n");
                printf("Sua ENERGIA: %i", energy);
                enter();
                OP111();
                break;
            case 0:
                inventory();
                enter();
                OP039();
                break;
        }
    }
}

//OPCAO 40
void OP040(){
    loop = 0;
    monsenergy = 9;
    monshability = 9;

    printf("\t40 - Voc� chama o An�o, dizendo que est� pronto para lutar contra o MINOTAURO. A porta de madeira se ergue lentamente, e voc� v� a assustadora fera, meio homem, meio touro, entrar na arena. Ele bufa e expele vapor pelas narinas, enquanto vai ficando mais e mais furioso, pronto para atacar. S�bito, arranca adiante, girando uma acha de dois gumes.\n\n\033[1;31mMINOTAURO HABILIDADE 9 ENERGIA 9\033[0;37m\n\n");

    enter();
    combat1();
    printf("Voc� sobreviveu ao MINOTAURO\n");
    printf("\n\nSua ENERGIA: %i", energy);
    enter();
    OP163();

}

//OPCAO 41
void OP041(){
    stageops = 41;
    save();
    loop = 0;

    printf("\t41 - Voc� caminha lentamente para a alcova, verificando cuidadosamente o ch�o para n�o cair em outras armadilhas ocultas. Voc� v� que a ta�a cont�m um l�quido vermelho efervescente. Voc�:\n\nBeber� o l�quido vermelho? \033[1;35mDigite 98.\033[0;37m\nDeixar� a ta�a e caminhar� de volta para procurar o B�rbaro? \033[1;35mDigite 126.\033[0;37m\nDeixar� a c�mara para continuar para o oeste? \033[1;35mDigite 83.\033[0;37m\n\n");

    printf("\033[1;34mLEMBRE-SE, VOC� PODE ACESSAR SEU INVENT�RIO DIGITANDO 0\033[0;37m\n\n");

    while(loop < 1){
        scanf("%i", &choices);
        switch(choices){
            case 98:
                loop++;
                system("cls");
                OP098();
                break;
            case 126:
                loop++;
                system("cls");
                OP126();
                break;
            case 83:
                loop++;
                system("cls");
                OP083();
                break;
            case 0:
                inventory();
                enter();
                OP041();
                break;
        }
    }
}

//OPCAO 42
void OP042(){
    loop = 0;

    printf("\t42 - Os dentes da naja se cravam fundo no seu pulso e voc� sente o veneno se alastrando pelo corpo. \033[1;31mVoc� perde 5 pontos de ENERGIA.\033[0;37m\n\n");

    if(status_OP042 == 0){
        energy -= 5;
        status_OP042 += 1;
        printf("Voc� perdeu 5 de ENERGIA");
        printf("\nSua ENERGIA: %i\n\n", energy);
        if(energy <= 0){
            death();
        }else{
            printf("O An�o n�o tem pena e lhe diz para tentar outra vez. \033[1;33mDigite \"ROLL\" e teste sua HABILIDADE.\033[0;37m\n\n");
            while(loop < 1){
                gets(startroll);
                if(strcasecmp(startroll, "roll") == 0){
                    dice2();
                    if(numroll <= hability){
                        system("cls");
                        OP055();
                    }else{
                        system("cls");
                        OP202();
                    }
                }
            }
        }
    }else{
        printf("Voc� perdeu 5 de ENERGIA");
        printf("\nSua ENERGIA: %i\n\n", energy);
        if(energy <= 0){
            death();
        }else{
            printf("O An�o n�o tem pena e lhe diz para tentar outra vez. \033[1;33mDigite \"ROLL\" e teste sua HABILIDADE.\033[0;37m\n\n");
            while(loop < 1){
                gets(startroll);
                if(strcasecmp(startroll, "roll") == 0){
                    dice2();
                    if(numroll <= hability){
                        system("cls");
                        OP055();
                    }else{
                        system("cls");
                        OP202();
                    }
                }
            }
        }
    }
}

//OPCAO 43
void OP043(){
    stageops = 43;
    save();
    loop = 0;
    save();
    printf("\t43 - O t�nel vira abruptamente para a direita e continua para o norte, at� onde a vista alcan�a. H� uma porta entreaberta na parede do lado esquerdo. Voc� ouve algu�m gritando por socorro, a voz vindo do outro lado da porta.\n\nSe voc� quiser abrir a porta, \033[1;35mdigite 200.\033[0;37m\nSe preferir continuar para o norte, \033[1;35mdigite 316.\033[0;37m\n\n");

    printf("\033[1;34mLEMBRE-SE, VOC� PODE ACESSAR SEU INVENT�RIO DIGITANDO 0\033[0;37m\n\n");

    while(loop < 1){
        scanf("%i", &choices);
        switch(choices){
            case 200:
                loop++;
                system("cls");
                OP200();
                break;
            case 316:
                loop++;
                system("cls");
                OP316();
                break;
            case 0:
                inventory();
                enter();
                OP043();
                break;
        }
    }
}

//OPCAO 44
void OP044(){
    loop = 0;
    printf("\t44 - Voc� est� a apenas alguns metros da porta quando ouve o velho atr�s de si enunciar umas palavras estranhas. Instantaneamente, sente os m�sculos endurecerem e a pele esticar. Voc� entra em p�nico, \033[1;31mmas n�o h� nada que possa fazer para impedir a petrifica��o do seu corpo.\033[0;37m");
    death();
}

//OPCAO 45
void OP045(){
    loop = 0;

    printf("\t45 - O disco, afiado como uma navalha, atinge-lhe as costas com terr�vel efeito. \033[1;31mVoc� perde 1 ponto de HABILIDADE e 4 pontos de ENERGIA\033[0;37m\n\n");

    if(status_OP045 == 0){
        hability -= 1;
        energy -= 4;
        status_OP045 += 1;
        printf("Voc� perdeu 4 de ENERGIA");
        printf("\nSua ENERGIA: %i", energy);
        printf("\n\nVoc� perdeu 1 de HABILIDADE");
        printf("\nSua HABILIDADE: %i\n\n", hability);

        if(energy <= 0){
            death();
        }else{
            printf("\n\nVoc� sobreviveu, mas luta para tirar o disco das costas, enquanto o ninja joga mais um.");
            enter();
            OP312();
        }
    }else{
        printf("Voc� perdeu 4 de ENERGIA");
        printf("\nSua ENERGIA: %i", energy);
        printf("\n\nVoc� perdeu 1 de HABILIDADE");
        printf("\nSua HABILIDADE: %i\n\n", hability);

        if(energy <= 0){
            death();
        }else{
            printf("\n\nVoc� sobreviveu, mas luta para tirar o disco das costas, enquanto o ninja joga mais um.");
            enter();
            OP312();
        }
    }
}

//OPCAO 46
void OP046(){
    loop = 0;

    printf("\t46 - Voc� desce cuidadosamente do �dolo e, sem perder mais tempo na caverna, corre para o t�nel adiante na parede norte.");

    enter();
    OP239();
}

//OPCAO 47
void OP047(){
    stageops = 47;
    save();
    loop = 0;
    save();

    printf("\t47 - Voc� tem um tubo oco de madeira?\n\nSe tiver, \033[1;35mdigite 10.\033[0;37m\nSe n�o tiver, \033[1;35mdigite 335.\033[0;37m\n\n");

    printf("\033[1;34mLEMBRE-SE, VOC� PODE ACESSAR SEU INVENT�RIO DIGITANDO 0\033[0;37m\n\n");

    while(loop < 1){
        scanf("%i", &choices);
        switch(choices){
            case 335:
                loop++;
                system("cls");
                OP335();
                break;
            case 10:
                loop++;
                if(wood_tube != 0){
                    system("cls");
                    OP010();
                } else{
                    printf("Voc� n�o possui este item.");
                    enter();
                    OP047();
                }
                break;
            case 0:
                inventory();
                enter();
                OP047();
                break;
        }
    }
}

//OPCAO 48
void OP048(){
    printf("\t48 - Somente sua for�a imensa e determina��o inquebrant�vel evitam que voc� caia inconsciente ao solo. Voc� aperta os dentes e, resoluto, segue adiante.");

    enter();
    OP197();
}

//OPCAO 49
void OP049(){
    stageops = 49;
    save();
    loop = 0;
    save();

    printf("\t49 - Voc� d� uma espiada, virando a esquina, e v� duas pequenas criaturas correndo de voc�. Vestem roupas largas e usam chap�us pontudos e desengon�ados. S�o os travessos LEPRECHAUNS.\n\nSe voc� quiser segui-los, \033[1;35migite 205.\033[0;37m\nSe preferir caminhar de volta para a �ltima encruzilhada e seguir para o norte, \033[1;35mdigite 241.\033[0;37m\n\n");

    printf("\033[1;34mLEMBRE-SE, VOC� PODE ACESSAR SEU INVENT�RIO DIGITANDO 0\033[0;37m\n\n");

    while(loop < 1){
        scanf("%i", &choices);
        switch(choices){
            case 205:
                loop++;
                system("cls");
                OP205();
                break;
            case 241:
                loop++;
                system("cls");
                OP241();
                break;
            case 0:
                inventory();
                enter();
                OP049();
                break;
        }
    }
}

//OPCAO 50
void OP050(){
    loop = 0;

    printf("\t50 - Voc� acorda e v� Throm puxando o anel do seu dedo. Ele joga o anel no ch�o e o esmaga com a acha de guerra. Em seguida, grunhindo para expressar que desaprova sua atitude, sai caminhando para o leste. Com esfor�o, voc� se levanta e o segue cambaleante.");

    enter();
    OP221();
}

//OPCAO 51

void OP051(){
    loop = 0;
    monsenergy = 5;
    monshability = 6;
    printf("\t51 - Os Hobgoblins n�o est�o preparados para o seu ataque, e voc� consegue matar o primeiro antes que ele possa puxar da espada. Voc� se volta para enfrentar o outro Hobgoblin, que rosna de �dio.\n\n\033[1;31mHOBGOBLIN HABILDADE 6 ENERGIA 5\033[0;37m\n\n");

    enter();
    combat1();
    printf("\n\nVoc� derrotou o HOBGOBLIN");
    printf("\n\nSua ENERGIA: %i", energy);
    enter();
    OP009();
}

//OPCAO 52

void OP052(){
    stageops = 52;
    save();
    loop = 0;
    save();

    printf("\t52 - Ao abrir o livro, voc� v� que ele come�a a se desintegrar. As p�ginas se transformando em poeira nas suas m�os. Mas voc� consegue salvar alguns fragmentos e ler o manuscrito. O livro parece ser sobre monstros, e, do que voc� pode concluir, cont�m uma descri��o completa de um ser chamado Besta Sangrenta. � uma horr�vel criatura inchada, com pele grossa e coberta de espinhos e �lceras faciais que se abrem para se tornar falsos olhos, cujo objetivo � esconder o �nico ponto fraco da Besta Sangrenta - seus olhos verdadeiros. Essas monstruosidades geralmente habitam po�os de lodo f�tido que exalam g�s venenoso, t�o forte que pode facilmente deixar uma pessoa inconsciente. A Besta Sangrenta, embora pesada demais para sair da po�a de lodo, tem uma l�ngua longa e poderosa que se enrosca em torno de suas v�timas para arrast�-las para o interior da po�a. Quando a carne das v�timas come�a a apodrecer no lodo abjeto, a Besta Sangrenta a devora. Voc� conta a Throm sobre a grotesca Besta Sangrenta, mas ele simplesmente sacode os ombros e lhe diz para seguir adiante.\n\nSe voc� quiser abrir o livro preto, \033[1;35mdigite 138.\033[0;37m\nDo contr�rio, voc� deve prosseguir para o norte com Throm, \033[1;35mdigite 369.\033[0;37m\n\n");

    printf("\033[1;34mLEMBRE-SE, VOC� PODE ACESSAR SEU INVENT�RIO DIGITANDO 0\033[0;37m\n\n");

    if(status_OP052 == 0){
        knowledge_bloody_beast += 1;
        status_OP052 += 1;
        printf("\033[1;34m");
        printf("Voc� recebeu o conhecimento da Besta Sangrenta, isso foi adicionado �s suas SKILLS.\n");
        printf("\033[0;37m");

        while(loop < 1){
            scanf("%i", &choices);
            switch(choices){
                case 138:
                    loop++;
                    system("cls");
                    OP138();
                    break;
                case 369:
                    loop++;
                    system("cls");
                    OP369();
                    break;
                case 0:
                    inventory();
                    enter();
                    OP052();
                    break;
            }
        }
    }else{
        printf("\033[1;31mVoc� j� esteve aqui, nada foi adicionado ao seu invent�rio.\033[0;37m\n");
        while(loop < 1){
            printf("");
            scanf("%i", &choices);
            switch(choices){
                case 138:
                    loop++;
                    system("cls");
                    OP138();
                    break;
                case 369:
                    loop++;
                    system("cls");
                    OP369();
                    break;
                case 0:
                    inventory();
                    enter();
                    OP052();
                    break;
            }
        }
    }
}

//OPCAO 53

void OP053(){
    stageops = 53;
    save();
    loop = 0;
    save();

    printf("\t53 - A Besta Sangrenta � inchada demais para sair da po�a, mas, com a longa e poderosa l�ngua, varre as cercanias e tenta alcan�ar a sua perna. Felizmente, voc� caiu fora do seu alcance. O ar, ao n�vel do ch�o, n�o cont�m nenhum dos vapores venenosos, mas voc� acorda com dor na garganta. Voc� cobre a boca com a manga da camisa para poder respirar atrav�s dela, e decide o que fazer.\n\nSe voc� quiser correr, contornando a po�a, na dire��o do t�nel, \033[1;35mdigite 370.\033[0;37m\nSe preferir atacar a Besta Sangrenta com sua espada, \033[1;35mdigite 348.\033[0;37m\n\n");

    printf("\033[1;34mLEMBRE-SE, VOC� PODE ACESSAR SEU INVENT�RIO DIGITANDO 0\033[0;37m\n\n");

    while(loop < 1){
        scanf("%i", &choices);
        switch(choices){
            case 370:
                loop++;
                system("cls");
                OP370();
                break;
            case 348:
                loop++;
                system("cls");
                OP348();
                break;
            case 0:
                inventory();
                enter();
                OP053();
                break;
        }
    }
}

//OPCAO 54

void OP054(){
    loop = 0;

    printf("\t54 - O la�o se solta e voc� consegue tir�-lo do pesco�o do �dolo com uma sacudidela. Ele cai ao ch�o com um ru�do alto. Voc� enrola a corda rapidamente e a coloca na mochila. Sem perder mais tempo na caverna, corre para o t�nel na parede norte.");

    enter();
    OP239();
}

//OPCAO 55

void OP055(){
    stageops = 55;
    save();
    loop = 0;
    save();

    printf("\t55 - Com a velocidade de um raio, voc� estica a m�o e segura a naja logo abaixo da boca aberta. Voc� a ergue e, com o bra�o estendido, sacode-a na frente do An�o. Ele fica impass�vel, mas, com seu jeito calmo e sem express�o, diz: \"Por favor, coloque a naja de volta na cesta e prepare-se para a parte final do teste. Siga-me.\". Voc� faz o que ele disse e o segue de volta para a c�mara, onde Throm est� andando de um lado para o outro, evidentemente nervoso. Voc� acena para ele, enquanto o An�o abre uma segunda porta secreta e manda que voc� entre por ela e espere por ele. Outra vez voc� obedece, e se v� em outro aposento circular, embora este se assemelhe a uma pequena arena. O ch�o � coberto de areia, e uma pequena sacada circunda a parede da arena. No lado oposto ao da porta secreta pela qual voc� entrou, h� uma porta de madeira de apar�ncia agourenta. De repente, voc� ouve um grito, e olha para cima, vendo o An�o sorridente na sacada. Ele joga dois peda�os de papel para voc�. Num deles, est�o escritas as palavras SEI PORC�O, e no outro, RUIM NO ATO. Com a voz sempre calma, ele diz: \"Se voc� rearrumar as letras das palavras, descobrir� os nomes de duas criaturas. Voc� pode escolher com qual delas quer lutar na minha Arena da Morte.\"\n\nSe voc� puder identificar a criatura rearrumando as letras de SEI PORC�O, \033[1;35mdigite 143.\033[0;37m\nSe puder identificar a criatura rearrumando as letras de RUIM NO ATO, \033[1;35mdigite 40.\033[0;37m\nSe voc� n�o puder identificar nenhuma das duas criaturas, \033[1;35mdigite 347.\033[0;37m\n\n");

    printf("\033[1;34mLEMBRE-SE, VOC� PODE ACESSAR SEU INVENT�RIO DIGITANDO 0\033[0;37m\n\n");



    while(loop < 1){
        scanf("%i", &choices);
        switch(choices){
            case 143:
                loop++;
                system("cls");
                OP143();
                break;
            case 40:
                loop++;
                system("cls");
                OP040();
                break;
            case 347:
                loop++;
                system("cls");
                OP347();
                break;
            case 0:
                inventory();
                enter();
                OP055();
                break;
        }
    }
}

//OPCAO 56

void OP056(){
    stageops = 56;
    save();
    loop = 0;
    save();

    printf("\t56 - Voc� v� que a obstru��o � causada por um objeto grande e marrom, parecendo um rochedo. Voc� o toca com a m�o e fica surpreso ao descobrir que � macio e esponjoso. \n\nSe voc� quiser tentar subir por cima dele, \033[1;35mdigite 373.\033[0;37m\nSe preferir cort�-lo ao meio com sua espada, \033[1;35mdigite 215.\033[0;37m\n\n");

    printf("\033[1;34mLEMBRE-SE, VOC� PODE ACESSAR SEU INVENT�RIO DIGITANDO 0\033[0;37m\n\n");

    while(loop < 1){
        scanf("%i", &choices);
        switch(choices){
            case 373:
                loop++;
                system("cls");
                OP373();
                break;
            case 215:
                loop++;
                system("cls");
                OP215();
                break;
            case 0:
                inventory();
                enter();
                OP056();
                break;
        }
    }
}

//OPCAO 57

void OP057(){
    loop = 0;

    printf("\t57 - Embora voc� j� tenha examinado a arca cuidadosamente, em busca de quaisquer mecanismos ocultos, n�o consegue ver a armadilha dentro dela. Ao levantar a tampa, uma bola de ferro pendente de uma corda � lan�ada para tr�s, partindo a c�psula de vidro fixada no lado de dentro da tampa. Uma nuvem de g�s venenoso � instantaneamente liberado no ar, e voc� cambaleia, recuando, enquanto tosse e se engasga. \033[1;31mVoc� perde 4 pontos de ENERGIA.\033[0;37m\n\n");

    if(status_OP057 == 0){
        energy -= 4;
        status_OP057 += 1;
        printf("Voc� perdeu 4 de ENERGIA");
        printf("\nSua ENERGIA: %i", energy);

        if(energy <= 0){
            death();
        }else{
            printf("\n\nVoc� sobreviveu ao g�s venenoso");
            enter();
            OP198();
        }
    }else{
        printf("Voc� perdeu 4 de ENERGIA");
        printf("\nSua ENERGIA: %i", energy);

        if(energy <= 0){
            death();
        }else{
            printf("\n\nVoc� sobreviveu ao g�s venenoso");
            enter();
            OP198();
        }
    }
}

//OPCAO 58

void OP058(){
    loop = 0;

    printf("\t58 - Voc� caminha lentamente entre os postes, tomando cuidado para n�o tocar em nenhum deles. \033[1;33mDigite \"ROLL\" e teste sua HABILIDADE.\033[0;37m\n\n");

    while(loop < 1){
        gets(startroll);
        if(strcasecmp(startroll, "roll") == 0){
            dice2();
            if(numroll <= hability){
                system("cls");
                OP080();
            }else{
                system("cls");
                OP246();
            }
        }
    }
}

//OPCAO 59

void OP059(){
    stageops = 59;
    save();
    loop = 0;
    save();

    printf("\t59 - Adiante, a dist�ncia, voc� ouve o som de passos lentos vindo na sua dire��o. Sem saber o que ou quem poderia estar se aproximando, voc� olha em volta, em busca de um lugar para se esconder. Encontra uma fenda grande na parede do t�nel onde n�o bate luz.\n\nSe voc� quiser defrontar-se com o rec�m-chegado de espada na m�o, \033[1;35mdigite 341.\033[0;37m\nSe preferir esconder-se nas sombras, \033[1;35mdigite 283.\033[0;37m\n\n");

    printf("\033[1;34mLEMBRE-SE, VOC� PODE ACESSAR SEU INVENT�RIO DIGITANDO 0\033[0;37m\n\n");

    while(loop < 1){
        scanf("%i", &choices);
        switch(choices){
            case 341:
                loop++;
                system("cls");
                OP341();
                break;
            case 283:
                loop++;
                system("cls");
                OP283();
                break;
            case 0:
                inventory();
                enter();
                OP059();
                break;
        }
    }
}

//OPCAO 60

void OP060(){
    stageops = 60;
    save();
    loop = 0;

    printf("\t60 - O t�nel termina em uma grande porta de carvalho. Throm n�o perde tempo e vai logo testando a ma�aneta, ficando algo admirado ao descobrir que a porta n�o est� trancada. Ele a empurra e voc�s se deparam com uma c�mara iluminada por tochas. Sentado sozinho em uma cadeira ornamentada, h� um AN�O, que os convida a entrar na c�mara. Ao faz�-lo, a porta de carvalho se fecha atr�s de voc�s. \"Aventureiros, voc�s se sa�ram muito bem at� agora\", diz o An�o com voz profunda. \"Contudo, como voc�s dois sabem, s� pode haver um vencedor na Prova dos Campe�es. Como Juiz da Prova, � minha obriga��o para com o Bar�o Sukumvit s� permitir que o mais capaz continue. Portanto, tenho que preparar um teste de intelig�ncia e for�a para eliminar um de voc�s. Por favor, n�o tentem livrar-se de mim. Seria completamente est�pido, pois, como voc�s podem ver, n�o h� nenhuma maneira �bvia de sair desta c�mara, e somente eu sei onde est� a sa�da oculta. Agora, se voc�s n�o se importassem de decidir entre voc�s quem ir� primeiro, eu tratarei de fazer as prepara��es necess�rias.\" Voc� olha para Throm, subitamente com raiva de que a eficaz associa��o de voc�s pudesse ter que terminar. Ele se inclina e sussurra no seu ouvido que voc�s deveriam tentar matar o An�o e preocuparse com a sa�da depois.\n\nSe voc� quiser unir-se a Throm no ataque ao An�o, \033[1;35mdigite 179.\033[0;37m\nSe voc� preferir convencer Throm seguir em frente com o teste do An�o, \033[1;35mdigite 365.\033[0;37m\n\n");

    printf("\033[1;34mLEMBRE-SE, VOC� PODE ACESSAR SEU INVENT�RIO DIGITANDO 0\033[0;37m\n\n");

    while(loop < 1){
        scanf("%i", &choices);
        switch(choices){
            case 179:
                loop++;
                system("cls");
                OP179();
                break;
            case 365:
                loop++;
                system("cls");
                OP365();
                break;
            case 0:
                inventory();
                enter();
                OP060();
                break;
        }
    }
}

//OPCAO 61

void OP061(){
    loop = 0;

    printf("\t61 - Apesar do terr�vel ru�do de campainha nos seus ouvidos, voc� ouve passos descendo pelo t�nel. Seus gritos altos atra�ram um guardi�o do t�nel. H� um HOBGOBLIN de p� junto a voc�. Ele sorri doentiamente enquanto pressiona a ponta da espada contra seu pesco�o. \033[1;31mVoc� n�o tem como se defender e impedir que ele o trespasse.\033[0;37m");
    death();
}

//OPCAO 62

void OP062(){
    stageops = 62;
    loop = 0;
    save();

    printf("\t62 - O Gnomo pula no ar, gritando: \"Belo trabalho, ningu�m jamais conseguiu encontrar todas as tr�s gemas antes! Agora, prepare-separa o teste final, o qual eu explicarei uma vez e somente uma vez. Como voc� pode ver, a fechadura desta porta tem tr�s ranhuras, com as etiquetas A, B e C, cada uma delas constru�da para aceitar uma gema espec�fica. Voc� tem porque p�r uma das suas tr�s gemas em cada uma das ranhuras na ordem certa. Se conseguir isso na primeira tentativa, �timo. Por�m, se puser as gemas nas ranhuras erradas, voc� ser� atingido por um raio de energia da fechadura, o que lhe causar� ferimentos. De qualquer maneira, como eu disse, tenho permiss�o para ajud�-lo um pouco. Se voc� colocar uma gema em sua ranhura correta, mas puser as outras duas erradas, eu gritarei: Uma coroa e dois cr�nios. Se voc� colocar todas as tr�s gemas incorretamente, eu gritarei: Tr�s cr�nios. Voc� ter� permiss�o para tentar repetidamente at� que tenha �xito ou morra. Est� pronto?\" Voc� faz um aceno de cabe�a e caminha adiante para colocar as tr�s gemas nas ranhuras. Resolva que gemas colocar� nas ranhuras com etiquetas:\n\n    A         B         C     \nEsmeralda|Diamante |Safira    -> \033[1;35mDigite 16\033[0;37m\nDiamante |Safira   |Esmeralda -> \033[1;35mDigite 392\033[0;37m\nSafira   |Esmeralda|Diamante  -> \033[1;35mDigite 177\033[0;37m\nEsmeralda|Safira   |Diamante  -> \033[1;35mDigite 287\033[0;37m\nDiamante |Esmeralda|Safira    -> \033[1;35mDigite 132\033[0;37m\nSafira   |Diamante |Esmeralda -> \033[1;35mDigite 249\033[0;37m\n\n");

    printf("\033[1;34mLEMBRE-SE, VOC� PODE ACESSAR SEU INVENT�RIO DIGITANDO 0\033[0;37m\n\n");

    while(loop < 1){
        scanf("%i", &choices);
        switch(choices){
            case 16:
                loop++;
                system("cls");
                OP016();
                break;
            case 392:
                loop++;
                system("cls");
                OP392();
                break;
            case 177:
                loop++;
                system("cls");
                OP177();
                break;
            case 287:
                loop++;
                system("cls");
                OP287();
                break;
            case 132:
                loop++;
                system("cls");
                OP132();
                break;
            case 249:
                loop++;
                system("cls");
                OP249();
                break;
            case 0:
                inventory();
                enter();
                OP062();
                break;
        }
    }
}

//OPCAO 63

void OP063(){
    loop = 0;

    printf("\t63 - Voc� amarra a corda na cintura e segura a tocha que Throm, seu aliado B�rbaro, lhe d�, j� acesa. Segurando a corda frouxa, Throm o vai descendo-o lentamente por sobre a borda do po�o at� as profundezas escuras. Voc� pode ver, com a luz da tocha, que os lados do po�o s�o extremamente lisos. Voc� desce por uns 20 metros antes de chegar ao fundo do po�o. Ali, v� um outro t�nel que segue para o norte, e chama Throm para contar-lhe a descoberta. Ele responde, dizendo que vai amarrar a corda em uma rocha proeminente na borda do po�o e descer�. Voc� ouve o B�rbaro descendo, e logo est�o juntos de novo. Throm recupera a corda, sacudindo-a para solt�-la da rocha, e voc�s partem para o norte pelo novo t�nel.");

    enter();
    OP194();
}

//OPCAO 64

void OP064(){
    loop = 0;

    printf("\t64 - Logo que voc� p�e o anel no dedo, todo seu corpo come�a a tremer. \033[1;33mDigite \"ROLL\" e teste sua HABILIDADE.\033[0;37m\n\n");

    while(loop < 1){
        gets(startroll);
        if(strcasecmp(startroll, "roll") == 0){
            dice2();
            if(numroll <= hability){
                system("cls");
                OP115();
            }else{
                system("cls");
                OP190();
            }
        }
    }
}

//OPCAO 65

void OP065(){
    stageops = 65;
    save();
    loop = 0;

    printf("\t65 - Voc� bebeu uma Po��o encontrada dentro de um livro de couro preto?\n\nSe bebeu, \033[1;35mdigite 345.\033[0;37m\nSe n�o, \033[1;35mdigite 372.\033[0;37m");

    printf("\033[1;34mLEMBRE-SE, VOC� PODE ACESSAR SEU INVENT�RIO DIGITANDO 0\033[0;37m\n\n");

    while(loop < 1){
        scanf("%i", &choices);
        switch(choices){
            case 372:
                loop++;
                system("cls");
                OP372();
                break;
            case 345:
                loop++;
                if(skill_trap_potion != 0){
                    system("cls");
                    OP345();
                } else{
                    printf("Voc� n�o fez isso.");
                    enter();
                    OP065();
                }
                break;
            case 0:
                inventory();
                enter();
                OP065();
                break;
        }
    }
}

//OPCAO 66

void OP066(){
    stageops = 66;
    loop = 0;
    save();

    printf("\t66 - Depois de caminhar pelo t�nel por alguns minutos, voc� chega a uma encruzilhada. Uma seta branca pintada na parede aponta para o oeste. No ch�o, voc� v� pegadas molhadas, feitas por aqueles que entraram antes de voc�. � dif�cil ter certeza, mas parece que tr�s deles seguiram a dire��o da seta, enquanto um resolveu ir para o leste.\n\nSe voc� quiser ir para o oeste, \033[1;35mdigite 293.\033[0;37m\nSe preferir ir para o leste, \033[1;35mdigite 119.\033[0;37m\n\n");

    printf("\033[1;34mLEMBRE-SE, VOC� PODE ACESSAR SEU INVENT�RIO DIGITANDO 0\033[0;37m\n\n");

    while(loop < 1){
        scanf("%d", &choices);
        switch(choices){
            case 293:
                loop++;
                system("cls");
                OP293();
                break;
            case 119:
                loop++;
                system("cls");
                OP119();
                break;
            case 0:
                inventory();
                enter();
                OP066();
                break;
        }
    }
}

//OPCAO 67

void OP067(){
    loop = 0;

    printf("\t67 - Voc� se agarra a um dos pilares submersos da ponte e gruda nele, prendendo a respira��o. Enquanto isso, os Trogloditas chegam � margem e concluem que voc� deve ter sido arrastado rio abaixo para morte certa, j� que o rio desaparece nas profundezas da montanha. A essa altura, seus pulm�es est�o estourando de falta de ar. \033[1;33mDigite \"ROLL\" e teste sua SORTE\033[0;37m outra vez.\n\n");

    while(loop < 1){
        gets(startroll);
        if(strcasecmp(startroll, "roll") == 0){
            dice2();
            if(numroll <= luck){
                luck--;
                system("cls");
                OP146();
            }else{
                luck--;
                system("cls");
                OP219();
            }
        }
    }
}

//OPCAO 68

void OP068(){
    stageops = 68;
    save();
    loop = 0;

    printf("\t68 - Voc� desce a passagem e logo se encontra de p� na borda de um po�o profundo e escuro. A passagem continua para o leste, do outro lado do po�o. Voc� pensa que provavelmente conseguir� pular por cima do po�o, mas n�o tem certeza. H� uma corda que pende do teto e desce sobre o centro do po�o. Voc�:\n\nJogar� seu escudo por cima do po�o e depois pular�? \033[1;35mDigite 271.\033[0;37m\nPular� por cima do po�o carregando todas as suas posses? \033[1;35mDigite 30.\033[0;37m\nUsar� a espada para trazer a corda at� voc�, de modo a poder us�-la para atravessar at� a outra margem? \033[1;35mDigite 212.\033[0;37m\n\n");

    printf("\033[1;34mLEMBRE-SE, VOC� PODE ACESSAR SEU INVENT�RIO DIGITANDO 0\033[0;37m\n\n");

    while(loop < 1){
        scanf("%i", &choices);
        switch(choices){
            case 271:
                loop++;
                system("cls");
                OP271();
                break;
            case 30:
                loop++;
                system("cls");
                OP030();
                break;
            case 212:
                loop++;
                system("cls");
                OP212();
                break;
            case 0:
                inventory();
                enter();
                OP068();
                break;
        }
    }
}

//OPCAO 69

void OP069(){
    loop = 0;

    printf("\t69 - Erva n�o nota que voc� abriu a porta. Voc� se esgueira para fora do aposento, fecha a porta silenciosamente e se v� no fim de um outro t�nel.");

    enter();
    OP305();
}

//OPCAO 70

void OP070(){
    loop = 0;

    printf("\t70 - Voc� consegue mergulhar para o lado, por pouco, antes que o rochedo despenque sobre o ch�o do t�nel, rachando a pedra. Enquanto se limpa, nota que h� luz do sol no fim do t�nel. Voc� corre para l�, alegre com a bela vis�o do c�u azule das �rvores verdes. Ao correr para fora do t�nel, voc� espera ser cumprimentado por multid�es vibrantes, mas fica horrorizado com o que v�. N�o h� recep��o de her�i que possa vir das pessoas � sua volta. Est�o todos mortos. Voc� est�, na realidade, de p� em uma c�mara fria, o ch�o coberto de cad�veres e esqueletos com armaduras - a sa�da para a vit�ria era apenas uma ilus�o! S� os restos dos aventureiros do passado s�o reais. Voc� corre de volta para o t�nel, mas colide com uma barreira invis�vel.\033[1;31m Voc� caiu na armadilha e est� condenado a terminar seus dias na c�mara dos mortos.\033[0;37m");
    death();
}

//OPCAO 71

void OP071(){
    loop = 0;

    printf("\t71 - Mais uma vez, voc� estica a m�o para o pergaminho, s� que dessa vez ele est� em meio a uma pilha de ossos quebrados. Ao desenrol�-lo, voc� v� o mapa de um aposento com o desenho de uma criatura pavorosa dentro. Embaixo da figura do monstro, h� uma rima que diz: \"Se voc� encontrar a Mant�cora, � bom de sua cauda cuidar. Proteja-se dos espinhos que ir�o voar pelo ar.\"Voc� enrola o peda�o de pergaminho e o coloca na mochila. Repetindo a rima muitas vezes para si mesmo, voc� caminha para o outro lado, em dire��o � alcova.");

    enter();
    OP128();
}

//OPCAO 72

void OP072(){
    loop = 0;

    printf("\t72 - O Espelho se quebra, lan�ando fragmentos de vidro por toda parte. As quatro faces do Dem�nio do Espelho gritam de agonia, e aparecem rachaduras em todas elas. Em seguida, elas tamb�m se partem e caem ao ch�o numa pilha de cacos de vidro. Infelizmente ao quebrar o espelho, voc� cortou seriamente o bra�o com que segura a espada. Embora sua for�a n�o tenha sido afetada, sua habilidade com as armas foi prejudicada. \033[1;31mVoc� perde 2 pontos de HABILIDADE antes de continuar na sua jornada para o norte.\033[0;37m\n\n");

    if(status_OP072 == 0){
        hability -= 2;
        status_OP072 += 1;
        printf("Voc� perdeu 2 de HABILIDADE");
        printf("\nSua HABILIDADE: %i", hability);
        enter();
        OP122();
    }else{
        printf("\033[1;31mVoc� j� esteve aqui, nada foi adicionado ao seu invent�rio.\033[0;37m\n\n");
        printf("Voc� perdeu 2 de HABILIDADE");
        printf("\nSua HABILIDADE: %i", hability);
        enter();
        OP122();
    }
}

//OPCAO 73

void OP073(){
    stageops = 73;
    save();
    loop = 0;

    printf("\t73 - Se quiser, poder� caminhar de volta � procura do B�rbaro, \033[1;35mdigite 126.\033[0;37m\nDo contr�rio, saia da c�mara para continuar para o oeste, \033[1;35mdigite 83.\033[0;37m\n\n");

    printf("\033[1;34mLEMBRE-SE, VOC� PODE ACESSAR SEU INVENT�RIO DIGITANDO 0\033[0;37m\n\n");

    while(loop < 1){
        scanf("%i", &choices);
        switch(choices){
            case 126:
                loop++;
                system("cls");
                OP126();
                break;
            case 83:
                loop++;
                system("cls");
                OP083();
                break;
            case 0:
                inventory();
                enter();
                OP073();
                break;
        }
    }
}

//OPCAO 74

void OP074(){
    stageops = 74;
    save();
    loop = 0;

    printf("\t74 - O t�nel faz uma curva fechada para a direita, e voc� se v� em uma esp�cie de galeria, coberta de espelhos por uns 20 metros. Um esqueleto humano parece estar sendo arrastado a meio caminho atrav�s de um espelho da parede da direita. S�bito, um ser grotesco, com quatro bra�os e quatro faces que gritam, emerge do espelho, barrando-lhe a passagem. Caminha lentamente na sua dire��o, todos os bra�os estendidos para agarr�-lo. � o DEM��NIO DO ESPELHO, de outro plano dimensional, que veio para levar seu esp�rito. Voc�:\n\nFar� um desejo (se estiver usando um Anel dos Desejos)? \033[1;35mDigite 265.\033[0;37m\nTentar� quebrar os espelhos? \033[1;35mDigite 300.\033[0;37m\nAtacar� o Dem�nio do Espelho com sua espada? \033[1;35mDigite 327.\033[0;37m\n\n");

    printf("\033[1;34mLEMBRE-SE, VOC� PODE ACESSAR SEU INVENT�RIO DIGITANDO 0\033[0;37m\n\n");

    while(loop < 1){
        scanf("%i", &choices);
        switch(choices){
            case 265:
                if(wish_ring != 0){
                    loop++;
                    wish_ring -= 1;
                    system("cls");
                    OP265();
                    break;
                } else{
                    printf("\033[1;31m\nVoc� n�o possui este item\033[0;37m");
                    enter();
                    OP074();
                }
            case 300:
                loop++;
                system("cls");
                OP300();
                break;
            case 327:
                loop++;
                system("cls");
                OP327();
                break;
            case 0:
                inventory();
                enter();
                OP074();
                break;
        }
    }
}

//OPCAO 75

void OP075(){
    stageops = 75;
    save();
    loop = 0;

    printf("\t75 - Voc� esfrega o l�quido nos seus ferimentos, mas eles n�o saram. Olhando fixamente para a garrafa vazia, voc� fica se perguntando o que o l�quido seria exatamente.\n\nSe quiser, poder� abrir o livro vermelho, \033[1;35mdigite 52.\033[0;37m\nDo contr�rio, voc� deve continuar para o norte com Throm, \033[1;35mdigite 369.\033[0;37m\n\n");

    printf("\033[1;34mLEMBRE-SE, VOC� PODE ACESSAR SEU INVENT�RIO DIGITANDO 0\033[0;37m\n\n");

    while(loop < 1){
        scanf("%i", &choices);
        switch(choices){
            case 52:
                loop++;
                system("cls");
                OP052();
                break;
            case 369:
                loop++;
                system("cls");
                OP369();
                break;
            case 0:
                inventory();
                enter();
                OP075();
                break;
        }
    }
}

//OPCAO 76

void OP076(){
    stageops = 76;
    save();
    loop = 0;

    printf("\t76 - Voc� d� a volta pela enorme massa morta do Verme da Rocha e d� uma espiada dentro da escurid�o de seu buraco perfurado. Voc� s� consegue ver alguns metros, mas pode notar que ele se inclina levemente e � t�mido por causa da gosma secretada pelo Verme da Rocha.\n\nSe voc� quiser explorar o buraco de broca, \033[1;35mdigite 317.\033[0;37m\nSe preferir caminhar para o oeste pelo t�nel, \033[1;35mdigite 117.\033[0;37m\n\n");

    printf("\033[1;34mLEMBRE-SE, VOC� PODE ACESSAR SEU INVENT�RIO DIGITANDO 0\033[0;37m\n\n");

    while(loop < 1){
        scanf("%i", &choices);
        switch(choices){
            case 317:
                loop++;
                system("cls");
                OP317();
                break;
            case 117:
                loop++;
                system("cls");
                OP117();
                break;
            case 0:
                inventory();
                enter();
                OP076();
                break;
        }
    }
}

//OPCAO 77

void OP077(){
    loop = 0;

    printf("\t77 - Voc� cambaleia pela porta aberta para outro t�nel, no fim do qual est� a vis�o bem-vinda da luz do dia. Com grande surpresa, voc� v� o Gnomo ca�do, morto, na metade do caminho do t�nel, com uma seta de besta cravada na cabe�a. O Gnomo, no esfor�o por libertar-se, caiu na armadilha final do Bar�o Sukumvit.\033[1;33m Voc� passa por ele rumo � luz do sol brilhante.\033[0;37m");

    enter();
    OP400();
}
//OPCAO 78

void OP078(){
    stageops = 78;
    save();
    loop = 0;
    printf("\t78 - H� um cano com cerca de um metro de di�metro aberto na parede da direita. Est� escuro demais para se ver muito abaixo nele. Voc� grita dentro do cano de ferro e ouve sua voz ecoar por alguns instantes at� desaparecer.\n\nSe voc� quiser engatinhar pelo cano, \033[1;35mdigite 301.\033[0;37m\nSe preferir continuar para o norte, \033[1;35mdigite 142.\033[0;37m\n\n");

    printf("\033[1;34mLEMBRE-SE, VOC� PODE ACESSAR SEU INVENT�RIO DIGITANDO 0\033[0;37m\n\n");

    while (loop < 1){
        scanf("%d", &choices);
        switch(choices){
            case 301:
                loop++;
                system("cls");
                OP301();
                break;
            case 142:
                loop++;
                system("cls");
                OP124();
                break;
            case 0:
                inventory();
                enter();
                OP078();
                break;
        }
    }
}

//OPCAO 79

void OP079(){
    printf("\t79 - Voc� segura os bra�os da cadeira firmemente, esperando que uma onda de energia se espalhasse pelo seu corpo. \033[1;33mDigite \"ROLL\" e teste sua SORTE.\033[0;37m\n\n");

    while(loop < 1){
        gets(startroll);
        if(strcasecmp(startroll, "roll") == 0){
            dice2();
            if(numroll <= luck){
                luck--;
                system("cls");
                OP106();
            }else{
                luck--;
                system("cls");
                OP383();
            }
        }
    }
}


//OPCAO 80

void OP080(){
    printf("\t80 - Voc� vai com calma e consegue passar pelo �ltimo poste sem ter tocado em nenhum deles. Corre para o leste, ainda seguindo os dois pares de pegadas.");

    enter();
    OP313();
}

//OPCAO 81

void OP081(){
    stageops = 81;
    save();
    loop = 0;

    printf("\t81 - A �nica mob�lia no quarto do Goblin consiste em uma mesa, duas cadeiras e um arm�rio de parede. H� duas portas fechadas, uma na parede oeste, outra na parede norte. Voc�:\n\nAbrir� o arm�rio? \033[1;35mDigite 307.\033[0;37m\nAbrir� a porta do oeste? \033[1;35mDigite 263.\033[0;37m\nAbrir� a porta do norte? \033[1;35mDigite 136.\033[0;37m\n\n");

    printf("\033[1;34mLEMBRE-SE, VOC� PODE ACESSAR SEU INVENT�RIO DIGITANDO 0\033[0;37m\n\n");

    while (loop < 1){
        scanf("%d", &choices);
        switch(choices){
            case 307:
                loop++;
                system("cls");
                OP307();
                break;
            case 263:
                loop++;
                system("cls");
                OP263();
                break;
            case 136:
                loop++;
                system("cls");
                OP136();
                break;
            case 0:
                inventory();
                enter();
                OP081();
                break;
        }
    }
}

//OPCAO 82

void OP082(){
    printf("\t82 - Quando o Diabo do Po�o bate como corpo contra a parede, voc� solta a corda e cai em seguran�a no ch�o. Voc� corre na dire��o das portas duplas e fica aliviado ao senti-las se abrirem quando as empurra; deixa que elas se fechem atr�s de si e segue para o norte pelo t�nel.");

    enter();
    OP214();
}

//OPCAO 83

void OP083(){
    printf("\t83 - A passagem logo conduz a uma encruzilhada. Voc� repara em mais pegadas no ch�o, possivelmente uns tr�s pares, dirigindo-se ao norte pela passagem do sul. Resolve segui-las.");

    enter();
    OP037();
}

//OPCAO 84

void OP084(){
    loop = 0;

    printf("\t84 - \033[1;33mDigite \"ROLL\" e role os dados.\033[0;37m\n\n");

    while(loop < 1){
        gets(startroll);
        if(strcasecmp(startroll, "roll") == 0){
            dice2();
            if(numroll <= 8){
                system("cls");
                OP121();
            }else{
                system("cls");
                OP152();
            }
        }
    }
}

//OPCAO 85

void OP085(){
    printf("\t85 - Antes que voc� possa fazer qualquer outra coisa, o velho murmura umas palavras estranhas. Voc� sente os m�sculos se enrijecerem e a pele se esticar. Come�a a entrar em p�nico, \033[1;31mmas n�o h� nada que possa fazer para impedir a petrifica��o do seu corpo.\033[0;37m");
    death();
}

//OPCAO 86

void OP086(){
    printf("\t86 - A chave gira na fechadura, e a porta se abre para um cruzamento de quatro caminhos do t�nel. N�o h� nada a ser visto a leste ou a oeste, a n�o ser os j� conhecidos cristais do teto que continuam a produzir luz fraca. Subitamente, voc� ouve um chamado: \"Por aqui, por aqui, voc� est� no caminho certo.\" A voz parece estar vindo de algum lugar bem � sua frente. N�o resistindo � curiosidade, voc� resolve atender ao chamado.");
    //Va para 187

    enter();
    OP187();
}

//OPCAO 87

void OP087(){
    printf("\t87 - A porta se abre para um aposento grande.");
    //va para 381

    enter();
    OP381();
}

//OPCAO 88

void OP088(){
    stageops = 88;
    save();
    loop = 0;

    printf("\t88 - Logo que os TROGLODITAS o v�em pegam os arcos e correm para cerc�-lo. Para seu horror, o l�der d� um passo adiante e declara que voc� � prisioneiro deles e ter� que se submetera uma prova, segundo o rito milenar, a Corrida da Flecha.\n\nSe voc� estiver disposto a participar da Corrida da Flecha, \033[1;35mdigite 343.\033[0;37m\nSe preferir tentar lutar para fugir, \033[1;35mdigite 268.\033[0;37m\n\n");

    printf("\033[1;34mLEMBRE-SE, VOC� PODE ACESSAR SEU INVENT�RIO DIGITANDO 0\033[0;37m\n\n");

    while(loop < 1){
        scanf("%i", &choices);
        switch(choices){
            case 343:
                loop++;
                system("cls");
                OP343();
                break;
            case 268:
                loop++;
                system("cls");
                OP268();
                break;
            case 0:
                inventory();
                enter();
                OP088();
                break;
        }
    }
}

//OPCAO 89

void OP089(){
    printf("\t89 - De volta � solidez do ch�o da caverna, voc� tenta sacudir a corda para que saia do pesco�o do �dolo. \033[1;33mDigite \"ROLL\" e teste sua SORTE.\033[0;37m\n\n");

    while(loop < 1){
        gets(startroll);
        if(strcasecmp(startroll, "roll") == 0){
            dice2();
            if(numroll <= luck){
                luck--;
                system("cls");
                OP054();
            }else{
                luck--;
                system("cls");
                OP261();
            }
        }
    }
}

//OPCAO 90

void OP090(){
    stageops = 90;
    save();
    loop = 0;

    printf("\t90 - Logo que se levanta, voc� se defronta com o quadro mais repulsivo que seus olhos jamais viram. Ali, na sua frente, chafurda numa po�a circular de lodo f�tido uma criatura inchada, inacreditavelmente horr�vel. O corpo � verde e coberto de amea�adores espinhos. A cara � um amontoado de feridas vermelhas, uma das quais subitamente se abre para revelar mais um dos muitos olhos sinistros que tudo v�em. Um caminho estreito contorna a borda da po�a e leva a um outro t�nel na parede do outro lado.\n\nSe voc� j� tiver lido detalhes sobre a abjeta BESTA SANGRENTA em um livro encadernado em couro, \033[1;35mdigite 172.\033[0;37m\nSe voc� n�o tiver lido o livro, \033[1;35mdigite 357.\033[0;37m\n\n");

    //ITEM
    printf("\033[1;34mLEMBRE-SE, VOC� PODE ACESSAR SEU INVENT�RIO DIGITANDO 0\033[0;37m\n\n");

    while(loop < 1){
        scanf("%i", &choices);
        switch(choices){
            case 172:
                loop++;
                if(knowledge_bloody_beast != 0){
                    system("cls");
                    OP172();
                }else{
                    printf("Voc� n�o leu esse item.");
                    enter();
                    OP090();
                }
                break;
            case 357:
                loop++;
                system("cls");
                OP357();
                break;
            case 0:
                inventory();
                enter();
                OP090();
                break;
        }
    }
}

//OPCAO 91

void OP091(){
    printf("\t91 - A ma�a de ferro do Orca atinge-lhe o bra�o, jogando sua espada no ch�o. Voc� ter� que lutar com as m�os nuas, o que lhe \033[1;31mreduz a HABILIDADE em 4 pontos enquanto durar o combate\033[1;37m. Felizmente, o t�nel � estreito demais para os dois Orcas atacarem-no ao mesmo tempo. Lute com um de cada vez.\n\n\033[1;31mPrimeiro ORCA HABILIDADE 5 ENERGIA 5\nSegundo ORCA HABILIDADE 6 ENERGIA 4\033[0;37m\n\n");

    monsenergy = 5;
    monshability = 5;
    hability -= 4;
    printf("Sua HABILIDADE: %d", hability);
    enter();
    combat1();
    printf("\n\nSua ENERGIA: %d", energy);
    printf("\n\nVOC� ENFRENTAR� A SEGUNDA ORCA! SE PREPARE PARA O COMBATE");
    monsenergy = 4;
    monshability = 6;
    enter();
    combat1();
    printf("Voc� recupera a sua espada e sua habilidade retorna ao normal");
    hability += 4;
    printf("\n\nSua HABILIDADE: %d", hability);
    enter();
    OP257();
}

//OPCAO 92

void OP092(){
    printf("\t92 - Reunindo todas as suas for�as, voc� desfere um golpe final no Dem�nio do Espelho com sua espada. Com um som de estourar os t�mpanos, abrem-se rachaduras no rosto e membros do monstro. As v�rias bocas gritam de agonia nos estertores da morte, antes do Dem�nio se despeda�ar completamente numa pilha de min�sculos cacos. Voc� solta um enorme suspiro de al�vio e depois se apressa a seguir em frente.");
    //Va para 122

    enter();
    OP122();
}

//OPCAO 93

void OP093(){
    stageops = 93;
    save();
    loop = 0;

    printf("\t93 - A porta se abre para um pequeno e escuro aposento, contendo apenas, na parede do lado oposto, uma robusta arca de madeira em cima de uma prateleira. No ch�o, coberto de poeira espessa, voc� pode ver claramente pegadas frescas que v�o at� a arca e retornam � porta. Voc� se pergunta se um dos seus rivais est� � sua frente na \"Caminhada\" ou se a arca s� foi posta na prateleira recentemente por um dos Ju�zes da Prova.\n\nSe voc� quiser entrar no aposento e abrir a arca, \033[1;35mdigite 284.\033[0;37m\nSe preferir continuar percorrendo o t�nel, \033[1;35mdigite 230.\033[0;37m\n\n");

    printf("\033[1;34mLEMBRE-SE, VOC� PODE ACESSAR SEU INVENT�RIO DIGITANDO 0\033[0;37m\n\n");

    while(loop < 1){
        scanf("%i", &choices);
        switch(choices){
            case 284:
                loop++;
                system("cls");
                OP284();
                break;
            case 230:
                loop++;
                system("cls");
                OP230();
                break;
            case 0:
                inventory();
                enter();
                OP093();
                break;
        }
    }
}

//OPCAO 94

void OP094(){
    printf("\t94 - Respirando fundo, voc� se debru�a sobre o po�o e mergulha o bra�o na massa de vermes que se contorcem. Eles s�o frios e viscosos, e o contato � extremamente desagrad�vel, mas, pelo menos, s�o inofensivos, e voc� consegue pegar o punhal pelo cabo. Ao sacudi-lo firmemente, ele sai da rachadura em que a ponta estava cravada. Admirando-lhe a beleza, e imaginando se ele teria um dia pertencido a um competidor de pouca sorte, voc� p�e o punhal ornamentado de opala firmemente no cinto e sai da caverna.\n\n");

    if(status_OP094 == 0){
        dagger += 1;
        status_OP094 += 1;
        printf("\033[1;34mUma Adaga foi adicionada a seu invent�rio\033[0;37m");
        enter();
        OP174();
    }else{
        printf("\033[1;31mVoc� j� esteve aqui, nada foi adicionado ao seu invent�rio.\033[0;37m\n\n");
        enter();
        OP174();
    }
}

//OPCAO 95

void OP095(){
    printf("\t95 - O anel de ferro est� preso a um pequeno al�ap�o. � f�cil  puxa -lo, e, dentro de um pequeno compartimento, voc� encontra um escudo, finamente trabalhado, feito do mais puro ferro. Maravilhado com o esplendor da pe�a, voc� a amarra ao seu bra�o. \033[1;32mAcrescente 1 ponto de HABILIDADE\033[0;37m. Voc� caminha na dire��o das portas duplas e as empurra.\n\n");

    if(status_OP095 == 0){
        hability += 1;
        status_OP095 += 1;
        printf("Voc� ganhou 1 de HABILIDADE");
        printf("\nSua ENERGIA: %i", energy);
        enter();
        OP248();
    }else{
        printf("\033[1;31mVoc� j� esteve aqui, nada foi adicionado ao seu invent�rio.\033[0;37m\n\n");
        enter();
        OP248();
    }
}

//OPCAO 96

void OP096(){
    printf("\t96 - Seu segundo golpe tamb�m n�o consegue partir o espelho. O Dem�nio do Espelho estica um bra�o, agarra-lhe o pulso e come�a a pux�-lo na dire��o do espelho. A for�a � incr�vel, e, apesar de todos os seus esfor�os, voc� n�o consegue resistir. A cada segundo, voc� chega mais perto do espelho. Quando o Dem�nio do Espelho toca o espelho, desaparece atrav�s dele. Com horror, voc� v� seu pr�prio bra�o desaparecer tamb�m atrav�s do espelho, e o resto do corpo logo tem o mesmo destino. \033[1;31mVoc� est� agora em um mundo de espelhos de outra dimens�o, do qual jamais retornar�.\033[0;37m");
    death();
}

//OPCAO 97

void OP097(){
    loop = 0;
    printf("\t97 - Voc� n�o sabe, mas a Besta Sangrenta s� tem um ponto fraco: seus olhos reais. Mais por sorte do que por prop�sito, voc� crava sua l�mina profundamente em um deles, e a Besta Sangrenta desaba de volta na po�a. Depois de medonhas convuls�es, ela afunda sob a superf�cie oleosa da po�a. Sem esperar para ver se ela vai se recuperar, voc� corre e entra no t�nel, ansioso por se afastar da c�mara t�xica da Besta Sangrenta o mais r�pido poss�vel.");
    //Va para 134

    enter();
    OP134();
}


//OPCAO 98

void OP098(){
    loop = 0;

    printf("\t98 - Erguendo a ta�a, voc� aciona um mecanismo de mola, e um dardo � disparado da perna da mesa de madeira. \033[1;33mDigite \"ROLL\" e teste sua SORTE.\033[0;37m\n\n");

    while(loop < 1){
        gets(startroll);
        if(strcasecmp(startroll, "roll") == 0){
            dice2();
            if(numroll <= luck){
                luck--;
                system("cls");
                OP105();
            }else{
                luck--;
                system("cls");
                OP235();
            }
        }
    }
}

//OPCAO 99

void OP099(){
    stageops = 99;
    save();
    loop = 0;

    printf("\t99 - Sorrindo, voc� diz a Erva que a acha muito parecida com Barriga Azeda. Ent�o, enquanto ela olha com admira��o para a pintura, voc� pega um banco quebrado, aproxima-se silenciosamente por tr�s dela e golpeia-lhe a cabe�a com toda a for�a. Para seu imenso al�vio, Erva cai sem sentidos.\n\nSe voc� quiser revistar-lhe o quarto, \033[1;35mdigite 266.\033[0;37m\nSe n�o, saia pela porta da parede leste. Voc� se encontrar� no final de um t�nel, \033[1;35mdigite 305.\033[0;37m\n\n");

    printf("\033[1;34mLEMBRE-SE, VOC� PODE ACESSAR SEU INVENT�RIO DIGITANDO 0\033[0;37m\n\n");

    while(loop < 1){
        scanf("%i", &choices);
        switch(choices){
            case 266:
                loop++;
                system("cls");
                OP266();
                break;
            case 305:
                loop++;
                system("cls");
                OP305();
                break;
            case 0:
                inventory();
                enter();
                OP099();
                break;
        }
    }
}

//OPCAO 100

void OP100(){
    stageops = 100;
    save();
    loop = 0;

    printf("\t100 - Alguns metros adiante, descendo a passagem, voc� v� uma outra porta fechada na parede da esquerda. H� uma letra X na placa central da porta. Colocando o ouvido na porta, voc� escuta atentamente, mas n�o consegue ouvir nada.\n\nSe voc� quiser abrir a porta, \033[1;35mdigite 87.\033[0;37m\nSe preferir continuar caminhando para o norte, \033[1;35mdigite 217.\033[0;37m\n\n");

    printf("\033[1;34mLEMBRE-SE, VOC� PODE ACESSAR SEU INVENT�RIO DIGITANDO 0\033[0;37m\n\n");

    while(loop < 1){
        scanf("%i", &choices);
        switch(choices){
            case 87:
                loop++;
                system("cls");
                OP087();
                break;
            case 217:
                loop++;
                system("cls");
                OP217();
                break;
            case 0:
                inventory();
                enter();
                OP100();
                break;
            default:
                break;
        }
    }
}

//OPCAO 101

void OP101(){
    printf("\t101 - A correnteza do rio � bastante forte, e, atrapalhado pela armadura e a mochila, voc� n�o est� em condi��o de nadar contra ela. Em poucos segundos, � arrastado por baixo da ponte. De p� na margem do rio, os Trogloditas olham, riem e gracejam, \033[1;31menquanto voc� desce o rio para encontrar a morte nas profundezas da montanha.\033[0;37m");
    death();
}

//OPCAO 102

void OP102(){
    stageops = 102;
    save();
    loop = 0;

    printf("\t102 - Voc� entra em um aposento pequeno e completamente vazio. Logo a porta se fecha atr�s de voc�. Repentinamente, uma voz ressoa, vinda de lugar nenhum: \"Bem vindo ao Calabou�o da Morte, o engenhoso labirinto assassino do meu senhor. Aventureiro, creio que voc� apresentar� seus respeitos ao meu senhor gritando seu nome?\".Voc� gritar�:\n\nSalve, Sukumvit? \033[1;35mDigite 133.\033[0;37m\nSukumvit � um verme? \033[1;35mDigite 251.\033[0;37m\n\n");

    printf("\033[1;34mLEMBRE-SE, VOC� PODE ACESSAR SEU INVENT�RIO DIGITANDO 0\033[0;37m\n\n");

    while(loop < 1){
        scanf("%i", &choices);
        switch(choices){
            case 133:
                loop++;
                system("cls");
                OP133();
                break;
            case 251:
                loop++;
                system("cls");
                OP251();
                break;
            case 0:
                inventory();
                enter();
                OP102();
                break;
        }
    }
}

//OPCAO 103

void OP103(){
    loop = 0;

    printf("\t103 - Voc� respira o g�s venenoso e come�a a se engasgar. \033[1;31mVoc� perde 3 pontos de ENERGIA.\033[0;37m");

    if(status_OP103 == 0){
        energy -= 3;
        status_OP103 += 1;
        if(energy < 1){
            death();
        }
        else{
            printf("\n\nSua ENERGIA: %i", energy);
            enter();
            OP077();
        }
    }else{
        energy -= 3;
        if(energy < 1){
            death();
        }
        else{
            printf("\033[1;31mVoc� j� esteve aqui, nada foi adicionado ao seu invent�rio.\033[0;37m\n\n");
            printf("\n\nSua ENERGIA: %i", energy);
            enter();
            OP077();
        }
    }
}
//OPCAO 104

void OP104(){
    loop = 0;
    printf("\t104 - Reagindo rapidamente, voc� consegue saltar por cima da l�ngua estendida e correr para o t�nel, deixando a Besta Sangrenta a chafurdar na po�a � espera de outra v�tima.");
    //Va para 134

    enter();
    OP134();
}

//OPCAO 105

void OP105(){
    stageops = 105;
    save();
    loop = 0;

    printf("\t105 - Seus reflexos s�o precisos, e voc� rapidamente pula de lado. O dardo passa assobiando, por pouco n�o o atingindo, e se choca contra a parede do outro lado. Voc� v� a c�lice jogada no ch�o, e o l�quido vermelho escorrendo pela pedra cinzenta como pequenos riachos. Pelo menos a ta�a pode ser de alguma utilidade, portanto voc� a p�e na mochila.\n\nSe quiser, poder� caminhar de volta para revistar o B�rbaro, \033[1;35mdigite 126.\033[0;37m\nDo contr�rio, saia da c�mara para continuar para o oeste, \033[1;35mdigite 83.\033[0;37m\n\n");

    printf("\033[1;34mLEMBRE-SE, VOC� PODE ACESSAR SEU INVENT�RIO DIGITANDO 0\033[0;37m\n\n");

    if(status_OP105 == 0){
        chalice += 1;
        status_OP105 += 1;
        printf("A ta�a foi adicionada ao seu invent�rio.");
        while(loop < 1){
            scanf("%i", &choices);
            switch(choices){
                case 126:
                    loop++;
                    system("cls");
                    OP126();
                    break;
                case 83:
                    loop++;
                    system("cls");
                    OP083();
                    break;
                case 0:
                    inventory();
                    enter();
                    OP105();
                    break;
            }
        }
    }else{
        while(loop < 1){
            printf("\033[1;31mVoc� j� esteve aqui, nada foi adicionado ao seu invent�rio.\033[0;37m\n\n");
            scanf("%i", &choices);
            switch(choices){
                case 126:
                    loop++;
                    system("cls");
                    OP126();
                    break;
                case 83:
                    loop++;
                    system("cls");
                    OP083();
                    break;
                case 0:
                    inventory();
                    enter();
                    OP105();
                    break;
            }
        }
    }
}

//OPCAO 106

void OP106(){
    printf("\t106 - Ao apertar o bra�o da cadeira, voc� aciona a mola de um painel secreto, que salta no ar. Voc� encontra um frasco de vidro e l� o r�tulo: \"Po��o da R�plica - uma dose apenas. Este l�quido far� com que seu corpo tome a forma de qualquer ser que esteja pr�ximo.\" Voc� coloca a estranha po��o na mochila e continua para o norte.\n\n");

    if(status_OP106 == 0){
        morph_potion += 1;
        status_OP106 += 1;
        printf("\033[1;34mPo��o de R�plica foi adicionada a seu invent�rio\033[0;37m");
        enter();
        OP188();
    }else{
        printf("\033[1;31mVoc� j� esteve aqui, nada foi adicionado ao seu invent�rio.\033[0;37m\n\n");
        enter();
        OP188();
    }
}

//OPCAO 107

void OP107(){
    stageops = 107;
    save();
    loop = 0;

    printf("\t107 - Voc� chega a uma porta em arco localizada na parede � direita do t�nel. A pesada porta de pedra est� fechada, mas h� um trinco de ferro e uma ma�aneta redonda.\n\nSe voc� quiser tentar a porta, \033[1;35mdigite 168.\033[0;37m\nSe, em vez disso, quiser continuar pelo t�nel, \033[1;35mdigite 267.\033[0;37m\n\n");

    printf("\033[1;34mLEMBRE-SE, VOC� PODE ACESSAR SEU INVENT�RIO DIGITANDO 0\033[0;37m\n\n");

    while(loop < 1){
        scanf("%i", &choices);
        switch(choices){
            case 168:
                loop++;
                system("cls");
                OP168();
                break;
            case 267:
                loop++;
                system("cls");
                OP267();
                break;
            case 0:
                inventory();
                enter();
                OP107();
                break;
        }
    }
}

//OPCAO 108

void OP108(){
    stageops = 108;
    save();
    loop = 0;

    printf("\t108 - H� um grande painel de vidro na parede � esquerda do t�nel. Atrav�s dele, voc� pode ver um aposento intensamente iluminado por tochas com INSETOS GIGANTES de todas as formas poss�veis. Abelhas, vespas, besouros, carrapatos, at� os bichos do queijo t�m mais de seis cent�metros de comprimento. O ru�do � amea�ador. No meio do aposento, uma coroa cravejada de j�ias est� colocada sobre uma pequena mesa. No meio da coroa, h� uma j�ia, parece um grande diamante. Voc�:\n\nQuebrar� o vidro e tentar� apanhar a coroa? \033[1;35mDigite 394.\033[0;37m\nContinuar� para o oeste? \033[1;35mDigite 59.\033[0;37m\nRetornar� � encruzilhada para seguir para o norte? \033[1;35mDigite 14.\033[0;37m\n\n");

    printf("\033[1;34mLEMBRE-SE, VOC� PODE ACESSAR SEU INVENT�RIO DIGITANDO 0\033[0;37m\n\n");

    while(loop < 1){
        scanf("%i", &choices);
        switch(choices){
            case 200:
                loop++;
                system("cls");
                OP200();
                break;
            case 316:
                loop++;
                system("cls");
                OP316();
                break;
            case 0:
                inventory();
                enter();
                OP108();
                break;
        }
    }
}

//OPCAO 109

void OP109(){
    stageops = 109;
    save();
    loop = 0;

    printf("\t109 - Voc� chega a uma outra encruzilhada no t�nel.\n\nSe quiser continuar seguindo para o oeste, \033[1;35mdigite 43.\033[0;37m\nSe quiser seguir para o norte, \033[1;35mdigite 24.\033[0;37m\n\n");

    printf("\033[1;34mLEMBRE-SE, VOC� PODE ACESSAR SEU INVENT�RIO DIGITANDO 0\033[0;37m\n\n");

    while(loop < 1){
        scanf("%i", &choices);
        switch(choices){
            case 43:
                loop++;
                system("cls");
                OP043();
                break;
            case 24:
                loop++;
                system("cls");
                OP024();
                break;
            case 0:
                inventory();
                enter();
                OP109();
                break;
        }
    }
}

//OPCAO 110

void OP110(){
    stageops = 110;
    save();
    loop = 0;

    printf("\t110 - O t�nel logo faz uma outra curva fechada para a direita. Seguindo para o leste, voc� chega a uma estranha obstru��o: uma linha de 12 postes de madeira atravessados no t�nel. Eles est�o fixos �s paredes a cerca de meio metro do ch�o, com um espa�o de um metro entre eles.\n\nSe voc� quiser caminhar entre os postes, \033[1;35mdigite 58.\033[0;37m\nSe preferir subir pelos postes e passar por sobre a obstru��o, \033[1;35mdigite 223.\033[0;37m\n\n");

    printf("\033[1;34mLEMBRE-SE, VOC� PODE ACESSAR SEU INVENT�RIO DIGITANDO 0\033[0;37m\n\n");

    while(loop < 1){
        scanf("%i", &choices);
        switch(choices){
            case 58:
                loop++;
                system("cls");
                OP058();
                break;
            case 223:
                loop++;
                system("cls");
                OP223();
                break;
            case 0:
                inventory();
                enter();
                OP110();
                break;
        }
    }
}

//OPCAO 111

void OP111(){
    loop = 0;

    printf("\t111 - Voc� limpa o viscoso lodo amarelo da l�mina de sua espada e caminha rapidamente para a porta, de volta para o t�nel, e segue para o norte.");
    //va para 267

    enter();
    OP267();
}

//OPCAO 112

void OP112(){
    loop = 0;
    printf("\t112 - A n�o ser pelas Provis�es, que ficaram encharcadas e \033[1;31mn�o servem mais para serem comidas\033[0;37m, todas as suas outras posses permanecem intactas. Voc� as recoloca cuidadosamente na mochila e parte para o norte de novo.\n\n");
    //Va para 356

    provisions = 0;
    printf("Voc� perdeu todas as sua PROVIS�ES\n");
    printf("Suas PROVIS�ES: %d", provisions);
    enter();
    OP356();
}

//OPCAO 113

void OP113(){
    stageops = 113;
    save();
    loop = 0;

    printf("\t113 - A bola de madeira passa assobiando pelo cr�nio, atingindo a parede do outro lado com um estrondo.\n\nSe voc� quiser tentar outra vez com a outra bola, \033[1;35mdigite 371.\033[0;37m\nSe j� tiver jogado duas vezes, ou n�o quiser tentar de novo, voc� pode fechar a porta e continuar pelo t�nel, \033[1;35mdigite 74.\033[0;37m\n\n");

    printf("\033[1;34mLEMBRE-SE, VOC� PODE ACESSAR SEU INVENT�RIO DIGITANDO 0\033[0;37m\n\n");

    while(loop < 1){
        scanf("%i", &choices);
        switch(choices){
            case 371:
                loop++;
                system("cls");
                OP371();
                break;
            case 74:
                loop++;
                system("cls");
                OP074();
                break;
            case 0:
                inventory();
                enter();
                OP113();
                break;
        }
    }
}

//OPCAO 114

void OP114(){
    stageops = 114;
    save();
    loop = 0;

    printf("\t114 - O Homem da Caverna est� usando uma munhequeira de couro com quatro pequenos cr�nios de rato pendurados.\n\nSe voc� quiser coloc�-la no seu pr�prio pulso, \033[1;35mdigite 336.\033[0;37m\nSe preferir prosseguir para o norte, \033[1;35mdigite 298.\033[0;37m\n\n");

    printf("\033[1;34mLEMBRE-SE, VOC� PODE ACESSAR SEU INVENT�RIO DIGITANDO 0\033[0;37m\n\n");

    while(loop < 1){
        scanf("%i", &choices);
        switch(choices){
            case 336:
                loop++;
                system("cls");
                OP336();
                break;
            case 298:
                loop++;
                system("cls");
                OP298();
                break;
            case 0:
                inventory();
                enter();
                OP114();
                break;
        }
    }
}

//OPCAO 115

void OP115(){
    loop = 0;

    printf("\t 115 - Seu corpo continua a vibrar intensamente, e voc� se sente como se estivesse prestes a desmaiar. Mas sua for�a � grande, e voc� consegue resistir ao tremendo choque sofrido. Finalmente, voc� se acalma e come�a a sentir a a��o dos poderes ben�ficos do anel. Some 3 pontos de ENERGIA. Throm o olha ansioso, e voc� o tranquiliza, dizendo que est� plenamente recuperado. Ele caminha para o leste, voc� o segue prontamente.");
    //Va para 221

    if(status_OP115 == 0){
        energy_ring += 1;
        status_OP115 += 1;
        printf("O anel foi adicionado ao seu invent�rio e voc� ganha 3 de ENERGIA.");
        enter();
        OP221();
    }else{
        printf("\033[1;31mVoc� j� esteve aqui, nada foi adicionado ao seu invent�rio.\033[0;37m\n\n");
        enter();
        OP221();
    }
}

//OPCAO 116

void OP116(){
    loop = 0;

    printf("\t116 - Voc� n�o consegue acreditar que a Besta Sangrenta n�o tenha sido afetada pela nova ferida. Voc� hesita uma fra��o de segundo demais, e a fera d� um bote, partindo-lhe o cr�nio com as mand�bulas. \033[1;31mEm seguida, arrasta-o para a po�a, onde seu corpo, depois de decomposto, ser� devorado pela pavorosa criatura.\033[0;37m");
    death();
}

//OPCAO 117

void OP117(){
    stageops = 117;
    save();
    loop = 0;

    printf("\t117 - Depois de longa caminhada t�nel abaixo, voc� chega a um beco sem sa�da. Um grande espelho, que vai do ch�o at� o teto, est� colocado na parede do fundo e, na penumbra, voc� s� consegue visualizar vagamente o seu pr�prio reflexo.\n\nSe quiser olhar o espelho mais de perto, \033[1;35mdigite 329.\033[0;37m\nSe preferir fazer a longa caminhada de volta para a �ltima encruzilhada no t�nel, a fim de prosseguir para o leste, \033[1;35mdigite 135.\033[0;37m\n\n");

    printf("\033[1;34mLEMBRE-SE, VOC� PODE ACESSAR SEU INVENT�RIO DIGITANDO 0\033[0;37m\n\n");

    while(loop < 1){
        scanf("%i", &choices);
        switch(choices){
            case 329:
                loop++;
                system("cls");
                OP329();
                break;
            case 135:
                loop++;
                system("cls");
                OP135();
                break;
            case 0:
                inventory();
                enter();
                OP117();
                break;
        }
    }
}

//OPCAO 118

void OP118(){
    loop = 0;
    printf("\t118 - apesar das estalactites que caem por toda parte, voc� consegue passar ileso pelo arco. Voc� olha ao redor e v� Throm disparando na sua dire��o, um bra�o por cima da cabe�a paia proteg�-la. Ele corre para o t�nel e se encosta na parede fria, a respira��o ofegante. Desculpase por ter iniciado o desabamento das rochas e lhe oferece a m�o. Voc� diz a Throm que talvez fosse melhor ele usar a linguagem dos sinais no futuro, mesmo para rir! Os dois sorriem e partem para o leste mais uma vez.");


    enter();
    OP060();
}

//OPCAO 119

void OP119(){
    stageops = 119;
    save();
    loop = 0;

    printf("\t119 - Adiante, voc� pode ver um grande obst�culo no ch�o do t�nel, embora esteja escuro demais para saber exatamente o que �. As pegadas molhadas que voc� vem seguindo continuam at� a obstru��o.\n\nSe voc� quiser continuar para o leste, \033[1;35mdigite 56.\033[0;37m\nSe preferir voltar para a encruzilhada e seguir para o oeste, \033[1;35mdigite 293.\033[0;37m\n\n");

    printf("\033[1;34mLEMBRE-SE, VOC� PODE ACESSAR SEU INVENT�RIO DIGITANDO 0\033[0;37m\n\n");

    while(loop < 1){
        scanf("%i", &choices);
        switch(choices){
            case 56:
                loop++;
                system("cls");
                OP056();
                break;
            case 293:
                loop++;
                system("cls");
                OP293();
                break;
            case 0:
                inventory();
                enter();
                OP119();
                break;
        }
    }
}

//OPCAO 120

void OP120(){
    stageops = 120;
    save();
    loop = 0;

    printf("\t120 - Jogados num buraco de mais ou menos um metro de profundidade, voc� v� um gancho de ferro e uma bolsa de couro.\n\nSe quiser esticar a m�o para apanh�-los, \033[1;35mdigite 228.\033[0;37m\nSe preferir ignorar os objetos e continuar para o norte, \033[1;35mdigite 29\033[0;37m\n\n.");

    printf("\033[1;34mLEMBRE-SE, VOC� PODE ACESSAR SEU INVENT�RIO DIGITANDO 0\033[0;37m\n\n");

    while(loop < 0){
        scanf("%i", &choices);
        switch(choices){
            case 228:
                loop++;
                system("cls");
                OP228();
                break;
            case 292:
                loop++;
                system("cls");
                OP292();
                break;
            case 0:
                inventory();
                enter();
                OP120();
                break;
        }
    }
}

//OPCAO 121

void OP121(){
    stageops = 121;
    save();
    loop = 0;

    printf("\t121 - O An�o olha para os dados. \"Voc� n�o � muito bom nesse jogo, �?\", graceja. \"Lamento, mas voc� ter� que sofrer uma penalidade antes de continuar.\" Ele retira duas p�lulas do bolso. Uma est� marcada com a letra S e a outra com a letra L. Pede que voc� escolha uma e engula.\n\nSe voc� escolher a p�lula marcada com a letra S, \033[1;35mdigite 26.\033[0;37m\nSe quiser engolir a outra, \033[1;35mdigite 354.\033[0;37m\n\n");

    printf("\033[1;34mLEMBRE-SE, VOC� PODE ACESSAR SEU INVENT�RIO DIGITANDO 0\033[0;37m\n\n");

    while(loop < 0){
        scanf("%i", &choices);
        switch(choices){
            case 26:
                loop++;
                system("cls");
                OP026();
                break;
            case 354:
                loop++;
                system("cls");
                OP354();
                break;
            case 0:
                inventory();
                enter();
                OP121();
                break;
        }
    }
}

//OPCAO 122

void OP122(){
    stageops = 122;
    save();
    loop = 0;
    printf("\t122 - � sua frente, h� dois lances de escadas de pedra, separados por um corrim�o de cr�nios de ratazana.\n\nVoc� pode subir pelo lance de escadas da esquerda, \033[1;35mdigite 176.\033[0;37m\nOu pelo da direita, \033[1;35mdigite 384.\033[0;37m\n\n");

    printf("\033[1;34mLEMBRE-SE, VOC� PODE ACESSAR SEU INVENT�RIO DIGITANDO 0\033[0;37m\n\n");

    while(loop < 1){
        scanf("%i", &choices);
        switch(choices){
            case 176:
                loop++;
                system("cls");
                OP176();
                break;
            case 384:
                loop++;
                system("cls");
                OP384();
                break;
            case 0:
                inventory();
                enter();
                OP122();
                break;
        }
    }
}

//OPCAO 123

void OP123(){
    loop = 0;

    printf("\t123 - O colar � um amuleto de for�a. \033[1;32mSome 1 ponto de HABILIDADE e 1 ponto de ENERGIA e continue na sua miss�o.\033[0;37m");

    if(status_OP123 == 0){
        hability += 1;
        energy += 1;
        status_OP123 += 1;
        printf("\n\nSua ENERGIA: %i", energy);
        printf("\nSua HABILIDADE: %i", hability);
        enter();
        OP282();
    }else{
        printf("\033[1;31mVoc� j� esteve aqui, nada foi adicionado ao seu invent�rio.\033[0;37m\n\n");
        enter();
        OP282();
    }
}

//OPCAO 124

void OP124(){
    loop = 0;
    monshability = 5;
    monshability2 = 5;
    monsenergy = 4;
    monsenergy2 = 5;

    printf("\t124 - Voc� abre o al�ap�o e sobe os degraus correndo, chegando a um aposento profundamente iluminado por lanternas. Dois GOBLINS afiam espadas curtas em uma pedra colocada no meio do ch�o. Voc� os pega desprevenidos, mas eles logo se recuperam e se projetam para frente a fim de atac�-lo.\n\nPrimeiro GOBLIN HABILIDADE 5 ENERGIA 4\nSegundo GOBLIN HABILIDADE 5 ENERGIA 5\n\nOs Goblins o atacar�o separadamente em cada S�rie de Ataque, mas voc� deve escolher com qual dos dois vai lutar. Ataque o Goblin escolhido como numa batalha normal. Contra o outro, voc� tem que jogar os dados para determinar sua For�a de Ataque da maneira usual, mas, mesmo que sua For�a de Ataque seja maior, voc� n�o ferir� o Goblin. Compute isso simplesmente como se tivesse se defendido de um golpe dele. Por�m, se a For�a de Ataque dele for maior, ele o ferir�, da forma costumeira");

    enter();
    combat2();
    printf("\nVoc� foi vitorioso no duelo duplo!\n");
    printf("\nSua ENERGIA: %i", energy);
    enter();
    OP081();



}

//OPCAP 125

void OP125(){
    loop = 0;
    printf("\t125 - Voc� caminha para a porta na ponta dos p�s, enquanto Erva segue tagarelando. \033[1;33mDigite \"ROLL\" e teste sua SORTE.\033[0;37m\n\n");

    while(loop < 1){
        gets(startroll);
        if(strcasecmp(startroll, "roll") == 0){
            dice2();
            if(numroll <= luck){
                luck--;
                system("cls");
                OP069();
            }else{
                luck--;
                system("cls");
                OP139();
            }
        }
    }
}

//OPCAO 126

void OP126(){
    stageops = 126;
    save();
    loop = 0;

    printf("\t126 - A bolsa no cinto do B�rbaro cont�m apenas uma por��o de carne seca de apar�ncia estranha, embrulhada num pano. Voc�:\n\nComer� a carne seca? \033[1;35mDigite 226.\033[0;37m\nDeixar� a carne e caminhar� para a alcova? \033[1;35mDigite 41.\033[0;37m\nDeixar� a c�mara e seguir� para o oeste? \033[1;35mDigite 83.\033[0;37m\n\n");

    printf("\033[1;34mLEMBRE-SE, VOC� PODE ACESSAR SEU INVENT�RIO DIGITANDO 0\033[0;37m\n\n");

    while(loop < 1){
        scanf("%i", &choices);
        switch(choices){
            case 226:
                loop++;
                system("cls");
                OP226();
                break;
            case 41:
                loop++;
                system("cls");
                OP041();
                break;
            case 83:
                loop++;
                system("cls");
                OP083();
            case 0:
                inventory();
                enter();
                OP126();
                break;
        }
    }
}

//OPCAO 127

void OP127(){
    loop = 0;

    printf("\t127 - A �nica maneira poss�vel de sair do sal�o, tanto quanto voc� pode ver, � usando um escorrega na parede norte. Voc� resolve arriscar e sobe no escorrega. Desce deslizando suavemente e aterrissa de costas em outro aposento.\n\n");

    if(status_OP127 == 0){
    status_OP127 += 1;
    diamond += 1;
    printf("\033[1;34mO Diamante foi adicionado ao seu invent�rio.\033[0;37m");
    enter();
    OP090();
    } else{
    printf("\033[1;31mVoc� j� pegou o diamante\033[0;37m");
    enter();
    OP090();
    }
}

//OPCAO 128

void OP128(){
    stageops = 128;
    save();
    loop = 0;

    printf("\t128 - Na parte de tr�s da alcova, h� uns degraus que conduzem a uma adega abaixo. Teias de aranha tocam-lhe o rosto enquanto voc� desce. O teto da adega � bastante baixo, e o ch�o est� coberto de lixo e detritos. No meio da parede do outro lado, uma passagem em arco leva a outro t�nel iluminado por cristais. Grandes cogumelos crescem no lixo � sua direita.\n\nSe voc� quiser atravessar a passagem em arco, \033[1;35mdigite 35.\033[0;37m\nSe preferir parar para comer alguns cogumelos, \033[1;35mdigite 233.\033[0;37m\n\n");

    printf("\033[1;34mLEMBRE-SE, VOC� PODE ACESSAR SEU INVENT�RIO DIGITANDO 0\033[0;37m\n\n");

    while(loop < 1){
        scanf("%i", &choices);
        switch(choices){
            case 35:
                loop++;
                system("cls");
                OP035();
                break;
            case 233:
                loop++;
                system("cls");
                OP233();
                break;
            case 0:
                inventory();
                enter();
                OP128();
                break;
        }
    }
}

//OPCAO 129

void OP129(){
    stageops = 129;
    save();
    loop = 0;

    printf("\t129 - Voc� amarra a corda ao gancho e o atira por cima da muralha. O gancho se prende na pedra, e voc� come�a a se i�ar. De cima da muralha, v� um monstro gigantesco, semelhante a um dinossauro, circulando em um po�o coberto de areia. O grosso couro da criatura � verde malhado, e de p� nas fortes pernas traseiras, deve atingir uns 10 metros de altura. As enormes mand�bulas deixam ver filas de dentes afiados como navalhas ao se abrirem e fecharem com for�a suficiente para triturar-lhe os ossos. Uma grande porta dupla na parede do outro lado do po�o parece ser a �nica maneira de sair desta parte do calabou�o. Voc�:\n\nDescer� pela corda para dentro do po�o, a fim de enfrentar o DIABO DO PO�O? \033[1;35mDigite 349.\033[0;37m\nJogar� seu amuleto de osso de macaco no po�o? \033[1;35mDigite 361.\033[0;37m\nTentar�, de cima da muralha, fisgar O DIABO DO PO�O com o gancho de ferro? \033[1;35mDigite 167.\033[0;37m\n\n");

    printf("\033[1;34mLEMBRE-SE, VOC� PODE ACESSAR SEU INVENT�RIO DIGITANDO 0\033[0;37m\n\n");

    while(loop < 1){
        scanf("%i", &choices);
        switch(choices){
            case 349:
                loop++;
                system("cls");
                OP349();
                break;
            case 361:
                loop++;
                if(monkey_amulet != 0){
                    monkey_amulet -= 1;
                    system("cls");
                    OP361();
                } else{
                    printf("Voc� n�o possui este item.");
                    enter();
                    OP129();
                }
                break;
            case 167:
                loop++;
                if(iron_hook != 0){
                    system("cls");
                    OP167();
                }
                else{
                    printf("Voc� n�o possui este item.");
                    enter();
                    OP129();
                }
                break;
            case 0:
                inventory();
                enter();
                OP129();
                break;
        }
    }
}

//OPCAO 130

void OP130(){
    loop = 0;
    monsenergy = 5;
    monshability = 7;

    printf("\t130 - Os Hobgoblins param de lutar imediatamente. Eles n�o entendem o que voc� est� dizendo e rosnam agressivamente. Em seguida, desembainham as espadas curtas e avan�am para atac�-lo. Lute com um de cada vez.\n\n\033[1;31mPrimeiro HOBGOBLIN HABILIDADE 7 ENERGIA 5\nSegundo HOBGOBLIN HABILIDADE 6 ENERGIA 5\033[0;37m\n\n");
    enter();
    combat1();
    printf("\nVOC� GANHOU DO PRIMEIRO GOBLIN! SE PREPARE PARA O PR��XIMO DUELO");
    enter();
    monsenergy = 5;
    monshability = 6;
    combat1();
    printf("\n\nVOC� GANHOU O DUELO DUPLO!\n");
    printf("Sua ENERGIA: %i", energy);
    enter();
    OP009();
}

//OPCAO 131

void OP131(){
    loop = 0;

    printf("\t131 - Os dardos da besta voam por cima de sua cabe�a e se cravam na parede; felizmente, voc� ainda est� agachado. Agora que a armadilha j� disparou, voc� pode sair do aposento pela mesma porta pela qual entrou. De volta no t�nel, voc� segue para o oeste.");

    enter();
    OP074();
}

//OPCAO 132

void OP132(){
    stageops = 132;
    save();
    loop = 0;

    printf("\t132 - Voc� s� tem tempo de ouvir o Gnomo dizer: \"Uma coroa e dois cr�nios\", antes de ser atingido no peito por um raio branco de energia disparado da fechadura. Voc� cai sem sentidos. \033[1;33mDigite \"ROLL\" e role um dado\033[0;37m, \033[1;31mo resultado mais 1 � reduzido de sua ENERGIA.\033[0;37m\n\n");
    while(loop < 1){
        gets(startroll);
        if(strcasecmp(startroll, "roll") == 0){
            dice1();
            if(numroll > 0){
                energy = (energy - (numroll + 1));
                printf("Sua ENERGIA: %i", energy);
            }
            if(energy > 0){
                printf("\n\nVoc� recupera a consci�ncia e o Gnomo manda que tente de novo. Voc� sabe que colocou uma gema na ranhura certa, mas qual? Voc� suspira e tenta uma nova combina��o.\n\n    A         B         C     \nEsmeralda|Diamante |Safira    -> \033[1;35mDigite 16.\033[0;37m\nDiamante |Safira   |Esmeralda -> \033[1;35mDigite 392.\033[0;37m\nSafira   |Esmeralda|Diamante  -> \033[1;35mDigite 177.\033[0;37m\nEsmeralda|Safira   |Diamante  -> \033[1;35mDigite 287.\033[0;37m\nDiamante |Esmeralda|Safira    -> \033[1;35mDigite 132.\033[0;37m\nSafira   |Diamante |Esmeralda -> \033[1;35mDigite 249.\033[0;37m\n\n");

                printf("\033[1;34mLEMBRE-SE, VOC� PODE ACESSAR SEU INVENT�RIO DIGITANDO 0\033[0;37m\n\n");

                scanf("%i", &choices);
                switch(choices){
                    case 16:
                        loop++;
                        system("cls");
                        OP016();
                        break;
                    case 392:
                        loop++;
                        system("cls");
                        OP392();
                        break;
                    case 177:
                        loop++;
                        system("cls");
                        OP177();
                        break;
                    case 287:
                        loop++;
                        system("cls");
                        OP287();
                        break;
                    case 132:
                        loop++;
                        system("cls");
                        OP132();
                        break;
                    case 249:
                        loop++;
                        system("cls");
                        OP249();
                        break;
                    case 0:
                        inventory();
                        enter();
                        OP132();
                        break;
                }
            }else{
                death();
            }
        }
    }
}

//OPCAO 133

void OP133(){
    loop = 0;

    printf("\t133 - Mais uma vez, a voz misteriosa ecoa, s� que agora num tom cheio de desprezo e esc�rnio. \"Ent�o, temos uma erva daninha em nosso meio, n�o\", zomba a voz. \"Meu senhor tem um presente especial para voc�, verme abjeto.\". Subitamente, come�a a entrar �gua no aposento por um buraco no teto. Logo sobe at� a altura dos seus tornozelos, e n�o parece haver qualquer meio de escapar. Voc� caminha na �gua at� a porta. Est� firmemente trancada, mas, no desespero, voc� tenta arromb�-la, batendo com o ombro. \033[1;33mDigite \"ROLL\" e teste sua HABILIDADE.\033[0;37m\n\n");

    while(loop < 1){
        gets(startroll);
        if(strcasecmp(startroll, "roll") == 0){
            dice2();
            if(numroll <= hability){
                system("cls");
                OP178();
            }else{
                system("cls");
                OP017();
            }
        }
    }
}
//OPCAO 134

void OP134(){
    stageops = 134;
    save();
    loop = 0;

    printf("\t134 - O t�nel leva a um amplo aposento cujo teto � sustentado por diversos pilares de m�rmore. Ao entrar no aposento, voc� depara com uma estranha fera � sua direita. Tem corpo de le�o, asas de drag�o, rabo de escorpi�o e cabe�a de velho barbudo.\n\nSe voc� tiver lido o poema escrito no Pergaminho do Guerreiro Esqueleto, \033[1;35mdigitar 222.\033[0;37m\nSe n�o tiver lido esse poema, \033[1;35mdigite 247.\033[0;37m\n\n");

    printf("\033[1;34mLEMBRE-SE, VOC� PODE ACESSAR SEU INVENT�RIO DIGITANDO 0\033[0;37m\n\n");

    while(loop < 1){
        scanf("%i", &choices);
        switch(choices){
            case 247:
                loop++;
                system("cls");
                OP247();
                break;
            case 222:
                loop++;
                if(read_skeleton_scroll != 0){
                    system("cls");
                    OP222();
                } else{
                    printf("Voc� n�o leu este item.");
                    enter();
                    OP134();
                }
                break;
            case 0:
                inventory();
                enter();
                OP134();
                break;
        }
    }
}

//OPCAO 135

void OP135(){
    loop = 0;

    printf("\t135 - Passando pelo buraco perfurado do Verme da Rocha, � sua esquerda, voc� logo chega � encruzilhada. D� uma olhada r�pida no t�nel que conduz ao sul, mas n�o v� ningu�m se aproximando. Apressando o passo, voc� segue velozmente para o leste.");
    enter();
    OP068();
}

//OPCAO 136

void OP136(){
    stageops = 136;
    save();
    loop = 0;

    printf("\t136 - A porta abre para um outro t�nel, que se inclina numa subida ao longe. Depois de percorrer essa subida por algum tempo, voc� chega a uma parte plana, onde numa porta na parede da direita encontra-se pregada uma m�o j� decomposta.\n\nSe voc� quiser abrir a porta, \033[1;35mdigite 210.\033[0;37m\nSe preferir continuar para o norte, \033[1;35mdigite 78.\033[0;37m\n\n");

    printf("\033[1;34mLEMBRE-SE, VOC� PODE ACESSAR SEU INVENT�RIO DIGITANDO 0\033[0;37m\n\n");

    while(loop < 1){
        scanf("%i", &choices);
        switch(choices){
            case 210:
                loop++;
                system("cls");
                OP210();
                break;
            case 78:
                loop++;
                system("cls");
                OP078();
                break;
            case 0:
                inventory();
                enter();
                OP136();
                break;
        }
    }
}

//OPCAO 137

void OP137(){
    stageops = 137;
    save();
    loop = 0;

    printf("\t137 - Caminhando pelo t�nel, voc� se surpreende com um grande sino de ferro pendurado no teto.\n\nSe quiser tocar o sino, \033[1;35mdigite 220.\033[0;37m\nSe preferir contorn�-lo e prosseguir para o oeste, \033[1;35mdigite 362.\033[0;37m\n\n");

    printf("\033[1;34mLEMBRE-SE, VOC� PODE ACESSAR SEU INVENT�RIO DIGITANDO 0\033[0;37m\n\n");

    while(loop < 1){
        scanf("%i", &choices);
        switch(choices){
            case 220:
                loop++;
                system("cls");
                OP220();
                break;
            case 362:
                loop++;
                system("cls");
                OP362();
                break;
            case 0:
                inventory();
                enter();
                OP137();
                break;
        }
    }
}

//OPCAO 138

void OP138(){
    stageops = 138;
    save();
    loop = 0;

    printf("\t138 - As p�ginas do livro est�o unidas com lacre, mas um pequeno orif�cio foi cortado no meio delas, de tamanho suficiente para conter uma pequena garrafa arrolhada, na qual h� um l�quido de cor clara. Voc� mostra isso a Throm, que levanta a m�o, indicando n�o querer que voc� sequer chegue perto dele com aquilo; a desconfian�a que ele sente em rela��o �s coisas desconhecidas fica evidente. Voc�:\n\nBeber� o l�quido? \033[1;35mDigite 397.\033[0;37m\nEsfregar� o l�quido nos seus ferimentos? \033[1;35mDigite 75.\033[0;37m\nAbrir� o livro vermelho? \033[1;35mDigite 52.\033[0;37m\nDeixar� a garrafa e o livro de lado para continuar para o norte com Throm? \033[1;35mDigite 369.\033[0;37m\n\n");

    printf("\033[1;34mLEMBRE-SE, VOC� PODE ACESSAR SEU INVENT�RIO DIGITANDO 0\033[0;37m\n\n");

    while(loop < 1){
        scanf("%i", &choices);
        switch(choices){
            case 397:
                loop++;
                system("cls");
                OP397();
                break;
            case 75:
                loop++;
                system("cls");
                OP075();
                break;
            case 52:
                loop++;
                system("cls");
                OP052();
                break;
            case 369:
                loop++;
                system("cls");
                OP369();
                break;
            case 0:
                inventory();
                enter();
                OP138();
                break;
        }
    }
}

//OPCAO 139

void OP139(){
    loop = 0;
    monsenergy = 9;
    monshability = 9;

    printf("\t139 - Ao tentar escapar, voc� � atacado ferozmente por Erva, que, com raiva, vira-se rapidamente, pega um banco quebrado e o atinge com ele. \033[1;31mVoc� perde 2 pontos de ENERGIA.\033[0;37m");

    energy -= 2;
    printf("\n\nVoc� perdeu 2 de ENERGIA");
    printf("\nSua ENERGIA: %i\n\n", energy);
    if(energy <= 0)
        death();
    else{
        printf("Voc� consegue desembainhar a espada e lutar.\n\nERVA HABILIDADE 9 ENERGIA 9\n\n");
        combat1();
        printf("\n\nSua ENERGIA: %i", energy);
        printf("\033[1;31m");
        printf("\n\nVoc� conseguiu sobreviver ao monstro!");
        printf("\033[0;37m");
        enter();
        OP201();
    }
}

//OPCAO 140

void OP140(){
    loop = 0;

    printf("\t140 - Voc� tenta for�ar o olho de esmeralda com a ponta da espada, procurando enfi�-la por baixo dele. Para sua grande surpresa, ele se despeda�a com o contato, soltando um jato de g�s venenoso direto no seu rosto. Voc� desmaia e cai para tr�s, chocando-se contra o �dolo v�rias vezes at� parar no ch�o de pedra. \033[1;31mSua aventura termina aqui.\033[0;37m");
    death();
}

//OPCAO 141

void OP141(){
    loop = 0;

    printf("\t141 - O Dem�nio do Espelho est� quase em cima de voc� quando, reunindo todas as suas for�as, voc� desfere um golpe decisivo contra o espelho com a espada. \033[1;33mDigite \"ROLL\" e teste sua HABILIDADE.\033[0;37m\n\n");

    while(loop < 1){
        gets(startroll);
        if(strcasecmp(startroll, "roll") == 0){
            dice2();
            if(numroll <= hability){
                system("cls");
                OP072();
            }else{
                system("cls");
                OP096();
            }
        }
    }
}

//OPCAO 142

void OP142(){
    loop = 0;

    printf("\t142 - H� uma nova ramifica��o no t�nel � sua esquerda, e, � frente, voc� v� dois corpos estendidos no ch�o. Voc� p�ra e d� uma espiada no novo t�nel, mas, n�o vendo nem portas nem criaturas, resolve seguir por ele. Com a espada na m�o, voc� caminha na dire��o dos corpos estendidos.");

    enter();
    OP338();
}

//OPCAO 143

void OP143(){
    loop = 0;

    printf("\t143 - Voc� chama o An�o, dizendo-lhe para mandar vir o ESCORPI�O, pois voc� est� pronto para lutar. Lentamente, a porta de madeira � erguida, e um enorme e grotesco escorpi�o negro se esgueira por baixo dela e entra no aposento. Voc� desembainha a espada em guarda e se prepara para enfrentar a sinistra criatura com pin�as gigantescas e ferr�o mortal.\n\nO Escorpi�o o ataca com ambas as pin�as, e voc� ter� que considerar cada uma das pin�as como uma entidade separada, como se lutasse contra duas criaturas. Ambas as pin�as possuem HABILIDADE 10, por�m cada pin�a tem ENERGIA 5 e o atacar�o separadamente em cada S�rie de Ataque, mas voc� ter� que escolher qual delas enfrentar�. Ataque uma pin�a como numa batalha normal. Contra a outra pin�a, voc� joga os dados para determinar sua For�a de Ataque da forma costumeira, mas voc� n�o causar� ferimentos ao Escorpi�o, mesmo que sua For�a de Ataque seja maior; conte isso como se voc� tivesse apenas conseguido se defender de um golpe. � claro que, se a For�a de Ataque da pin�a for maior que a sua, voc� ser� ferido da maneira usual. Se, durante qualquer das S�ries de Ataque, a For�a de Ataque do Escorpi�o totalizar 22, o combate terminar� e ter� um evento diferente do evento caso voc� ganhe.\n\n\033[1;31mESCORPI�O GIGANTE HABILIDADE 10 ENERGIA 10\033[0;37m");
    monshability = 10;
    monshability2 = 10;
    monsenergy = 5;
    monsenergy2 = 5;
    enter();

    printf("COME�OU O COMBATE!");
    combatloop = 0;
    fight1 = 0;
    fight2 = 0;
    while(combatloop < 1){
        loop = 0;
        combatloop2 = 0;
        printf("\nRode os dados:\n");
        printf("\033[1;31m");
        printf("DIGITE ROLL\n");
        printf("\033[0;37m");
        while(combatloop2 < 1){
        
        gets(combatroll);
            if(strcasecmp(combatroll, "roll") == 0){
                printf("DIGITE O INIMIGO QUE VOCE QUER ATACAR\n");
                if(monsenergy > 0)
                    printf("MONSTRO 1: \"digite 1\"\n");
                if(monsenergy2 > 0)
                    printf("MONSTRO 2: \"digite 2\"\n");
                else
                    printf("\n");
            }
            scanf("%d", &monschoice);
            if(monschoice == 1 && monsenergy > 0){
                defenseloop = 0;
                fight1 = 0;
                loop = 0;
                while(fight1 < 1){
                    if(strcasecmp(combatroll, "roll") == 0){
                        dice2();
                        playerhabil = numroll + hability;
                        printf("\n\nSUA FOR�A DE ATAQUE: %d\n", playerhabil);

                        dice2();
                        damagemonster = numroll + monshability;
                        printf("\nFOR�A DE ATAQUE DO MONSTRO 1: %d\n", damagemonster);
                    }
                    if(strcasecmp(combatroll, "roll") == 0 && playerhabil > damagemonster){
                        printf("\nVOC� CAUSOU DANO\n");
                        monsenergy -= 2;
                        printf("\n\033[1;33mVoc� deseja testar sua SORTE? (digite \"sim\" ou \"nao\")\n");
                        printf("Sua SORTE ATUAL: %d\n\n\033[0;37m", luck);
                        while(loop < 1){
                            gets(luckhit);
                            if(strcasecmp(luckhit, "sim") == 0){
                                dice2();
                                if(numroll <= luck){
                                    luck--;
                                    printf("\n\nSua SORTE: %d", luck);
                                    monsenergy -= 2;
                                    loop++;
                                }
                                else{
                                    luck--;
                                    printf("\n\nSua SORTE: %d", luck);
                                    monsenergy += 1;
                                    loop++;
                                }
                                printf("\n\n");
                            }
                            else if(strcasecmp(luckhit, "nao") == 0){
                                loop++;
                            }
                        }
                        printf("HP MONSTRO: %d", monsenergy);
                        enter();
                        printf("A VEZ DOS MONSTROS: DEFENDA-SE!");
                        while(defenseloop < 1){
                            loop = 0;
                            printf("\nRode os dados:\n");
                            printf("\033[0;31m");
                            printf("DIGITE ROLL\n");
                            printf("\033[0;37m");
                            gets(combatroll);
                            if(strcasecmp(combatroll, "roll") == 0){
                                dice2();
                                damagemonster2 = numroll + monshability;
                                printf("\n\nFOR�A DE ATAQUE DOS MONSTROS: %d\n", damagemonster2);
                                dice2();
                                playerhabil = numroll + hability;
                                printf("\n\nSUA DEFESA: %d\n", playerhabil);
                            }
                            if(strcasecmp(combatroll, "roll") == 0 && playerhabil > damagemonster2){
                                printf("\nVOC� CONSEGUIU SE DEFENDER!");
                                defenseloop += 1;
                                fight1 += 1;
                                combatloop2 += 1;
                                enter();
                            }
                            if(strcasecmp(combatroll, "roll") == 0 && playerhabil < damagemonster2){
                                printf("\nVOCE LEVOU DANO\n");
                                printf("\n\033[1;33mVoc� deseja testar sua SORTE? (digite \"sim\" ou \"nao\")\n");
                                printf("Sua SORTE ATUAL: %d\n\n\033[0;37m", luck);
                                while(loop < 1){
                                    gets(luckhit);
                                    if(strcasecmp(luckhit, "sim") == 0){
                                        dice2();
                                        if(numroll <= luck){
                                            luck--;
                                            printf("\n\nSua SORTE: %d", luck);
                                            energy += 1;
                                            loop++;
                                        }else{
                                            luck--;
                                            printf("\n\nSua SORTE: %d", luck);
                                            energy -= 1;
                                            loop++;
                                        }
                                        printf("\n\n");
                                    }else if(strcasecmp(luckhit, "nao") == 0)
                                        loop++;
                                }
                                energy -= 2;
                                printf("SEU HP: %d", energy);
                                fight1 += 1;
                                defenseloop += 1;
                                combatloop2 += 1;
                                enter();
                            }
                        }
                    }
                    else if(strcasecmp(combatroll, "roll") == 0 && playerhabil < damagemonster){
                        printf("\nVOCE LEVOU DANO\n");
                        printf("\n\033[1;33mVoc� deseja testar sua SORTE? (digite \"sim\" ou \"nao\")\n");
                        printf("Sua SORTE ATUAL: %d\n\n\033[0;37m", luck);
                        while(loop < 1){
                            gets(luckhit);
                            if(strcasecmp(luckhit, "sim") == 0){
                                dice2();
                                if(numroll <= luck){
                                    luck--;
                                    printf("\n\nSua SORTE: %d", luck);
                                    energy += 1;
                                    loop++;
                                }
                                else{
                                    luck--;
                                    printf("\n\nSua SORTE: %d", luck);
                                    energy -= 1;
                                    loop++;
                                }
                                printf("\n\n");
                            }
                            else if(strcasecmp(luckhit, "nao") == 0){
                                loop++;
                            }
                        }
                        energy -= 2;
                        printf("SEU HP: %d", energy);
                        enter();
                        printf("A VEZ DOS MONSTROS: DEFENDA-SE!");
                        while(defenseloop < 1){
                            loop = 0;
                            printf("\nRode os dados:\n");
                            printf("\033[0;31m");
                            printf("DIGITE ROLL\n");
                            printf("\033[0;37m");
                            gets(combatroll);
                            if(strcasecmp(combatroll, "roll") == 0){
                                dice2();
                                damagemonster2 = numroll + monshability;
                                printf("\nFOR�A DE ATAQUE DOS MONSTROS: %d\n", damagemonster2);

                                dice2();
                                playerhabil = numroll + hability;
                                printf("\n\nSUA DEFESA: %d\n", playerhabil);
                            }
                            if(strcasecmp(combatroll, "roll") == 0 && playerhabil > damagemonster2){
                                printf("\nVOC� CONSEGUIU SE DEFENDER!");
                                defenseloop += 1;
                                fight1 += 1;
                                combatloop2 += 1;
                                enter();
                            }
                            if(strcasecmp(combatroll, "roll") == 0 && playerhabil < damagemonster2){
                                printf("\nVOCE LEVOU DANO\n");
                                printf("\n\033[1;33mVoc� deseja testar sua SORTE? (digite \"sim\" ou \"nao\")\n");
                                printf("Sua SORTE ATUAL: %d\n\n\033[0;37m", luck);
                                while(loop < 1){
                                    gets(luckhit);
                                    if(strcasecmp(luckhit, "sim") == 0){
                                        dice2();
                                        if(numroll <= luck){
                                            luck--;
                                            printf("\n\nSua SORTE: %d", luck);
                                            energy += 1;
                                            loop++;
                                        }else{
                                            luck--;
                                            printf("\n\nSua SORTE: %d", luck);
                                            energy -= 1;
                                            loop++;
                                        }
                                        printf("\n\n");
                                    } else if(strcasecmp(luckhit, "nao") == 0)
                                        loop++;
                                }
                                energy -= 2;
                                printf("SEU HP: %d", energy);
                                defenseloop += 1;
                                enter();
                            }
                        }
                    }
                    if(energy <= 0){
                        death();
                    }
                    else if (monsenergy <= 0){
                        fight1 += 2;
                        printf("VOCE GANHOU O COMBATE\n\n");
                        printf("COME�E O COMBATE COM O PROXIMO MONSTRO");
                        monshability = monshability2;
                        monsenergy = monsenergy2;
                        enter();
                        combat1();
                    }
                    if(fight1 == 2 && fight2 == 2){
                        combatloop2 += 1;
                        combatloop += 1;
                        system("cls");
                    }
                }
            }
            if(monschoice == 2 && monsenergy2 > 0){
                defenseloop = 0;
                fight2 = 0;
                loop = 0;
                while(fight2 < 1){
                    if(strcasecmp(combatroll, "roll") == 0){
                        dice2();
                        playerhabil = numroll + hability;
                        printf("\n\nSUA FOR�A DE ATAQUE: %d\n", playerhabil);

                        dice2();
                        damagemonster2 = numroll + monshability2;
                        printf("\nFOR�A DE ATAQUE DO MONSTRO 1: %d\n", damagemonster2);
                    }
                    if(strcasecmp(combatroll, "roll") == 0 && playerhabil > damagemonster2){
                        printf("\nVOC� CAUSOU DANO\n");
                        monsenergy2 -= 2;
                        printf("\n\033[1;33mVoc� deseja testar sua SORTE? (digite \"sim\" ou \"nao\")\n");
                        printf("Sua SORTE ATUAL: %d\n\n\033[0;37m", luck);
                        while(loop < 1){
                            gets(luckhit);
                            if(strcasecmp(luckhit, "sim") == 0){
                                dice2();
                                if(numroll <= luck){
                                    luck--;
                                    printf("\n\nSua SORTE: %d", luck);
                                    monsenergy2 -= 2;
                                    loop++;
                                }
                                else{
                                    luck--;
                                    printf("\n\nSua SORTE: %d", luck);
                                    monsenergy2 += 1;
                                    loop++;
                                }
                                printf("\n\n");
                            }
                            else if(strcasecmp(luckhit, "nao") == 0){
                                loop++;
                            }
                        }
                        printf("HP MONSTRO: %d", monsenergy2);
                        enter();
                        printf("A VEZ DOS MONSTROS: DEFENDA-SE!");
                        while(defenseloop < 1){
                            loop = 0;
                            printf("\nRode os dados:\n");
                            printf("\033[0;31m");
                            printf("DIGITE ROLL\n");
                            printf("\033[0;37m");
                            gets(combatroll);
                            if(strcasecmp(combatroll, "roll") == 0){
                                dice2();
                                damagemonster = numroll + monshability;
                                printf("\nFOR�A DE ATAQUE DOS MONSTROS: %d\n", damagemonster);
                                dice2();
                                playerhabil = numroll + hability;
                                printf("\n\nSUA DEFESA: %d\n", playerhabil);

                            }if(strcasecmp(combatroll, "roll") == 0 && playerhabil > damagemonster){
                                printf("VOC� CONSEGUIU SE DEFENDER!");
                                defenseloop += 1;
                                fight2 += 1;
                                combatloop2 += 1;
                                enter();

                            }if(strcasecmp(combatroll, "roll") == 0 && playerhabil < damagemonster){
                                printf("\nVOCE LEVOU DANO\n");
                                printf("\n\033[1;33mVoc� deseja testar sua SORTE? (digite \"sim\" ou \"nao\")\n");
                                printf("Sua SORTE ATUAL: %d\n\n\033[0;37m", luck);
                                while(loop < 1){
                                    gets(luckhit);
                                    if(strcasecmp(luckhit, "sim") == 0){
                                        dice2();
                                        if(numroll <= luck){
                                            luck--;
                                            printf("\n\nSua SORTE: %d", luck);
                                            energy += 1;
                                            loop++;
                                        }else{
                                            luck--;
                                            printf("\n\nSua SORTE: %d", luck);
                                            energy -= 1;
                                            loop++;
                                        }
                                        printf("\n\n");
                                    } else if(strcasecmp(luckhit, "nao") == 0)
                                        loop++;
                                }

                                energy -= 2;
                                printf("SEU HP: %d", energy);
                                defenseloop += 1;
                                fight2 += 1;
                                combatloop2 += 1;
                                enter();

                            }
                        }
                    }
                    else if(strcasecmp(combatroll, "roll") == 0 && playerhabil < damagemonster2){
                        printf("\nVOCE LEVOU DANO\n");
                        printf("\n\033[1;33mVoc� deseja testar sua SORTE? (digite \"sim\" ou \"nao\")\n");
                        printf("Sua SORTE ATUAL: %d\n\n\033[0;37m", luck);
                        while(loop < 1){
                            gets(luckhit);
                            if(strcasecmp(luckhit, "sim") == 0){
                                dice2();
                                if(numroll <= luck){
                                    luck--;
                                    printf("\n\nSua SORTE: %d", luck);
                                    energy += 1;
                                    loop++;
                                }
                                else{
                                    luck--;
                                    printf("\n\nSua SORTE: %d", luck);
                                    energy -= 1;
                                    loop++;
                                }
                                printf("\n\n");
                            }
                            else if(strcasecmp(luckhit, "nao") == 0){
                                loop++;
                            }
                        }
                        energy -= 2;
                        printf("SEU HP: %d", energy);
                        enter();
                        printf("A VEZ DOS MONSTROS: DEFENDA-SE!");
                        while(defenseloop < 1){
                            loop = 0;
                            printf("\nRode os dados:\n");
                            printf("\033[0;31m");
                            printf("DIGITE ROLL\n");
                            printf("\033[0;37m");
                            gets(combatroll);
                            if(strcasecmp(combatroll, "roll") == 0){
                                dice2();
                                damagemonster = numroll + monshability;
                                printf("\nFOR�A DE ATAQUE DOS MONSTROS: %d\n", damagemonster);

                                dice2();
                                playerhabil = numroll + hability;
                                printf("\n\nSUA DEFESA: %d\n", playerhabil);

                            }if(strcasecmp(combatroll, "roll") == 0 && playerhabil > damagemonster){
                                printf("VOC� CONSEGUIU SE DEFENDER!");
                                defenseloop += 1;
                                fight2 += 1;
                                combatloop2 += 1;
                                enter();

                            }if(strcasecmp(combatroll, "roll") == 0 && playerhabil < damagemonster){
                                printf("\nVOCE LEVOU DANO\n");
                                printf("\n\033[1;33mVoc� deseja testar sua SORTE? (digite \"sim\" ou \"nao\")\n");
                                printf("Sua SORTE ATUAL: %d\n\n\033[0;37m", luck);
                                while(loop < 1){
                                    gets(luckhit);
                                    if(strcasecmp(luckhit, "sim") == 0){
                                        dice2();
                                        if(numroll <= luck){
                                            luck--;
                                            printf("\n\nSua SORTE: %d", luck);
                                            energy += 1;
                                            loop++;
                                        }else{
                                            luck--;
                                            printf("\n\nSua SORTE: %d", luck);
                                            energy -= 1;
                                            loop++;
                                        }
                                        printf("\n\n");
                                    } else if(strcasecmp(luckhit, "nao") == 0)
                                        loop++;
                                }

                                energy -= 2;
                                printf("SEU HP: %d", energy);
                                defenseloop += 1;
                                fight2 += 1;
                                combatloop2 += 1;
                                enter();

                            }
                        }
                    }
                    if(energy <= 0){
                        death();
                    }
                    else if (monsenergy2 <= 0){
                        combatloop2 += 1;
                        fight2 += 2;
                        printf("VOCE GANHOU O COMBATE\n\n");
                        printf("COME�E O COMBATE COM O PROXIMO MONSTRO");
                        enter();
                        combat1();
                    }
                    if(fight1 == 2 && fight2 == 2){
                        combatloop2 += 1;
                        combatloop += 1;
                    system("cls");
                    }
                }
            }
        }
    }
}
//OPCAO 144

void OP144(){
    loop = 0;

    printf("\t144 - Ainda sorrindo, o velho olha para voc� e diz em voz baixa: \033[1;31m\"Errado.\".\033[0;37m");

    enter();
    OP085();
}

//OPCAO 145

void OP145(){
    loop = 0;
    monsenergy = 6;
    monshability = 8;

    printf("\t145 - O An�o estava esperando seu movimento. Al�m disso, voc� n�o � t�o r�pido quanto deveria, devido ao sofrimento recente, por isso ele evita seu golpe facilmente, dizendo: \"Eu poderia mat�-lo agora, se quisesse, mas estou com saudades de uma luta corpo a corpo.\" Em seguida, ele larga a besta no ch�o e puxa uma acha do cinto. Apesar da fadiga, voc� s� pensa em vingan�a.\n\n\033[1;31mAN�O HABILIDADE 8 ENERGIA 6\n\nVoc� lutar� com -2 de HABILIDADE, por causa da sua condi��o f�sica.\033[0;37m\n\n");

    hability -= 2;
    combat1();
    hability += 2;
    printf("\n\nSua HABILIDADE FOI RECUPERADA!\nSua ENERGIA: %i", energy);
    printf("\033[1;31m");
    printf("\n\nVoc� conseguiu sobreviver ao monstro!");
    printf("\033[0;37m");
    enter();
    OP028();
}

//OPCAO 146

void OP146(){
    stageops = 146;
    save();
    loop = 0;

    printf("\t146 - A dor nos pulm�es for�a-o a subir � superf�cie para respirar. Felizmente, nenhum dos Trogloditas o v� e todos se dispersam. Voc� sai do rio e atravessa a ponte para a margem norte. Quaisquer Provis�es restantes que voc� possa ter est�o agora imprest�veis. Voc� segue pela vasta caverna at� que, finalmente, v� um t�nel na parede do outro lado. Voc� anda at� ele e chega a uma pesada porta de madeira, que est� trancada.\n\nSe voc� tiver uma chave de ferro, \033[1;35mdigite 86.\033[0;37m\nSe n�o tiver a chave, \033[1;35mdigite 276.\033[0;37m\n\n");
    provisions = 0;

    printf("\033[1;34mLEMBRE-SE, VOC� PODE ACESSAR SEU INVENT�RIO DIGITANDO 0\033[0;37m\n\n");

    printf("Suas PROVIS�ES foram removidas do invent�rio.\n\n");
    while(loop < 1){
        scanf("%i", &choices);
        switch(choices){
            case 276:
                loop++;
                system("cls");
                OP276();
                break;
            case 86:
                loop++;
                if(iron_key != 0){
                    system("cls");
                    OP086();
                } else{
                    printf("Voc� n�o tem esta chave.");
                    enter();
                    OP146();
                }
                break;
            case 0:
                inventory();
                enter();
                OP146();
                break;
        }
    }
}

//OPCAO 147

void OP147(){
    printf("\t147 - A �gua no tubo de bambu � agradavelmente refrescante. \033[1;32mVoc� ganha 1 ponto de ENERGIA\033[0;37m. A �gua cont�m tamb�m uma solu��o m�gica que lhe permite expor-se a temperaturas alt�ssimas sem sofrer danos. Jogando fora o bambu, voc� segue para o norte de novo com excelente disposi��o.\n\n");

    if(status_OP147 == 0){
        high_temperature_potion += 1;
        energy += 1;
        status_OP147 += 1;
        printf("\033[1;32mVoc� ganhou 1 de ENERGIA");
        printf("\nSua ENERGIA: %i\033[0;37m", energy);
        enter();
        OP182();
    }else{
        printf("\033[1;31mVoc� j� esteve aqui, nada foi adicionado ao seu invent�rio.\033[0;37m\n\n");
        enter();
        OP182();
    }
}

//OPCAO 148

void OP148()
{
    loop = 0;
    luckloop = 0;

    printf("\t148 - Nada h� a fazer sen�o descer as escadas, na dire��o dos cachorros que latem. Voc� chega ao p� da escada com a espada na m�o e enfrenta os dois gigantescos C�ES DE GUARDA, que saltam sobre voc�, um de cada vez.\n\n\033[1;31mPRIMEIRO CAO DE GUARDA HABILIDADE 7 ENERGIA 7\nSEGUNDO CAO DE GUARDA HABILIDADE 7 ENERGIA 8\033[0;37m\n\n");

    monsenergy = 7;
    monshability = 7;
    combat1();
    loop = 0;
    while(loop < 1)
    {
        printf("Voc� deseja FUGIR?\n");
        gets(startroll);
        if(strcasecmp(startroll, "sim") == 0)
        {
            energy -= 2;
            printf("Voc� recebe 2 de dano.");
            if(energy <= 0)
                death();
            else if(energy > 0)
            {
                printf("\nVoc� deseja testar sua SORTE? (digite \"sim\" ou \"nao\")\n");
                while(luckloop < 1)
                {
                    gets(luckhit);
                    if(strcasecmp(luckhit, "sim") == 0){
                        dice2();
                        if(numroll <= luck){
                            luck--;
                            printf("\n\nSua SORTE: %d", luck);
                            energy += 1;
                            luckloop++;
                        }
                        else{
                            luck--;
                            printf("\n\nSua SORTE: %d", luck);
                            energy -= 1;
                            luckloop++;
                        }
                        enter();
                        OP315();
                    }
                    else if(strcasecmp(luckhit, "nao") == 0)
                        loop++;
                }
            }
        }
        else if(strcasecmp(startroll, "nao") == 0)
        {
            printf("\n\nVOC� ENFRENTAR� O SEGUNDO C�O! SE PREPARE PARA O COMBATE!\n");
            monsenergy = 8;
            monshability = 7;
            combat1();
            printf("\033[1;35m");
            printf("VOC� VENCEU OS DOIS INIMIGOS!\n");
            printf("\033[0;37m");
            printf("Sua ENERGIA: %d", energy);
            enter();
            OP175();
        }
    }
}

//OPCAO 149

void OP149(){
    loop = 0;
    printf("\t149 - Voc� solta a corda e ouve ela cair no fundo do po�o. O B�rbaro o amaldi�oa, prometendo mat�-lo se seus caminhos se cruzarem outra vez. Voc� recua, toma dist�ncia e salta. Cai em seguran�a do outro lado do po�o e continua para o oeste. Mais adiante no t�nel, voc� pisa em uma parte do ch�o de pedra que se inclina para frente, disparando uma armadilha que solta um rochedo preso frouxamente no teto. Voc� olha para cima bem no momento em que o rochedo est� prestes a cair sobre voc�. \033[1;33mDigite \"ROLL\" e teste sua SORTE.\033[0;37m\n\n");
    while(loop < 1){
        gets(startroll);
        if(strcasecmp(startroll, "roll") == 0){
            dice2();
            if(numroll <= luck){
                luck--;
                system("cls");
                OP070();
            }else{
                luck--;
                system("cls");
                OP353();
            }
        }
    }
}

//OPCAO 150

void OP150(){
    loop = 0;

    printf("\t150 - Tendo tido a boa id�ia de n�o p�r o seu bra�o da espada dentro do buraco, os efeitos do tent�culo n�o s�o muito graves. \033[1;31mVoc� perde 1 ponto de HABILIDADE\033[0;37m. Enfiando novamente o bra�o no buraco, de l� retira o gancho e a bolsa de couro. Dentro da bolsa, voc� encontra um min�sculo sino de metal. Guarda suas novas posses na mochila e continua para o norte.");


    if(status_OP150 == 0){
        hability -= 1;
        iron_hook += 1;
        metal_bell += 1;
        status_OP150 += 1;
        printf("\n\nSua HABILIDADE: %i", hability);

        printf("\033[1;34m");
        printf("\n- Gancho foi adicionada a seu invent�rio.");
        printf("\n- Sino de metal foi adicionada a seu invent�rio.");
        printf("\033[0;37m");
    }else{
        printf("\033[1;31mVoc� j� esteve aqui, nada foi adicionado ao seu invent�rio.\033[0;37m\n\n");
        enter();
        OP292();
    }
}

//OPCAO 151

void OP151(){
    loop = 0;

    printf("\t151 - Quando toca o olho de esmeralda do �dolo, voc� ouve um rangido abaixo. Ao olhar, fica abismado ao ver os dois p�ssaros empalhados voando. As asas das criaturas batem aos arrancos, mas logo est�o acima de voc� e parecem prontos para atacar. Lute com um dos GUARDI�ES VOADORES de cada vez, mas reduza sua HABILIDADE em 2 pontos durante este combate, pois a posi��o restringe-lhe os movimentos.\n\n\033[1;31mPRIMEIRO GUARDIAO VOADOR - HABILIDADE: 7 - ENERGIA: 8\nSEGUNDO GUARDI�O VOADOR - HABILIDADE: 8 - ENERGIA: 8\033[0;37m\n\n");
    hability -= 2;
    monsenergy = 7;
    monshability = 8;
    enter();
    combat1();
    printf("PREPARE-SE PARA O SEGUNDO COMBATE!");
    enter();
    monsenergy = 8;
    monshability = 8;
    combat1();

    hability += 2;
    OP240();
}

//OPCAO 152

void OP152(){
    loop = 0;

    printf("\t152 - O An�o o cumprimenta por ter adivinhado corretamente. Ele diz que agora voc� dever� seguir para a segunda fase do teste. Apanhando uma cesta de vime, ele lhe diz que h� uma cobra dentro dela. Vira a cesta e a cobra cai ao ch�o; � uma naja, que se ergue no ar, pronta para o bote. O An�o diz que quer testar suas rea��es. De m�os vazias, voc� dever� segurar a naja pelo pesco�o, evitando-lhe os dentes mortais.\n\nVoc� se agacha, tensionando os m�sculos para o momento decisivo. \033[1;33mDigite \"ROLL\" e teste sua HABILIDADE.\033[0;37m\n\n ");

    while(loop < 1){
        gets(startroll);
        if(strcasecmp(startroll, "roll") == 0){
            dice2();
            if(numroll <= hability){
                system("cls");
                OP055();
            }else{
                system("cls");
                OP202();
            }
        }
    }
}

//OPCAO 153

void OP153(){
    stageops = 153;
    save();
    loop = 0;

    printf("\t153 - A porta abre para um pequeno aposento, no qual h� um cr�nio humano cujos olhos s�o j�ias, pousado sobre um pedestal de m�rmore. Uma bateria de bestas com dardos est� fixada � parede da esquerda, e duas pequenas bolas de madeira est�o no ch�o, bem perto da porta. Voc�:\n\nEntrar� no aposento e apanhar� o cr�nio? Digite 390.\nJogar�, da porta, uma das bolas de madeira no cr�nio? \033[1;35mDigite 371.\033[0;37m\nFechar� a porta e continuar� para o oeste, levando as bolas de madeira? \033[1;35mDigite 74.\033[0;37m\n\n");

    printf("\033[1;34mLEMBRE-SE, VOC� PODE ACESSAR SEU INVENT�RIO DIGITANDO 0\033[0;37m\n\n");

    while(loop < 1){
        scanf("%i", &choices);
        switch(choices){
            case 390:
                loop++;
                system("cls");
                OP200();
                break;
            case 371:
                loop++;
                system("cls");
                OP316();
                break;
            case 74:
                loop++;
                system("cls");
                OP074();
                break;
            case 0:
                inventory();
                enter();
                OP153();
                break;
        }
    }
}

//OPCAO 154

void OP154(){
    printf("\t154 - Correndo pelo t�nel, voc� logo alcan�a o B�rbaro e diz a ele que a passagem do leste conduz a um beco sem sa�da. Ele faz um aceno com a cabe�a, num entendimento silencioso, e ambos partem para o oeste.\n\n");
    enter();
    OP022();
}

//OPCAO 155

void OP155(){
    stageops = 155;
    save();
    loop = 0;

    printf("\t155 - As palavras do poema dela cruzam velozmente a sua mente: \"Quando o corredor a �gua encontrar, n�o se apresse em recuar...\" Est� claro, � aqui que ela quer que voc� mergulhe na �gua. Agora, voc� deve decidir.\n\nSe quiser mergulhar na �gua, \033[1;35mdigite 378.\033[0;37m\nSe preferir caminhar de volta para o t�nel, \033[1;35mdigite 322.\033[0;37m");

    printf("\033[1;34mLEMBRE-SE, VOC� PODE ACESSAR SEU INVENT�RIO DIGITANDO 0\033[0;37m\n\n");

    while(loop < 1){
        scanf("%i", &choices);
        switch(choices){
            case 378:
                loop++;
                system("cls");
                OP378();
                break;
            case 322:
                loop++;
                system("cls");
                OP322();
                break;
            case 0:
                inventory();
                enter();
                OP155();
                break;
        }
    }
}

//OPCAO 156

void OP156(){
    stageops = 156;
    save();
    loop = 0;

    printf("\t156 - A pequena placa desliza e se abre facilmente, e voc� divisa um aposento com um po�o profundo no ch�o atr�s da porta. Na parede do outro lado, h� dois ganchos de ferro, num dos quais est� pendurado um rolo de corda.\n\nSe voc� quiser abrir a porta, pular por cima do po�o e pegar a corda, \033[1;35mdigite 208.\033[0;37m\nSe preferir continuar para o norte pelo t�nel, \033[1;35mdigite 326.\033[0;37m\n\n");

    printf("\033[1;34mLEMBRE-SE, VOC� PODE ACESSAR SEU INVENT�RIO DIGITANDO 0\033[0;37m\n\n");

    while(loop < 1){
        scanf("%i", &choices);
        switch(choices){
            case 208:
                loop++;
                system("cls");
                OP208();
                break;
            case 326:
                loop++;
                system("cls");
                OP326();
                break;
            case 0:
                inventory();
                enter();
                OP156();
                break;
        }
    }
}

//OPCAO 157

void OP157(){
    printf("\t157 - O pequeno cofre se abre facilmente; dentro, uma bolsa de veludo negro cont�m uma p�rola grande. \033[1;32mSome 1 ponto de SORTE\033[0;37m. Depois de p�r a p�rola no bolso, voc� avan�a em meio �s teias de aranha.");

    if(status_OP157 == 0){
        luck += 1;
        printf("Voc� ganhou 1 de SORTE.");
        printf("\n\nSua SORTE: %i", luck);
        enter();
        OP310();
    }else{
        printf("\033[1;31mVoc� j� esteve aqui, nada foi adicionado ao seu invent�rio.\033[0;37m\n\n");
        enter();
        OP310();
    }
}

//OPCAO 158

void OP158(){
    loop = 0;

    printf("\t158 - Voc� leva a moringa aos l�bios e toma um gole. O l�quido queima tanto que voc� larga a moringa e segura a garganta em agonia.\033[1;31m Voc� engoliu �cido! Perde 1 ponto de HABILIDADE e 4 de ENERGIA.\033[0;37m");

    if(status_OP158 == 0){
        hability -= 1;
        energy -= 4;
        status_OP158 += 1;
        printf("\n\nSua HABILIDADE CAIU EM 1");
        printf("\nSua HABILIDADE: %i", hability);
        printf("\n\nSua ENERGIA CAIU EM 4");
        printf("\nSua ENERGIA: %d", energy);
        enter();
        if(energy <= 0){
            death();
        }else if(energy > 0){
            printf("\n\nVoc� sobreviveu ao �cido!");
            enter();
            OP275();
        }
    }else{
        printf("\033[1;31mVoc� j� esteve aqui, nada foi adicionado ao seu invent�rio.\033[0;37m\n\n");
        printf("\n\nSua HABILIDADE CAIU EM 1");
        printf("\nSua HABILIDADE: %i", hability);
        printf("\n\nSua ENERGIA CAIU EM 4");
        printf("\nSua ENERGIA: %d", energy);
        enter();
        if(energy <= 0){
            death();
        }else if(energy > 0){
            printf("\n\nVoc� sobreviveu ao �cido!");
            enter();
            OP275();
        }
    }
}

//OPCAO 159

void OP159(){
    stageops = 159;
    save();
    loop = 0;

    printf("\t159 - Suas rea��es ainda est�o lentas por causa do veneno em seu organismo, e, embora voc� tente pular por cima da l�ngua estendida, suas pernas o traem. A l�ngua pegajosa se enrosca em torno da sua perna, derrubando-o, e come�a a puxa-lo na dire��o da po�a. A espada escorregou da sua m�o, e voc� come�a a entrar em p�nico.\n\nSe voc� tiver um punhal, \033[1;35mdigite 294.\033[0;37m\nSe n�o tiver um punhal, \033[1;35mdigite 334.\033[0;37m\n\n");

    printf("\033[1;34mLEMBRE-SE, VOC� PODE ACESSAR SEU INVENT�RIO DIGITANDO 0\033[0;37m\n\n");

    while(loop < 1){
        scanf("%i", &choices);
        switch(choices){
            case 334:
                loop++;
                system("cls");
                OP334();
                break;
            case 294:
                loop++;
                if(dagger != 0){
                    system("cls");
                    OP294();
                } else{
                    printf("Voc� n�o tem este item.");
                    enter();
                    OP159();
                }
                break;
            case 0:
                inventory();
                enter();
                OP159();
                break;
        }
    }
}

//OPCAO 160

void OP160(){
    printf("\t160 - Sua armadura e sua espada s�o pesadas e dificultam o salto, mas voc� aterrissa em seguran�a, por um triz, na borda do outro lado do po�o. Voc� n�o perde tempo e se encaminha para o leste.");
    enter();
    OP237();
}

//OPCAO 161

void OP161(){
    printf("\t161 - Voc� passa sem parar pelos dois Leprechauns e segue para o norte, os risos e a goza��o ainda ecoando nos seus ouvidos. Mais adiante no t�nel, voc� p�ra para descansar e verificar seus pertences. \033[1;31mSe voc� tinha gemas, elas agora sumiram.\033[0;37m O Leprechaum que caiu sobre as suas costas roubou-as da mochila. Voc� amaldi�oa os Leprechauns ladr�es e prossegue para o norte.\n\n");

    emerald = 0;
    sapphire = 0;
    ruby = 0;
    topaz = 0;
    printf("\033[1;34m");
    printf("VOC� PERDEU TODAS AS SUAS JOIAS");
    printf("\033[0;37m");
    enter();
    OP029();
}

//OPCAO 162

void OP162(){
    loop = 0;
    printf("\t162 - Retirando a tampa da caixa na luz do t�nel, voc� encontra uma chave de ferro e uma gema grande. � uma safira. \033[1;32mSome 1 ponto de SORTE.\033[0;37m Colocando as coisas cuidadosamente na mochila, voc� parte para o norte mais uma vez.");

    if(status_OP162 == 0){
        iron_key += 1;
        sapphire += 1;
        status_OP162 += 1;
        luck += 1;
        printf("\033[1;34m");
        printf("\n\nUma chave de ferro foi adicionada ao seu invent�rio");
        printf("\nUma safira foi adicionada ao seu invent�rio");
        printf("\n\n1 de SORTE foi adicionado");
        printf("\nSua SORTE: %i", luck);
        printf("\033[0;37m");
        enter();
        OP142();
    }else{
        printf("\033[1;34m");
        printf("\033[1;31mVoc� j� esteve aqui, nada foi adicionado ao seu invent�rio.\033[0;37m\n\n");
        printf("\nSua SORTE: %i", luck);
        printf("\033[0;37m");
        enter();
        OP142();
    }
}

//OPCAO 163

void OP163(){
    stageops = 163;
    save();
    loop = 0;

    printf("\t163 - O An�o congratula pela vit�ria. Ele joga um saco na arena e lhe diz para relaxar e recuperar as for�as para a parte final do teste. Depois, ele sai, dizendo que estar� de volta em 10 minutos. Voc� abre o saco e encontra uma moringa com vinho e galinha cozida.\n\nSe voc� quiser comer o que o An�o ofereceu, \033[1;35mdigite 363.\033[0;37m\nSe preferir simplesmente ficar sentado, esperando que ele volte, \033[1;35mdigite 302.\033[0;37m\n\n");

    printf("\033[1;34mLEMBRE-SE, VOC� PODE ACESSAR SEU INVENT�RIO DIGITANDO 0\033[0;37m\n\n");

    while(loop < 1){
        scanf("%i", &choices);
        switch(choices){
            case 363:
                loop++;
                system("cls");
                OP363();
                break;
            case 302:
                loop++;
                system("cls");
                OP302();
                break;
            case 0:
                inventory();
                enter();
                OP163();
                break;
        }
    }
}

//OPCAO 164

void OP164(){
    stageops = 164;
    save();
    loop = 0;

    printf("\t164 - Enquanto voc� caminha, pingos de �gua voltam a cair do teto do t�nel. Voc� v� pegadas �midas, feitas pelas mesmas botas que voc� havia seguido anteriormente, se dirigindo para o oeste. As pegadas conduzem a uma porta de ferro fechada na parede do lado direito do t�nel, mas n�o parecem continuar a partir dali.\n\nSe quiser abrir a porta, \033[1;35mdigite 299.\033[0;37m\nSe preferir continuar em frente para o oeste, \033[1;35mdigite 83.\033[0;37m\n\n");

    printf("\033[1;34mLEMBRE-SE, VOC� PODE ACESSAR SEU INVENT�RIO DIGITANDO 0\033[0;37m\n\n");

    while(loop < 1){
        scanf("%i", &choices);
        switch(choices){
            case 299:
                loop++;
                system("cls");
                OP299();
                break;
            case 83:
                loop++;
                system("cls");
                OP083();
                break;
            case 0:
                inventory();
                enter();
                OP164();
                break;
        }
    }
}

//OPCAO 165

void OP165(){
    printf("\t165 - H� uma ranhura no cadeado, na qual voc� coloca a moeda. Imediatamente, o cadeado se abre, e voc� consegue desacorrentar as pernas-de-pau. Voc� as coloca nos ombros e, mais uma vez, parte para o norte.");

    if(status_OP165 == 0){
        gold -= 1;
        wooden_legs += 1;
        status_OP165 += 1;
        printf("\n\n\033[1;31mUma moeda de ouro foi removida do invent�rio.");
        printf("\n\033[1;34mPernas-de-Pau foram adicionadas a seu invent�rio.\033[0;37m");
        enter();
        OP234();
    }else{
        printf("\033[1;31mVoc� j� esteve aqui, nada foi adicionado ao seu invent�rio.\033[0;37m\n\n");
        printf("\n\n\033[1;31mUma moeda de ouro foi removida do invent�rio.");
        printf("\n\033[1;34mPernas-de-Pau foram adicionadas a seu invent�rio.\033[0;37m");
        enter();
        OP234();
    }
}

//OPCAO 166

void OP166(){
    printf("\t166 - Ao tocar o olho de esmeralda do �dolo, voc� ouve um rangido abaixo de si. Olhando na dire��o do ru�do. Voc� fica abismado ao ver os dois p�ssaros empalhados voando. As asas dele batem aos arrancos, mas logo est�o sobre voc� e parecem prontos para atacar. Lute com os GUARDI�ES VOADORES um de cada vez, mas reduza a sua HABILIDADE em 3 pontos durante este combate, pois a posi��o restringe-lhe os movimentos.\n\n\033[1;31mPRIMEIRO GUARDIAO VOADOR HABILIDADE 7 ENERGIA 8\nSEGUNDO GUARDIAO VOADOR HABILIDADE 8 ENERGIA 8\033[0;37m\n\n");
    monsenergy = 8;
    monshability = 7;
    hability -= 3;
    printf("Sua HABILIDADE foi reduzida em 3\n");
    printf("Sua HABILIDADE: %d\n\n", hability);
    enter();
    combat1();
    printf("\n\nSua ENERGIA: %d", energy);
    printf("\n\nVOC� ENFRENTAR� O SEGUNDO GUARDIAO VOADOR! SE PREPARE PARA O COMBATE");
    monsenergy = 8;
    monshability = 8;
    enter();
    combat1();
    printf("\n\nSua ENERGIA: %d", energy);
    printf("\nVoc� recupera os movimentos e sua habilidade retorna ao normal");
    hability += 3;
    printf("\nSua HABILIDADE: %d", hability);
    enter();
    OP011();
}

//OPCAO 167

void OP167(){
    loop = 0;

    printf("\t167 - Voc� gira o gancho de ferro em torno da cabe�a e o atira na fera l� embaixo. As enormes mand�bulas do Diabo do Po�os e fecham firmemente sobre o gancho, e, em seguida, ele joga a cabe�a para tr�s. Ainda segurando a corda, voc� � puxado do alto da muralha e despenca no fundo do po�o. \033[1;31mVoc� perde 4 pontos de ENERGIA.\033[0;37m");

    if(status_OP167 == 0){
        energy -= 4;
        status_OP167 += 1;
        printf("\n\nSua ENERGIA CAIU EM 4");
        printf("\nSua ENERGIA: %d", energy);
        enter();
        if(energy <= 0){
            death();
        }else if(energy > 0){
            printf("\n\nVOCE SOBREVIVEU!");
            enter();
            OP203();
        }
    }else{
        printf("\n\nSua ENERGIA CAIU EM 4");
        printf("\nSua ENERGIA: %d", energy);
        enter();
        if(energy <= 0){
            death();
        }else if(energy > 0){
            printf("\n\nVOCE SOBREVIVEU!");
            enter();
            OP203();
        }
    }
}
//OPCAO 168

void OP168(){
    stageops = 168;
    save();
    loop = 0;

    printf("\t168 - Levantando o trinco e empurrando a pesada porta de pedra, voc� se v� em uma grande caverna. A luz � fraca e sombria, mas seus olhos logo se adaptam e voc� v� que as paredes s�o �midas e revestidas de algas verdes. O ch�o est� coberto de palha. A atmosfera � quente, �mida e f�tida, e um zumbido suave enche o ar. Com cautela, voc� avan�a pela palha na dire��o de um dos cantos da caverna, onde parece haver um po�o raso. Espiando com cuidado para dentro do po�o, voc� fica enojado ao ver uma massa de vermes esbranqui�ados que se contorcem, alguns deles chegando a meio metro de comprimento. Nauseado, voc� est� prestes a ir embora quando repara que os corpos ondulantes dos vermes est�o amontoados em torno de um punhal, cuja ponta est� firmemente presa a uma fenda no fundo do po�o. O cabo � envolto em couro negro com incrusta��es de opalas, e a l�mina � feita de um estranho metal lustrado preto-avermelhado. Voc� fica doido para pegar a arma, mas isso significaria enfiar a m�o no meio daqueles vermes.\n\nVoc� tenta apanhar o punhal? \033[1;35mDigite 94.\033[0;37m\nOu recua enojado e sai da caverna? \033[1;35mDigite 267.\033[0;37m\n\n");
    while(loop < 1){
        scanf("%i", &choices);
        switch(choices){
            case 94:
                loop++;
                system("cls");
                OP094();
                break;
            case 267:
                loop++;
                system("cls");
                OP267();
                break;
            case 0:
                inventory();
                enter();
                OP168();
                break;
        }
    }
}

//OPCAO 169

void OP169(){
    loop = 0;

    printf("\t169 - Ele olha desconfiado quando voc� lhe oferece uma parte das suas Provis�es. Mas a fome � mais forte que o medo, e ele acaba pondo a comida na boca. Voc� pergunta o que ele est� fazendo nos t�neis, e ele explica que � servo de um dos Ju�zes da Prova, os controladores de se��es do calabou�o designados pelo Bar�o Sukumvit. Diz que gostaria de escapar, mas ningu�m pode sair do calabou�o, a fim de impedir que o segredo da constru��o seja revelado. Voc� diz-se um dos concorrentes na Prova dos Campe�es e que apreciaria qualquer tipo de ajuda. Esfregando o queixo, ele vira-se para voc� e diz: \"Tudo o que lhe posso dizer � que, em um dos t�neis setentrionais, h� uma cadeira esculpida na forma de um p�ssaro demon�aco; um painel secreto no bra�o da cadeira cont�m uma po��o em um frasco de vidro. � uma Po��o de R�plica. Agora, preciso realizar minhas tarefas. Boa sorte. Espero que nos encontremos de novo fora destes t�neis infernais.\" O homem sai se arrastando e voc� continua sua jornada para o oeste.");

    if(status_OP169 == 0){
        knowledge_morph_potion += 1;
        provisions -= 1;
        status_OP169 += 1;
        printf("\033[1;34m");
        printf("\n\n\033[1;34mVOC� ADQUIRIU O CONHECIMENTO QUE EXISTE UMA PO��O DE R�PLICA, ACHE-A NO CALABOU�O\033[0;37m");
        printf("\033[0;37m");
        enter();
        OP109();
    }else{
        printf("\033[1;31mVoc� j� esteve aqui, nada foi adicionado ao seu invent�rio.\033[0;37m\n\n");
        enter();
        OP109();
    }
}

//OPCAO 170

void OP170(){
    stageops = 170;
    save();
    loop = 0;

    printf("\t170 - Ao se aproximar da figura prostrada, voc� v� que � um dos seus rivais na Prova dos Campe�es. �, na realidade, a Mulher-elfo. Ela luta tenazmente pela vida, envolta no abra�o de uma enorme JIB��IA que lhe esmaga os ossos.\n\nSe voc� quiser ajud�-la, \033[1;35mdigite 281.\033[0;37m\nSe preferir deix�-la � pr�pria sorte e retornar pelo t�nel para seguir para o norte, \033[1;35mdigite 192.\033[0;37m\n\n");
    while(loop < 1){
        scanf("%i", &choices);
        switch(choices){
            case 281:
                loop++;
                system("cls");
                OP281();
                break;
            case 192:
                loop++;
                system("cls");
                OP192();
                break;
            case 0:
                inventory();
                enter();
                OP170();
                break;
        }
    }
}

//OPCAO 171

void OP171(){
    loop = 0;

    printf("\t171 - A porta abre para um pequeno aposento, mas, antes que saiba o que est� acontecendo, voc� despenca no vazio havia um po�o atr�s da porta e voc� n�o o viu. Voc� cai pesadamente no fundo e se contorce em dores. \033[1;31mPerde 4 pontos de ENERGIA\033[0;37m. As paredes do po�o s�o rugosas e t�m muitos pontos onde apoiar os p�s e as m�os; por isso, voc� consegue fazer a escalada e sair com bastante facilidade. Voc� amaldi�oa sua pr�pria ansiedade e diz a si mesmo que doravante ser� mais cuidadoso. No interior do aposento, voc� v� dois ganchos de ferro numa das paredes. H� um rolo de corda pendurado em um deles; voc� o coloca na mochila, salta de volta por cima do po�o e sai do aposento, dirigindo-se ao norte.\n\n");

    if(status_OP171 == 0){
        rope += 1;
        energy -= 4;
        status_OP171 += 1;
        printf("\033[1;31mVoc� perdeu 4 de ENERGIA");
        printf("\nSua ENERGIA: %i\033[0;37m\n\n", energy);
        printf("\033[1;34mO ROLO DE CORDA FOI ADICIONADO A SEU INVENT�RIO\033[0;37m");
        enter();
        OP326();
    }else{
        printf("\033[1;31mVoc� j� esteve aqui, nada foi adicionado ao seu invent�rio.\033[0;37m\n\n");
        enter();
        OP326();
    }
}

//OPCAO 172

void OP172(){
    loop = 0;

    printf("\t172 - Lembrando da descri��o da abjeta Besta Sangrenta, e da advert�ncia quanto aos gases t�xicos que exalam da po�a da fera, voc� cobre a boca com a manga da camisa e, atento, avan�a, espada na m�o, para a l�ngua do monstro. Enquanto voc� contorna a po�a, a fera se projeta para frente e estica a l�ngua, mas voc� est� prevenido e a perfura com um golpe da espada. A fera urra de dor e se estica, fren�tica, para fora da po�a, tentando abocanh�-lo com as mand�bulas inundadas de sangue. Voc� golpeia-lhe a carantonha com a espada, na tentativa de atingir-lhe os olhos verdadeiros.\n\n\033[1;31mBESTA SANGRENTA - HABILIDADE: 12 - ENERGIA: 10\033[0;37m\n\n");

    monsenergy = 10;
    monshability = 12;

    printf("COME�OU O COMBATE!");
    combatloop = 0;
    atkseries = 0;
    while(combatloop < 1){
        loop = 0;
        printf("\nRode os dados:\n");
        printf("\033[0;31m");
        printf("DIGITE ROLL\n");
        printf("\033[0;37m");
        gets(combatroll);
        if(strcasecmp(combatroll, "roll") == 0){
            dice2();
            playerhabil = numroll + hability;
            printf("\n\nSUA FOR�A DE ATAQUE: %d\n\n", playerhabil);

            dice2();
            damagemonster = numroll + monshability;
            printf("\n\nFOR�A DE ATAQUE DO MONSTRO: %d\n", damagemonster);
        }
        if(strcasecmp(combatroll, "roll") == 0 && playerhabil > damagemonster){
            printf("\nVOC� CAUSOU DANO\n");
            atkseries += 1;
            monsenergy -= 2;
            if(atkseries >= 2){
                printf("\nVOC� GANHOU 2 S�RIES DE ATAQUE!");
                enter();
                OP278();
            }
            printf("\nVoc� deseja testar sua SORTE? (digite \"sim\" ou \"nao\")\n");
            while(loop < 1){
                gets(luckhit);
                if(strcasecmp(luckhit, "sim") == 0){
                    dice2();
                    if(numroll <= luck){
                        luck--;
                        printf("\n\nSua SORTE: %d", luck);
                        monsenergy -= 2;
                        loop++;
                    }
                    else{
                        luck--;
                        printf("\n\nSua SORTE: %d", luck);
                        monsenergy += 1;
                        loop++;
                    }
                    printf("\n\n");
                }
                else if(strcasecmp(luckhit, "nao") == 0){
                    loop++;
                }
            }
            printf("HP MONSTRO: %d", monsenergy);
            enter();
        }
        else if(strcasecmp(combatroll, "roll") == 0 && playerhabil < damagemonster){
            printf("\nVOCE LEVOU DANO\n");
            printf("\nVoc� deseja testar sua SORTE? (digite \"sim\" ou \"nao\")\n");
            while(loop < 1){
                gets(luckhit);
                if(strcasecmp(luckhit, "sim") == 0){
                    dice2();
                    if(numroll <= luck){
                        luck--;
                        printf("\n\nSua SORTE: %d", luck);
                        energy += 1;
                        loop++;
                    }
                    else{
                        luck--;
                        printf("\n\nSua SORTE: %d", luck);
                        energy -= 1;
                        loop++;
                    }
                    printf("\n\n");
                }
                else if(strcasecmp(luckhit, "nao") == 0){
                    loop++;
                }
            }
            energy -= 2;
            printf("SEU HP: %d", energy);
            enter();
        }
        else if(strcasecmp(combatroll, "roll") == 0 && playerhabil == damagemonster){
            printf("\nAMBOS CONSEGUIRAM SE DEFENDER E NINGU�M SE MACHUCOU");
            enter();
        }
        if(energy <= 0){
            death();
        }
        else if (monsenergy <= 0){
            combatloop += 1;
            printf("VOCE GANHOU O COMBATE");
            enter();
        }
        system("cls");
    }
}

//OPCAO 173

void OP173(){
    stageops = 173;
    save();
    loop = 0;

    printf("\t173 - A �gua fresca � revigorante e vem de uma fonte que foi salpicada com poeira de Duende.\n\nVoc� pode beber da outra fonte, digite 337.\nOu continuar para o norte, digite 368.\n\n");

    while(loop < 1){
        scanf("%i", &choices);
        switch(choices){
            case 337:
                loop++;
                system("cls");
                OP337();
                break;
            case 368:
                loop++;
                system("cls");
                OP368();
                break;
            case 0:
                inventory();
                enter();
                OP173();
                break;
        }
    }

}

//OPCAO 174

void OP174(){
    loop = 0;

    printf("\t174 - Quando voc� est� retornando para a porta, o zumbido aumenta de intensidade, e voc� procura desesperadamente descobrir de onde ele vem. Ao olhar para o alto, voc� v� num relance a imensa e grotesca forma negra de uma MOSCA GIGANTE surgindo de uma reentr�ncia no alto da parede da caverna. Ao se aproximar, voc� se d� conta de que ela tem pelo menos um metro e meio de comprimento. As asas opacas vibram, produzindo o abomin�vel zumbido que voc� vem ouvindo; as seis pernas peludas est�o posicionadas para agarr�-lo; abaixo dos olhos multifacetados, h� uma longa prob�scida, negra e lustrosa, que se movimenta malignamente para dentro e para fora. Voc� retirou o tesouro da Mosca Gigante do ninho de larvas, e agora deve enfrentar as consequ�ncias.\033[1;33m Digite \"ROLL\" e teste sua SORTE.\033[0;37m");

    while(loop < 1){
        gets(startroll);
        if(strcasecmp(startroll, "roll") == 0){
            dice2();
            if(numroll <= luck){
                luck--;
                system("cls");
                OP039();
            }else{
                luck--;
                system("cls");
                OP350();
            }
        }
    }
}

//OPCAO 175

void OP175(){
    loop = 0;

    printf("\t175 - Presa � coleira de um dos C�es de Guarda, h� uma c�psula de metal. Voc� retira a parte de cima da c�psula e encontra um pequeno dente l� dentro. � um dente de Leprechaum, que lhe trar� boa sorte. \033[1;32mSome 2 pontos de SORTE\033[0;37m. Voc� p�e o dente no bolso e parte para o leste pelo t�nel.");

    if(status_OP175 == 0){
        luck += 2;
        status_OP175 += 1;
        printf("\n\nFOI ADICIONADO DOIS PONTOS DE SORTE");
        printf("\nSua SORTE: %d", luck);
        enter();
        OP315();
    }else{
        printf("\033[1;31mVoc� j� esteve aqui, nada foi adicionado ao seu invent�rio.\033[0;37m\n\n");
        enter();
        OP315();
    }
}

//OPCAO 176

void OP176(){
    loop = 0;

    printf("\t176 - Caminhando cuidadosamente, voc� vai subindo os degraus devagar. Logo chega ao topo sem problemas. Continue pelo t�nel adiante.");
    enter();
    OP277();
}

//OPCAO 177

void OP177(){
    loop = 0;

    printf("\t177 - Voc� s� tem tempo para ouvir o Gnomo gritar: \"Tr�s coroas!\", antes que a fechadura estale e abra. Quando a pesada porta gira lentamente para fora, o Gnomo corre na dire��o dela, jogando a bola de vidro a seus p�s. Um g�s verde escapa do vidro quebrado, e voc� tenta n�o o inspirar. \033[1;33mDigite \"ROLL\" e teste sua SORTE.\033[0;37m\n\n");
    while(loop < 1){
        gets(startroll);
        if(strcasecmp(startroll, "roll") == 0){
            dice2();
            if(numroll <= luck){
                luck--;
                system("cls");
                OP243();
            }else{
                system("cls");
                OP103();
            }
        }
    }

}

//OPCAO 178

void OP178(){
    loop = 0;

    printf("\t178 - A porta n�o resiste �s violentas pancadas que voc� desfere. A placa central racha e se despeda�a; voc� abre a pontap�s um buraco grande o bastante para por ele se esgueirar. Molhado, mas feliz por ter sobrevivido a essa amea�a, voc� parte para o norte de novo.");
    enter();
    OP344();
}

//OPCAO 179

void OP179(){
    stageops = 179;
    save();
    loop = 0;

    printf("\t179 - Quando voc� parte na dire��o do An�o, ele tira do cinto dois dardos de m�o e os atira contra voc� e Throm, atingindo-os nas pernas. Ambos ficam instantaneamente paralisados pelo veneno existente na ponta dos dardos. Voc� perde 2 pontos de ENERGIA. Como que pregado ao ch�o, voc� v� o An�o se aproximar e retirar-lhe o dardo coxa. Ele pergunta se agora voc� est� disposto a entrar da em seu campeonato. Voc� se esfor�a para balan�ar a cabe�a afirmativamente. Aos poucos, os efeitos do veneno se dissipam, e a mobilidade retorna. O An�o ordena que voc� o siga e que Throm espere o retorno dele. Ele abre uma porta secreta na parede da c�mara, e voc�s entram em um pequeno aposento circular. Ele fecha a porta atr�s de voc� e lhe d� dois dados de osso, mandando que os jogue no ch�o. Voc� tira um seis e um dois, total oito. O An�o ordena um novo lan�amento, mas desta vez voc� tem que adivinhar o total: ser� igual, maior ou menor que oito?\n\nSe voc� preferir igual a oito, \033[1;35mdigite 290.\033[0;37m\nSe optar por maior que oito, \033[1;35mdigite 84.\033[0;37m\nSe escolher menor que oito, \033[1;35mdigite 191.\033[0;37m\n\n");
    while(loop < 1){
        scanf("%i", &choices);
        switch(choices){
            case 290:
                loop++;
                system("cls");
                OP290();
                break;
            case 84:
                loop++;
                system("cls");
                OP084();
                break;
            case 191:
                loop++;
                system("cls");
                OP191();
                break;
            case 0:
                inventory();
                enter();
                OP179();
                break;
        }
    }
}

//OPCAO 180

void OP180(){
    loop = 0;

    printf("\t180 - Voc� avan�a na dire��o da Besta Sangrenta; de repente, sente-se fraco. O g�s que emana da po�a � altamente t�xico, e voc� vai ao ch�o, inconsciente. \033[1;33mDigite \"ROLL e teste sua SORTE.\033[0;37m");
    while(loop < 1){
        gets(startroll);
        if(strcasecmp(startroll, "roll") == 0){
            dice2();
            if(numroll <= luck){
                luck--;
                system("cls");
                OP053();
            }else{
                luck--;
                system("cls");
                OP272();
            }
        }
    }
}

//OPCAO 181

void OP181(){
    loop = 0;

    printf("\t181 - O t�nel conduz a um sal�o com piso de m�rmore e pilares que se erguem at� o teto. Ao atravessar o piso, suas passadas ecoam pelo sal�o. Os cabelos da sua nuca come�am a ficar em p�, pois voc� pressente que est� sendo observado. Sem que voc� saiba, um dos seus rivais se esconde atr�s de um pilar. � o NINJA, o terr�vel assassino vestido com o manto negro. Sem qualquer ru�do, ele sai do esconderijo e joga um disco estrelado nas suas costas. Uma voz interior manda que voc� se abaixe. \033[1;33mDigite \"ROLL\" e teste sua SORTE.\033[0;37m");
    while(loop < 1){
        gets(startroll);
        if(strcasecmp(startroll, "roll") == 0){
            dice2();
            if(numroll <= luck){
                luck--;
                system("cls");
                OP312();
            }else{
                luck--;
                system("cls");
                OP045();
            }
        }
    }
}

//OPCAO 182

void OP182(){
    stageops = 182;
    save();
    loop = 0;

    printf("\t182 - A temperatura continua a subir, e voc� come�a a pingar suor. Adiante, o calor se intensifica. Parece que voc� est� numa fornalha. A situa��o � t�o insuport�vel que voc� come�a a desfalecer.\n\nSe voc� tiver bebido o l�quido do tubo de bambu, \033[1;35mdigite 25.\033[0;37m\nSe n�o tiver parado para beber o l�quido, \033[1;35mdigite 242.\033[0;37m\n\n");

    while(loop < 1){
        scanf("%i", &choices);
        switch(choices){
            case 242:
                loop++;
                system("cls");
                OP242();
                break;
            case 25:
                loop++;
                if(high_temperature_potion != 0){
                    system("cls");
                    OP025();
                } else{
                    printf("Voc� n�o leu este item.");
                    enter();
                    OP182();
                }
                break;
            case 0:
                inventory();
                enter();
                OP182();
                break;
        }
}
}

//OPCAO 183

void OP183(){
    stageops = 183;
    save();
    loop = 0;

    printf("\t183 - Voc� sobe nas pernas-de-pau e d� alguns passos experimentais. Sua confian�a aumenta, e logo voc� se sente capaz de enfrentar a caminhada pelo lodo. A fuma�a sobe da base das pernas-de-pau: o lodo come�a a corro�-las. Voc� segue em frente com firmeza e acaba atingindo terreno s�lido de novo. Infelizmente, as pernas-de-pau ficam cobertas de lodo, e voc� � for�ado a abandon�-las.\n\nSe quiser ir para o oeste, \033[1;35mdigite 386.\033[0;37m\nSe preferir continuar para o norte, \033[1;35mdigite 218.\033[0;37m\n\n");

    wooden_legs -= 1;
    printf("Pernas-de-Pau removidas do seu invent�rio.\n\n");

    while(loop < 1){
        scanf("%i", &choices);
        switch(choices){
            case 386:
                loop++;
                system("cls");
                OP386();
                break;
            case 218:
                loop++;
                system("cls");
                OP218();
                break;
            case 0:
                inventory();
                enter();
                OP183();
                break;
        }
    }
}

//OPCAO 184

void OP184(){
    stageops = 184;
    save();
    loop = 0;

    printf("\t184 - O B�rbaro, que se diz chamar Throm, amarra a corda em volta da cintura, dando-lhe a outra ponta. Ao acender a tocha, voc� nota um ar de desconfian�a nos olhos do B�rbaro. Lentamente, ele sobe na borda do po�o, enquanto voc� se firma no ch�o e segura a corda tensa. Ao abaix�-lo aos poucos, voc� v� os lados lisos do po�o iluminados pela tocha de Throm. Ele finalmente chega ao fundo e grita que h� um outro t�nel rumo ao norte. Manda que voc� prenda a corda em uma rocha saliente na borda do po�o e des�a.\n\nSe voc� quiser ficar com o B�rbaro e seguir para o norte pelo t�nel inferior, \033[1;35mdigite 323.\033[0;37m\nSe desejar abandon�-lo, pulando por cima do po�o para se dirigir ao oeste, \033[1;35mdigite 149.\033[0;37m");

    while(loop < 1){
        scanf("%i", &choices);
        switch(choices){
            case 323:
                loop++;
                system("cls");
                OP323();
                break;
            case 149:
                loop++;
                system("cls");
                OP149();
                break;
            case 0:
                inventory();
                enter();
                OP184();
                break;
        }
    }
}

//OPCAO 185

void OP185(){
    stageops = 185;
    save();
    loop = 0;

    printf("\t185 - Os Trogloditas est�o t�o concentrados na dan�a tribal que n�o ouvem o ru�do da sua espada, e voc� engatinha e passa. Quando acha que est� suficientemente longe, voc� se levanta e corre pelo piso da caverna. � sua frente, corre um rio subterr�neo de leste para oeste atrav�s da caverna; sobre ele, uma ponte de madeira. Ao ouvir um barulho, voc� olha para tr�s e toma consci�ncia de que foi descoberto. Os Trogloditas est�o vindo atr�s de voc�.\n\nSe quiser correr pela ponte, \033[1;35mdigite 318.\033[0;37m\nSe preferir mergulhar no rio, \033[1;35mdigite 47.\033[0;37m\n\n");

    while(loop < 1){
        scanf("%i", &choices);
        switch(choices){
            case 47:
                loop++;
                system("cls");
                OP047();
                break;
            case 318:
                loop++;
                system("cls");
                OP318();
                break;
            case 0:
                inventory();
                enter();
                OP185();
                break;
        }
    }
}

//OPCAO 186

void OP186(){
    loop = 0;

    printf("\t186 - Lenta e cuidadosamente, voc� come�a a escalar o �dolo. Quando est� prestes a segurar na grande orelha, seu p� escorrega. \033[1;33mDigite \"ROLL\" e teste sua SORTE.\033[0;37m\n\n");

    while(loop < 1){
        gets(startroll);
        if(strcasecmp(startroll, "roll") == 0){
            dice2();
            if(numroll <= luck){
                luck--;
                system("cls");
                OP260();
            }else{
                luck--;
                system("cls");
                OP358();
            }
        }
    }

}

//OPCAO 187

void OP187(){
    stageops = 187;
    save();
    loop = 0;

    printf("\t187 - O t�nel faz uma curva fechada para a direita, depois da qual voc� v� um velhinho de barba longa encolhido atr�s de uma grande cesta de vime. A cesta est� amarrada a uma corda cuja ponta desaparece no teto. Com apar�ncia preocupada,o velho diz: \"N�o me ataque, estranho. N�o sou nenhuma amea�a para voc�. Estou aqui simplesmente para ajud�-lo. Se voc� fizesse a gentileza de me oferecer algum tipo de remunera��o, eu ficarei feliz em i��-lo na cesta para o n�vel superior. E, acredite-me, voc� deveria estar l�.\".\n\nSe voc� quiser dar ao homem alguma coisa da sua mochila pelo servi�o, \033[1;35mdigite 360.\033[0;37m\nSe preferir passar por ele e seguir pelo t�nel, \033[0;35mdigite 280.\033[0;37m\n\n");

    while(loop < 1){
        scanf("%i", &choices);
        switch(choices){
            case 360:
                loop++;
                system("cls");
                OP360();
                break;
            case 280:
                loop++;
                system("cls");
                OP280();
                break;
            case 0:
                inventory();
                enter();
                OP187();
                break;
        }
    }
}

//OPCAO 188

void OP188(){
    stageops = 188;
    save();
    loop = 0;

    printf("\t188 - O t�nel come�a a declinar e termina numa po�a profunda.\n\nSe voc� conseguir se lembrar do poema da garota-esp�rito, \033[1;35mdigite 155.\033[0;37m\nSe n�o tiver encontrado a garota-esp�rito, \033[1;35mdigite 224.\033[0;37m\n\n");

    while(loop < 1){
        scanf("%i", &choices);
        switch(choices){
            case 224:
                loop++;
                system("cls");
                OP224();
                break;
            case 155:
                loop++;
                if(knowledge_deadgirl_poem != 0){
                    system("cls");
                    OP155();
                } else{
                    printf("Voc� n�o possui esta SKILL.");
                    enter();
                    OP188();
                }
                break;
            case 0:
                inventory();
                enter();
                OP188();
                break;
        }
}
    // KNOWLEDGE POEM OF THE SPIRIT GIRL
}

//OPCAO 189

void OP189(){
    printf("\t189 - As pontas da ma�a do Orca penetram dolorosamente na sua coxa esquerda. Voc� perde 3 pontos de ENERGIA. Voc� cambaleia para tr�s, mas consegue recuperar o equil�brio a tempo de se defender. Felizmente, o t�nel � estreito demais para que ambos os Orcas ataquem-no a um s� tempo. Lute com um de cada vez.\n\n\033[1;31mPRIMEIRA ORCA  HABILIDADE 5 ENERGIA 5\nSEGUNDA ORCA  HABILIDADE 6 ENERGIA 4\n\n\033[0;37m");

    monsenergy = 5;
    monshability = 5;
    enter();
    combat1();
    printf("PREPARE-SE PARA O SEGUNDO COMBATE!");
    enter();
    monsenergy = 4;
    monshability = 6;
    combat1();
    printf("Voc� derrotou AS DUAS ORCAS!");
    enter();
    OP257();
}

//OPCAO 190

void OP190(){
    loop = 0;

    printf("\t190 - Seu corpo vibra desenfreadamente, e voc� n�o consegue evitar o desmaio. \033[1;31mVoc� perde 3 pontos de ENERGIA\033[0;37m.\n\n");

    energy -= 3;
    printf("Voc� perdeu 3 de ENERGIA");
    printf("sua ENERGIA: %d", energy);
    if(energy <= 0)
    death();
    else{
        printf("Voc� sobreviveu");
        enter();
        OP050();
    }
}

//OPCAO 191

void OP191(){
    printf("\t191 - \033[1;33mDigite \"ROLL\" e role os dados.\033[0;37m\n\n");
    while(loop < 1){
        gets(startroll);
        if(strcasecmp(startroll, "roll") == 0){
            dice2();
            if(numroll <= 8){
                system("cls");
                OP152();
            }
            else{
                system("cls");
                OP121();
            }
        }
    }
}

//OPCAO 192

void OP192(){
    stageops = 192;
    save();
    loop = 0;

    printf("\t192 - Caminhando pelo t�nel, voc� repara em uma grade de ferro no ch�o.\n\nSe quiser parar e levant�-la, \033[1;35mdigite 120.\033[0;37m\nSe preferir prosseguir, \033[1;35mdigite 292.\033[0;37m\n\n");

    printf("\033[1;34mLEMBRE-SE, VOC� PODE ACESSAR SEU INVENT�RIO DIGITANDO 0\033[0;37m\n\n");

    while(loop < 1){
        scanf("%i", &choices);
        switch(choices){
            case 120:
                loop++;
                system("cls");
                OP120();
                break;
            case 292:
                loop++;
                system("cls");
                OP292();
                break;
            case 0:
                inventory();
                enter();
                OP192();
                break;
        }
    }
}

//OPCAO 193

void OP193(){
    printf("\t193 - O �cido queima a parede do seu est�mago, penetrando nos seus �rg�os vitais.\033[1;31m Voc� tomba inconsciente para nunca mais se recuperar. Sua aventura termina aqui.\033[0;37m");
    death();
}

//OPCAO 194

void OP194(){
    stageops = 194;
    save();
    loop = 0;

    printf("\t194 - Em uma plataforma de pedra na parede do t�nel, voc� v� dois livros empoeirados encadernado sem couro. Throm expressa seu desprezo pela palavra escrita com um grunhido, insistindo para que voc� deixe os livros de lado e siga adiante com ele. Voc�:\n\nAbrir� o livro de couro vermelho? \033[1;35mDigite 52.\033[0;37m\nAbrir� o livro de couro preto? \033[1;35mDigite 138.\033[0;37m\nContinuar� para o norte do t�nel? \033[1;35mDigite 369.\033[0;37m\n\n");

    while(loop < 1){
        scanf("%i", &choices);
        switch(choices){
            case 52:
                loop++;
                system("cls");
                OP052();
                break;
            case 138:
                loop++;
                system("cls");
                OP138();
                break;
            case 369:
                loop++;
                system("cls");
                OP369();
                break;
            case 0:
                inventory();
                enter();
                OP194();
                break;
        }
    }
}

//OPCAO 195

void OP195(){
    printf("\t195 - Voc� desembainha a espada e corre na dire��o do velho. Ele ergue o bra�o esquerdo e, subitamente, voc� esbarra em uma barreira invis�vel. \"N�o seja tolo, meus poderes s�o grandes!\", diz o velho calmamente. \"Se voc� n�o acredita em mim, veja isto.\" Saindo do nada, um punho voador lhe desfere um soco no rosto antes que voc� possa se esquivar. \033[1;31mVoc� perde 1 ponto de ENERGIA\033[0;37m. Voc� sacode a cabe�a e esfrega o queixo. Parece que n�o tem alternativa sen�o tentar responder � pergunta do velho.");

    energy -= 1;
    printf("\n\nVoc� perdeu 1 de ENERGIA\n");
    printf("Sua ENERGIA: %d\n", energy);
    if(energy <= 0)
        death();
    else{
        enter();
        OP382();
    }
}

//OPCAO 196

void OP196(){
    loop = 0;
    monsenergy = 11;
    monshability = 11;

    printf("\t196 - Voc� levanta o escudo bem a tempo de se proteger de uma saraivada de espinhos lan�ados contra seu cora��o pela cauda do Mant�cora. Ileso, com os espinhos cravados no escudo, voc� desembainha a espada e avan�a para o Mant�cora.\n\n\033[1;31mMANT�CORA - HABILIDADE: 11 - ENERGIA: 11\033[0;37m");

    enter();
    combat1();
    enter();
    OP364();
}

//OPCAO 197

void OP197(){
    stageops = 197;
    save();
    loop = 0;

    printf("\t197 - Gra�as aos c�us, a temperatura agora come�a a cair rapidamente, e logo parece quase fresca de novo. No lado esquerdo do t�nel, h� uma porta fechada e nela, uma pequena placa de ferro que talvez possa ser aberta. Voc�:\n\nTentar� abrir a porta? \033[1;35mDigite 171.\033[0;37m\nTentar� fazer deslizar a placa de ferro? \033[1;35mDigite 156.\033[0;37m\nContinuar� para o norte, subindo o t�nel? \033[1;35mDigite 326.\033[0;37m\n\n");

    while(loop < 1){
        scanf("%i", &choices);
        switch(choices){
            case 171:
                loop++;
                system("cls");
                OP171();
                break;
            case 156:
                loop++;
                system("cls");
                OP156();
                break;
            case 326:
                loop++;
                system("cls");
                OP326();
                break;
            case 0:
                inventory();
                enter();
                OP197();
                break;
        }
    }
}

//OPCAO 198

void OP198(){
    printf("\t198 - Quando o g�s se dissipa, voc� caminha de volta para a arca e olha dentro dela. H� uma corrente com pingente jogada no fundo, mas algu�m j� retirou a pedra que estava incrustada nele. Isso o aborrece tanto que voc� o atira ao ch�o e sai furioso do aposento, subindo o t�nel.");
    enter();
    OP230();
}

//OPCAO 199

void OP199(){
    loop = 0;

    printf("\t199 - Os dardos da besta s�o em n�mero t�o grande que � imposs�vel evit�-los. Jogue um dado para determinar o n�mero de dardos que lhe atingem o corpo, \033[1;31mperdendo 2 pontos de ENERGIA\033[0;37m para cada um deles. \033[1;33mDigite \"roll\" e role os dados.\033[0;37m");

    while(loop < 1){
        gets(startroll);
        if(strcasecmp(startroll, "roll")== 0){
            dice1();
            dards = (numroll * 2);
            energy -= dards;
            if(energy <= 0){
                loop++;
                death();
            }else{
                luck--;
                loop++;
                printf("\n\nVoc� ter� que descansar aqui por um longo tempo para se recuperar dos ferimentos. \033[1;31mPerde 1 ponto de SORTE.\033[0;37m Quando voc�, finalmente, se sente forte o bastante para seguir adiante, sai do aposento e continua para o oeste pelo t�nel.\n\n");

                printf("\033[1;31mVoc� perdeu 1 de SORTE\n\033[0;37m");
                printf("Sua SORTE: %d", luck);

                printf("\n\n\033[1;31mVoc� perdeu %d de ENERGIA com os dardos\n\033[0;37m", dards);
                printf("Sua ENERGIA: %d", energy);
                enter();
                OP074();
            }
        }
    }
}

//OPCAO 200

void OP200(){
    stageops = 200;
    save();
    loop = 0;

    printf("\t200 - A porta abre para um pequeno aposento como ch�o coberto de palha. No centro do aposento, h� uma grande gaiola coberta de cerca de dois metros de altura; uma corda presa ao topo da cobertura de pano passa por um anel de ferro no teto e desce at� o ch�o.\n\nSe voc� quiser levantar o pano, \033[1;35mdigite 321.\033[0;37m\nSe preferir sair do aposento e se dirigir para o norte pelo t�nel, \033[1;35mdigite 316.\033[0;37m\n\n");
    while(loop < 1){
        scanf("%i", &choices);
        switch(choices){
            case 321:
                loop++;
                system("cls");
                OP321();
                break;
            case 316:
                loop++;
                system("cls");
                OP316();
                break;
            case 0:
                inventory();
                enter();
                OP200();
                break;
        }
    }

}

//OPCAO 201

void OP201(){
    loop = 0;

    printf("\t201 - Voc� revista os arm�rios e caixas no quarto de Erva mas n�o encontra nada, a n�o ser um osso velho. H� uma porta na parede leste da c�mara, e voc� resolve sair. Pode levar o osso velho, se quiser. Voc� agora est� de p� no final de um outro t�nel.\n\n");
    printf("Deseja levar o osso velho? - Digite \033[1;32m\"SIM\"\033[0;37m ou \033[1;31m\"NAO\"\033[0;37m\n");

    while(loop < 1){
        gets(startroll);
        if(strcasecmp(startroll, "sim")== 0){
            loop++;
            old_bone += 1;
            printf("\033[1;34m");
            printf("\nO osso velho foi adicionado ao seu invent�rio");
            printf("\033[0;37m");
            enter();
            OP305();
        }else if(strcasecmp(startroll, "nao")== 0){
            loop++;
            enter();
            OP305();
        }
    }
}

//OPCAO 202

void OP202(){
    loop = 0;

    printf("\t202 - As rea��es da naja s�o mais r�pidas do que as suas, e a cabe�a estufada do animal se projeta para mord�-lo. \033[1;33mDigite \"ROLL\" e teste sua SORTE.\033[0;37m\n\n");
    while(loop < 1){
        gets(startroll);
        if(strcasecmp(startroll, "roll") == 0){
            dice2();
            if(numroll <= luck){
                luck--;
                system("cls");
                OP018();
            }else{
                luck--;
                system("cls");
                OP042();
            }
        }
    }
}

//OPCAO 203

void OP203(){
    loop = 0;
    monsenergy = 15;
    monshability = 12;

    printf("\t203 - Voc� se levanta com dificuldade e desembainha a espada. Faz isso bem a tempo, pois a assustadora fera se aproxima velozmente. Esta vai ser uma das lutas mais dif�ceis de sua vida.\n\n\033[1;31mDIABO DO PO�O HABILIDADE: 12 ENERGIA: 15\033[0;37m\n\n");
    combat1();
    printf("\nVOC� SOBREVIVEU A FERA ASSUSTADORA!\n");
    printf("\n\nSua ENERGIA: %i", energy);
    enter();
    OP258();
}

//OPCAO 204

void OP204(){
    loop = 0;

    printf("\t204 - H� uma placa sens�vel � press�o no topo do pedestal, e, logo que o cr�nio � colocado de volta sobre ele, o mecanismo invis�vel � disparado. Imediatamente, uma chuva de dardos lan�ados pela besta atravessa o aposento. \033[1;33mDigite \"ROLL\"\033[0;37m\n\n");

    while(loop < 1){
        gets(startroll);
        if(strcasecmp(startroll, "roll") == 0){
            dice2();
            if(numroll <= luck){
                luck--;
                system("cls");
                OP131();
            }else{
                luck--;
                system("cls");
                OP199();
            }
        }
    }
}

//OPCAO 205

void OP205(){
    stageops = 205;
    save();
    loop = 0;

    printf("\t205 - Correndo atr�s dos Leprechauns, voc� ouve mais risos, s� que agora eles v�m de tr�s de voc�. Voc� se vira e v� mais seis Leprechauns saindo de uma porta oculta na parede do t�nel. De repente, mais um Leprechaun salta de uma plataforma fixada no teto e cai sobre suas costas. Livrando-se dele com um safan�o, voc� desembainha a espada, o que faz com que os Leprechauns riam ainda mais alto.\n\nSe voc� quiser atac�-los, \033[1;35mdigite 306.\033[0;37m\nSe preferir tentar passar por eles, \033[1;35mdigite 161.\033[0;37m");

    printf("\033[1;34mLEMBRE-SE, VOC� PODE ACESSAR SEU INVENT�RIO DIGITANDO 0\033[0;37m\n\n");

    while(loop < 1){
        scanf("%i", &choices);
        switch(choices){
            case 306:
                loop++;
                system("cls");
                OP306();
                break;
            case 161:
                loop++;
                system("cls");
                OP161();
                break;
            case 0:
                inventory();
                enter();
                OP205();
                break;
        }
    }

}

//OPCAO 206

void OP206(){
    printf("\t206 - As estalactites continuam a cair ao redor, mas voc� n�o tem for�a suficiente para fazer mais do que se arrastar na dire��o do arco. De repente, sente um bra�o em volta da cintura e se d� conta, em estado de semi-inconsci�ncia, de que Throm o est� carregando. Ele o p�e na seguran�a do t�nel e cuida dos seus ferimentos. Voc� resolve comer parte das Provis�es para ajudar a recuperar as for�as, e d� tamb�m uma parte para Throm, como agradecimento por ele t�-lo salvado. Ele se desculpa por ter iniciado o desabamento das rochas e lhe oferece a m�o. Apesar da dor, voc� consegue sorrir e apertar a m�o dele. Quando voc� finalmente se recupera, levanta-se e segue para o leste, com Throm caminhando � sua frente.\n\n");

    provisions -= 2;
    printf("\033[1;31mVoc� perdeu parte de suas PROVIS�ES\n\033[0;37m");
    printf("\033[1;35m");
    printf("Suas PROVIS�ES: %d", provisions);
    printf("\033[0;37m");
    enter();
    OP060();
}

//OPCAO 207

void OP207(){
    stageops = 207;
    save();
    loop = 0;

    printf("\t207 - Voc� tira a camisa e a rasga ao meio, depois amarra cada um dos peda�os em volta de cada p�, a fim de se proteger em certa medida do lodo corrosivo, e dispara para cruz�-lo a passos largos. No terreno fume do outro lado do loda�al, voc� tenta freneticamente, com a espada, arrancar a camisa que queima em seus p�s. Por�m, parte do lodo penetrou at� seu tornozelo. \033[1;31mVoc� perde 3 pontos de ENERGIA\033[0;37m. Partindo para o norte de novo, voc� chega a uma encruzilhada. Se quiser ir para o oeste, \033[1;35mdigite 386.\033[0;37m\nSe preferir continuar para o norte, \033[1;35mdigite 218.\033[0;37m\n\n");

    printf("\033[1;34mLEMBRE-SE, VOC� PODE ACESSAR SEU INVENT�RIO DIGITANDO 0\033[0;37m\n\n");

    energy -= 3;
    printf("Voc� perdeu 3 de ENERGIA\n");
    printf("\n\nSua ENERGIA: %i\n\n", energy);
    while(loop < 1){
        scanf("%i", &choices);
        switch(choices){
            case 386:
                loop++;
                system("cls");
                OP386();
                break;
            case 218:
                loop++;
                system("cls");
                OP218();
                break;
            case 0:
                inventory();
                enter();
                OP207();
                break;
        }
    }


}

//OPCAO 208

void OP208(){
    loop = 0;

    printf("\t208 - A porta abre para o aposento; voc� toma dist�ncia e salta sobre o po�o. Coloca a corda na mochila e salta de volta por sobre o po�o para sair do aposento e prosseguir para o norte.");
    printf("A Corda foi adicionada ao seu invent�rio.");
    rope += 1;
    enter();
    OP326();
}

//OPCAO 209

void OP209(){
    loop = 0;

    printf("\t209 - Voc� fica desolado ao descobrir que n�o apenas todas as suas Provis�es restantes est�o encharcadas e imprest�veis para comer, mas tamb�m que um dos seus tesouros desapareceu. Jogue fora um item da sua Lista de Equipamentos ou uma de suas j�ias ou po��es. Voc� guarda cuidadosamente na mochila as posses que lhe restam e parte para o norte outra vez.\n\n");
    //v� para 356
    provisions = 0;
    printf("Escolha o item que voc� quer despejar:");
    printf("\n\nINVENT�RIO:\n");
    
    printf("\n\nPO��ES:\n");
    if(energy_potion == 0 && luck_potion == 0 && hability_potion == 0 && morph_potion == 0)
        printf("\n\033[1;31mVoc� n�o possui PO��ES\033[0;37m");
    if(luck_potion != 0)
        printf("\nPo��o de fortuna: x%d, se deseja jogar fora este po��o digite \033[1;33m\"1\"\033[0;37m", luck_potion);
    if(energy_potion != 0)
        printf("\nPo��o de for�a: x%d, se deseja jogar fora este po��o digite \033[1;33m\"2\"\033[0;37m", energy_potion);
    if(hability_potion != 0)
        printf("\nPo��o de habilidade: x%d, se deseja jogar fora esta po��o digite \033[1;33m\"3\"\033[0;37m", hability_potion);
    if(morph_potion != 0)
        printf("\nPo��o de R�plica: x%d, se deseja jogar fora este item digite \033[1;33m\"4\"\033[0;37m", morph_potion);

    printf("\n\nITENS COLETADOS:\n");
    if(iron_hook == 0 && iron_key == 0 && wood_tube == 0 && rope == 0 && metal_bell == 0 && chalice == 0 && leather_wristband == 0 && high_temperature_potion == 0)
        printf("\n\033[1;31mVoce n�o possui ITENS\033[0;37m");
    if(iron_hook != 0)
        printf("\nGancho de Ferro: x%d, se deseja jogar fora este item digite \033[1;33m\"5\"\033[0;37m", iron_hook);
    if(iron_key != 0)
        printf("\nChave de Ferro: x%d, se deseja jogar fora este item digite \033[1;33m\"6\"\033[0;37m", iron_key);
    if(wood_tube != 0)
        printf("\nTubo oco de Madeira: x%d, se deseja jogar fora este item digite \033[1;33m\"7\"\033[0;37m", wood_tube);
    if(rope != 0)
        printf("\nRolo de Corda: x%d, se deseja jogar fora este item digite \033[1;33m\"8\"\033[0;37m", rope);
    if(metal_bell != 0)
        printf("\nSino de Metal: x%d, se deseja jogar fora este item digite \033[1;33m\"9\"\033[0;37m", metal_bell);
    if(chalice != 0)
        printf("\nC�lice: x%d, se deseja jogar fora este item digite \033[1;33m\"10\"\033[0;37m", chalice);

    printf("\n\nJOIAS COLETADAS:\n");
    if(emerald == 0 && jewel == 0 && sapphire == 0 && diamond == 0 && ruby == 0 && topaz == 0)
        printf("\n\033[1;31mVoc� n�o possui JOIAS\033[0;37m");
    if(emerald != 0)
        printf("\nEsmeralda: x%d, se deseja jogar fora esta joia digite \033[1;33m\"11\"\033[0;37m", emerald);
    if(diamond != 0)
        printf("\nDiamante: x%d, se deseja jogar fora esta joia digite \033[1;33m\"12\"\033[0;37m", diamond);
    if(ruby != 0)
        printf("\nRubi: x%d, se deseja jogar fora esta joia digite \033[1;33m\"13\"\033[0;37m", ruby);
    if(topaz != 0)
        printf("\nTopazio: x%d, se deseja jogar fora esta joia digite \033[1;33m\"14\"\033[0;37m", topaz);
    if(sapphire != 0)
        printf("\nSafira: %d, se deseja jogar fora esta joia digite \033[1;33m\"15\"\033[0;37m", sapphire);
    if(jewel != 0)
        printf("\nJoia: x%d, se deseja jogar fora esta joia digite \033[1;33m\"16\"\033[0;37m", jewel);
    
    printf("\n\n");
    while(loop < 1){
        scanf("%d", &invuse);
        switch (invuse)
        {
        case 1:
            luck_potion -= 1;
            loop++;
            break;
        case 2:
            energy_potion -= 1;
            loop++;
            break;
        case 3:
            hability_potion -= 1;
            loop++;
            break;
        case 4:
            morph_potion -= 1;
            loop++;
            break;
        case 5:
            iron_hook -= 1;
            loop++;
            break;
        case 6:
            iron_key -= 1;
            loop++;
            break;
        case 7:
            wood_tube -= 1;
            loop++;
            break;
        case 8:
            rope -= 1;
            loop++;
            break;
        case 9:
            metal_bell -= 1;
            loop++;
            break;
        case 10:
            chalice -= 1;
            loop++;
            break;
        case 11:
            emerald -= 1;
            loop++;
            break;
        case 12:
            diamond -= 1;
            loop++;
            break;
        case 13:
            ruby -= 1;
            loop++;
            break;
        case 14:
            topaz -= 1;
            loop++;
            break;
        case 15:
            sapphire -= 1;
            loop++;
            break;
        case 16:
            jewel -= 1 ;
            loop++;
            break;
        }
    }
    printf("\n\033[1;31mVoc� jogou fora o item/joia selecionado\033[0;37m");
    enter();
    OP356();
}

//OPCAO 210

void OP210(){
    stageops = 210;
    save();
    loop = 0;

    printf("\t210 - Voc� entra em um aposento no qual h� um homem maltrapilho, de p�, acorrentado, � parede pelo bra�o esquerdo. Vendo que ele n�o tema m�o direita, voc� se d� conta de que a m�o pregada na porta deve ser dele. Implorando piedade, ele se encolhe para longe de voc�, tanto quanto as correntes permitem.\n\nSe voc� quiser libert�-lo das cadeias, \033[1;35mdigite 27.\033[0;37m\nSe preferir sair do aposento e se dirigir para o norte, \033[1;35mdigite 78.\033[0;37m\n\n");

    printf("\033[1;34mLEMBRE-SE, VOC� PODE ACESSAR SEU INVENT�RIO DIGITANDO 0\033[0;37m\n\n");

    while(loop < 1){
        scanf("%i", &choices);
        switch(choices){
            case 27:
                loop++;
                system("cls");
                OP027();
                break;
            case 78:
                loop++;
                system("cls");
                OP078();
                break;
            case 0:
                inventory();
                enter();
                OP210();
                break;
        }
    }

}

//OPCAO 211

void OP211(){
    loop = 0;
    monsenergy = 9;
    monshability = 9;

    printf("\t211 - Voc� consegue se livrar do aperto de Erva e desembainha a espada. Apanhando um banco quebrado para lhe servir de arma, ela avan�a na sua dire��o.\n\n\033[0;31mERVA HABILIDADE 9 ENERGIA 9\033[0;37m\n\n");
    enter();
    combat1();
    printf("\nVOC� DERROTOU A \"ERVA\"");
    printf("\nSua ENERGIA: %i", energy);
    enter();
    OP201;
}

//OPCAO 212

void OP212(){
    printf("\t212 - Segurando a corda firmemente, voc� toma dist�ncia para o salto. Contudo, sob a luz fraca, voc� n�o nota que algu�m enfraqueceu a corda, a ponto de parti-la em duas, logo acima do local em que voc� est� segurando. Quando se lan�a por sobre o po�o, a corda rompe e voc� grita de medo ao despencar de cabe�a nas profundezas.");
    enter();
    OP285();
}

//OPCAO 213

void OP213(){
    stageops = 213;
    save();
    loop = 0;

    printf("\t213 - O t�nel logo se divide em dois. Voc� ouve um zumbido que vem do ramo da direita. Se quiser caminhar para o oeste para investigar quem ou o que est� fazendo o ru�do, \033[1;35mdigite 108.\033[0;37m\nSe preferir continuar para o norte, \033[1;35mdigite 14.\033[0;37m\n\n");

    printf("\033[1;34mLEMBRE-SE, VOC� PODE ACESSAR SEU INVENT�RIO DIGITANDO 0\033[0;37m\n\n");

    while(loop < 1){
        scanf("%i", &choices);
        switch(choices){
            case 108:
                loop++;
                system("cls");
                OP108();
                break;
            case 14:
                loop++;
                system("cls");
                OP014();
                break;
            case 0:
                inventory();
                enter();
                OP213();
                break;
        }
    }
}

//OPCAO 214

void OP214(){
    stageops = 214;
    save();
    loop = 0;

    printf("\t214 - Caminhando em frente, voc� v� uma linha vermelha pintada no ch�o do t�nel e nota um aviso na parede que diz: \"Armas n�o s�o permitidas a partir deste ponto.\" \nSe voc� quiser abandonar suas armas antes de continuar para o norte, \033[1;35mdigite 389.\033[0;37m\nSe preferir ignorar o aviso e prosseguir para o norte, \033[1;35mdigite 181.\033[0;37m\n\n");

    printf("\033[1;34mLEMBRE-SE, VOC� PODE ACESSAR SEU INVENT�RIO DIGITANDO 0\033[0;37m\n\n");

    while(loop < 1){
        scanf("%i", &choices);
        switch(choices){
            case 389:
                loop++;
                system("cls");
                OP389();
                break;
            case 181:
                loop++;
                system("cls");
                OP181();
                break;
            case 0:
                inventory();
                enter();
                OP214();
                break;
        }
    }
}

//OPCAO 215

void OP215(){
    printf("\t215 - Sua espada arrebenta facilmente a fina casca externa da gigantesca bola de esporos. Uma espessa nuvem de esporos sa�da da bola se espalha e o envolve. Alguns dos esporos grudamse � sua pele, que come�a a co�ar terrivelmente. Aparecem grandes caro�os no seu rosto e bra�os, e sua pele parece estar em fogo. \033[1;31mVoc� perde 2 pontos de ENERGIA.\033[0;37m Co�ando freneticamente os caro�os, voc� passa por cima da bola de esporos, agora murcha, e segue para o oeste.\n\n");

    energy -= 2;
    printf("\033[1;31mVoc� perdeu dois de ENERGIA");
    printf("\nSua ENERGIA: %i\033[0;37m", energy);
    enter();
    OP013();
}

//OPCAO 216

void OP216(){
    stageops = 216;
    save();
    loop = 0;

    printf("\t216 - Reconhecendo a cabe�a de serpentes da Medusa, voc� fecha os olhos para evitar o olhar mortal da criatura que o transformaria em pedra.\nSe voc� quiser entrar na gaiola com os olhos fechados para enfrent�-la com sua espada, \033[1;35mdigite 308.\033[0;37m\nSe preferir recuar para sair do aposento com os olhos fechados e continuar para o norte, \033[1;35mdigite 316.\033[0;37m\n\n");

    printf("\033[1;34mLEMBRE-SE, VOC� PODE ACESSAR SEU INVENT�RIO DIGITANDO 0\033[0;37m\n\n");

    while(loop < 1){
        scanf("%i", &choices);
        switch(choices){
            case 308:
                loop++;
                system("cls");
                OP308();
                break;
            case 316:
                loop++;
                system("cls");
                OP316();
                break;
            case 0:
                inventory();
                enter();
                OP216();
                break;
        }
    }
}

//OPCAO 217

void OP217(){
    printf("\t217 - A passagem come�a a subir lentamente, conduzindo-o sempre para o norte. Voc� n�o passa por uma �nica encruzilhada. N�o h� portas ou mesmo uma alcova para ser investigada, e voc� vai ficando mais relaxado enquanto segue adiante. Depois de certo tempo, voc� se torna t�o temer�rio que n�o repara em um fino arame estendido bem baixo de lado a lado da passagem. Somente quando o seu p� o toca, e voc� ouve um ronco distante, � que se d� conta do erro que cometeu. O ronco cresce at� um n�vel ensurdecedor, e subitamente surge da penumbra do t�nel � sua frente um gigantesco rochedo que vem rolando na sua dire��o, ganhando velocidade a cada segundo. \033[1;31mLargando o escudo, se tiver um (voc� perde 1 ponto de HABILIDADE)\033[0;37m, voc� se volta para fugir do rochedo que se aproxima.\n\n");

    hability -= 1;
    printf("Voc� perdeu 1 de HABILIDADE");
    printf("\nSua HABILIDADE: %i", hability);
    if(shield != 0){
        shield = 0;
        printf("\033[1;34m");
        printf("Voc� perdeu seu Escudo");
        printf("\033[0;37m");
    }
    enter();
    OP036();
}

//OPCAO 218

void OP218(){
    stageops = 218;
    save();
    loop = 0;

    printf("\t218 - Voc� logo chega a uma porta dupla na parede da esquerda. Apura os ouvidos, mas n�o percebe nada. Tenta a ma�aneta, ela gira, voc� abre uma fresta na porta da esquerda e d� uma espiada. Um guerreiro armado jaz de bru�os no ch�o de um aposento vazio, de paredes lisas e teto baixo. Ele deve estar morto, pois permanece inerte mesmo quando voc� grita por ele. Uma j�ia grande, talvez um diamante, est� ca�da logo adiante do bra�o esticado.\nSe voc� quiser entrar no aposento e pegar a j�ia, \033[1;35mdigite 65.\033[0;37m\nSe preferir continuar para o norte, \033[1;35mdigite 252.\033[0;37m\n\n");

    printf("\033[1;34mLEMBRE-SE, VOC� PODE ACESSAR SEU INVENT�RIO DIGITANDO 0\033[0;37m\n\n");

    while(loop < 1){
        scanf("%i", &choices);
        switch(choices){
            case 65:
                loop++;
                system("cls");
                OP065();
                break;
            case 252:
                loop++;
                system("cls");
                OP252();
                break;
            case 0:
                inventory();
                enter();
                OP218();
                break;
        }
    }
}

//OPCAO 219

void OP219(){
    printf("\t219 - A dor nos pulm�es for�a-o a subir � tona para respirar. Infelizmente, um dos Trogloditas o v� e grita pelos companheiros. Indefeso, voc� v� os arqueiros fazerem pontaria, e uma saraivada de flechas cai sobre voc� com impacto fatal. \033[1;31mSeu corpo sem vida desce o rio boiando, penetrando nas profundezas ocultas da montanha.\033[0;37m");\
    death();
}

//OPCAO 220

void OP220(){
    stageops = 220;
    save();
    loop = 0;

    printf("\t220 - Um \"bong\" sombrio soa como um toque de sino f�nebre. Tudo vibra � sua volta, e voc� aperta os dentes quando sua cabe�a tamb�m estremece. Todo seu corpo est� tremendo, e voc� cai. Voc� tirita e tem calafrios, contorcendo-se convulsivamente no ch�o, � medida que as vibra��es se intensificam. Procura desesperadamente uma maneira de parar o sino. Voc�:\n\nGritar� o mais alto poss�vel? \033[1;35mDigite 61.\033[0;37m\nTentar� abafar o sino com sua bota? \033[1;35mDigite 346.\033[0;37m\n\n");

    printf("\033[1;34mLEMBRE-SE, VOC� PODE ACESSAR SEU INVENT�RIO DIGITANDO 0\033[0;37m\n\n");

    while(loop < 1){
        scanf("%i", &choices);
        switch(choices){
            case 61:
                loop++;
                system("cls");
                OP061();
                break;
            case 346:
                loop++;
                system("cls");
                OP346();
                break;
            case 0:
                inventory();
                enter();
                OP220();
                break;
        }
    }
}

//OPCAO 221

void OP221(){
    stageops = 221;
    save();
    loop = 0;

    printf("\t221 - O t�nel conduz a uma caverna �mida de teto alto, como ch�o coberto de rochas. Estalactites em forma de dentes pendem amea�adoramente, os pingos constantes criando po�as leitosas no ch�o. O t�nel prossegue atravessando a passagem em arco, a qual � talhada na forma de uma boca demon�aca.\nSe voc� quiser examinara caverna, \033[1;35mdigite 374.\033[0;37m\nSe preferir prosseguir direto pela passagem em arco, \033[1;35mdigite 60.\033[0;37m\n\n");

    printf("\033[1;34mLEMBRE-SE, VOC� PODE ACESSAR SEU INVENT�RIO DIGITANDO 0\033[0;37m\n\n");

    while(loop < 1){
        scanf("%i", &choices);
        switch(choices){
            case 374:
                loop++;
                system("cls");
                OP374();
                break;
            case 60:
                loop++;
                system("cls");
                OP060();
                break;
            case 0:
                inventory();
                enter();
                OP221();
                break;
        }
    }
}

//OPCAO 222

void OP222(){
    stageops = 222;
    save();
    loop = 0;

    printf("\t222 - Voc� reconhece a fera - � um MANT�CORA. Levando a s�rio a advert�ncia do poema, voc� fica atento para a cauda dele, de cuja ponta sai uma profus�o de espinhos afiados, grossos e duros como dardos de ferro. Se voc� tiver um escudo, \033[1;35mdigite 196.\033[0;37m\nSe n�o estiver carregando um escudo, \033[1;35mdigite 6.\033[0;37m\n\n");

    printf("\033[1;34mLEMBRE-SE, VOC� PODE ACESSAR SEU INVENT�RIO DIGITANDO 0\033[0;37m\n\n");

    while(loop < 1){
        scanf("%i", &choices);
        switch(choices){
            case 196:
                loop++;
                system("cls");
                OP196();
                break;
            case 6:
                loop++;
                system("cls");
                OP006();
                break;
            case 0:
                inventory();
                enter();
                OP222();
                break;
        }
    }
}

//OPCAO 223

void OP223(){
    loop = 0;

    printf("\t223 - Voc� pisa com confian�a no primeiro poste e avan�a para o pr�ximo. Ao tocar o terceiro poste, ele imediatamente solta uma chuva de farpas afiadas, cada uma com v�rios cent�metros de comprimento. \033[1;31mVoc� perde 2 pontos de SORTE\033[0;37m. As farpas voam em todas as dire��es a grande velocidade, e voc� n�o consegue evit�-las. \033[1;33mDigite \"ROLL\" para saber o n�mero de farpas que lhe penetram a pele.\033[1;31m Cada uma delas reduz sua ENERGIA em 1 ponto.\033[0;37m\n\n");

    luck -= 2;

    while(loop < 1){
        gets(startroll);
        if(strcasecmp(startroll, "roll") == 0){
            dice2();
            energy -= numroll;
            if(energy > 0){
                printf("\n\nSe voc� ainda estiver vivo, consegue arrastar-se por sobre os postes restantes e se senta para a dolorosa tarefa de retirar as farpas do corpo. Depois de descansar um pouco, voc� segue para o leste.");
                enter();
                OP313();
            }else if(energy <= 0){
                death();
            }
        }
    }
}

//OPCAO 224

void OP224(){
    loop = 0;

    printf("\t224 - Parece n�o haver como continuar para o norte. Voc� d� meia-volta e retorna pelo t�nel, passando pela cadeira de madeira. Logo chega � encruzilhada e vira � direita para seguir para o oeste.");

    enter();
    OP043();

}

//OPCAO 225

void OP225(){
    loop = 0;

    printf("\t225 - Voc� reage prontamente e, com um golpe de espada, consegue cortar a l�ngua estendida da Besta Sangrenta. A fera urra de dor e se atira para frente, tentando prend�-lo nas mand�bulas ensang�entadas. Esta ser� uma luta at� a morte.\n\n\033[1;31mBESTA SANGRENTA HABILIDADE 12 ENERGIA 10.\033[0;37m\n\nQuando vencer a sua primeira S�rie de Ataque, \033[1;33mteste sua SORTE.\033[0;37m");

    monshability = 12;
    monsenergy = 10;
    enter();

    printf("COME�OU O COMBATE!");
    combatloop = 0;
    while(combatloop < 1){
        loop = 0;
        printf("\nRode os dados:\n");
        printf("\033[0;31m");
        printf("DIGITE ROLL\n");
        printf("\033[0;37m");
        gets(combatroll);
        if(strcasecmp(combatroll, "roll") == 0){
            dice2();
            playerhabil = numroll + hability;
            printf("\n\nSUA FOR�A DE ATAQUE: %d\n\n", playerhabil);

            dice2();
            damagemonster = numroll + monshability;
            printf("\n\nFOR�A DE ATAQUE DO MONSTRO: %d\n", damagemonster);
        }
        if(strcasecmp(combatroll, "roll") == 0 && playerhabil > damagemonster){
            printf("\nVOC� CAUSOU DANO\n");
            monsenergy -= 2;
            printf("\nVoc� deseja testar sua SORTE? (digite \"sim\" ou \"nao\")\n");
            while(loop < 1){
                gets(luckhit);
                if(strcasecmp(luckhit, "sim") == 0){
                    dice2();
                    if(numroll <= luck){
                        luck--;
                        printf("\n\nSua SORTE: %d", luck);
                        monsenergy -= 2;
                        combatloop += 1;
                        loop++;
                        enter();
                        OP097();
                    }
                    else{
                        luck--;
                        printf("\n\nSua SORTE: %d", luck);
                        monsenergy += 1;
                        combatloop += 1;
                        loop++;
                        enter();
                        OP021();
                    }
                    printf("\n\n");
                }
                else if(strcasecmp(luckhit, "nao") == 0){
                    printf("\033[1;31mVOCE PRECISA TESTAR SUA SORTE\033[0;37m");
                }
            }
            printf("HP MONSTRO: %d", monsenergy);
            enter();
        }
        else if(strcasecmp(combatroll, "roll") == 0 && playerhabil < damagemonster){
            printf("\nVOCE LEVOU DANO\n");
            printf("\nVoc� deseja testar sua SORTE? (digite \"sim\" ou \"nao\")\n");
            while(loop < 1){
                gets(luckhit);
                if(strcasecmp(luckhit, "sim") == 0){
                    dice2();
                    if(numroll <= luck){
                        luck--;
                        printf("\n\nSua SORTE: %d", luck);
                        energy += 1;
                        loop++;
                    }
                    else{
                        luck--;
                        printf("\n\nSua SORTE: %d", luck);
                        energy -= 1;
                        loop++;
                    }
                    printf("\n\n");
                }
                else if(strcasecmp(luckhit, "nao") == 0){
                    loop++;
                }
            }
            energy -= 2;
            printf("SEU HP: %d", energy);
            enter();
        }
        else if(strcasecmp(combatroll, "roll") == 0 && playerhabil == damagemonster){
            printf("\nAMBOS CONSEGUIRAM SE DEFENDER E NINGU�M SE MACHUCOU");
            enter();
        }
        if(energy <= 0){
            death();
        }
        else if (monsenergy <= 0){
            combatloop += 1;
            printf("VOCE GANHOU O COMBATE");
            enter();
        }
        system("cls");
    }

}

//OPCAO 226

void OP226(){
    stageops = 226;
    save();
    loop = 0;

    printf("\t226 - A carne cont�m ervas que lhe aumentar�o a for�a. \033[1;31mSome 3 pontos seu �ndice de ENERGIA.\033[0;37m\n\nVoc� pode caminhar at� a alcova, se ainda n�o o fez, \033[1;35mdigite 41.\033[0;37m\n\nOu sair da c�mara e continuar para o oeste, \033[1;35mdigite 83.\033[0;37m\n\n");

    if(status_OP226 == 0){
        status_OP226 += 1;
        energy += 3;
        printf("Voc� ganhou 3 de ENERGIA");
        printf("\nSua ENERGIA: %i\n\n", energy);
        while(loop < 1){
            scanf("%i", &choices);
            switch(choices){
                case 83:
                    loop++;
                    system("cls");
                    OP083();
                    break;
                case 316:
                    loop++;
                    system("cls");
                    OP316();
                    break;
                case 0:
                    inventory();
                    enter();
                    OP226();
                    break;
            }
        }
    }else{
        printf("\033[1;31mVoc� j� esteve aqui, nada foi adicionado ao seu invent�rio.\033[0;37m\n\n");
        printf("\nSua ENERGIA: %i\n\n", energy);
        while(loop < 1){
            scanf("%i", &choices);
            switch(choices){
                case 83:
                    loop++;
                    system("cls");
                    OP083();
                    break;
                case 316:
                    loop++;
                    system("cls");
                    OP316();
                    break;
                case 0:
                    inventory();
                    enter();
                    OP226();
                    break;
            }
        }
    }
}

//OPCAO 227

void OP227(){
    printf("\t227 - Ainda sorrindo, o velho olha para voc�. \033[1;31m\"Errado\"\033[0;37m, ele diz em voz baixa.");

    enter();
    OP085();
}

//OPCAO 228

void OP228(){
    loop = 0;

    printf("\t228 - Voc� enfia o bra�o no buraco e sente seu sangue gelar quando uma coisa quente e pegajosa se enrosca nele. Voc� consegue tirar o bra�o de dentro do buraco, mas um horrendo tent�culo, com ventosas incrivelmente fortes, est� pendurado nele. Quando voc� consegue se libertar, cortando o tent�culo, seu bra�o d�i e lateja. \033[1;33mDigite \"ROLL\" e teste sua SORTE.\033[0;37m\n\n");
    while(loop < 1){
        gets(startroll);
        if(strcasecmp(startroll, "roll") == 0){
            dice2();
            if(numroll <= luck){
                luck--;
                system("cls");
                OP150();
            }else{
		    luck--;
                system("cls");
                OP033();
            }
        }
    }

}

//OPCAO 229

void OP229(){
    printf("\t229 - Logo que sua cabe�a entra embaixo da luz azul, voc� ouve o som de vozes abafadas. Os rostos j� n�o riem, e as express�es s�o agora m�scaras de desespero e ang�stia. O rosto triste de uma menina paira � sua frente, ela come�a a sussurrar um poema. Em transe, voc� ouve atentamente, acreditando que ela tem uma mensagem especial para voc�, enquanto ela recita:\033[1;35m\"Quando o corredor a �gua encontrar, N�o se apresse em recuar. Mergulhe depois dos pulm�es encher, Se sua Prova espera vencer.\"\033[0;37m Guardando de cor o poema da garota-esp�rito, voc� atravessa o raio de luz e se dirige rapidamente para o norte.\n\n");

    if(status_OP229 == 0){
        knowledge_deadgirl_poem += 1;
        status_OP229 +=1;
        printf("\033[1;34mVoc� adquiriu o conhecimento do poema da garota morta\033[0;37m");
        enter();
        OP107();
    }else{
        printf("\033[1;31mVoc� j� esteve aqui, nada foi adicionado ao seu invent�rio.\033[0;37m\n\n");
        enter();
        OP107();
    }
}

//OPCAO 230

void OP230(){
    stageops = 230;
    save();
    loop = 0;

    printf("\t230 - O t�nel come�a a se alargar e abre para uma imensa caverna, de onde voc� pode ouvir o som de muitas vozes agudas. Voc� se aproxima silenciosamente da entrada e espia. Cerca de 20 min�sculos seres, com narizes e orelhas compridos, correm em c�rculo em volta de uma grande ef�gie de ouro. Voc�:\n\nAndar� at� eles para conversar? Digite 85.\nTentar� se esgueirar e passar por eles? \033[1;35mDigite 5.\033[0;37m\nBeber� a Po��o da R�plica (se voc� a tiver)? \033[1;35mDigite 385.\033[0;37m");

    while(loop < 1){
        scanf("%i", &choices);
        switch(choices){
            case 85:
                loop++;
                system("cls");
                OP085();
                break;
            case 5:
                loop++;
                system("cls");
                OP005();
                break;
            case 222:
                loop++;
                if(morph_potion != 0){
                    system("cls");
                    OP385();
                } else{
                    printf("Voc� n�o possui este item.");
                    enter();
                    OP134();
                }
                break;
            case 0:
                inventory();
                enter();
                OP230();
                break;
        }
    }
}

//OPCAO 231

void OP231(){
    printf("\t231 - Voc� encontra uma po�a atr�s dos Hobglobins mortos e toma grandes goles de �gua fresca o mais r�pido poss�vel. Isso neutraliza o �cido e, lentamente, voc� come�a a se recuperar. Ainda com dor, voc� se levanta e parte para o norte.");

    enter();
    OP110();
}

//OPCAO 232

void OP232(){
    stageops = 232;
    save();
    loop = 0;

    printf("\t232 - Se voc� estiver desarmado, \033[1;35mdigite 286.\033[0;37m\nSe ainda estiver com suas armas, \033[1;35mdigite 320.\033[0;37m\n\n");
    while(loop < 1){
        scanf("%i", &choices);
        switch(choices){
            case 320:
                loop++;
                system("cls");
                OP320();
                break;
            case 286:
                loop++;
                if(disarmed != 0){
                    system("cls");
                    OP286();
                } else{
                    printf("\nVoc� est� armado.");
                    enter();
                    OP232();
                }
                break;
            case 0:
                inventory();
                enter();
                OP232();
                break;
        }
    }
}

// OP��O 233
void OP233(){
    printf("\t233 - Voc� parte um peda�o grande do cogumelo e o mastiga ansiosamente. De imediato, seu est�mago incha, e voc� pode mesmo v�-lo estufando por baixo do cinto. Todo o seu corpo come�a a se expandir, rasgando-lhe ruidosamente as roupas. Voc� fica cada vez maior, e logo seu rosto est� imprensado de encontro ao teto. Os cogumelos que voc� comeu s�o muito procurados por m�gicos para as po��es de crescimento, mas para voc� eles significam a morte. Voc� est� grande demais para poder algum dia sair da adega. \033[1;31mSua aventura termina aqui.\033[0;37m");
    death();
}

// OP��O 234
void OP234(){
    stageops = 234;
    save();
    loop = 0;

    printf("\t234 - Um pouco mais adiante, voc� chega a uma parte do t�nel coberta de lodo verde e espesso. Parece amea�ador, por isso voc� resolve test�-lo primeiro com um peda�o de pano. A pasta corrosiva do lodo queima o pano instantaneamente, n�o deixando nem sinal dele.\n\nSe voc� estiver carregando um par de pernas-de-pau, \033[1;35mdigite 183.\033[0;37m\nSe n�o as tiver, \033[1;35mdigite 207.\033[0;37m\n\n");

    while(loop < 1){
        scanf("%i", &choices);
        switch(choices){
            case 207:
                loop++;
                system("cls");
                OP207();
                break;
            case 183:
                loop++;
                if(wooden_legs != 0){
                    system("cls");
                    OP183();
                } else{
                    printf("Voc� n�o tem este item.");
                    enter();
                    OP234();
                }
                break;
            case 0:
                inventory();
                enter();
                OP234();
                break;
        }
    }

}

//OPCAO 235
void OP235(){
    printf("\t235 - Voc� n�o tem tempo para reagir antes que o dardo se crave na sua coxa. \033[1;31mVoc� perde 2 pontos de ENERGIA.\033[0;37m");

    energy -= 2;
    printf("\n\nSua ENERGIA: %i", energy);
    if(energy <= 0){
        death();
    } else
    printf("Voc� sobreviveu ao Dardo");
    enter();
    OP073();
}

//OPCAO 236
void OP236(){
    loop = 0;
    monsenergy = 8;
    monshability = 9;
    
    printf("\t236 - O punho recua e prepara um novo ataque. Com a m�o livre, voc� puxa a espada e tenta cortar a ma�aneta da porta. Embora n�o o reconhe�a, voc� est� sendo atacado pela forma fluida de um IMITADOR.\n\n\033[1;31mIMITADOR HABILIDADE 9 ENERGIA 8\033[0;37m\n\n");

    enter();
    printf("COME�OU O COMBATE!");
    combatloop = 0;
    while(combatloop < 1){
        loop = 0;
        printf("\nRode os dados:\n");
        printf("\033[0;31m");
        printf("DIGITE ROLL\n");
        printf("\033[0;37m");
        gets(combatroll);
        if(strcasecmp(combatroll, "roll") == 0){
            dice2();
            playerhabil = numroll + hability;
            printf("\n\nSUA FOR�A DE ATAQUE: %d\n\n", playerhabil);

            dice2();
            damagemonster = numroll + monshability;
            printf("\n\nFOR�A DE ATAQUE DO MONSTRO: %d\n", damagemonster);
        }
        if(strcasecmp(combatroll, "roll") == 0 && playerhabil > damagemonster){
            printf("\nVOC� CAUSOU DANO\n");
            printf("AGORA � SUA HORA DE BATER EM RETIRADA!");
            enter();
            OP314();
        }
        else if(strcasecmp(combatroll, "roll") == 0 && playerhabil < damagemonster){
            printf("\nVOCE LEVOU DANO\n");
            printf("\nVoc� deseja testar sua SORTE? (digite \"sim\" ou \"nao\")\n");
            while(loop < 1){
                gets(luckhit);
                if(strcasecmp(luckhit, "sim") == 0){
                    dice2();
                    if(numroll <= luck){
                        luck--;
                        printf("\n\nSua SORTE: %d", luck);
                        energy += 1;
                        loop++;
                    }
                    else{
                        luck--;
                        printf("\n\nSua SORTE: %d", luck);
                        energy -= 1;
                        loop++;
                    }
                    printf("\n\n");
                }
                else if(strcasecmp(luckhit, "nao") == 0){
                    loop++;
                }
            }
            energy -= 2;
            printf("SEU HP: %d", energy);
            enter();
        }
        else if(strcasecmp(combatroll, "roll") == 0 && playerhabil == damagemonster){
            printf("\nAMBOS CONSEGUIRAM SE DEFENDER E NINGU�M SE MACHUCOU");
            enter();
        }
        if(energy <= 0){
            death();
        }
        else if (monsenergy <= 0){
            combatloop += 1;
            printf("VOCE GANHOU O COMBATE");
            enter();
        }
        system("cls");
    }
}

//OPCAO 237
void OP237(){
    stageops = 237;
    save();
    loop = 0;

    printf("\t237 - O t�nel faz uma curva s�bita para a esquerda e continua para o norte at� onde a vista alcan�a. Voc� logo chega a uma porta de madeira, fechada, na parede do lado esquerdo.\n\nSe voc� quiser abrir a porta, \033[1;35mdigite 12.\033[0;37m\nSe preferir continuar seguindo para o norte, \033[1;35mdigite 100.\033[0;37m\n\n");

    printf("\033[1;34mLEMBRE-SE, VOC� PODE ACESSAR SEU INVENT�RIO DIGITANDO 0\033[0;37m\n\n");

    while(loop < 1){
        scanf("%i", &choices);
        switch(choices){
            case 12:
                loop++;
                system("cls");
                OP012();
                break;
            case 100:
                loop++;
                system("cls");
                OP100();
                break;
            case 0:
                inventory();
                enter();
                OP237();
                break;
        }
    }
}

//OPCAO 238
void OP238(){
    loop = 0;

    printf("\t238 - Ao cair, voc� consegue agarrar a corda com as m�os. Lentamente, voc� se i�a at� o outro lado e sobe para o piso. Voc� retira o elmo do poste e o p�e na cabe�a. O elmo foi feito por um ferreiro altamente habilidoso.\033[1;32m Some 1 ponto de HABILIDADE\033[0;37m. N�o querendo se arriscar a caminhar de volta pela corda bamba, voc� resolve engatinhar por ela. De volta ao terreno firme, em seguran�a, voc� atravessa a passagem em arco para seguir pelo t�nel na dire��o norte.\n\n");

    hability =+ 1;
    printf("Voc� ganhou 1 de HABILIDADE");
    printf("\nSua HABILIDADE: %i", hability);
    enter();
    OP291();
}

//OPCAO 239
void OP239(){
    stageops = 239;
    save();
    loop = 0;

    printf("\t239 - N�o muito adiante, o t�nel chega a uma porta fechada � sua esquerda. Colocando o ouvido na porta, voc� escuta, mas n�o ouve nada. Se voc� quiser abrir a porta, \033[1;35mdigite 102.\033[0;37m\nSe desejar prosseguir para o norte, \033[1;35mdigite 344.\033[0;37m\n\n");

    printf("\033[1;34mLEMBRE-SE, VOC� PODE ACESSAR SEU INVENT�RIO DIGITANDO 0\033[0;37m\n\n");

    while(loop < 1){
        scanf("%i", &choices);
        switch(choices){
            case 102:
                loop++;
                system("cls");
                OP102();
                break;
            case 344:
                loop++;
                system("cls");
                OP344();
                break;
            case 0:
                inventory();
                enter();
                OP239();
                break;
        }
    }


}

//OPCAO 240
void OP240(){
    stageops = 240;
    save();
    loop = 0;

    printf("\t240 - Voc� olha para baixo e v� esparramados no ch�o os corpos inertes dos Guardi�es Voadores. Voc� come�a a for�ar o olho esquerdo de esmeralda do �dolo com a ponta da espada. Finalmente, ele se solta e cai na sua m�o; o peso da pedra o deixa surpreso. Esperando que seja de utilidade mais tarde, voc� a guarda na mochila. Se quiser agora for�ar o olho direito, \033[1;35mdigite 34.\033[0;37m\nSe preferir descer do �dolo, \033[1;35mdigite 89.\033[0;37m\n\n");

    printf("\033[1;34mLEMBRE-SE, VOC� PODE ACESSAR SEU INVENT�RIO DIGITANDO 0\033[0;37m\n\n");

    if(status_OP240 >= 0 && status_OP240 <= 3){
        emerald += 1;
        status_OP240 += 1;
        printf("\033[1;34m");
        printf("Uma Esmeralda foi adicionada a seu invent�rio\n");
        printf("\033[0;37m");
        while(loop < 1){
            scanf("%i", &choices);
            switch(choices){
                case 34:
                    loop++;
                    system("cls");
                    OP034();
                    break;
                case 89:
                    loop++;
                    system("cls");
                    OP089();
                    break;
                case 0:
                    inventory();
                    enter();
                    OP240();
                    break;
            }
        }
    }else{
        printf("\033[1;31mVoc� j� esteve aqui, nada foi adicionado ao seu invent�rio.\033[0;37m\n\n");
        while(loop < 1){
            scanf("%i", &choices);
            switch(choices){
                case 34:
                    loop++;
                    system("cls");
                    OP034();
                    break;
                case 89:
                    loop++;
                    system("cls");
                    OP089();
                    break;
                case 0:
                    inventory();
                    enter();
                    OP240();
                    break;
            }
        }
    }
}

//OPCAO 241
void OP241(){
    stageops = 241;
    save();
    loop = 0;

    printf("\t241 - Uma cortina de veludo marrom fecha uma passagem em arco na parede oriental do t�nel. Se voc� quiser descerrar a cortina e atravessar a passagem em arco, \033[0;35mdigite 393.\033[0;37m\nSe preferir continuar para o norte, \033[1;35mdigite 291.\033[0;37m\n\n");

    printf("\033[1;34mLEMBRE-SE, VOC� PODE ACESSAR SEU INVENT�RIO DIGITANDO 0\033[0;37m\n\n");

    while(loop < 1){
        scanf("%i", &choices);
        switch(choices){
            case 393:
                loop++;
                system("cls");
                OP393();
                break;
            case 291:
                loop++;
                system("cls");
                OP291();
                break;
            case 0:
                inventory();
                enter();
                OP241();
                break;
        }
    }
}

//OPCAO 242
void OP242(){
    loop = 0;

    printf("\t242 - Voc� sacode a cabe�a, tentando desesperadamente manter a consci�ncia, mas o calor � intenso demais, e voc� perde os sentidos. \033[1;33mDigite \"ROLL\" e teste sua HABILIDADE.\033[0;37m\n\n");

    while(loop < 1){
        gets(startroll);
        if(strcasecmp(startroll, "roll") == 0){
            dice2();
            if(numroll <= hability){
                system("cls");
                OP048();
            }else{
                system("cls");
                OP366();
            }
        }
    }

}

//OPCAO 243
void OP243(){
    printf("\t243 - Cobrindo o nariz e a boca com a m�o, a fim de evitar inalar o g�s, voc� segue o Gnomo pela porta aberta. Voc� entra em outro t�nel, ao fim do qual aparece a vis�o bem vinda da luz do dia. Para sua grande surpresa, o Gnomo est� morto no meio do caminho com um dardo de besta cravado na cabe�a. Na �nsia por liberdade, o Gnomo ca�ra v�tima da �ltima armadilha do Bar�o Sukumvit. \033[1;33mVoc� passa pelo infeliz e sai na luz brilhante do sol.\033[0;37m");
    enter();
    OP400();
}

//OPCAO 244
void OP244(){
    printf("\t244 - Ele pega sua Pe�a de Ouro e lhe diz que, em um t�nel setentrional, h� uma cadeira de madeira esculpida na forma de um p�ssaro demon�aco. No bra�o da cadeira, um painel secreto cont�m uma po��o em um frasco de vidro. \033[1;35m\"� uma Po��o de R�plica, se eu bem me lembro. Boa sorte. Espero que nos encontremos de novo fora destes t�neis infernais.\"\033[0;37m O homem sai arrastando os p�s, e voc� continua sua jornada.\n\n");

    if(status_OP244 == 0){
        gold -= 1;
        morph_potion += 1;
        status_OP244 += 1;
        printf("Voc� perdeu 1 de GOLD");
        printf("\nSeu GOLD: %d", gold);
        printf("Po��o de R�plica foi adicionada ao seu invent�rio");
        enter();
        OP109();
    }else{
        printf("\033[1;31mVoc� j� esteve aqui, nada foi adicionado ao seu invent�rio.\033[0;37m\n\n");
        enter();
        OP109();
    }
}

//OPCAO 245
void OP245(){
    loop = 0;
    monsenergy = 15;
    monshability = 12;

    printf("\t245 - Voc� n�o tem outra alternativa sen�o abrir a porta, j� que o muro � liso demais para ser escalado. Respirando fundo, voc� gira a ma�aneta e entra em um po�o coberto de areia. Ali, um monstro enorme com apar�ncia de dinossauro, chegando a uns 10 metros de altura, est� de p� nas imensas patas traseiras, diante de grandes portas duplas na parede do outro lado. Possui um couro grosso verde malhado e uma boca com filas de dentes afiados como navalhas. As mand�bulas da criatura se abrem e fecham com for�a capaz de pulverizar ossos. E mesmo voc� n�o consegue evitar o tremor ao se aproximar do Diabo do Po�o com a espada na m�o.\n\n\033[1;31mDIABO DO PO�O HABILIDADE 12 ENERGIA 15.\033[0;37m");

    enter();
    combat1();
    printf("\n\033[1;33mVOC� DERROTOU O DIABO DO PO�O\033[0;37m");
    printf("\nSua ENERGIA: %i", energy);
    enter();
    OP258();
}

//OPCAO 246
void OP246(){
    loop = 0;
    printf("\t246 - Apesar de toda a cautela, sua perna raspa em um dos postes, que imediatamente solta uma chuva de farpas afiadas, cada uma com v�rios cent�metros de comprimento. Voc� perde 2 pontos de SORTE. Elas voam em todas as dire��es com grande velocidade, e voc� n�o consegue evit�-las. \033[1;33mDigite \"ROLL\" e role 2 dados para determinar o n�mero de farpas que se cravam na sua carne.\033[0;37m \033[1;31mCada farpa reduz sua ENERGIA em 1 ponto.\033[0;37m\n\n");

    luck -= 2;
    printf("Voc� perdeu 2 de SORTE\n");
    printf("Sua SORTE: %i\n\n", luck);

    while(loop < 1){
        gets(startroll);
        if(strcasecmp(startroll, "roll") == 0){
            dice2();
            energy -= numroll;
            printf("\nVOC� RECEBEU %i DE DANO", numroll);
            if(energy > 0){
                loop++;
                printf("\n\nvoc� senta para a dolorosa tarefa de retirar as farpas do corpo antes de partir para o leste.");
                enter();
                OP313();
            }else if(energy <= 0)
                death();
        }
    }
}

//OPCAO 247
void OP247(){
    loop = 0;

    printf("\t247 - A fera diante de voc� � o tem�vel MANT�CORA. A ponta da cauda da criatura guarda uma profus�o de espinhos pontudos, grossos e duros como dardos de ferro. Subitamente, ele sacode a cauda, lan�ando uma saraivada de espinhos na sua dire��o.  Se voc� ainda estiver vivo, avan�a com dificuldade para atacar o Mant�cora com sua espada, antes que ele tenha tempo de disparar mais espinhos.\n\n\033[1;31mMANT�CORA HABILIDADE 11 ENERGIA 11\033[0;37m\n\n");

    dice1();
    dards = numroll * 2;
    energy -= dards;
    printf("Voc� perdeu %d de ENERGIA\n\n", dards);
    if(energy <= 0){
        death();
    }else
    printf("\nVoc� sobreviveu a rajada de espinhos!");
    enter();
    combat1();
    printf("\nVOC� DERRROTOU A MANT�CORA!");
    printf("\nSua ENERGIA: %i", energy);
    enter();
    OP364();
}

//OPCAO 248
void OP248(){
    printf("\t248 - As portas abrem para um t�nel que segue para o norte. Voc� fecha as portas atr�s de si e parte mais uma vez.");

    enter();
    OP214();
}

//OPCAO 249
void OP249(){
    stageops = 249;
    save();
    loop = 0;

    printf("\t249 - Voc� s� tem tempo de ouvir o Gnomo dizer: \"Uma coroa e dois cr�nios\", antes que um raio branco de energia parta da fechadura e atinja-lhe o peito, derrubando-o sem sentidos. \033[1;33mDigite \"ROLL\", \033[1;31mo resultado somado 1 � reduzido de sua ENERGIA.\033[0;37m");

    while(loop < 1){
        gets(startroll);
        if(strcasecmp(startroll, "roll") == 0){
            dice1();
            if(numroll > 0){
                energy = energy - (numroll + 1);
                printf("Sua ENERGIA: %i", energy);
            }
            if(energy > 0){
                printf("\n\nVoc� recupera a consci�ncia e o Gnomo manda que tente de novo. Voc� sabe que colocou uma gema na ranhura certa, mas qual? Voc� suspira e tenta uma nova combina��o.\n\n    A         B         C     \nEsmeralda|Diamante |Safira    -> \033[1;35mDigite 16.\033[0;37m\nDiamante |Safira   |Esmeralda -> \033[1;35mDigite 392.\033[0;37m\nSafira   |Esmeralda|Diamante  -> \033[1;35mDigite 177.\033[0;37m\nEsmeralda|Safira   |Diamante  -> \033[1;35mDigite 287.\033[0;37m\nDiamante |Esmeralda|Safira    -> \033[1;35mDigite 132.\033[0;37m\nSafira   |Diamante |Esmeralda -> \033[1;35mDigite 249.\033[0;37m\n\n");

                printf("\033[1;34mLEMBRE-SE, VOC� PODE ACESSAR SEU INVENT�RIO DIGITANDO 0\033[0;37m\n\n");

                scanf("%i", &choices);
                switch(choices){
                    case 16:
                        loop++;
                        system("cls");
                        OP016();
                        break;
                    case 392:
                        loop++;
                        system("cls");
                        OP392();
                        break;
                    case 177:
                        loop++;
                        system("cls");
                        OP177();
                        break;
                    case 287:
                        loop++;
                        system("cls");
                        OP287();
                        break;
                    case 132:
                        loop++;
                        system("cls");
                        OP132();
                        break;
                    case 249:
                        loop++;
                        system("cls");
                        OP249();
                        break;
                    case 0:
                        inventory();
                        enter();
                        OP132();
                        break;
                }
            }else{
                death();
            }
        }
    }
}

//OPCAO 250
void OP250(){
    stageops = 250;
    save();
    loop = 0;

    printf("\t250 - Quando voc� corre para a porta, o velho grita atr�s de voc�: \"N�o corra, ningu�m escapa de mim. Pare, ou eu o transformarei em pedra neste instante!\" Voc�: \n\nContinua correndo? \033[1;35mDigite 44.\033[0;37m\nVira-se para atac�-lo com a espada? \033[1;35mDigite 195.\033[0;37m\nDiz a ele que responder� � pergunta? \033[1;35mDigite 382.\033[0;37m\n\n");

    printf("\033[1;34mLEMBRE-SE, VOC� PODE ACESSAR SEU INVENT�RIO DIGITANDO 0\033[0;37m\n\n");

    while(loop < 1){
        scanf("%i", &choices);
        switch(choices){
            case 44:
                loop++;
                system("cls");
                OP044();
                break;
            case 195:
                loop++;
                system("cls");
                OP195();
                break;
            case 382:
                loop++;
                system("cls");
                OP382();
                break;
            case 0:
                inventory();
                enter();
                OP250();
                break;
        }
    }
}

//OPCAO 251
void OP251(){
    printf("\t251 - Mais uma vez, ouve-se a voz misteriosa, s� que agora, para sua grande surpresa, num tom bem menos amea�ador: \"Bom, meu senhor gosta daqueles que demonstram ter esp�rito. Tome este presente para ajud�-lo. Isto lhe conceder� um desejo, mas somente um desejo. Adeus.\" Um anel de ouro, magicamente sa�do do nada, cai a seus p�s com um tinido suave. Voc� o p�e num dedo. A porta se abre e voc� entra de novo no t�nel, rumo ao norte.\n\n");

    if(status_OP251 <= 0){
        status_OP251 += 1;
        printf("\033[1;34mAnel dos Desejos foi adicionado a seu invent�rio\033[0;37m");
        wish_ring += 1;
        enter();
        OP344();
    }else{
        printf("\033[1;31mVoc� j� esteve aqui, nada foi adicionado ao seu invent�rio.\033[0;37m\n\n");
        enter();
        OP344();
    }
}

//OPCAO 252
void OP252(){
    printf("\t252 - O t�nel continua para o norte por uma boa dist�ncia antes de chegar a um beco sem sa�da. A entrada de um escorrega � vis�vel na parede do oeste, e essa parece ser a �nica alternativa, al�m da op��o de retornar. Voc� resolve arriscar e sobe no escorrega. Desliza suavemente e aterrissa sobre as costas em um aposento.");

    enter();
    OP090();
}

//OPCAO 253
void OP253(){
    printf("\t253 - Voc� tira o osso da mochila e o atira escada abaixo. Os latidos ficam mais altos, transformando-se em rosnados e ranger de dentes quando o osso cai no ch�o. Lentamente, voc� desce os degraus com a espada na m�o, e v� os dois enormes C�ES DE GUARDA disputando o osso. Voc� passa correndo por eles e segue em frente pelo t�nel.");

    enter();
    OP315();
}

//OPCAO 254
void OP254(){
    printf("\t254 - Voc� desembainha a espada e avan�a lentamente na dire��o do imenso e viscoso Verme da Rocha.\n\nVERME DA ROCHA HABILIDADE 7 ENERGIA 11\n\nVoc� poder� fugir depois de duas S�ries de Ataque, correndo para o oeste pelo t�nel.\n\n");

    monshability = 7;
    monsenergy = 11;

    printf("COME�OU O COMBATE!");
    combatloop = 0;
    atkseries = 0;
    while(combatloop < 1){
        loop = 0;
        printf("\nRode os dados:\n");
        printf("\033[0;31m");
        printf("DIGITE ROLL\n");
        printf("\033[0;37m");
        gets(combatroll);
        if(strcasecmp(combatroll, "roll") == 0){
            dice2();
            playerhabil = numroll + hability;
            printf("\n\nSUA FOR�A DE ATAQUE: %d\n\n", playerhabil);

            dice2();
            damagemonster = numroll + monshability;
            printf("\n\nFOR�A DE ATAQUE DO MONSTRO: %d\n", damagemonster);
        }
        if(strcasecmp(combatroll, "roll") == 0 && playerhabil > damagemonster){
            printf("\nVOC� CAUSOU DANO\n");
            monsenergy -= 2;
            atkseries = atkseries + 1;
            printf("\nVoc� deseja testar sua SORTE? (digite \"sim\" ou \"nao\")\n");
            while(loop < 1){
                gets(luckhit);
                if(strcasecmp(luckhit, "sim") == 0){
                    dice2();
                    if(numroll <= luck){
                        luck--;
                        printf("\n\nSua SORTE: %d", luck);
                        monsenergy -= 2;
                        loop++;
                    }
                    else{
                        luck--;
                        printf("\n\nSua SORTE: %d", luck);
                        monsenergy += 1;
                        loop++;
                    }
                    printf("\n\n");
                }
                else if(strcasecmp(luckhit, "nao") == 0){
                    loop++;
                }
            printf("HP MONSTRO: %d", monsenergy);
            }
            if(atkseries >= 2){
                loop++;
                printf("\n\n\033[1;34mA PARTIR DE AGORA VOC� PODE TENTAR FUGIR!\n\033[0;31mDIGITE FLEE\033[1;34m INV�S DE ROLL PARA FUGIR!\033[0;37m");
            }
            enter();
        }
        else if(strcasecmp(combatroll, "roll") == 0 && playerhabil < damagemonster){
            printf("\nVOCE LEVOU DANO\n");
            printf("\nVoc� deseja testar sua SORTE? (digite \"sim\" ou \"nao\")\n");
            while(loop < 1){
                gets(luckhit);
                if(strcasecmp(luckhit, "sim") == 0){
                    dice2();
                    if(numroll <= luck){
                        luck--;
                        printf("\n\nSua SORTE: %d", luck);
                        energy += 1;
                        loop++;
                    }
                    else{
                        luck--;
                        printf("\n\nSua SORTE: %d", luck);
                        energy -= 1;
                        loop++;
                    }
                    printf("\n\n");
                }
                else if(strcasecmp(luckhit, "nao") == 0){
                    loop++;
                }
            }
            energy -= 2;
            printf("SEU HP: %d", energy);
            enter();
        }
        else if(strcasecmp(combatroll, "roll") == 0 && playerhabil == damagemonster){
            printf("\nAMBOS CONSEGUIRAM SE DEFENDER E NINGU�M SE MACHUCOU");
            enter();
        }
        else if(strcasecmp(combatroll, "flee") == 0 && atkseries == 2){
            combatloop += 1;
            printf("\nAssim que voc� acerta seu segundo golpe na criatura, durante um momento de distra��o do Verme, voc� corre para o oeste como qualquer covarde faria.");
            enter();
            OP117();
        }
        if(energy <= 0){
            death();
        }
        else if (monsenergy <= 0){
            combatloop += 1;
            printf("VOCE GANHOU O COMBATE");
            enter();
        }
        system("cls");
    }
}

//OPCAO 255
void OP255(){
    printf("\t255 - Quando corre contornando o caminho estreito, voc� se sente tonto. O g�s da po�a est� fazendo efeito: sua vis�o come�a a ficar emba�ada, e voc� perde o equil�brio. Voc� s� tem uma vaga consci�ncia da l�ngua da Besta Sangrenta, enquanto ela se enrosca na sua perna e o arrasta para a po�a de lodo. \033[1;31mDepois de decomposto no lodo abjeto, seu corpo ser� saboreado pela ign�bil Besta Sangrenta.\033[0;37m");
    death();
}

//OPCAO 256
void OP256(){
    loop = 0;

    printf("\t256 - Lembrando do conselho do velho, voc� examina o bra�o da cadeira em busca de um painel secreto. Descobrindo uma fenda quase impercept�vel, voc� a for�a e, s�bito, um pequeno painel salta do bra�o. Ao perceber um pequeno frasco de vidro numa cavidade, voc� o apanha e l� o r�tulo: \033[1;34m\"Po��o de R�plica - uma dose apenas. Este l�quido far� com que voc� assuma a forma de qualquer ser vivo que lhe esteja pr�ximo.\"\033[0;37m Voc� p�e a estranha po��o na mochila e continua para o norte.");

    if(status_OP256 == 0){
        morph_potion += 1;
        status_OP256 += 1;
        printf("\033[1;34mA Po��o de R�plica foi adicionada a seu invent�rio\033[0;37m");
        enter();
        OP188();
    }else{
        printf("\033[1;31mVoc� j� esteve aqui, nada foi adicionado ao seu invent�rio.\033[0;37m\n\n");
        enter();
        OP188();
    }
}

//OPCAO 257
void OP257(){
    printf("\t257 - Dentro dos bolsos de um dos Orcas, voc� acha uma Pe�a de Ouro e um tubo oco de madeira. Voc� guarda na mochila o que encontrou e parte para o oeste.\n\n");

    if(status_OP257 >= 0 && status_OP257 <= 3){
        wood_tube += 1;
        gold += 1;
        status_OP257 += 1;
        printf("\033[1;34mUm tubo oco de madeira foi adicionado a seu invent�rio\033[0;37m\n");
        printf("\033[1;33m1 de GOLD foi adicionado seu invent�rio\n");
        printf("Seu GOLD: %d\033[0;37m", gold);
        enter();
        OP164();
    }else{
        printf("\033[1;31mVoc� j� esteve aqui, nada foi adicionado ao seu invent�rio.\033[0;37m\n\n");
        enter();
        OP164();
    }
}

//OPCAO 258
void OP258(){
    stageops = 258;
    save();
    loop = 0;

    printf("\t258 - Voc� est� exausto e se senta para um descanso na cauda da fera morta. Olhando para baixo, a seus p�s, voc� de repente nota um anel de ferro que se destaca na areia. Se voc� quiser puxar o anel, \033[1;35mdigite 95.\033[0;37m\nSe preferir sair do po�o pelas portas duplas, \033[1;35mdigite 248.\033[0;37m\n\n");

    printf("\033[1;34mLEMBRE-SE, VOC� PODE ACESSAR SEU INVENT�RIO DIGITANDO 0\033[0;37m\n\n");

    while(loop < 1){
        scanf("%i", &choices);
        switch(choices){
            case 95:
                loop++;
                system("cls");
                OP095();
                break;
            case 248:
                loop++;
                system("cls");
                OP248();
                break;
            case 0:
                inventory();
                enter();
                OP258();
                break;
        }
    }

}

//OPCAO 259
void OP259(){
    stageops = 259;
    save();
    loop = 0;

    printf("\t259 - Ignorando a dor, voc�, continua a correr. � sua frente, v� um rio subterr�neo que corre de leste para oeste atravessando a caverna, com uma ponte de madeira que liga uma margem a outra. Voc� olha para tr�s e v� os Trogloditas no seu encal�o. Se voc� quiser correr pela ponte, \033[1;35mdigite 318.\033[0;37m\nSe desejar mergulhar no rio, \033[1;35mdigite 47.\033[0;37m");

    printf("\033[1;34mLEMBRE-SE, VOC� PODE ACESSAR SEU INVENT�RIO DIGITANDO 0\033[0;37m\n\n");

    while(loop < 1){
        scanf("%i", &choices);
        switch(choices){
            case 47:
                loop++;
                system("cls");
                OP047();
                break;
            case 318:
                loop++;
                system("cls");
                OP318();
                break;
            case 0:
                inventory();
                enter();
                OP259();
                break;
        }
    }

}

//OPCAO 260
void OP260(){
    stageops = 260;
    save();
    loop = 0;

    printf("\t260 - Voc� mal consegue se agarrar � orelha do �dolo e recuperar um ponto de apoio para os p�s. Voc� se desloca pelo rosto da est�tua. Sentado no nariz do �dolo, voc� desembainha a espada e considera qual dos olhos dele arrancar� primeiro para levar a j�ia.\n\nSe quiser arrancar primeiro o olho esquerdo, \033[1;35mdigite 166.\033[0;37m\nSe preferir arrancar o olho direito, \033[1;35mdigite 140.\033[0;37m\n\n");

    printf("\033[1;34mLEMBRE-SE, VOC� PODE ACESSAR SEU INVENT�RIO DIGITANDO 0\033[0;37m\n\n");

    while(loop < 1){
        scanf("%i", &choices);
        switch(choices){
            case 166:
                loop++;
                system("cls");
                OP166();
                break;
            case 140:
                loop++;
                system("cls");
                OP140();
                break;
            case 0:
                inventory();
                enter();
                OP260();
                break;
        }
    }

}

//OPCAO 261
void OP261(){
    printf("\t261 - Apesar de todos os esfor�os, voc� n�o consegue tirar o La�o do pesco�o do �dolo. Finalmente, voc� desiste e o abandona para quem quer que venha depois de voc�. N�o h� nada mais de interesse na caverna, portanto voc� caminha at� a parede norte e entra no t�nel.");
    enter();
    OP239();
}

//OPCAO 262
void OP262(){
    stageops = 262;
    save();
    loop = 0;

    printf("\t262 - A porta abre para um outro t�nel que segue para o norte. Voc� topa com duas fontes de pedra, uma de cada lado do t�nel, esculpidas na forma de querubins, de cujas bocas a �gua jorra e desce em cascata para pequenas conchas nos p�s. Voc�: Beber� �gua na fonte da esquerda? \033[1;35mDigite 337.\033[0;37m\nBeber� �gua na fonte da direita? \033[1;35mDigite 173.\033[0;37m\nContinuar� caminhando para o norte? \033[1;35mDigite 368.\033[0;37m\n\n");

    printf("\033[1;34mLEMBRE-SE, VOC� PODE ACESSAR SEU INVENT�RIO DIGITANDO 0\033[0;37m\n\n");

    while(loop < 1){
        scanf("%i", &choices);
        switch(choices){
            case 337:
                loop++;
                system("cls");
                OP337();
                break;
            case 173:
                loop++;
                system("cls");
                OP173();
                break;
            case 368:
                loop++;
                system("cls");
                OP368();
                break;
            case 0:
                inventory();
                enter();
                OP262();
                break;
        }
    }
}

//OPCAO 263
void OP263(){
    stageops = 263;
    save();
    loop = 0;

    printf("\t263 - A porta abre para um outro t�nel. Caminhando para o oeste, voc� logo chega a uma porta na parede norte. Se quiser abrir a porta, \033[1;35mdigite 153.\033[0;37m\nSe preferir continuar para o oeste, \033[1;35mdigite 74.\033[0;37m\n\n");

    printf("\033[1;34mLEMBRE-SE, VOC� PODE ACESSAR SEU INVENT�RIO DIGITANDO 0\033[0;37m\n\n");

    while(loop < 1){
        scanf("%i", &choices);
        switch(choices){
            case 153:
                loop++;
                system("cls");
                OP153();
                break;
            case 74:
                loop++;
                system("cls");
                OP074();
                break;
            case 0:
                inventory();
                enter();
                OP263();
                break;
        }
    }

}

//OPCAO 264
void OP264(){
    stageops = 264;
    save();
    loop = 0;

    printf("\t264 - Adiante, na penumbra, voc� v� dois HOBGOBLINS se engalfinhando. H� uma bolsa de couro jogada no ch�o, e parece ser ela a raz�o da luta. Voc�:\n\nTentar� conversar com eles? \033[1;35mDigite 130.\033[0;37m\nVai atac�-los com sua espada? \033[1;35mDigite 51.\033[0;37m\nTentar� passar sem ser percebido? \033[1;35mDigite 355.\033[0;37m\n\n");

    printf("\033[1;34mLEMBRE-SE, VOC� PODE ACESSAR SEU INVENT�RIO DIGITANDO 0\033[0;37m\n\n");

    while(loop < 1){
        scanf("%i", &choices);
        switch(choices){
            case 130:
                loop++;
                system("cls");
                OP130();
                break;
            case 51:
                loop++;
                system("cls");
                OP051();
                break;
            case 355:
                loop++;
                system("cls");
                OP355();
                break;
            case 0:
                inventory();
                enter();
                OP264();
                break;
        }
    }
}

//OPCAO 265
void OP265(){
    printf("\t265 - Voc� esfrega seu anel m�gico e deseja que o Dem�nio do Espelho seja transportado de volta ao pr�prio mundo e nunca mais retome. Ainda avan�ando na sua dire��o, o ser come�a a se esvair e desaparece aos poucos. Por fim, ele some completamente, e voc� pode continuar sua jornada para o norte.");
    // Volte para 188.
    enter();
    OP188();
}

//OPCAO 266
void OP266(){
    loop = 0;

    printf("\t266 - Voc� revista os arm�rios e caixas no quarto de Erva, mas n�o encontra nada, exceto um osso velho, que pode levar com voc�, se quiser. Saindo da c�mara pela porta do leste, voc� agora se encontra de p� no final de um outro t�nel.");

    enter();
    OP305();
}

//OPCAO 267
void OP267(){
    stageops = 267;
    save();
    loop = 0;

    printf("\t267 - O t�nel logo termina em uma encruzilhada. Olhando para a esquerda e para a direita, voc� v� uma passagem estreita que desaparece na penumbra da dist�ncia.\n\nSe voc� quiser se dirigir para o oeste, \033[1;35mdigite 352.\033[0;37m\nSe preferir seguir para o leste, \033[1;35mdigite 68.\033[0;37m\n\n");

    printf("\033[1;34mLEMBRE-SE, VOC� PODE ACESSAR SEU INVENT�RIO DIGITANDO 0\033[0;37m\n\n");

    while(loop < 1){
        scanf("%i", &choices);
        switch(choices){
            case 352:
                loop++;
                system("cls");
                OP352();
                break;
            case 68:
                loop++;
                system("cls");
                OP068();
                break;
            case 0:
                inventory();
                enter();
                OP267();
                break;
        }
    }
}

//OPCAO 268
void OP268(){
    loop = 0;

    printf("\t268 - Voc� salta para adiante e tenta agarrar o l�der para us�-lo como ref�m. Contudo, os Trogloditas estavam prevenidos para sua tentativa, e seis dos arqueiros deles imediatamente disparam flechas em voc�. A pontaria deles � mortalmente precisa, e as seis flechas atingem o alvo. Voc� tomba sem vida. \033[1;31mOs Trogloditas encerraram abruptamente sua jornada.\033[0;37m");
    death();
}

//OPCAO 269
void OP269(){
    stageops = 269;
    save();
    loop = 0;

    printf("\t269 - Voc� esvazia o conte�do do vidro na m�o e o aplica �s suas feridas. Os efeitos curativos s�o imediatos, e voc� se sente mais forte a cada momento. Acrescente 3 pontos de ENERGIA. Voc� poder� comer o arroz e beber a �gua, \033[1;35mdigite 330.\033[0;37m Ou sair do sal�o, levando apenas o diamante com voc�, \033[1;35mdigite 127\033[0;37m.");

    if(status_OP269 == 0){
        energy += 3;
        status_OP269 += 1;
        while(loop < 1){
            scanf("%i", &choices);
            switch(choices){
                case 330:
                    loop++;
                    system("cls");
                    OP330();
                    break;
                case 127:
                    loop++;
                    system("cls");
                    OP127();
                    break;
                case 0:
                    inventory();
                    enter();
                    OP269();
                    break;
            }
        }
    }else{
        printf("\033[1;31mVoc� j� esteve aqui, nada foi adicionado ao seu invent�rio.\033[0;37m\n\n");
        while(loop < 1){
            scanf("%i", &choices);
            switch(choices){
                case 330:
                    loop++;
                    system("cls");
                    OP330();
                    break;
                case 127:
                    loop++;
                    system("cls");
                    OP127();
                    break;
                case 0:
                    inventory();
                    enter();
                    OP269();
                    break;
            }
        }
    }
}

//OPCAO 270
void OP270(){
    loop = 0;

    printf("\t270 - A tampa da caixa sai facilmente. Dentro, voc� acha duas Pe�as de Ouro e um bilhete, escrito num pequeno peda�o de pergaminho, endere�ado a voc�. Depois de colocar o ouro no bolso, voc� l� a mensagem: Muito bem. Pelo menos voc� tem o bom senso de parar e tirar proveito da ajuda simb�lica que lhe � dada. Agora, posso avis�-lo da necessidade de encontrar e usar diversos itens, se espera sair-se bem no meu Calabou�o da Morte. Assinado \"Sukumvit.\" Guardando de cor o aviso do bilhete, voc� o rasga em pequenos peda�os e continua para o norte pelo t�nel.\n\n");

    if(status_OP270 == 0){
        gold += 2;
        status_OP270 += 1;
        printf("\033[1;33mFoi adicionado dois de GOLD ao seu invent�rio");
        printf("\nSeu GOLD: %d\033[0;37m", gold);
        enter();
        OP066();
    }else{
        printf("\033[1;31mVoc� j� esteve aqui, nada foi adicionado ao seu invent�rio.\033[0;37m\n\n");
        enter();
        OP066();
    }
}

//OPCAO 271
void OP271(){
    loop = 0;

    printf("\t271 - Quando voc� est� prestes a soltar o escudo e atir�-lo por cima do po�o, ele escorrega de seus dedos e rola pelo ch�o. Voc� n�o consegue apanh�-lo antes que ele ultrapasse a borda, caindo ruidosamente, de lado, no fundo. A perda do escudo reduz-lhe a capacidade, \033[1;31mvoc� perde 1 ponto de HABILIDADE\033[0;37m. Amaldi�oando sua pr�pria falta de jeito, voc� d� um passo � frente, salta por sobre o po�o e cai em seguran�a do outro lado. Voc� n�o perde tempo e se dirige para o leste.");
    // Digite 237.
    hability -= 1;
    printf("Voc� perdeu um ponto de HABILIDADE");
    printf("\nSua HABILIDADE: %i", hability);
    enter();
    OP237();
}

//OPCAO 272
void OP272(){
    loop = 0;

    printf("\t272 - Embora a Besta Sangrenta seja pesada e estufada demais para sair da po�a, a l�ngua da fera se estica e se enrosca na sua perna. Ainda inconsciente, voc� � arrastado para a po�a de lodo. \033[1;31mDepois de decomposto pela a��o do lodo abjeto, seu corpo ser� saboreado pela repugnante Besta Sangrenta.\033[0;37m");
    death();
}

//OPCAO 273
void OP273(){
    stageops = 273;
    save();
    loop = 0;

    printf("\t273 - A bola de madeira se choca contra o cr�nio, derrubando-o do pedestal. Para sua surpresa, as bestas n�o disparam os dardos mortais. Voc� entra no aposento com cautela e apanha o cr�nio do ch�o. Reconhece as j�ias amarelas dos olhos como sendo top�zios, e rapidamente os arranca das �rbitas. Voc� os coloca na mochila, imaginando se ainda h� uma cilada � sua espera no aposento. Voc�: Ficar� de quatro e sair� engatinhando do aposento, segurando o cr�nio? \033[1;35mDigite 15.\033[0;37m\nRecolocar� o cr�nio no pedestal antes de sair do aposento? \033[1;35mDigite 204.\033[0;37m\n\n");

    printf("\033[1;34mLEMBRE-SE, VOC� PODE ACESSAR SEU INVENT�RIO DIGITANDO 0\033[0;37m\n\n");

    while(loop < 1){
        scanf("%i", &choices);
        switch(choices){
            case 15:
                loop++;
                system("cls");
                OP015();
                break;
            case 204:
                loop++;
                system("cls");
                OP204();
                break;
            case 0:
                inventory();
                enter();
                OP273();
                break;
        }
    }
}

//OPCAO 274
void OP274(){
    loop = 0;

    printf("\t274 - Voc� pisa nervosamente na corda, sem se atrever a olhar para baixo. Na metade da travessia, voc� come�a a entrar em p�nico e perde o equil�brio. \033[1;33mDIGITE \"ROLL\" e teste sua HABILIDADE\033[0;37m.\n\n");

    while(loop < 1){
        gets(startroll);
        if(strcasecmp(startroll, "roll") == 0){
            dice2();
            if(numroll <= hability){
                system("cls");
                OP238();
            }else{
                system("cls");
                OP359();
            }
        }
    }
}

//OPCAO 275
void OP275(){
    loop = 0;

    printf("\t275 - Uma fuma�a espessa sobe do ch�o no lugar onde o �cido caiu da moringa quebrada. Voc� se arrasta desesperadamente, tentando encontrar �gua pot�vel nas po�as rasas do t�nel gotejante. \033[1;33mDIGITE \"ROLL\" e teste sua SORTE.\033[0;37m\n\n");

    while(loop < 1){
        gets(startroll);
        if(strcasecmp(startroll, "roll") == 0){
            dice2();
            if(numroll <= luck){
                luck--;
                system("cls");
                OP231();
            }else{
                luck--;
                system("cls");
                OP309();
            }
        }
    }

}

//OPCAO 276
void OP276(){
    loop = 0;

    printf("\t276 - Ao tentar arrombar a porta com uma pancada de ombro, voc� ouve as vozes esgani�adas dos Trogloditas que v�m descendo o t�nel. Voc� est� encurralado e desembainha a espada. Os Trogloditas se aproximam, os arcos prontos, e uma saraivada de flechas o atinge com impacto fatal. \033[1;31mSeu corpo desaba sem vida nas profundezas do Calabou�o da Morte.\033[0;37m");
    death();
}

//OPCAO 277
void OP277(){
    printf("\t277 - O t�nel faz uma curva fechada para a direita e depois, uns 100 metros adiante, chega a um cruzamento. Olhando para a esquerda, voc� v� dois corpos ca�dos no ch�o. Resolve chegar perto e investigar.");

    enter();
    OP338();
}

//OPCAO 278
void OP278(){
    printf("\t278 - Sua l�mina atinge um dos olhos verdadeiros da Besta Sangrenta. O efeito � devastador. Ela desaba na po�a, debatendo-se freneticamente. Voc� aproveita a oportunidade e corre, contornando a po�a, rumo � sa�da para o t�nel.");

    enter();
    OP134();
}

//OPCAO 279
void OP279(){
    printf("\t279 - Voc� chega a um cruzamento no t�nel. Uma nova ramifica��o leva para o oeste, mas as pegadas molhadas que voc� vem seguindo continuam para o norte. Voc� decide continuar seguindo as pegadas.");

    enter();
    OP032();
}

//OPCAO 280
void OP280(){
    printf("\t280 - O t�nel continua para o leste por uma boa dist�ncia antes de chegar a um cruzamento. As paredes, o teto e o ch�o do t�nel que leva para o sul est�o cobertos por um limo verde e espesso. Voc� considera que � mais seguro dirigir-se para o norte.");

    enter();
    OP280();
}

//OPCAO 281
void OP281(){
    stageops = 281;
    save();
    loop = 0;

    printf("\t281 - Com um golpe da sua espada de f�, voc� corta a cabe�a da Jib�ia. Voc� desenrola o corpo gigantesco, libertando a Mulher-elfo, e tenta ressuscit�-la. Os olhos dela se abrem um pouco, mas n�o h� esperan�a. Ela olha para voc� e sorri, depois murmura:\"Obrigada. Sei que � tarde demais para mim, mas lhe direi o que j� pude aprender. A sa�da est� adiante, mas voc� precisa de gemas para destrancar a �ltima porta. Uma delas � um diamante, mas n�o sei quais s�o as outras. Pena, n�o encontrei um diamante, mas aconselho-o a procurar um. Boa sorte.\" Os olhos dela se fecham, e ela tomba no ch�o frio. Voc� a olha entristecido enquanto ela solta o �ltimo suspiro. Sabendo que ela n�o se importaria, retira-lhe os dois punhais e examina a mochila de couro que trazia. Dentro, voc� acha um peda�o de p�o �zimo, um espelho e um amuleto de osso com a forma de um macaco. Se voc� quiser comer o p�o, \033[1;35mdigite 399.\033[0;37m\nSe preferir pegar apenas o espelho e o amuleto e retornar ao t�nel para dirigir-se ao norte, \033[1;35mdigite 192.\033[0;37m\n\n");

    printf("\033[1;34mLEMBRE-SE, VOC� PODE ACESSAR SEU INVENT�RIO DIGITANDO 0\033[0;37m\n\n");

    while(loop < 1){
        scanf("%i", &choices);
        switch(choices){
            case 399:
                loop++;
                system("cls");
                OP399();
                break;
            case 192:
                loop++;
                system("cls");
                OP192();
                break;
            case 0:
                inventory();
                enter();
                OP281();
                break;
        }
    }

}

//OPCAO 282
void OP282(){
    stageops = 282;
    save();
    loop = 0;

    printf("\t282 - O t�nel logo termina em uma encruzilhada. Parado l� sozinho e sem saber para que lado ir est� um de seus rivais. � um dos B�rbaros. Voc� o chama, mas ele n�o responde; apenas olha fria e fixamente para voc�, segurando a acha com firmeza. Voc� anda at� ele e pergunta para que lado est� indo. Ele grunhe sua resposta, dizendo que est� indo para o oeste, e, se quiser, voc� pode ir com ele. Se voc� quiser seguir para o oeste com o B�rbaro, \033[1;35mdigite 22.\033[0;37m\nSe preferir recusar a oferta e seguir para o leste sozinho, \033[1;35mdigite 388.\033[0;37m\n\n");

    printf("\033[1;34mLEMBRE-SE, VOC� PODE ACESSAR SEU INVENT�RIO DIGITANDO 0\033[0;37m\n\n");

    while(loop < 1){
        scanf("%i", &choices);
        switch(choices){
            case 22:
                loop++;
                system("cls");
                OP022();
                break;
            case 388:
                loop++;
                system("cls");
                OP388();
                break;
            case 0:
                inventory();
                enter();
                OP282();
                break;
        }
    }
}

//OPCAO 283
void OP283(){
    printf("\t283 - Voc� precisa se espremer e entrar fundo na fenda para se esconder completamente. Dessa posi��o desajeitada, voc� n�o consegue ver o dono dos p�s que se arrastam, passando lentamente. Um minuto depois, tudo est� quieto de novo, por isso voc� se esgueira de volta para o t�nel e prossegue para o oeste.");

    enter();
    OP109();
}

//OPCAO 284
void OP284(){
    stageops = 284;
    save();
    loop = 0;

    printf("\t284 - Voc� bebeu uma po��o encontrada em um livro de couro preto? Se voc� tiver bebido, \033[1;35mdigite 398.\033[0;37m Se n�o, \033[1;35mdigite 57.\033[0;37m\n\n");

    while(loop < 1){
        scanf("%i", &choices);
        switch(choices){
            case 57:
                loop++;
                system("cls");
                OP057();
                break;
            case 398:
                loop++;
                if(skill_trap_potion != 0){
                    system("cls");
                    OP398();
                } else{
                    printf("Voc� n�o leu este item.");
                    enter();
                    OP284();
                }
                break;
            case 0:
                inventory();
                enter();
                OP284();
                break;
        }
    }
}

//OPCAO 285
void OP285(){
    stageops = 285;
    save();
    loop = 0;

    printf("\t285 - Voc� cai pesadamente de costas, mas, felizmente, sua mochila suaviza o impacto.\033[1;31m Voc� perde 1 ponto de HABILIDADE e 2 pontos de ENERGIA\033[0;37m. A escurid�o � quase total no fundo do po�o, e voc� se arrasta, tateando. Repentinamente, sua m�o toca alguma coisa fria, dura e lisa. O objeto � pequeno e redondo, mas voc� n�o consegue imaginar o que pode ser. Voc� o p�e na mochila, esperando saber o que � quando sair do po�o. Voc� continua a engatinhar e, adiante, topa com a parede do po�o. � lisa demais para ser escalada, e voc� tem que escavar apoios nela com a espada. Isso toma muito tempo, mas, finalmente, voc� chega � boca do po�o e sai dele pelo lado leste. Imediatamente, verifica a mochila, e descobre que o objeto encontrado � uma esfera de rubi vermelho vivo. Voc� fica absolutamente deslumbrado e se dirige para o leste com excelente disposi��o, assobiando suavemente.\n\n");

    if(status_OP285 >= 0 && status_OP285 <= 2){
        energy -= 2;
        hability -= 1;
        ruby += 1;
        status_OP011 += 1;
        printf("Voc� perdeu 1 de HABILIDADE\n");
        printf("Sua HABILIDADE: %i\n\n", hability);
        printf("Voc� perdeu 2 de ENERGIA\n");
        printf("Sua ENERGIA: %i\n\n", energy);
        printf("\033[1;34m");
        printf("Rubi Vermelho foi adicionado a seu invent�rio");
        printf("\033[0;37m");
        enter();
        OP237();
    }else{
        printf("\033[1;31mVoc� j� esteve aqui, nada foi adicionado ao seu invent�rio.\033[0;37m\n\n");
        enter();
        OP237();
    }
}

//OPCAO 286
void OP286(){
    printf("\t286 - Foi obviamente um erro ter largado suas armas, mas, pelo menos, agora voc� pode se apossar das do Ninja morto. Voc� escolhe uma das facas compridas e a longa espada curva. O fio da l�mina de a�o � excepcionalmente duro, e voc� n�o consegue deixar de admirar-lhe a beleza terrificante.\n\n");

    printf("\033[1;32mVoc� ganhou 4 de HABILIDADE\033[0;37m\n");
    printf("Sua HABILIDADE: %i\n\n", hability);
    enter();
    OP320();
}

//OPCAO 287
void OP287(){
    stageops = 287;
    save();
    loop = 0;

    printf("\t287 - Voc� s� tem tempo de ouvir o Gnomo dizer: \"Uma coroa e dois cr�nios\", antes que um raio branco de energia parta da fechadura e atinja-lhe o peito, derrubando-o sem sentidos. \033[1;33mDigite \"ROLL\",\033[1;31m  voc� perde ENERGIA igual ao resultado mais 1.\033[0;37m\n\n");

    while(loop < 1){
        gets(startroll);
        if(strcasecmp(startroll, "roll") == 0){
            dice1();
            if(numroll > 0){
                energy = energy - (numroll + 1);
                printf("Sua ENERGIA: %i", energy);
            }
            if(energy > 0){
                printf("\n\nVoc� recupera a consci�ncia e o Gnomo manda que tente de novo. Voc� sabe que colocou uma gema na ranhura certa, mas qual? Voc� suspira e tenta uma nova combina��o.\n\n    A         B         C     \nEsmeralda|Diamante |Safira    -> \033[1;35mDigite 16.\033[0;37m\nDiamante |Safira   |Esmeralda -> \033[1;35mDigite 392.\033[0;37m\nSafira   |Esmeralda|Diamante  -> \033[1;35mDigite 177\033[0;37m\nEsmeralda|Safira   |Diamante  -> \033[1;35mDigite 287.\033[0;37m\nDiamante |Esmeralda|Safira    -> \033[1;35mDigite 132.\033[0;37m\nSafira   |Diamante |Esmeralda -> \033[1;35mDigite 249.\033[0;37m\n\n");

                printf("\033[1;34mLEMBRE-SE, VOC� PODE ACESSAR SEU INVENT�RIO DIGITANDO 0\033[0;37m\n\n");

                scanf("%i", &choices);
                switch(choices){
                    case 16:
                        loop++;
                        system("cls");
                        OP016();
                        break;
                    case 392:
                        loop++;
                        system("cls");
                        OP392();
                        break;
                    case 177:
                        loop++;
                        system("cls");
                        OP177();
                        break;
                    case 287:
                        loop++;
                        system("cls");
                        OP287();
                        break;
                    case 132:
                        loop++;
                        system("cls");
                        OP132();
                        break;
                    case 249:
                        loop++;
                        system("cls");
                        OP249();
                        break;
                    case 0:
                        inventory();
                        enter();
                        OP132();
                        break;
                }
            }else{
                death();
            }
        }
    }
}

//OPCAO 288
void OP288(){
    stageops = 288;
    save();
    loop = 0;

    printf("\t288 - Voc� olha para a esquerda e v� Throm de p� sobre o Troll da Caverna que ele liquidou. O sangue que escorre do corte profundo que tem no ombro n�o parece preocup�-lo. Voc�s revistam os corpos dos Trolls da Caverna, mas n�o encontram nada al�m de um anel de osso em um cord�o de couro no pesco�o de um deles. O anel tem um s�mbolo entalhado. Throm o reconhece e explica que deve ter pertencido a druidas do norte; trata-se de um antigo e poderoso talism�, capaz de aumentar-lhe os poderes, se seu corpo puder aceit�-lo. Throm recusa-se a tocar nele, e aconselha que voc� tamb�m n�o o fa�a. Se voc� quiser p�r o anel, \033[1;35mdigite 64.\033[0;37m\nSe preferir continuar para o leste com Throm, \033[1;35mdigite 221.\033[0;37m\n\n");

    printf("\033[1;34mLEMBRE-SE, VOC� PODE ACESSAR SEU INVENT�RIO DIGITANDO 0\033[0;37m\n\n");

    while(loop < 1){
        scanf("%i", &choices);
        switch(choices){
            case 64:
                loop++;
                system("cls");
                OP064();
                break;
            case 221:
                loop++;
                system("cls");
                OP221();
                break;
            case 0:
                inventory();
                enter();
                OP288();
                break;
        }
    }

}

//OPCAO 289
void OP289(){
    loop = 0;

    printf("\t289 - A cobertura de pano sobe para o topo da gaiola, e nela, para seu horror, voc� v� o rosto de uma mulher velha, cujo cabelo � uma massa de serpentes que silvam. � a terr�vel MEDUSA!. \033[1;33mDIGITE \"ROLL\" e teste sua SORTE.\033[0;37m\n\n");

    while(loop < 1){
        gets(startroll);
        if(strcasecmp(startroll, "roll") == 0){
            dice2();
            if(numroll <= luck){
                luck--;
                system("cls");
                OP216();
            }else{
                luck--;
                system("cls");
                OP019();
            }
        }
    }
}

//OPCAO 290
void OP290(){
    printf("\t290 - \033[1;33mDigite \"ROLL\" e role os dados.\033[0;37m\n\n");

    while(loop < 1){
        gets(startroll);
        if(strcasecmp(startroll, "roll") == 0){
            dice2();
            if(numroll == 8){
                system("cls");
                OP152();
            }else{
                system("cls");
                OP121();
            }
        }
    }
}

//OPCAO 291
void OP291(){
    printf("\t291 - O t�nel continua para o norte por uma longa dist�ncia, antes de fazer uma curva fechada para a direita. Ao vir�-la, voc� chega a um beco sem sa�da. Somente a entrada de um escorrega de madeira na parede oferece alguma esperan�a de continuidade no caminho. Voc� resolve se arriscar e sobe no escorrega. Desliza suavemente e aterrissa sobre as costas num aposento.");

    enter();
    OP090();
}

//OPCAO 292
void OP292(){
    stageops = 292;
    save();
    loop = 0;

    printf("\t292 - Uma porta se torna vis�vel na parede do lado esquerdo do t�nel. Voc� escuta cuidadosamente junto � porta, mas n�o ouve nada. A porta n�o est� trancada, e a ma�aneta gira facilmente. Se voc� quiser abrir a porta, \033[1;35mdigite 93.\033[0;37m\nSe preferir prosseguir pelo t�nel, \033[1;35mdigite 230.\033[0;37m\n\n");

    printf("\033[1;34mLEMBRE-SE, VOC� PODE ACESSAR SEU INVENT�RIO DIGITANDO 0\033[0;37m\n\n");

    while(loop < 1){
        scanf("%i", &choices);
        switch(choices){
            case 93:
                loop++;
                system("cls");
                OP093();
                break;
            case 230:
                loop++;
                system("cls");
                OP230();
                break;
            case 0:
                inventory();
                enter();
                OP292();
                break;
        }
    }
}

//OPCAO 293
void OP293(){
    stageops = 293;
    save();
    loop = 0;

    printf("\t293 - Seguindo os tr�s pares de pegadas molhadas pela passagem oeste do t�nel, voc� logo chega a uma encruzilhada.\n\nSe quiser continuar para o oeste, seguindo dois pares de pegadas, \033[1;35mdigite 137.\033[0;37m\nSe quiser se dirigir para o norte, seguindo o terceiro par de pegadas, \033[1;35mdigite 387.\033[0;37m\n\n");

    printf("\033[1;34mLEMBRE-SE, VOC� PODE ACESSAR SEU INVENT�RIO DIGITANDO 0\033[0;37m\n\n");

    while(loop < 1){
        scanf("%i", &choices);
        switch(choices){
            case 137:
                loop++;
                system("cls");
                OP137();
                break;
            case 387:
                loop++;
                system("cls");
                OP387();
                break;
            case 0:
                inventory();
                enter();
                OP293();
                break;
        }
    }
}

//OPCAO 294
void OP294(){
    loop = 0;

    printf("\t294 - Voc� puxa o punhal do cinto com a m�o livre e golpeia a l�ngua da Besta Sangrenta. A fera urra de dor e rola para a frente, tanto quanto consegue, para tentar abocanh�-lo com as mand�bulas ensanguentadas. Do ch�o, voc� tem que lutar contra a fera como punhal. \033[1;31mReduza sua HABILIDADE em 2 pontos durante este combate\033[0;37m, pois n�o est� lutando com sua espada.\n\n\033[1;31mBESTA SANGRENTA HABILIDADE 12 ENERGIA 10\033[0;37m \n\nT�o logo que voc� vencer sua primeira S�rie de Ataque, \033[1;33mTESTE SUA SORTE.\033[0;37m");

    monshability = 12;
    monsenergy = 10;
    enter();

    printf("COME�OU O COMBATE!");
    combatloop = 0;
    while(combatloop < 1){
        loop = 0;
        printf("\nRode os dados:\n");
        printf("\033[0;31m");
        printf("DIGITE ROLL\n");
        printf("\033[0;37m");
        gets(combatroll);
        if(strcasecmp(combatroll, "roll") == 0){
            dice2();
            playerhabil = numroll + hability;
            printf("\n\nSUA FOR�A DE ATAQUE: %d\n\n", playerhabil);

            dice2();
            damagemonster = numroll + monshability;
            printf("\n\nFOR�A DE ATAQUE DO MONSTRO: %d\n", damagemonster);
        }
        if(strcasecmp(combatroll, "roll") == 0 && playerhabil > damagemonster){
            printf("\nVOC� CAUSOU DANO\n");
            monsenergy -= 2;
            printf("\nVoc� deseja testar sua SORTE? (digite \"sim\" ou \"nao\")\n");
            while(loop < 1){
                gets(luckhit);
                if(strcasecmp(luckhit, "sim") == 0){
                    dice2();
                    if(numroll <= luck){
                        luck--;
                        printf("\n\nSua SORTE: %d", luck);
                        monsenergy -= 2;
                        combatloop += 1;
                        loop++;
                        enter();
                        OP097();
                    }
                    else{
                        luck--;
                        printf("\n\nSua SORTE: %d", luck);
                        monsenergy += 1;
                        combatloop += 1;
                        loop++;
                        enter();
                        OP021();
                    }
                    printf("\n\n");
                }
                else if(strcasecmp(luckhit, "nao") == 0){
                    printf("\033[1;31mVOCE PRECISA TESTAR SUA SORTE\033[0;37m");
                }
            }
            printf("HP MONSTRO: %d", monsenergy);
            enter();
        }
        else if(strcasecmp(combatroll, "roll") == 0 && playerhabil < damagemonster){
            printf("\nVOCE LEVOU DANO\n");
            printf("\nVoc� deseja testar sua SORTE? (digite \"sim\" ou \"nao\")\n");
            while(loop < 1){
                gets(luckhit);
                if(strcasecmp(luckhit, "sim") == 0){
                    dice2();
                    if(numroll <= luck){
                        luck--;
                        printf("\n\nSua SORTE: %d", luck);
                        energy += 1;
                        loop++;
                    }
                    else{
                        luck--;
                        printf("\n\nSua SORTE: %d", luck);
                        energy -= 1;
                        loop++;
                    }
                    printf("\n\n");
                }
                else if(strcasecmp(luckhit, "nao") == 0){
                    loop++;
                }
            }
            energy -= 2;
            printf("SEU HP: %d", energy);
            enter();
        }
        else if(strcasecmp(combatroll, "roll") == 0 && playerhabil == damagemonster){
            printf("\nAMBOS CONSEGUIRAM SE DEFENDER E NINGU�M SE MACHUCOU");
            enter();
        }
        if(energy <= 0){
            death();
        }
        else if (monsenergy <= 0){
            combatloop += 1;
            printf("VOCE GANHOU O COMBATE");
            enter();
        }
        system("cls");
    }
}

//OPCAO 295
void OP295(){
    loop = 0;

    printf("\t295 - Correndo na dire��o da passagem em arco, voc� trope�a numa pedra e perde o equil�brio. Voc� cai estatelado no ch�o, e, antes que tenha tempo de levantar-se, uma estalactite despenca, rasgando-lhe a perna com a ponta agu�ada. \033[1;31mVoc� perde 5 pontos de ENERGIA.\033[0;37m\n\n");

    energy -= 5;
    printf("Voc� perdeu 2 de ENERGIA\n");
    printf("Sua ENERGIA: %i\n\n", energy);
    if(energy <= 0){
        death();
    }else{
        printf("Voc� conseguiu sobreviver");
        enter();
        OP206();
    }
}

//OPCAO 296
void OP296(){
    stageops = 296;
    save();
    loop = 0;

    printf("\t296 - Voc� percebe que adiante o t�nel faz uma curva e depois continua para o norte. Alertado pelo som de vozes esgani�adas que sussurram e riem baixo, voc� p�ra antes da curva. Se quiser desembainhar a espada e olhar depois da curva, \033[1;35mdigite 49.\033[0;37m\nSe preferir caminhar de volta para a encruzilhada e seguir para o norte, \033[1;35mdigite 241.\033[0;37m\n\n");

    printf("\033[1;34mLEMBRE-SE, VOC� PODE ACESSAR SEU INVENT�RIO DIGITANDO 0\033[0;37m\n\n");

    while(loop < 1){
        scanf("%i", &choices);
        switch(choices){
            case 49:
                loop++;
                system("cls");
                OP049();
                break;
            case 241:
                loop++;
                system("cls");
                OP241();
                break;
            case 0:
                inventory();
                enter();
                OP296();
                break;
        }
    }
}

//OPCAO 297
void OP297(){
    loop = 0;

    printf("\t297 - A perda de suas posses, obtidas com tanta dificuldade, est� se tornando um problema. \033[1;31mVoc� perde 1 ponto de SORTE.\033[0;37m Sem mesmo parar para agradecer, Erva o empurra para fora do quarto por uma porta na parede leste. Ei-lo parado no fim de um outro t�nel.\n\n");

    luck -= 1;
    printf("Voc� perdeu 1 de SORTE\n");
    printf("\n\nSua SORTE: %i", luck);
    enter();
    OP305();
}

void OP298(){
    stageops = 298;
    save();
    loop = 0;

    printf("\t298 - H� uma mochila encostada na parede do t�nel. Voc� se pergunta se ela pertenceria a um de seus rivais.\n\nSe voc� quiser olhar dentro da mochila, \033[1;35mdigite 304.\033[0;37m\nSe preferir continuar para o norte, \033[1;35mdigite 279.\033[0;37m\n\n");

    printf("\033[1;34mLEMBRE-SE, VOC� PODE ACESSAR SEU INVENT�RIO DIGITANDO 0\033[0;37m\n\n");

    while(loop < 1){
        scanf("%i", &choices);
        switch(choices){
            case 304:
                loop++;
                system("cls");
                OP304();
                break;
            case 279:
                loop++;
                system("cls");
                OP279();
                break;
            case 0:
                inventory();
                enter();
                OP298();
                break;
        }
    }


}

//OPCAO 299
void OP299(){
    stageops = 299;
    save();
    loop = 0;

    printf("\t299 - A porta abre para uma grande c�mara, onde voc� se choca ao ver que um de seus rivais obviamente encontrou morte s�bita ao ser perfurado. � um dos B�rbaros, e ele est� empalado em v�rios espig�es de ferro bem longos, presos a uma t�bua projetada de dentro do ch�o. O piso est� coberto de lixo e detritos, escondendo um arame no qual ele deve ter pisado, disparando assim o mecanismo da t�bua com espig�es. Numa alcova na parede do outro lado, voc� pode ver uma ta�a de prata sobre uma pequena mesa de madeira. Voc�:\n\nIr� at� o B�rbaro para revist�-lo? \033[1;35mDigite 126.\033[0;37m\nCaminhar� na dire��o da alcova? \033[1;35mDigite 41.\033[0;37m\nFechar� a porta e continuar� para o oeste? \033[1;35mDigite 83.\033[0;37m\n\n");

    printf("\033[1;34mLEMBRE-SE, VOC� PODE ACESSAR SEU INVENT�RIO DIGITANDO 0\033[0;37m\n\n");

    while(loop < 1){
        scanf("%i", &choices);
        switch(choices){
            case 126:
                loop++;
                system("cls");
                OP126();
                break;
            case 41:
                loop++;
                system("cls");
                OP041();
                break;
            case 83:
                loop++;
                system("cls");
                OP083();
                break;
            case 0:
                inventory();
                enter();
                OP299();
                break;
        }
    }

}

//OPCAO 300
void OP300(){
    stageops = 300;
    save();
    loop = 0;

    printf("\t300 - Voc� golpeia o espelho com a espada, com toda sua for�a, mas isso de nada adianta: o espelho n�o quebra, e o Dem�nio do Espelho continua a avan�ar.\n\nSe voc� quiser tentar partir o espelho de novo, \033[1;35mdigite 141.\033[0;37m\nSe, em vez disso, preferir atacar o Dem�nio do Espelho, \033[1;35mdigite 327.\033[0;37m\n\n");

    printf("\033[1;34mLEMBRE-SE, VOC� PODE ACESSAR SEU INVENT�RIO DIGITANDO 0\033[0;37m\n\n");

    while(loop < 1){
        scanf("%i", &choices);
        switch(choices){
            case 141:
                loop++;
                system("cls");
                OP141();
                break;
            case 327:
                loop++;
                system("cls");
                OP327();
                break;
            case 0:
                inventory();
                enter();
                OP300();
                break;
        }
    }
}

//OPCAO 301
void OP301(){
    stageops = 301;
    save();
    loop = 0;

    printf("\t301 - O cano est� �mido e cheio de limo, mas voc� segue engatinhando na escurid�o abafada, escorregando e deslizando no caminho. Subitamente, sua m�o toca em algo duro e quadrado; parece ser de madeira. Ao sacudi-la, a coisa chacoalha, e voc� conclui que deve estar segurando uma caixa. Se quiser engatinhar de volta e sair do cano para examinar o achado, \033[1;35mdigite 162.\033[0;37m\nSe preferir seguir em frente pelo cano, levando a caixa para examinar mais tarde, \033[1;35mdigite 4.\033[0;37m\n\n");

    printf("\033[1;34mLEMBRE-SE, VOC� PODE ACESSAR SEU INVENT�RIO DIGITANDO 0\033[0;37m\n\n");

    while(loop < 1){
        scanf("%i", &choices);
        switch(choices){
            case 162:
                loop++;
                system("cls");
                OP162();
                break;
            case 4:
                loop++;
                system("cls");
                OP004();
                break;
            case 0:
                inventory();
                enter();
                OP301();
                break;
        }
    }
}

//OPCAO 302
void OP302(){
    loop = 0;
    monsenergy = 12;
    monshability = 10;

    printf("\t302 - Depois de cerca de 20 minutos, o An�o reaparece na sacada. Ele lhe grita: \"Bem, eu realmente tenho um problema muito interessante nas m�os. Prepare-se para lutar contra seu pr�ximo advers�rio.\" A porta de madeira se ergue mais uma vez, e voc� se admira ao ver um rosto conhecido. � Throm! Ele est� muito machucado e tem cortes pelo corpo todo, e n�o parece reconhec�-lo. Est� claramente delirante enquanto cambaleia para frente com a acha erguida para atac�-lo. O An�o ri e lhe diz: \"A naja o mordeu, mas ele tema for�a de um touro e conseguiu resistir, ao contr�rio da maioria dos homens. Agora voc� deve lutar com ele, para decidir finalmente qual dos dois continuar� na Prova dos Campe�es.\" Voc� grita com o An�o, revoltado, denunciando a crueldade de um confronto desses. Ele simplesmente ri, e voc� n�o tem alternativas e n�o se defender do ataque do pobre Throm. \n\n\033[1;31mTHROM HABILIDADE 10 ENERGIA 12\033[0;37m\nApesar dos ferimentos, Throm � imensamente forte...");

    enter();
    combat1();
    printf("Voc� sobreviveu a THROM!\n");
    printf("\nSua ENERGIA: %i", energy);
    enter();
    OP379();
}

//OPCAO 303
void OP303(){
    printf("\t303 - Com sua m�o livre, voc� busca a moringa na mochila. Desarrolhando-a com os dentes, derrama o �cido sobre a porta, que � na realidade a forma fluida de um IMITADOR. Um jato de fuma�a sobe dela, com um alto som sibilante, enquanto o �cido come�a a queimar o Imitador. Ela derrete rapidamente, e voc� consegue afastar-se sem se ferir. N�o tendo outra alternativa, voc�, um tanto apreensivo, gira a ma�aneta da outra porta.");

    enter();
    OP262();
}

//OPCAO 304
void OP304(){
    printf("\t304 - H� uma �nica Pe�a de Ouro no fundo da mochila. Quando voc� tenta peg�-la, sente um leve movimento que faz c�cegas nas costas, da sua m�o. Voc� retira a m�o lentamente, tentando controlar o p�nico crescente, e fica horrorizado ao ver uma ARANHA VI��VA NEGRA. Antes que possa afast�-la, ela crava as presas venenosas profundamente no seu pulso.\033[1;31m Voc� perde 6 pontos de ENERGIA.\033[0;37m\n\n");

    energy -= 6;
    printf("Voc� perdeu 6 de ENERGIA");
    printf("\nSua ENERGIA: %i\n\n", energy);
    if(energy <= 0){
        death();
    }else{
        printf("Voc� sobreviveu a picada da Vi�va-Negra");
        enter();
        OP020();
    }
}

//OPCAO 305
void OP305(){
    stageops = 305;
    save();
    loop = 0;

    printf("305 - O t�nel termina em um lance de degraus de pedra. Do ch�o, abaixo, v�m latidos de c�es. Voc� tem um osso velho?\n\nSe tiver, \033[1;35mdigite 253.\033[0;37m\nSe n�o tiver, \033[1;35mdigite 148.\033[0;37m\n\n");

    printf("\033[1;34mLEMBRE-SE, VOC� PODE ACESSAR SEU INVENT�RIO DIGITANDO 0\033[0;37m\n\n");

    while(loop < 1){
        scanf("%i", &choices);
        switch(choices){
            case 148:
                loop++;
                system("cls");
                OP148();
                break;
            case 253:
                loop++;
                if(old_bone != 0){
                    system("cls");
                    OP253();
                } else{
                    printf("Voc� n�o tem este item.");
                    enter();
                    OP305();
                }
                break;
            case 0:
                inventory();
                enter();
                OP305();
                break;
        }
    }
}

//OPCAO 306
void OP306(){
    printf("306 - Antes que voc� possa dar um passo na dire��o dos Leprechauns, um deles joga uma poeira cintilante em voc�, que � imediatamente congelado no lugar, incapaz de mover um m�sculo. Voc� v�, indefeso, os Leprechauns revirarem sua mochila, fugindo com todas as suas posses e deixando a mochila vazia. \033[1;31mVoc� perde 2 pontos de SORTE.\033[0;37m Cerca de uma hora depois, o efeito congelante da poeira se desfaz, e as sensa��es retornam a seu corpo. Furioso com a perda, voc� ruma para o norte, determinado a se vingar.\n\n");

    luck -= 2;
    printf("Voc� perdeu 2 de SORTE\n");
    printf("Voc� perdeu TODOS os itens do seu invent�rio");

    hability_potion = 0, luck_potion = 0, energy_potion = 0, emerald = 0, sapphire = 0, iron_hook = 0, iron_key = 0, wood_tube = 0, rope = 0, metal_bell = 0, brass_bell = 0, chalice = 0, morph_potion = 0, leather_wristband = 0, monkey_amulet = 0, dagger = 0, ruby = 0, topaz = 0, wooden_legs = 0, old_bone = 0, shield = 0, wish_ring = 0, moringa_acid = 0, diamond = 0;
    enter();
    OP029();
}

//OPCAO 307
void OP307(){
    stageops = 307;
    save();
    loop = 0;

    printf("307 - O arm�rio cont�m uma marreta de madeira e 10 espig�es de ferro, os quais voc� p�e na mochila enquanto decide qual porta abrir.\n\nSe quiser abrir a porta do oeste, volte \033[1;35mdigite 263.\033[0;37m\nSe preferir abrir a porta do norte, \033[1;35mdigite 136.\033[0;37m\n\n");

    printf("\033[1;34mLEMBRE-SE, VOC� PODE ACESSAR SEU INVENT�RIO DIGITANDO 0\033[0;37m\n\n");

    while(loop < 1){
        scanf("%i", &choices);
        switch(choices){
            case 263:
                loop++;
                system("cls");
                OP263();
                break;
            case 136:
                loop++;
                system("cls");
                OP136();
                break;
            case 0:
                inventory();
                enter();
                OP307();
                break;
        }
    }
}

//OPCAO 308
void OP308(){
    stageops = 308;
    save();
    loop = 0;

    printf("\t308 - A Medusa berra quando voc� entra na gaiola, mantendo os olhos firmemente fechados e desferindo golpes furiosos de um lado para o outro com a espada. Voc� sente a l�mina penetrar profundamente na fera e ouve um baque alto quando ela desaba pesadamente no ch�o. Voc� abre os olhos de novo e se arrepia com a vis�o da Medusa prostrada. O manto dela est� preso por um grande broche constitu�do por uma �nica gema grande; � uma granada. Voc� a arranca, p�e no bolso e sai do aposento, rumo ao norte.\n\n");

    if(status_OP308 == 0){
        grenade += 1;
        status_OP308 += 1;
        printf("\033[1;34mVoc� ganhou uma GRANADA\033[0;37m");
        enter();
        OP316();
    }else{
        printf("\033[1;31mVoc� j� esteve aqui, nada foi adicionado ao seu invent�rio.\033[0;37m\n\n");
        enter();
        OP316();
    }
}

//OPCAO 309
void OP309(){
    loop = 0;

    printf("\t309 - Voc� cambaleia desnorteado em busca de uma po�a de �gua, mas n�o encontra. O �cido queima com uma dor lancinante bem fundo na sua garganta. \033[1;31mVoc� perde 3 pontos de ENERGIA.\033[0;37m \033[1;33mDigite \"ROLL\" e teste sua SORTE.\033[0;37m");

    energy -= 3;
    printf("Voc� perdeu 3 de ENERGIA");
    printf("\nSua ENERGIA: %i", energy);
    if(energy <= 0){
        death();
    }else{
        while(loop < 1){
            gets(startroll);
            if(strcasecmp(startroll, "roll") == 0){
                dice2();
                if(numroll <= luck){
                    luck--;
                    system("cls");
                    OP231();
                }else{
                    luck--;
                    system("cls");
                    OP193();
                }
            }
        }
    }
}

//OPCAO 310
void OP310(){
    stageops = 310;
    save();
    loop = 0;

    printf("\t310 - Voc� chega � parede do outro lado da c�mara e v� duas portas.\n\nSe quiser abrir a portada esquerda, \033[1;35mdigite 339.\033[0;37m\nSe quiser abrir a porta da direita, \033[1;35mdigite 262.\033[0;37m\n\n");

    printf("\033[1;34mLEMBRE-SE, VOC� PODE ACESSAR SEU INVENT�RIO DIGITANDO 0\033[0;37m\n\n");

    while(loop < 1){
        scanf("%i", &choices);
        switch(choices){
            case 339:
                loop++;
                system("cls");
                OP339();
                break;
            case 262:
                loop++;
                system("cls");
                OP262();
                break;
            case 0:
                inventory();
                enter();
                OP310();
                break;
        }
    }
}

//OPCAO 311
void OP311(){
    printf("\t311 - Depois de muito relutar, o B�rbaro concorda com sua alternativa. Voc�s dois tomam dist�ncia e saltam por sobre o po�o. Aterrissando em seguran�a do outro lado, voc� continua descendo pelo t�nel. O B�rbaro, que vai na frente, subitamente trope�a em uma pedra, que se inclina para frente e dispara o mecanismo de um rochedo preso precariamente ao teto. O rochedo despenca sobre ele, derrubando-o e esmagando-lhe o cr�nio. \033[1;31mVoc� ter� que continuar sua jornada sozinho.\033[0;37m");

    enter();
    OP325();
}

//OPCAO 312
void OP312(){
    loop = 0;
    monsenergy = 9;
    monshability = 11;

    printf("\t312 - O disco, afiado como uma navalha, passa assobiando pela sua cabe�a e crava-se profundamente em um dos pilares. Voc� se vira e p�e-se em guarda para enfrentar o assassino, que avan�a com a espada longa desembainhada.\n\n\033[1;31mNINJA HABILIDADE 11 ENERGIA 9\033[0;37m\n\n");

    enter();
    combat1();
    printf("Voc� venceu o NINJA!\n");
    printf("Sua ENERGIA: %i", energy);
    enter();
    OP232();
}

//OPCAO 313
void OP313(){
    printf("\t313 - O t�nel termina em uma encruzilhada. As pegadas que voc� vem seguindo viram para o norte, e voc� resolve manter-se na trilha delas.");

    enter();
    OP032();
}

//OPCAO 314
void OP314(){
    loop = 0;

    printf("\t314 - Sua espada corta a ma�aneta e, separada do corpo de origem, a membrana murcha e cai ao ch�o. N�o tendo outra alternativa, voc� gira, um tanto apreensivo, a ma�aneta da outra porta.");

    enter();
    OP262();
}

//OPCAO 315
void OP315(){
    stageops = 315;
    save();
    loop = 0;

    printf("\t315 - O t�nel d� uma guinada brusca para a esquerda e chega ao fim em uma parede alta, na qual h� uma porta. Voc� ouve um rugido feroz vindo do outro lado da porta e tenta imaginar qu�o gigantesca seria a fera capaz de tamanho ru�do.\n\nSe voc� tiver um rolo de corda e um gancho de ferro, \033[1;35mdigite 129.\033[0;37m\nSe n�o tiver esses objetos, \033[1;35mdigite 245.\033[0;37m\n\n");

    while(loop < 1){
        scanf("%i", &choices);
        switch(choices){
            case 245:
                loop++;
                system("cls");
                OP245();
                break;
            case 129:
                loop++;
                if(rope != 0 && iron_hook != 0){
                    system("cls");
                    OP129();
                } else{
                    printf("\nVoc� n�o tem estes itens.");
                    enter();
                    OP315();
                }
                break;
            case 0:
                inventory();
                enter();
                OP315();
                break;
        }
    }
}

//OPCAO 316
void OP316(){
    stageops = 316;
    save();
    loop = 0;

    printf("\t316 - O t�nel continua por uma boa dist�ncia antes de chegar a um cruzamento.\n\nSe voc� quiser se dirigir para o oeste pelo novo t�nel, \033[1;35mdigite 296.\033[0;37m\nSe preferir continuar para o norte, \033[1;35mdigite 241.\033[0;37m\n\n");
    while(loop < 1){
        scanf("%i", &choices);
        switch(choices){
            case 241:
                loop++;
                system("cls");
                OP241();
                break;
            case 296:
                loop++;
                system("cls");
                OP296();
                break;
            case 0:
                inventory();
                enter();
                OP316();
                break;
        }
    }
}

//OPCAO 317
void OP317(){
    printf("\t317 - Tateando nos lados do buraco perfurado com sua espada, voc� abre caminho cegamente pelo lodo viscoso. Voc� segue as curvas e reviravoltas do orif�cio por um tempo que parece ser uma eternidade e come�a a imaginar onde poderia levar. De repente, voc� ouve o ru�do de alguma coisa se arrastando � frente. Voc� fica gelado de medo, seus olhos tentando desesperadamente rasgar a escurid�o impenetr�vel. Antes que voc� se d� conta do que est� acontecendo, seu pesco�o � abocanhado pelas fort�ssimas mand�bulas de outro Verme da Rocha. E o companheiro daquele que voc� matou, o qual foi atra�do pelo cheiro de sangue na sua espada. Ele aperta mais forte. Seu pesco�o estala como um ramo seco. \033[1;31mSua aventura termina aqui.\033[0;37m");
    death();
}

//OPCAO 318
void OP318(){
    stageops = 318;
    save();
    loop = 0;

    printf("\t318 - Depois de cruzar a ponte, voc� atravessa a caverna correndo. Finalmente, v� um t�nel na parede do outro lado, pelo qual voc� entra a toda. O t�nel termina numa pesada porta de madeira, e ela est� trancada.\n\nSe voc� tiver uma chave de ferro, \033[1;35mdigite 86.\033[0;37m\nSe n�o tiver uma chave, \033[1;35mdigite 276.\033[0;37m\n\n");
    while(loop < 1){
        scanf("%i", &choices);
        switch(choices){
            case 86:
                loop++;
                system("cls");
                OP086();
                break;
            case 276:
                loop++;
                if(iron_key != 0){
                    system("cls");
                    OP276();
                } else{
                    printf("Voc� n�o tem este item.");
                    enter();
                    OP318();
                }
                break;
            case 0:
                inventory();
                enter();
                OP318();
                break;
        }
    }
}

//OPCAO 319
void OP319(){
    loop = 0;

    printf("\t319 - A armadura e a espada pesam mais do que voc� pensa. No ar, voc� toma consci�ncia, com horror, de que n�o vai conseguir chegar ao outro lado do po�o. Voc� se choca contra o lado do po�o, uns dois metros abaixo da borda, e despenca de cabe�a para o fundo.");

    enter();
    OP285();
}

//OPCAO 320
void OP320(){
    stageops = 320;
    save();
    loop = 0;

    printf("\t320 - Voc� resolve revistar o Ninja e, em meio �s vestes dele, encontra um saco de pano. Dentro, h� um frasco de �gua, um pouco de arroz enrolado em folha de palmeira, um vidro de unguento e um lindo diamante. Voc�:\n\nComer� o arroz e beber� a �gua? \033[1;35mDigite 330.\033[0;37m\nEsfregar� um pouco do unguento nos seus ferimentos? \033[1;35mDigite 269.\033[0;37m\n Pegar� apenas o diamante e sair� do sal�o? \033[1;35mDigite 127.\033[0;37m\n\n");

    printf("O diamante foi adicionado ao seu invent�rio.");
    while(loop < 1){
        scanf("%i", &choices);
        switch(choices){
            case 330:
                loop++;
                system("cls");
                OP330();
                break;
            case 269:
                loop++;
                system("cls");
                OP269();
                break;
            case 127:
                loop++;
                system("cls");
                OP127();
                break;
            case 0:
                inventory();
                enter();
                OP320();
                break;
        }
    }
}

//OPCAO 321
void OP321(){
    stageops = 321;
    save();
    loop = 0;

    printf("\t321 - Voc� puxa o cord�o e o pano sobe pelos lados da gaiola. A voz da mulher insiste para que voc� seja r�pido, dizendo que o aposento est� preparado para uma cilada, de forma que o piso desabar� em um minuto por causa do seu peso extra.\n\nSe voc� ainda quiser ajud�-la, \033[1;35mdigite 289.\033[0;37m\n Se preferir sair do aposento e se dirigir para o norte pelo t�nel, \033[1;35mdigite 316.\033[0;37m\n\n");
    while(loop < 1){
        scanf("%i", &choices);
        switch(choices){
            case 289:
                loop++;
                system("cls");
                OP289();
                break;
            case 316:
                loop++;
                system("cls");
                OP316();
                break;
            case 0:
                inventory();
                enter();
                OP321();
                break;
        }
    }
}

//OPCAO 322
void OP322(){
    loop = 0;

    printf("\t322 - Voc� passa pela cadeira de madeira e logo retorna ao cruzamento, virando � direita para o oeste.");

    enter();
    OP043();
}

//OPCAO 323
void OP323(){
    loop = 0;

    printf("\t323 - Depois de amarrar a corda em torno da rocha, voc� desce devagar para o fundo do po�o. Throm recupera a corda dele, soltando-a da rocha com uma sacudidela, e voc�s partem juntos pelo novo t�nel.");

    enter();
    OP194();
}

//OPCAO 324
void OP324(){
    stageops = 324;
    save();
    loop = 0;

    printf("\t324 - Voc� falou com o servo aleijado dos Ju�zes da Prova? Se falou, \033[1;35mdigite 256.\033[0;37m Se n�o, \033[1;35mdigite 79.\033[0;37m\n\n");

    while(loop < 1){
        scanf("%i", &choices);
        switch(choices){
            case 79:
                loop++;
                system("cls");
                OP079();
                break;
            case 256:
                loop++;
                if(status_OP341 != 0){
                    system("cls");
                    OP256();
                } else{
                    printf("Voc� n�o falou com o servo.");
                    enter();
                    OP324();
                }
                break;
            case 0:
                inventory();
                enter();
                OP324();
                break;
        }
    }
}

//OPCAO 325
void OP325(){
    printf("\t325 - Voc� se levanta e segue t�nel abaixo. De repente, v� a luz do dia no fim do t�nel. Enquanto corre na dire��o da vis�o mais bela que teve diante de si desde muito tempo, um c�u claro e azul, �rvores verdes, voc� sonha com o alegre cen�rio de pessoas vibrando. Mas n�o h� recep��o de her�i da parte das pessoas � sua volta. Est�o todas mortas. Voc� est� dentro de uma c�mara fria repleta de cad�veres e esqueletos com armaduras. A sa�da para a vit�ria era apenas uma ilus�o. Somente os despojos de aventureiros do passado s�o reais. Profundamente deprimido, voc� caminha de volta para o t�nel, mas se choca com uma barreira invis�vel. \033[1;31mVoc� est� aprisionado neste sinistro local, fadado a terminar seus dias na c�mara dos mortos.\033[0;37m");
    death();
}

//OPCAO 326
void OP326(){
    loop = 0;

    printf("\t326 - Adiante, o t�nel faz uma curva fechada para a esquerda. Ao  dobr�-la, voc� quase bate de frente em dois ORCAS de aspecto feroz, armados de ma�as com pontas de ferro e usando armaduras de couro. Voc� est� totalmente despreparado, e, enquanto desembainha a espada, um deles desfere-lhe um golpe de ma�a. \033[1;33mDigite \"ROLL\" para rolar um dado.\033[0;37m\n\n");

    while(loop < 1){
        gets(startroll);
        if(strcasecmp(startroll, "roll") == 0){
            dice1();
            if(numroll == 1 || numroll == 2){
                system("cls");
                OP091();
            }else if(numroll == 3 || numroll == 4){
                system("cls");
                OP189();
            }else{
                system("cls");
                OP380();
            }
        }
    }
}

//OPCAO 327
void OP327(){
    loop = 0;

    printf("\t327 - Exclusivamente voltado para agarrar-lhe o bra�o, o Dem�nio do Espelho n�o tenta defenderse. DEM��NIO DO ESPELHO HABILIDADE 10 ENERGIA 10 Se, durante uma S�rie de Ataque, a For�a de Ataque do Dem�nio do Espelho for maior que a sua o combate terminar�.\n\n");

    printf("COME�OU O COMBATE!");
    combatloop = 0;
    while(combatloop < 1){
        loop = 0;
        printf("\nRode os dados:\n");
        printf("\033[0;31m");
        printf("DIGITE ROLL\n");
        printf("\033[0;37m");
        gets(combatroll);
        if(strcasecmp(combatroll, "roll") == 0){
            dice2();
            playerhabil = numroll + hability;
            printf("\n\nSUA FOR�A DE ATAQUE: %d\n\n", playerhabil);

            dice2();
            damagemonster = numroll + monshability;
            printf("\n\nFOR�A DE ATAQUE DO MONSTRO: %d\n", damagemonster);
        }
        if(strcasecmp(combatroll, "roll") == 0 && playerhabil > damagemonster){
            printf("\nVOC� CAUSOU DANO\n");
            monsenergy -= 2;
            printf("\nVoc� deseja testar sua SORTE? (digite \"sim\" ou \"nao\")\n");
            while(loop < 1){
                gets(luckhit);
                if(strcasecmp(luckhit, "sim") == 0){
                    dice2();
                    if(numroll <= luck){
                        luck--;
                        printf("\n\nSua SORTE: %d", luck);
                        monsenergy -= 2;
                        loop++;
                    }
                    else{
                        luck--;
                        printf("\n\nSua SORTE: %d", luck);
                        monsenergy += 1;
                        loop++;
                    }
                    printf("\n\n");
                }
                else if(strcasecmp(luckhit, "nao") == 0){
                    loop++;
                }
            }
            printf("HP MONSTRO: %d", monsenergy);
            enter();
        }
        else if(strcasecmp(combatroll, "roll") == 0 && playerhabil < damagemonster){
            printf("\nA FOR�A DE ATAQUE DO MONSTRO FOI MAIOR QUE A SUA! O COMBATE TERMINOU\n");
            enter();
            OP008();
        }
        else if(strcasecmp(combatroll, "roll") == 0 && playerhabil == damagemonster){
            printf("\nAMBOS CONSEGUIRAM SE DEFENDER E NINGU�M SE MACHUCOU");
            enter();
        }
        if(energy <= 0){
            death();
        }
        else if (monsenergy <= 0){
            combatloop += 1;
            system("cls");
            printf("VOCE GANHOU O COMBATE!");
            enter();
            OP092();
        }
    }
}

//OPCAO 328
void OP328(){
    stageops = 328;
    save();
    loop = 0;

    printf("328 - Voc� olha em torno do quarto de Erva. Ao ver o retrato de um outro Troll pendurado na parede, pergunta a ela se s�o parentes. Imediatamente, o humor e a express�o dela mudam. Ela afrouxa o aperto sobre voc� e sorri, dizendo: \"Ah, sim. Este � meu amado e querido irm�o Barriga Azeda. Ele tem-se sa�do muito bem l� no sul, em Port Blacksand. Est� agora na Guarda Imperial, na tropa de elite de Lord Azzur. Estou muito orgulhosa dele.\" Erva fica olhando para a pintura e continua a tecer elogios ao irm�o.\n\nSe voc� quiser se esgueirar para fora do quarto, pela porta na parede do leste, \033[1;35mdigite 125.\033[0;37m\nSe preferir continuar a conversa, \033[1;35mdigite 99.\033[0;37m\n\n");

    while(loop < 1){
        scanf("%i", &choices);
        switch(choices){
            case 125:
                loop++;
                system("cls");
                OP125();
                break;
            case 99:
                loop++;
                system("cls");
                OP099();
                break;
            case 0:
                inventory();
                enter();
                OP328();
                break;
        }
    }
}

//OPCAO 329
void OP329(){
    printf("329 - Voc� caminha at� o espelho e se diverte com a imagem distorcida. Sua cabe�a parece t�o grande quanto uma ab�bora, o rosto, muito estranho... Sem qualquer sinal pr�vio, uma dor terr�vel martela-lhe a cabe�a; voc� tenta desviar o olhar do espelho, mas n�o consegue. Alguma for�a do mal mant�m seus olhos pregados ao pr�prio reflexo. Voc� segura a cabe�a com as m�os e, horrorizado, se d� conta de que ela est� se expandindo. \033[1;31mVoc� n�o pode mais suportar a dor, e tomba sem sentidos para nunca mais acordar.\033[0;37m");
    death();
}

//OPCAO 330
void OP330(){
    stageops = 330;
    save();
    loop = 0;

    printf("330 - As ra��es do Ninja s�o modestas mas bem-vindas. \033[1;32mAcrescente 1 ponto de ENERGIA.\033[0;37m\n\nVoc� poder� esfregar um pouco do unguento nos seus ferimentos, \033[1;35mdigite 269.\033[0;37m\nOu sair do sal�o, levando s� o diamante, \033[1;35mdigite 127.\033[0;37m");

    if(status_OP330 == 0){
        status_OP330 += 1;
        energy += 1;
        printf("Sua ENERGIA: %i", energy);
        while(loop < 1){
            scanf("%i", &choices);
            switch(choices){
                case 127:
                    loop++;
                    system("cls");
                    OP127();
                    break;
                case 269:
                    loop++;
                    system("cls");
                    OP269();
                    break;
                case 0:
                    inventory();
                    enter();
                    OP330();
                    break;
            }
        }
    }else{
        printf("\033[1;31mVoc� j� esteve aqui, nada foi adicionado ao seu invent�rio.\033[0;37m\n\n");
        while(loop < 1){
            scanf("%i", &choices);
            switch(choices){
                case 127:
                    loop++;
                    system("cls");
                    OP127();
                    break;
                case 269:
                    loop++;
                    system("cls");
                    OP269();
                    break;
                case 0:
                    inventory();
                    enter();
                    OP330();
                    break;
            }
        }
    }
}

//OPCAO 331
void OP331(){
    loop = 0;
    monsenergy = 6;
    monshability = 8;

    printf("331 - Tocar o pergaminho tem precisamente o efeito que voc� temia. O esqueleto d� um impulso para frente e, levantando-se da cadeira numa s�rie de movimentos aos arrancos, ergue a espada para golpe�-lo. Esquivando-se para o lado, voc� desembainha a sua espada para se defender.\n\nGUERREIRO-ESQUELETO HABILIDADE 8 ENERGIA 6");

    enter();
    combat1();
    printf("Voc� derrotou o GUERREIRO-ESQUELETO!\n");
    printf("Sua ENERGIA: %i", energy);
    enter();
    OP071();
}

//OPCAO 332
void OP332(){
    printf("332 - Sua gema cai na po�a com um \"plop\" surdo. Enquanto espera que alguma coisa aconte�a, voc� come�a a se sentir fraco. O g�s que emana da po�a � t�xico, e voc� tomba inconsciente. \033[1;33mDigite \"ROLL\" e teste sua HABILIDADE.\033[0;37m\n\n");

    while(loop < 1){
        gets(startroll);
        if(strcasecmp(startroll, "roll") == 0){
            dice2();
            if(numroll <= luck){
                luck--;
                system("cls");
                OP053();
            }else{
                luck--;
                system("cls");
                OP272();
            }
        }
    }
}

//OPCAO 333
void OP333(){
    printf("333 - Voc� ouve passos e, de repente, a porta do al�ap�o � jogada para tr�s. Por alguns segundos, voc� � cegado pela intensa luz que vem do aposento de cima, e n�o v� o Goblin desferir um golpe de lan�a, nem ouve o riso s�dico quando a ponta rasga seu pesco�o. \033[1;31mSua aventura termina aqui, nos degraus de pedra do t�nel.\033[0;37m");
    death();
}

//OPCAO 334
void OP334(){
    printf("334 - Voc� tenta se livrar da l�ngua com as m�os nuas, mas n�o consegue. Lentamente, voc� � arrastado para a po�a, onde, depois de decomposto pelo lodo, \033[1;31mseu corpo ser� devorado pela pavorosa Besta Sangrenta.\033[0;37m");
    death();
}

//OPCAO 335
void OP335(){
    loop = 0;

    printf("\t335 - Ainda correndo o mais r�pido que pode, voc� mergulha no rio. \033[1;33mDigite \"ROLL\" e teste sua SORTE.\033[0;37m\n\n");

    while(loop < 1){
        gets(startroll);
        if(strcasecmp(startroll, "roll") == 0){
            dice2();
            if(numroll <= luck){
                luck--;
                system("cls");
                OP067();
            }else{
                luck--;
                system("cls");
                OP101();
            }
        }
    }

}

//OPCAO 336
void OP336(){
    loop = 0;

    printf("\t336 - A munhequeira foi feita e amaldi�oada por uma Bruxa. Ela torna suas rea��es mais lentas e embota-lhe os sentidos. \033[1;31mReduza sua HABILIDADE em 4 pontos.\033[0;37m Furioso, voc� chuta a parede do t�nel e segue para o norte.\n\n");

    if(status_OP336 == 0){
        leather_wristband += 1;
        hability -= 4;
        status_OP336 += 1;
        printf("\033[1;34mMunhequeira de Couro Amaldi�oada foi adicionada a seu invent�rio\033[0;37m");
        printf("\n\nVoc� perdeu 4 de HABILIDADE");
        printf("\nSua HABILIDADE: %i", hability);
        enter();
        OP298();
    }else{
        printf("\033[1;31mVoc� j� esteve aqui, nada foi adicionado ao seu invent�rio.\033[0;37m\n\n");
        printf("\nSua HABILIDADE: %i", hability);
        enter();
        OP298();
    }
}

//OPCAO 337
void OP337(){
    stageops = 337;
    save();
    loop = 0;

    printf("\t337 - A �gua fresca � revigorante, mas prov�m de uma fonte amaldi�oada por uma Bruxa. Some 1 ponto de ENERGIA, mas desconte 2 pontos de SORTE.\n\nVoc� poder� beber da outra fonte, \033[1;35mdigite 173\033[0;37m\nOu continuar para o norte, \033[1;35mdigite 368.\033[0;37m\n\n");

    printf("Voc� perdeu 2 de SORTE\n");
    printf("Sua SORTE: %i\n\n", luck - 2);
    printf("\n\nVoc� ganhou 1 de ENERGIA\n");
    printf("Sua ENERGIA: %i\n\n", energy + 1);

    if(status_OP337 >= 0 && status_OP337 <= 2){
        luck -= 2;
        energy += 1;
        status_OP337 += 1;
        while(loop < 1){
            scanf("%i", &choices);
            switch(choices){
                case 173:
                    loop++;
                    system("cls");
                    OP173();
                    break;
                case 368:
                    loop++;
                    system("cls");
                    OP368();
                    break;
                case 0:
                    inventory();
                    enter();
                    OP337();
                    break;
            }
        }
    }else{
        printf("\033[1;31mVoc� j� esteve aqui, nada foi adicionado ao seu invent�rio.\033[0;37m\n\n");
        while(loop < 1){
            scanf("%i", &choices);
            switch(choices){
                case 200:
                    loop++;
                    system("cls");
                    OP200();
                    break;
                case 316:
                    loop++;
                    system("cls");
                    OP316();
                    break;
                case 0:
                    inventory();
                    enter();
                    OP337();
                    break;
            }
        }
    }
}

//OPCAO 338
void OP338(){
    stageops = 338;
    save();
    loop = 0;

    printf("338 - Os corpos s�o de dois guardas Orcas. Pelo menos um de seus rivais na Prova dos Campe�es ainda deve estar � sua frente. De uma r�pida revista aos corpos nada resulta sen�o um colar de dentes pendurado no pesco�o de um dos Orcas.\n\nSe voc� quiser usar o colar, \033[1;35mdigite 123.\033[0;37m\nSe preferir partir para o norte sem o colar, \033[1;35mdigite 282.\033[0;37m\n\n");

    while(loop < 1){
        scanf("%i", &choices);
        switch(choices){
            case 123:
                loop++;
                system("cls");
                OP123();
                break;
            case 282:
                loop++;
                system("cls");
                OP282();
                break;
            case 0:
                inventory();
                enter();
                OP338();
                break;
        }
    }
}

//OPCAO 339
void OP339(){
    stageops = 339;
    save();
    loop = 0;

    printf("\t339 - Quando voc� toca a ma�aneta da porta, ela fica mole na sua m�o, e, quando tenta tirar a m�o, descobre que ela est� grudada na ma�aneta. Ent�o, um punho gigantesco se forma no meio da porta e projeta-se na sua dire��o, atingindo-o no est�mago. Voc� perde 1 ponto de ENERGIA.\n\nSe tiver uma moringa de �cido, \033[1;35mdigite 303.\033[0;37m\nSe n�o tiver, \033[1;35mdigite 236.\033[0;37m\n\n");

    printf("Voc� perdeu 1 de ENERGIA\n");
    printf("Sua ENERGIA: %i\n\n", energy - 1);

    while(loop < 1){
        scanf("%i", &choices);
        switch(choices){
            case 236:
                energy -= 1;
                loop++;
                system("cls");
                OP236();
                break;
            case 303:
                loop++;
                energy -= 1;
                if(moringa_acid != 0){
                    system("cls");
                    OP303();
                } else{
                    printf("\nVoc� n�o tem este item.");
                    enter();
                    OP339();
                }
                break;
            case 0:
                inventory();
                enter();
                OP339();
                break;
        }
    }
}

//OPCAO 340
void OP340(){
    printf("\t340 - O medo lhe d� uma nova inje��o de energia, e, de alguma forma, suas pernas cansadas conseguem mant�-lo � frente do rochedo. Adiante, � direita, voc� v� a forma bem-vinda de uma porta. Voc� mergulha de encontro � porta e, por sorte, ela se abre. O rochedo passa estrondoso, e voc� fica deitado, exausto, no ch�o de um aposento grande.");

    enter();
    OP381();
}

//OPCAO 341
void OP341(){
    stageops = 341;
    save();
    loop = 0;

    printf("\t341 - Um homem aleijado, com cadeias nos p�s, arrasta-se na sua dire��o carregando uma bandeja de madeira cheia de p�o e �gua. Ele parece cansado e desalentado, e tenta passar por voc� sem demonstrar rea��o � sua presen�a. Voc�:\n\nFalar� com ele?\033[1;35m Digite 367.\033[0;37m\nPegar� p�o e �gua da bandeja dele? \033[1;35mDigite 38.\033[0;37m\nOferecer� a ele alguma provis�o (se voc� ainda tiver alguma)? \033[1;35mDigite 169.\033[0;37m\n\n  ");
    status_OP341 += 1;
    while(loop < 1){
        scanf("%i", &choices);
        switch(choices){
            case 367:
                loop++;
                system("cls");
                OP367();
                break;
            case 169:
                loop++;
                if(provisions != 0){
                    system("cls");
                    OP169();
                } else{
                    printf("Voc� n�o tem este item.");
                    enter();
                    OP341();
                }
                break;
            case 38:
                loop++;
                system("cls");
                OP038();
                break;
            case 0:
                inventory();
                enter();
                OP341();
                break;
        }
    }
}

//OPCAO 342
void OP342(){
    stageops = 342;
    save();
    loop = 0;

    printf("\t342 - Suas rea��es s�o lentas por causa do veneno e, embora voc� tente pular por cima da l�ngua estendida, suas pernas n�o conseguem ergu�-lo o bastante. A l�ngua pegajosa se enrola na sua perna e come�a a pux�-lo na dire��o da po�a. Voc� � arrastado para o ch�o e n�o consegue desembainhar a espada.\n\nSe voc� tiver um punhal, \033[1;35mdigite 294.\033[0;37m\nSe n�o tiver um punhal, \033[1;35mdigite 334.\033[0;37m\n\n");

    while(loop < 1){
        scanf("%i", &choices);
        switch(choices){
            case 334:
                loop++;
                system("cls");
                OP334();
                break;
            case 294:
                loop++;
                if(dagger != 0){
                    system("cls");
                    OP294();
                } else{
                    printf("Voc� n�o tem este item.");
                    enter();
                    OP342();
                }
                break;
            case 0:
                inventory();
                enter();
                OP342();
                break;
        }
    }
}

//OPCAO 343
void OP343(){
    stageops = 343;
    save();
    loop = 0;

    printf("\t343 - Com vozes esgani�adas, os Trogloditas explicam as regras da Corrida da Flecha. Eles disparar�o uma flecha e voc� poder� caminhar, sem ser atacado, at� o ponto onde ela cair. Por�m, voc� dever� ir descal�o, e o ch�o da caverna, como pode ver, est� coberto de pedras pontiagudas. Logo que voc� chegar � flecha, os Trogloditas come�ar�o a persegui-lo; se o pegarem, voc� ser� morto. De repente, um dos Trogloditas dispara uma flecha bem alto no ar. Ela cai a grande dist�ncia, e, imediatamente, os Trogloditas for�am-no a caminhar na dire��o dela. Enquanto voc� anda devagar na dire��o da flecha, ouve os gritos excitados dos Trogloditas. Ao chegar � flecha voc� se volta e v� os Trogloditas agitarem os bra�os no ar e iniciarem a persegui��o. Voc� corre o mais depressa que pode, os p�s sangrando com os cortes sofridos nas pedras pontiagudas. Voc� perde 1 ponto de ENERGIA. Adiante, um rio subterr�neo, que corre de leste para oeste, cruza a caverna; uma ponte de madeira liga uma margem � outra.\n\nSe voc� quiser atravessar a ponte, \033[1;35mdigite 318.\033[0;37m\nSe quiser mergulhar no rio, \033[1;35mdigite 47.\033[0;37m\n\n");

    printf("Voc� perdeu 1 de ENERGIA");
    printf("\nSua ENERGIA: %i\n\n", energy - 1);

    while(loop < 1){
        scanf("%i", &choices);
        switch(choices){
            case 318:
                energy -= 1;
                loop++;
                system("cls");
                OP318();
                break;
            case 47:
                energy -= 1;
                loop++;
                system("cls");
                OP047();
                break;
            case 0:
                inventory();
                enter();
                OP343();
                break;
        }
    }
}

//OPCAO 344
void OP344(){
    stageops = 344;
    save();
    loop = 0;

    printf("344 - O t�nel faz curvas e reviravoltas, mas continua sempre para o norte. � sua frente, um facho de luz azul desce do teto para o ch�o. Ele fa�sca e cintila, e voc� pode ver imagens de rostos que riem na luz.\n\nSe voc� quiser passar atrav�s da luz, \033[1;35mdigite 229.\033[0;37m\nSe preferir contornar o facho, \033[1;35mdigite 107.\033[0;37m\n\n");
    while(loop < 1){
        scanf("%i", &choices);
        switch(choices){
            case 229:
                loop++;
                system("cls");
                OP229();
                break;
            case 107:
                loop++;
                system("cls");
                OP107();
                break;
            case 0:
                inventory();
                enter();
                OP344();
                break;
        }
    }
}

//OPCAO 345
void OP345(){
    printf("345 - Voc� est� prestes a entrar no aposento quando a Po��o de Detec��o de Cilada come�a a fazer efeito, e voc� � dominado por uma terr�vel premoni��o. H� uma armadilha mortal neste aposento. Voc� resolve n�o entrar e continua para o norte pelo t�nel.");

    enter();
    OP252();
}

//OPCAO 346
void OP346(){
    loop = 0;

    printf("\t346 - Voc� tira a bota do p� e se esfor�a para estend�-la at� o sino e travar-lhe a vibra��o. Aos poucos, o sino vai parando de vibrar, e a dor no seu corpo diminui gradualmente. Voc� consegue se levantar, mas n�o afasta a bota do sino at� que ele esteja completamente im�vel. Voc� cal�a a bota e continua a jornada para o oeste.");

    enter();
    OP362();
}

//OPCAO 347
void OP347(){
    printf("\t347 - O An�o sacode a cabe�a, dizendo: \"S� m�sculos, sem intelig�ncia, n�o bastam para conquistar a Prova dos Campe�es. \033[1;31mSinto dizer que voc� fracassou\033[0;37m. Voc� n�o ter� permiss�o para ir embora, pois poder� revelar os segredos do calabou�o para outros. Todavia, voc� conseguiu muito chegando t�o longe, e eu o indicarei para meu servo pelos anos futuros para preparar o calabou�o para os novos competidores\".");
    death();
}

//OPCAO 348
void OP348(){
    printf("348 - Voc� avan�a sobre a Besta Sangrenta, tentando evitar a l�ngua que se estende para agarrar-lhe a perna. \033[1;33mDigite \"ROLL\" e teste sua SORTE\033[0;37m\n\n");

     while(loop < 1){
        gets(startroll);
        if(strcasecmp(startroll, "roll") == 0){
            dice2();
            if(numroll <= hability){
                system("cls");
                OP225();
            }else{
                system("cls");
                OP159();
            }
        }
    }
}

//OPCAO 349
void OP349(){
    loop = 0;
    monsenergy = 15;
    monshability = 12;

    printf("\t349 - Voc� desce pela corda para o interior do po�o, segurando-se com uma das m�os, enquanto a outra leva a espada desembainhada. O Diabo do Po�o � uma das feras mais terr�veis que voc� j� viu, e voc� sabe que esta ser� uma das lutas mais dif�ceis da sua vida.\n\n\033[1;31mDIABO DO PO�O HABILIDADE 12 ENERGIA 15\033[0;37m\n\n");

    enter();
    combat1();
    printf("\nVoc� derrotou o DIABO DO PO�O!\n");
    printf("Sua HABILIDADE: %i", hability);
    enter();
    OP258();

}

//OPCAO 350
void OP350(){
    loop = 0;

    printf("\t350 - A Mosca Gigante mergulha na sua dire��o e agarra-o com quatro patas. Rapidamente ela retorna ao teto da caverna, e voc� se encontra indefeso pendurado no ar. S�bito, para seu horror, ela o solta. Voc� despenca de 10 metros de altura, estatelando-se no solo.\n\n\033[1;33mDigite \"ROLL\" e teste sua SORTE.\033[0;37m\n\n");

    while(loop < 1){
        gets(startroll);
        if(strcasecmp(startroll, "roll") == 0){
            dice1();
            dards = numroll;
            energy -= dards;
            printf("\n\nVoc� perdeu %d de ENERGIA", dards);
            printf("\nSua ENERGIA: %i", energy);
            if(energy <= 0){
                death();
            } else{
                printf("\n\nVoc� sobreviveu a queda, a tempo de tomando seus sentidos desembainha sua espada contra a investida seguinte da Mosca Gigante");
                enter();
                OP039();
            }
        }
    }
}

//OPCAO 351
void OP351(){
    stageops = 351;
    save();
    loop = 0;

    printf("\t351 - O �dolo � muito liso, e a escalada ser� dif�cil. Voc� tem corda?\n\nSe tiver, \033[1;35mdigite 396.\033[0;37m\nSe n�o tiver, \033[1;35mdigite 186.\033[0;37m\n\n");

    printf("\033[1;34mLEMBRE-SE, VOC� PODE ACESSAR SEU INVENT�RIO DIGITANDO 0\033[0;37m\n\n");

    while(loop < 1){
        scanf("%i", &choices);
        switch(choices){
            case 186:
                loop++;
                system("cls");
                OP186();
                break;
            case 396:
                loop++;
                if(rope != 0){
                    system("cls");
                    OP396();
                } else{
                    printf("\n\033[1;31mVoc� n�o tem este item.\033[0;37m");
                    enter();
                    OP351();
                }
                break;
            case 0:
                inventory();
                enter();
                OP351();
                break;
        }
    }
}

//OPCAO 352
void OP352(){
    stageops = 352;
    save();
    loop = 0;

    printf("\t352 - Voc� ouve o som de rochas sendo trituradas e esmagadas � sua frente. O ru�do cresce e, subitamente, voc� se d� conta de que a parede do seu lado direito come�a a desabar. Apavorado, voc� v� uma enorme e horrorosa criatura, com mand�bulas incrivelmente poderosas, deslizar por um buraco na parede. A enorme boca da criatura mastiga rocha enquanto ela vira a cabe�a devagar de um lado para outro, sentindo o ar fresco do t�nel. O VERME DA ROCHA parece ser cego, mas d� a impress�o de estar ciente de sua presen�a, talvez sentindo o calor de seu corpo. Ele se arrasta na sua dire��o com as mand�bulas bem abertas, pronto para o ataque.\n\nSe voc� quiser lutar contra o Verme da Rocha, \033[1;35mdigite 254.\033[0;37m\nSe preferir correr de volta pelo t�nel para o cruzamento e depois se dirigir para o leste, \033[1;35mdigite 68.\033[0;37m\n\n");

    printf("\033[1;34mLEMBRE-SE, VOC� PODE ACESSAR SEU INVENT�RIO DIGITANDO 0\033[0;37m\n\n");

    while(loop < 1){
        scanf("%i", &choices);
        switch(choices){
            case 254:
                loop++;
                system("cls");
                OP254();
                break;
            case 68:
                loop++;
                system("cls");
                OP068();
                break;
            case 0:
                inventory();
                enter();
                OP352();
                break;
        }
    }

}

//OPCAO 353
void OP353(){
    loop = 0;

    printf("\t353 - Antes que voc� possa sair do caminho, o rochedo se choca contra seu ombro. \033[1;31mVoc� perde 1 ponto de HABILIDADE e 4 pontos de ENERGIA.\033[0;37m\n\n");

    energy -= 4;
    hability -= 1;
    printf("Voc� perdeu 4 de ENERGIA");
    printf("\nSua ENERGIA: %i", energy);
    printf("\n\nVoc� perdeu 1 de HABILIDADE");
    printf("\nSua HABILIDADE: %i", hability);
    if(energy <= 0){
        death();
    }else{
        printf("Voc� sobrevive a pancada");
        enter();
        OP325();
    }
}

//OPCAO 354
void OP354(){
    loop = 0;

    printf("\t354 - A p�lula faz com que voc� se sinta como se o mundo inteiro estivesse contra voc�. E perde 2 pontos de SORTE. O An�o lhe diz que agora voc� pode passar � segunda fase do teste. Ele apanha uma cesta de vime e lhe diz que ela cont�m uma serpente. Vira a cesta e a serpente cai no ch�o. � uma naja, e se ergue no ar, pronta para dar o bote. O An�o lhe diz que pretende testar suas rea��es. Voc� dever� agarrar a naja com as m�os nuas, pelo pesco�o, evitando as presas mortais. Voc� se agacha, tensionando os m�sculos para o momento decisivo.\n\n\033[1;35mDigite \"ROLL\" e teste sua HABILIDADE.\033[0;37m\n\n");

    while(loop < 1){
        gets(startroll);
        if(strcasecmp(startroll, "roll") == 0){
            dice2();
            if(numroll <= hability){
                system("cls");
                OP055();
            }else{
                system("cls");
                OP202();
            }
        }
    }

}

//OPCAO 355
void OP355(){
    printf("\t355 - Voc� se aproxima silenciosamente por tr�s dos Hobglobins que lutam e, saltando das sombras, empurra-os contra a parede e foge correndo. Voc� olha para tr�s e os v� esparramados no ch�o. Rindo, voc� segue depressa para o norte.");

    enter();
    OP110();
}

//OPCAO 356
void OP356(){
    stageops = 356;
    save();
    loop = 0;

    printf("\t356 - H� uma abertura no lado esquerdo da parede do t�nel. Voc� est� de p� na entrada de uma caverna grande, quando ouve uma voz de mulher gritando por socorro. Voc� distingue apenas a forma de uma figura humana que rola pelo ch�o no fundo da caverna.\n\nSe voc� quiser entrar na caverna, \033[1;35mdigite 170.\033[0;37m\nSe preferir continuar para o norte pelo t�nel, \033[1;35mdigite 192.\033[0;37m\n\n");

    printf("\033[1;34mLEMBRE-SE, VOC� PODE ACESSAR SEU INVENT�RIO DIGITANDO 0\033[0;37m\n\n");

    while(loop < 1){
        scanf("%i", &choices);
        switch(choices){
            case 170:
                loop++;
                system("cls");
                OP170();
                break;
            case 192:
                loop++;
                system("cls");
                OP192();
                break;
            case 0:
                inventory();
                enter();
                OP356();
                break;
        }
    }
}

//OPCAO 357
void OP357(){
    stageops = 357;
    save();
    jeweloop = 0;
    loop = 0;

    printf("\t357 - A Besta Sangrenta chafurda na po�a, e o cheiro dos gases venenosos, cujas bolhas sobem � tona e contaminam a atmosfera, provoca �nsias de v�mito. Voc�:\n\nCorrer� contornando a po�a da fera, na dire��o do t�nel? \033[1;35mDigite 255.\033[0;37m\nJogar� uma gema na po�a (se voc� tiver uma)? \033[1;35mDigite 332.\033[0;37m\nAtacar� a fera com sua espada? \033[1;35mDigite 180.\033[0;37m\n\n");

    printf("\033[1;34mLEMBRE-SE, VOC� PODE ACESSAR SEU INVENT�RIO DIGITANDO 0\033[0;37m\n\n");
    
    while(loop < 1){
        scanf("%i", &choices);
        switch(choices){
            case 255:
                loop++;
                system("cls");
                OP255();
                break;
            case 332:
                loop++;
                printf("\n\nJOIAS COLETADAS:\n");
                if(emerald == 0 && jewel == 0 && sapphire == 0 && diamond == 0 && ruby == 0 && topaz == 0){
                    printf("\n\033[1;31mVoc� n�o possui JOIAS\033[0;37m");
                    enter();
                    OP357();
                }if(emerald != 0)
                    printf("\nEsmeralda: x%d, se deseja jogar fora esta joia digite \033[1;33m\"1\"\033[0;37m", emerald);
                if(diamond != 0)
                    printf("\nDiamante: x%d, se deseja jogar fora esta joia digite \033[1;33m\"2\"\033[0;37m", diamond);
                if(ruby != 0)
                    printf("\nRubi: x%d, se deseja jogar fora esta joia digite \033[1;33m\"3\"\033[0;37m", ruby);
                if(topaz != 0)
                    printf("\nTopazio: x%d, se deseja jogar fora esta joia digite \033[1;33m\"4\"\033[0;37m", topaz);
                if(sapphire != 0)
                    printf("\nSafira: %d, se deseja jogar fora esta joia digite \033[1;33m\"5\"\033[0;37m", sapphire);
                if(jewel != 0)
                    printf("\nJoia: x%d, se deseja jogar fora esta joia digite \033[1;33m\"6\"\033[0;37m", jewel);
                
                printf("\n");
                while(jeweloop < 1){
                    scanf("%d", &invuse);
                    switch (invuse)
                    {
                    case 1:
                        jeweloop++;
                        emerald -= 1;
                        break;
                    case 2:
                        jeweloop++;
                        diamond -= 1;
                        break;
                    case 3:
                        jeweloop++;
                        ruby -= 1;
                        break;
                    case 4:
                        jeweloop++;
                        topaz -= 1;
                        break;
                    case 5:
                        jeweloop++;
                        sapphire -= 1;
                        break;
                    case 6:
                        jeweloop++;
                        jewel -= 1;
                        break;
                    }
                }
                printf("A joia selecionada foi jogada ao po�o");
                enter();
                OP332();
                break;
            case 180:
                loop++;
                system("cls");
                OP180();
            case 0:
                inventory();
                enter();
                OP357();
                break;
        }
    }
}

//OPCAO 358
void OP358(){
    printf("\t358 - Voc� perde o equil�brio e despenca de cabe�a no ch�o. \033[1;31mPerde 2 pontos de ENERGIA.\033[0;37m Voc� desiste de tentar escalar o �dolo e corre para seguir pelo t�nel na parede norte.\n\n");

    printf("Voc� perdeu 2 de ENERGIA\n");
    printf("\nSua ENERGIA: %i", energy);
    enter();
    OP239();
}

//OPCAO 359
void OP359(){
    printf("\t359 - Voc� cai da corda e despenca de cabe�a na fenda. \033[1;31mBate com a cabe�a em uma sali�ncia rochosa e morre antes de chegar ao fundo da fenda.\033[0;37m");
    death();
}

//OPCAO 360
void OP360(){
    stageops = 360;
    save();
    loop = 0;

    printf("\t360 - Depois de pagar, voc� sobe na cesta de vime. O velho grita, jogando a cabe�a para tr�s: \"Puxa, Erva!\" A corda se retesa, e a cesta se ergue aos solavancos. Enquanto voc� est� sendo1 i�ado cada vez mais alto, o velho lhe grita: \"Voc� vai gostar de Erva, ela � uma �tima garota. N�s a chamamos de Erva Venenosa!\" Ele ri descontrolado, e voc�, um tanto apreensivo, se pergunta quem o est� i�ando. A cesta passa por um buraco no teto, e voc� se v� em um pequeno quarto, frente a frente com uma mulher TROLL feia e velha. Ela tem o rosto peludo e coberto de verrugas. Com uma enorme m�o ela o puxa para fora da cesta, a qual deixa cair l� embaixo. Em seguida, agarra-o pela garganta e lhe diz, numa voz rouca: \"Quero pagamento tamb�m!\" Voc�:\n\nOferecer� a ela alguma coisa da sua mochila? \033[1;35mDigite 297.\033[0;37m\nTentar� convenc�-la a n�o cobrar nada de voc�? \033[1;35mDigite 328.\033[0;37m\nAtacar� a mulher com sua espada? \033[1;35mDigite 211.\033[0;37m\n\n");

    printf("\033[1;34mLEMBRE-SE, VOC� PODE ACESSAR SEU INVENT�RIO DIGITANDO 0\033[0;37m\n\n");

    while(loop < 1){
        scanf("%i", &choices);
        switch(choices){
            case 297:
                loop++;
                system("cls");
                OP297();
                break;
            case 328:
                loop++;
                system("cls");
                OP328();
                break;
            case 211:
                loop++;
                system("cls");
                OP211();
                break;
            case 0:
                inventory();
                enter();
                OP360();
                break;
        }
    }
}

//OPCAO 361
void OP361(){
    loop = 0;

    printf("\t361 - As mand�bulas do Diabo do Po�o d�o um bote no amuleto de macaco e o apanham no ar, mas logo se abrem de novo, for�adas pelo amuleto, que se expandiu a ponto de ocupar toda a boca da fera. Enquanto o Diabo do Po�o se debate, tentando livrar-se do amuleto, voc� desce at� o fundo para chegar �s portas duplas. Desvairado, o Diabo do Po�o usa o imenso corpo na tentativa de esmagar voc� contra a parede.\033[1;33m\n\nDigite \"ROLL\" e teste sua SORTE.\033[0;37m\n\n");

    while(loop < 1){
        gets(startroll);
        if(strcasecmp(startroll, "roll") == 0){
            dice2();
            if(numroll <= luck){
                luck--;
                system("cls");
                OP082();
            }else{
                luck--;
                system("cls");
                OP377();
            }
        }
    }

}

//OPCAO 362
void OP362(){
    printf("\t362 - O t�nel d� uma guinada acentuada para a direita e continua para o norte at� onde a vista alcan�a. A dist�ncia, voc� ouve uma tremenda como��o: grunhidos, rosnados, uivos. Voc� desembainha a espada e parte na dire��o do tumulto.");

    enter();
    OP264();
}

//OPCAO 363
void OP363(){
    loop = 0;

    printf("\t363 - A comida e a bebida s�o excelentes, e voc� se sente muito melhor.\033[1;32m Acrescente 2 pontos de ENERGIA.\033[0;37m Plenamente satisfeito, voc� senta e espera a volta do An�o.\n\n");

    if(status_OP363 == 0){
        energy += 2;
        status_OP363 += 1;
        printf("Voc� recebeu 2 de ENERGIA");
        printf("\nSua ENERGIA: %i", energy);
        enter();
        OP302();
    }else{
        printf("\033[1;31mVoc� j� esteve aqui, nada foi adicionado ao seu invent�rio.\033[0;37m\n\n");
        enter();
        OP302();
    }
}

//OPCAO 364
void OP364(){
    stageops = 364;
    save();
    loop = 0;

    printf("\t364 - Enquanto remove o sangue do Mant�cora de sua espada, voc� leva um susto ao ver um homenzinho com um nariz grande saltar de tr�s de um dos pilares de m�rmore. Ele veste uma t�nica justa, verde, e parece inofensivo, embora voc� fique desconfiado do modo como ele segura uma bola de vidro opaco com uma luz verde cintilante. \"Meus cumprimentos!\", ele diz animadamente. \"Meu nome � Igbut, o Gnomo, e sou o Juiz da Prova para seu teste final. N�o � preciso dizer que meus poderes m�gicos s�o grandes, por isso voc� n�o deve tentar me atacar. Talvez voc� tenha sabido, durante a sua jornada, que as gemas desempenham um papel essencial na Prova dos Campe�es. A porta de ferro � sua frente � a sa�da para a vit�ria, mas s� h� uma maneira de abri-la. � preciso p�r tr�s gemas no mecanismo da fechadura, numa ordem espec�fica. Cada gema irradia uma energia que acionar� o mecanismo, se voc� as colocar corretamente, � claro. Eu o ajudarei de certa forma, mas primeiro precisamos das gemas certas. Voc� tem uma esmeralda?\".\n\nSe voc� tiver uma esmeralda, \033[1;35mdigite 31.\033[0;37m\nSe n�o tiver, \033[1;35mdigite 3.\033[0;37m\n\n");

    while(loop < 1){
        scanf("%i", &choices);
        switch(choices){
            case 3:
                loop++;
                system("cls");
                OP003();
                break;
            case 31:
                loop++;
                if(emerald != 0){
                    system("cls");
                    OP031();
                } else{
                    printf("Voc� n�o tem este item.");
                    enter();
                    OP134();
                }
                break;
            case 0:
                inventory();
                enter();
                OP364();
                break;
        }
    }
}

//OPCAO 365
void OP365(){
    stageops = 365;
    save();
    loop = 0;

    printf("\t365 - Voc� diz a Throm que matar o An�o n�o vai adiantar nada, pois voc�s jamais achar�o a sa�da da c�mara sozinhos. Voc� argumenta que talvez surja uma chance de enganar o An�o mais tarde, quando tiverem descoberto a sa�da da c�mara, por isso voc� pretende ir adiante com o teste do An�o. Voc� diz ao An�o que est� pronto, e ele acena para que o siga. Throm deve aguardar a volta dele. Uma porta secreta abre-se na parede da c�mara, e voc� segue o An�o at� um pequeno aposento circular. Ele fecha a porta atr�s de voc� e lhe entrega dois dados de osso, mandando que os jogue no ch�o. Voc� tira um seis e um dois: total, oito. O An�o pede que voc� os jogue mais uma vez, mas, agora, deve adivinhar se o total ser� igual, menor ou maior que oito.\n\nSe seu palpite for que ser� igual, \033[1;35mdigite 290.\033[0;37m\nSe achar que ser� menor que oito, \033[1;35mdigite 191.\033[0;37m\nSe optar por maior que oito, \033[1;35mdigite 84.\033[0;37m\n\n");

    printf("\033[1;34mLEMBRE-SE, VOC� PODE ACESSAR SEU INVENT�RIO DIGITANDO 0\033[0;37m\n\n");

    while(loop < 1){
        scanf("%i", &choices);
        switch(choices){
            case 290:
                loop++;
                system("cls");
                OP290();
                break;
            case 191:
                loop++;
                system("cls");
                OP191();
                break;
            case 84:
                loop++;
                system("cls");
                OP084();
                break;
            case 0:
                inventory();
                enter();
                OP365();
                break;
        }
    }

}

//OPCAO 366
void OP366(){
    printf("\t366 - A temperatura continua a subir, muito al�m dos limites de toler�ncia humanos. Estendido no ch�o quase derretido do t�nel, voc� n�o consegue recuperar a consci�ncia. \033[1;31mSua aventura termina aqui.\033[0;37m");
    death();
}

//OPCAO 367
void OP367(){
    stageops = 367;
    save();
    loop = 0;

    printf("\t367 - Ele o encara desconfiado quando voc� diz que � um competidor na Prova dos Campe�es. Voc� pergunta a ele o que faz nos t�neis, e ele lhe responde, um tanto relutante, que � servo de um dos Ju�zes da Prova, os controladores das diferentes partes do calabou�o designados pelo Bar�o Sukumvit. Depois de alguma conversa, ele admite que gostaria de fugir, mas ningu�m pode sair do calabou�o, pois poderia revelar os segredos da constru��o. Ele espera conseguir sair dali mediante suborno, e, por uma Pe�a de Ouro, poder� dizer-lhe onde h� um tesouro escondido.\n\nSe voc� quiser pagar pela orienta��o do velho, \033[1;35mdigite 244.\033[0;37m\nSe preferir simplesmente desejar-lhe o melhore continuar para o oeste, \033[1;35mdigite 109.\033[0;37m\n\n");

    printf("\033[1;34mLEMBRE-SE, VOC� PODE ACESSAR SEU INVENT�RIO DIGITANDO 0\033[0;37m\n\n");

    while(loop < 1){
        scanf("%i", &choices);
        switch(choices){
            case 244:
                loop++;
                system("cls");
                OP244();
                break;
            case 109:
                loop++;
                system("cls");
                OP109();
                break;
            case 0:
                inventory();
                enter();
                OP367();
                break;
        }
    }
}

//OPCAO 368
void OP368(){
    stageops = 368;
    save();
    loop = 0;

    printf("\t368 - Voc� v� um par de pernas-de-pau junto � parede do lado esquerdo do t�nel. Elas est�o firmemente acorrentadas, e num aviso preso a um cadeado l�-se: \"O pre�o destas pernas-depau � uma Pe�a de Ouro. Coloque a moeda na ranhura para abrir o cadeado.\"\n\nSe voc� quiser comprar as pernas-de-pau, \033[1;35mdigite 165.\033[0;37m\nSe preferir prosseguir para o norte, \033[1;35mdigite 234.\033[0;37m\n\n");

    printf("\033[1;34mLEMBRE-SE, VOC� PODE ACESSAR SEU INVENT�RIO DIGITANDO 0\033[0;37m\n\n");

    while(loop < 1){
        scanf("%i", &choices);
        switch(choices){
            case 165:
                loop++;
                system("cls");
                OP165();
                break;
            case 234:
                loop++;
                system("cls");
                OP234();
                break;
            case 0:
                inventory();
                enter();
                OP368();
                break;
        }
    }
}

//OPCAO 369
void OP369(){
    loop = 0;
    monsenergy = 11;
    monshability = 10;

    printf("\t369 - O t�nel faz uma curva fechada para a direita, continuando para o leste at� onde a vista alcan�a. Throm p�ra e lhe diz que fa�a o mesmo. Ele vira a cabe�a devagar de um lado para o outro: \"Ou�o passos descendo pelo t�nel na nossa dire��o\", ele sussurra. \"Desembainhe a espada.\" Voc�s se agacham para se esconder nas sombras, e bem a tempo: duas figuras armadas se aproximam. Throm salta e brada um grito de guerra. Dois TROLLS DA CAVERNA est�o diante de voc�s. Throm ataca o primeiro com a acha de guerra, e voc� corre para ajud�-lo, atacando o segundo Troll da Caverna.\033[1;31m\n\nTROLL DA CAVERNA HABILIDADE 10 ENERGIA 11\n\n\033[0;37m");

    enter();
    combat1();
    printf("\n\nVoc� derrotou o TROLL DA CAVERNA");
    printf("\nSua ENERGIA: %i", energy);
    enter();
    OP288();
}

//OPCAO 370
void OP370(){
    loop = 0;

    printf("370 - Quando voc� contorna a po�a correndo, a Besta Sangrenta estende a l�ngua comprida mais uma vez.\033[1;33m\n\nDigite \"ROLL\" e teste sua HABILIDADE.\n\n\033[0;37m");

    while(loop < 1){
        gets(startroll);
        if(strcasecmp(startroll, "roll") == 0){
            dice2();
            if(numroll <= hability){
                system("cls");
                OP104();
            }else{
                system("cls");
                OP342();
            }
        }
    }
}

//OPCAO 371
void OP371(){
    loop = 0;

    printf("\t371 - Voc� faz pontaria e joga a bola de madeira no cr�nio.\033[1;33m\n\nDigite \"ROLL\" e teste sua HABILIDADE.\n\n\033[0;37m");

    while(loop < 1){
        gets(startroll);
        if(strcasecmp(startroll, "roll") == 0){
            dice2();
            if(numroll <= hability){
                system("cls");
                OP237();
            }else{
                system("cls");
                OP113();
            }
        }
    }
}

//OPCAO 372
void OP372(){
    printf("\t372 - Voc� finalmente chega ao corpo do guerreiro, mas, logo que toca na j�ia, tanto ela quanto o guerreiro desaparecem como num passe de m�gica. A porta bate atr�s de voc�, e segue-se um estrondo agourento acima da sua cabe�a. Voc� olha para o alto e v� o teto baixando. Corre para a porta na tentativa de escapar, mas ela est� trancada e n�o h� ma�aneta do lado de dentro. O teto vai descendo, e voc� � obrigado a se deitar no ch�o, tentando impedir o movimento do teto comas m�os e os p�s. \033[1;31mMas o esfor�o � in�til, e voc� � esmagado entre os blocos de pedra.\033[0;37m");
    death();
}

//OPCAO 373
void OP373(){
    printf("\t373 - Voc� sobe pelo rochedo macio, temendo ser absorvido por ele a qualquer momento. � dif�cil passar por cima da coisa, pois seus membros afundam na casca mole, mas, por fim, voc� consegue chegar ao outro lado. Aliviado por estar de novo em terreno firme, voc� se dirige para o leste.");

    enter();
    OP013();
}

//OPCAO 374
void OP374(){
    loop = 0;

    printf("\t374 - Voc� caminha pela caverna, mas n�o acha nada interessante. Throm o chama l� de tr�s, dizendo que encontrou um saco de couro sob uma pilha de rochas. Abrindo o saco, Throm ri alto quando um min�sculo camundongo corre entre os dedos dele e foge para uma fresta entre dois rochedos. A s�bitas, voc� ouve o som de rocha rachando: estalactites se desprendem do teto, como resultado da vibra��o causada pelo riso retumbante de Throm, que ainda ecoa pela caverna. Voc� berra para que Throm fuja pela passagem em arco, enquanto as estalactites desabam.\033[1;33m\n\nDigite \"ROLL\" e teste sua SORTE.\033[0;37m\n\n");

    while(loop < 1){
        gets(startroll);
        if(strcasecmp(startroll, "roll") == 0){
            dice2();
            if(numroll <= luck){
                luck--;
                system("cls");
                OP118();
            }else{
                luck--;
                system("cls");
                OP295();
            }
        }
    }
}

//OPCAO 375
void OP375(){
    printf("375 - Uma fuma�a acre emana da moringa quando voc� enfia o pano nela. O l�quido � indubitavelmente �cido. Voc� arrolha a moringa de novo e a coloca na mochila, esperando que venha a ter utilidade mais tarde. Voc� recoloca a espada na bainha e prossegue rumo ao norte.\n\n");

    if(status_OP375 == 0){
        moringa_acid += 1;
        status_OP375 += 1;
        printf("�cido de Moringa foi adicionado a seu invent�rio");
        enter();
        OP110();
    }else{
        printf("\033[1;31mVoc� j� esteve aqui, nada foi adicionado ao seu invent�rio.\033[0;37m\n\n");
        enter();
        OP110();
    }
}

//OPCAO 376
void OP376(){
    stageops = 376;
    save();
    loop = 0;

    printf("376 - O Gnomo, ainda sorrindo, lhe diz, excitado: \"Excelente! S� falta uma. Voc� possui um diamante?\"n\\nSe voc� tiver encontrado um diamante, \033[1;35mdigite 62.\033[0;37m\nSe n�o tiver encontrado um diamante, \033[1;35mdigite 3.\033[0;37m\n\n");

    printf("\033[1;34mLEMBRE-SE, VOC� PODE ACESSAR SEU INVENT�RIO DIGITANDO 0\033[0;37m\n\n");

    while(loop < 1){
        scanf("%i", &choices);
        switch(choices){
            case 3:
                loop++;
                system("cls");
                OP003();
                break;
            case 62:
                loop++;
                if(diamond != 0){
                    system("cls");
                    OP062();
                } else{
                    printf("\n\nVoc� n�o tem este item.");
                    enter();
                    OP376();
                }
                break;
            case 0:
                inventory();
                enter();
                OP376();
                break;
        }
}
}
//OPCAO 377
void OP377(){
    loop = 0;

    printf("377 - A imensa fera atira o corpo contra o seu bra�o, e voc� solta a corda. Gritando de dor, voc� despenca no fundo do po�o e \033[1;31mperde 5 pontos de ENERGIA.\033[0;37m\n\n");

    energy -= 5;
    printf("Voc� perdeu 5 de ENERGIA");
    printf("\nSua ENERGIA: %i", energy);
    if(energy <= 0){
        death();
    } else{
        printf("\n\nVoc� sobreviveu ao ataque da fera");
        enter();
        OP203();
    }

}

//OPCAO 378
void OP378(){
    loop = 0;

    printf("378 - Um tanto nervoso, voc� respira fundo e mergulha na po�a escura. A parede norte n�o se projeta muito longe, sob a superf�cie da �gua, e voc� resolve se arriscar e nadar por baixo dela. Logo come�a a sentir falta de ar e � obrigado a voltar � tona. Voc� tenta n�o pensar que pode estar aprisionado em um velho t�nel submerso e fica aliviado quando emerge e encontra ar puro. Voc� est� do outro lado da parede e pode ver o t�nel saindo da �gua e continuando para o norte. Saindo da �gua, voc� verifica o conte�do da mochila molhada.\n\n\033[1;33mDigite \"ROLL\" e teste sua SORTE\033[0;37m\n\n");

    while(loop < 1){
        gets(startroll);
        if(strcasecmp(startroll, "roll") == 0){
            dice2();
            if(numroll <= luck){
                luck--;
                system("cls");
                OP112();
            }else{
                luck--;
                system("cls");
                OP209();
            }
        }
    }
}

//OPCAO 379
void OP379(){
    stageops = 379;
    save();
    loop = 0;

    printf("379 - Exaurido pelo longo duelo, voc� cai de joelhos. Ao olhar para o corpo im�vel de Throm, um �dio amargo ao An�o enche-lhe o cora��o. De alguma forma, voc� vingar� Throm. Envolvido pela raiva, n�o repara que o An�o entra na arena, at� que ele chega diante de voc�, uma besta carregada apontada para o seu peito. \"Sei o que voc� est� pensando\", ele diz calmamente, \"Mas n�o se esque�a que s� eu sei o modo de sair daqui. Levante-se, est� na hora de voc� ir embora.\" O An�o indica que voc� deve andar � frente dele. De volta � c�mara, ele vai at� a parede norte e empurra uma das pedras que a comp�em. Um peda�o da parede, semelhante a uma porta, gira, abrindo-se para um t�nel iluminado por cristais. Com a besta ainda apontada para o seu peito, o An�o sorri, dizendo: \"Boa sorte.\"\n\nSe voc� quiser caminhar direto para o t�nel, \033[1;35mdigite 213.\033[0;37m\nSe preferir desferir um soco no An�o, \033[1;35mdigite 145.\033[0;37m\n\n");

    printf("\033[1;34mLEMBRE-SE, VOC� PODE ACESSAR SEU INVENT�RIO DIGITANDO 0\033[0;37m\n\n");

    while(loop < 1){
        scanf("%i", &choices);
        switch(choices){
            case 213:
                loop++;
                system("cls");
                OP213();
                break;
            case 145:
                loop++;
                system("cls");
                OP145();
                break;
            case 0:
                inventory();
                enter();
                OP379();
                break;
        }
    }
}

//OPCAO 380
void OP380(){
    loop = 0;
    monsenergy = 5;
    monshability = 5;

    printf("\t380 - A ma�a de ferro do Orca se choca contra o escudo e resvala sem causar dano. O t�nel � estreito demais para que os dois o ataquem ao mesmo tempo, por isso voc� pode lutar com um de cada vez.\n\n\033[1;31mPrimeiro ORCA HABILIDADE 5 ENERGIA 5\nSegundo ORCA HABILIDADE 6 ENERGIA 4\033[0;37m\n\n");

    enter();
    combat1();
    printf("\nSua ENERGIA: %i\n", energy);
    printf("Voc� matou a PRIMEIRA ORCA! Se prepare para o seu segundo combate.\n\n");
    loop = 0;
    monsenergy = 4;
    monshability = 6;
    enter();
    combat1();
    printf("\nSua ENERGIA: %i\n", energy);
    printf("Voc� matou a SEGUNDA ORCA!\n\nVoc� venceu a batalha!");
    enter();
    OP257();
}

//OPCAO 381
void OP381(){
    stageops = 381;
    save();
    loop = 0;

    printf("381 - Voc� olha em volta no aposento e nada v� de interesse, exceto a alcova na parede do oeste e uma cadeira de pedra no meio do aposento, na qual se encontra sentado o esqueleto de um guerreiro armado, possivelmente um concorrente de anos atr�s. Os dedos descamados da m�o direita est�o fechados em torno de um peda�o de pergaminho.\n\nSe voc� quiser pegar o pergaminho do esqueleto, \033[1;35mdigite 331.\033[0;37m\nSe preferir caminhar at� a alcova, \033[1;35mdigite 128.\033[0;37m\n\n");

    printf("\033[1;34mLEMBRE-SE, VOC� PODE ACESSAR SEU INVENT�RIO DIGITANDO 0\033[0;37m\n\n");

    while(loop < 1){
        scanf("%i", &choices);
        switch(choices){
            case 331:
                loop++;
                system("cls");
                OP331();
                break;
            case 128:
                loop++;
                system("cls");
                OP128();
                break;
            case 0:
                inventory();
                enter();
                OP381();
                break;
        }
    }

}

//OPCAO 382

void OP382(){
    stageops = 382;
    save();
    loop = 0;

    printf("\t382 - O velho aponta para uma das est�tuas, e voc� logo a reconhece. � o cavaleiro que iniciou a Prova dos Campe�es, um olhar de agonia registrado na pedra para toda a eternidade. O velho sorri, dizendo: \"Este homem pesa 50 kg mais a metade do peso dele. Quanto ele pesa?\" O que voc� responder�?\n\n50 quilos? \033[1;35mDigite 144.\033[0;37m\n75 quilos? \033[1;35mDigite 227.\033[0;37m\n100 quilos? \033[1;35mDigite 391\033[0;37m\n\n");

    printf("\033[1;34mLEMBRE-SE, VOC� PODE ACESSAR SEU INVENT�RIO DIGITANDO 0\033[0;37m\n\n");

    while(loop < 1){
        scanf("%i", &choices);
        switch(choices){
            case 144:
                loop++;
                system("cls");
                OP144();
                break;
            case 227:
                loop++;
                system("cls");
                OP227();
                break;
            case 391:
                loop++;
                system("cls");
                OP391();
                break;
            case 0:
                inventory();
                enter();
                OP382();
                break;
        }
    }
}

//OPCAO 383

void OP383(){
    printf("Para sua grande surpresa, nada de extraordin�rio lhe acontece enquanto est� sentado na cadeira. Nada h� a fazer sen�o continuar para o norte pelo t�nel.");

    enter();
    OP188();
}

//OPCAO 384

void OP384(){
    printf("O quarto degrau cede sob seu peso. Sua perna afunda num buraco e, antes que voc� tenha tempo de retira-la, sente uma terr�vel dor no p� quando dentes que n�o pode ver cravam-se nele. Os guinchos agudos que voc� ouve l� embaixo s�o produzidos por ratazanas. Elas est�o famintas e arrancam-lhe peda�os do p�, ansiosas pela sua carne. Voc� perde 2 pontos de ENERGIA. Voc� recupera o equil�brio e consegue tirar a perna do buraco. Tr�s ratazanas ainda se penduram pelos dentes no seu p�. Chutando freneticamente, voc� bate com as cabe�as delas contra o corrim�o at� que se soltem. Voc� ent�o enrola bandagens improvisadas com sua camisa rasgada em torno do p� que sangra e sobe os degraus para partir para o norte de novo.\n\n");

    energy -= 2;
    printf("Voc� perdeu 2 de ENERGIA");
    printf("\n\nSua ENERGIA: %i", hability);
    enter();
    OP277();
}

//OPCAO 385

void OP385(){
    stageops = 385;
    save();
    loop = 0;

    printf("Voc� derrama o conte�do do frasco de vidro na boca e engole o l�quido claro. Embora n�o sinta qualquer mudan�a imediata, voc� espera que a po��o crie a ilus�o de que voc� � um TROGLODITA igual aos outros diante de voc�. Respirando fundo, penetra decididamente na caverna. Os Trogloditas continuam com sua dan�a tribal, acreditando que voc� � um deles. Voc� passa por eles andando naturalmente e segue para o norte. Infelizmente, os efeitos da po��o s�o de curta dura��o, e voc� ouve um berro atr�s de si, quando um dos Trogloditas repara em voc�, que � for�ado a correr, atravessando a caverna. Adiante, voc� v� um rio subterr�neo que corre de leste para oeste, cruzando a caverna, e uma ponte que liga uma margem � outra.\n\nSe voc� quiser correr pela ponte, \033[1;35mdigite 318.\033[0;37m\nSe preferir mergulhar no rio, \033[1;35mdigite 47.\033[0;37m\n\n");

    printf("\033[1;34mLEMBRE-SE, VOC� PODE ACESSAR SEU INVENT�RIO DIGITANDO 0\033[0;37m\n\n");

    while(loop < 1){
        scanf("%i", &choices);
        switch(choices){
            case 318:
                loop++;
                system("cls");
                OP318();
                break;
            case 47:
                loop++;
                system("cls");
                OP047();
                break;
            case 0:
                inventory();
                enter();
                OP385();
                break;
        }
    }
}

//OPCAO 386

void OP386(){
    printf("\t386 - Voc� n�o chega a percorrer mais de tr�s metros para o oeste antes de se chocar contra uma barreira invis�vel. Ela estala e solta fa�scas, e voc� � repelido. Voc� colidiu com uma parede magn�tica. \033[1;31mVoc� perde 1 ponto de ENERGIA\033[0;37m. N�o h� outra alternativa sen�o voltar para a encruzilhada e seguir para o norte.\n\n");

    energy -= 1;
    printf("Voc� perdeu 1 de ENERGIA");
    printf("\nSua ENERGIA: %i", energy);
    enter();
    OP218();

}

//OPCAO 387

void OP387(){
    loop = 0;
    monsenergy = 7;
    monshability = 7;

    printf("Da sua frente vem o baque de passos pesados que se aproximam. Da penumbra surge um ser grande e primitivo, vestido com uma pele de animal e carregando uma clava de madeira. Ao v�-lo, ele grunhe e cospe no ch�o, em seguida ergue a clava e avan�a na sua dire��o, com um ar nada amig�vel. Voc� desembainha a espada e se prepara para enfrentar o HOMEM DA CAVERNA.\n\n\033[1;31mHOMEM DA CAVERNA HABILIDADE 7 ENERGIA 7\033[0;37m\n\n");

    enter();
    combat1();
    printf("Voc� derrotou o HOMEM DA CAVERNA!\n");
    printf("\nSua ENERGIA: %i", energy);
    enter();
    OP114();

}

//OPCAO 388

void OP388(){
    stageops = 388;
    save();
    loop = 0;

    printf("O t�nel logo chega a um beco sem sa�da. Um peda�o de papel, escurecido e enrugado de t�o velho, est� pregado na parede do fundo.\n\nSe voc� quiser peg�-lo para ver se cont�m alguma mensagem, \033[1;35mdigite 23\033[0;37m.\nSe preferir apressar-se a voltar pelo t�nel para reunir-se ao B�rbaro, \033[1;35mdigite 154.\033[0;37m");

    printf("\033[1;34mLEMBRE-SE, VOC� PODE ACESSAR SEU INVENT�RIO DIGITANDO 0\033[0;37m\n\n");

    while(loop < 1){
        scanf("%i", &choices);
        switch(choices){
            case 23:
                loop++;
                system("cls");
                OP023();
                break;
            case 154:
                loop++;
                system("cls");
                OP154();
                break;
            case 0:
                inventory();
                enter();
                OP388();
                break;
        }
    }
}

//OPCAO 389

void OP389(){
    printf("Sem suas armas voc� est� mais vulner�vel, e a perda da espada faz com que se sinta praticamente nu.\033[1;31m Voc� perde 4 pontos de HABILIDADE\033[0;37m. Questionando se tomou a decis�o correta, voc� segue pelo t�nel para o norte.\n\n");

    printf("\033[1;34mVoc� perdeu 4 de HABILIDADE\033[0;37m");
    printf("\nSua HABILIDADE: %i", hability);
    enter();
    OP181();
}

//OPCAO 390

void OP390(){
    stageops = 390;
    save();
    loop = 0;

    printf("Voc� se agacha ao lado do pedestal, abaixo da linha de fogo das bestas. Estica a m�o e puxa o cr�nio do pedestal, esperando que sua a��o fa�a as bestas dispararem. Para sua grande surpresa, nada acontece. Some 1 ponto de SORTE. Ainda agachado, voc� arranca as j�ias que formam os olhos do cr�nio. Voc� identifica as pedras amarelas - top�zios - e as coloca na mochila. Olhando para a s�rie de bestas, pergunta-se se ainda h� uma armadilha � sua espera no aposento. Voc�:\n\nEngatinha para fora do aposento, levando o cr�nio? \033[1;35mDigite 15.\033[0;37m\nRecoloca o cr�nio no pedestal antes de engatinhar para fora do aposento? \033[1;35mDigite 204.\033[0;37m\n\n");

    printf("\033[1;34mLEMBRE-SE, VOC� PODE ACESSAR SEU INVENT�RIO DIGITANDO 0\033[0;37m\n\n");

    while(loop < 1){
        scanf("%i", &choices);
        switch(choices){
            case 15:
                loop++;
                system("cls");
                OP015();
                break;
            case 204:
                loop++;
                system("cls");
                OP204();
                break;
            case 0:
                inventory();
                enter();
                OP390();
                break;
        }
    }
}

//OPCAO 391

void OP391(){
    printf("Ainda sorrindo, o velho olha para voc� e diz: \"Muito bem, Estranho. Voc� respondeu corretamente. Desejo-lhe boa sorte durante o resto da Prova dos Campe�es, e, com este objetivo, aumentarei seus poderes.\" Ele ent�o murmura mais umas poucas palavras inintelig�veis, e voc� sente um impulso poderoso percorrer-lhe o corpo. \033[1;32mAcrescente 1 ponto a cada um dos seus �ndices de HABILIDADE, ENERGIA e SORTE.\033[0;37m Voc� diz adeus ao velho e sai do aposento para continuar para o norte pela passagem.\n\n");

    if(status_OP391 == 0){
        luck += 1;
        energy += 1;
        hability += 1;
        status_OP391 += 1;
        printf("\033[1;33mVoc� recebeu 1 de SORTE\n");
        printf("\033[1;32mVoc� recebeu 1 de ENERGIA\n");
        printf("\033[1;31mVoc� recebeu 1 de HABILIDADE\n\n");
        printf("\033[0;37mSua SORTE: %i", luck);
        printf("\nSua ENERGIA: %i", energy);
        printf("\nSua HABILIDADE: %i", hability);
        enter();
        OP100();
    }else{
        printf("\033[1;31mVoc� j� esteve aqui, nada foi adicionado ao seu invent�rio.\033[0;37m\n\n");
        enter();
        OP100();
    }
}

//OPCAO 392

void OP392(){
    stageops = 392;
    save();
    loop = 0;

    printf("Voc� s� tem tempo de ouvir o Gnomo dizer: \"Tr�s cr�nios\", antes que um raio branco de energia seja disparado da fechadura e atinja-lhe o peito, derrubando-o sem sentidos. Digite \"ROLL\" e role um dado, o resultado somado 1 � reduzido de sua ENERGIA.");

    while(loop < 1){
        gets(startroll);
        if(strcasecmp(startroll, "roll") == 0){
            dice1();
            if(numroll > 0){
                energy = energy - (numroll + 1);
                printf("Sua ENERGIA: %i", energy);
            }
            if(energy > 0){
                printf("\n\nVoc� recupera os sentidos e ouve o Gnomo ordenar que tente de novo. Voc� n�o acertou nenhuma das gemas, por isso n�o tentar� essa combina��o de novo.\n\n    A         B         C     \nEsmeralda|Diamante |Safira    -> \033[1;35mDigite 16.\033[0;37m\nDiamante |Safira   |Esmeralda -> \033[1;35mDigite 392.\033[0;37m\nSafira   |Esmeralda|Diamante  -> \033[1;35mDigite 177.\033[0;37m\nEsmeralda|Safira   |Diamante  -> \033[1;35mDigite 287.\033[0;37m\nDiamante |Esmeralda|Safira    -> \033[1;35mDigite 132.\033[0;37m\nSafira   |Diamante |Esmeralda -> \033[1;35mDigite 249.\033[0;37m\n\n");

                printf("\033[1;34mLEMBRE-SE, VOC� PODE ACESSAR SEU INVENT�RIO DIGITANDO 0\033[0;37m\n\n");

                scanf("%i", &choices);
                switch(choices){
                    case 16:
                        loop++;
                        system("cls");
                        OP016();
                        break;
                    case 392:
                        loop++;
                        system("cls");
                        OP392();
                        break;
                    case 177:
                        loop++;
                        system("cls");
                        OP177();
                        break;
                    case 287:
                        loop++;
                        system("cls");
                        OP287();
                        break;
                    case 132:
                        loop++;
                        system("cls");
                        OP132();
                        break;
                    case 249:
                        loop++;
                        system("cls");
                        OP249();
                        break;
                    case 0:
                        inventory();
                        enter();
                        OP132();
                        break;
                }
            }else{
                death();
            }
        }
    }
}

//OPCAO 393

void OP393(){
    stageops = 393;
    save();
    loop = 0;

    printf("Voc� entra em um aposento frio, dividido por uma fenda profunda. Uma corda retesada estendida de lado a lado atravessa a fenda para o outro lado, onde um magn�fico elmo alado repousa sobre um poste.\n\nSe voc� quiser caminhar pela corda bamba para chegar ao elmo, \033[1;35mdigite 274.\033[0;37m\nSe preferir retornar pelo t�nel para continuar para o norte, \033[1;35mdigite 291.\033[0;37m\n\n");

    printf("\033[1;34mLEMBRE-SE, VOC� PODE ACESSAR SEU INVENT�RIO DIGITANDO 0\033[0;37m\n\n");

    while(loop < 1){
        scanf("%i", &choices);
        switch(choices){
            case 274:
                loop++;
                system("cls");
                OP274();
                break;
            case 291:
                loop++;
                system("cls");
                OP291();
                break;
            case 0:
                inventory();
                enter();
                OP393();
                break;
        }
    }
}

//OPCAO 394

void OP394(){
    stageops = 394;
    save();
    loop = 0;

    printf("\t394 - Voc� arrebenta o vidro com o cabo da espada, fazendo um buraco grande o bastante para que voc� passe. Imediatamente, os Insetos Gigantes saltam na sua dire��o. Sem perda de tempo, voc� entra no aposento, apanhando uma das tochas acesas para se defender. O fogo mant�m a maioria dos Insetos a dist�ncia, mas, quando voc� consegue pegar a coroa e retornar ao corredor, certamente foi mordido por alguns deles. Os Insetos Gigantes n�o v�m atr�s de voc�, preferindo a luz brilhante do aposento em que est�o. Voc� examina a coroa, e v� com desgosto que n�o � nada al�m de ferro pintado, e o \"diamante\" � vidro e n�o vale nada. Voc� a atira no ch�o com raiva e fica pensando aonde ir em seguida.\n\nSe quiser se dirigir para o oeste, \033[1;35mdigite 59.\033[0;37m\nSe preferir retornar ao cruzamento para continuar para o norte, \033[1;35mdigite 14.\033[0;37m");

    printf("\033[1;34mLEMBRE-SE, VOC� PODE ACESSAR SEU INVENT�RIO DIGITANDO 0\033[0;37m\n\n");

    // Jogue um dado e some 2 ao total. Este � o n�mero de ferroadas que voc� recebeu, e ter� que reduzir sua ENERGIA em 1 ponto para cada uma delas.
    dice1();
    dards = numroll + 2;
    printf("\033[1;31mVoc� perdeu %i de ENERGIA\033[0;37m", dards);
    printf("\nSua ENERGIA: %i\n\n", energy - dards);

    while(loop < 1){
        scanf("%i", &choices);
        switch(choices){
            case 14:
                energy -= dards;
                loop++;
                system("cls");
                OP014();
                break;
            case 59:
                loop++;
                system("cls");
                OP059();
                break;
            case 0:
                inventory();
                enter();
                OP394();
                break;
        }
    }
}

//OPCAO 395

void OP395(){
    printf("\t395 - Ao ouvir o ro�do da sua bainha, um dos Trogloditas d� o alarme. Voc� se levanta e corre o mais r�pido que pode pela caverna. Um dos arqueiros dispara uma flecha que lhe rasga o ombro com precis�o mortal. \033[1;31mVoc� perde 3 pontos de ENERGIA.\033[0;37m\n\n");

    printf("\033[1;31mVoc� perdeu 3 de ENERGIA\033[0;37m");
    printf("\nSua HABILIDADE: %i", hability);
    if(energy <= 0){
        death();
    } else{
        printf("Voc� sobreviveu a flechada no ombro");
        enter();
        OP259();
    }

}

//OPCAO 396

void OP396(){
    stageops = 396;
    save();
    loop = 0;

    printf("\t396 - Voc� faz um la�o com a corda, gira-o acima de si e o lan�a na cabe�a do �dolo, sorrindo com alegria quando ele cai em torno do pesco�o da est�tua. Voc� ent�o aperta o n� e come�a a i�ar-se pela corda. Logo chega ao topo, sentando-se em cima do nariz do �dolo enquanto continua a segurar a corda. Voc� desembainha a espada e fica pensando de que olho arrancar a j�ia primeiro.\n\nSe voc� quiser arrancar primeiro a do olho esquerdo, \033[1;35mdigite 151.\033[0;37m\nSe preferir arrancar a do olho direito, \033[1;35mdigite 34.\n\n\033[0;37m");

    printf("\033[1;34mLEMBRE-SE, VOC� PODE ACESSAR SEU INVENT�RIO DIGITANDO 0\033[0;37m\n\n");

    while(loop < 1){
        scanf("%i", &choices);
        switch(choices){
            case 151:
                loop++;
                system("cls");
                OP151();
                break;
            case 34:
                loop++;
                system("cls");
                OP034();
                break;
            case 0:
                inventory();
                enter();
                OP396();
                break;
        }
    }
}

//OPCAO 397

void OP397(){
    stageops = 397;
    save();
    loop = 0;

    printf("\t397 - O l�quido � uma po��o m�gica que lhe permitir� detectar armadilhas ocultas. Some 2 pontos de SORTE.\n\nSe ainda n�o o fez, voc� pode abrir o livro vermelho, \033[1;35mdigite 52.\033[0;37m\nDo contr�rio, voc� ter� que continuar para o norte com Throm, \033[1;35mdigite 369.\033[0;37m\n\n");
    printf("\033[1;34mLEMBRE-SE, VOC� PODE ACESSAR SEU INVENT�RIO DIGITANDO 0\033[0;37m\n\n");
    if(status_OP397 >= 0 && status_OP397 <= 3){
        printf("\033[1;31mA po��o foi adicionada �s suas SKILLS.");
        printf("\033[1;31mVoc� ganhou 2 de SORTE.");
        printf("\033[0;37mSua SORTE: %i", luck);
        skill_trap_potion += 1;
        luck += 2;
        status_OP397 += 1;
        while(loop < 1){
            scanf("%i", &choices);
            switch (choices){
                case 52:
                    loop++;
                    system("cls");
                    OP052();
                    break;
                case 369:
                    loop++;
                    system("cls");
                    OP369();
                    break;
                case 0:
                    loop++;
                    system("cls");
                    OP397();
                    break;
            }
        }
    }
    else{
        printf("\033[1;31mVoc� j� esteve aqui, nada foi adicionado ao seu invent�rio.\033[0;37m\n\n");
        while(loop < 1){
            scanf("%i", &choices);
            switch (choices){
                case 52:
                    loop++;
                    system("cls");
                    OP052();
                    break;
                case 369:
                    loop++;
                    system("cls");
                    OP369();
                    break;
                case 0:
                    loop++;
                    system("cls");
                    OP397();
                    break;
            }
        }
    }
}

//OPCAP 398

void OP398(){
    printf("\t398 - Embora n�o haja qualquer armadilha evidente, voc� tem a forte sensa��o de que a arca cont�m um perigo oculto. A Po��o de Dete`c��o de Armadilha est� funcionando bem. Voc� p�ra de um dos lados da arca e levanta a tampa com a espada, esticando o bra�o para mant�-la a dist�ncia. Quando a tampa se ergue, uma bola de ferro presa a um cord�o � atirada para tr�s e quebra uma c�psula de vidro que est� fixada no lado de dentro da tampa, instantaneamente liberando um g�s. Felizmente, voc� tem tempo de pular para tr�s sem inalar os vapores venenosos. Quando o g�s se dissipa, voc� caminha at� a arca e olha dentro dela. Uma corrente com um pingente est� jogada no fundo, mas algu�m j� tirou a j�ia que havia nele. Voc� fica t�o aborrecido que joga a corrente no ch�o e sai do aposento, furioso, para o t�nel.");

    enter();
    OP230();
}


//OPCAO 399

void OP399(){
    printf("\t399 - O p�o cont�m ervas curativas secretas dos elfos. \033[1;322mSome 3 pontos de ENERGIA.\033[0;37m Sentindo-se triste, embora forte, voc� guarda o espelho e o amuleto, saindo da caverna para seguir para o norte.\n\n");

    energy -= 3;
    printf("Voc� perdeu 3 de ENERGIA\n");
    printf("Sua ENERGIA: %i", energy);
    if(energy <= 0){
        death();
    }else{
        enter();
        OP192();
    }
}

//OPCAO 400

void OP400(){
    printf("\t400 - Logo que voc� aparece na sa�da do t�nel, uma multid�o grita e vibra. As pessoas abrem alas para que voc� siga na dire��o de um pequeno palanque, no qual, sentado embaixo de um p�rasol de bambu colorido, est� o Bar�o Sukumvit. Ele parece apalermado, como se jamais esperasse que algu�m conseguisse sair vivo do Calabou�o da Morte. O segredo de Fang foi revelado. Quando o Bar�o se levanta da cadeira, voc� sobe os degraus do palanque, inclina-se diante dele e observa aqueles olhos frios fixos em voc� em completo espanto. Voc� sorri meio sem gra�a quando ele lhe oferece a m�o estendida. Em meio ao barulho ensurdecedor da ova��o do povo de Fang, o Bar�o Sukumvit abre o cofre que cont�m seu pr�mio de 10.000 Pe�as de Ouro. Em seguida, ele coloca uma coroa de louros sobre a sua cabe�a e o proclama Campe�o do Calabou�o da Morte.");
    enter();
    end();
}

void end(){
    printf("\t\t\t\t\t\t\t\t\t\t\t\t\t\t  \033[1;36mPARAB�NS!\033[0;37m  \t\t\t\t\t\t\t\t\t\t\t\t\t\t\n\n");
    printf("\t\t\t\t\t\t\t\t\t\t\t\t Voc� chegou ao final do \033[1;31mCALABOU�O DA MORTE!\033[0;37m \t\t\t\t\t\t\t\t\t\t\t\t");
    enter();
    godmode = 1;
    stageops = 0;
    printf("\t\t\t\t\t\t\t\t\t\t\t\t\t\t  CR�DITOS  \t\t\t\t\t\t\t\t\t\t\t\t\t\t\n\n");
    printf("\tEste jogo � uma adapta��o de um livro chamado \"A MASMORRA DA MORTE\" escrito por Ian Livingstone. Toda a programa��o, idealiza��o e design deste jogo fora feito por tr�s estudantes do primeiro per�odo do curso Sistemas de Informa��o da institui��o CESMAC de Macei�-AL, os alunos s�o:\n\n\t\t\t\t\t\t\t\t\t\t\t\t\t       \033[1;32mDANIEL CORREIA\n\n\t\t\t\t\t\t\t\t\t\t\t\t\t       MATEUS PAC��FICO\n\n\t\t\t\t\t\t\t\t\t\t\t\t\t\tSILVIO ROMERO\033[0;37m\n\n\t\t\t\t\t\t\t\t\t\t\t\t\t     \033[1;33mObrigado por jogar!\033[0;37m");
    enter();
    printf("\t\t\t\t\t\t\t\t\t\t\t\t       \033[1;34mNovo modo \"GODMODE\" dispon�vel para jogo!\033[0;37m");
    save();
    enter();
    startmenu();
}

int main(){
    setlocale(LC_ALL, "portuguese");
    srand(time(NULL));
    startmenu();
    return 0;
}