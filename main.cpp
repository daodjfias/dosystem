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

	//ִ����
//	printf("ִ����6.1\n");
//	printf("���ļ��ϵ��˳�����ִ��\n�� B �� S ��ǿ�ƹرճ���\n��¼���������teb,esc,return,up,down,copy,past,delete,all\n");
//	printf("��ʼ\n-------------------------\n");
	FILE* fp;
	errno_t err = 0;
	//ѡ���ļ��򿪷�ʽ
	if (aegc == 1)
	{
		printf("ִ��ϵͳ1.4		������鿴/���㣬�����¼/ִ����һ��\n�������\n");
		printf("cak,x,y,r,g,b,		 	���x��y���괦�������Ƿ���r,g,bƥ��,����ƥ������ִͣ��\n");
		printf("pas,str		 	pas-��ͣ��str-�ڴ����е���ʾ��Ϣ\n");
		printf("\".file\"			ʹ�����·�����ó���(��ǰĿ¼)\n");
		printf("c��str			��str���Ƶ����а壬��k,p���ʹ��\n");
		printf("i��int��int			��ʼ�����ָ�룬Ĭ��Ϊ0,0 ��ֻ������ѭ����ʹ��\n");
		printf("m��int��int			�ƶ����ָ�룬ֻ������ѭ����ʹ��\n");
		printf("l,x,y  | r,x,y | s,x,y	 ʹ�����ָ�������ֻ������ѭ����ʹ��\n");
		system("pause");
		//��¼�� ���ɼ�¼�ļ���������
printf("�˳����¼��������\n");
printf("����help�鿴����\n");
printf("��ʼ\n----------------------\n");
bool go=1;
short num = 0;		//��������
short a = 0;
POINT xy;
char fname[20] = { 0 };
printf("�������ļ�����\n");
scanf_s("%s", fname);
link(fname, ".txt");
put_str(fname);
putchar(10);
//���ļ�
FILE* fp;
errno_t err = 0;
err = fopen_s(&fp, fname, "w");
if (err == 0)
	printf("�ļ��򿪳ɹ�");
else
	printf("�ļ���ʧ��");
putchar(10);
//ʵ��
	char plan[10] = { 0 };
	char os;
	short temp=0;
	bool ism = 0 ,isc=0;		//�Ƿ��� ����������
while (go)
{
	printf("���������		��������%d\n",num);
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
		//��a�����ļ�
	if (ism)				//��ȡ���꣨���ô��룩
		{
		//input_file(fp, a);
		fputc(os, fp);
		fputc(',', fp);			
		char c0[5] = { 0 };
		printf("��ָ�����λ�� ������1ȷ��\n");
			scanf_s("%s", c0);
			GetCursorPos(&xy);
			printf(" ��¼���꣺ x=%d,y=%d \n", xy.x, xy.y);
			//����������ļ�
			input_file(fp, xy.x);
			fputc(',', fp);
			input_file(fp, xy.y);
		}				
	if(is_str(plan,"key"))    //���̲���
	{
		isc = 1;
		char pram;
		//����ֵ�����ļ�
		printf("�������ֵ��\n");
	    scanf_s("%s", &pram);
		fputs("k,", fp);
		fputc(pram, fp);
	}
	if (is_str(plan, "//"))    //ע��
	{
		isc = 1;
		num--;
		char pram[30];
		//����ֵ�����ļ�
		printf("������ע�ͣ�\n");
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
		printf("������ѭ��������\n");
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
		printf("������ʱ�䣺(��λ0.5��)\n");
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
		printf("����������\n");
		scanf_s("%s", datas);
		fputs(datas, fp);
	}
	if (is_str(plan, "dist"))
	{
		isc = 1, num--;
		POINT xy2;
		char c0[5] = { 0 };
		printf("��ָ����һ�� ������1ȷ��\n");
		scanf_s("%s", c0);
		GetCursorPos(&xy);
		printf("��ָ���ڶ��� ������1ȷ��\n");
		scanf_s("%s", c0);
		GetCursorPos(&xy2);
		xy.x = xy2.x - xy.x;
		xy.y = xy2.y - xy.y;
		printf("���� x2-x1=%d,y2-y1=%d \n", xy.x, xy.y);

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
				printf(" ���꣺ x=%d,y=%d      ��B����\n", m_xy.x, m_xy.y),
				printf(" ����ֵ�� R=%d, G=%d, B=%d     \n\n��B��ESC����\n", GetRValue(now), GetGValue(now), GetBValue(now));
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
		printf("��������ʾ��Ϣ��\n");
		scanf_s("%s", tip);
		fputs(tip,fp);
		isc = 1;
	}
	if (is_str(plan, "chak"))//���ؼ��
	{

		fputs("cak,", fp);
		char c0[5] = { 0 };
		printf("��ָ�����λ�� ������1ȷ��\n");
		scanf_s("%s", c0);
		GetCursorPos(&xy);
		printf(" ��¼���꣺ x=%d,y=%d \n", xy.x, xy.y);
		//����������ļ�
		input_file(fp, xy.x);
		fputc(',', fp);
		input_file(fp, xy.y);
		fputc(',', fp);



		HDC hdc = GetDC(GetDesktopWindow());
		COLORREF now;
				
			now = GetPixel(hdc, xy.x, xy.y);
		
			printf(" ����ֵ�� R=%d, G=%d, B=%d     \n", GetRValue(now), GetGValue(now), GetBValue(now));
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
		printf("���������(��ֵ)��\n");
		printf("t---teb\n");
		printf("e---esc\n");
		printf("r---return\n");
		printf("u---up\n");
		printf("d---down\na---contre+A\nb---delete\nc---copy\np---past\ns---alt+F4\n\n");
		printf("�����б�\n");
		printf("l-------���\nls------˫��\nr-------�Ҽ�\nkey-----����\nwind----��󻯴���\ntime----��ʱ\nchak----���ָ��������ֵ\npas----��ͣ\ndist----����������\nxy-----�鿴����\nclip-----������������а�\ncls-----����\n//------���ע��\nbegin---��ѭ����ʼ\nend-----��ѭ������\nexit----�˳�\n");
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
		printf("��Ч����\n");
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
	//�ж��Ƿ�ɹ�
	if (err == 0)
		printf("�ļ��򿪳ɹ�");
	else
	{
		printf("�ļ���ʧ��");
		system("pause");
		return 0;
	}
	putchar(10);
	//��С������
	Sleep(500);
	HWND me = GetForegroundWindow();
	ShowWindow(me, 6);
	//׼������
	byte run_speed = 50;
	short x0 = 0, y0 = 0;			//���Ĭ��ָ��
	bool go = 1;
	short i = 0, j = 0;
	char key, ch;
	char msg[20] = { 0 };
//	char backup[15] = { 0 };			//��ѭ��׼��
	short  coms = 0, redos = 1;				//ѭ�����Ʊ���
	bool isre = 0, isgo = 1;						//��ѭ����ʼ��־
	char msgs[15][15] = { 0 };				//��ѭ��׼��
	short ncoms = 0;				//������������
	while (EOF != (ch = getc(fp)))		//��ȡ�ļ�
	{

		if (ch == '#')				//ע�������Զ�����		
			isgo = 0;
		if (ch == '\n')				//ע�ͽ���
			isgo = 1;
		if (isgo)
		{
			if (ch != '\n' && ch != 32 && ch != '\t')			// �ո񲻼�������
				msg[i] = ch;
			i++;
			//	redos = 1;
			if (ch == '\n')
			{
				//	short var[5] = { 0 };	//���ñ���
				if (msg[0] == '{')				//��ѭ����ʼ	//����ѭ�������Զ�����			
					isre = 1;
				if (msg[0] == '}')				//��ѭ������
				{
					isre = 0;
					put_str(msg + 2);
					redos = str_int(msg + 2);
					for (; redos > 0; redos--)			//��ѭ��
					{
						printf("��ѭ��������%d\n", redos);
						printf("����ִ�д�����%d\n", ncoms);
						short i1 = 0;
						coms = 0;
						for (; i1 < ncoms; i1++) {					//����ѭ��											
							if (ch == '\n')				 //����һ������
							{
								printf("ִ�����ݣ� ");
								put_str(msgs[coms]);
								putchar(10);
								//	i = 0;	//	��һ�������׼��	

								if (msgs[coms][0] == 'k')
								{
									key = msgs[coms][2];
									if (key < 91)		//��д��ĸ
										keyput(key);
									else
									{
										if (key == 'a')						//ȫѡ
											contre_key('A');
										if (key == 'c')						//����
											contre_key('C');
										if (key == 'p')						//ճ��
											contre_key('V');
										if (key == 'b')						//ɾ��
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
									//	printf("��ֵ��%c\n", key);
								}
								if (msgs[coms][0] == 't')
								{
									short t;
									t = str_int(msgs[coms] + 2);
									Sleep(t);
								}
								if (msgs[coms][0] == 'm')		//�ƶ�Ĭ��ָ��
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
										cout << "���꣺x0=" << x0 << endl;
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
									//�ƶ�Ĭ��ָ��
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


								//	��ջ�����Ϣ
								Sleep(run_speed);				//����ִ���ٶ�
								if (GetAsyncKeyState('B') || GetAsyncKeyState('S') || GetAsyncKeyState(VK_ESCAPE))
									return 0;
								//	printf("ѭ��������%d\n", redo);
								coms++;
							}
						}
					}
				}
				if (isre)					//��¼ѭ��������
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
			if (ch == '\n')				 //����һ������  
				{
					printf("command:\n");
					put_str(msg);
					putchar(10);
					i = 0;
					//	��һ�������׼��
					if (!isre)				//�����ظ�ִ��{}�ں�f�ϵ�����
					{
						if (msg[0] == 'k')
						{
							key = msg[2];
							if (key < 91)		//��д��ĸ
								keyput(key);
							else
							{
								if (key == 'a')						//ȫѡ
									contre_key('A');
								if (key == 'c')						//����
									contre_key('C');
								if (key == 'p')						//ճ��
									contre_key('V');
								if (key == 'b')						//ɾ��
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
							//	printf("��ֵ��%c\n", key);
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
						if (msg[0] == '"')				//����exe,bat				
						{
							char file[20] = { 0 };		//�ļ���
							dele_char(msg + 1, '"');		//ȥ��ĩβ�� "
							char path[40] = { 0 };

							if (msg[1] == '.')	//ʹ�����·��
							{
								ShellExecute(0, "open", msg+2, 0, 0, 1);
							}
							else {
								short sit = find_char_end(msg + 1, '\\');
								for (int i = 0; i < sit; i++)
								{
									path[i] = msg[i + 1];					//��ȡ·��
								}
								for (int i = sit, j = 0; msg[i] != '\0' && msg[i] != '\n'; i++, j++)		//��ȡ�ļ���
									file[j] = msg[i + 2];
								put_str(path);		//���Դ���
								putchar(10);
								put_str(file);
								//���ļ�
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
							cout << "���λ�ã�xy.x=" << xy.x << endl;
							cout << "xy.y=" << xy.y << endl;
						}
						if (msg[0] == 'i')		//��ʼ��Ĭ��ָ��
						{
							char sx[10] = { 0 };
							short  j = 0;
							j = cutstr_head(msg + 2, ',', sx);
							x0 = str_int(sx);
							y0 = str_int(msg + j + 2);
							cout << "init :x0=" << x0 << endl;
							cout << "y0=" << y0 << endl;
						}
						if (msg[0] == 'c')		//���а�
						{
							SetDataToClip(msg + 2);
						
						}
						if (msg[0] == 'p')	//��ͣ
						{
							if (msg[1] == 'a' && msg[2] == 's') {
								system("cls");
								ShowWindow(me, SW_NORMAL);
								MoveWindow(me, 0, 0, 600, 130, 1);
								printf("%s\n",msg+4);
								printf("��ͣ��\n");
								system("pause");
								ShowWindow(me, SW_MINIMIZE);
							}
						}
						if (msg[0] == 'c')		//���ָ��λ�õ�����
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
									printf("����ƥ�����\n");
									printf("��ͣ��\n");
									system("pause");
									ShowWindow(me, SW_MINIMIZE);
								}

							}
						}
						//	do_command(msg);

						clear_str(msg);			//��ջ�����Ϣ
						Sleep(run_speed);				//����ִ���ٶ�
						if (GetAsyncKeyState('B') || GetAsyncKeyState('S') || GetAsyncKeyState(VK_ESCAPE))			//�˳�����
							return 0;
					}

				}				
		}

	}
	fclose(fp);
	//system("pause");
//	Sleep(5000);

			////ȥ������
		//printf("��ʼ\n-------------------------\n");
		//FILE* fp, * out;
		//errno_t err = 0;
		////ѡ���ļ��򿪷�ʽ
		//if (aegc == 1)
		//{
		//	char p = 0;
		//	cout << "�������ã�\ns.ȥ�ո� space     	r.ȥ���� return 	   a.��ȥ all\n";
		//	cin >> p;
		//	FILE* param;
		//	fopen_s(&param, "param.txt", "w");
		//	fputc(p, param);
		//	fclose(param);
		//	cout << "����������ɣ����������ļ��ϵ�ͼ����ִ��\n";
		//	Sleep(2000);
		//	return 0;
		//}
		//err = fopen_s(&fp, argv[1], "r");
		////�ж��Ƿ�ɹ�
		//if (err == 0)
		//	printf("�ļ��򿪳ɹ�");
		//else
		//{
		//	printf("�ļ���ʧ��");
		//	system("pause");
		//	return 0;
		//}
		//putchar(10);
		//fopen_s(&out, "out.txt", "w");
		//char ch2 = 0, ch, p;
		//p = get_filechar("param.txt");
		//cout << "mode : " << p << endl;
		////printf("value %d\n", p);
		//while (EOF != (ch = getc(fp)))		//��ȡ�ļ�
		//{
		//	if ((ch == ch2) && ch == '\n' && (p == 'r' || p == 'a'))				//ע�ͽ���
		//		cout << "�п���\n";
		//	else
		//	{
		//		if ((ch == 32 || ch == '\t') && (p == 's' || p == 'a'))
		//			cout << "�пո�\n";
		//		else
		//			fputc(ch, out);
		//	}
		//	ch2 = ch;
		//}
		//fclose(fp);
		//fclose(out);
		//Sleep(1000);
		////system("pause");

			////�Զ�����
		//FILE* fp, * out;
		////ѡ���ļ��򿪷�ʽ
		//if (aegc == 1)
		//{
		//	char p = 0;
		//	printf("ԭ�������Զ��ھ�ź�ӻس�\n");
		//	printf("��ʼ\n-------------------------\n");
		//	cout << "�������ã�\n���б�־��1.���ľ��		0.Ӣ�ľ��\n";
		//	cin >> p;
		//	FILE* param;
		//	fopen_s(&param, "param_cut.txt", "w");
		//	fputc(p, param);
		//	fclose(param);
		//	cout << "����������ɣ����������ļ��ϵ�ͼ����ִ��\n";
		//	Sleep(1500);
		//	return 0;
		//}
		////ifstream File(argv[1], ios::in); //���ı�ģʽ��in.txt����putchar(10);
		////cout<<File.rdbuf();
		//short n = 0 ,n2=0;
		//fopen_s(&fp, argv[1],"r");
		//fopen_s(&out, "out_cut.txt","w");
		//char ch2 = 0, ch, p;
		//p = get_filechar("param_cut.txt");
		//cout << "mode : " << p << endl;
		////printf("value %d\n", p);
		//while (EOF != (ch = getc(fp)))		//��ȡ�ļ�
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
			//	left.init(xy, xy.get_xy(200, 70), "�������");
			//	right.init(xy.get_xy(300,0), xy.get_xy(500, 70), "�Ҽ�����");
			//	lefts.init(xy.get_xy(0, 150), xy.get_xy(200, 220), "���˫��");
			//	key.init(xy.get_xy(300,150),xy.get_xy(500,220),"���̲���");
			//	enter.init(xy.get_xy(100,400),xy.get_xy(300,500) , "ȷ��");
			//	outtextxy(770, 70, "��������");
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