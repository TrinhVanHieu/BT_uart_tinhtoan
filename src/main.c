#include "project.h"


/*************************************************************************************************/
char a[10] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
int m;

void delay(unsigned int timeout)
{
    unsigned int t1, t2;
    for (t1 = 0; t1 < timeout; t1++)
    {
        for (t2 = 0; t2 < 0xFFF; t2++)
        {
          asm(" nop");
        }
    }
}

/*send int*/
void send_int(int s)
{
	int ng, d;
	int *a;
	char *b;
	int k = 0;
	int l = 0;
	while (0 != s)
	{
		ng = s / 10; 
		d = s % 10;
		*(a + k) = d;
		k++;
		s = ng;
	}
	for (int i = k - 1; i >= 0; i--)
	{
		*(b + l) = (*(a + i) + 48); //doi so sang chu
		l++;
	}
	for (int i = 0; i < l; i++) usart_send_byte(*(b + i));
}
/*addition */
void Add(int a, int b)
{
	int s = a + b;
	usart_send_string("\r\nTong hai so vua nhap la: ");
	send_int(s);
}

/*subtraction*/
void Sub(int a, int b)
{
	int s = a - b;
	usart_send_string("\r\nHieu hai so vua nhap la: ");
	send_int(s);
}

/*multiplication*/
void Mul(int a, int b)
{
	int s = a * b;
	usart_send_string("\r\nTich hai so vua nhap la: ");
	send_int(s);
}

/*division*/
void Div(int a, int b)
{
	int ng, d;
	ng = a/b;
	d = a%b;
	usart_send_string("\r\nKet qua phep chia duoc: ");
	send_int(ng);
	usart_send_string("\r\nVa du: ");
	send_int(d);
}
void main(void)
{
	unsigned char state = 0;
	unsigned char flag = 0;
	unsigned int value = 0;
	unsigned int value_sh_1 = 0;
	unsigned int value_sh_2 = 0;

	
    system_init();
    enabled_clock();
    pin_init();
    usart_init();

    interrupt_init();

    /* send "Hello world -MCU" to terminal app on PC */
	usart_send_string("\r\nNhap so thu nhat: ");
    led_on(LD4_PIN);
	
	while(1)
	{
		if (0 != rx_data)
		{
			if(0x0D != rx_data) // so
			{
				for (int i = 0; i < 10; i++)
				{
					if (rx_data == a[i])
					{
						m = i;
						break;
					}
				}
				value = value*10 + m;
				usart_send_byte(rx_data);
			}
			else // enter
			{
				if (0 == state)
				{
					value_sh_1 = value;
					usart_send_string("\r\nNhap so thu hai: ");
					state = 1;
				}
				else
				{
					value_sh_2 = value;
					usart_send_string("\r\nNhap so thu nhat: ");
					state = 0;
					flag = 1;
				}
				value = 0;
			}
			rx_data = 0;
		}
		if (flag)
		{
			Add(value_sh_1, value_sh_2);
			Sub(value_sh_1, value_sh_2);
			Mul(value_sh_1, value_sh_2);
			//Div(value_sh_1, value_sh_2);
			flag = 0;
		}
	}
}

