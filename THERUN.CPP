#include<stdio.h>
#include<iostream.h>
#include<conio.h>
#include<dos.h>
#include<graphics.h>
#include<process.h>
#include<stdlib.h>
typedef struct speed;
void first(void);
void second(void);
void game(void);
void rules(void);
class circles
{
	public:void circle1(int adv)
	{       for(int j=0;j<=2;j++)
		circle(1+adv,300,j);
	}
	public:void circle2(int adv,int dist)
	{       for(int j=0;j<=2;j++)
		circle(1+adv-dist,300,j);
	}
	public:void circle3(int adv,int dist)
	{       for(int j=1;j<=2;j++)
		circle(1+adv-(2*dist),300,j);
	}
	public:void circle4(int adv,int dist)
	{       for(int j=1;j<=2;j++)
		circle(1+adv-(3*dist),300,j);
	}
}cplot;
struct speed
{
	int min_speed;
	int max_speed;
}sp;
void main()
{
	int gd=DETECT, gm, x= getmaxx(), counter=0, y= getmaxy();
       //	int poly[8];
	initgraph(&gd, &gm, "C:\\TurboC3\\BGI");
	first();//Loading...
	second();//The Run & Welcome to the game screen
	cleardevice();
	rectangle(0, 0, 630, 475);//The border of the game
	line(400,0,400,475);//The divider of the box
	game();//The main game
	getch();
	closegraph();
}
void rules()
{
	int gd=DETECT,gm;
	initgraph(&gd,&gm,"C:\\TurboC3\\BGI");
	cleardevice();
	settextstyle(GOTHIC_FONT, HORIZ_DIR,7);
	setcolor(6);
	outtextxy(getmaxx()/2-100,30,"RULES");
	settextstyle(SMALL_FONT,HORIZ_DIR,4);
	setcolor(7);
	outtextxy(getmaxx()/2-300,120,"\nIn this game, you have to control the car and dodge the \nobstacles that come in your way.\n");
	outtextxy(getmaxx()/2-300,140,"You can move the car in the left and right lane \nusing the left and right arrow keys respectively.\n");
	outtextxy(getmaxx()/2-300,160,"You can also pick up the FLY powerup that comes randomly in the lanes.\n");
	outtextxy(getmaxx()/2-300,180,"The FLY powerup allows you to fly over incoming \nobstacles for a limited time of 700 milliseconds.");
	outtextxy(getmaxx()/2-300,190,"So watch your timer!  ;)");
	outtextxy(getmaxx()/2-300,210,"Once the car touches any point of any incoming obstacle,");
	outtextxy(getmaxx()/2-300,220,"the day wouldn't suit your desires, the game will be over!\n");
	outtextxy(getmaxx()/2-300,250,"Ready for the adrenaline? Just a minute, loading environment... :D");
	delay(20000);
	getch();
}
void first()//Loading Screen
{

	sp.min_speed=8;
	sp.max_speed=2;
	int dist,setc1,circle2set,circle3set,circle4set;
	int flag=0,gm=DETECT,gd;
	initgraph(&gm,&gd,"C:\\TurboC3\\BGI");
	setcolor(4);
	while(flag==0)
	{

		for(int advance=1;advance<=getmaxx()+150;advance++)
		{

				int a[8];
				a[0]=97+(advance/1.5);
				a[1]=130;
				a[2]=104+(advance/1.5);
				a[3]=122;
				a[4]=118+(advance/1.5);
				a[5]=122;
				a[6]=128+(advance/1.5);
				a[7]=130;

			bar(90+(advance/1.5),130,140+(advance/1.5),144);
			drawpoly(4,a);
			fillpoly(4,a);
			for(int d=0;d<=5;d++)
			{
				arc(100+(advance/1.5),144,180,360,d);
				arc(128+(advance/1.5),144,180,360,d);
			}

			settextstyle(6,0,2);
			outtextxy(270,210,"Please wait");
			settextstyle(6,0,5);
			outtextxy(250,220,"Loading....");
			if(advance<(getmaxx()/2)-50||advance>(getmaxx()/2)+50)
			{
				dist=50;
				cplot.circle1(advance);
				cplot.circle2(advance,dist);
				cplot.circle3(advance,dist);
				cplot.circle4(advance,dist);
				delay(sp.max_speed);
				setc1=advance;
			}
			else
			{
				if(advance==(getmaxx()/2)-50||advance-150<=(getmaxx()/2)-50||advance-150<=(getmaxx()/2)-50)
				{
					dist=50;
					cplot.circle1(setc1);
					if(advance-50==(getmaxx()/2)-50)
					cplot.circle2((getmaxx()/2)-100,dist);
					else
					{
					if(advance-50<=(getmaxx()/2)-30)
					{
						cplot.circle2(advance,dist);
						circle2set=advance;
					}
					else
					{
						cplot.circle2(circle2set,30);
					}
					}
					if(advance-100==(getmaxx()/2)-50)
					cplot.circle3((getmaxx()/2)-150,dist);
					else
					{
					if(advance-100<=(getmaxx()/2)-30)
					{
						cplot.circle3(advance,dist);
						circle3set=advance;
					}
					else
					{
						cplot.circle3(circle3set,30);
					}
					}
					if(advance-150==(getmaxx()/2)-50)
					cplot.circle4((getmaxx()/2)-200,dist);
					else
					{
					if(advance-150<=(getmaxx()/2)-30)
					{
						cplot.circle2(advance,dist);
						circle4set=advance;
					}
					else
					{
						cplot.circle4(circle4set,30);
					}
					}
					delay(sp.max_speed);
				}
				else
				{
					dist=20;
					cplot.circle1(advance);
					cplot.circle2(advance,dist);
					cplot.circle3(advance,dist);
					cplot.circle4(advance,dist);
					delay(sp.min_speed);
				}
			}
			if(advance==getmaxx()+150)
			{
				flag=1;
			}
			cleardevice();
		 }
	}
}
void second()//The run & Welcome to the game screen
{
	int x,y,i;
	int g=DETECT, d;
	initgraph(&g, &d,"C:\\TurboC3\\BGI");
	cleardevice();
	x=getmaxx()/2;
	y=getmaxy()/2;
	settextstyle(TRIPLEX_FONT,HORIZ_DIR,3);
	setcolor(7);
	int c=150;
	for(int e=0;e<20;e++)
	{
		for(int i=50;i<100;i++)
		{
			setcolor(3);
			settextstyle(SMALL_FONT, HORIZ_DIR, 10);
			outtextxy(x-10, y-10,"THE RUN");
			circle(x,y,i);
			circle(x,y,c);
			c--;
			cleardevice();
		}
	}
	setcolor(6);
	settextstyle(SMALL_FONT, HORIZ_DIR, 10);
	settextjustify(x,y);
	outtextxy(x-70,y-60,"WELCOME");
	delay(150);
	outtextxy(x-70,y-20,"TO");
	delay(150);
	outtextxy(x-10,y-20,"THE");
	delay(150);
	outtextxy(x-60,y+15,"RACE");
	//outtextxy(SMALL);
	settextstyle(SMALL_FONT, HORIZ_DIR, 5);
	outtextxy((x-90),(y+85),"Press any key to view the rules!");
	getch();
	rules();
	setcolor(6);
	cleardevice();
	settextstyle(GOTHIC_FONT,HORIZ_DIR,10);
	outtextxy(getmaxx()/2-20,getmaxy()/2-100,"3");
	sound(5000);
	delay(1000);
	cleardevice();
	outtextxy(getmaxx()/2-20,getmaxy()/2-100,"2");
	sound(3000);
	delay(1000);
	cleardevice();
	outtextxy(getmaxx()/2-20,getmaxy()/2-100,"1");
	sound(2000);
	delay(1000);
	cleardevice();
	outtextxy(getmaxx()/2-60,getmaxy()/2-100,"GO!");
	sound(1000);
	delay(1000);
	settextstyle(SMALL_FONT, HORIZ_DIR, 5);
	nosound();
}
class obstacles
{
	public:int car1(int advance,int lane)
	{
		if(lane%2==0)
		{
		bar(80,-70+advance,120,0+advance);//main car
		bar(70,-65+advance,80,-55+advance);//wheels
		bar(70,-15+advance,80,-5+advance);//wheels
		bar(120,-65+advance,130,-55+advance);//wheels
		bar(120,-15+advance,130,-5+advance);//wheels
		return (0+advance);
		}
		else
		{
		bar(280,-70+advance,320,0+advance);//main car
		bar(270,-65+advance,280,-55+advance);//wheels
		bar(270,-15+advance,280,-5+advance);//wheels
		bar(320,-65+advance,330,-55+advance);//wheels
		bar(320,-15+advance,330,-5+advance);//wheels
		return (0+advance);
		}
	}
	public:int car2(int advance, int lane)
	{
		if(lane%2==0)
		{
		bar(80,-70+advance,120,0+advance);//main car
		bar(70,-65+advance,80,-55+advance);//wheels
		bar(70,-15+advance,80,-5+advance);//wheels
		bar(120,-65+advance,130,-55+advance);//wheels
		bar(120,-15+advance,130,-5+advance);//wheels
		return (0+advance);
		}
		else
		{
		bar(280,-70+advance,320,0+advance);//main car
		bar(270,-65+advance,280,-55+advance);//wheels
		bar(270,-15+advance,280,-5+advance);//wheels
		bar(320,-65+advance,330,-55+advance);//wheels
		bar(320,-15+advance,330,-5+advance);//wheels
		return (0+advance);
		}
      }

}obs;

class powerups
{
	public:int fly(int advance,int lane)
	{
		if(lane%2==0)
		{
		circle(100,-60+advance,30);
		outtextxy(80,-30+advance,"FLY");
		return(0+advance);
		}
		else
		{
		circle(300,-60+advance,30);
		outtextxy(280,-30+advance,"FLY");
		return(0+advance);
		}
	}
}pwup;
class game_over
{
	public:void over(long score)
	{
		cleardevice();
		char score_disp[50];
		sprintf(score_disp,"SCORE:%d",score);
		for(int star=0;star<=400;star++)
		{
			settextstyle(GOTHIC_FONT,HORIZ_DIR,6);
			setfillstyle(SOLID_FILL,WHITE);
			circle(getmaxx()/2,getmaxy()/2,star);
		}
		cleardevice();
		outtextxy((getmaxx()/2)-150,(getmaxy()/2)-40,"GAME OVER!");
		settextstyle(SMALL_FONT,HORIZ_DIR,5);
		outtextxy((getmaxx()/2)-70,(getmaxy()/2)+30,score_disp);
		outtextxy((getmaxx()/2)-120,(getmaxy()/2)+60,"Press any key to exit");
		getch();
		exit(0);
	}
}gm_ovr;
class lane_generator
{
	public:int lane()
	{
		randomize();
		return (rand()%100);
	}
}generator;
void game()//The main game
{
	char score[50],pow[80];
	int j=250,ptx=100/*control variable*/,x=0,y=-1,ch,gd=DETECT,gm;
	long i=0,counter=0,obstacle1=0,obstacle2=0,flypow=0,collision1,collision2,pwrcoll,powerup=0;
	int cir_rad=30,pow_time=0,flag_for_powerup=0,c=0,a;/*control for powerup vanish after pickup*/;
	int flag_for_over=0/*if game is not over*/,reset=0/*var for controlling the appearance of the fly powerup*/,lane_generator,stop_flag=0;
	while(1)
	{
		//clearviewport();
		if(collision1>=565)
		{
			lane_generator=generator.lane();
			collision1=0;
			obstacle1=0;
		}
		setfillstyle(SOLID_FILL,WHITE);
		if(counter>=500||counter>=1000)
		{
			collision1=obs.car1(obstacle1,lane_generator);
			obstacle1++;
		}
		if(collision2>=565)
		{
			lane_generator=generator.lane();
			collision2=0;
			obstacle2=0;
		}
		setfillstyle(SOLID_FILL,WHITE);
		if(obstacle2>=500+obstacle1)
		{
			collision2=obs.car1(obstacle2,(lane_generator%2==0)?(lane_generator+1):(lane_generator-1));
			obstacle2++;
		}
		if(counter>=100)
		{
			if(flag_for_powerup==0/*&&(pwrcoll!=collision1-30||pwrcoll!=collision2-30)*/)
				pwrcoll=pwup.fly(powerup,lane_generator);
			else
			{
				c++;
				if(c==1)
					cleardevice();
			}
			powerup++;
			if(lane_generator%2==0)
			{
			if((pwrcoll==350&&ptx==100)||(ptx==100&&(pwrcoll<=455&&pwrcoll>=365)))//check whether the head of the obstacle collides with the head of our car
			{
				cir_rad=50;
				flag_for_powerup=1;
				stop_flag=1;
				pwrcoll=0;
				powerup=0;
			}
			}
			else
			{
			if((pwrcoll==350&&ptx==300)||(ptx==300&&(pwrcoll<=455&&pwrcoll>=365)))//check whether the head of the obstacle collides with the head of our car
			{
				cir_rad=50;
				flag_for_powerup=1;
				stop_flag=1;
				pwrcoll=0;
			}
			}
	     /*		if(pwrcoll>=565)
			{
				powerup=0;
				pwrcoll=0;
			}     */
			if(stop_flag==1)
			{
				pow_time++;
				sprintf(pow,"%d",700-pow_time);
				outtextxy(475,170,"FLY POWER:");
				outtextxy(500,200,pow);
			}
		}
		if(pow_time>=700)
		{
			cir_rad=30;
			//pow_time=0;
			stop_flag=0;
			reset++;
			//flag_for_powerup=0;
		}
		if(reset==300)
		{
			reset=0;
			flag_for_powerup=0;
			pow_time=0;
			pwrcoll=0;
			powerup=0;
			//stop_flag=0;
		}
		//Main Car
		bar(ptx-20,340,ptx+20,390);
		for(a=0;a<=20;a++)
		arc(ptx,340,0,180,a);
		bar(ptx-27,345,ptx-20,358);   //tyres
		bar(ptx+27,345,ptx+20,358);
		bar(ptx-27,372,ptx-20,385);
		bar(ptx+27,372,ptx+20,385);
		if(lane_generator%2==0)
		{
		if(((collision1==320&&ptx==100)||(ptx==100&&(collision1<=415&&collision1>=325)))&&(cir_rad==30))//check whether the head of the obstacle collides with the head of our car
		{
			gm_ovr.over(counter);
		}
		if(((collision2==320&&ptx==300)||(ptx==300&&(collision2<=415&&collision2>=325)))&&(cir_rad==30))//check whether the head of the obstacle collides with the head of our car
		{
			gm_ovr.over(counter);
		}
		}
		else
		{
		if(((collision1==320&&ptx==300)||(ptx==300&&(collision1<=415&&collision1>=325)))&&(cir_rad==30))//check whether the head of the obstacle collides with the head of our car
		{
			gm_ovr.over(counter);
		}
		if(((collision2==320&&ptx==100)||(ptx==100&&(collision2<=415&&collision2>=325)))&&(cir_rad==30))//check whether the head of the obstacle collides with the head of our car
		{
			gm_ovr.over(counter);
		}
		}
		outtextxy(415,400,"Press Esc to Exit..");
		rectangle(0, 0, 630, 475);
		line(400, 0, 400, 475);
		outtextxy(500,100, "SCORE");
		sprintf(score,"%d",counter);
		outtextxy(500,120,score);
		//outtextxy(500,111,counter);
		bar(197, i-37.5, 203, 0+i);
		bar(197, 37.5+i, 203, 75+i);
		bar(197, 112.5+i, 203, 150+i);
		bar(197, 187.5+i, 203, 225+i);
		bar(197, 262.5+i, 203, 300+i);
		bar(197, 337.5+i, 203, 375+i);
		bar(197, 412.5+i, 203, 475);
		if(i==75)//check to generate continuous bars
		{
			i-=75;
		}
		if(kbhit())//check to note keypress
		{
			ch=getch();//recording the keypress
			if(ch==72)      //up
			{
				x=0;
				y=-1;
			}
			if(ch==75)       //left
			{
				if(ptx==300)//to check on right margin
				{
					ptx=ptx-200;
					y=0;
				}
				else
				{
					x=0;
					y=0;
				}
			}
			if(ch==77)      //right
			{
				if(ptx==100)//to check on left margin				{
				{
					ptx=ptx+200;
					y=0;
				}
				else
				{
					x=0;
					y=0;
				}
			}
			if(ch==80)      //down
			{
				x=0;
				y=1;
			}
			if(ch==27)//exit
			{
			       exit(0);
			}
			//ptx=ptx+x;
			//j=j+y;
		}
		sound(i+600);
		if(counter<=500)
			delay(4);
		else if(counter>500&&counter<=2560)
			delay(2);
		else if(counter>2560&&counter<=3800)
			delay(1.7);
		else if(counter>3800&&counter<=5000)
			delay(1.5);
		else if(counter>5000&&counter<=7000)
			delay(1);
		else
			delay(0.2);
		nosound();
		i++;
		counter++;

		/*Anti-Flicker Treatment(Currently Not Working)
		int poly[10];
		poly[0]=0;
		poly[1]=0;
		poly[2]=getmaxx();
		poly[3]=0;
		poly[4]=getmaxx();
		poly[5]=getmaxy();
		poly[6]=0;
		poly[7]=getmaxy();
		poly[8]=poly[0];
		poly[9]=poly[1];
		setfillstyle(SOLID_FILL,BLACK);
		drawpoly(5,poly);
		fillpoly(4,poly);
		*/
		cleardevice();
	}

}