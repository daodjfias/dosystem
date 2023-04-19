#pragma once
//#include"F:\desktop\code\c\ͷ�ļ�\str.h"
//#include"F:\desktop\code\c\ͷ�ļ�\graph.h"
//#include"F:\desktop\code\c\ͷ�ļ�\win.h"

char get_filechar(const char* filename)			//��ȡ�ļ���һ���ַ�
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
//	void change_xy(int x1, int y1)         //�Ե�ǰ��Ϊԭ�㣬�����������,�ı��Լ�������ֵ
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
//	void get(point b)  //��ȡ����
//	{
//		x = b.x;
//		y = b.y;
//	}
//
//	void put()          //�������
//	{
//		printf("x=%d\ny=%d", x, y);
//	}
//};

int ten(int m)         //10�Ĵη�
{
	int sum=1;
	for (int i = 0; i < m; i++)
	{
		sum = sum * 10;
	}
	return sum;
}

void clear_str(char str[])			//���һ���ַ���
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

int cutstr_head(char str[] , char p ,char end[])  //�ض��ַ���
{
	int i = 0;
	while (str[i]!=p)
	{
		end[i] = str[i];
		i++;
	}
	return i+1;			//�ضϵ�
}

//int str_int(char* str)   //�ַ���ת����
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

//�ַ���ת����	
int str_int(char str[])     //���Ӹ�������
{
	if (str[0] == '-')				//��������ʹ���˵ݹ�
		return str_int(str + 1) * -1;

	int i = 0;
	while (str[i] != '\0')    	//��������λ��	
		i++;

	if (i == 1)			//��λ����������
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

int str_int2(char* str)   //�ַ���ת����//��������
{
	int i = 0;		//����ֵ
	bool f = 0;		//��������

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


//����a,b �����Ϊa
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

void input_file(FILE* fp ,int a) //���ļ�����һ������
{
	char txt[7];
	sprintf_s(txt, "%d", a);
	if (fp != NULL)	
		fputs(txt, fp);
}

//����ض���ɫ������
void color_put(const char* txt, WORD color)
{
	HANDLE hc = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hc, color);
	printf(txt);
	SetConsoleTextAttribute(hc, 15);
}

void  int_str(int a , char str[])		//����ת�ַ�  //��Χ 0 - 999
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

bool is_str(char* a, const char* b)     //�ж������ַ����Ƿ����
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

void dele_char(char str[], char be_dele)		//ȥ��ĩβ�ġ�
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

int find_char_end(char str[], char p)  //������ָ���ַ�(����)
{
	int i = 0;
	while (str[i] != '\0')
		i++;
	while (str[i] != p && i != 0)
		i--;
	if (i == 0)
		return 0;
	else
		return i;			//�ضϵ�
}

struct int_sit	//��ֵ��ֵλ��
{
	short data, sit;
};

int_sit get_int_dh(char str[])//���ַ����л�ȡ��һ������ǰ������
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

int get_int_ByIndex(char str[], short index)		//��ȡstr�еĵ�index������(�����ָ�)
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
	// �򿪼�����   
	if (!OpenClipboard(NULL) || !EmptyClipboard())
	{
		printf("�򿪻���ռ��а����/n");
		return;
	}

	HGLOBAL hMen;
	//TCHAR strText[256] = "test/n";

	// ����ȫ���ڴ�    
	hMen = GlobalAlloc(GMEM_MOVEABLE, ((strlen(strText) + 1) * sizeof(TCHAR)));

	if (!hMen)
	{
		printf("����ȫ���ڴ����/n");
		// �رռ��а�    
		CloseClipboard();
		return;
	}

	// �����ݿ�����ȫ���ڴ���   
	// ��ס�ڴ���    
	LPSTR lpStr = (LPSTR)GlobalLock(hMen);

	// �ڴ渴��   
	memcpy(lpStr, strText, ((strlen(strText)) * sizeof(TCHAR)));
	// �ַ�������    
	lpStr[strlen(strText)] = (TCHAR)0;
	// �ͷ���    
	GlobalUnlock(hMen);

	// ���ڴ��е����ݷŵ����а���   
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
//	//	if (key < 91)		//��д��ĸ
//	//		keyput(key);
//	//	else
//	//	{
//	//		if (key == 'a')						//ȫѡ
//	//			contre_key('A');
//	//		if (key == 'c')						//����
//	//			contre_key('C');
//	//		if (key == 'p')						//ճ��
//	//			contre_key('V');
//	//		if (key == 'b')						//ɾ��
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
//	//	char file[20] = { 0 };		//�ļ���
//	//	dele_char(msg + 1, '"');		//ȥ��ĩβ�� "
//	//	char path[40] = { 0 };
//	//	short sit = find_char_end(msg + 1, '\\');
//	//	for (int i = 0; i < sit; i++)		
//	//		path[i] = msg[i + 1];					//��ȡ·��		
//	//	for (int i = sit, j = 0; msg[i] != '\0' && msg[i] != '\n'; i++, j++)		//��ȡ�ļ���
//	//		file[j] = msg[i + 2];
//	//	put_str(path);		//���Դ���
//	//	putchar(10);
//	//	put_str(file);
//	//	//���ļ�
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
//		cout << "���λ�ã�xy.x=" << xy.x << endl;
//		cout << "xy.y=" << xy.y << endl;
//	}
//
//}



