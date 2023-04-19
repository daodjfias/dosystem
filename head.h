#pragma once
//#include"F:\desktop\code\c\头文件\str.h"
//#include"F:\desktop\code\c\头文件\graph.h"
//#include"F:\desktop\code\c\头文件\win.h"

char get_filechar(const char* filename)			//读取文件第一个字符
{
	char ch = 0;
	FILE* fp;
	fopen_s(&fp,filename, "r");
	ch = fgetc(fp);
	fclose(fp);
	return ch;
}

void left_click(int x, int y)
{
	SetCursorPos(x, y);
	mouse_event(MOUSEEVENTF_LEFTDOWN, 0, 0, 0, 0);
	Sleep(50);
	mouse_event(MOUSEEVENTF_LEFTUP, 0, 0, 0, 0);
	Sleep(50);
}

void left_clicks(int x,int y)
{
	SetCursorPos(x,y);
	mouse_event(MOUSEEVENTF_LEFTDOWN, 0, 0, 0, 0);
	Sleep(50);
	mouse_event(MOUSEEVENTF_LEFTUP, 0, 0, 0, 0);
	Sleep(50);
	mouse_event(MOUSEEVENTF_LEFTDOWN, 0, 0, 0, 0);
	Sleep(50);
	mouse_event(MOUSEEVENTF_LEFTUP, 0, 0, 0, 0);
}

void right_click(int x, int y)
{
	SetCursorPos(x, y);
	mouse_event(MOUSEEVENTF_RIGHTDOWN, 0, 0, 0, 0);
	Sleep(50);
	mouse_event(MOUSEEVENTF_RIGHTUP, 0, 0, 0, 0);
	Sleep(50);
}

void keyput(char key ,int time=50)
{
	keybd_event(key, 0, 0, 0);
	Sleep(time);
	keybd_event(key, 0, 2, 0);
	Sleep(time);
}

void keyput_all(BYTE key, int time = 50)
{
	keybd_event(key, 0, 0, 0);
	Sleep(time);
	keybd_event(key, 0, 2, 0);
	Sleep(time);
}

void contre_key(char key)
{
	keybd_event(VK_CONTROL, 0, 0, 0);
	Sleep(50);
	keybd_event(key, 0, 0, 0);
	Sleep(50);
	keybd_event(key, 0, 2, 0);
	Sleep(50);
	keybd_event(VK_CONTROL, 0, 2, 0);
}

void alt_key(char key)
{
	keybd_event(VK_LMENU, 0, 0, 0);
	Sleep(50);
	keybd_event(key, 0, 0, 0);
	Sleep(50);
	keybd_event(key, 0, 2, 0);
	Sleep(50);
	keybd_event(VK_LMENU, 0, 2, 0);
}

void win_key(char key)
{
	keybd_event(VK_LWIN, 0, 0, 0);
	Sleep(50);
	keybd_event(key, 0, 0, 0);
	Sleep(50);
	keybd_event(key, 0, 2, 0);
	Sleep(50);
	keybd_event(VK_LWIN, 0, 2, 0);
}



//class point
//{
//public:
//	int x;
//	int y;
//	void init(int a, int b)
//	{
//		x = a;
//		y = b;
//	}
//
//	void change_xy(int x1, int y1)         //以当前点为原点，设置相对坐标,改变自己的坐标值
//	{
//		x = x + x1;
//		y = y + y1;
//	}
//
//	point get_xy(int x1, int y1)
//	{
//		point xy;
//		xy.x = x + x1;
//		xy.y = y + y1;
//		return xy;
//	}
//
//	void get(point b)  //获取坐标
//	{
//		x = b.x;
//		y = b.y;
//	}
//
//	void put()          //输出坐标
//	{
//		printf("x=%d\ny=%d", x, y);
//	}
//};

int ten(int m)         //10的次方
{
	int sum=1;
	for (int i = 0; i < m; i++)
	{
		sum = sum * 10;
	}
	return sum;
}

void clear_str(char str[])			//清空一个字符串
{
	int i = 0;
	while (str[i]!='\0')
	{
		str[i] = 0;
		i++;
	}
}

void put_str(char s[])
{
	int i = 0;
	while (s[i]!='\0')
	{
		printf("%c", s[i]);
		i++;
	}
}

int cutstr_head(char str[] , char p ,char end[])  //截断字符串
{
	int i = 0;
	while (str[i]!=p)
	{
		end[i] = str[i];
		i++;
	}
	return i+1;			//截断点
}

//int str_int(char* str)   //字符串转整型
//{
//	int i = 0;
//	while (str[i]!='\0')
//	{
//		i++;
//	}
//	if (i == 1)
//		return str[0] - '0';
//	else
//	{
//		int sum = 0;
//		int p = i;
//		for (int j = 0; j < p; j++)
//		{
//			sum = sum + (str[j]-'0')* ten(i - 1);
//			i--;
//		}
//		return sum;
//	}
//
//}

//字符串转整型	
int str_int(char str[])     //增加负数处理
{
	if (str[0] == '-')				//负数处理，使用了递归
		return str_int(str + 1) * -1;

	int i = 0;
	while (str[i] != '\0')    	//计算整数位数	
		i++;

	if (i == 1)			//个位数单独处理
		return str[0] - '0';
	else
	{
		int sum = 0;
		int p = i;
		for (int j = 0; j < p; j++)
		{
			sum = sum + (str[j] - '0') * ten(i - 1);
			i--;
		}
		return sum;
	}
}

int str_int2(char* str)   //字符串转整型//负数处理
{
	int i = 0;		//长度值
	bool f = 0;		//负数处理

	while (str[i] != '\0')	
		i++;
	
	if (str[0] == '-')
		f = 1;

	if (i == 1)
		return str[0] - '0';
	else
	{
		int sum = 0, p = i, j = 0;
			 
		if (f)
			j++,i--;
		for (; j < p; j++)
		{
			sum = sum + (str[j] - '0') * ten(i - 1);
			i--;
		}
		if (f)
			return -sum;
		else
			return sum;
	}

}

bool chak_num(char data)	//ascii 0-9
{
	if (data > 47 && data < 58)
		return 1;
	else
		return 0;
}

template <typename chars>
int get_num(chars str, short n)		//get num from srt
{
	bool is = 0;
	char t = 0, cn[5] = { 0 };
	short i = 0, all = 0, data, j = 0;
	while (str[i] != '\0')
	{
		if (chak_num(str[i]))
		{
			if (!is) {
				all++;
				cn[j] = str[i];
				j++;
			}
			else
			{
				j = 0;
			}
			is = 1;
		}
		else
		{
			is = 0;
		}
		if (all == n)
			return str_int(cn);
		i++;
	}
}


//连接a,b 最后结果为a
void link(char* a,const char* b)
{
	int i = 0, j = 0;
	while (a[i] != '\0')
	{
		i++;
	}
	while (b[j] != '\0')
	{
		a[i] = b[j];
		i++;
		j++;
	}
}

void input_file(FILE* fp ,int a) //向文件输入一个整数
{
	char txt[7];
	sprintf_s(txt, "%d", a);
	if (fp != NULL)	
		fputs(txt, fp);
}

//输出特定颜色的字体
void color_put(const char* txt, WORD color)
{
	HANDLE hc = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hc, color);
	printf(txt);
	SetConsoleTextAttribute(hc, 15);
}

void  int_str(int a , char str[])		//整型转字符  //范围 0 - 999
{
	if (a+'0' < 58)
	{
		a = a + '0';
		str[0] = a;
		str[1] = '\0';
	}
	else
	{
		if (a+'0' < 100)
		{
			str[0] = (int)(a / 10) + '0';
			str[1] = (a % 10) + '0';
			str[2] = '\0';
		}
		else
		{
			str[0] = (int)(a / 100) + '0';
			str[1] = ((int)(a / 10)) % 10 + '0';
			str[2] = (a % 100)%10 + '0';
			str[3] = '\0';
		}
	}
}

bool is_str(char* a, const char* b)     //判断两个字符串是否相等
{
	int i = 0, j = 0, m = 0;
	while ((a[i] != '\0') || (b[j] != '\0'))
	{
		if (a[i] == b[j])
		{
			m++;
		}
		if (a[i] != '\0')
		{
			i++;
		}
		if (b[j] != '\0')
		{
			j++;
		}
	}
	if ((i == j) && (i == m))
		return 1;
	else
		return 0;
}

void copy_str(char ing[], char ed[])
{
	short i = 0;
	clear_str(ing);
	while (ed[i]!='\0')
	{
		ing[i] = ed[i];
		i++;
	}
}

void dele_char(char str[], char be_dele)		//去除末尾的“
{
	int i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '"')
		{
			str[i] = '\0'; break;
		}
		i++;
	}
}

int find_char_end(char str[], char p)  //搜索到指定字符(反向)
{
	int i = 0;
	while (str[i] != '\0')
		i++;
	while (str[i] != p && i != 0)
		i--;
	if (i == 0)
		return 0;
	else
		return i;			//截断点
}

struct int_sit	//数值和值位数
{
	short data, sit;
};

int_sit get_int_dh(char str[])//从字符串中获取第一个逗号前的数据
{
	byte i = 0;
	char txt_int[10] = { 0 };
	while (str[i] != ',' && str[i] != '\0')
	{
		txt_int[i] = str[i];
		i++;
	}
	int_sit t;
	t.data = str_int(txt_int);
	t.sit = i;
	return t;
}

int get_int_ByIndex(char str[], short index)		//提取str中的第index个数据(按，分隔)
{
	char data[9] = { 0 };
	short i = 0, order = 0;
	if (index == 0)
	{
		while (str[i] != ',')
		{
			data[i] = str[i];
			i++;
		}
		return str_int(data);
	}
	if (index == 1)
	{
		short j = 0;
		while (str[i] != ',' && str[i] != 0)
			i++;
		i++;
		while (str[i] != '\n' && str[i] != 0)
		{
			data[j] = str[i];
			i++; j++;
		}
		return str_int(data);
	}
	while (str[i] != '\0')
	{
		if (str[i] == ',' || str[i] == '\n')		
			order++;
		
		if (order == index)		//finded data's index
		{
			if (i != 0)
				i--;
			short j = 0;
			while (str[i] != ',' && i != -1)			
				i--;			
			i++;
			while (str[i] != ',' && str[i] != '\n' && str[i] != '\0')
			{
				data[j] = str[i];
				i++, j++;
			}
			return str_int(data);
		}
		i++;
	}
	return 0;
}

//enum command
//{
//	left,
//	lefts,
//	right,
//	key,
//	wind,
//	help,
//	cls,
//};

void SetDataToClip(TCHAR strText[])
{
	// 打开剪贴板   
	if (!OpenClipboard(NULL) || !EmptyClipboard())
	{
		printf("打开或清空剪切板出错！/n");
		return;
	}

	HGLOBAL hMen;
	//TCHAR strText[256] = "test/n";

	// 分配全局内存    
	hMen = GlobalAlloc(GMEM_MOVEABLE, ((strlen(strText) + 1) * sizeof(TCHAR)));

	if (!hMen)
	{
		printf("分配全局内存出错！/n");
		// 关闭剪切板    
		CloseClipboard();
		return;
	}

	// 把数据拷贝考全局内存中   
	// 锁住内存区    
	LPSTR lpStr = (LPSTR)GlobalLock(hMen);

	// 内存复制   
	memcpy(lpStr, strText, ((strlen(strText)) * sizeof(TCHAR)));
	// 字符结束符    
	lpStr[strlen(strText)] = (TCHAR)0;
	// 释放锁    
	GlobalUnlock(hMen);

	// 把内存中的数据放到剪切板上   
	SetClipboardData(CF_TEXT, hMen);
	CloseClipboard();

	return;
}

//void do_command(char msg[])
//{
//	switch (msg[0])
//	{
//	//case 'k':
//	//	char key;
//	//	key = msg[2];
//	//	if (key < 91)		//大写字母
//	//		keyput(key);
//	//	else
//	//	{
//	//		if (key == 'a')						//全选
//	//			contre_key('A');
//	//		if (key == 'c')						//复制
//	//			contre_key('C');
//	//		if (key == 'p')						//粘贴
//	//			contre_key('V');
//	//		if (key == 'b')						//删除
//	//			keyput_all(VK_DELETE);
//	//		if (key == 'e')
//	//			keyput_all(VK_ESCAPE);
//	//		if (key == 'r')
//	//			keyput_all(VK_RETURN);
//	//		if (key == 't')
//	//			keyput_all(VK_TAB);
//	//		if (key == 'u')
//	//			keyput_all(VK_UP);
//	//		if (key == 'd')
//	//			keyput_all(VK_DOWN);
//	//		if (key == 's')
//	//			alt_key(VK_F4);
//	//		if (key == 'w')
//	//			win_key('D');
//	//	}
//	//break;
//	//case 't':
//	//	short t;
//	//	t = str_int(msg + 2);
//	//	Sleep(t);
//	//break;
//	case 'w':
//		HWND wind = GetForegroundWindow();
//		ShowWindow(wind, SW_MAXIMIZE);
//	break;
//	//case '"':
//	//	char file[20] = { 0 };		//文件名
//	//	dele_char(msg + 1, '"');		//去除末尾的 "
//	//	char path[40] = { 0 };
//	//	short sit = find_char_end(msg + 1, '\\');
//	//	for (int i = 0; i < sit; i++)		
//	//		path[i] = msg[i + 1];					//获取路径		
//	//	for (int i = sit, j = 0; msg[i] != '\0' && msg[i] != '\n'; i++, j++)		//获取文件名
//	//		file[j] = msg[i + 2];
//	//	put_str(path);		//测试代码
//	//	putchar(10);
//	//	put_str(file);
//	//	//打开文件
//	//	ShellExecute(0, "open", file, 0, path, 1);
//	//break;
//	//case 'i':
//	//	char sx[10] = { 0 };
//	//	short  j = 0;
//	//	j = cutstr_head(msg + 2, ',', sx);
//	//	x00 = str_int(sx);
//	//	y00 = str_int(msg + j + 2);
//	////	cout << "init :x0=" << x0 << endl;
//	////	cout << "y0=" << y0 << endl;
//	//break;
//	//case 'c':
//	//	SetDataToClip(msg + 2);
//	//break;
//	default:
//	break;
//	}
//
//	if (msg[0] == 'l' || msg[0] == 's' || msg[0] == 'r')			//mouse
//	{
//		char sx[10] = { 0 };
//		POINT xy;
//		short  j = 0;
//		j = cutstr_head(msg + 2, ',', sx);
//		xy.x = str_int(sx);
//		xy.y = str_int(msg + j + 2);
//		if (msg[0] == 'l')
//			left_click(xy.x, xy.y);
//		if (msg[0] == 'r')
//			right_click(xy.x, xy.y);
//		if (msg[0] == 's')
//			left_clicks(xy.x, xy.y);
//		cout << "点击位置：xy.x=" << xy.x << endl;
//		cout << "xy.y=" << xy.y << endl;
//	}
//
//}



