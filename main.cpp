//#define NOMINMAX
#include <Windows.h>
#include <stdio.h>
#include<iostream>
//#include <fstream>
using namespace std;
#include"head.h"
//#include"resource.h"
//#include<easyx.h>
int main(int aegc, char* argv[])
{

	//执行器
//	printf("执行器6.1\n");
//	printf("将文件拖到此程序上执行\n按 B 或 S 可强制关闭程序\n已录入特殊键：teb,esc,return,up,down,copy,past,delete,all\n");
//	printf("开始\n-------------------------\n");
	FILE* fp;
	errno_t err = 0;
	//选择文件打开方式
	if (aegc == 1)
	{
		printf("执行系统1.4		集坐标查看/计算，命令记录/执行于一体\n新增命令：\n");
		printf("cak,x,y,r,g,b,		 	检查x，y坐标处的像素是否与r,g,b匹配,若不匹配则暂停执行\n");
		printf("pas,str		 	pas-暂停，str-在窗口中的提示信息\n");
		printf("\".file\"			使用相对路径调用程序(当前目录)\n");
		printf("c，str			将str复制到剪切板，与k,p配合使用\n");
		printf("i，int，int			初始化鼠标指针，默认为0,0 ；只能在组循环外使用\n");
		printf("m，int，int			移动鼠标指针，只能在组循环中使用\n");
		printf("l,x,y  | r,x,y | s,x,y	 使用鼠标指针变量，只能在组循环中使用\n");
		system("pause");
		//记录器 生成记录文件，不操作
printf("此程序记录操作步骤\n");
printf("输入help查看帮助\n");
printf("开始\n----------------------\n");
bool go=1;
short num = 0;		//命令数量
short a = 0;
POINT xy;
char fname[20] = { 0 };
printf("请输入文件名：\n");
scanf_s("%s", fname);
link(fname, ".txt");
put_str(fname);
putchar(10);
//打开文件
FILE* fp;
errno_t err = 0;
err = fopen_s(&fp, fname, "w");
if (err == 0)
	printf("文件打开成功");
else
	printf("文件打开失败");
putchar(10);
//实现
	char plan[10] = { 0 };
	char os;
	short temp=0;
	bool ism = 0 ,isc=0;		//是否是 鼠标命令，命令
while (go)
{
	printf("请输入命令：		命令数：%d\n",num);
	scanf_s("%s", plan);
	ism = 0;
	isc = 0;
	if (is_str(plan, "l") || is_str(plan, "ls") || is_str(plan, "r"))
	{
		ism = 1;
		isc = 1;
	}
	if (is_str(plan, "l"))
		os = 'l';
	if (is_str(plan, "ls"))
		os = 's';
	if (is_str(plan, "r"))
		os = 'r';
		//将a存入文件
	if (ism)				//获取坐标（公用代码）
		{
		//input_file(fp, a);
		fputc(os, fp);
		fputc(',', fp);			
		char c0[5] = { 0 };
		printf("请指定点击位置 ，输入1确定\n");
			scanf_s("%s", c0);
			GetCursorPos(&xy);
			printf(" 记录坐标： x=%d,y=%d \n", xy.x, xy.y);
			//将坐标存入文件
			input_file(fp, xy.x);
			fputc(',', fp);
			input_file(fp, xy.y);
		}				
	if(is_str(plan,"key"))    //键盘操作
	{
		isc = 1;
		char pram;
		//将键值存入文件
		printf("请输入键值：\n");
	    scanf_s("%s", &pram);
		fputs("k,", fp);
		fputc(pram, fp);
	}
	if (is_str(plan, "//"))    //注释
	{
		isc = 1;
		num--;
		char pram[30];
		//将键值存入文件
		printf("请输入注释：\n");
		scanf_s("%s", pram);
		fseek(fp, -2, SEEK_CUR);
		fputs("\t\t#", fp);
		fputs(pram, fp);
		putc('\n', fp);
	}
	if (is_str(plan, "begin"))
	{
		isc = 1;
		fputc('{', fp);
	}
	if (is_str(plan, "end"))
	{
		short t = 1;
		isc = 1;
		fputs("},", fp);
		printf("请输入循环次数：\n");
		scanf_s("%d", &t);
		if (t < 1)
			t = 1;
		input_file(fp, t);
	}
	if (is_str(plan, "time"))
	{
		isc = 1;
		short d = 500 ,t;
		fputc('t', fp);
		fputc(',', fp);
		printf("请输入时间：(单位0.5秒)\n");
		scanf_s("%d", &t);
		if (t < 1)
			t = 1;
		t = t * d;
		input_file(fp,t);
	}
	if (is_str(plan, "wind"))
	{
		isc = 1;
		fputc('w', fp);
	}
	if (is_str(plan, "clip"))
	{
		isc = 1;
		char datas[20] = { 0 };
		fputc('c', fp);
		fputc(',', fp);
		printf("请输入数据\n");
		scanf_s("%s", datas);
		fputs(datas, fp);
	}
	if (is_str(plan, "dist"))
	{
		isc = 1, num--;
		POINT xy2;
		char c0[5] = { 0 };
		printf("请指定第一点 ，输入1确定\n");
		scanf_s("%s", c0);
		GetCursorPos(&xy);
		printf("请指定第二点 ，输入1确定\n");
		scanf_s("%s", c0);
		GetCursorPos(&xy2);
		xy.x = xy2.x - xy.x;
		xy.y = xy2.y - xy.y;
		printf("坐标差： x2-x1=%d,y2-y1=%d \n", xy.x, xy.y);

	}
	if (is_str(plan, "xy"))
	{
		bool a;
		POINT m_xy;
		HDC hdc = GetDC(GetDesktopWindow());
		COLORREF now;
		while (1)
		{
			system("cls");
			a = GetCursorPos(&m_xy);
			now = GetPixel(hdc, m_xy.x, m_xy.y);
			if (a)
				printf(" 坐标： x=%d,y=%d      按B结束\n", m_xy.x, m_xy.y),
				printf(" 像素值： R=%d, G=%d, B=%d     \n\n按B或ESC结束\n", GetRValue(now), GetGValue(now), GetBValue(now));
			Sleep(700);
			if (GetAsyncKeyState('B')|| GetAsyncKeyState(VK_ESCAPE))
				break;
		}
		isc = 1, num--;
	//	fflush(stdin);
	}
	if (is_str(plan, "pas"))
	{
		char tip[15] = { 0 };
		fputs("pas,",fp);
		printf("请输入提示信息：\n");
		scanf_s("%s", tip);
		fputs(tip,fp);
		isc = 1;
	}
	if (is_str(plan, "chak"))//像素检查
	{

		fputs("cak,", fp);
		char c0[5] = { 0 };
		printf("请指定检查位置 ，输入1确定\n");
		scanf_s("%s", c0);
		GetCursorPos(&xy);
		printf(" 记录坐标： x=%d,y=%d \n", xy.x, xy.y);
		//将坐标存入文件
		input_file(fp, xy.x);
		fputc(',', fp);
		input_file(fp, xy.y);
		fputc(',', fp);



		HDC hdc = GetDC(GetDesktopWindow());
		COLORREF now;
				
			now = GetPixel(hdc, xy.x, xy.y);
		
			printf(" 像素值： R=%d, G=%d, B=%d     \n", GetRValue(now), GetGValue(now), GetBValue(now));
			input_file(fp, GetRValue(now));
			fputc(',', fp);
			input_file(fp, GetGValue(now));
			fputc(',', fp);
			input_file(fp, GetBValue(now));
			fputc(',', fp);
				
		isc = 1;

	}
	if (is_str(plan, "help"))
	{
		isc = 1;
		num--;
		printf("特殊键规则(键值)：\n");
		printf("t---teb\n");
		printf("e---esc\n");
		printf("r---return\n");
		printf("u---up\n");
		printf("d---down\na---contre+A\nb---delete\nc---copy\np---past\ns---alt+F4\n\n");
		printf("命令列表：\n");
		printf("l-------左键\nls------双击\nr-------右键\nkey-----按键\nwind----最大化窗口\ntime----延时\nchak----检查指定点像素值\npas----暂停\ndist----坐标距离计算\nxy-----查看坐标\nclip-----将数据送入剪切板\ncls-----清屏\n//------添加注释\nbegin---组循环开始\nend-----组循环结束\nexit----退出\n");
	}
	if (is_str(plan, "cls"))
	{
		isc = 1;
		num--;
		system("cls");
	}
	if (is_str(plan, "exit"))
		break;					
	if(num==temp && isc==1)
	fputs("\n",fp);
	if(isc==0)
	{
		printf("无效命令\n");
		num--;
	}
	num++;
	temp = num;
	printf("\n");
}
fclose(fp);
return 0;
	}
	err = fopen_s(&fp, argv[1], "r");
	//判断是否成功
	if (err == 0)
		printf("文件打开成功");
	else
	{
		printf("文件打开失败");
		system("pause");
		return 0;
	}
	putchar(10);
	//最小化窗口
	Sleep(500);
	HWND me = GetForegroundWindow();
	ShowWindow(me, 6);
	//准备变量
	byte run_speed = 50;
	short x0 = 0, y0 = 0;			//鼠标默认指针
	bool go = 1;
	short i = 0, j = 0;
	char key, ch;
	char msg[20] = { 0 };
//	char backup[15] = { 0 };			//单循环准备
	short  coms = 0, redos = 1;				//循环控制变量
	bool isre = 0, isgo = 1;						//多循环开始标志
	char msgs[15][15] = { 0 };				//多循环准备
	short ncoms = 0;				//组内命令数量
	while (EOF != (ch = getc(fp)))		//读取文件
	{

		if (ch == '#')				//注释内容自动跳过		
			isgo = 0;
		if (ch == '\n')				//注释结束
			isgo = 1;
		if (isgo)
		{
			if (ch != '\n' && ch != 32 && ch != '\t')			// 空格不记入命令
				msg[i] = ch;
			i++;
			//	redos = 1;
			if (ch == '\n')
			{
				//	short var[5] = { 0 };	//设置变量
				if (msg[0] == '{')				//组循环开始	//若无循环体则自动跳过			
					isre = 1;
				if (msg[0] == '}')				//组循环结束
				{
					isre = 0;
					put_str(msg + 2);
					redos = str_int(msg + 2);
					for (; redos > 0; redos--)			//组循环
					{
						printf("组循环次数：%d\n", redos);
						printf("组内执行次数：%d\n", ncoms);
						short i1 = 0;
						coms = 0;
						for (; i1 < ncoms; i1++) {					//组内循环											
							if (ch == '\n')				 //处理一条命令
							{
								printf("执行内容： ");
								put_str(msgs[coms]);
								putchar(10);
								//	i = 0;	//	下一条命令的准备	

								if (msgs[coms][0] == 'k')
								{
									key = msgs[coms][2];
									if (key < 91)		//大写字母
										keyput(key);
									else
									{
										if (key == 'a')						//全选
											contre_key('A');
										if (key == 'c')						//复制
											contre_key('C');
										if (key == 'p')						//粘贴
											contre_key('V');
										if (key == 'b')						//删除
											keyput_all(VK_DELETE);
										if (key == 'e')
											keyput_all(VK_ESCAPE);
										if (key == 'r')
											keyput_all(VK_RETURN);
										if (key == 't')
											keyput_all(VK_TAB);
										if (key == 'u')
											keyput_all(VK_UP);
										if (key == 'd')
											keyput_all(VK_DOWN);
										if (key == 's')
											alt_key(VK_F4);
										if (key == 'w')
											win_key('D');
									}
									//	printf("键值：%c\n", key);
								}
								if (msgs[coms][0] == 't')
								{
									short t;
									t = str_int(msgs[coms] + 2);
									Sleep(t);
								}
								if (msgs[coms][0] == 'm')		//移动默认指针
								{
									char sx[10] = { 0 };
									POINT xy;
									short  j = 0;
									j = cutstr_head(msgs[coms] + 2, ',', sx);
									xy.x = str_int2(sx);
									xy.y = str_int2(msgs[coms] + 2 + j);
									x0 += xy.x;
									y0 += xy.y;
									cout << "m,x=" << xy.x << endl;
									cout << "m,y=" << xy.y << endl;
								}
								if (msgs[coms][0] == 'w')
								{
									HWND wind = GetForegroundWindow();
									ShowWindow(wind, SW_MAXIMIZE);
								}
								if (msgs[coms][0] == 'l' || msgs[coms][0] == 's' || msgs[coms][0] == 'r')			//mouse
								{
									if (msgs[coms][2] > 58)
									{
										POINT xy;
										xy.x = x0;
										xy.y = y0;
										if (msgs[coms][0] == 'l')
											left_click(xy.x, xy.y);
										if (msgs[coms][0] == 'r')
											right_click(xy.x, xy.y);
										if (msgs[coms][0] == 's')
											left_clicks(xy.x, xy.y);
										cout << "坐标：x0=" << x0 << endl;
										cout << "y0=" << y0 << endl;
									}
									else
									{
										char sx[10] = { 0 };
										POINT xy;
										short  j = 0;
										j = cutstr_head(msgs[coms] + 2, ',', sx);
										xy.x = str_int(sx);
										xy.y = str_int(msgs[coms] + 2 + j);
										if (msgs[coms][0] == 'l')
											left_click(xy.x, xy.y);
										if (msgs[coms][0] == 'r')
											right_click(xy.x, xy.y);
										if (msgs[coms][0] == 's')
											left_clicks(xy.x, xy.y);
									}
								}

						//		do_command(msgs[coms]);
								if (msgs[coms][0] == 'm')
									//移动默认指针
{
	char sx[10] = { 0 };
	POINT xy;
	short  j = 0;
	j = cutstr_head(msgs[coms] + 2, ',', sx);
	xy.x = str_int2(sx);
	xy.y = str_int2(msgs[coms] + 2 + j);
	x0 += xy.x;
	y0 += xy.y;
	cout << "m,x=" << xy.x << endl;
	cout << "m,y=" << xy.y << endl;
}


								//	清空缓存信息
								Sleep(run_speed);				//控制执行速度
								if (GetAsyncKeyState('B') || GetAsyncKeyState('S') || GetAsyncKeyState(VK_ESCAPE))
									return 0;
								//	printf("循环次数：%d\n", redo);
								coms++;
							}
						}
					}
				}
				if (isre)					//记录循环组内容
				{
					if (msg[0] != '{' && msg[0] != '}')
					{
						copy_str(msgs[coms], msg);
						printf("msgs[%d]=", coms);
						put_str(msgs[coms]);
						printf("\n");
						coms++;
						ncoms = coms;
						clear_str(msg);
					}
				}
			}
			//0					
			if (ch == '\n')				 //处理一条命令  
				{
					printf("command:\n");
					put_str(msg);
					putchar(10);
					i = 0;
					//	下一条命令的准备
					if (!isre)				//避免重复执行{}内和f上的命令
					{
						if (msg[0] == 'k')
						{
							key = msg[2];
							if (key < 91)		//大写字母
								keyput(key);
							else
							{
								if (key == 'a')						//全选
									contre_key('A');
								if (key == 'c')						//复制
									contre_key('C');
								if (key == 'p')						//粘贴
									contre_key('V');
								if (key == 'b')						//删除
									keyput_all(VK_DELETE);
								if (key == 'e')
									keyput_all(VK_ESCAPE);
								if (key == 'r')
									keyput_all(VK_RETURN);
								if (key == 't')
									keyput_all(VK_TAB);
								if (key == 'u')
									keyput_all(VK_UP);
								if (key == 'd')
									keyput_all(VK_DOWN);
								if (key == 's')
									alt_key(VK_F4);
								if (key == 'w')
									win_key('D');
							}
							//	printf("键值：%c\n", key);
						}
						if (msg[0] == 't')
						{
							short t;
							t = str_int(msg + 2);
							Sleep(t);
						}
						if (msg[0] == 'w')
						{
							HWND wind = GetForegroundWindow();
							ShowWindow(wind, SW_MAXIMIZE);
						}
						if (msg[0] == '"')				//调用exe,bat				
						{
							char file[20] = { 0 };		//文件名
							dele_char(msg + 1, '"');		//去除末尾的 "
							char path[40] = { 0 };

							if (msg[1] == '.')	//使用相对路径
							{
								ShellExecute(0, "open", msg+2, 0, 0, 1);
							}
							else {
								short sit = find_char_end(msg + 1, '\\');
								for (int i = 0; i < sit; i++)
								{
									path[i] = msg[i + 1];					//获取路径
								}
								for (int i = sit, j = 0; msg[i] != '\0' && msg[i] != '\n'; i++, j++)		//获取文件名
									file[j] = msg[i + 2];
								put_str(path);		//测试代码
								putchar(10);
								put_str(file);
								//打开文件
								ShellExecute(0, "open", file, 0, path, 1);
							}
						}
						if (msg[0] == 'l' || msg[0] == 's' || msg[0] == 'r')			//mouse
						{
							char sx[10] = { 0 };
							POINT xy;
							short  j = 0;
							j = cutstr_head(msg + 2, ',', sx);
							//	put_str(sx);		//x
							//	putchar(10);
							//	put_str(msg+j+2);    //y
							//	putchar(10);
							xy.x = str_int(sx);
							xy.y = str_int(msg + j + 2);
							//	printf("x=%d\n", xy.x);
							//	printf("y=%d\n", xy.y);
							//	printf("msg=");
							//	put_str(msg);
							//	putchar(10);
							if (msg[0] == 'l')
								left_click(xy.x, xy.y);
							if (msg[0] == 'r')
								right_click(xy.x, xy.y);
							if (msg[0] == 's')
								left_clicks(xy.x, xy.y);
							cout << "点击位置：xy.x=" << xy.x << endl;
							cout << "xy.y=" << xy.y << endl;
						}
						if (msg[0] == 'i')		//初始化默认指针
						{
							char sx[10] = { 0 };
							short  j = 0;
							j = cutstr_head(msg + 2, ',', sx);
							x0 = str_int(sx);
							y0 = str_int(msg + j + 2);
							cout << "init :x0=" << x0 << endl;
							cout << "y0=" << y0 << endl;
						}
						if (msg[0] == 'c')		//剪切板
						{
							SetDataToClip(msg + 2);
						
						}
						if (msg[0] == 'p')	//暂停
						{
							if (msg[1] == 'a' && msg[2] == 's') {
								system("cls");
								ShowWindow(me, SW_NORMAL);
								MoveWindow(me, 0, 0, 600, 130, 1);
								printf("%s\n",msg+4);
								printf("暂停中\n");
								system("pause");
								ShowWindow(me, SW_MINIMIZE);
							}
						}
						if (msg[0] == 'c')		//检查指定位置的像素
						{
							if (msg[1] == 'a' && msg[2] == 'k')
							{
								byte r, g, b;
								short x, y;
								x = get_int_ByIndex(msg, 2);
								y = get_int_ByIndex(msg, 3);
								r = get_int_ByIndex(msg, 4);
								g = get_int_ByIndex(msg, 5);
								b = get_int_ByIndex(msg, 6);

								COLORREF now;
								HDC hdc = GetDC(GetDesktopWindow());
								now = GetPixel(hdc, x, y);
								if (GetRValue(now) != r || GetGValue(now) != g || GetBValue(now) != b)
								{
									//	printf("x=%d,y=%d\nr=%d,g=%d,b=%d\n",x,y,r,g,b);
									ShowWindow(me, SW_NORMAL);
									MoveWindow(me, 0, 0, 600, 330, 1);
									printf("像素匹配错误\n");
									printf("暂停中\n");
									system("pause");
									ShowWindow(me, SW_MINIMIZE);
								}

							}
						}
						//	do_command(msg);

						clear_str(msg);			//清空缓存信息
						Sleep(run_speed);				//控制执行速度
						if (GetAsyncKeyState('B') || GetAsyncKeyState('S') || GetAsyncKeyState(VK_ESCAPE))			//退出程序
							return 0;
					}

				}				
		}

	}
	fclose(fp);
	//system("pause");
//	Sleep(5000);

			////去除空行
		//printf("开始\n-------------------------\n");
		//FILE* fp, * out;
		//errno_t err = 0;
		////选择文件打开方式
		//if (aegc == 1)
		//{
		//	char p = 0;
		//	cout << "参数设置：\ns.去空格 space     	r.去空行 return 	   a.都去 all\n";
		//	cin >> p;
		//	FILE* param;
		//	fopen_s(&param, "param.txt", "w");
		//	fputc(p, param);
		//	fclose(param);
		//	cout << "参数设置完成，将待处理文件拖到图标上执行\n";
		//	Sleep(2000);
		//	return 0;
		//}
		//err = fopen_s(&fp, argv[1], "r");
		////判断是否成功
		//if (err == 0)
		//	printf("文件打开成功");
		//else
		//{
		//	printf("文件打开失败");
		//	system("pause");
		//	return 0;
		//}
		//putchar(10);
		//fopen_s(&out, "out.txt", "w");
		//char ch2 = 0, ch, p;
		//p = get_filechar("param.txt");
		//cout << "mode : " << p << endl;
		////printf("value %d\n", p);
		//while (EOF != (ch = getc(fp)))		//读取文件
		//{
		//	if ((ch == ch2) && ch == '\n' && (p == 'r' || p == 'a'))				//注释结束
		//		cout << "有空行\n";
		//	else
		//	{
		//		if ((ch == 32 || ch == '\t') && (p == 's' || p == 'a'))
		//			cout << "有空格\n";
		//		else
		//			fputc(ch, out);
		//	}
		//	ch2 = ch;
		//}
		//fclose(fp);
		//fclose(out);
		//Sleep(1000);
		////system("pause");

			////自动断行
		//FILE* fp, * out;
		////选择文件打开方式
		//if (aegc == 1)
		//{
		//	char p = 0;
		//	printf("原理：程序自动在句号后加回车\n");
		//	printf("开始\n-------------------------\n");
		//	cout << "参数设置：\n断行标志：1.中文句号		0.英文句号\n";
		//	cin >> p;
		//	FILE* param;
		//	fopen_s(&param, "param_cut.txt", "w");
		//	fputc(p, param);
		//	fclose(param);
		//	cout << "参数设置完成，将待处理文件拖到图标上执行\n";
		//	Sleep(1500);
		//	return 0;
		//}
		////ifstream File(argv[1], ios::in); //以文本模式打开in.txt备读putchar(10);
		////cout<<File.rdbuf();
		//short n = 0 ,n2=0;
		//fopen_s(&fp, argv[1],"r");
		//fopen_s(&out, "out_cut.txt","w");
		//char ch2 = 0, ch, p;
		//p = get_filechar("param_cut.txt");
		//cout << "mode : " << p << endl;
		////printf("value %d\n", p);
		//while (EOF != (ch = getc(fp)))		//读取文件
		//{
		//	if (p == '1') {
		//		fputc(ch, out);
		//		if (ch == -93 && ch2 == -95)
		//			n++,
		//			fputc('\n', out);
		//		if (n2 != n)
		//			printf("cut %d\n", n);
		//		ch2 = ch;
		//		n2 = n;
		//	}
		//	else
		//	{
		//		fputc(ch, out);
		//		if (ch == '.')
		//			n++,
		//			fputc('\n', out);
		//		if (n2 != n)
		//			printf("cut %d\n", n);
		//		ch2 = ch;
		//		n2 = n;
		//	}
		////	printf("%c", ch);
		//}
		//printf("cut all: %d\n", n);
		//fclose(fp);
		//fclose(out);
		//Sleep(2000);
		////system("pause");

			//initgraph(900, 700);
			//short num = 0;
			//buttum left, right, lefts, key ,time ,enter;
			//input_box input;
			//point xy;
			//xy.init(100, 100);	
			//input.init(xy.get_xy(300, 220), xy.get_xy(390, 260));
			//enter.setcolor(RED, RGB(71,203,203));
			//setbkcolor(WHITE);
			//cleardevice();
			//MOUSEMSG m;
			//m = GetMouseMsg();
			//while (1)
			//{
			////
			//	BeginBatchDraw();
			//	cleardevice();
			//	m = GetMouseMsg();
			//	left.init(xy, xy.get_xy(200, 70), "左键单击");
			//	right.init(xy.get_xy(300,0), xy.get_xy(500, 70), "右键单击");
			//	lefts.init(xy.get_xy(0, 150), xy.get_xy(200, 220), "左键双击");
			//	key.init(xy.get_xy(300,150),xy.get_xy(500,220),"键盘操作");
			//	enter.init(xy.get_xy(100,400),xy.get_xy(300,500) , "确定");
			//	outtextxy(770, 70, "命令数：");
			//	out_int(800, 100, num);
			//	input.draw_box();
			//	input.run(m);
			//	if(left.buttum_switch(m)) 
			//	{
			//		left.ison = 1;
			//		right.ison = 0;
			//		lefts.ison = 0;
			//		key.ison = 0;
			//	}
			//	if (right.buttum_switch(m)) 
			//	{
			//		left.ison = 0;
			//		right.ison = 1;
			//		lefts.ison = 0;
			//		key.ison = 0;
			//	}
			//	if (lefts.buttum_switch(m)) 
			//	{
			//		left.ison = 0;
			//		right.ison = 0;
			//		lefts.ison = 1;
			//		key.ison = 0;
			//	}
			//	if (key.buttum_switch(m)) 
			//	{
			//		left.ison = 0;
			//		right.ison = 0;
			//		lefts.ison = 0;
			//		key.ison = 1;
			//	}
			//	if (enter.buttum_switch(m))
			//	{
			//		num++;
			//		if (left.ison)
			//		{
			//		}
			//	}
			//	Sleep(30);
			//	EndBatchDraw();
			//	FlushMouseMsgBuffer();
			//	
			//}

//	system("pause");
}