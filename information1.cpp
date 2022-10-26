#include<iostream>
#include<string>
#include<sstream>
#include<fstream>
#include<windows.h>
#include<bitset>

#define KEY_DOWN(VK_NONAME) ((GetAsyncKeyState(VK_NONAME) & 0x8000) ? 1:0) 
using namespace std;

struct chassis                        //结构体定义部分 
{
	string code;
	string model="SCOUT MINI";
	int wheel_base=451;
	int tread=490;
	int minimum_ground_clearance=115;
	int minimum_turning_radius=0;
	string drive_form="4WD";
	int maximum_distance=10;
	string wheel_model1="公路轮";
	string wheel_model2="麦克纳姆轮";
	int wheel_size=175;
};

struct AGX_component
{
	string model="AGX Xavier";
	int AI=32;
	int CUDA_CORE=512;
	int Tensor_CORE=64;
	int VRAM=32;
	int ROM=32;
	
}A;

struct camera
{
	string model="RealSense D435i";
	string cam="D430";
	string RGB_resolution="1920*1080";
	int RGB_FPS=30;
	string FOV="87*50";
	int depth_FPS=90;
}C;

struct Radar
{
	string model="RS-Helios-16p";
	int channel=16;
	int range=100;
	int power=8;
}R;

struct gyroscope
{
	string model="CH110";
	string producer="NXP";
}G;
struct display
{
	int size=11.6;
	string model="super";
}D;

struct battery
{
	string parameter="24V/15Ah";
	int output_voltage=24;
	int charge_time=2; 
}B;

struct student
{
	int ID;
	string name;
};

	struct CAR
{
	string ID;
	chassis CAR_chassis;
	AGX_component CAR_AGX;
	camera Dual_camera;
	Radar LADAR;
	gyroscope G_gyro;
	display LCD;
	battery BAT;
	student get_student;
	
};

bitset<30>down;                           //当前键盘按下状态
bitset<30>pre;                            //前一时刻键盘按下状态
void check(char c){                      //检测某个按键是否按下，按下将改变bitset数组中对应的元素 
	if(!KEY_DOWN(c))down[c-'A']=0;
	else down[c-'A']=1;
}




void gotoxy(int x, int y) {                     //用于移动光标 
	COORD pos = {x,y};
	HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(hOut, pos);
}


int main()
{
	chassis car_chas[10];
	student student[10];
	CAR MINI_CAR[10];
	for(int i=0;i<=9;i++)
	{
		string s1="dp",s2="adb";
		ostringstream chas_code;                
		chas_code<<s1<<i+10000001<<s2;          // //使用ostringstream 格式化字符串   生成编号 
		car_chas[i].code=chas_code.str();       //初始化底盘结构体 
	}

 string Student_name[10]={"小鹏","小李","小张","小强","小王","小新","小刘","小芳","小佑","小五"};
 for(int j=0;j<=9;j++)
 {
 	student[j].ID=j+20192000;
 	student[j].name=Student_name[j];       //初始化学生结构体 
 }
 
 for(int k=0;k<=9;k++)                    //初始化小车结构体 
 {
 	    string s1="cqusn",s2="agx";
		ostringstream car_code;                  
		car_code<<s1<<k+1524200000000000<<s2;  // 使用ostringstream 格式化字符串  生成编号 
		MINI_CAR[k].ID=car_code.str(); 
		MINI_CAR[k].CAR_chassis=car_chas[k];
		MINI_CAR[k].CAR_AGX=A;
		MINI_CAR[k].BAT=B;
		MINI_CAR[k].G_gyro=G;
		MINI_CAR[k].LADAR=R;
		MINI_CAR[k].LCD=D;
		MINI_CAR[k].get_student=student[k];   //分配学生 
		
 }                                          
 
 
    fstream dataFile("小车分配信息.txt",ios::out);
    if(!dataFile)
    {
    	cout<<"文件打开失败";
		exit(0); 
	}
 
for(int k=0;k<=9;k++)        //进行文件写入 
{

	    dataFile<<"车辆编号："<<MINI_CAR[k].ID<<' '<<endl;
	   
	    dataFile<<"所属学生:"<<MINI_CAR[k].get_student.name<<" 学号："<<MINI_CAR[k].get_student.ID<<endl<<endl;
	    
	    
	    dataFile<<"底盘"<<endl;
		dataFile<<"底盘编号"<<":"<<MINI_CAR[k].CAR_chassis.code<<endl; 
		dataFile<<"底盘型号"<<":"<<MINI_CAR[k].CAR_chassis.model<<endl;
		dataFile<<"轴距"<<":"<<MINI_CAR[k].CAR_chassis.wheel_base<<"mm"<<endl;
		dataFile<<"轮距"<<":"<<MINI_CAR[k].CAR_chassis.tread<<"mm"<<endl;
		dataFile<<"最小离地间隙"<<":"<<MINI_CAR[k].CAR_chassis.minimum_ground_clearance<<"mm"<<endl;
		dataFile<<"最小转弯半径"<<":"<<MINI_CAR[k].CAR_chassis.minimum_turning_radius<<"m"<<endl;
		dataFile<<"驱动形式"<<":"<<MINI_CAR[k].CAR_chassis.drive_form<<endl;
		dataFile<<"最大行程"<<":"<<MINI_CAR[k].CAR_chassis.maximum_distance<<"KM"<<endl;
		dataFile<<"轮胎型号"<<":"<<MINI_CAR[k].CAR_chassis.wheel_model1<<','<<MINI_CAR[k].CAR_chassis.wheel_model2<<endl;
		dataFile<<"轮胎尺寸"<<":"<<MINI_CAR[k].CAR_chassis.wheel_size<<"mm"<<endl<<endl;
		
		dataFile<<"AGX套件"<<endl;
		dataFile<<"型号"<<":"<<MINI_CAR[k].CAR_AGX.model<<endl;
		dataFile<<"AI"<<":"<<MINI_CAR[k].CAR_AGX.AI<<" TOPS"<<endl;
		dataFile<<"CUDA核心"<<":"<<MINI_CAR[k].CAR_AGX.CUDA_CORE<<endl;
		dataFile<<"Tensor CORE"<<":"<<MINI_CAR[k].CAR_AGX.Tensor_CORE<<endl;
		dataFile<<"显存"<<":"<<MINI_CAR[k].CAR_AGX.VRAM<<"G"<<endl;
		dataFile<<"存储"<<":"<<MINI_CAR[k].CAR_AGX.ROM<<"G"<<endl<<endl;
		
		dataFile<<"双目摄像头"<<endl;
		dataFile<<"型号"<<":"<<MINI_CAR[k].Dual_camera.model<<endl;
		dataFile<<"摄像头"<<":"<<MINI_CAR[k].Dual_camera.cam<<endl;
		dataFile<<"RGB分辨率"<<":"<<MINI_CAR[k].Dual_camera.RGB_resolution<<endl;
		dataFile<<"RGB帧率"<<":"<<MINI_CAR[k].Dual_camera.RGB_FPS<<endl;
		dataFile<<"FOV"<<":"<<MINI_CAR[k].Dual_camera.FOV<<endl;
		dataFile<<"深度帧率"<<":"<<MINI_CAR[k].Dual_camera.depth_FPS<<endl<<endl;
		
		dataFile<<"多线激光雷达"<<endl;
		dataFile<<"型号"<<":"<<MINI_CAR[k].LADAR.model<<endl;
		dataFile<<"通道数"<<":"<<MINI_CAR[k].LADAR.channel<<endl;
		dataFile<<"测试范围"<<":"<<MINI_CAR[k].LADAR.range<<"m"<<endl;
		dataFile<<"功耗"<<":"<<MINI_CAR[k].LADAR.power<<"w"<<endl<<endl;
		
		dataFile<<"g轴陀螺仪"<<endl;
		dataFile<<"型号"<<":"<<MINI_CAR[k].G_gyro.model<<endl;
		dataFile<<"厂家"<<":"<<MINI_CAR[k].G_gyro.producer<<endl<<endl;
		
		dataFile<<"液晶显示屏"<<endl;
		dataFile<<"型号"<<":"<<MINI_CAR[k].LCD.size<<endl;
		dataFile<<"尺寸"<<":"<<MINI_CAR[k].LCD.model<<endl<<endl;
		
		dataFile<<"电池模块"<<endl;
		dataFile<<"参数"<<":"<<MINI_CAR[k].BAT.parameter<<endl;
		dataFile<<"对外供电"<<":"<<MINI_CAR[k].BAT.output_voltage<<"V"<<endl;
		dataFile<<"充电时长"<<":"<<MINI_CAR[k].BAT.charge_time<<"h                "<<endl<<endl<<'%';
		//以 %符号作为结束符 
		

}                      
 
 dataFile.close();
 
 dataFile.open("小车分配信息.txt",ios::in);
 if(!dataFile)
    {
    	cout<<"文件打开失败";
		exit(0); 
	}
 

int position=0;        //记录下一个要显示的小车是第几个 
char input;
while(1)               //屏幕显示部分 
{
        
         pre=down;

        for(int i=0; i<26; i++)         //循环检查是否有按键按下 
		  {
            check(char('A'+i));
          }

        if(pre!=down&&down[13]==1&&position<=9)     //按键状态改变且N处于按下状态 
        {
        	position++;                //定位到下一个小车 
            gotoxy(0,0);               //移动光标到最左上角，覆盖输出 
           
        	dataFile.seekg(0, ios::beg);   //将文件流的 读指针 定位到起始位置 
			for(int b=0;b<position;b++)
		   {
        	 while(!dataFile.eof())
           	   {
                
		        dataFile.get(input);
		        if(input=='%')                 //遇到结束符退出本次数据读取 
		        break;
		        
		        if(b==position-1)  //仅当循环到达指定小车位置时才显示 ，避免闪烁 
		        cout<<input;
         	   } 
           }
 	
		}
		
		else if(pre!=down&&down[15]==1&&position>1)
	    {
        	position--;                        //定位到前一个小车 
            gotoxy(0,0);
           
        	dataFile.seekg(0, ios::beg);
			for(int b=0;b<position;b++)
			{

        	  while(!dataFile.eof())
           	  {
                
		        dataFile.get(input);
		        
		        if(input=='%')
		        break;
		        
		        if(b==position-1)
		        cout<<input;

         	  }
            }

		}

        Sleep(20);//循环时间间隔
}


dataFile.close(); 
	
	return 0;
}