/*
Dragon Ball Z Game
@Author
Md. Toufiqul Islam
Abrar ul haque
*/
# include "iGraphics.h"
#include<iostream>
#include<cmath>
#include<string.h>
#include<conio.h>
#include<stdlib.h>
#include<algorithm>
#include<stdio.h>


using namespace std;
int mposx, mposy;

#define _CRT_SECURE_NO_DEPRECATE
#define screenCondition 1
#define screenSpeed 10
#define groundCondition 1
#define groundSpeed 12
void backgrndmv();
void floormove();
void groundImage();
void backImagemove();
void power();
void updatescore();
void jump();
void jumppic();
void home();
void start();
void score();
void name();
int blastmove(int blast_x);
/*
function iDraw() is called again and again by the system.
*/
struct background
{
	int sc_x;
	int gr_x;
};
struct players{
	char name[20];
	int playerScore;
}plyScore[12],temp;
FILE *fp;
int screenx = 1136, screeny = 553;
int screenConditioncheck = 0;
int back_x = 0, back_y = 0;
int mainback_x = 230, mainback_y = 215;
int goku_x = 231, goku_y = 175;
int screenWidth = 1368;
#define screenHeight 768
int stageChange = 1;
int gr1_y = 260;
int groundConditionCheck;
int sound_x = 20, sound_y = 700, checksound = 1, flagsound = 1;
int nosound_x = 20, nosound_y = 700;
int sady = 0;
int homescreen = 0;
int instraction = 0;

int i = 0, j = 0, k;
int strt_i = 0;
background backgroundscreen[10];
int backg_y = 220;
int x_1 = 228;
int x_2 = 342;
int x_3 = 456;
int x_4 = 570;
int x_5 = 684;
int x_6 = 798;
int x_7 = 912;
int x_8 = 1026;
int x_9 = 1140;
int x_10 = 1254;
int x_11 = 1368;
int x_12 = 1482;

int flr_xin = 0, flr_xdiff = 98, flr_y = 53;

int flr_x1 = flr_xin, flr_y1 = 50;
int flr_x2 = flr_x1 + flr_xdiff;
int flr_x3 = flr_x2 + flr_xdiff;
int flr_x4 = flr_x3 + flr_xdiff;
int flr_x5 = 390;
int flr_x6 = 388 + flr_xdiff;
int flr_x7 = 582;
int flr_x8 = 678;
int flr_x9 = 774;
int flr_x10 = flr_x9 + flr_xdiff - 2;
int flr_x11 = flr_x10 + flr_xdiff - 2;
int flr_x12 = flr_x11 + flr_xdiff - 2;
int flr_x13 = flr_x12 + flr_xdiff + 10; // (speed=20)int flr_x13 = flr_x12 + flr_xdiff + 10;
int flr_x14 = flr_x13 + flr_xdiff;
// int x_13 = 1680, y_13 = 255;
char bc1main[100][160] = { "mainback\\1.bmp", "mainback\\2.bmp", "mainback\\3.bmp", "mainback\\4.bmp", "mainback\\5.bmp", "mainback\\6.bmp", "mainback\\7.bmp", "mainback\\8.bmp", "mainback\\9.bmp", "mainback\\10.bmp", "mainback\\11.bmp", "mainback\\12.bmp" };
char flr[100][160] = { "movefloor\\1.bmp", "movefloor\\2.bmp", "movefloor\\3.bmp", "movefloor\\4.bmp", "movefloor\\5.bmp", "movefloor\\6.bmp", "movefloor\\7.bmp", "movefloor\\8.bmp", "movefloor\\9.bmp", "movefloor\\10.bmp", "movefloor\\11.bmp", "movefloor\\12.bmp", "movefloor\\13.bmp", "movefloor\\14.bmp", "movefloor\\15.bmp", "movefloor\\16.bmp" };
//char bcMain2[10][15] = { "new\\11.bmp", "new\\22.bmp", "new\\33.bmp", "new\\44.bmp", "new\\55.bmp", "new\\66.bmp", "new\\77.bmp", "new\\88.bmp", "new\\99.bmp", "new\\100.bmp" };
int regular = 1;
int chrctr_flag = 1;
int mg=0;
int jump_flag = 0,jumpshowflag=1;
int mc = 0;
int hgt_flag = 0;
int pause = 0;
int down_flag = 0, hgst_flag = 0;
//variable for score
int scr_x = 350, scr_y = 300;
char tm[100]="SCORE =";
char life[100] = "ENERGY ", stamina[100]="STAMINA";
int hitflag = 0, gokulife = 100,gokustamina=100;
float gklife = 250.0;
float gkstamina = 250.0;
int scr = 0;
int pause_flag = 0, pausecount = 0, pausespd = 0;

string scoretext,lifetext,staminatext;
//char gu[100];
int blastcountstamina = 0;
int screen_flag = 1;
int powerup = 0, powerupcount = 1, powerup1 = 0, pup = 0;
int blast = 0, blastposecount = 0, blstmv = 0, blast_xin = goku_x + 150, blastcount = -1; //int blast_x = blast_xin;
int blast_x[20] = { blast_xin, blast_xin+5, blast_xin+10, blast_xin, blast_xin, blast_xin, blast_xin, blast_xin, blast_xin, blast_xin, blast_xin, blast_xin
, blast_xin, blast_xin, blast_xin, blast_xin, blast_xin, blast_xin, blast_xin, blast_xin };
int blast_y[20] = { goku_y + 58, goku_y + 58, goku_y + 58, goku_y + 58, goku_y + 58, goku_y + 58, goku_y + 58, goku_y + 58, goku_y + 58, goku_y + 58, goku_y + 58, goku_y + 58, goku_y + 58, goku_y + 58, goku_y + 58, goku_y + 58, goku_y + 58, goku_y + 58, goku_y + 58, goku_y + 58 };
int blastflag[20] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
int thugs1_xin = 1380, thugs1_yin = 450; int thugs1_x = thugs1_xin, thugs1_y = thugs1_yin;
int thugblast1_xin = 1070, thugblast1_yin = thugs1_y + 10; int thugblast1_x = thugblast1_xin, thugblast1_y = thugblast1_yin, thugblastflag1 = 0, thugflag1 = 0;
int thugs2_xin = 1700, thugs2_yin = 600;
 int thugs2_x = thugs2_xin, thugs2_y = thugs2_yin;
int thugblast2_xin = 1070, thugblast2_yin = thugs2_y + 10; int thugblast2_x = thugblast2_xin, thugblast2_y = thugblast2_yin, thugblastflag2 = 0, thugflag2 = 0;
int thugs3_xin = 1970, thugs3_yin = 250; int thugs3_x = thugs3_xin, thugs3_y = thugs3_yin;
int thugblast3_xin = 1070, thugblast3_yin = thugs3_y + 10; int thugblast3_x = thugblast3_xin, thugblast3_y = thugblast3_yin, thugblastflag3 = 0, thugflag3 = 0;
int tbin1 = 0, tbin2 = 0, tbin3 = 0;
int  check = 1, movespd = 0;
int thug3offflag[20] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, thugblast3offflag = 0;
int thug2offflag[20] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },thugblast2offflag=0; 
int thug1offflag[20] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },thugblast1offflag = 0;
int blastoffflag1[20] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
int blastoffflag2[20] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
int blastoffflag3[20] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
int gokuhitthug3_y1 = 175, gokuhitthug3_y2 = 285, gokuhitthugblast3_y1 = 175, gokuhitthugblast3_y2 = 250;
int gokuhitthug2_y1 = 500, gokuhitthug2_y2 = 580, gokuhitthugblast2_y1 = 500, gokuhitthugblast2_y2 = 520;
int gokuhitthug1_y1 = 463, gokuhitthug1_y2 = 525, gokuhitthugblast1_y1 = 471, gokuhitthugblast1_y2 = 505;
int hitregularchck = 0, hitjumpchck = 0;
int blastfin = 0;
int menuflag = 0;
int thugspd = 25, thugblastspd = 35;
int inst = 0;
int blastcheck = 1;
char nam[20],playername[20];
boolean entername;
int len;
// int thugblast1_xin = 1128, thugblast_yin = 508; int thugblast1_x = thugblast1_xin, thugblast1_y = thugblast_yin;

void iDraw()
{
	//int blast_x = goku_x + 150, blast_y = goku_y + 58;
	//place your drawing codes here
	iClear();
	//iText(0, 250, str, GLUT_BITMAP_TIMES_ROMAN_24);
	if (screen_flag == 1)
	{
		if (mg == 0)
		{
			iShowBMP(0, 0, "back\\home2.bmp");
			mg = 1;
		}
		else if (mg == 1)
		{
			iShowBMP(0, 0, "back\\home3.bmp");
			mg = 0;
		}
	}
		
	

	//MENU :
	else if (menuflag==1){
		if (i == 1 )
		{
			cout << "instraactn=" << instraction << endl;
			iClear();
			iShowBMP(back_x, back_y, "back\\backgrnd1.bmp");
			if (checksound % 2 != 0){
				iShowBMP2(sound_x, sound_y, "back\\sound.bmp", 16777215);
				//PlaySound("music\\backmusic1", NULL, SND_LOOP | SND_ASYNC);
				flagsound = 1;
			}
			else{
				iShowBMP(nosound_x, nosound_y, "back\\silent.bmp");

				flagsound = 0;
			}
		}
		else if (i == 2 )
		{

			iClear();
			iShowBMP(back_x, back_y, "back\\backgrnd2.bmp");
			if (checksound % 2 != 0){
				iShowBMP2(sound_x, sound_y, "back\\sound.bmp", 16777215);
				//PlaySound("music\\backmusic1", NULL, SND_LOOP | SND_ASYNC);
				flagsound = 1;
			}
			else
			{
				flagsound = 0;
				iShowBMP(nosound_x, nosound_y, "back\\silent.bmp");
			}
		}
		else if (i == 3)
		{
			iClear();
			iShowBMP(back_x, back_y, "back\\backgrnd3.bmp");
			if (checksound % 2 != 0)
			{
				iShowBMP2(sound_x, sound_y, "back\\sound.bmp", 16777215);
				//PlaySound("music\\backmusic1", NULL, SND_LOOP | SND_ASYNC);
				flagsound = 1;

			}
			else
			{
				iShowBMP(nosound_x, nosound_y, "back\\silent.bmp");
				flagsound = 0;
				//PlaySound(0, 0, 0);
			}
		}
		else if (i == 4)
		{
			iClear();
			iShowBMP(back_x, back_y, "back\\backgrnd4.bmp");
			if (checksound % 2 != 0)
			{
				flagsound = 1;
				//PlaySound("music\\backmusic1", NULL, SND_LOOP | SND_ASYNC);
				iShowBMP2(sound_x, sound_y, "back\\sound.bmp", 16777215);
			}
			else
			{
				flagsound = 0;
				//PlaySound(0, 0, 0);
				iShowBMP(nosound_x, nosound_y, "back\\silent.bmp");

			}
		}
	}
	//startgame :
	if (entername)
	{
		iShowBMP(0, 0, "Entername\\Name.bmp");
		iSetColor(0, 0, 255);
		
		iText(961, 276, nam, GLUT_BITMAP_TIMES_ROMAN_24);
	}
	if (strt_i == 1)
	{
		iClear();
		
		


		//mainback	
		
		

		iShowBMP(x_1, backg_y, bc1main[0]);
		iShowBMP(x_2, backg_y, bc1main[1]);
		iShowBMP(x_3, backg_y, bc1main[2]);
		iShowBMP(x_4, backg_y, bc1main[3]);
		iShowBMP(x_5, backg_y, bc1main[4]);
		iShowBMP(x_6, backg_y, bc1main[5]);
		iShowBMP(x_7, backg_y, bc1main[6]);
		iShowBMP(x_8, backg_y, bc1main[7]);
		iShowBMP(x_9, backg_y, bc1main[8]);
		iShowBMP(x_10, backg_y, bc1main[9]);
		iShowBMP(x_11, backg_y, bc1main[10]);
		iShowBMP(x_12, backg_y, bc1main[11]);
		//iShowBMP(0, 30, "back\\lt1.bmp");
		//floorback
		iShowBMP2(flr_x1, flr_y, flr[0], 16777215);
		iShowBMP2(flr_x2, flr_y, flr[1], 16777215);
		iShowBMP2(flr_x3, flr_y, flr[2], 16777215);
		iShowBMP2(flr_x4, flr_y, flr[3], 16777215);
		iShowBMP2(flr_x5, flr_y, flr[4], 16777215);
		iShowBMP2(flr_x6, flr_y, flr[5], 16777215);
		iShowBMP2(flr_x7, flr_y, flr[6], 16777215);
		iShowBMP2(flr_x8, flr_y, flr[7], 16777215);
		iShowBMP2(flr_x9, flr_y, flr[8], 16777215);
		iShowBMP2(flr_x10, flr_y, flr[9], 16777215);
		iShowBMP2(flr_x11, flr_y, flr[10], 16777215);
		iShowBMP2(flr_x12, flr_y, flr[11], 16777215);
		iShowBMP2(flr_x13, flr_y, flr[12], 16777215);
		iShowBMP2(flr_x14, flr_y, flr[13], 16777215);
		//iShowBMP(0, 0, "mainback\\gokunormal.bmp");

		backImagemove();
		floormove();
		
		if (regular)
		{
			if (movespd == 4 && check == 1)
			{
				movespd = 0;
				check = 2;
			}
			else if (movespd == 4 && check == 2)
			{
				movespd = 0;
				check = 1;

			}
			if (check == 1 && movespd < 4){
				iShowBMP2(goku_x + 58, goku_y + 30, "character\\mor.bmp", 16777215);
				movespd++;
			}

			else if (check == 2 && movespd < 4)
			{

				iShowBMP2(goku_x + 58, goku_y + 30, "character\\run1.bmp", 16777215);
				movespd++;

			}
			
		}
		if (hitregularchck == 1){
			hitregularchck = 0;
			if (goku_y==175)
			regular = 1;
		}
		
		else if (powerup1 == 1){
			//regular = 0;
			power();
			jump_flag = 0;
			powerup1 = 0;
			jump();
			//regular = 0;
		}
		else if (powerup1==0&& regular==0)
		{
			
			jump_flag = 1;
		}
		
		//gokurun :
	
	
		

		//blastpose			
		if (blast)
		{
			
			//regular = 0;
			//powerup1 = -1;
			int lul;
			blastposecount++;
			if (blastposecount == 1){
					//for (lul = 0; lul <10; lul++)
				{
					iShowBMP2(goku_x + 58, goku_y + 30, "character\\redgoku7.bmp", 16777215);

				}
				cout << "blastCheck=" << blastcheck << endl;
				blastcheck = 0;
				//iShowBMP2(blast_x, blast_y, "character\\blast1.bmp", 0);
			}
			else if (blastposecount == 2)
			{
				
				//for (lul = 0; lul <10; lul++)
				{
					iShowBMP2(goku_x + 58, goku_y + 30, "character\\redgoku8.bmp", 16777215);

				}
				//	iShowBMP2(blast_x, blast_y, "character\\blast1.bmp", 0);
				cout << "blastCheck=" << blastcheck << endl;
				blastposecount = 0;
				blastcheck = 1;

			}
			blast = 0; 
			if (goku_y == 175)
				regular = 1;
			else
				jump_flag = 1;
			
			
		}
		//actual blast
		if (blstmv){
			int blastspd = 50;

			if ((blastcount == 0 || blastflag[0])&& !blastfin){
				blastflag[0] = 1;
				iShowBMP2(blast_x[0], blast_y[0], "character\\blast1.bmp", 0);
				
				blast_x[0] += blastspd;
				///	blastpresscheck = 0;

			}
			if (blastcount == 1 || blastflag[1]){
				blastflag[1] = 1;
				iShowBMP2(blast_x[1], blast_y[1], "character\\blast1.bmp", 0);
				
				blast_x[1] += blastspd;

			}
			if (blastcount == 2 || blastflag[2]){
				blastflag[2] = 1;
				iShowBMP2(blast_x[2], blast_y[2], "character\\blast1.bmp", 0);
				blast_x[2] += blastspd;

			}
			if (blastcount == 3 || blastflag[3]){
				blastflag[3] = 1;
				iShowBMP2(blast_x[3], blast_y[3], "character\\blast1.bmp", 0);
				blast_x[3] += blastspd;

			}
			if (blastcount == 4 || blastflag[4]){
				blastflag[4] = 1;
				iShowBMP2(blast_x[4], blast_y[4], "character\\blast1.bmp", 0);
				blast_x[4] += blastspd;

			}
			if (blastcount == 5 || blastflag[5]){
				blastflag[5] = 1;
				iShowBMP2(blast_x[5], blast_y[5], "character\\blast1.bmp", 0);
				blast_x[5] += blastspd;

			}
			if (blastcount == 6 || blastflag[6]){
				blastflag[6] = 1;
				iShowBMP2(blast_x[6], blast_y[6], "character\\blast1.bmp", 0);
				blast_x[6] += blastspd;

			}
			if (blastcount == 7 || blastflag[7]){
				blastflag[7] = 1;
				iShowBMP2(blast_x[7], blast_y[7], "character\\blast1.bmp", 0);
				blast_x[7] += blastspd;

			}
			if (blastcount == 8 || blastflag[8]){
				blastflag[8] = 1;
				iShowBMP2(blast_x[8], blast_y[8], "character\\blast1.bmp", 0);
				blast_x[8] += blastspd;

			}
			if (blastcount == 9 || blastflag[9]){
				blastflag[9] = 1;
				iShowBMP2(blast_x[9], blast_y[9], "character\\blast1.bmp", 0);
				blast_x[9] += blastspd;

			}
			if (blastcount == 10 || blastflag[10]){
				blastflag[10] = 1;
				iShowBMP2(blast_x[10], blast_y[10], "character\\blast1.bmp", 0);
				blast_x[10] += blastspd;

			}
			if (blastcount == 11 || blastflag[11]){
				blastflag[11] = 1;
				iShowBMP2(blast_x[11], blast_y[11], "character\\blast1.bmp", 0);
				blast_x[11] += blastspd;

			}
			if (blastcount == 12 || blastflag[12]){
				blastflag[12] = 1;
				iShowBMP2(blast_x[12], blast_y[12], "character\\blast1.bmp", 0);
				blast_x[12] += blastspd;

			}
			if (blastcount == 13 || blastflag[13]){
				blastflag[13] = 1;
				iShowBMP2(blast_x[13], blast_y[13], "character\\blast1.bmp", 0);
				blast_x[13] += blastspd;

			}
			if (blastcount == 14 || blastflag[14]){
				blastflag[14] = 1;
				iShowBMP2(blast_x[14], blast_y[14], "character\\blast1.bmp", 0);
				blast_x[14] += blastspd;

			}
			if (blastcount == 15 || blastflag[15]){
				blastflag[15] = 1;
				iShowBMP2(blast_x[15], blast_y[15], "character\\blast1.bmp", 0);
				blast_x[15] += blastspd;

			}
			if (blastcount == 16 || blastflag[16]){
				blastflag[16] = 1;
				iShowBMP2(blast_x[16], blast_y[16], "character\\blast1.bmp", 0);
				blast_x[16] += blastspd;

			}
			if (blastcount == 17 || blastflag[17]){
				blastflag[17] = 1;
				iShowBMP2(blast_x[17], blast_y[17], "character\\blast1.bmp", 0);
				blast_x[17] += blastspd;

			}
			if (blastcount == 18 || blastflag[18]){
				blastflag[18] = 1;
				iShowBMP2(blast_x[18], blast_y[18], "character\\blast1.bmp", 0);
				blast_x[18] += blastspd;

			}
			if (blastcount == 19 || blastflag[19]){
				blastflag[19] = 1;
				iShowBMP2(blast_x[19], blast_y[19], "character\\blast1.bmp", 0);
				blast_x[19] += blastspd;

			}
			/*if (blastcount == 9 || blastflag[9]){
			blastflag[9] = 1;
			iShowBMP2(blast_x[9], blast_y, "character\\blast1.bmp", 0);
			blast_x[9] += blastspd;

			}*/
			//blastoff:			
			if (blast_x[0] > 1366 || (blastoffflag1[0] == 1 || blastoffflag2[0] == 1  || blastoffflag3[0] == 1||blastfin))
			{
				blast_x[0] = blast_xin;
				blastflag[0] = 0;
				if (blastcount == 0)
					blastcount--;

			}
			if (blast_x[1] > 1366 || blastoffflag1[1] == 1 || blastoffflag2[1] == 1 || blastoffflag3[1] == 1 || blastfin)
			{
				blast_x[1] = blast_xin;
				blastflag[1] = 0;
				if (blastcount == 1)
					blastcount -= 2;

			}
			if (blast_x[2] > 1366 || blastoffflag1[2] == 1 || blastoffflag2[2] == 1 || blastoffflag3[2] == 1 || blastfin)
			{
				blast_x[2] = blast_xin;
				blastflag[2] = 0;
				if (blastcount == 2)
					blastcount -= 3;

			}
			if (blast_x[3] > 1366 || blastoffflag1[3] == 1 || blastoffflag2[3] == 1 || blastoffflag3[3] == 1 || blastfin)
			{
				blast_x[3] = blast_xin;
				blastflag[3] = 0;
				if (blastcount == 3)
					blastcount -= 4;


			}
			if (blast_x[4] > 1366 || blastoffflag1[4] == 1 || blastoffflag2[4] == 1 || blastoffflag3[4] == 1 || blastfin)
			{
				blast_x[4] = blast_xin;
				blastflag[4] = 0;
				if (blastcount == 4)
					blastcount -= 5;
			}
			if (blast_x[5] > 1366 || blastoffflag1[5] == 1 || blastoffflag2[5] == 1 || blastoffflag3[5] == 1 || blastfin)
			{
				blast_x[5] = blast_xin;
				blastflag[5] = 0;
				if (blastcount == 5)
					blastcount -= 6;
			}
			if (blast_x[6] > 1366 || blastoffflag1[6] == 1 || blastoffflag2[6] == 1 || blastoffflag3[6] == 1 || blastfin)
			{
				blast_x[6] = blast_xin;
				blastflag[6] = 0;
				if (blastcount == 6)
					blastcount -= 7;
			}
			if (blast_x[7] > 1366 || blastoffflag1[7] == 1 || blastoffflag2[7] == 1 || blastoffflag3[7] == 1 || blastfin)
			{
				blast_x[7] = blast_xin;
				blastflag[7] = 0;
				if (blastcount == 7)
					blastcount -= 8;
			}
			if (blast_x[8] > 1366 || blastoffflag1[8] == 1 || blastoffflag2[8] == 1 || blastoffflag3[8] == 1 || blastfin)
			{
				blast_x[8] = blast_xin;
				blastflag[8] = 0;
				if (blastcount == 8)
					blastcount -= 9;
			}
			if (blast_x[9] > 1366 || blastoffflag1[9] == 1 || blastoffflag2[9] == 1 || blastoffflag3[9] == 1 || blastfin)
			{
				blast_x[9] = blast_xin;
				blastflag[9] = 0;
				if (blastcount == 9)
					blastcount -= 10;

				//blstmv = 0;
			}
			if (blast_x[10] > 1366 || blastoffflag1[10] == 1 || blastoffflag2[10] == 1 || blastoffflag3[10] == 1 || blastfin)
			{
				blast_x[10] = blast_xin;
				blastflag[10] = 0;
				if (blastcount == 10)
					blastcount -= 11;
			}

			if (blast_x[11] > 1366 || blastoffflag1[11] == 1 || blastoffflag2[11] == 1 || blastoffflag3[11] == 1 || blastfin)
			{
				blast_x[11] = blast_xin;
				blastflag[11] = 0;
				if (blastcount == 11)
					blastcount -= 12;
			}

			if (blast_x[12] > 1366 || blastoffflag1[12] == 1 || blastoffflag2[12] == 1 || blastoffflag3[12] == 1 || blastfin)
			{
				blast_x[12] = blast_xin;
				blastflag[12] = 0;
				if (blastcount == 12)
					blastcount -= 13;
			}
			if (blast_x[13] > 1366 || blastoffflag1[13] == 1 || blastoffflag2[13] == 1 || blastoffflag3[13] == 1 || blastfin)
			{
				blast_x[13] = blast_xin;
				blastflag[13] = 0;
				if (blastcount == 13)
					blastcount -= 14;
			}

			if (blast_x[14] > 1366 || blastoffflag1[14] == 1 || blastoffflag2[14] == 1 || blastoffflag3[14] == 1 || blastfin)
			{
				blast_x[14] = blast_xin;
				blastflag[14] = 0;
				if (blastcount == 14)
					blastcount -= 15;
			}

			if (blast_x[15] > 1366 || blastoffflag1[15] == 1 || blastoffflag2[15] == 1 || blastoffflag3[15] == 1 || blastfin)
			{
				blast_x[15] = blast_xin;
				blastflag[15] = 0;
				if (blastcount == 15)
					blastcount -= 16;
			}

			if (blast_x[16] > 1366 || blastoffflag1[16] == 1 || blastoffflag2[16] == 1 || blastoffflag3[16] == 1 || blastfin)
			{
				blast_x[16] = blast_xin;
				blastflag[16] = 0;
				if (blastcount == 16)
					blastcount -= 17;
			}

			if (blast_x[17] > 1366 || blastoffflag1[17] == 1 || blastoffflag2[17] == 1 || blastoffflag3[17] == 1 || blastfin)
			{
				blast_x[17] = blast_xin;
				blastflag[17] = 0;
				if (blastcount == 17)
					blastcount -= 18;
			}

			if (blast_x[18] > 1366 || blastoffflag1[18] == 1 || blastoffflag2[18] == 1 || blastoffflag3[18] == 1 || blastfin)
			{
				blast_x[18] = blast_xin;
				blastflag[18] = 0;
				if (blastcount == 18)
					blastcount -= 19;
			}

			if (blast_x[19] > 1366 || blastoffflag1[19] == 1 || blastoffflag2[19] == 1 || blastoffflag3[19] == 1 || blastfin)
			{
				blast_x[19] = blast_xin;
				blastflag[19] = 0;
				if (blastcount == 19)
					blastcount -= 20;
			}


		//	cout << blastcount << endl;
			if (blastcount > 19)
				blastcount = -1;
			/*	if (blastcount == -1)
			blstmv = 0;*/
		}
		iShowBMP(0, 0, "mainback\\gk.bmp");
		//thugs//:
		int poseloop = 10;
		//thug1

		if (thugs1_x <= 1150) {
			tbin1++;
		}
		if (tbin1 == 1 || thugflag1)
		{
			for (int t = 0; t < poseloop; t++)
				iShowBMP2(thugs1_x, thugs1_y, "character\\thugblastpose.bmp", 16777215);
			thugblastflag1 = 1;
			thugflag1 = 0;

		}

		else
		{
			if (thug1offflag[0] || thug1offflag[1] || thug1offflag[2] || thug1offflag[3] || thug1offflag[4] || thug1offflag[5] || thug1offflag[6] || thug1offflag[7] || thug1offflag[8] || thug1offflag[9] || thug1offflag[10] || thug1offflag[11] || thug1offflag[12] || thug1offflag[13] || thug1offflag[14] || thug1offflag[15] || thug1offflag[16] || thug1offflag[17] || thug1offflag[18] || thug1offflag[19])
				iShowBMP2(thugs1_x, thugs1_y, "character\\thughit.bmp", 16777215);
			else
				iShowBMP2(thugs1_x, thugs1_y, "character\\thugsmove.bmp", 16777215);
		}
		if (thugblastflag1 == 1)
		{
			if (!thugblast1offflag)
			iShowBMP2(thugblast1_x, thugblast1_y, "character\\enemyblast.bmp", 0);
			thugblast1_x -= thugblastspd;
		}
		//	if (thugs_x < 418) thugflag = 0;
		if (thugblast1_x < 100)
		{
			thugblast1offflag = 0;
			thugflag1 = 1;
			thugblast1_x = thugs1_x - 80;
			thugblastflag1 = 0;
		}
		thugs1_x -= thugspd;


		if (thugs1_x < 100 || thug1offflag[0] || thug1offflag[1] || thug1offflag[2] || thug1offflag[3] || thug1offflag[4] || thug1offflag[5] || thug1offflag[6] || thug1offflag[7] || thug1offflag[8] || thug1offflag[9] || thug1offflag[10] || thug1offflag[11] || thug1offflag[12] || thug1offflag[13] || thug1offflag[14] || thug1offflag[15] || thug1offflag[16] || thug1offflag[17] || thug1offflag[18] || thug1offflag[19]){
			tbin1 = 0;
			thugblast1_x = thugblast1_xin;
			thugs1_x = thugs1_xin;
			thugflag1 = 0;
		}
		//thug2:
		if (thugs2_x <= 1150) {
			tbin2++;
		}
		if (tbin2 == 1 || thugflag2)
		{
			for (int t = 0; t < poseloop; t++)
				iShowBMP2(thugs2_x, thugs2_y, "character\\thugblastpose.bmp", 16777215);
			thugblastflag2 = 1;
			thugflag2 = 0;

		}

		else
		{
			if (thug2offflag[0] || thug2offflag[1] || thug2offflag[2] || thug2offflag[3] || thug2offflag[4] || thug2offflag[5] || thug2offflag[6] || thug2offflag[7] || thug2offflag[8] || thug2offflag[9] || thug2offflag[10] || thug2offflag[11] || thug2offflag[12] || thug2offflag[13] || thug2offflag[14] || thug2offflag[15] || thug2offflag[16] || thug2offflag[17] || thug2offflag[18] || thug2offflag[19])
				iShowBMP2(thugs2_x, thugs2_y, "character\\thughit.bmp", 16777215);
			else
				iShowBMP2(thugs2_x, thugs2_y, "character\\thugsmove.bmp", 16777215);
		}
		if (thugblastflag2 == 1)
		{
			if (!thugblast2offflag)
			iShowBMP2(thugblast2_x, thugblast2_y, "character\\enemyblast.bmp", 0);
			thugblast2_x -= thugblastspd;
		}
		//	if (thugs_x < 418) thugflag = 0;
		if (thugblast2_x < 100 )
		{ 
			thugblast2offflag = 0;
			tbin2 = 0;
			thugflag2 = 1;
			thugblast2_x = thugs2_x - 80;
			thugblastflag2 = 0;
		}
		thugs2_x -= thugspd;


		if ((thugs2_x < 100 || thug2offflag[0] || thug2offflag[1] || thug2offflag[2] || thug2offflag[3] || thug2offflag[4] || thug2offflag[5] || thug2offflag[6] || thug2offflag[7] || thug2offflag[8] || thug2offflag[9] || thug2offflag[10] || thug2offflag[11] || thug2offflag[12] || thug2offflag[13] || thug2offflag[14] || thug2offflag[15] || thug2offflag[16] || thug2offflag[17] || thug2offflag[18] || thug2offflag[19])){
			thugblast2_x = thugblast2_xin;
			thugs2_x = thugs2_xin;
			thugflag2 = 0;
		}
		//thug3:
		//if (thugs_x == thugblast1_x)
		if (thugs3_x <= 1150) {
			tbin3++;
		}
		if (tbin3 == 1 || thugflag3)
		{
			for (int t = 0; t < poseloop; t++)
				iShowBMP2(thugs3_x, thugs3_y, "character\\thugblastpose.bmp", 16777215);
			thugblastflag3 = 1;
			thugflag3 = 0;

		}

		else
		{
			if (thug3offflag[0] || thug3offflag[1] || thug3offflag[2] || thug3offflag[3] || thug3offflag[4] || thug3offflag[5] || thug3offflag[6] || thug3offflag[7] || thug3offflag[8] || thug3offflag[9] || thug3offflag[10] || thug3offflag[11] || thug3offflag[12] || thug3offflag[13] || thug3offflag[14] || thug3offflag[15] || thug3offflag[16] || thug3offflag[17] || thug3offflag[18] || thug3offflag[19])
				iShowBMP2(thugs3_x, thugs3_y, "character\\thughit.bmp", 16777215);
			else
				iShowBMP2(thugs3_x, thugs3_y, "character\\thugsmove.bmp", 16777215);
		}
		if (thugblastflag3 == 1)
		{
			if (!thugblast3offflag)
				iShowBMP2(thugblast3_x, thugblast3_y, "character\\enemyblast.bmp", 0);
			thugblast3_x -= thugblastspd;
		}
		//	if (thugs_x < 418) thugflag = 0;
		if (thugblast3_x < 150)
		{

			thugblast3offflag = 0;
			tbin3 = 0;
			thugflag3 = 1;
			thugblast3_x = thugs3_x - 80;
			thugblastflag3 = 0;
		}
		thugs3_x -= thugspd;


		if (thugs3_x < 150 || thug3offflag[0] || thug3offflag[1] || thug3offflag[2] || thug3offflag[3] || thug3offflag[4] || thug3offflag[5] || thug3offflag[6] || thug3offflag[7] || thug3offflag[8] || thug3offflag[9] || thug3offflag[10] || thug3offflag[11] || thug3offflag[12] || thug3offflag[13] || thug3offflag[14] || thug3offflag[15] || thug3offflag[16] || thug3offflag[17] || thug3offflag[18] || thug3offflag[19]){
			thugblast3_x = thugblast3_xin;
			thugs3_x = thugs3_xin;
			thugflag3 = 0;
		}


//thughit: 
	//for thug3:	
		if (!thugblast3offflag && ( blast_x[0] >= thugblast3_x && (blast_y[0] >= 233 && blast_y[0] <= 285) && blastcount >= 0)){
			
			thugblast3offflag = 1;
			blastoffflag3[0] = 1;
		}
		else {
			if (blast_x[0] >= thugs3_x && (blast_y[0] >= 233 && blast_y[0] <= 285) && (blastcount >= 0)){

				blastoffflag3[0] = 1;
				thug3offflag[0] = 1;
				//thugblast3offflag = 1;
				scr += 5;
			}
			else{
				blastoffflag3[0] = 0;
				thug3offflag[0] = 0;
				//thugblast3offflag = 0;
			}
		}
	//	cout << "lol" << blast_y[0] << endl;
		/*if (blast_x[0] >= thugblast3_x)
		{
		//	thugblast3offflag = 1;
			blastoffflag3[0] = 1;
		}

		else{
			
		//	thugblast3offflag = 0;
			blastoffflag3[0] = 0;
		}*/

		if (!thugblast3offflag && (blast_x[1] >= thugblast3_x && (blast_y[1] >= 233 && blast_y[1] <= 285) && blastcount >= 1)){
			
			thugblast3offflag = 1;
			blastoffflag3[1] = 1;
		}
		else {

			if (blast_x[1] >= thugs3_x && (blast_y[1] >= 233 && blast_y[1] <= 285) && (blastcount >= 1)){

				blastoffflag3[1] = 1;
				thug3offflag[1] = 1;
				//thugblast3offflag = 1;
				scr += 5;

			}
			else{ 
				blastoffflag3[1] = 0;
				thug3offflag[1] = 0;
				//thugblast3offflag = 0;

			}
		}

		if (!thugblast3offflag && (blast_x[2] >= thugblast3_x && (blast_y[2] >= 233 && blast_y[2] <= 285) && blastcount >= 2)){

			thugblast3offflag = 1;
			blastoffflag3[2] = 1;
		}
		else {

			if (blast_x[2] >= thugs3_x && (blast_y[2] >= 233 && blast_y[2] <= 285) && (blastcount >= 2)){

				blastoffflag3[2] = 1;
				thug3offflag[2] = 1;
				scr += 5;


			}
			else{
				blastoffflag3[2] = 0;
				thug3offflag[2] = 0;


			}
		}
		if (!thugblast3offflag && (blast_x[3] >= thugblast3_x && (blast_y[3] >= 233 && blast_y[3] <= 285) && blastcount >= 1)){

			thugblast3offflag = 1;
			blastoffflag3[3] = 1;
		}
		else {

			if (blast_x[3] >= thugs3_x && (blast_y[3] >= 233 && blast_y[3] <= 285) && (blastcount >= 3)){

				blastoffflag3[3] = 1;
				thug3offflag[3] = 1;
				scr += 5;


			}
			else{
				blastoffflag3[3] = 0;
				thug3offflag[3] = 0;


			}
		}

		if (!thugblast3offflag && (blast_x[4] >= thugblast3_x && (blast_y[4] >= 233 && blast_y[4] <= 285) && blastcount >= 4)){

			thugblast3offflag = 1;
			blastoffflag3[4] = 1;
		}
		else {

			if (blast_x[4] >= thugs3_x && (blast_y[4] >= 233 && blast_y[4] <= 285) && (blastcount >= 4)){

				blastoffflag3[4] = 1;
				thug3offflag[4] = 1;
				scr += 5;


			}
			else{
				blastoffflag3[4] = 0;
				thug3offflag[4] = 0;


			}
		}

		if (!thugblast3offflag && (blast_x[5] >= thugblast3_x && (blast_y[5] >= 233 && blast_y[5] <= 285) && blastcount >= 5)){

			thugblast3offflag = 1;
			blastoffflag3[5] = 1;
		}
		else {

			if (blast_x[5] >= thugs3_x && (blast_y[5] >= 233 && blast_y[5] <= 285) && (blastcount >= 5)){

				blastoffflag3[5] = 1;
				thug3offflag[5] = 1;
				scr += 5;


			}
			else{
				blastoffflag3[5] = 0;
				thug3offflag[5] = 0;


			}
		}

		if (!thugblast3offflag && (blast_x[6] >= thugblast3_x && (blast_y[6] >= 233 && blast_y[6] <= 285) && blastcount >= 6)){

			thugblast3offflag = 1;
			blastoffflag3[6] = 1;
		}
		else {
			if (blast_x[6] >= thugs3_x && (blast_y[6] >= 233 && blast_y[6] <= 285) && (blastcount >= 6)){

				blastoffflag3[6] = 1;
				thug3offflag[6] = 1;
				scr += 5;

			}
			else{
				blastoffflag3[6] = 0;
				thug3offflag[6] = 0;


			}
		}

		if (!thugblast3offflag && (blast_x[7] >= thugblast3_x && (blast_y[7] >= 233 && blast_y[7] <= 285) && blastcount >= 7)){

			thugblast3offflag = 1;
			blastoffflag3[7] = 1;
		}

		else {
			if (blast_x[7] >= thugs3_x && (blast_y[7] >= 233 && blast_y[7] <= 285) && (blastcount >= 7)){

				blastoffflag3[7] = 1;
				thug3offflag[7] = 1;
				scr += 5;

			}
			else{
				blastoffflag3[7] = 0;
				thug3offflag[7] = 0;


			}
		}

		if (!thugblast3offflag && (blast_x[8] >= thugblast3_x && (blast_y[8] >= 233 && blast_y[8] <= 285) && blastcount >= 8)){

			thugblast3offflag = 1;
			blastoffflag3[8] = 1;
		}
		else {

			if (blast_x[8] >= thugs3_x && (blast_y[8] >= 233 && blast_y[8] <= 285) && (blastcount >= 8)){

				blastoffflag3[8] = 1;
				thug3offflag[8] = 1;
				scr += 5;

			}
			else{
				blastoffflag3[8] = 0;
				thug3offflag[8] = 0;


			}
		}

		if (!thugblast3offflag && (blast_x[9] >= thugblast3_x && (blast_y[9] >= 233 && blast_y[9] <= 285) && blastcount >= 9)){

			thugblast3offflag = 1;
			blastoffflag3[9] = 1;
		}
		else {
			if (blast_x[9] >= thugs3_x && (blast_y[9] >= 233 && blast_y[9] <= 285) && (blastcount >= 9)){

				blastoffflag3[9] = 1;
				thug3offflag[9] = 1;

				scr += 5;
			}
			else{
				blastoffflag3[9] = 0;
				thug3offflag[9] = 0;


			}
		}

		if (!thugblast3offflag && (blast_x[10] >= thugblast3_x && (blast_y[10] >= 233 && blast_y[10] <= 285) && blastcount >= 10)){

			thugblast3offflag = 1;
			blastoffflag3[10] = 1;
		}
		else {
			if (blast_x[10] >= thugs3_x && (blast_y[10] >= 233 && blast_y[10] <= 285) && (blastcount >= 10)){

				blastoffflag3[10] = 1;
				thug3offflag[10] = 1;
				scr += 5;

			}
			else{
				blastoffflag3[10] = 0;
				thug3offflag[10] = 0;


			}
		}

		if (!thugblast3offflag && (blast_x[11] >= thugblast3_x && (blast_y[11] >= 233 && blast_y[11] <= 285) && blastcount >= 11)){

			thugblast3offflag = 1;
			blastoffflag3[11] = 1;
		}
		else {
			if (blast_x[11] >= thugs3_x && (blast_y[11] >= 233 && blast_y[11] <= 285) && (blastcount >= 11)){

				blastoffflag3[11] = 1;
				thug3offflag[11] = 1;
				scr += 5;

			}
			else{
				blastoffflag3[11] = 0;
				thug3offflag[11] = 0;


			}
		}

		if (!thugblast3offflag && (blast_x[12] >= thugblast3_x && (blast_y[12] >= 233 && blast_y[12] <= 285) && blastcount >= 12)){

			thugblast3offflag = 1;
			blastoffflag3[12] = 1;
		}
		else {
			if (blast_x[12] >= thugs3_x && (blast_y[12] >= 233 && blast_y[12] <= 285) && (blastcount >= 12)){

				blastoffflag3[12] = 1;
				thug3offflag[12] = 1;
				scr += 5;

			}
			else{
				blastoffflag3[12] = 0;
				thug3offflag[12] = 0;


			}
		}

		if (!thugblast3offflag && (blast_x[13] >= thugblast3_x && (blast_y[13] >= 233 && blast_y[13] <= 285) && blastcount >= 13)){

			thugblast3offflag = 1;
			blastoffflag3[13] = 1;
		}
		else {
			if (blast_x[13] >= thugs3_x && (blast_y[13] >= 233 && blast_y[13] <= 285) && (blastcount >= 13)){

				blastoffflag3[13] = 1;
				thug3offflag[13] = 1;

				scr += 5;
			}
			else{
				blastoffflag3[13] = 0;
				thug3offflag[13] = 0;


			}
		}

		if (!thugblast3offflag && (blast_x[14] >= thugblast3_x && (blast_y[14] >= 233 && blast_y[14] <= 285) && blastcount >= 14)){

			thugblast3offflag = 1;
			blastoffflag3[14] = 1;
		}
		else {
			if (blast_x[14] >= thugs3_x && (blast_y[14] >= 233 && blast_y[14] <= 285) && (blastcount >= 14)){

				blastoffflag3[14] = 1;
				thug3offflag[14] = 1;

				scr += 5;
			}
			else{
				blastoffflag3[14] = 0;
				thug3offflag[14] = 0;


			}
		}

		if (!thugblast3offflag && (blast_x[15] >= thugblast3_x && (blast_y[15] >= 233 && blast_y[15] <= 285) && blastcount >= 15)){

			thugblast3offflag = 1;
			blastoffflag3[15] = 1;
		}
		else {
			if (blast_x[15] >= thugs3_x && (blast_y[15] >= 233 && blast_y[15] <= 285) && (blastcount >= 15)){

				blastoffflag3[15] = 1;
				thug3offflag[15] = 1;

				scr += 5;
			}
			else{
				blastoffflag3[15] = 0;
				thug3offflag[15] = 0;


			}
		}

		if (!thugblast3offflag && (blast_x[16] >= thugblast3_x && (blast_y[16] >= 233 && blast_y[16] <= 285) && blastcount >= 16)){

			thugblast3offflag = 1;
			blastoffflag3[16] = 1;
		}
		else {
			if (blast_x[16] >= thugs3_x && (blast_y[16] >= 233 && blast_y[16] <= 285) && (blastcount >= 16)){

				blastoffflag3[16] = 1;
				thug3offflag[16] = 1;

				scr += 5;
			}
			else{
				blastoffflag3[16] = 0;
				thug3offflag[16] = 0;


			}
		}
		if (!thugblast3offflag && (blast_x[17] >= thugblast3_x && (blast_y[17] >= 233 && blast_y[17] <= 285) && blastcount >= 17)){

			thugblast3offflag = 1;
			blastoffflag3[1] = 1;
		}
		else {
			if (blast_x[17] >= thugs3_x && (blast_y[17] >= 233 && blast_y[17] <= 285) && (blastcount >= 17)){

				blastoffflag3[17] = 1;
				thug3offflag[17] = 1;

				scr += 5;
			}
			else{
				blastoffflag3[17] = 0;
				thug3offflag[17] = 0;


			}
		}

		if (!thugblast3offflag && (blast_x[18] >= thugblast3_x && (blast_y[18] >= 233 && blast_y[18] <= 285) && blastcount >= 18)){

			thugblast3offflag = 1;
			blastoffflag3[18] = 1;
		}
		else {
			if (blast_x[18] >= thugs3_x && (blast_y[18] >= 233 && blast_y[18] <= 285) && (blastcount >= 18)){

				blastoffflag3[18] = 1;
				thug3offflag[18] = 1;
				scr += 5;

			}
			else{
				blastoffflag3[18] = 0;
				thug3offflag[18] = 0;


			}
		}

		if (!thugblast3offflag && (blast_x[19] >= thugblast3_x && (blast_y[19] >= 233 && blast_y[19] <= 285) && blastcount >= 19)){

			thugblast3offflag = 1;
			blastoffflag3[19] = 1;
		}
		else {
			if (blast_x[19] >= thugs3_x && (blast_y[19] >= 233 && blast_y[19] <= 285) && (blastcount >= 19)){

				blastoffflag3[19] = 1;
				thug3offflag[19] = 1;

				scr += 5;
			}
			else{
				blastoffflag3[19] = 0;
				thug3offflag[19] = 0;


			}
		}
//for thug 2:
		if (!thugblast2offflag && (blast_x[0] >= thugblast2_x && (blast_y[0] >= 581 && blast_y[0] <= 660) && blastcount >= 0)){

			thugblast2offflag = 1;
			blastoffflag2[0] = 1;
		}
		else {

			if (blast_x[0] >= thugs2_x && (blast_y[0] >= 581 && blast_y[0] <= 660) && (blastcount >= 0)){

				blastoffflag2[0] = 1;
				thug2offflag[0] = 1;
				//thugblast3offflag = 1;
				scr += 5;
			}
			else{
				blastoffflag2[0] = 0;
				thug2offflag[0] = 0;
			}
		}
		//cout << "lull==" << blast_y[0] << endl;
		
		if (!thugblast2offflag && (blast_x[1] >= thugblast2_x && (blast_y[1] >= 581 && blast_y[1] <= 660) && blastcount >= 1)){

			thugblast2offflag = 1;
			blastoffflag2[1] = 1;
		}
		
		else {

			if (blast_x[1] >= thugs2_x && (blast_y[1] >= 581 && blast_y[1] <= 660) && (blastcount >= 1)){

				blastoffflag2[1] = 1;
				thug2offflag[1] = 1;
				//thugblast3offflag = 1;
				scr += 5;
			}
			else{
				blastoffflag2[1] = 0;
				thug2offflag[1] = 0;
				//thugblast3offflag = 0;

			}
		}

		if (!thugblast2offflag && (blast_x[2] >= thugblast2_x && (blast_y[2] >= 581 && blast_y[2] <= 660) && blastcount >= 2)){

			thugblast2offflag = 1;
			blastoffflag2[2] = 1;
		}

		else {

			if (blast_x[2] >= thugs2_x && (blast_y[2] >= 581 && blast_y[2] <= 660) && (blastcount >= 2)){

				blastoffflag2[2] = 1;
				thug2offflag[2] = 1;

				scr += 5;
			}
			else{
				blastoffflag2[2] = 0;
				thug2offflag[2] = 0;


			}
		}

		if (!thugblast2offflag && (blast_x[3] >= thugblast2_x && (blast_y[3] >= 581 && blast_y[1] <= 660) && blastcount >= 3)){

			thugblast2offflag = 1;
			blastoffflag2[3] = 1;
		}

		else {

			if (blast_x[3] >= thugs2_x && (blast_y[3] >= 581 && blast_y[3] <= 660) && (blastcount >= 3)){

				blastoffflag2[3] = 1;
				thug2offflag[3] = 1;

				scr += 5;
			}
			else{
				blastoffflag2[3] = 0;
				thug2offflag[3] = 0;


			}
		}

		if (!thugblast2offflag && (blast_x[4] >= thugblast2_x && (blast_y[4] >= 581 && blast_y[4] <= 660) && blastcount >= 4)){

			thugblast2offflag = 1;
			blastoffflag2[4] = 1;
		}

		else {

			if (blast_x[4] >= thugs2_x && (blast_y[4] >= 581 && blast_y[4] <= 660) && (blastcount >= 4)){

				blastoffflag2[4] = 1;
				thug2offflag[4] = 1;

				scr += 5;
			}
			else{
				blastoffflag2[4] = 0;
				thug2offflag[4] = 0;


			}
		}

		if (!thugblast2offflag && (blast_x[5] >= thugblast2_x && (blast_y[5] >= 581 && blast_y[5] <= 660) && blastcount >= 5)){

			thugblast2offflag = 1;
			blastoffflag2[5] = 1;
		}

		else {

			if (blast_x[5] >= thugs2_x && (blast_y[5] >= 581 && blast_y[5] <= 660) && (blastcount >= 5)){

				blastoffflag2[5] = 1;
				thug2offflag[5] = 1;

				scr += 5;
			}
			else{
				blastoffflag2[5] = 0;
				thug2offflag[5] = 0;


			}
		}

		if (!thugblast2offflag && (blast_x[6] >= thugblast2_x && (blast_y[6] >= 581 && blast_y[6] <= 660) && blastcount >= 6)){

			thugblast2offflag = 1;
			blastoffflag2[6] = 1;
		}

		else {

			if (blast_x[6] >= thugs2_x && (blast_y[6] >= 581 && blast_y[6] <= 660) && (blastcount >= 6)){

				blastoffflag2[6] = 1;
				thug2offflag[6] = 1;

				scr += 5;
			}
			else{
				blastoffflag2[6] = 0;
				thug2offflag[6] = 0;


			}
		}

		if (!thugblast2offflag && (blast_x[7] >= thugblast2_x && (blast_y[7] >= 581 && blast_y[7] <= 660) && blastcount >= 7)){

			thugblast2offflag = 1;
			blastoffflag2[7] = 1;
		}

		else {

			if (blast_x[7] >= thugs2_x && (blast_y[7] >= 581 && blast_y[7] <= 660) && (blastcount >= 7)){

				blastoffflag2[7] = 1;
				thug2offflag[7] = 1;
				scr += 5;

			}
			else{
				blastoffflag2[7] = 0;
				thug2offflag[7] = 0;


			}
		}

		if (!thugblast2offflag && (blast_x[8] >= thugblast2_x && (blast_y[8] >= 581 && blast_y[8] <= 660) && blastcount >= 8)){

			thugblast2offflag = 1;
			blastoffflag2[8] = 1;
		}

		else {

			if (blast_x[8] >= thugs2_x && (blast_y[8] >= 581 && blast_y[8] <= 660) && (blastcount >= 8)){

				blastoffflag2[8] = 1;
				thug2offflag[8] = 1;
				scr += 5;

			}
			else{
				blastoffflag2[8] = 0;
				thug2offflag[8] = 0;


			}
		}

		if (!thugblast2offflag && (blast_x[9] >= thugblast2_x && (blast_y[9] >= 581 && blast_y[1] <= 660) && blastcount >= 1)){

			thugblast2offflag = 1;
			blastoffflag2[1] = 1;
		}

		else {

			if (blast_x[9] >= thugs2_x && (blast_y[9] >= 581 && blast_y[9] <= 660) && (blastcount >= 9)){

				blastoffflag2[9] = 1;
				thug2offflag[9] = 1;
				scr += 5;

			}
			else{
				blastoffflag2[9] = 0;
				thug2offflag[9] = 0;


			}
		}

		if (!thugblast2offflag && (blast_x[1] >= thugblast2_x && (blast_y[1] >= 581 && blast_y[1] <= 660) && blastcount >= 1)){

			thugblast2offflag = 1;
			blastoffflag2[1] = 1;
		}

		else {

			if (blast_x[10] >= thugs2_x && (blast_y[10] >= 581 && blast_y[10] <= 660) && (blastcount >= 10)){

				blastoffflag2[10] = 1;
				thug2offflag[10] = 1;
				scr += 5;

			}
			else{
				blastoffflag2[10] = 0;
				thug2offflag[10] = 0;


			}
		}

		if (!thugblast2offflag && (blast_x[11] >= thugblast2_x && (blast_y[11] >= 581 && blast_y[11] <= 660) && blastcount >= 11)){

			thugblast2offflag = 1;
			blastoffflag2[11] = 1;
		}

		else {

			if (blast_x[11] >= thugs2_x && (blast_y[11] >= 581 && blast_y[11] <= 660) && (blastcount >= 11)){

				blastoffflag2[11] = 1;
				thug2offflag[11] = 1;
				scr += 5;

			}
			else{
				blastoffflag2[11] = 0;
				thug2offflag[11] = 0;


			}
		}

		if (!thugblast2offflag && (blast_x[12] >= thugblast2_x && (blast_y[12] >= 581 && blast_y[1] <= 660) && blastcount >= 12)){

			thugblast2offflag = 1;
			blastoffflag2[12] = 1;
		}

		else {

			if (blast_x[12] >= thugs2_x && (blast_y[12] >= 581 && blast_y[12] <= 660) && (blastcount >= 12)){

				blastoffflag2[12] = 1;
				thug2offflag[12] = 1;
				scr += 5;

			}
			else{
				blastoffflag2[12] = 0;
				thug2offflag[12] = 0;


			}
		}
		if (!thugblast2offflag && (blast_x[13] >= thugblast2_x && (blast_y[13] >= 581 && blast_y[13] <= 660) && blastcount >= 13)){

			thugblast2offflag = 1;
			blastoffflag2[13] = 1;
		}

		else {


			if (blast_x[13] >= thugs2_x && (blast_y[13] >= 581 && blast_y[13] <= 660) && (blastcount >= 13)){

				blastoffflag2[13] = 1;
				thug2offflag[13] = 1;
				scr += 5;

			}
			else{
				blastoffflag2[13] = 0;
				thug2offflag[13] = 0;


			}
		}
		if (!thugblast2offflag && (blast_x[14] >= thugblast2_x && (blast_y[14] >= 581 && blast_y[14] <= 660) && blastcount >= 14)){

			thugblast2offflag = 1;
			blastoffflag2[14] = 1;
		}

		else {
			if (blast_x[14] >= thugs2_x && (blast_y[14] >= 581 && blast_y[14] <= 660) && (blastcount >= 14)){

				blastoffflag2[14] = 1;
				thug2offflag[14] = 1;

				scr += 5;
			}
			else{
				blastoffflag2[14] = 0;
				thug2offflag[14] = 0;


			}
		}

		if (!thugblast2offflag && (blast_x[15] >= thugblast2_x && (blast_y[15] >= 581 && blast_y[15] <= 660) && blastcount >= 15)){

			thugblast2offflag = 1;
			blastoffflag2[15] = 1;
		}

		else {
			if (blast_x[15] >= thugs2_x && (blast_y[15] >= 581 && blast_y[15] <= 660) && (blastcount >= 15)){

				blastoffflag2[15] = 1;
				thug2offflag[15] = 1;

				scr += 5;
			}
			else{
				blastoffflag2[15] = 0;
				thug2offflag[15] = 0;


			}
		}

		if (!thugblast2offflag && (blast_x[16] >= thugblast2_x && (blast_y[16] >= 581 && blast_y[16] <= 660) && blastcount >= 16)){

			thugblast2offflag = 1;
			blastoffflag2[16] = 1;
		}

		else {

			if (blast_x[16] >= thugs3_x && (blast_y[16] >= 581 && blast_y[16] <= 660) && (blastcount >= 16)){

				blastoffflag2[16] = 1;
				thug2offflag[16] = 1;

				scr += 5;
			}
			else{
				blastoffflag2[16] = 0;
				thug2offflag[16] = 0;


			}
		}

		if (!thugblast2offflag && (blast_x[17] >= thugblast2_x && (blast_y[17] >= 581 && blast_y[17] <= 660) && blastcount >= 17)){

			thugblast2offflag = 1;
			blastoffflag2[17] = 1;
		}

		else {

			if (blast_x[17] >= thugs2_x && (blast_y[17] >= 581 && blast_y[17] <= 660) && (blastcount >= 17)){

				blastoffflag2[17] = 1;
				thug2offflag[17] = 1;

				scr += 5;
			}
			else{
				blastoffflag2[17] = 0;
				thug2offflag[17] = 0;


			}
		}

		if (!thugblast2offflag && (blast_x[18] >= thugblast2_x && (blast_y[18] >= 581 && blast_y[18] <= 660) && blastcount >= 18)){

			thugblast2offflag = 1;
			blastoffflag2[18] = 1;
		}

		else {

			if (blast_x[18] >= thugs2_x && (blast_y[18] >= 581 && blast_y[18] <= 660) && (blastcount >= 18)){

				blastoffflag2[18] = 1;
				thug2offflag[18] = 1;
				scr += 5;

			}
			else{
				blastoffflag2[18] = 0;
				thug2offflag[18] = 0;


			}
		}

		if (!thugblast2offflag && (blast_x[19] >= thugblast2_x && (blast_y[19] >= 581 && blast_y[19] <= 660) && blastcount >= 19)){

			thugblast2offflag = 1;
			blastoffflag2[19] = 1;
		}

		else {

			if (blast_x[19] >= thugs2_x && (blast_y[19] >= 581 && blast_y[19] <= 660) && (blastcount >= 19)){

				blastoffflag2[19] = 1;
				thug2offflag[19] = 1;
				scr += 5;

			}
			else{
				blastoffflag2[19] = 0;
				thug2offflag[19] = 0;


			}
		}

//for thug1: 
			
		if (!thugblast1offflag && (blast_x[0] >= thugblast1_x && (blast_y[0] >= 420 && blast_y[0] <= 508) && blastcount >= 0)){

			thugblast1offflag = 1;
			blastoffflag1[0] = 1;
		}
		else {

			if (blast_x[0] >= thugs1_x && (blast_y[0] >= 420 && blast_y[0] <= 508) && (blastcount >= 0)){

				blastoffflag1[0] = 1;
				thug1offflag[0] = 1;
				//thugblast3offflag = 1;
				scr += 5;
			}
			else{
				blastoffflag1[0] = 0;
				thug1offflag[0] = 0;
			}
		}
		
		//cout << "lull==" << blast_y[0] << endl;
		

		if (!thugblast1offflag && (blast_x[1] >= thugblast1_x && (blast_y[1] >= 420 && blast_y[1] <= 508) && blastcount >= 1)){

			thugblast1offflag = 1;
			blastoffflag1[1] = 1;
		}
		else {

			if (blast_x[1] >= thugs1_x && (blast_y[1] >= 420 && blast_y[1] <= 508) && (blastcount >= 1)){

				blastoffflag1[1] = 1;
				thug1offflag[1] = 1;
				scr += 5;
				//thugblast3offflag = 1;

			}
			else{
				blastoffflag1[1] = 0;
				thug1offflag[1] = 0;
				//thugblast3offflag = 0;

			}
		}

		if (!thugblast1offflag && (blast_x[2] >= thugblast1_x && (blast_y[2] >= 420 && blast_y[2] <= 508) && blastcount >= 2)){

			thugblast1offflag = 1;
			blastoffflag1[2] = 1;
		}
		else {


			if (blast_x[2] >= thugs1_x && (blast_y[2] >= 420 && blast_y[2] <= 508) && (blastcount >= 2)){

				blastoffflag1[2] = 1;
				thug1offflag[2] = 1;
				scr += 5;


			}
			else{
				blastoffflag1[2] = 0;
				thug1offflag[2] = 0;


			}
		}

		if (!thugblast1offflag && (blast_x[3] >= thugblast1_x && (blast_y[3] >= 420 && blast_y[3] <= 508) && blastcount >= 3)){

			thugblast1offflag = 1;
			blastoffflag1[3] = 1;
		}
		else {

			if (blast_x[3] >= thugs1_x && (blast_y[3] >= 420 && blast_y[3] <= 508) && (blastcount >= 3)){

				blastoffflag1[3] = 1;
				thug1offflag[3] = 1;
				scr += 5;


			}
			else{
				blastoffflag1[3] = 0;
				thug1offflag[3] = 0;


			}
		}

		if (!thugblast1offflag && (blast_x[4] >= thugblast1_x && (blast_y[4] >= 420 && blast_y[4] <= 508) && blastcount >= 4)){

			thugblast1offflag = 1;
			blastoffflag1[4] = 1;
		}
		else {

			if (blast_x[4] >= thugs1_x && (blast_y[4] >= 420 && blast_y[4] <= 508) && (blastcount >= 4)){

				blastoffflag1[4] = 1;
				thug1offflag[4] = 1;
				scr += 5;


			}
			else{
				blastoffflag1[4] = 0;
				thug1offflag[4] = 0;


			}
		}

		if (!thugblast1offflag && (blast_x[5] >= thugblast1_x && (blast_y[5] >= 420 && blast_y[5] <= 508) && blastcount >= 5)){

			thugblast1offflag = 1;
			blastoffflag1[5] = 1;
		}
		else {

			if (blast_x[5] >= thugs1_x && (blast_y[5] >= 420 && blast_y[5] <= 508) && (blastcount >= 5)){

				blastoffflag1[5] = 1;
				thug1offflag[5] = 1;
				scr += 5;

			}
			else{
				blastoffflag1[5] = 0;
				thug1offflag[5] = 0;


			}
		}

		if (!thugblast1offflag && (blast_x[6] >= thugblast1_x && (blast_y[6] >= 420 && blast_y[6] <= 508) && blastcount >= 6)){

			thugblast1offflag = 1;
			blastoffflag1[6] = 1;
		}
		else {

			if (blast_x[6] >= thugs1_x && (blast_y[6] >= 420 && blast_y[6] <= 508) && (blastcount >= 6)){

				blastoffflag1[6] = 1;
				thug1offflag[6] = 1;
				scr += 5;


			}
			else{
				blastoffflag1[6] = 0;
				thug1offflag[6] = 0;


			}
		}

		if (!thugblast1offflag && (blast_x[7] >= thugblast1_x && (blast_y[7] >= 420 && blast_y[7] <= 508) && blastcount >= 7)){

			thugblast1offflag = 1;
			blastoffflag1[7] = 1;
		}
		else {

			if (blast_x[7] >= thugs1_x && (blast_y[7] >= 420 && blast_y[7] <= 508) && (blastcount >= 7)){

				blastoffflag1[7] = 1;
				thug1offflag[7] = 1;
				scr += 5;


			}
			else{
				blastoffflag1[7] = 0;
				thug1offflag[7] = 0;


			}
		}

		if (!thugblast1offflag && (blast_x[8] >= thugblast1_x && (blast_y[8] >= 420 && blast_y[8] <= 508) && blastcount >= 8)){

			thugblast1offflag = 1;
			blastoffflag1[8] = 1;
		}
		else {

			if (blast_x[8] >= thugs1_x && (blast_y[8] >= 420 && blast_y[8] <= 508) && (blastcount >= 8)){

				blastoffflag1[8] = 1;
				thug1offflag[8] = 1;
				scr += 5;


			}
			else{
				blastoffflag1[8] = 0;
				thug1offflag[8] = 0;


			}
		}

		if (!thugblast1offflag && (blast_x[9] >= thugblast1_x && (blast_y[9] >= 420 && blast_y[9] <= 508) && blastcount >= 9)){

			thugblast1offflag = 1;
			blastoffflag1[9] = 1;
		}
		else {

			if (blast_x[9] >= thugs1_x && (blast_y[9] >= 420 && blast_y[9] <= 508) && (blastcount >= 9)){

				blastoffflag1[9] = 1;
				thug1offflag[9] = 1;
				scr += 5;


			}
			else{
				blastoffflag1[9] = 0;
				thug1offflag[9] = 0;


			}
		}

		if (!thugblast1offflag && (blast_x[10] >= thugblast1_x && (blast_y[10] >= 420 && blast_y[10] <= 508) && blastcount >= 10)){

			thugblast1offflag = 1;
			blastoffflag1[10] = 1;
		}
		else {

			if (blast_x[10] >= thugs1_x && (blast_y[10] >= 420 && blast_y[10] <= 508) && (blastcount >= 10)){

				blastoffflag1[10] = 1;
				thug1offflag[10] = 1;
				scr += 5;

			}
			else{
				blastoffflag1[10] = 0;
				thug1offflag[10] = 0;


			}
		}

		if (!thugblast1offflag && (blast_x[11] >= thugblast1_x && (blast_y[11] >= 420 && blast_y[11] <= 508) && blastcount >= 11)){

			thugblast1offflag = 1;
			blastoffflag1[11] = 1;
		}
		else {

			if (blast_x[11] >= thugs1_x && (blast_y[11] >= 420 && blast_y[11] <= 508) && (blastcount >= 11)){

				blastoffflag1[11] = 1;
				thug1offflag[11] = 1;
				scr += 5;

			}
			else{
				blastoffflag1[11] = 0;
				thug1offflag[11] = 0;


			}
		}

		if (!thugblast1offflag && (blast_x[12] >= thugblast1_x && (blast_y[12] >= 420 && blast_y[12] <= 508) && blastcount >= 12)){

			thugblast1offflag = 1;
			blastoffflag1[12] = 1;
		}
		else {

			if (blast_x[12] >= thugs1_x && (blast_y[12] >= 420 && blast_y[12] <= 508) && (blastcount >= 12)){

				blastoffflag1[12] = 1;
				thug1offflag[12] = 1;

				scr += 5;
			}
			else{
				blastoffflag1[12] = 0;
				thug1offflag[12] = 0;


			}
		}

		if (!thugblast1offflag && (blast_x[13] >= thugblast1_x && (blast_y[13] >= 420 && blast_y[13] <= 508) && blastcount >= 13)){

			thugblast1offflag = 1;
			blastoffflag1[13] = 1;
		}
		else {

			if (blast_x[13] >= thugs1_x && (blast_y[13] >= 420 && blast_y[13] <= 508) && (blastcount >= 13)){

				blastoffflag1[13] = 1;
				thug1offflag[13] = 1;

				scr += 5;
			}
			else{
				blastoffflag1[13] = 0;
				thug1offflag[13] = 0;


			}
		}

		if (!thugblast1offflag && (blast_x[14] >= thugblast1_x && (blast_y[14] >= 420 && blast_y[14] <= 508) && blastcount >= 14)){
			
			thugblast1offflag = 1;
			blastoffflag1[14] = 1;
		}
		else {

			if (blast_x[14] >= thugs1_x && (blast_y[14] >= 420 && blast_y[14] <= 508) && (blastcount >= 14)){

				blastoffflag1[14] = 1;
				thug1offflag[14] = 1;
				scr += 5;

			}
			else{
				blastoffflag1[14] = 0;
				thug1offflag[14] = 0;


			}
		}

		if (!thugblast1offflag && (blast_x[15] >= thugblast1_x && (blast_y[15] >= 420 && blast_y[15] <= 508) && blastcount >= 15)){

			thugblast1offflag = 1;
			blastoffflag1[15] = 1;
		}
		else {

			if (blast_x[15] >= thugs1_x && (blast_y[15] >= 420 && blast_y[15] <= 508) && (blastcount >= 15)){

				blastoffflag1[15] = 1;
				thug1offflag[15] = 1;
				scr += 5;

			}
			else{
				blastoffflag1[15] = 0;
				thug1offflag[15] = 0;


			}
		}

		if (!thugblast1offflag && (blast_x[16] >= thugblast1_x && (blast_y[16] >= 420 && blast_y[16] <= 508) && blastcount >= 16)){

			thugblast1offflag = 1;
			blastoffflag1[16] = 1;
		}
		else {

			if (blast_x[16] >= thugs1_x && (blast_y[16] >= 420 && blast_y[16] <= 508) && (blastcount >= 16)){

				blastoffflag1[16] = 1;
				thug1offflag[16] = 1;

				scr += 5;
			}
			else{
				blastoffflag1[16] = 0;
				thug1offflag[16] = 0;


			}
		}

		if (!thugblast1offflag && (blast_x[17] >= thugblast1_x && (blast_y[17] >= 420 && blast_y[17] <= 508) && blastcount >= 17)){

			thugblast1offflag = 1;
			blastoffflag1[17] = 1;
		}
		else {

			if (blast_x[17] >= thugs1_x && (blast_y[17] >= 420 && blast_y[17] <= 508) && (blastcount >= 17)){

				blastoffflag1[17] = 1;
				thug1offflag[17] = 1;
				scr += 5;

			}
			else{
				blastoffflag1[17] = 0;
				thug1offflag[17] = 0;


			}
		}


		if (!thugblast1offflag && (blast_x[18] >= thugblast1_x && (blast_y[18] >= 420 && blast_y[18] <= 508) && blastcount >= 18)){

			thugblast1offflag = 1;
			blastoffflag1[1] = 1;
		}
		else {

			if (blast_x[18] >= thugs1_x && (blast_y[18] >= 420 && blast_y[18] <= 508) && (blastcount >= 18)){

				blastoffflag1[18] = 1;
				thug1offflag[18] = 1;
				scr += 5;

			}
			else{
				blastoffflag1[18] = 0;
				thug1offflag[18] = 0;


			}
		}


		if (!thugblast1offflag && (blast_x[19] >= thugblast1_x && (blast_y[19] >= 420 && blast_y[19] <= 508) && blastcount >= 19)){

			thugblast1offflag = 1;
			blastoffflag1[19] = 1;
		}
		else {

			if (blast_x[19] >= thugs1_x && (blast_y[19] >= 420 && blast_y[19] <= 508) && (blastcount >= 19)){

				blastoffflag1[19] = 1;
				thug1offflag[19] = 1;

				scr += 5;
			}
			else{
				blastoffflag1[19] = 0;
				thug1offflag[19] = 0;


			}
		}
 
		//cout << "thug1== " <<thugs1_y << endl;

//gokuhit:
		//iShowBMP2(goku_x + 58, goku_y + 30, "character\\gokuhit.bmp", 16777215);


		if (!thugblast3offflag && ( (thugs3_x <= (goku_x + 58) && gokuhitthug3_y1 <= goku_y + 30 && goku_y + 30 <= gokuhitthug3_y2) || (thugblast3_x <= goku_x + 58 && gokuhitthugblast3_y1 <= goku_y + 30 && goku_y + 30 <= gokuhitthugblast3_y2)))
		{
			//cout << "th==" << thugblast3offflag << endl;
			regular = 0,jumpshowflag=0,hitregularchck=1,hitjumpchck=1;
			thugblast3offflag = 1;
			iShowBMP2(goku_x + 58, goku_y + 30, "character\\gokuhit.bmp", 16777215);
			
			gklife -= 12.5;
			
			gokulife = (gklife * 100) / 250;

		}
		if (!thugblast2offflag && ((thugs2_x <= (goku_x + 58) && gokuhitthug2_y1 <= goku_y + 30 && goku_y + 30 <= gokuhitthug2_y2) || (thugblast2_x <= goku_x + 58 && gokuhitthugblast2_y1 <= goku_y + 30 && goku_y + 30 <= gokuhitthugblast2_y2)))
		{

			regular = 0, hitregularchck = 1, hitjumpchck = 1;
			thugblast2offflag = 1;
			iShowBMP2(goku_x + 58, goku_y + 30, "character\\gokuhit.bmp", 16777215);

			gklife -= 12.5;
			gokulife = (gklife * 100) / 250;
		}

		if (!thugblast1offflag && ((thugs1_x <= (goku_x + 58) && gokuhitthug1_y1 <= goku_y + 30 && goku_y + 30 <= gokuhitthug1_y2) || (thugblast1_x <= goku_x + 58 && gokuhitthugblast1_y1 <= goku_y + 30 && goku_y + 30 <= gokuhitthugblast1_y2)))
		{
			thugblast1offflag = 1;
			regular = 0, hitregularchck = 1, hitjumpchck = 1;
			iShowBMP2(goku_x + 58, goku_y + 30, "character\\gokuhit.bmp", 16777215);

			gklife -= 12.5;
			gokulife = (gklife * 100) / 250;
		}

		//cout << "thug3offflag== " << blastcount << endl;
	/*	if (blast_x[1] >= thugblast3_x)
		{
			thugblast3offflag = 1;
			blastoffflag[1] = 1;
		}

		else{

			thugblast3offflag = 0;
			blastoffflag[1] = 0;
		}*/
		//cout << "bl=== " << blastpresscheck << endl;
		//if (thugs_x==thugblast1_x)
		
		score();
		//iShowBMP2(496,215, "mainback\\spike.bmp",0);

		//	if (powerup1==0)
		//iShowBMP2(goku_x + 25, goku_y + 30, "character\\redgoku6.bmp", 16777215);




//jump:
		if (jump_flag == 1 && sady!=1 )
		{
			//cout << "jumpflag==" << jump_flag << endl;
			cout << "sady in jump functn=" << sady << endl;
			jumppic();
				jump();
				
			//jumpshowflag = 1;

		}
		sady = 0;
		cout << "sady out jump functn=" << sady << endl;
			//if (goku_y != 325 && mc >= 1)
			/*if (mc >= 1 && goku_y != 675)
			{
				goku_y += 50;
			}
			if (goku_y <= 525 && mc >= 2)
				//if (mc>=2)
			{

				while (goku_y != 675)
				{
					goku_y += 25;
				}
				// if (goku_y==525)

				hgt_flag = 1;
				// mc = 0;
			}
 			else
			if (goku_y == 675)
			{
				mc = 0;
				hgt_flag = 1;
			}

			if (hgt_flag == 1)
			{
				mc = 0;
				if (goku_y !=175)
				{
					goku_y -= 25;
				}

			}
			if (goku_y == 175)
			{
				jump_flag = 0;
				regular = 1;
				mc = 0;
				hgt_flag = 0;
			}
			else	if (goku_y == 525 && mc > 0)
				//else if (mc>0)
			{
				while (goku_y != 175)
				{
					goku_y -= 25;
					jump_flag = 0;
					regular = 1;
					mc = 0;
					hgt_flag = 0;

				}
			}

		}*/
		//if (goku_y > 175)
		//	regular = 0;
	

		iShowBMP(0, 340, "mainback\\gokussjg1.bmp");
	//gokulife:
		iSetColor(255, 255, 255);
		iRectangle(32.0, 80.0, 31.0, 250.0);
			
		iSetColor(255, 0, 0);
		iFilledRectangle(32.0, 80.0, 30.0, gklife);

		
		iText(5, 400, life, GLUT_BITMAP_TIMES_ROMAN_24);
		lifetext = to_string(gokulife);
		iText2(30, 350, lifetext, GLUT_BITMAP_TIMES_ROMAN_24);
		iText2(70, 350, "%" , GLUT_BITMAP_TIMES_ROMAN_24);
	
	//gokustamina:
		gokustamina = (gkstamina * 100) / 250;

		iSetColor(255, 255, 255);
		iRectangle(145.0, 80.0, 31.0, 250.0);

		iSetColor(0, 255, 0);
		iFilledRectangle(145.0, 80.0, 30.0, gkstamina);


		iText(115, 400, stamina, GLUT_BITMAP_TIMES_ROMAN_24);
		staminatext = to_string(gokustamina);
		iText2(140, 350, staminatext, GLUT_BITMAP_TIMES_ROMAN_24);
		iText2(180, 350, "%", GLUT_BITMAP_TIMES_ROMAN_24);

		//iShowBMP(62, 0, "mainback\\energy1.bmp");
	//gokudead: 
		if (gokulife <= 0){
			menuflag = 1;
			strt_i = 0;
			updatescore;
            
			}
	}

	if (inst==1)
	{
		//menuflag = 0;
		iShowBMP(0, 0, "inst\\inst.bmp");
		

	}
	/*else if (inst == 0)
	{
		menuflag == 1;
	}*/


}





/*
function iMouseMove() is called when the user presses and drags the mouse.
(mx, my) is the position where the mouse pointer is.
*/
void iMouseMove(int mx, int my)
{
	//place your codes here
}


/*
function iMouse() is called when the user presses/releases the mouse.
(mx, my) is the position where the mouse pointer is.
*/
void iMouse(int button, int state, int mx, int my)
{
	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{
		//	cout << mx << "\t" << my << endl;
		if ((mx >= 23 && mx <= 67) && (my >= 708 && my <= 741)){
			checksound++;
			if (flagsound == 0) PlaySound("music\\backmusic1", NULL, SND_LOOP | SND_ASYNC);
			else PlaySound(0, 0, 0);
		}
		//place your codes here
		cout << mx << "\t" << my << endl;
	}


	if (button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
	{
		//place your codes here
		//	cout << rand()%3 << endl;
	}
}
/*iPassiveMouseMove is called to detect and use
the mouse point without pressing any button */

void iPassiveMouseMove(int mx, int my)
{
	//place your code here

	mposx = mx;
	mposy = my;
	if (mx == 2){}        /*Something to do with mx*/
	else if (my == 2){}   /*Something to do with my*/

}

/*
function iKeyboard() is called whenever the user hits a key in keyboard.
key- holds the ASCII value of the key pressed.
*/
void iKeyboard(unsigned char key)
{
	if ((key == '\r') && (i == 1))
	{
		strt_i = 1;
		menuflag = 0;
		//entername = true;
		j = 1;
	

		//PlaySound("music\\mainmusic", NULL, SND_LOOP | SND_ASYNC);
		//mainsound_flag = 1;
		//iClear();
		//PlaySound(0, 0, 0);
	}
	if (entername){
		
		PlaySound(0, 0, 0);
		nam[len] = key;
		if (key == '\b')
		{
			nam[--len] = '\0';
		}
		else if (key == 'k' )
		{
			strcpy(playername, nam);
			strt_i = 1;
	
			
		}

		else
			len++;
		
	}
	
	
	else if (key == '\r' && i == 2)
	{
		inst = 1;
		menuflag = 0;
		PlaySound("music\\instmusic", NULL, SND_LOOP | SND_ASYNC);
	}
	if (key == '\b'&& entername==FALSE )
	{
		menuflag = 1;
		inst = 0;
		PlaySound("music\\backmusic1", NULL, SND_LOOP | SND_ASYNC);
	}
	
	if (key == 'w'){
		goku_y += 10;
		//blast_y += 10;
	}

	else if (key == 's')
	{
		goku_y -= 10;
		//blast_y -= 10;
	}
	else if (key == 'd')
	{
		goku_x += 10;
		//blast_x += 10;
	}
	if (key == '\r' )
	{
		menuflag = 1;
		i = 1;
		screen_flag = 0;
		
	}
	else if (key == 'a')
	{
		goku_x -= 20;
		//blast_x -= 20;
	}
	
	else if (key == 'c'){
		
		powerup1 = 1;
		regular = 0;
		
		if (gkstamina < 250)
			gkstamina += 12.5;
		if (gkstamina>250)
			gkstamina = 250;
	//	cout << "pup==" << powerup1 <<"\tregular=="<<regular<< endl;
	}
	else if (key == 32)
	{
		
		jump_flag = 1;
		regular = 0;
		

		if (mc == 0 || mc == 1)
			mc++;


	}
	else if (key == 'x')
	{
		
		blast = 1; regular = 0; blstmv = 1, blastcount++, jumpshowflag = 0,sady=1;
		jump();
		//cout << "jumpFlag" << jump_flag << endl;;
		if (gkstamina > 0)
			gkstamina -= 31.25;
		if (gkstamina < 0)
			gkstamina = 0;
		if (gokustamina == 0)
		{
			if (goku_y == 175) regular = 1;
			else if (goku_y>175) jumpshowflag = 1;
			blast = 0, blastfin = 1;

		}
		else if (gokustamina>0)
				blastfin = 0;

		if (blastcount==0) blast_y[0] = goku_y + 58;
		else if (blastcount == 1) blast_y[1] = goku_y + 58;
		else if (blastcount == 2) blast_y[2] = goku_y + 58;
		else if (blastcount == 3) blast_y[3] = goku_y + 58;
		else if (blastcount == 4) blast_y[4] = goku_y + 58;
		else if (blastcount == 5) blast_y[5] = goku_y + 58;
		else if (blastcount == 6) blast_y[6] = goku_y + 58;
		else if (blastcount == 7) blast_y[7] = goku_y + 58;
		else if (blastcount == 8) blast_y[8] = goku_y + 58;
		else if (blastcount == 9) blast_y[9] = goku_y + 58;
		else if (blastcount == 10) blast_y[10] = goku_y + 58;
		else if (blastcount == 11) blast_y[11] = goku_y + 58;
		else if (blastcount == 12) blast_y[12] = goku_y + 58;
		else if (blastcount == 13) blast_y[13] = goku_y + 58;
		else if (blastcount == 14) blast_y[14] = goku_y + 58;
		else if (blastcount == 15) blast_y[15] = goku_y + 58;
		else if (blastcount == 16) blast_y[16] = goku_y + 58;
		else if (blastcount == 17) blast_y[17] = goku_y + 58;
		else if (blastcount == 18) blast_y[18] = goku_y + 58;
		else if (blastcount == 19) blast_y[19] = goku_y + 58;

		
		
	//	cout << "blasty == " << blast_y[0] << endl;
	}
	/*for (int i = 0; i != '\r'; i++)
	{
		str[i] = key;
	}*/
	/*else if (key == 'z')
	powerup = 0;*/
	//place your codes for other keys here
}

/*
function iSpecialKeyboard() is called whenver user hits special keys like-
function keys, home, end, pg up, pg down, arraows etc. you have to use
appropriate constants to detect them. A list is:
GLUT_KEY_F1, GLUT_KEY_F2, GLUT_KEY_F3, GLUT_KEY_F4, GLUT_KEY_F5, GLUT_KEY_F6,
GLUT_KEY_F7, GLUT_KEY_F8, GLUT_KEY_F9, GLUT_KEY_F10, GLUT_KEY_F11, GLUT_KEY_F12,
GLUT_KEY_LEFT, GLUT_KEY_UP, GLUT_KEY_RIGHT, GLUT_KEY_DOWN, GLUT_KEY_PAGE UP,
GLUT_KEY_PAGE DOWN, GLUT_KEY_HOME, GLUT_KEY_END, GLUT_KEY_INSERT
*/
void iSpecialKeyboard(unsigned char key)
{

	if ((key == GLUT_KEY_DOWN) && (i<4))
	{

		i++;


	}

	else if ((key == GLUT_KEY_UP) && (i>1)){
		i--;


	}
	else if ((key == GLUT_KEY_UP) && (i == 1))
		i = 4;
	else if ((key == GLUT_KEY_DOWN) && (i == 4))
		i = 1;
	
}
/*void backgrndmv(){
//screenx -= 10;
int n = 9; int first = 0;
for (k = n; k >= 0; k--)
{
iShowBMP(screenx, screeny, bc1main[k]);
screenx -= 111;
/*if (screenx < 230)
{

//bc1main[n] = bc1main[first];
n--; first++;
}
}
}*/

void backImagemove()

{
	int back_spd = 2;
	x_1 -= back_spd;
	x_2 -= back_spd;
	x_3 -= back_spd;
	x_4 -= back_spd;
	x_5 -= back_spd;
	x_6 -= back_spd;
	x_7 -= back_spd;
	x_8 -= back_spd;
	x_9 -= back_spd;
	x_10 -= back_spd;
	x_11 -= back_spd;
	x_12 -= back_spd;
	//x_13 -= 4;
	if (x_1 <= 0)
	{

		x_1 = screenWidth;

	}
	else if (x_2 <= 0)
	{
		x_2 = screenWidth;
	}
	else if (x_3 <= 0)
	{
		x_3 = screenWidth;
	}
	else if (x_4 <= 0)
	{
		x_4 = screenWidth;
	}
	else if (x_5 <= 0)
	{
		x_5 = screenWidth;
	}
	else if (x_6 <= 0)
	{
		x_6 = screenWidth;
	}
	else if (x_7 <= 0)
	{
		x_7 = screenWidth;
	}
	else if (x_8 <= 0)
	{
		x_8 = screenWidth;
	}
	else if (x_9 <= 0)
	{
		x_9 = screenWidth;
	}
	else if (x_10 <= 0)
	{
		x_10 = screenWidth;
	}
	else if (x_11 <= 0)
	{
		x_11 = iScreenWidth;
	}
	else if (x_12 <= 0)
	{
		x_12 = screenWidth;
	}


}
void floormove(){
	int flr_spd = 10;
	flr_x1 -= flr_spd;
	flr_x2 -= flr_spd;
	flr_x3 -= flr_spd;
	flr_x4 -= flr_spd;
	flr_x5 -= flr_spd;
	flr_x6 -= flr_spd;
	flr_x7 -= flr_spd;
	flr_x8 -= flr_spd;
	flr_x9 -= flr_spd;
	flr_x10 -= flr_spd;
	flr_x11 -= flr_spd;
	flr_x12 -= flr_spd;
	flr_x13 -= flr_spd;
	flr_x14 -= flr_spd;
	//x_13 -= 4;
	if (flr_x1 <= 0)
	{

		flr_x1 = screenWidth;

	}
	else if (flr_x2 <= 0)
	{
		flr_x2 = screenWidth;
	}
	else if (flr_x3 <= 0)
	{
		flr_x3 = screenWidth;
	}
	else if (flr_x4 <= 0)
	{
		flr_x4 = screenWidth;
	}
	else if (flr_x5 <= 0)
	{
		flr_x5 = screenWidth;
	}
	else if (flr_x6 <= 0)
	{
		flr_x6 = screenWidth;
	}
	else if (flr_x7 <= 0)
	{
		flr_x7 = screenWidth;
	}
	else if (flr_x8 <= 0)
	{
		flr_x8 = screenWidth;
	}
	else if (flr_x9 <= 0)
	{
		flr_x9 = screenWidth;
	}
	else if (flr_x10 <= 0)
	{
		flr_x10 = screenWidth;
	}
	else if (flr_x11 <= 0)
	{
		flr_x11 = iScreenWidth;
	}
	else if (flr_x12 <= 0)
	{
		flr_x12 = screenWidth;
	}
	if (flr_x13 <= 0)
	{

		flr_x13 = screenWidth;

	}
	if (flr_x14 <= 0)
	{

		flr_x14 = screenWidth;

	}
}
int blastmove(int blast_x){

	int blast_spd = 4;
	blast_x += blast_spd;
	return blast_x;
}
void jumppic()
{
	iShowBMP2(goku_x + 58, goku_y + 30, "character\\redgoku12.bmp", 16777215);
}

void power(){

		powerupcount++;
		//for (pup = 0; pup < 100; pup++){
		if (powerupcount == 1){
			//for (pup = pup; pup < 100; pup++)
			//if (pup==0 )
			//jump_flag = 0;
			iShowBMP2(goku_x + 25, goku_y + 30, "character\\flare1.bmp", 0);
			iShowBMP2(goku_x + 58, goku_y + 30, "character\\redgoku6.bmp", 16777215);
			//iShowBMP2(goku_x + 25, goku_y + 30, "character\\redgoku1wp.bmp", 16777215);
			//else if (pup == 99) pup = 0;
			//else break;

		}
		else if (powerupcount == 2)
		{
			//for (pup = 0; pup < 100; pup++)
			//jump_flag = 0;
			iShowBMP2(goku_x + 10, goku_y + 30, "character\\flare2.bmp", 0);
			iShowBMP2(goku_x + 58, goku_y + 30, "character\\redgoku6.bmp", 16777215);
			//iShowBMP2(goku_x + 25, goku_y + 30, "character\\redgoku1wp.bmp", 16777215);
			//powerupcount = 0;
		}
		else if (powerupcount == 3){
			//for (pup = 0; pup < 100; pup++)
			//jump_flag = 0;
			iShowBMP2(goku_x + 5, goku_y + 15, "character\\flare3.bmp", 0);
		    iShowBMP2(goku_x + 58, goku_y + 30, "character\\redgoku6.bmp", 16777215);
			//iShowBMP2(goku_x + 25, goku_y + 30, "character\\redgoku1wp.bmp", 16777215);
			powerupcount = 0;
			
		}
	}

	//if (powerup1 == 0)
	//iShowBMP2(goku_x + 58, goku_y + 30, "character\\redgoku6.bmp", 16777215);





/*void changeGround()
{
groundConditionCheck++;
if (groundConditionCheck == groundCondition)
{
int s = groundSpeed;
for (int i = 0; i < 10; i++)
{
backgroundscreen[i].gr_x -= s;
if (backgroundscreen[i].gr_x <= 0)
{
backgroundscreen[i].gr_x = screenWidth;
}
}
groundConditionCheck = 0;
}
}*/
void jump(){
	if (hitjumpchck) {
		jumpshowflag = 0;
		hitjumpchck = 0;
	}
	if (jumpshowflag)
	//iShowBMP2(goku_x + 58, goku_y + 30, "character\\redgoku12.bmp", 16777215);
	//iShowBMP2(goku_x + 58, goku_y + 30, "character\\redgoku12.bmp", 16777215);
	jumpshowflag = 1;


	if (mc > 0 && hgt_flag == 0)
	{

		goku_y += 10;
		if (goku_y == 395)
		{
			hgt_flag = 1;
			mc = 0;
		}
	}

	else if (mc > 0 && goku_y >= 395)
	{

		if (goku_y != 625)
		{
			goku_y += 10;

		}
		if (goku_y == 625)
		{
			hgst_flag = 1;
			mc = 0;
		}
	}
	else if (hgst_flag == 1)
	{
		if (goku_y != 395 || goku_y != 175)
		{
			goku_y -= 10;
		}
		hgst_flag = 0;
	}

	else if (hgt_flag == 1)
	{
		if (goku_y != 175)
		{
			goku_y -= 10;
			down_flag = 1;
			mc = 0;
		}
		else if (goku_y == 175)
		{
			mc = 0;
			hgt_flag = 0;
			regular = 1;
			jump_flag = 0;
		}

	}
	

}
int scoredplayer = 0;
void score(){
	iSetColor(0, 0, 255);
	iText(10, 700,tm, GLUT_BITMAP_TIMES_ROMAN_24);
	scoretext = to_string(scr);
	iText2(120, 700, scoretext, GLUT_BITMAP_TIMES_ROMAN_24);

}
void updatescore(){
	
	fp=fopen("scorestore.txt","w");
	strcpy(plyScore[scoredplayer].name, playername);
	plyScore[scoredplayer].playerScore = scr;
	for (int u = 0; u <= scoredplayer; u++)
	{
		for (int v = u + 1; v <= scoredplayer; v++)
		{
			if (plyScore[i].playerScore < plyScore[j].playerScore)
			{
				temp = plyScore[i];
				plyScore[i] = plyScore[j];
				plyScore[j] = temp;
				
			}
		}
	}
	for (int u = 0; u <= 10; u++)
	{
		if (plyScore[i].name[0] != NULL || strlen(plyScore[i].name) != 0)
		{
			fprintf(fp, "%s\n%d\n", plyScore[i].name, plyScore[i].playerScore);
		}
	}
	fclose(fp);

}
void start(){
	
	iShowBMP(0, 0, "back\\home2.bmp");
}
void home(){
	if (homescreen == 0)
	{
		iShowBMP(0, 0, "back\\home2.bmp");
			homescreen =1;
	}
	else if (homescreen == 1)
	{
		iShowBMP(0, 0, "back\\home3.bmp");
		homescreen =0;
	}
}

int main()
{
	//place your own initialization codes here.


	//PlaySound("music\\02", NULL, SND_LOOP | SND_ASYNC);
	//iSetTimer(100, power);
	//iDelay();
	PlaySound("music\\backmusic1", NULL, SND_LOOP | SND_ASYNC);
	iInitialize(screenWidth, screenHeight, "GOKU'S LEGACY");

	return 0;

}
