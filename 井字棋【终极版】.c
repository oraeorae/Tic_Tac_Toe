 /*
========ww================================ww============== 
�񱾳����ɰ���������
	QQ����2783608988
��汾��
������ ��Tic Tac Toe�����ռ��桿 
��ʹ��˵���� 
	���˻���ս��
[��][��][��][��]������ҷ��� 
[�س���]ȷ�� [Esc]����
	��˫�˶�ս��
���1:[��][��][��][��]
[�ո�]ȷ�� 
���2:[��][��][��][��]
[�س���]ȷ�� 

[Esc]����
						ʱ�䣺2016.10.22
---------------------------------------------------------
©��

	1.�������ʱ ���Ե����һ�����Ӳ������a
	2.�������˵�ʱ �ظ�ѡ��						�����޸��� 
	3.��ʾ����ӣ����ӣ������     			�����޸��� 
	4.���������ظ�����Ϣ��
	
������
	1.�����Ҳ���Կ������˵� 					������ӡ� 
	2.˫�˶�ս ��ȷ���������ӿո� 				������ӡ� 
======ww=================================ww============== 
*/

/*		ͷ�ļ�		*/
# include <time.h>
# include <stdio.h>
# include <stdlib.h>
# include <windows.h>

/*		ȫ�ֱ���	*/
int chess[3][3]={{0,0,0},{0,0,0},{0,0,0}},step = 0,frist_play,number_time = 1;	//�������ͼ,�û�����,˭����,draw_map�������д��� 

/*		��������	*/	
void main_mean(int show);								//��ʾ���� 
void gotoxy(int x,int y);								//��굽ָ��λ��
void a_word_printf(char *a, int time);					//��������
void computer_play(void);								//�˻���ս 
void people_play(void);									//˫�˶�ս 
int check_result(void);									//���˻���ս��˫�˶�ս������� 
void draw_map(int model);								//���˻���ս��˫�˶�ս���������� 
void computer_play_chess(void);							//���˻���ս���������� 
void check_people_play(int *will_x,int *will_y);		//���˻���ս�����������ӣ��Ӷ������ж� 
void check_computer_play(int *will_x,int *will_y);		//���˻���ս�����������ӣ��Ӷ������ж� 

int main(void)
{
	system("title �����塾�ռ��桿");				//�ı䴰�ڱ���
	system("mode con: cols=38 lines=24");				//���ô��ڴ�С
	
	/*				���ع��			*/
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);	//��ñ�׼����豸���
	CONSOLE_CURSOR_INFO cci;							//��������Ϣ�ṹ�� 
	GetConsoleCursorInfo(hConsole, &cci);				//��õ�ǰ�����Ϣ 
	cci.bVisible = 0;  									//Ϊ0ʱ��겻�ɼ�
	SetConsoleCursorInfo(hConsole, &cci);


	int location = 1;		//ѡ��
		
	main_mean(1);	//��ʾ���˵� 
	
 	while(1)	//��ѭ�� 
	{
		switch(getch())
		{
			case 'W':case 'w':
			W:				//GOTO��ǩ 
				location--;
				if( location == 0 )
				{
					location++;
				}	
				else if( location == 1 )
				{
					/* ��������ѡ��ۼ� */
					gotoxy(8,4);
					printf("��"); 
					/* ����ϴ�ѡ��ۼ� */
					gotoxy(8,7);
					printf("  "); 
				}
				else if( location == 2 )
				{
					/* ��������ѡ��ۼ� */
					gotoxy(8,7);
					printf("��"); 
					/* ����ϴ�ѡ��ۼ� */
					gotoxy(8,10);
					printf("  "); 
				}
				else if( location == 3 )
				{
					/* ��������ѡ��ۼ� */
					gotoxy(8,10);
					printf("��"); 
					/* ����ϴ�ѡ��ۼ� */
					gotoxy(8,13);
					printf("  "); 
				}
				break;
			
			case 'S':case 's':
			S:		//GOTO��ǩ 
				location++;
				if( location == 2 )
				{
					/* ��������ѡ��ۼ� */
					gotoxy(8,7);
					printf("��"); 
					/* ����ϴ�ѡ��ۼ� */
					gotoxy(8,4);
					printf("  "); 
				}
				else if( location == 3 )
				{
					/* ��������ѡ��ۼ� */
					gotoxy(8,10);
					printf("��"); 
					/* ����ϴ�ѡ��ۼ� */
					gotoxy(8,7);
					printf("  "); 
				}
				else if( location == 4 )
				{
					/* ��������ѡ��ۼ� */
					gotoxy(8,13);
					printf("��");
					/* ����ϴ�ѡ��ۼ� */ 
					gotoxy(8,10);
					printf("  "); 
				}
				else if( location == 5 )
				{
					location--;
				}	
				break;
			case 224:			//������Ϻ��� 
			{
				int d_key = getch();		//��¼����� 
				if( 72 == d_key )			//72--������� 
				{
					goto W; 
				}	
				else if( 80 == d_key ) 		//80--������� 
				{
					goto S; 
				}
					
			}break;
			case 13:
			{	
				main_mean(0);	//��ʾ���� 
			
				if( location == 1 )			/*	ѡ������˻���ս��	*/ 
				{	
					computer_play();//�˻���ս 
				}
				else if( location == 2 )	/*	ѡ�����˫�˶�ս��	*/
				{
 					people_play();//˫�˶�ս 
				}
				else if( location == 3 )	/*	ѡ�����ʹ��˵����	*/
				{
					a_word_printf("�񱾳����ɰ�����C��������\n����QQ2783608988\n"
					"���˻���ս��\n"
					"[��][��][��][��]������ҷ���\n[�س���]ȷ�� [Esc]����\n\n" 
					"��˫�˶�ս��\n"
					"���1:[��][��][��][��]\n[�ո�]ȷ��\n���2:[��][��][��][��]\n[�س���]ȷ�� [Esc]����\n" 
					,50); 
					
					printf("====================================\n\n         ����ESC������������");
					if( 27 == getch() )	//27�ǡ�ESC�� 
					{
						main_mean(1);	//��ʾ���˵� 
						location = 1; 
					} 
				}
				else if( location == 4 )	/*	ѡ�������ȡԴ�롿	*/
				{
					system("start http://user.qzone.qq.com/2783608988/infocenter?ptsig=6WaMCZpAXYGnFFTEpeBbVlVER2TwK6fP45CaFcPZY7Q_");	//���ӡ���������QQ�ռ�
					
					printf("====================================\n\n         ����ESC������������");
					if( 27 == getch() )	//27�ǡ�ESC�� 
					{
						main_mean(1);	//��ʾ���˵� 
						location = 1; 
					}  
				} 
				
				location = 1; 	//�ָ� 
			}break;
		
			 
		 } //switch 
		
	}//while 

	return 0;
}

void computer_play(void)				//�˻���ս������ 
{
	int chess_x = 0 ,chess_y = 0,result,choose;//������������꣬��Ϸ�����ѡ���������� 
	 
	draw_map(1);			//�������� 
	getch(); 
	
	frist_play = MessageBox(NULL,TEXT("�Ƿ��������"),TEXT("ѡ��"),MB_YESNO);//������Ϣ�� 
	if( IDYES == frist_play ) //��Ϣ��ġ��ǡ���ť��ѡ�� 
	{
		frist_play = 3;			//2��ʾ�û���3��ʾ���� 
		computer_play_chess(); 
	}
	else 	//IDNO == choose //��Ϣ��ġ��񡿰�ť��ѡ�� 
	{
		frist_play = 2;		//2��ʾ�û���3��ʾ���� 
	}
	
	getch();
	draw_map(1);			//�������� 
	
	if( 3 != chess[chess_y][chess_x] )
	{
	 	chess[chess_y][chess_x] = 1; //���������ʼλ�� 
	}
	else
	{
		chess_x = chess_y = 1;
		chess[chess_y][chess_x] = 1; //���������ʼλ�� 
	} 
	
	while(1)
	{
		draw_map(1);			//�������� 
		
		switch(getch())
		{
			 
			case 'w':case 'W':
			{
				if( 0 == chess_y ) //��ֹԽ�� 
				{
					chess_y = 1;
				}
				if( 2 != chess[--chess_y][chess_x] && 3 != chess[chess_y][chess_x] )
				{
					chess[chess_y][chess_x] = 1;		
				}
				if( 1 == chess[chess_y+1][chess_x] ) 
				{
					chess[chess_y+1][chess_x] = 0;
				}
			}break;
			case 's':case 'S':
			{
				if( 2 == chess_y ) //��ֹԽ�� 
				{
					chess_y = 1;		
				}
				if( 2 != chess[++chess_y][chess_x] && 3 != chess[chess_y][chess_x] )
				{
					chess[chess_y][chess_x] = 1;
				}
				if( 1 == chess[chess_y-1][chess_x] ) 
				{
					chess[chess_y-1][chess_x] = 0;
				}
			}break;
			case 'a':case 'A':
			{
				if( 0 == chess_x ) //��ֹԽ�� 
				{
					chess_x = 1;		
				}
				if( 2 != chess[chess_y][--chess_x] && 3 != chess[chess_y][chess_x] )
				{
					chess[chess_y][chess_x] = 1;
				}
				if( 1 == chess[chess_y][chess_x+1] ) 
				{
					chess[chess_y][chess_x+1] = 0;
				}
			}break;
			case 'd':case 'D':
			{
				if( 2 == chess_x ) //��ֹԽ�� 
				{
					chess_x = 1;		
				}
				if( 2 != chess[chess_y][++chess_x] && 3 != chess[chess_y][chess_x] ) 
				{
					chess[chess_y][chess_x] = 1;
				}
				if( 1 == chess[chess_y][chess_x-1] ) 
				{
					chess[chess_y][chess_x-1] = 0;
				}
			}break;
			case 13:	//�س��� 
			{
				if(	1 == chess[chess_y][chess_x] )	//�жϵ�ǰλ���Ƿ�Ϊ1����ô 
				{
					chess[chess_y][chess_x] = 2;//ȷ����ǰλ��Ϊ2 
					step++;						//����+1(���������ӵ�����+1)
					if( step < 9 )
					{
						computer_play_chess();			//�û�ȷ��֮�󣬵�������
					}
				}
		
			}break;
			case 27:	//Esc��
			{
				choose = MessageBox(NULL,TEXT("��Ϸ��û�н������Ƿ񷵻�?"),TEXT("��ʾ"),MB_YESNO);
				if( IDYES == choose ) //��Ϣ��ġ��񡿰�ť��ѡ�� 
				{
						/*		ȫ����ʼ��		*/
					for( chess_y = 0 ; chess_y < 3 ; chess_y++ ) //��վ������������Ϣ 
					{
						for( chess_x = 0 ; chess_x < 3 ; chess_x++ )
						{
							chess[chess_y][chess_x] = 0 ;
						}
					}
					step = 0,number_time = 1;
	
					main_mean(1);
					return;
				} 
				
			}break; 
			
		} 

		result = check_result();				//����� 
		draw_map(1);							//�������� 	
		
		if( 2 == result || 1 == result || 9 == step )
		{
		 
			if( 2 == result )	//������ʤ�� 
			{			
				choose = MessageBox(NULL,TEXT("̫�ź��ˣ������ˣ��Ƿ�����һ��?"),TEXT("��ʾ"),MB_YESNO);
				if( IDNO == choose ) //��Ϣ��ġ��񡿰�ť��ѡ�� 
				{
					/*		ȫ����ʼ��		*/
					for( chess_y = 0 ; chess_y < 3 ; chess_y++ ) //��վ������������Ϣ 
					{
						for( chess_x = 0 ; chess_x < 3 ; chess_x++ )
						{
							chess[chess_y][chess_x] = 0 ;
						}
					}
					step = 0,number_time = 1;
					
					main_mean(1);
					return;
				}
			}
			else if( 1 == result ) 	//�����ʤ�� 
			{
				choose = MessageBox(NULL,TEXT("��ʤ���ˣ��Ƿ�����һ��?"),TEXT("��ʾ"),MB_YESNO);
				if( IDNO == choose ) //��Ϣ��ġ��񡿰�ť��ѡ�� 
				{
					/*		ȫ����ʼ��		*/
					for( chess_y = 0 ; chess_y < 3 ; chess_y++ ) //��վ������������Ϣ 
					{
						for( chess_x = 0 ; chess_x < 3 ; chess_x++ )
						{
							chess[chess_y][chess_x] = 0 ;
						}
					}
					step = 0,number_time = 1;

					main_mean(1);
					return;
				}
		}
			else if( 9 == step  ) 
			{
				choose = MessageBox(NULL,TEXT("ƽ�֣��Ƿ�����һ��?"),TEXT("��ʾ"),MB_YESNO);
				if( IDNO == choose ) //��Ϣ��ġ��񡿰�ť��ѡ�� 
				{
					/*		ȫ����ʼ��		*/
					for( chess_y = 0 ; chess_y < 3 ; chess_y++ ) //��վ������������Ϣ 
					{
						for( chess_x = 0 ; chess_x < 3 ; chess_x++ )
						{
							chess[chess_y][chess_x] = 0 ;
						}
					}
					step = 0,number_time = 1;

					main_mean(1);
					return;
				}
			}
	
			/*		ȫ����ʼ��		*/
			for( chess_y = 0 ; chess_y < 3 ; chess_y++ ) //��վ������������Ϣ 
			{
				for( chess_x = 0 ; chess_x < 3 ; chess_x++ )
				{
					chess[chess_y][chess_x] = 0 ;
				}
			}
			step = 0,result = 0,chess_x = chess_y = 0;
			draw_map(1);			//�������� 
		
			frist_play = MessageBox(NULL,TEXT("�Ƿ��������"),TEXT("ѡ��"),MB_YESNO);
			if( IDYES == frist_play ) //��Ϣ��ġ��ǡ���ť��ѡ�� 
			{
				frist_play = 3;		//3��ʾ���� 
				computer_play(); 
			}
			else 					 //��Ϣ��ġ��񡿰�ť��ѡ�� 
			{
				frist_play = 2;		//2��ʾ�û�
			}
			getch();
			draw_map(1);			//�������� 
			
			/*		���������ʼλ��	*/
			if( 3 != chess[chess_y][chess_x] )
			{
		 		chess[chess_y][chess_x] = 1; 
			}
			else
			{
				chess_x = chess_y = 1;
				chess[chess_y][chess_x] = 1;  
			} 	
		} 
	}
	return; 
}
 
void people_play()						//˫�˶�ս������ 
{
	int chess_x = 0 ,chess_y = 0,result,choose,chess_kind;//������������꣬��Ϸ�����ѡ���������� 
	 
	draw_map(2);			//�������� 
	getch();	
	draw_map(2);			//�������� 
	
	chess[chess_y][chess_x] = 1; //���������ʼλ�� 
	
	while(1)
	{
		//step��ʾ��ǰ�µ����ӵ��������Դ��ж���һ���µ����ӵ����� �������������9���� 
		if( 1 == step || 3 == step || 5 == step || 7 == step || 9 == step  )
		{
			chess_kind = 2 ;//2��ʾ���� (���1 ��)
		}
		else
		{
			chess_kind = 3 ;//2��ʾ���� (���2 ��)
		} 
		
		draw_map(2);			//�������� 
		
		if( 2 == chess_kind ) //2��ʾ���� 
		{
			switch(getch())
			{
				case 'w':case 'W':
				{
					if( 0 == chess_y ) //��ֹԽ�� 
					{
						chess_y = 1;
					}
					if( 2 != chess[--chess_y][chess_x] && 3 != chess[chess_y][chess_x] )
					{
						chess[chess_y][chess_x] = 1;		
					}
					if( 1 == chess[chess_y+1][chess_x] ) 
					{
						chess[chess_y+1][chess_x] = 0;
					}
				}break;
				case 's':case 'S':
				{
					if( 2 == chess_y ) //��ֹԽ�� 
					{
						chess_y = 1;		
					}
					if( 2 != chess[++chess_y][chess_x] && 3 != chess[chess_y][chess_x] )
					{
						chess[chess_y][chess_x] = 1;
					}
					if( 1 == chess[chess_y-1][chess_x] ) 
					{
						chess[chess_y-1][chess_x] = 0;
					}
				}break;
				case 'a':case 'A':
				{
					if( 0 == chess_x ) //��ֹԽ�� 
					{
						chess_x = 1;		
					}
					if( 2 != chess[chess_y][--chess_x] && 3 != chess[chess_y][chess_x] )
					{
						chess[chess_y][chess_x] = 1;
					}
					if( 1 == chess[chess_y][chess_x+1] ) 
					{
						chess[chess_y][chess_x+1] = 0;
					}
				}break;
				case 'd':case 'D':
				{
					if( 2 == chess_x ) //��ֹԽ�� 
					{
						chess_x = 1;		
					}
					if( 2 != chess[chess_y][++chess_x] && 3 != chess[chess_y][chess_x] ) 
					{
						chess[chess_y][chess_x] = 1;
					}
					if( 1 == chess[chess_y][chess_x-1] ) 
					{
						chess[chess_y][chess_x-1] = 0;
					}
				}break;
				case 13:	//�س��� 
				{
				
					if( 2 != chess[chess_y][chess_x] && 3 != chess[chess_y][chess_x] ) 
					{	
						chess[chess_y][chess_x] = chess_kind;//ȷ����ǰλ��
						step++;	//����+1(���������ӵ�����+1)
					}	
				}break;
			}
		}
		else if( 3 == chess_kind )
		{
			switch(getch())
			{
				case 224:	//�����
				{
					switch(getch())
					{
					case 72: 	//�����-�� 
					{
						if( 0 == chess_y ) //��ֹԽ�� 
						{
							chess_y = 1;
						}
						if( 2 != chess[--chess_y][chess_x] && 3 != chess[chess_y][chess_x] )
						{
							chess[chess_y][chess_x] = 1;		
						}
						if( 1 == chess[chess_y+1][chess_x] ) 
						{
							chess[chess_y+1][chess_x] = 0;
						}
					}break;
				 
					case 80: 	//�����-�� 
					{
						if( 2 == chess_y ) //��ֹԽ�� 
						{
							chess_y = 1;		
						}
						if( 2 != chess[++chess_y][chess_x] && 3 != chess[chess_y][chess_x] )
						{
							chess[chess_y][chess_x] = 1;
						}
						if( 1 == chess[chess_y-1][chess_x] ) 
						{
							chess[chess_y-1][chess_x] = 0;
						}
					}break; 
					
					case 75: 	//�����-��
					{
						if( 0 == chess_x ) //��ֹԽ�� 
						{
							chess_x = 1;		
						}
						if( 2 != chess[chess_y][--chess_x] && 3 != chess[chess_y][chess_x] )
						{
							chess[chess_y][chess_x] = 1;
						}
						if( 1 == chess[chess_y][chess_x+1] ) 
						{
							chess[chess_y][chess_x+1] = 0;
						}
					}break; 
					
					case 77: 	//�����-�� 
					{
						if( 2 == chess_x ) //��ֹԽ�� 
						{
							chess_x = 1;		
						}
						if( 2 != chess[chess_y][++chess_x] && 3 != chess[chess_y][chess_x] ) 
						{
							chess[chess_y][chess_x] = 1;
						}
						if( 1 == chess[chess_y][chess_x-1] ) 
						{
							chess[chess_y][chess_x-1] = 0;
						}
					}break;
				}
			}break;
			case 32:	///�ո�� 
			{
				if( 2 != chess[chess_y][chess_x] && 3 != chess[chess_y][chess_x] ) 
				{	
					chess[chess_y][chess_x] = chess_kind;//ȷ����ǰλ��
					step++;	//����+1(���������ӵ�����+1)
				}
			}break;
			case 27:	//Esc��
			{	
				choose = MessageBox(NULL,TEXT("��Ϸ��û�н������Ƿ񷵻�?"),TEXT("��ʾ"),MB_YESNO);
				if( IDYES == choose ) //��Ϣ��ġ��񡿰�ť��ѡ�� 
				{
						/*		ȫ����ʼ��		*/
					for( chess_y = 0 ; chess_y < 3 ; chess_y++ ) //��վ������������Ϣ 
					{
						for( chess_x = 0 ; chess_x < 3 ; chess_x++ )
						{
							chess[chess_y][chess_x] = 0 ;
						}
					}
					step = 0,number_time = 1;
	
					main_mean(1);
					return;
				} 
				
			}break; 
		}
		}
		
		result = check_result();			//����� 
		draw_map(2);			//�������� 
		
		if( 2 == result || 1 == result || 9 == step )
		{
			if( 2 == result )	//������ʤ�� 
			{			
				choose = MessageBox(NULL,TEXT("����ʤ�����Ƿ�����һ��?"),TEXT("��ʾ"),MB_YESNO);
				if( IDNO == choose ) //��Ϣ��ġ��񡿰�ť��ѡ�� 
				{
					/*		ȫ����ʼ��		*/
					for( chess_y = 0 ; chess_y < 3 ; chess_y++ ) //��վ������������Ϣ 
					{
						for( chess_x = 0 ; chess_x < 3 ; chess_x++ )
						{
							chess[chess_y][chess_x] = 0 ;
						}
					}
					step = 0,number_time = 1;
	
					main_mean(1);
					return; 
				}
			}
			else if( 1 == result ) 	//������ʤ�� 
			{
				choose = MessageBox(NULL,TEXT("����ʤ�����Ƿ�����һ��?"),TEXT("��ʾ"),MB_YESNO);
				if( IDNO == choose ) //��Ϣ��ġ��񡿰�ť��ѡ�� 
				{
					/*		ȫ����ʼ��		*/
					for( chess_y = 0 ; chess_y < 3 ; chess_y++ ) //��վ������������Ϣ 
					{
						for( chess_x = 0 ; chess_x < 3 ; chess_x++ )
						{
							chess[chess_y][chess_x] = 0 ;
						}
					}
					step = 0,number_time = 1;
	
					main_mean(1);
					return;
				}
			}
			else if( 9 == step ) 
			{
				choose = MessageBox(NULL,TEXT("ƽ�֣��Ƿ�����һ��?"),TEXT("��ʾ"),MB_YESNO);
				if( IDNO == choose ) //��Ϣ��ġ��񡿰�ť��ѡ�� 
				{
					/*		ȫ����ʼ��		*/
					for( chess_y = 0 ; chess_y < 3 ; chess_y++ ) //��վ������������Ϣ 
					{
						for( chess_x = 0 ; chess_x < 3 ; chess_x++ )
						{
							chess[chess_y][chess_x] = 0 ;
						}
					}
					step = 0,number_time = 1;

					main_mean(1);
					return;
				}
			}
			
		/*		ȫ����ʼ��		*/
		for( chess_y = 0 ; chess_y < 3 ; chess_y++ ) //��վ������������Ϣ 
		{
			for( chess_x = 0 ; chess_x < 3 ; chess_x++ )
			{
				chess[chess_y][chess_x] = 0 ;
			}
		}
		step = 1,result = 0,chess_x = chess_y = 0;
		draw_map(2);			//�������� 

		getch();
		chess[chess_y][chess_x] = 1; //���������ʼλ�� 
	
		}
	}
	return ;
} 

void main_mean(int show)				//���˵� 
{
 	system("cls");    //���� 		
	gotoxy(0,0); 
 	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole,FOREGROUND_GREEN|FOREGROUND_RED|FOREGROUND_INTENSITY); //���ÿ���̨������ɫ 
	printf( "                                  \n"
			"        �����¾����塾�ռ��桿    \n"
		    "                                  \n"); 
	int line;
	for( line = 0 ; line < 5 ; line++ ) 
	{
		if( show == 1 )
		{
		SetConsoleTextAttribute(hConsole,FOREGROUND_BLUE|FOREGROUND_GREEN|FOREGROUND_INTENSITY|COMMON_LVB_GRID_HORIZONTAL); //���ÿ���̨������ɫ 
		printf( "                                     \n" );
		SetConsoleTextAttribute(hConsole,FOREGROUND_BLUE|FOREGROUND_GREEN|FOREGROUND_INTENSITY); //���ÿ���̨������ɫ
		
		
		if( line == 0 )
		{
			printf("                �˻���ս              \n");
		}
		else if( line == 1 )		
		{ 
			printf("                ˫�˶�ս              \n");
		} 
		else if( line == 2 )	
		{ 
			printf("                ʹ��˵��              \n");
		} 
		else if( line == 3 )	
		{ 
			printf("                ��ȡԴ��              \n");
		} 
 
		}
	}
	
	if( show == 1 )
	{
		
	/*		�����ʾ��ʾ	*/
	SetConsoleTextAttribute(hConsole,FOREGROUND_GREEN|FOREGROUND_INTENSITY); //���ÿ���̨������ɫ
	srand((unsigned)time(NULL));							//���������	 
	gotoxy(0,16);
	int tips = ( rand() % 3 ) + 1;
	if( tips == 1 ) 
	{
		printf("======================================\n                С��ʾ\n\n           ���Կ��Ǻܴ�����\n  �������ȥ���˻���ս����ս���԰�");
	}
	else if( tips == 2 ) 
	{
		printf("======================================\n                С��ʾ\n\n          ����QQ 2783608988\n        �н����С�����Լ�Q");
	}
	else if( tips == 3 ) 
	{
		printf("======================================\n                С��ʾ\n\n          ����㲻֪��ô��\n    ����Ϸ�����ȿ�һ�¡�ʹ��˵����");
	}
	else if( tips == 4 ) 
	{
		printf("======================================\n                С��ʾ\n\n          ��������c��������\n      ���ȡԴ��ɵ������ȡԴ�롿");
	}
	 
	
	SetConsoleTextAttribute(hConsole,FOREGROUND_BLUE|FOREGROUND_GREEN|FOREGROUND_INTENSITY); //���ÿ���̨������ɫ
 	gotoxy(8,4);
	printf("��"); 
	}
	SetConsoleTextAttribute(hConsole,FOREGROUND_BLUE|FOREGROUND_GREEN|FOREGROUND_INTENSITY); //���ÿ���̨������ɫ

 	return;
 }
 
void check_people_play(int *will_x,int *will_y)			//���˻���ս�����������ӣ��Ӷ������ж� ������1�����Խ�Ҫ�����λ��x ������2�����Խ�Ҫ�����λ��y ��
{
	int c_x,c_y;
	 
	/*		������	*/
	for( c_y = 0 ; c_y < 3 ; c_y++ )
	{
		if( 2 == chess[c_y][0] && 2 == chess[c_y][1] )
		{
			if( 3 != chess[c_y][2] )
			{
				*will_x = 2, *will_y = c_y;
				return;
			}
		}
		if( 2 == chess[c_y][0] && 2 == chess[c_y][2] )	
		{
			if( 3 != chess[c_y][1] )
			{
				*will_x = 1, *will_y = c_y;
				return;
			}
		}
		if( 2 == chess[c_y][1] && 2 == chess[c_y][2] )	
		{
			if( 3 != chess[c_y][1] )
			{
				*will_x = 0, *will_y = c_y;
				return;
			}
		}	
			
	} 
	
	/*		�������	*/
	for( c_x = 0 ; c_x < 3 ; c_x++ )
	{
		if( 2 == chess[0][c_x] && 2 ==  chess[1][c_x] )	 
		{
			if( 3 != chess[2][c_x] )
			{
				*will_x = c_x, *will_y = 2;
				return;
			}
		}
		if( 2 == chess[0][c_x] && 2 == chess[2][c_x] )	
		{
			if( 3 != chess[1][c_x] )
			{
				*will_x = c_x, *will_y = 1;
				return;
			}
		}
		if( 2 == chess[1][c_x] && 2 == chess[2][c_x] )	
		{
			if( 3 != chess[0][c_x] )
			{
				*will_x = c_x, *will_y = 0;
				return;
			}
		}	
	} 
	
	/*		���Խ��� 		*/
	if( 2 == chess[0][0] && 2 ==  chess[1][1] )	
	{
		if( 3 != chess[2][2] )
		{
			*will_x = 2, *will_y = 2;
			return;
		}
	}
	if( 2 == chess[0][0] && 2 == chess[2][2] )	
	{
		if( 3 != chess[1][1] )
		{
			*will_x = 1, *will_y = 1;
			return;
		}
	}
	if( 2 == chess[1][1] && 2 == chess[2][2] )	
	{
		if( 3 != chess[0][0] )
		{
			*will_x = 0, *will_y = 0;
			return;
		}
	} 
	if( 2 == chess[0][2] && 2 ==  chess[1][1] )	
	{
		if( 3 != chess[2][0] )
		{
			*will_x = 0, *will_y = 2;
			return;
		}
	}
	if( 2 == chess[0][2] && 2 == chess[2][0] )	
	{
		if( 3 != chess[1][1] )
		{
			*will_x = 1, *will_y = 1;
			return;
		}
	}
	if( 2 == chess[1][1] && 2 == chess[2][0] )	
	{
		if( 3 != chess[0][2] )
		{
			*will_x = 2, *will_y = 0;
			return;
		}
	}
	
	
	*will_x = 4;	//��ⲻ�������ݴ�����Ϣ 
	return;
}

void check_computer_play(int *will_x,int *will_y)		//���˻���ս�����������ӣ��Ӷ������ж� ������1�����Խ�Ҫ�����λ��x ������2�����Խ�Ҫ�����λ��y ��
{
	int c_x,c_y;
	 
	/*		������	*/
	for( c_y = 0 ; c_y < 3 ; c_y++ )
	{
		if( 3 == chess[c_y][0] && 3 == chess[c_y][1] )
		{
			if( 2 != chess[c_y][2] )
			{
				*will_x = 2, *will_y = c_y;
				return;
			}
		}
		if( 3 == chess[c_y][0] && 3 == chess[c_y][2] )	
		{
			if( 2 != chess[c_y][1] )
			{
				*will_x = 1, *will_y = c_y;
				return;
			}
		}
		if( 3 == chess[c_y][1] && 3 == chess[c_y][2] )	
		{
			if( 2 != chess[c_y][0] )
			{
				*will_x = 0, *will_y = c_y;
				return;
			}
		}	
			
	} 
	
	/*		�������	*/
	for( c_x = 0 ; c_x < 3 ; c_x++ )
	{
		if( 3 == chess[0][c_x] && 3 ==  chess[1][c_x] )	 
		{
			if( 2 != chess[2][c_x] )
			{
				*will_x = c_x, *will_y = 2;
				return;
			}
		}
		if( 3 == chess[0][c_x] && 3 == chess[2][c_x] )	
		{
			if( 2 != chess[1][c_x] )
			{
				*will_x = c_x, *will_y = 1;
				return;
			}
		}
		if( 3 == chess[1][c_x] && 3 == chess[2][c_x] )	
		{
			if( 2 != chess[0][c_x] )
			{
				*will_x = c_x, *will_y = 0;
				return;
			}
		}	
	} 
	
	/*		���Խ��� 		*/
	if( 3 == chess[0][0] && 3 ==  chess[1][1] )	
	{
		if( 2 != chess[2][2] )
		{
			*will_x = 2, *will_y = 2;
			return;
		}
	}
	if( 3 == chess[0][0] && 3 == chess[2][2] )	
	{
		if( 2 != chess[1][1] )
		{
			*will_x = 1, *will_y = 1;
			return;
		}
	}
	if( 3 == chess[1][1] && 3 == chess[2][2] )	
	{
		if( 2 != chess[0][0] )
		{
			*will_x = 0, *will_y = 0;
			return;
		}
	} 
	if( 3 == chess[0][2] && 3 ==  chess[1][1] )	
	{
		if( 2 != chess[2][0] )
		{
			*will_x = 0, *will_y = 2;
			return;
		}
	}
	if( 3 == chess[0][2] && 3 == chess[2][0] )	
	{
		if( 2 != chess[1][1] )
		{
			*will_x = 1, *will_y = 1;
			return;
		}
	}
	if( 3 == chess[1][1] && 3 == chess[2][0] )	
	{
		if( 2 != chess[0][2] )
		{
			*will_x = 2, *will_y = 0;
			return;
		}
	}
	
	*will_x = 4;	//��ⲻ�������ݴ�����Ϣ 
	return;
}

void draw_map(int model)				//���˻���ս��˫�˶�ս����������
{	
	HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);	//��ȡ������ľ��

	int n_x = 13, n_y = 6,map1,map2;
	
	if( 1 == model )//ģʽ1_�˻���ս 
	{
		SetConsoleTextAttribute(hOut,FOREGROUND_GREEN|FOREGROUND_BLUE|FOREGROUND_INTENSITY); // ������ɫ 
		gotoxy(12,5);
		printf("�����������");	
	} 
	else if( 2 == model )//ģʽ2_˫�˶�ս 
	{
		if( 1 == step || 3 == step || 5 == step || 7 == step || 9 == step  )
		{
			SetConsoleTextAttribute(hOut,FOREGROUND_GREEN|FOREGROUND_BLUE|FOREGROUND_INTENSITY); // ������ɫ 
			gotoxy(10,5);
			printf("���������2����"); 
		}
		else
		{
			SetConsoleTextAttribute(hOut,FOREGROUND_GREEN|FOREGROUND_BLUE|FOREGROUND_INTENSITY); // ������ɫ 
			gotoxy(10,5);
			printf("���������1����"); 
		} 
	} 
	
	if( 1 == number_time )		//����������ǵ�һ������ 
	{
		SetConsoleTextAttribute(hOut,FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_INTENSITY); 
		gotoxy(n_x,n_y);
		printf("����������\n");
		/*		����������	*/

		for( map1 = 0 ; map1 < 3 ; map1++ )	
		{
			gotoxy(n_x,++n_y);
			printf("��      ");
			
			SetConsoleTextAttribute(hOut,FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_INTENSITY); 
			printf("��");			
		}
		SetConsoleTextAttribute(hOut,FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_INTENSITY); 	
		gotoxy(n_x,++n_y);
		printf("����������\n");

		if( 1 == model )//ģʽ1_�˻���ս 
		{
	
			SetConsoleTextAttribute(hOut,FOREGROUND_GREEN|FOREGROUND_INTENSITY); //���ÿ���̨������ɫ
			gotoxy(0,13);
			printf("======================================\n              ʹ��˵��\n\n" 
			"          �����˻���ս����\n"
			"       [W][S][A][D]������ҷ���\n       [�س���]ȷ��  [Esc]����\n\n" 
			"       ���߰�����QQ2783608988\n");
		
		
		} 
		else if( 2 == model )//ģʽ2_˫�˶�ս 
		{
			SetConsoleTextAttribute(hOut,FOREGROUND_GREEN|FOREGROUND_INTENSITY); //���ÿ���̨������ɫ
			gotoxy(0,13);
			printf("======================================\n              ʹ��˵��\n\n" 
			"          ����˫�˶�ս����\n"
			"       ���1:[��][��][��][��]\n       [�ո��]ȷ��         \n���2:[��][��][��][��]\n       [�س���]ȷ��  [Esc]����\n" 
			"       ���߰�����QQ2783608988\n");
		
		}
		SetConsoleTextAttribute(hOut,FOREGROUND_GREEN|FOREGROUND_BLUE|FOREGROUND_INTENSITY); // ������ɫ 
		gotoxy(8,5);
		printf("    ���κμ���ʼ    "); 
	} 
	else	//���ǵ�һ�����б����� 
	{	
		n_x = 15 ,n_y = 7 ; 
    
		/*		����������	*/
		for( map1 = 0 ; map1 < 3 ; map1++ )	
		{
			gotoxy(n_x,n_y++);
			for( map2 = 0 ; map2 < 3 ; map2++ )
			{
				if( 0 == chess[map1][map2] )
				{
					printf("  ");
				}
				else if( 1 == chess[map1][map2] )
				{
					SetConsoleTextAttribute(hOut,FOREGROUND_GREEN|FOREGROUND_BLUE|FOREGROUND_INTENSITY); // ������ɫ 
					printf("��");
				}
				else if( 2 == chess[map1][map2] )
				{
					SetConsoleTextAttribute(hOut,FOREGROUND_GREEN|FOREGROUND_BLUE|FOREGROUND_INTENSITY); // ������ɫ 
					printf("��");
				}
				else if( 3 == chess[map1][map2] )
				{
					SetConsoleTextAttribute(hOut,FOREGROUND_GREEN|FOREGROUND_INTENSITY); // ������ɫ 
					printf("��");
				}
			}	
		
		}
	}
		
	
		number_time++;//���д���+1 
}

void computer_play_chess(void)					//���˻���ս�� ��������
{
 	/*
	���˹����ܣ��������塿 
	������£�
	���Tic-Tac-Toe�˹�����ʵ��_��Ʒ�Ŀ�_IThao123 - IT��ҵ��һվ  
	http://www.ithao123.cn/content-3384427.html
	 */
 	srand((unsigned)time(NULL));			//���������	
 	int way = (int)(rand()%3);	 			//ȡ�������0~2����������õ������巽ʽ����һ�� 

 	if( 0 == step ) 	//��������
 	{
 		if( 0 == way )	//ռ�м�
 		{
 			chess[1][1]=3;
		}
 		else if( 1 == way )	//ռ��λ 
 		{
 			way = (int)(rand()%4);
 			if( 0 == way ) 
 			{
 				chess[0][1] = 3;	
			}
 			else if( 1 == way ) 
 			{	
			 	chess[2][1] = 3;
			}
			else if( 2 == way ) 
 			{
 				chess[1][0] = 3;
			}
 			else if( 3 == way ) 
 			{
 				chess[1][2] = 3;	
			}
		}
		else if( 2 == way )	//ռ�Ľ� 
		{
			way = (int)(rand()%4);
 			if( 0 == way ) 
 			{
 				chess[0][0] = 3;	
			}
 			else if( 1 == way ) 
 			{	
			 	chess[0][2] = 3;
			}
			else if( 2 == way ) 
 			{
 				chess[2][0] = 3;
			}
 			else if( 3 == way ) 
 			{
 				chess[2][2] = 3;	
			}
		}
	}

	else if( 1 == step ) //���Ժ��� 
	{
		if( 2 == chess[1][1] )  	//�������������λ��
		{
			/*	
			ʹ����������õ�������λ�ò���һ 
			���涼�������Ӷ��ڽ�λ ���Ƚ�ԭ�� 
			*/
			way = (int)(rand()%4);
			if( 0 == way )
			{
				chess[0][0] = 3;
			}
			else if( 1 == way )
			{
				chess[0][2] = 3;
			}
			else if( 2 == way )
			{
				chess[2][0] = 3;
			}
			else if( 3 == way )
			{
				chess[2][2] = 3;
			}
		}
		else 					//�����������λ����λ
		{
			chess[1][1] = 3;	//�����������м� 
		} 		
	}
	else
	{
		int c_x,c_y;
		check_computer_play(&c_x,&c_y);//������Կ���Ӯ���͹����κμ�����ö����������һ���������п�λʱ�������ڿ�λ��) 
 		if( 4 != c_x ) //������Թ� 
 		{
 			chess[c_y][c_x] = 3;
		}
		else
		{
			check_people_play(&c_x,&c_y);//���������ҿ�ҪӮ������(�κζԷ���ö����������һ���������п�λʱ�������ڿ�λ��)
			if( 4 != c_x ) 	//���������
 			{
 				chess[c_y][c_x] = 3;
			}
			else 
			{
				for( c_y = 0 ; c_y  < 3 ; c_y++ )	//�ٷ����������
				{	for( c_x = 0 ; c_x < 3 ; c_x++ )
					{
						if( 0 == chess[c_y][c_x])
						{
							chess[c_y][c_x] = 3;//���ϵ��£�ɨ���������̣�Ȼ��Ѱ�ҿ�λ������ҵ�һ���հ׵ĵط������� 
							step++;
							return; 
						}
					}				
				}	
			}
		} 
	}
	step++;//����+1 
 	return; 
 } 

int check_result(void)						//���˻���ս��˫�˶�ս���������[3]ʤ������1��[2]ʤ������2����ûʤ������0�����ӻ����--[3]�����ӻ��û�--[2])
{
	int c_x,c_y;
	
	/*		������	*/
	for( c_y = 0 ; c_y < 3 ; c_y++ )
	{
		if( 2 == chess[c_y][0] && 2 == chess[c_y][1] && 2 == chess[c_y][2])	//����ʤ�� 
		{
			return 1; 
		}
	    else if( 3 == chess[c_y][0] && 3 == chess[c_y][1] && 3 == chess[c_y][2])//����ʤ�� 
		{
			return 2; 
		}
	} 
	
	/*		�������	*/
	for( c_x = 0 ; c_x < 3 ; c_x++ )
	{
		if( 2 == chess[0][c_x] && 2 == chess[1][c_x] && 2 == chess[2][c_x] )//����ʤ�� 
		{
			return 1; 
		}
		else if( 3 == chess[0][c_x] && 3 == chess[1][c_x] && 3 == chess[2][c_x] )//����ʤ�� 
		{
			return 2; 
		}
	} 
	
	/*		���Խ��� 		*/
	if( ( 2 == chess[0][0] && 2 == chess[1][1] && 2 == chess[2][2] ) ) //����ʤ�� 
	{
		return 1; 
	}
	else if( ( 3 == chess[0][0] && 3 == chess[1][1] && 3 == chess[2][2] ) ) //����ʤ�� 
	{
		return 2; 
	}
	if( ( 2 == chess[0][2] && 2 == chess[1][1] && 2 == chess[2][0] ) )//����ʤ�� 
	{
		return 1; 
	} 
	else if( ( 3 == chess[0][2] && 3 == chess[1][1] && 3 == chess[2][0] ) )//����ʤ�� 
	{
		return 2; 
	}
	
	return 0;//��ûʤ�� 
}

void a_word_printf(char * a, int time)		//��������
{
	int i ;
	for (i = 0; a[i] != '\0'; i++)
	{
		printf("%c", a[i]);
		Sleep(time);
	}

	return;
}

 void gotoxy(int x,int y)					//��굽ָ��λ�� 
{
	HANDLE hOut;
	hOut = GetStdHandle(STD_OUTPUT_HANDLE);		//��ñ�׼��������ľ��
	COORD pos = {x,y};							//��ʾһ���ַ��ڿ���̨��Ļ�ϵ�����(ASCLL����Ϊ1 ��ASCLL����Ϊ2)
	SetConsoleCursorPosition(hOut ,pos);	    //��궨λ�ڶ�Ӧ��λ��	
	return;
}
